#include <stdio.h>
#include "bilet_fonksiyon.h"
#include <time.h>
#include <stdlib.h>


#define SEFER_SAYISI 10                            // Toplam sefer sayısı
#define SEHIR_SAYISI 10                            // Toplam şehir sayısı
#define MAX_REZERVASYON_SAYISI 100                 // Maksimum rezervasyon sayısı




void biletBilgileriYazdir(Bilet bilet) {
    printf("Tarih: %02d/%02d/%d\n", bilet.tarih_gun, bilet.tarih_ay, bilet.tarih_yil);
    printf("Kalkis Sehri: %s\n", bilet.kalkisSehir);
    printf("Varis Sehri: %s\n", bilet.varisSehir);
    printf("Saat: %02d:00\n", bilet.saat);
    printf("Firma: %s\n", bilet.firma);
    printf("Dolu Koltuk Numaralari: ");
    for (int j = 0; j < bilet.doluOlanKoltukSayisi; j++) {
        printf("%d ", bilet.doluKoltuklar[j]);
    }
    printf("\n\n");
}

// Rezervasyon iptal etme fonksiyonu
void rezervasyonIptalEt(Rezervasyon rezervasyonlar[], int *rezervasyonSayisi, Bilet biletler[]) {
    if (*rezervasyonSayisi == 0) {
        printf("Herhangi bir rezervasyon bulunmamaktadir.\n");
        return;
    }

    printf("Iptal etmek istediginiz rezervasyonun numarasini giriniz (1-%d): ", *rezervasyonSayisi);
    int iptalIndex;
    scanf("%d", &iptalIndex);

    if (iptalIndex < 1 || iptalIndex > *rezervasyonSayisi) {
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
    for (int i = iptalIndex - 1; i < *rezervasyonSayisi - 1; i++) {
        rezervasyonlar[i] = rezervasyonlar[i + 1];
    }

    (*rezervasyonSayisi)--;

    printf("Rezervasyon basariyla iptal edildi.\n");
}
