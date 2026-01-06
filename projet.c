#include <stdio.h>
#include <string.h>

#define MAX 100 // Limite maximale d'enregistrements 

// Structure de donnée simple 
typedef struct {
    int id;
    char nom[50];
} Enregistrement;

Enregistrement tableau[MAX];
int nb_elements = 0;

// 1. Afficher le menu 
void afficher_menu() {
    printf("\n--- GESTIONNAIRE ---");
    printf("\n1. Ajouter");
    printf("\n2. Afficher tout");
    printf("\n3. Rechercher");
    printf("\n4. Supprimer");
    printf("\n0. Quitter");
    printf("\nChoix : ");
}

// 2. Ajouter un enregistrement 
void ajouter() {
    if (nb_elements < MAX) {
        printf("Entrez l'ID : ");
        scanf("%d", &tableau[nb_elements].id);
        printf("Entrez le nom : ");
        scanf("%s", tableau[nb_elements].nom);
        nb_elements++;
        printf("Ajoute avec succes !\n");
    } else {
        printf("Erreur : Tableau plein !\n");
    }
}

// 3. Afficher tous les enregistrements 
void afficher_tout() {
    if (nb_elements == 0) {
        printf("La liste est vide.\n");
        return;
    }
    for (int i = 0; i < nb_elements; i++) {
        printf("ID: %d | Nom: %s\n", tableau[i].id, tableau[i].nom);
    }
}

// 4. Rechercher par ID 
void rechercher() {
    int id_cherche;
    printf("Entrez l'ID a chercher : ");
    scanf("%d", &id_cherche);

    for (int i = 0; i < nb_elements; i++) {
        if (tableau[i].id == id_cherche) {
            printf("Trouve ! Nom : %s\n", tableau[i].nom);
            return;
        }
    }
    printf("ID non trouve .\n");
}

// 5. Supprimer un enregistrement 
void supprimer() {
    int id_suppr;
    printf("ID a supprimer : ");
    scanf("%d", &id_suppr);

    for (int i = 0; i < nb_elements; i++) {
        if (tableau[i].id == id_suppr) {
            // On décale les éléments pour boucher le vide
            for (int j = i; j < nb_elements - 1; j++) {
                tableau[j] = tableau[j + 1];
            }
            nb_elements--;
            printf("Supprime !\n");
            return;
        }
    }
    printf("ID non trouve.\n");
}

// Boucle principale courte 
int main() {
    int choix;
    do {
        afficher_menu();
        scanf("%d", &choix);

        if (choix == 1) ajouter();
        else if (choix == 2) afficher_tout();
        else if (choix == 3) rechercher();
        else if (choix == 4) supprimer();

    } while (choix != 0);

    printf("Fin du programme.\n");
    return 0;
}