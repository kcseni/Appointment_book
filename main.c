#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "debugmalloc.h"
#include "kilistaz.h"
#include "letrehoz_keres_felszabadit.h"
#include "modosit.h"
#include "econio.h"


int main(void){
    printf("Szokozok helyett hasznaljon '_' -t. Ekezetet beirni tilos! Max 200 karakter!\n");
    printf("\n");
    Rekordok *naplo = NULL;
    char valasz[200];
    printf("Szeretne beolvasni a probafajlt?(igen/nem)\n");
    scanf("%s", valasz);
    if(strcmp(valasz,"igen")==0){

        FILE *fp=fopen("proba.txt", "r+t");
        if (fp == NULL) {
            perror("Fajl megnyitasa sikertelen");

        }
        else{
        printf("A probafajl sikeresen beolvasva.\n");
        printf("\n");
        char sor[1000];
        while(fgets(sor, 1000, fp)>0){
            int honap, nap, ora, perc;
            char hely[200], esemeny[200], megjegyzes[200];
            sscanf(sor,"%d.%d.\t%d:%d\t%[^\t]\t%[^\t]\t%[^\n]", &honap, &nap, &ora, &perc, hely, esemeny, megjegyzes);
            naplo = letrehoz(naplo, honap, nap, ora, perc, hely, esemeny, megjegyzes);
        }

        fclose(fp);
    }
    }

    int szam;
    int honap, nap, ora, perc;
    char hely[200], esemeny[200], megjegyzes[200];
    printf("\n");
    do{
        printf(
               "1. Uj rekord letrehozasa\n"
               "2. Rekord (esemeny) modositasa\n"
               "3. Esemenyek kilistazasa\n"
               "4. Esemeny keresese\n"
               "5. Kilepes es mentes\n"
               "\n"
               "Adja meg a valasztott menupont szamat!\n");

       while(scanf("%d", &szam)!=1){
        printf("Nem szamot adtal meg.\n");
        scanf("%*[^\n]%*c");
        printf("\nAdja meg a valasztott menupont szamat!\n");
        }

       printf("\n");
       switch(szam){
           case 1:
                econio_clrscr();
                printf("Szokozok helyett hasznaljon '_' -t. Ekezetet beirni tilos! Max 200 karakter!\n");
                printf("\n");
                printf("Datum:");

                while(scanf("%d.%d.",&honap, &nap)!=2){
                    printf("Nem ho.nap. formaban adta meg.\n");
                    scanf("%*[^\n]%*c");
                    printf("Datum: \n");
                }
                printf("Ido:");

                while(scanf("%d:%d", &ora, &perc)!=2){
                    printf("Nem ora.perc. formaban adta meg.\n");
                    scanf("%*[^\n]%*c");
                    printf("Ido: \n");
                }
                printf("Hely:");
                scanf("%s", hely);
                printf("Esemeny:");
                scanf("%s", esemeny);
                printf("Megjegyzes:");
                scanf("%s", megjegyzes);
                naplo = letrehoz(naplo, honap, nap, ora, perc, hely, esemeny, megjegyzes);
                econio_clrscr(); break;
           case 2: econio_clrscr(); naplo=modosit(naplo); break;
           case 3: kilistaz(naplo); break;
           case 4: keres(naplo); break;
           case 5: felszabadit(naplo); break;
           default: printf("Nincs ilyen menupont.\n"); printf("\n"); break;

       }
    } while (szam!=5);


    return 0;
}
