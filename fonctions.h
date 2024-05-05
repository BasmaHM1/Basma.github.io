#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#define MAX_PRODUCTS 100
typedef struct{
    int jour;
    int mois;
    int annee;
}date;
typedef struct{
    int ID;//unique
    char Desc[1234];
    char NomU[20];
    char NomP[20];
    float prix;
    float Quantite;
    float seuil;
    date DTE ;
    date DTS ;
}PR;
FILE * fp;
int N=0;


void ajouterPRD(PR *e);
void afficherPRD(PR *e);
void modifierPRD(PR *e);
void supprimerPRD(PR *e);
void afficherNom(PR *e);
void afficherNomU(PR *e);
void tri_nom ();
void tri_prix ();

void ajouterPRD(PR *e)
{
    e=(PR*)malloc(100*sizeof(PR));
    int IDr=0,tr=0;
    fp=fopen("gestion.csv","at+");
    if(fp==NULL)
    {
        printf("Impossible d'ouvrir le fichier\n");
        exit(1);
    }
    printf("Donner l'identifiant : ");scanf("%d",&IDr);

    while(!feof(fp))
    {
        fscanf(fp,"%d \n%s\n%s\n%s\n%f\n%f\n%f\n%d\n%d\n%d\n%d\n%d\n%d\n",&e->ID,e->NomP,e->Desc,e->NomU,&e->prix,&e->Quantite,&e->seuil,&e->DTE.jour,&e->DTE.mois,&e->DTE.annee,&e->DTS.jour,&e->DTS.mois,&e->DTS.annee);
        if((e->ID)==IDr)
        {
            tr=1;break;
        }
    }
    if(tr==1)
        printf("Produit existe deja!!!\n");
    else
    {
        N++;
        printf("Donner le nom du produit : ");scanf("%s",e->NomP);
        printf("Donner la description : ");scanf("%s",e->Desc);
        printf("Donner le nom de l'utilisateur : ");scanf("%s",e->NomU);
        do{printf("Donner le prix : ");scanf("%f",&e->prix);}while(e->prix<0);
        do{printf("Donner la quantite : ");scanf("%f",&e->Quantite);}while(e->Quantite<0);
        printf("Donner le seuil : ");scanf("%f",&e->seuil);
        printf("Donner la date de derniere entree en stock : ");scanf("%d %d %d",&e->DTE.jour,&e->DTE.mois,&e->DTE.annee);
        printf("Donner la date de derniere sortie en stock : ");scanf("%d %d %d",&e->DTS.jour,&e->DTS.mois,&e->DTS.annee);
        fprintf(fp,"%d \n%s\n%s\n%s\n%.2f\n%.2f\n%.2f\n%d %d %d\n%d %d %d\n",IDr,e->NomP,e->Desc,e->NomU,e->prix,e->Quantite,e->seuil,e->DTE.jour,e->DTE.mois,e->DTE.annee,e->DTS.jour,e->DTS.mois,e->DTS.annee);
     }
     fclose(fp);


}


void afficherPRD(PR *e)
{
    e=(PR*)malloc(100*sizeof(PR));
    int IDr,tr=0;
    fp=fopen("gestion.csv","rt");
    if(fp==NULL)
    {
        printf("Impossible d'ouvrir le fichier\n");
        exit(1);
    }
    printf("Donner l'identifiant : ");scanf("%d",&IDr);

    while(!feof(fp))
    {
        fscanf(fp,"%d \n%s\n%s\n%s\n%f\n%f\n%f\n%d\n%d\n%d\n%d\n%d\n%d\n",&e->ID,e->NomP,e->Desc,e->NomU,&e->prix,&e->Quantite,&e->seuil,&e->DTE.jour,&e->DTE.mois,&e->DTE.annee,&e->DTS.jour,&e->DTS.mois,&e->DTS.annee);
        if((e->ID)==IDr)
        {
            tr=1;
            printf("Nom : %s\n",e->NomP);
            printf("Description : %s\n",e->Desc);
            printf("Nom Utilisateur : %s\n",e->NomU);
            printf("Prix : %.2f\n",e->prix);
            printf("Quantite : %.2f\n",e->Quantite);
            printf("Seuild'alerte de stock : %.2f\n",e->seuil);
            printf("Date de derniere entree en stock : %d %d %d\n",e->DTE.jour,e->DTE.mois,e->DTE.annee);
            printf("Date de derniere sortie de stock : %d %d %d\n",e->DTS.jour,e->DTS.mois,e->DTS.annee);

        }
    }
    if(tr==0)
        printf("Produit n'existe pas !!!\n");

     fclose(fp);
}

void modifierPRD(PR *e)
{
   e=(PR*)malloc(100*sizeof(PR));
    int choix,IDr=0,tr=0;
    FILE* stock;
    fp=fopen("gestion.csv","rt");
    if(fp==NULL)
    {
        printf("Impossible d'ouvrir le fichier\n");
        exit(1);
    }
    stock=fopen("stock.csv","wt");
    if(stock==NULL)
    {
        printf("Impossible d'ouvrir le fichier\n");
        exit(1);
    }
    printf("Donner l'identifiant du produit a modifier : ");scanf("%d",&IDr);

     while(fscanf(fp,"%d \n%s\n%s\n%s\n%f\n%f\n%f\n%d\n%d\n%d\n%d\n%d\n%d\n",&e->ID,e->NomP,e->Desc,e->NomU,&e->prix,&e->Quantite,&e->seuil,&e->DTE.jour,&e->DTE.mois,&e->DTE.annee,&e->DTS.jour,&e->DTS.mois,&e->DTS.annee)==13)
    {
         if((e->ID)==IDr)
        {
            tr=1;
             do{
                printf("\n<<<<<<<< MENU DE MODIFICATION >>>>>>>>\n\n");
                printf("1-Modifier le Nom du Produit \n");
                printf("2-Modifier la Description\n");
                printf("3-Modifier le Nom de l'utilisateur\n");
                printf("4-Modifier le Prix  \n");
                printf("5-Modifier la Quantite \n");
                printf("6-Modifier le Seuil \n");
                printf("0-Fin de traitement\n");
                printf("Votre Choix :");scanf("%d",&choix);
                switch(choix)
                {
                   case 1 :{printf("Donner le nouveau nom : ");scanf("%s",e->NomP);break;}
                   case 2 :{printf("Donner la nouvelle description : ");scanf("%s",e->Desc);break;}
                   case 3 :{printf("Donner le nouveau nom d'utilisateur : ");scanf("%s",e->NomU);break;}
                   case 4 :{printf("Donner le nouveau PRIX : ");scanf("%s",e->prix);break;}
                   case 5 :{printf("Donner la nouvelle Quantite : ");scanf("%s",e->Quantite);break;}
                   case 6 :{printf("Donner le nouveau seuil : ");scanf("%s",e->seuil);break;}
                   case 0 :{printf("Fin de traitement\n");break;}
                   default : printf("Choix errone !!! le choix entre [0- 6]\n\n");
                }

             }while(choix!=0);

        }
       fprintf(stock,"%d \n%s\n%s\n%s\n%.2f\n%.2f\n%.2f\n%d %d %d\n%d %d %d\n",IDr,e->NomP,e->Desc,e->NomU,e->prix,e->Quantite,e->seuil,e->DTE.jour,e->DTE.mois,e->DTE.annee,e->DTS.jour,e->DTS.mois,e->DTS.annee);
    }
    fclose(fp);fclose(stock);
    remove("gestion.csv");
    rename("stock.csv","gestion.csv");
    if(tr==0)
        printf("Le produit n'existe pas !!!\n");
    else
        printf("Le produit est modifie !!!\n");
}

void supprimerPRD(PR *e)
{
   e=(PR*)malloc(100*sizeof(PR));
    int choix,IDr=0,tr=0;
    FILE* stock;
    fp=fopen("gestion.csv","rt");
    if(fp==NULL)
    {
        printf("Impossible d'ouvrir le fichier\n");
        exit(1);
    }
    stock=fopen("stock.csv","wt");
    if(stock==NULL)
    {
        printf("Impossible d'ouvrir le fichier\n");
        exit(1);
    }
    printf("Donner l'identifiant du produit a supprimer : ");scanf("%d",&IDr);

     while(fscanf(fp,"%d \n%s\n%s\n%s\n%f\n%f\n%f\n%d\n%d\n%d\n%d\n%d\n%d\n",&e->ID,e->NomP,e->Desc,e->NomU,&e->prix,&e->Quantite,&e->seuil,&e->DTE.jour,&e->DTE.mois,&e->DTE.annee,&e->DTS.jour,&e->DTS.mois,&e->DTS.annee)==13)
    {
         if((e->ID)!=IDr)
           fprintf(stock,"%d \n%s\n%s\n%s\n%.2f\n%.2f\n%.2f\n%d %d %d\n%d %d %d\n",IDr,e->NomP,e->Desc,e->NomU,e->prix,e->Quantite,e->seuil,e->DTE.jour,e->DTE.mois,e->DTE.annee,e->DTS.jour,e->DTS.mois,e->DTS.annee);
         else
            tr=1;
    }
    fclose(fp);fclose(stock);
    remove("gestion.csv");
    rename("stock.csv","gestion.csv");
    if(tr==0)
        printf("Le produit n'existe pas !!!\n");
    else{
        N--;
        printf("Le produit est supprime !!!\n");
    }
}

void afficherNom(PR *e)
{
   e=(PR*)malloc(100*sizeof(PR));
    char Pnom[20],tr=0;
    fp=fopen("gestion.csv","rt");
    if(fp==NULL)
    {
        printf("Impossible d'ouvrir le fichier\n");
        exit(1);
    }
    printf("Donner le nom du produit : ");scanf("%s",Pnom);

    while(!feof(fp))
    {
        fscanf(fp,"%d \n%s\n%s\n%s\n%f\n%f\n%f\n%d\n%d\n%d\n%d\n%d\n%d\n",&e->ID,e->NomP,e->Desc,e->NomU,&e->prix,&e->Quantite,&e->seuil,&e->DTE.jour,&e->DTE.mois,&e->DTE.annee,&e->DTS.jour,&e->DTS.mois,&e->DTS.annee);
        if(strcmp(e->NomP,Pnom)==0)
        {
            tr=1;
            printf("\n>>>> Les infos du produit : \n");
            printf("ID  :  %d\n",e->ID);
            printf("Nom : %s\n",e->NomP);
            printf("Description : %s\n",e->Desc);
            printf("Nom Utilisateur : %s\n",e->NomU);
            printf("Prix : %.2f\n",e->prix);
            printf("Quantite : %.2f\n",e->Quantite);
            printf("Seuild'alerte de stock : %.2f\n",e->seuil);
            printf("Date de derniere entree en stock : %d %d %d\n",e->DTE.jour,e->DTE.mois,e->DTE.annee);
            printf("Date de derniere sortie de stock : %d %d %d\n",e->DTS.jour,e->DTS.mois,e->DTS.annee);

        }
    }
    if(tr==0)
        printf("Produit n'existe pas !!!\n");

     fclose(fp);
}

void afficherNomU(PR *e)
{
   e=(PR*)malloc(100*sizeof(PR));
    char Unom[20],tr=0;
    fp=fopen("gestion.csv","rt");
    if(fp==NULL)
    {
        printf("Impossible d'ouvrir le fichier\n");
        exit(1);
    }
    printf("Donner le nom de l'utilisateur : ");scanf("%s",Unom);

    while(!feof(fp))
    {
        fscanf(fp,"%d \n%s\n%s\n%s\n%f\n%f\n%f\n%d\n%d\n%d\n%d\n%d\n%d\n",&e->ID,e->NomP,e->Desc,e->NomU,&e->prix,&e->Quantite,&e->seuil,&e->DTE.jour,&e->DTE.mois,&e->DTE.annee,&e->DTS.jour,&e->DTS.mois,&e->DTS.annee);
        if(strcmp(e->NomU,Unom)==0)
        {
            tr=1;
            printf("\n>>>> Les infos du produit : \n");
            printf("ID  :  %d\n",e->ID);
            printf("Nom : %s\n",e->NomP);
            printf("Description : %s\n",e->Desc);
            printf("Nom Utilisateur : %s\n",e->NomU);
            printf("Prix : %.2f\n",e->prix);
            printf("Quantite : %.2f\n",e->Quantite);
            printf("Seuild'alerte de stock : %.2f\n",e->seuil);
            printf("Date de derniere entree en stock : %d %d %d\n",e->DTE.jour,e->DTE.mois,e->DTE.annee);
            printf("Date de derniere sortie de stock : %d %d %d\n",e->DTS.jour,e->DTS.mois,e->DTS.annee);

        }
    }
    if(tr==0)
        printf("Produit n'existe pas !!!\n");

     fclose(fp);
}

void tri_nom() {
    PR produits[MAX_PRODUCTS];
    int choix,nombre_produits = 0;
    PR temp;

    // Ouvrir le fichier en mode lecture
    fp = fopen("gestion.csv", "rt");
    if (fp == NULL) {
        printf("Impossible d'ouvrir le fichier\n");
        exit(1);
    }

    // Lire les produits du fichier et les stocker dans un tableau
    while (nombre_produits < MAX_PRODUCTS && fscanf(fp, "%d \n%s\n%s\n%s\n%f\n%f\n%f\n%d\n%d\n%d\n%d\n%d\n%d\n", &produits[nombre_produits].ID, produits[nombre_produits].NomP, produits[nombre_produits].Desc, produits[nombre_produits].NomU, &produits[nombre_produits].prix, &produits[nombre_produits].Quantite, &produits[nombre_produits].seuil, &produits[nombre_produits].DTE.jour, &produits[nombre_produits].DTE.mois, &produits[nombre_produits].DTE.annee, &produits[nombre_produits].DTS.jour, &produits[nombre_produits].DTS.mois, &produits[nombre_produits].DTS.annee) == 13) {
        nombre_produits++;
    }

    // Fermer le fichier
    fclose(fp);

    // Tri des produits par leur nom en utilisant strcmp()

    for (int i = 0; i < nombre_produits - 1; i++) {
        for (int j = 0; j < nombre_produits - i - 1; j++) {
            if (strcmp(produits[j].NomP, produits[j + 1].NomP) > 0) {
                temp = produits[j];
                produits[j] = produits[j + 1];
                produits[j + 1] = temp;
            }
        }
    }

    // Ouvrir le fichier en mode écriture
    fp = fopen("gestion.csv", "wt");
    if (fp == NULL) {
        printf("Impossible d'ouvrir le fichier\n");
        exit(1);
    }

    // Réécrire le fichier avec les produits triés par nom
    for (int i = 0; i < nombre_produits; i++) {
        fprintf(fp, "%d \n%s\n%s\n%s\n%.2f\n%.2f\n%.2f\n%d %d %d\n%d %d %d\n", produits[i].ID, produits[i].NomP, produits[i].Desc, produits[i].NomU, produits[i].prix, produits[i].Quantite, produits[i].seuil, produits[i].DTE.jour, produits[i].DTE.mois, produits[i].DTE.annee, produits[i].DTS.jour, produits[i].DTS.mois, produits[i].DTS.annee);
    }

    // Fermer le fichier
    fclose(fp);

    printf("Produits triés par nom dans le fichier.\n");
}


void tri_prix() {
    PR produits[MAX_PRODUCTS];
    int nombre_produits = 0;
    PR temp;

    // Ouvrir le fichier en mode lecture
    fp = fopen("gestion.csv", "rt");
    if (fp == NULL) {
        printf("Impossible d'ouvrir le fichier\n");
        exit(1);
    }

    // Lire les produits du fichier et les stocker dans un tableau
    while (nombre_produits < MAX_PRODUCTS && fscanf(fp, "%d \n%s\n%s\n%s\n%f\n%f\n%f\n%d\n%d\n%d\n%d\n%d\n%d\n", &produits[nombre_produits].ID, produits[nombre_produits].NomP, produits[nombre_produits].Desc, produits[nombre_produits].NomU, &produits[nombre_produits].prix, &produits[nombre_produits].Quantite, &produits[nombre_produits].seuil, &produits[nombre_produits].DTE.jour, &produits[nombre_produits].DTE.mois, &produits[nombre_produits].DTE.annee, &produits[nombre_produits].DTS.jour, &produits[nombre_produits].DTS.mois, &produits[nombre_produits].DTS.annee) == 13) {
        nombre_produits++;
    }

    // Fermer le fichier
    fclose(fp);

    // Tri des produits par leur prix en utilisant le tri à bulles
    for (int i = 0; i < nombre_produits - 1; i++) {
        for (int j = 0; j < nombre_produits - i - 1; j++) {
            if (produits[j].prix > produits[j + 1].prix) {
                temp = produits[j];
                produits[j] = produits[j + 1];
                produits[j + 1] = temp;
            }
        }
    }

    // Ouvrir le fichier en mode écriture
    fp = fopen("gestion.csv", "wt");
    if (fp == NULL) {
        printf("Impossible d'ouvrir le fichier\n");
        exit(1);
    }

    // Réécrire le fichier avec les produits triés par prix
    for (int i = 0; i < nombre_produits; i++) {
        fprintf(fp, "%d \n%s\n%s\n%s\n%.2f\n%.2f\n%.2f\n%d %d %d\n%d %d %d\n", produits[i].ID, produits[i].NomP, produits[i].Desc, produits[i].NomU, produits[i].prix, produits[i].Quantite, produits[i].seuil, produits[i].DTE.jour, produits[i].DTE.mois, produits[i].DTE.annee, produits[i].DTS.jour, produits[i].DTS.mois, produits[i].DTS.annee);
    }

    // Fermer le fichier
    fclose(fp);

    printf("Produits tries par prix dans le fichier.\n");
}


#endif // FONCTIONS_H_INCLUDED
