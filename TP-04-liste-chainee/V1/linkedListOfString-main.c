#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

int main(void){
	Liste l;
	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");

	l = ajoutTete("wow",l);
	l = ajoutTete("wow",l);
	l = ajoutTete("w0w",l);
	l = ajoutTete("wow",l);
	l = ajoutTete("wow",l);
	l = ajoutTete("wow",l);
	l = ajoutTete("w0w",l);
	l = ajoutTete("wow",l);
	l = ajoutTete("wow",l);

	afficheListe_r(l);
	printf("\n");

	ajoutFin_i("99",l);
	afficheListe_i(l);

	ajoutFin_r("100",l);
	afficheListe_i(l);

	Liste p = cherche_i("200",l);
	printf("cherche_i(200) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_i("99",l);
	if(estVide(p))
		printf("cherche_i(99) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_i(99) : trouve ");
		afficheElement(p->val);
	 	printf("\n");
	}

	p = cherche_r("200",l);
	printf("cherche_r(200) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_r("99",l);
	if(estVide(p))
		printf("cherche_r(99) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_r(99) : trouve ");
		afficheElement(p->val);
		printf("\n");
	}

	printf("retirePremier_i(1)   : ");
	l = retirePremier_i("w0w",l);
	afficheListe_r(l);
	printf("\n");

	printf("retirePremier_i(1)   : ");
	l = retirePremier_i("wow",l);
	afficheListe_r(l);
	printf("\n");

	printf("retirePremier_i(100) : ");
	l = retirePremier_i("100",l);
	afficheListe_r(l);
	printf("\n");

	printf("retirePremier_r(4)   : ");
	l = retirePremier_r("wow",l);
	afficheListe_r(l);
	printf("\n");

	printf("retirePremier_r(4)   : ");
	l = retirePremier_r("w0w",l);
	afficheListe_r(l);
	printf("\n");

	printf("retirePremier_r(99)  : ");
	l = retirePremier_r("99",l);
	afficheEnvers_r(l);
	printf("\n");

	detruire_r(l);

	return EXIT_SUCCESS;
}