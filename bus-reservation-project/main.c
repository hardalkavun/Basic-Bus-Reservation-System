#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choose;
    printf("+--------------+\n");
    printf("|| Buy Ticket<1>\n");
    printf("|| Profile<2>\n");
    printf("|| My Trips<3>\n");
    printf("+--------------+\n");
    printf("Welcome To The ETS Ticket System ! \n");


    printf("Please Select An Option:");                             //değiştirilcek
    scanf("%d",&choose);
    switch(choose){
    case '1':
        printf("---Enter Your Destination---\n");
        printf("From:");
        scanf("%c",&from);
        printf("To:");
        scanf("%c",&to);
        // Bilet Al                    // nereden-nereye, kaç bilet,otobüs firması seç,koltuk seç,ödeme,bilet alma başarılı-başarısız mesajı                         //otogarlar,iller,firma,random bilet sayısı,random koltuk sayısı
        break;
    case '2':
            //profil kısmının olduğu                                              //isim soy isim,email,şifre,cinsiyet

        break;
    case '3':
          // seyahatlarim kısmı                                                                                  // bilet iptal etme biletin saati falan filan
        break;
    }

    return 0;
}
