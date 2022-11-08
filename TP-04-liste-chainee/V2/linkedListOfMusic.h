#pragma once

#include <stdbool.h>

typedef struct music {
	char* name;
	char* artist;
	char* album;
	char* genre;
    int diskNumber;
    int trackNumber;
    int year;
} Music;

struct cellule_s {
	Music val;
	struct cellule_s* suiv;
};

typedef struct cellule_s Cellule;

typedef Cellule* Liste;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l);

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Music v);

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Music v, Liste l);

void afficheMusic(Music e);

bool equalsMusic(Music e1, Music e2);

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l);

// version recursive
void afficheListe_r(Liste l);

void detruireMusic(Music e);

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l);

// version récursive
void detruire_r(Liste l);

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Music v, Liste l);

// version recursive
Liste ajoutFin_r(Music v, Liste l);

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Music v,Liste l);

// version récursive
Liste cherche_r(Music v,Liste l);

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Music v, Liste l);

// version recursive
Liste retirePremier_r(Music v, Liste l);


void afficheEnvers_r(Liste l);
