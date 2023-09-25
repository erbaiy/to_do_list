#include <stdlib.h>
#include <stdio.h>
#include <string.h>
  int index = 0;// Number of tasks added
// Variables for statistics
int ident = 0;
int complet = 0;
int incomplet = 0;
struct tache
{
    int id;// Task ID
    char titre[10]; // Task title
    char description[100];// Task description
    int jour,mois,anne;// Task deadline
    char statut[14]; // Task status (0: incomplete, 1: complete)
};

struct tache task1[100]; // Array to store tasks
struct tache temp;
void ajouter()
{
      // Add a single task to the task1 array
    printf("entrer id ");
    scanf("%d",&task1[index].id);
    printf("entrer le titre ");
    scanf("%s",task1[index].titre);
    printf("entrer le description ");
    scanf(" %[^\n]s",task1[index].description);
    printf("entrer le dedline DD/MM/YYYY ");
    scanf("%d/%d/%d",&task1[index].jour,&task1[index].mois,&task1[index].anne);
    printf("entrer le statut de ce titre \n");

    int c;
    printf("1- a realise 2-en cours de realisation,  3-finalisee ");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        strcpy(task1[index].statut, "realiser");
        break;
    case 2:
        strcpy(task1[index].statut, " en cours de realisation");
        break;
    case 3:
        strcpy(task1[index].statut, "finalisee ");
        break;
    default:

        printf("not value");
        break;
    }
       index++;
}
void afichage()
{
    // afichage
    int v;
    printf("[1]-Trier les taches par ordre alphabetique\n");
    printf("[2]-Trier les taches par deadline\n");
    printf("[3]-Afficher les taches dont le deadline est dans 3 jours ou moins\n");
    printf("__________________________________________________\n");
    printf("choiser un nombre : \n");
    scanf("%d", &v);
    switch (v)
    {
    case 1://Trier les taches par ordre alphabetique
        for (int i = 0; i<index;i++)
        {
            for (int j = i + 1; j<index;j++)
            {
                if (strcmp(task1[i].titre,task1[j].titre) > 0)
                {
                    temp=task1[i];
                    task1[i]=task1[j];
                   task1[j]=temp ;
                }
            }
            printf("le %d tach est : \n id : %d \n le titre est : %s \n le description est : %s \n le dead line est: %d/%d/%d \n le statutest : %s : ", i + 1,task1[i].id,task1[i].titre,task1[i].description,task1[i].jour,task1[i].mois,task1[i].anne,task1[i].statut);
        }
        break;
    case 2://Trier les taches par deadline

        break;
    case 3://Afficher les taches dont le deadline est dans 3 jours ou moins
        break;
    }
}


void ajouter_plusieu()
{
    int d;
    printf("enter the nomber of task you wanna apend :\n");
    scanf("%d", &d);
    for (int i = 1; i <= d; i++)
    {
        ajouter();
    }
}
void statistique()
{
    int k;
    printf("[1]-Afficher le nombre total des tâches.\n2[2]Afficher le nombre de tâches complètes et incomplètes.\n[3]Afficher le nombre de jours restants jusqu'au délai de chaque tâche.");
    scanf("%d", &k);
    switch (k)
    {
    case 1://Afficher le nombre total des tâches
        printf("%d \n",index);
        break;
    case 2://Afficher le nombre de tâches complètes et incomplètes.

        for (int i = 0; i < index; i++)
        {
            if (strcmp(task1[i].statut, "finalisee") == 0)
            {
                complet++;
            }
            else
                incomplet++;
        }
        printf("le nommber des tach complet est %d\n", complet);
        printf("le nommber des tach incomplet est %d\n", incomplet);
         break;

    default:
        printf("try again");
        break;
    }
}
void recherch()
{
    int q,newid;
    char new_titre[50];
    printf("[1]_Rechercher une tâche par son Identifiant \n");
    printf("[2]-Rechercher une tâche par son Titre \n");
    printf("choisir 1 ou 2: \n");
    scanf("%d",&q);
    switch (q)
    {
    case 1://Rechercher une tâche par son Identifiant
        printf("entre le id\n");
        scanf("%d", &newid);
        for (int i = 0; i < index; i++)
        {
            if (newid == task1[i].id)
            {
             printf("le %d tach est : \n id : %d \n titre : %s \n description : %s \n le dead line : %d/%d/%d \n statut : %s : ", i + 1, task1[i].id, task1[i].titre, task1[i].description, task1[i].jour,task1[i].mois,task1[i].anne, task1[i].statut);
            }
        }
        break;
    case 2://Rechercher une tâche par son Titre
        printf("entre le titre \n");
        scanf("%s",new_titre);
        for (int i = 0; i < index; i++)
        {
            if (strcmp(new_titre, task1[i].titre) == 0)
            {
            printf("le %d tach est : \n id : %d \n titre : %s \n description : %s \n le dead line : %d/%d/%d \n statut : %s : ", i + 1, task1[i].id, task1[i].titre, task1[i].description, task1[i].jour,task1[i].mois,task1[i].anne, task1[i].statut);
            }
        }
        break;
    }
}
void modification(){
    int w,new_id,m;
    char newdescription[200];
    int new_jour,new_moi,new_anee;
    printf("[1]Modifier la description d'une tâche\n");
    printf("[2]Modifier le statut d’une tâche\n");
    printf("[3]Modifier le deadline d’une tâche\n");
    printf("choisir un nomber:\n");
    scanf("%d",&w);
    switch(w){
case 1:
    printf("enter the id of your tach you wanna modifie :\n ");
    scanf("%d",&new_id);
    for(int i=0;i<index;i++){
        if(new_id == task1[i].id){
            printf("type the new description :\n ");
            scanf(" %[^\n]s",newdescription);
            strcpy(task1[i].description,newdescription);
        }
    }
    break;
case 2:
    printf("entrer le id de tach you wanna modifie : \n");
    scanf("%d",&new_id);
    printf("1- a realise 2-en cours de realisation,  3-finalisee ");
    scanf("%d",&m);
    for(int i=0;i<index;i++){
        if(new_id == task1[i].id){
            switch (m){
    case 1:
        strcpy(task1[i].statut, "realiser");
        break;
    case 2:
        strcpy(task1[i].statut, " en cours de realisation");
        break;
    case 3:
        strcpy(task1[i].statut, "finalisee ");
        break;
                }
    }

    }
    break;
    case 3:
    printf("enter id the tach you wanna modifie\n");
    scanf("%d",&new_id);
    printf("enter the new dealine\n");
    scanf("%d/%d/%d",&new_jour,&new_moi,&new_anee);
    for(int i=0;i<index;i++){
        if(new_id == task1[i].id){
            task1[i].jour = new_jour;
            task1[i].mois = new_moi;
            task1[i].anne = new_anee;

        }
    }
    break;
    default:
        printf("invalid number");
};
};
void supprime(){
    int new_id;
    printf("entrer id de tach que vous souhaitez supprime \n");
    scanf("%d",&new_id);
    for(int i=0;i<index;i++){
        if(new_id==task1[i].id){
            for(int j=i;j<index - 1;j++){
                task1[j]=task1[j+1];
            }
            index--;
        }
    }
};
void menu()
{
    printf("===================       MENU        =======================\n");
    printf("                   ___________________                         |\n");
    printf("|1-ajouter une nouvelle tache                                  |\n");
    printf("|2-ajouter une plusieurs taches                                |\n");
    printf("|3-afficher la liste de tout les tache                         |\n");
    printf("|4-modifier une tache                                          |\n");
    printf("|5-Statistiques                                                |\n");
    printf("|6-recherche                                                   |\n");
    printf("|7-supprime                                                    |\n");
    printf("===============================================================n\n");
}
int main()
{
    int choice;
    do
    {
        menu();
        printf("entrer votre choice :\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            ajouter();
            break;
        case 2:
            ajouter_plusieu();
            break;
        case 3:
            afichage();
            break;
        case 4:
            modification();
            break;
        case 5:
            statistique();
            break;
        case 6:
            recherch();
                break;
        case 7:
            supprime();
            break;
    }
        }while (choice != 0);
    return 0;
}
