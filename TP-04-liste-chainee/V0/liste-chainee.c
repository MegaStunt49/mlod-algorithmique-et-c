#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Liste l;
	l = malloc(sizeof(Cellule));
	l->suiv=NULL;
	l->val=v;
	return l;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	Liste l2;
	l2 = malloc(sizeof(Cellule));
	l2->suiv = l;
	l2->val = v;
	return l2;
}


void afficheElement(Element e) {
	printf("%i ",e);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	Liste l2 = l;
	while (!estVide(l2)){
		afficheElement(l2->val);
		l2 = l2->suiv;
	}
	printf("\n");
}

// version recursive
void afficheListe_r(Liste l) {
	if (l!=NULL){
		afficheElement(l->val);
		afficheListe_r(l->suiv);
	}
}

void detruireElement(Element e) {}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste lcop = l;
	if (estVide(l)){return NULL;}
	while(lcop->suiv!=NULL){
		Liste suivant = lcop->suiv;
		detruireElement(lcop->val);
		free(lcop);
		lcop = suivant;
	}
}

// version récursive
void detruire_r(Liste l) {
	if (!estVide(l)){
		detruireElement(l->val);
		detruire_r(l);
		free(l);
	}
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	if (estVide(l)){
		l=creer(v);
		return l;
	}
	Liste lcop = l;
	while(lcop->suiv!=NULL){
		lcop = lcop->suiv;
	}
	lcop->suiv = creer(v);
	return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if (estVide(l)){
		l=creer(v);
		return l;
	}
	if (l->suiv!=NULL){
		ajoutFin_r( v, l->suiv);
	}
	else{
		l->suiv = creer(v);
	}
	return l;
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	Liste lcop = l;
	if (lcop->val == v){return lcop;}
	while(lcop->suiv!=NULL){
		lcop = lcop->suiv;
		if (lcop->val == v){return lcop;}
	}
	return NULL;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if (l->val == v){return l;}
	if (l->suiv != NULL) {return cherche_r(v,l->suiv);}
	return NULL;
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	Liste lcop = l;
	if (lcop->val == v){return lcop->suiv;}
	while(lcop->suiv!=NULL){
		Liste lcopint = lcop->suiv;
		if (lcopint->val == v){
			lcop->suiv = lcopint->suiv;
			free(lcopint);
			return l;
		}
		lcop = lcopint;
	}
	return l;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	Liste lsuiv = l->suiv;
	if (l->val == v){return lsuiv;}
	if (lsuiv != NULL){
		if (lsuiv->val == v){
			l->suiv = lsuiv->suiv;
			free(lsuiv);
			return l;
		}
		else{
			retirePremier_r(v,l->suiv);
			return l;
		}
	}
	return l;
}


void afficheEnvers_r(Liste l) {
	if (!estVide(l)){
		afficheEnvers_r(l->suiv);
		afficheElement(l->val);
	}
}



