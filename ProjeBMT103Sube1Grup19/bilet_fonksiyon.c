#include <stdio.h>
#include "bilet_fonksiyon.h"
#include <time.h>
#include <stdlib.h>


#define SEFER_SAYISI 10                            // Toplam sefer sayısı
#define SEHIR_SAYISI 10                            // Toplam şehir sayısı
#define MAX_REZERVASYON_SAYISI 100                 // Maksimum rezervasyon sayısı




void biletBilgileriYazdir(Bilet bilet) {    //Bilet structure'ı parametre olarak alındı
    printf("Tarih: %02d/%02d/%d\n", bilet.tarih_gun, bilet.tarih_ay, bilet.tarih_yil); // structure'dan gün ay yıl yazdırma
    printf("Kalkis Sehri: %s\n", bilet.kalkisSehir);  //structure'dan yazdırır
    printf("Varis Sehri: %s\n", bilet.varisSehir);    //structure'dan yazdırır
    printf("Saat: %02d:00\n", bilet.saat);          //structure'dan yazdırır
    printf("Firma: %s\n", bilet.firma);            //structure'dan yazdırır
    printf("Dolu Koltuk Numaralari: ");
    for (int j = 0; j < bilet.doluOlanKoltukSayisi; j++) {
        printf("%d ", bilet.doluKoltuklar[j]);             //for döngüsünde dolu koltuk numaraları index'in artması ile yazdırılır.
    }
    printf("\n\n");
}

// Rezervasyon iptal etme fonksiyonu
void rezervasyonIptalEt(Rezervasyon rezervasyonlar[], int *rezervasyonSayisi, Bilet biletler[]) {    //rezervasyonlar dizisi ve biletler dizisi alınır ---> bu iki dizi structure içindedir
    if (*rezervasyonSayisi == 0) {
        printf("Herhangi bir rezervasyon bulunmamaktadir.\n");
        return;
    }

    printf("Iptal etmek istediginiz rezervasyonun numarasini giriniz (1-%d): ", *rezervasyonSayisi);
    int iptalIndex;                              // kullanıcıdan iptal etmek istediği biletin numarasını aldırır
    scanf("%d", &iptalIndex);

    if (iptalIndex < 1 || iptalIndex > *rezervasyonSayisi) {                    // kullanıcının doğru sayı almasını sağlar
        printf("Hatali rezervasyon numarasi. Lutfen gecerli bir rezervasyon numarasi giriniz.\n");
        return;
    }

    // İptal edilecek rezervasyonun bilgilerini ekrana yazdırma
    printf("Iptal edilen Rezervasyon Bilgileri:\n");
    printf("Bilet Numarasi: %d\n", rezervasyonlar[iptalIndex - 1].biletIndex + 1);
    printf("Koltuk Numarasi: %d\n", rezervasyonlar[iptalIndex - 1].koltukNo);
    printf("Bilet Bilgileri:\n");
    biletBilgileriYazdir(biletler[rezervasyonlar[iptalIndex - 1].biletIndex]);
    printf("\n");

    // Rezervasyonu silme
    for (int i = iptalIndex - 1; i < *rezervasyonSayisi - 1; i++) { //1- int i = iptalIndex - 1;: döngünün başlangıç noktasını iptal edilecek rezervasyonun dizideki indeksine ayarlar bu indeks dizide 0'dan başladığı için 1 çıkartılmıştır
                                                                    //2- i < *rezervasyonSayisi - 1;: döngünün devam koşulu dizideki rezervasyon sayısının bir eksiğine kadar devam etmesini sağlar0 bu dizide bir eleman silindiğinde dizinin sonunda boş bir elemanın oluşmamasını sağlar
        rezervasyonlar[i] = rezervasyonlar[i + 1];                     //3- rezervasyonlar[i] = rezervasyonlar[i + 1]; iptal edilen rezervasyonun bulunduğu indeksten başlayarak bir sonraki rezervasyonun bilgilerini bir öncekine kopyalar bu seçilen rezervasyonu diziden silmek anlamına gelir
    }

    (*rezervasyonSayisi)--;                                             //rezervasyon iptal edildikten sonra sayısı bir düşürülür

    printf("Rezervasyon basariyla iptal edildi.\n");
}


void biletleriDosyayaYaz(Bilet biletler[], int seferSayisi, int index, int secilenKoltuk) {
    FILE *dosya = fopen("bilet_bilgileri.txt", "a");

    if (dosya == NULL) {
        perror("Dosya acilirken bir hata olustu");
        exit(EXIT_FAILURE);
    }

    if (index < 0 || index >= seferSayisi) {
        printf("Hatali bilet indeksi. Dosyaya yazma islemi iptal edildi.\n");
        fclose(dosya);
        return;
    }

    int yazilan = fprintf(dosya, "%02d/%02d/%d %02d:00 %s %s %s %d ",
                          biletler[index].tarih_gun, biletler[index].tarih_ay,
                          biletler[index].tarih_yil, biletler[index].saat,
                          biletler[index].kalkisSehir, biletler[index].varisSehir,
                          biletler[index].firma, biletler[index].doluOlanKoltukSayisi);

    if (yazilan < 0) {
        perror("Dosyaya yazma hatasi");
        exit(EXIT_FAILURE);
    }

    for (int j = 0; j < biletler[index].doluOlanKoltukSayisi; j++) {
        int yazilanKoltuk = fprintf(dosya, "%d ", biletler[index].doluKoltuklar[j]);
        if (yazilanKoltuk < 0) {
            perror("Dosyaya yazma hatasi");
            exit(EXIT_FAILURE);
        }
    }

    // Burada kullanıcının seçtiği koltuğu dosyaya yazıyoruz
    fprintf(dosya, "Seçilen Koltuk: %d\n", secilenKoltuk);

    fprintf(dosya, "\n");

    fclose(dosya);
}



// Dosyadan bilet bilgilerini okuyan fonksiyon
void biletleriDosyadanOku(Bilet biletler[], int *seferSayisi) {
    FILE *dosya = fopen("bilet_bilgileri.txt", "a");

    if (dosya == NULL) {
        perror("Dosya acilirken bir hata olustu");
        exit(EXIT_FAILURE);
    }

    while (fscanf(dosya, "%d/%d/%d %d:00 %s %s %s %d",
                  &biletler[*seferSayisi].tarih_gun, &biletler[*seferSayisi].tarih_ay, &biletler[*seferSayisi].tarih_yil,
                  &biletler[*seferSayisi].saat, biletler[*seferSayisi].kalkisSehir, biletler[*seferSayisi].varisSehir,
                  biletler[*seferSayisi].firma, &biletler[*seferSayisi].doluOlanKoltukSayisi) != EOF) {
        for (int j = 0; j < biletler[*seferSayisi].doluOlanKoltukSayisi; j++) {
            fscanf(dosya, "%d", &biletler[*seferSayisi].doluKoltuklar[j]);
        }
        (*seferSayisi)++;
    }

    fclose(dosya);
}
