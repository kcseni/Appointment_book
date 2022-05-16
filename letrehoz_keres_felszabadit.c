#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "letrehoz_keres_felszabadit.h"
#include "modosit.h"
#include "kilistaz.h"


Rekordok *letrehoz(Rekordok *naplo, int honap, int nap, int ora, int perc, char *hely, char *esemeny, char *megjegyzes) {
   Rekordok *uj= (Rekordok*) malloc(sizeof(Rekordok));
   uj->honap = honap;
   uj->nap=nap;
   uj->ora=ora;
   uj->perc=perc;
   strncpy(uj->hely, hely, 200);
   uj->hely[199]='\0';
   strncpy(uj->esemeny, esemeny, 200);
   uj->esemeny[199]='\0';
   strncpy(uj->megjegyzes, megjegyzes, 200);
   uj->megjegyzes[199]='\0';
   uj->kov = naplo;
   return uj;
}

void keres(Rekordok *naplo){
    printf("\n");
    printf("Szokozok helyett hasznaljon '_' -t. Ekezetet beirni tilos! Max 200 karakter!\n");
    printf("\n");
    printf("Adja meg az esemeny nevet!\n");
    char esemeny[200];
    scanf("%s", esemeny);

    printf("\n");

    Rekordok *mozgo=naplo;
    while(mozgo!=NULL && (strcmp(mozgo->esemeny,esemeny)!=0)){

        mozgo=mozgo->kov;
    }
    if(mozgo==NULL){
        printf("Nincs ilyen esemeny.\n");
        printf("\n");
    }
    else{

        printf("%d.%d. %d:%d %s %s %s\n",mozgo->honap, mozgo->nap, mozgo->ora, mozgo->perc, mozgo->hely, mozgo->esemeny, mozgo->megjegyzes);
        printf("\n");
    }


}

void felszabadit(Rekordok *naplo){
    printf("Szokozok helyett hasznaljon '_' -t. Ekezetet beirni tilos! Max 200 karakter!\n");
    printf("\n");
    char fajlnev[200];
    printf("Adja meg a fajl nevet, amibe menteni szeretne!\n");
    scanf("%s", fajlnev );
    FILE *fp=fopen(fajlnev, "wt");
    if (fp == NULL) {
        perror("Fajl megnyitasa sikertelen");
        return;
    }
    Rekordok *mozgo;
    for(mozgo=naplo; mozgo!=NULL; mozgo=mozgo->kov){
        fprintf(fp,"%d.%d.\t%d:%d\t%s\t%s\t%s\n", mozgo->honap, mozgo->nap, mozgo->ora, mozgo->perc, mozgo->hely, mozgo->esemeny, mozgo->megjegyzes);
    }
    fclose(fp);
    Rekordok *iter;
    iter=naplo;
    while(iter!=NULL){
        Rekordok *kov= iter->kov;
        free(iter);
        iter = kov;
    }
}

    int hetelsonap(int het){
        int elso=(het*7)-6;
        return elso;
    }

    int hanyadiknap(int honap, int nap){
        int honapok[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
        int hanyadik_nap=honapok[honap-1]+nap;
        return hanyadik_nap;
    }
