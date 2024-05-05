#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "fonctions.h"
int main()
{
    PR *t;
    int choix;
    t=(PR*)malloc(100*sizeof(PR));

    do{
        printf("\n************ MENU GESTION DE STOCK ************\n\n");
        printf("1-Ajouter nouvel produit\n");
        printf("2-Afficher un produit\n");
        printf("3-Modifier un produit\n");
        printf("4-Supprimer un produit\n");
        printf("5-Rechercher des produits par leur nom\n");
        printf("6-Rechercher des produits par le nom de l'utilisateur\n");
        printf("7-Trier les produits par le nom\n");
        printf("8-Trier les produits par le prix\n");
        printf("0-Fin de traitement\n");
        printf("Votre Choix :");scanf("%d",&choix);
        switch(choix)
        {
            case 1 :{ajouterPRD(t);break;}
            case 2 :{afficherPRD(t);break;}
            case 3 :{modifierPRD(t);break;}
            case 4 :{supprimerPRD(t);break;}
            case 5 :{afficherNom(t);break;}
            case 6 :{afficherNomU(t);break;}
            case 7 :{tri_nom();break;}
            case 0 :{printf("Fin de traitement\n");break;}
            default : printf("Choix errone !!! le choix entre [0- 6]\n\n");
        }

    }while(choix!=0);

return 0;
}
