#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "kilistaz.h"
#include "letrehoz_keres_felszabadit.h"
#include "modosit.h"



void kilistaz(Rekordok *naplo){
    printf("Szokozok helyett hasznaljon '_' -t. Ekezetet beirni tilos! Max 200 karakter!\n");
    int n;
    int listaz_honap;
    int listaz_nap;
    int het;

    Rekordok *mozgo;
    do{

        printf(
               "1. Nap szerinti listazas\n"
               "2. Het szerinti listazas\n"
               "3. Honap szerinti listazas\n"
               "\n"
               "Adja meg a valasztott menupont szamat!\n");


       while(scanf("%d", &n)!=1){
        printf("Nem szamot adtal meg.\n");
        scanf("%*[^\n]%*c");
        printf("\nAdja meg a valasztott menupont szamat!\n");
        }


        printf("\n");

        switch(n){
            case 1:
                printf("Hanyadik honap hanyadik napja? (ho.nap.): ");

                while(scanf("%d.%d.",&listaz_honap, &listaz_nap )!=2){
                    printf("Nem ho.nap. alakban adta meg.\n");
                    scanf("%*[^\n]%*c");
                    printf("\nHanyadik honap hanyadik napja? (ho.nap.): ");
                }

                bool vanilyenesemeny;
                for(mozgo=naplo; mozgo!=NULL; mozgo=mozgo->kov){
                    if((mozgo->honap==listaz_honap)&&(mozgo->nap==listaz_nap)){
                        vanilyenesemeny=true;
                        printf("%d.%d. %d:%d %s %s %s\n", mozgo->honap, mozgo->nap, mozgo->ora, mozgo->perc, mozgo->hely, mozgo->esemeny, mozgo->megjegyzes);
                    }

                }

                if(!vanilyenesemeny){
                    printf("Nincs ilyen esemeny.\n");
                }
                printf("\n");
                break;
            case 2:

                printf("Hanyadik het?(het.): ");

                while(scanf("%d.",&het)!=1){
                    printf("Nem het. alakban adta meg.\n");
                    scanf("%*[^\n]%*c");
                    printf("\nHanyadik het?(het.): ");
                }

                int i;
                for(mozgo=naplo; mozgo!=NULL; mozgo=mozgo->kov){
                    for(i=hetelsonap(het); i<hetelsonap(het)+7; i++){
                        if(hanyadiknap(mozgo->honap, mozgo->nap)==i){
                            vanilyenesemeny=true;
                            printf("%d.%d. %d:%d %s %s %s\n", mozgo->honap, mozgo->nap, mozgo->ora, mozgo->perc, mozgo->hely, mozgo->esemeny, mozgo->megjegyzes);
                        }
                    }
                }

                if(!vanilyenesemeny){
                    printf("Nincs ilyen esemeny.\n");
                }
                printf("\n");
                break;
            case 3:

                printf("Hanyadik honap?(ho.): ");

                while(scanf("%d.", &listaz_honap)!=1){
                    printf("Nem honap. alakban adta meg.\n");
                    scanf("%*[^\n]%*c");
                    printf("\nHanyadik honap?(ho.): ");
                }

                for(mozgo=naplo; mozgo!=NULL; mozgo=mozgo->kov){
                    if(mozgo->honap==listaz_honap){
                        vanilyenesemeny=true;
                        printf("%d.%d. %d:%d %s %s %s\n", mozgo->honap, mozgo->nap, mozgo->ora, mozgo->perc, mozgo->hely, mozgo->esemeny, mozgo->megjegyzes);
                    }
                }

                if(!vanilyenesemeny){
                    printf("Nincs ilyen esemeny.\n");
                }
                printf("\n");
                break;
            default: printf("Nincs ilyen menupont.\n"); printf("\n"); break;

        }


}while(n<4);
}
