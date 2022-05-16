#ifndef LETREHOZ_KERES_FELSZABADIT_H_INCLUDED
#define LETREHOZ_KERES_FELSZABADIT_H_INCLUDED

typedef struct Rekordok{
    int honap, nap, ora, perc;
    char hely[200];
    char esemeny[200];
    char megjegyzes[200];
    struct Rekordok *kov;
}Rekordok;

Rekordok *letrehoz(Rekordok *naplo, int honap, int nap, int ora, int perc, char *hely, char *esemeny, char *megjegyzes);
void keres(Rekordok *naplo);
void felszabadit(Rekordok *naplo);
int hanyadiknap(int honap, int nap);
int hetelsonap(int het);



#endif // LETREHOZ_KERES_FELSZABADIT_H_INCLUDED

