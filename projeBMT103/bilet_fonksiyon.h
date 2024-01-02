#ifndef BILET_FONKSIYON_H_INCLUDED
#define BILET_FONKSIYON_H_INCLUDED


#define MAX_SEATS 25                                // Maksimum koltuk sayısı
#define SEFER_SAYISI 10                            // Toplam sefer sayısı
#define SEHIR_SAYISI 10                            // Toplam şehir sayısı
#define MAX_REZERVASYON_SAYISI 100                 // Maksimum rezervasyon sayısı



// Bilet yapısı
typedef struct {           //typedef sayesinde struct yapısını direkt kendi adlandırdığımız isim ile işleme alabiliriz.
    int tarih_gun;
    int tarih_ay;
    int tarih_yil;
    int saat;
    char *kalkisSehir;
    char *varisSehir;
    char *firma;
    int doluOlanKoltukSayisi;
    int doluKoltuklar[MAX_SEATS];
} Bilet;                                 //typedef struct Bilet;    struct yapısını direkt "Bilet" olarak çağırabiliriz.



typedef struct {
    int biletIndex;                       //satın alma kısmı
    int koltukNo;
} SatinAlmaBilgileri;




typedef struct {
    int biletIndex;                //rezervasyon yapma kısmı
    int koltukNo;
} Rezervasyon;


void biletBilgileriYazdir(Bilet bilet);


// Rezervasyon iptal etme fonksiyonu
void rezervasyonIptalEt(Rezervasyon rezervasyonlar[], int *rezervasyonSayisi, Bilet biletler[]);



#endif // BILET_FONKSIYON_H_INCLUDED
