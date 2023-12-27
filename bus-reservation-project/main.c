#include <stdio.h>
#include <stdlib.h>

int main()
{
char *from[10]={"Ankara","Bursa","Gaziantep","Samsun","Sivas","ankara","bursa","gaziantep","samsun","sivas"};
char *towards[10]={"Ankara","Bursa","Gaziantep","Samsun","Sivas","ankara","bursa","gaziantep","samsun","sivas"};
char *firma[3]={"Truva","Pamukkale Turizm","Ali Osman Ulusoy"};
    int choose;
    int i=0;

    printf("+--------------+\n");
    printf("|| Buy Ticket<1>\n");
    printf("|| Profile<2>\n");
    printf("|| My Trips<3>\n");
    printf("|| Exit<0>\n");
    printf("+--------------+\n\n");
    printf("Welcome To The ETS Ticket System ! \n");


    printf("Please Select An Option:");                             //değiştirilcek
    scanf("%d",&choose);
    if(choose!=0){

          switch(choose){
                  case 1:
                     printf("---Enter Your Destination---\n");

                     while(i!=1){
                printf("From: ");
                scanf(" %[^\n]s", from);
                printf("To: ");
                scanf(" %[^\n]s\n", towards);
                printf("Continue[1]Retry[0]");
                scanf("%d",&i);
                       }
                printf("Available Buses For Your Destination:\n");   //random oluşturulmuş otobüs ve koltuk

                       // Bilet ;Al                    // nereden-nereye, kaç bilet,otobüs firması seç,koltuk seç,ödeme,bilet alma başarılı-başarısız mesajı                         //otogarlar,iller,firma,random bilet sayısı,random koltuk sayısı
                      break;
                   case 2:
                      //profil kısmının olduğu                                              //isim soy isim,email,şifre,cinsiyet

                      break;
                case 3:
                     // seyahatlarim kısmı                                                                                  // bilet iptal etme biletin saati falan filan
                      break;
                   }
          }
     else{
        printf("Quitting The Application.\n\n\n\n\n\n");
     }
    return 0;
}
