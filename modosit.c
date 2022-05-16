#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modosit.h"
#include "letrehoz_keres_felszabadit.h"
#include "kilistaz.h"
#include "econio.h"

Rekordok *modosit(Rekordok *naplo){

    int modositott_honap;
    int modositott_nap;
    int modositott_ora;
    int modositott_perc;
    char modositott_hely[200];
    char modositott_esemeny[200];
    char modositott_megjegyzes[200];


    int n;
    char esemeny[200];

    do{
        printf(
               "1. Datum modositasa\n"
               "2. Ido modositasa\n"
               "3. Hely modositasa\n"
               "4. Esemeny nevenek modositasa\n"
               "5. Megjegyzes modositasa\n"
               "6. Rekord (esemeny) torlese\n"
               "\n"
               "Adja meg a valasztott menupont szamat!\n");


       while(scanf("%d", &n)!=1){
        printf("Nem szamot adtal meg.\n");
        scanf("%*[^\n]%*c");
        printf("Adja meg a valasztott menupont szamat!\n");
        }

        printf("\n");

        if(n>6){
            printf("Nincs ilyen menupont.\n");
            printf("\n");
            break;
        }
        econio_clrscr();

        printf("Szokozok helyett hasznaljon '_' -t. Ekezetet beirni tilos! Max 200 karakter!\n");
        printf("\n");
        printf("Melyik esemenyt szeretne modositani? Adja meg a nevet!\n");
        scanf("%s", esemeny);


        Rekordok *lemarado=NULL;
        Rekordok *mozgo=naplo;
        while(mozgo!=NULL && (strcmp(mozgo->esemeny,esemeny)!=0)){
            lemarado=mozgo;
            mozgo=mozgo->kov;
        }
        if(mozgo==NULL){
            printf("\n");
            printf("Nincs ilyen esemeny.\n");
            printf("\n");
            break;
        }

        else{

                switch(n){
                    case 1:
                        printf("Uj datum: ");

                        while(scanf("%d.%d.",&modositott_honap, &modositott_nap)!=2){
                            printf("Nem ho.nap. formaban adta meg.\n");
                            scanf("%*[^\n]%*c");
                            printf("\nUj datum: ");
                        }
                        mozgo->honap=modositott_honap;
                        mozgo->nap=modositott_nap; econio_clrscr(); break;


                    case 2:
                        printf("Uj ido: ");
                        while(scanf("%d:%d", &modositott_ora, &modositott_perc)!=2){
                            printf("Nem Nem ido:perc formaban adta meg.\n");
                            scanf("%*[^\n]%*c");
                            printf("\nUj ido: ");
                        }
                        mozgo->ora=modositott_ora;
                        mozgo->perc=modositott_perc; econio_clrscr(); break;

                    case 3:
                        printf("Uj hely: ");
                        scanf("%s", modositott_hely);
                        strncpy(mozgo->hely,modositott_hely, 200);
                        mozgo->hely[199]='\0'; econio_clrscr(); break;

                    case 4:
                        printf("Uj esemeny: ");
                        scanf("%s", modositott_esemeny);
                        strncpy(mozgo->esemeny,modositott_esemeny, 200);
                        mozgo->esemeny[199]='\0'; econio_clrscr(); break;

                    case 5:
                        printf("Uj megjegyzes: ");
                        scanf("%s", modositott_megjegyzes);
                        strncpy(mozgo->megjegyzes,modositott_megjegyzes, 200);
                        mozgo->megjegyzes[199]='\0'; econio_clrscr(); break;

                    case 6:
                        if(lemarado==NULL){
                            Rekordok *ujeleje = mozgo->kov;
                            free(mozgo);
                            naplo=ujeleje;
                        }
                        else{
                            lemarado->kov=mozgo->kov;
                            free(mozgo);
                        }

                        break;


                    default: printf("Nincs ilyen menupont.\n");
                              printf("\n");
                              break;
                }


        }
        }while (n<7);
        return naplo;

}
