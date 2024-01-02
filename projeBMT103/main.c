#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bilet_fonksiyon.h"     //header dosyaso



#define MAX_SEATS 25                                // Maksimum koltuk sayısı
#define SEFER_SAYISI 10                            // Toplam sefer sayısı
#define SEHIR_SAYISI 10                            // Toplam şehir sayısı
#define MAX_REZERVASYON_SAYISI 100                 // Maksimum rezervasyon sayısı



// Otobüs firmalarının isimleri
char *firmaIsimleri[] = {"Truva", "Pamukkale", "Metro"};



// Şehirlerin isimleri
char *sehirIsimleri[] = {"Istanbul (Esenler Otogari)", "Istanbul (Alibeykoy Otogari)", "Ankara (ASTI)",
                         "Bursa", "Izmir", "Antalya", "Diyarbakir", "Samsun", "Adana", "Van", "Sivas"};


int main()
{
        srand(time(NULL));       //random değerler almamızı sağlayan fonksiyon

                                                             // Kullanıcının rezervasyonları saklamak için dizi
    Rezervasyon rezervasyonlar[MAX_REZERVASYON_SAYISI];
    int rezervasyonSayisi = 0;

    // Bilet dizisi
    Bilet biletler[SEFER_SAYISI];

    // Ana menü
    int secim;
    do {                                                       // do while döngüsünün içinde do ile başlamanın sebebi koşula bağlı kalmadan ana menünün bir kez yazılması için
            printf("*---------------*");
        printf("\nAna Menu\n");
        printf("1. Bilet Al\n");
        printf("2. Rezervasyonlarimi Goruntule\n");                            // ana menü
        printf("3. Rezervasyon Iptal Etme\n");
        printf("0. Cikis\n");
    printf("*---------------*\n\n");
        printf("Seciminizi yapiniz: ");
        scanf("%d", &secim);
        printf("\n");

        switch (secim) {                                                     // ana menüden kullanıcının seçim yapması sonucu oluşan dallanmalar için switch case yapısı
            case 1: {

                printf("Lutfen tarihi giriniz (Gun Ay Yil): ");
                int gun, ay, yil;
                scanf("%d %d %d", &gun, &ay, &yil);                                               // Kullanıcıdan tarih bilgisinin alınması
                printf("\n");
                printf("+-------------------------------+\n");

                printf("Hangi sehirde bulunuyorsunuz? (1-%d)\n", SEHIR_SAYISI);                 // 10 tane şehrin alt alta yazılması
                for (int i = 0; i < SEHIR_SAYISI; i++) {
                    printf("%d. %s\n", i + 1, sehirIsimleri[i]);
                }
                printf("+-------------------------------+\n");
                printf("Seciminizi yapiniz: ");
                int kalkisSehirSayi;
                scanf("%d", &kalkisSehirSayi);                                                  // kullanıcıdan bulunduğu şehrin harf karşılığının alınması
                printf("\n");
                printf("+-------------------------------+\n");

                printf("Nereye seyahat etmek istiyorsunuz? (1-%d)\n", SEHIR_SAYISI);             // (10-1) kez şehirlerin alt alta yazılması
                for (int i = 0; i < SEHIR_SAYISI; i++) {
                    if (i != kalkisSehirSayi - 1) {                                             //burdaki if'in yazma sebebi ilk durumda seçilen şehrin tekrar seçilmesini engellemek içindir.
                        printf("%d. %s\n", i + 1, sehirIsimleri[i]);                           // -1 de aynı şekilde ilk seçilen şehrin tekrar seçilmemesi için
                    }
                }
                printf("+-------------------------------+\n");
                printf("Seciminizi yapiniz:");

                int varisSehirSayi;
                scanf("%d", &varisSehirSayi);                                              //kullanıcıdan seyahat etmek istediği şehrin numarasının alınması.
                 printf("\n\n");

                // Oluşturulan biletlerin bilgilerinin ekrana yazdırılması
                for (int i = 0; i < SEFER_SAYISI; i++)                                       //for döngüsünün sebebi bilet oluşturma aşamasında 10 tane farklı bilet oluşturmak için.
                    {

                        // Saatlerin sıralı halde belirlenmesi
                        int saatler[24];
                          for (int j = 0; j < 24; j++) {                               //saatler[1]=1 , saatler[2]=2 şeklinde bir dizi oluşturur
                            saatler[j] = j;
                          }

                         // Saat seçimi
                         int saatSayi = rand() % 24;                                   // Saat rastgele seçilir
                         int saat = saatler[saatSayi];                              //saatler[saatSayi] dizisinin elemanı= saat değişkenine atanır.

                         // Firma seçimi
                         int firmaSayi = rand() % 3;

                          // Dolu koltuk sayısı ve numaralarının belirlenmesi (yukarıdaki programın bir benzeri)
                          int doluOlanKoltukSayisi = 1 + rand() % MAX_SEATS;                                          //dolu koltuk sayısının MAX_SEATS=25 ile 1 arasında seçilip doluOlanKoltukSayisi değişkenine atanır

                    // Bilet bilgilerinin atanması
                    biletler[i].tarih_gun = gun;
                    biletler[i].tarih_ay = ay;
                    biletler[i].tarih_yil = yil;                                          //Bilet biletler[SEFER_SAYISI] dizisinden Bilet structure içine gidip değerlerin atanması.
                    biletler[i].saat = saat;
                    biletler[i].kalkisSehir = sehirIsimleri[kalkisSehirSayi - 1];       // şehir isimleri dizisine gidip atama yapılması. (-1 in sebebi dizilerde index'in 0 ile başlamasından dolayı)
                    biletler[i].varisSehir = sehirIsimleri[varisSehirSayi - 1];
                    biletler[i].firma = firmaIsimleri[firmaSayi];
                    biletler[i].doluOlanKoltukSayisi = doluOlanKoltukSayisi;

                    // Dolu koltuk numaralarının belirlenmesi
                    for (int j = 0; j < doluOlanKoltukSayisi; j++)              // bu döngü biletteki dolu koltuk sayısı kadar işlemde kalır
                        {
                           int yenikoltuk;
                           int x;                       //bu değişken bir koltuğun dolu olup olmadığını kontrol etmek için

                              do
                               {
                               x = 0;
                               yenikoltuk = 1 + rand() % MAX_SEATS;     //rastgele bir koltuk seçme

                                // for döngüsü üstte rastgele atanan koltuğun dolu olup olmadığını kontrol eder
                                       for (int k = 0; k < j; k++) {
                                           if (biletler[i].doluKoltuklar[k] == yenikoltuk) {
                                            x = 1;
                                           break;    //x=1 olup döngüden çıkar
                                           }
                                       }
                                }
                         while (x);          //x=1 olduğunda while içine girip boş koltuk seçilmiş olur

                        biletler[i].doluKoltuklar[j] = yenikoltuk;  //dolu olmayan bir koltuk seçildiğinde bu koltuk numarası biletin dolu koltuklar listesine eklenir

                       }
                 }

                // Oluşturulan biletlerin bilgilerinin ekrana yazdırılması
                for (int i = 0; i < SEFER_SAYISI; i++) {
                    printf("Bilet %d Bilgileri:\n", i + 1);     //biletin numarası
                    printf("Tarih: %02d/%02d/%d\n", biletler[i].tarih_gun, biletler[i].tarih_ay, biletler[i].tarih_yil); // Bilet Structure içinde olan biletler dizisinden değer ataması yapıyor
                    printf("Kalkis Sehri: %s\n", biletler[i].kalkisSehir);            // Bilet Structure içinde olan biletler dizisinden değer ataması yapıyor
                    printf("Varis Sehri: %s\n", biletler[i].varisSehir);             // Bilet Structure içinde olan biletler dizisinden değer ataması yapıyor
                    printf("Saat: %02d:00\n", biletler[i].saat);              // Bilet Structure içinde olan biletler dizisinden değer ataması yapıyor
                    printf("Firma: %s\n", biletler[i].firma);              // Bilet Structure içinde olan biletler dizisinden değer ataması yapıyor
                    printf("Dolu Koltuk Numaralari: ");
                    for (int j = 0; j < biletler[i].doluOlanKoltukSayisi; j++) {
                        printf("%d ", biletler[i].doluKoltuklar[j]);           //yukarda rastgele atanan dolu koltukları gösterir
                    }
                    printf("\n\n");
                }

                // Kullanıcının bilet seçmesi ve koltuk numarası belirlemesi
                SatinAlmaBilgileri satinAlmaBilgileri;  // struct için ad değişikliği gibi bir şey
                int koltukVar = 0;
                do
                    {
                    printf("Satin almak istediginiz biletin numarasini giriniz (1-%d): ", SEFER_SAYISI);
                    scanf("%d", &satinAlmaBilgileri.biletIndex);      // SatinAlmaBilgileri struct içine gidip biletIndex değerine kullanıcının değer ataması sağlanır
                    satinAlmaBilgileri.biletIndex--;                 // Kullanıcıya 1'den başlayan bilet numaraları gösteriyoruz fakat programdaki dizi 0'dan başlıyo o yüzden -1 koyduk

                    if (satinAlmaBilgileri.biletIndex < 0 || satinAlmaBilgileri.biletIndex >= SEFER_SAYISI) {        //kullanıcı 0'dan küçük veya 10'dan büyük seçerse tekrar seçmesi için döngü başına atar
                        printf("Hatali bilet numarasi. Lutfen gecerli bir bilet numarasi giriniz.\n");
                        continue;
                    }

                    // Kullanıcının seçtiği biletin bilgilerini ekrana yazdırma
                    printf("Secilen Bilet Bilgileri:\n");
                    printf("Tarih: %02d/%02d/%d\n", biletler[satinAlmaBilgileri.biletIndex].tarih_gun,biletler[satinAlmaBilgileri.biletIndex].tarih_ay, biletler[satinAlmaBilgileri.biletIndex].tarih_yil);
                    printf("Kalkis Sehri: %s\n", biletler[satinAlmaBilgileri.biletIndex].kalkisSehir);
                    printf("Varis Sehri: %s\n", biletler[satinAlmaBilgileri.biletIndex].varisSehir);          //1- satinAlmaBilgileri.biletIndex bu ifade kullanıcının satın almak istediği biletin numarasını içeren satinAlmaBilgileri yapısındaki biletIndex üyesine erişir bu değer kullanıcının seçtiği biletin indeksidir
                    printf("Saat: %02d:00\n", biletler[satinAlmaBilgileri.biletIndex].saat);                  //2-biletler[satinAlmaBilgileri.biletIndex]: Bu ifade, biletler dizisindeki belirtilen indeksteki biletin tamamını içerir
                    printf("Firma: %s\n", biletler[satinAlmaBilgileri.biletIndex].firma);                    //3-kalkisSehir ifadesi biletler[satinAlmaBilgileri.biletIndex] ifadesinin kalkış şehri bilgisine erişir böylece kullanıcının seçtiği biletin kalkış şehri bilgisine ulaşmış oluruz
                    printf("Dolu Koltuk Numaralari: ");
                    for (int j = 0; j < biletler[satinAlmaBilgileri.biletIndex].doluOlanKoltukSayisi; j++) {
                        printf("%d ", biletler[satinAlmaBilgileri.biletIndex].doluKoltuklar[j]);                             //bu döngüde kullanıcının seçtiği biletin numarasına göre dolu olan koltukların üzerinde kontrol yapar doluOlanKoltukSayisi kullanıcının seçtiği biletin dolu koltuk sayısını içerir ve bu döngü bu sayı kadar döner
                    }
                    printf("\n");

                    // Kullanıcının koltuk numarası seçmesi
                    printf("Satin almak istediginiz koltuk numarasini giriniz (1-%d): ", MAX_SEATS);
                    scanf("%d", &satinAlmaBilgileri.koltukNo);    // satınalma bilgileri struct içindeki koltukNo değişkenine atama yapar

                    // Seçilen koltuğun durumunu kontrol etme
                    koltukVar = 0;

                    for (int i = 0; i < biletler[satinAlmaBilgileri.biletIndex].doluOlanKoltukSayisi; i++)    //1-biletler[satinAlmaBilgileri.biletIndex].doluOlanKoltukSayisi: Seçilen biletin dolu olan koltuk sayısını temsil eder
                                                                                                             //2-satinAlmaBilgileri struct'ı, kullanıcının satın alma işlemi sırasında seçtiği bilet ve koltuk bilgilerini içerir
                     {
                                                                                                              //3-biletler[satinAlmaBilgileri.biletIndex] ifadesi, biletler dizisinde bulunan biletlerden, kullanıcının seçtiği biletin bilgilerini temsil eder
                                                                                                                //4-satinAlmaBilgileri.biletIndex ifadesi ise, kullanıcının seçtiği biletin dizideki indeksini (numarasını) belirtir

                        if (satinAlmaBilgileri.koltukNo == biletler[satinAlmaBilgileri.biletIndex].doluKoltuklar[i])

                            {
                            koltukVar = 1;
                            printf("Secilen koltuk dolu. Lutfen baska bir koltuk seciniz.\n");
                            break;                                                                // burdaki break bilet seçtirme ekrarına geri dönüyor !!! pull request


                            }
                     }


                    if (!koltukVar) {        //koltuk dolu değilse if bloğu çalışır
                        printf("Satin alma islemi basariyla tamamlandi. Iyi yolculuklar!\n");

                        // Rezervasyonları güncelle
                        rezervasyonlar[rezervasyonSayisi].biletIndex = satinAlmaBilgileri.biletIndex;  // rezervasyon gösterme kısmında yeni atanan bilet numarası gösterilir
                        rezervasyonlar[rezervasyonSayisi].koltukNo = satinAlmaBilgileri.koltukNo;      // rezervasyo gösterme kısmında yeni atanan koltuk numarası gösterilri
                        rezervasyonSayisi++;
                    }

                }
                while (koltukVar);

                break;
            }
               case 2:


                // Rezervasyonları görüntüle
                if (rezervasyonSayisi == 0) {
                    printf("Herhangi bir rezervasyon bulunmamaktadir.\n\n");
                }

                else
                    {
                    printf("Rezervasyonlariniz:\n");
                    for (int i = 0; i < rezervasyonSayisi; i++)   // rezervasyonları sırasıyla gösterir
                           {
                        printf("Rezervasyon %d Bilgileri:\n", i + 1);
                        printf("Bilet Numarasi: %d\n", rezervasyonlar[i].biletIndex + 1); //Rezervasyon struct içine gidip değerleri yazdırır
                        printf("Koltuk Numarasi: %d\n", rezervasyonlar[i].koltukNo);
                        printf("Bilet Bilgileri:\n");
                        biletBilgileriYazdir(biletler[rezervasyonlar[i].biletIndex]);  // fonksiyona gidip
                        printf("\n");
                                  }
                    }

                break;

                case 3:
                // Rezervasyon iptali fonksiyonun içinde gider
                rezervasyonIptalEt(rezervasyonlar, &rezervasyonSayisi, biletler); // fonksiyon
                break;



                case 0:
                printf("Programdan cikiliyor...\n");
                break;


                default:
                printf("Gecersiz secim. Lutfen tekrar deneyin.\n");
                break;
        }

    } while (secim != 0);  // seçimin 0' dan farklı olduğunda çalışmasını sağlayan döngü sonu.



    return 0;
}
