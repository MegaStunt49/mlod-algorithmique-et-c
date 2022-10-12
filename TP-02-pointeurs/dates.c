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
    m=mi;
    d->mois = m;
    printf("Saisissez l'année :\n");
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

unsigned int nbreJours(Mois mois, unsigned int annee){
    switch (mois){
        case Janvier: return 31;
        case Fevrier: return (annee%4==0 && annee%100!=0) || annee%400==0 ? 29 : 28 ;
        case Mars: return 31;
        case Avril: return 30;
        case Mai: return 31;
        case Juin: return 30;
        case Juillet: return 31;
        case Aout: return 31;
        case Septembre: return 30;
        case Octobre: return 31;
        case Novembre: return 30;
        case Decembre: return 31;
    }
    return 0;
}

bool dateValide(Date uneDate){
    return nbreJours(uneDate.mois,uneDate.annee)>=uneDate.jour && uneDate.jour>0 && uneDate.mois<=12;
}

unsigned int jourDansAnnee(Date uneDate){
    if (!dateValide(uneDate)){
        return 0;
    }
    int s=0;
    Mois m;
    int an = uneDate.annee;
    for (int i = 1; i<uneDate.mois;i++){
        m=i;
        s+=nbreJours(m,an);
    }
    return s+uneDate.jour;
}

int main(void) {
    Date d = creerDateParCopie();
    printf("%d\n",jourDansAnnee(d));
    return EXIT_SUCCESS;
}