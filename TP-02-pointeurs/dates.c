#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "dates.h"

char* getMonthName(Mois m){
    switch (m){
        case Janvier: return "Janvier";
        case Fevrier: return "Fevrier";
        case Mars: return "Mars";
        case Avril: return "Avril";
        case Mai: return "Mai";
        case Juin: return "Juin";
        case Juillet: return "Juillet";
        case Aout: return "Aout";
        case Septembre: return "Septembre";
        case Octobre: return "Octobre";
        case Novembre: return "Novembre";
        case Decembre: return "Decembre";
    }
    return "";
};

void initialiseDate(Date *d){
    int i;
    int a;
    int mi;
    Mois m;
    printf("Saisissez le jour :\n");
    scanf("%d", &i);
    d->jour = i;
    printf("Saisissez le numéro du mois :\n");
    scanf("%d", &mi);
    m=mi-1;
    d->mois = m;
    printf("Saisissez l'année' :\n");
    scanf("%d", &a);
    d->annee = a;
}

void afficheDate(Date *d){
    int i = d->jour;
    int a = d->annee;
    Mois m = d->mois;
    printf("La date est le %d ",i);
    printf("%s",getMonthName(m));
    printf(" %d \n",a);
}

Date creerDateParCopie(){
    Date d;
    initialiseDate(&d);
    return d;
}

Date *newDate(){
    Date *d;
    d=malloc(sizeof(Date));
    initialiseDate(d);
    return d;
}

int main(void) {
    Date *date;
    date = newDate();
    afficheDate(date);
    free(date);
    return EXIT_SUCCESS;
}