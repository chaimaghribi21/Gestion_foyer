#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include <gtk/gtk.h>
typedef struct Foyer
{
char nom[20];
char prenom[20];
char paiement[10];
int num_chambre;
char etage[20];
char id[20];
}foyer;

void ajouter(foyer f);
void modifier(foyer g);
void supprimer(char idt[20]);
void afficher(GtkWidget *liste);
int verif_id(char id[]);
foyer recherche( char id[]);
void liste_alarmes(char tab[100][100], char fich[] );

#endif
