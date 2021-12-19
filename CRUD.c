#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "callbacks.h"
#include<string.h>
#include"CRUD.h"

//Ajouter un menu 

void ajouter_menu( menu t)
{
FILE*f=NULL; //flot de donnée
f=fopen("menu.txt","a+");// creation du fichier menu .txt et ouverture en  mode lecture et ecriture a la fin
fprintf(f,"%s %s %s %s %s %s \n",t.jour,t.temps,t.date,t.entree,t.plat_principal,t.dessert); //f variable de type file 
fclose(f);
 //retour NULL si operation fini 
}
//********************************************************





//verifier l'existance 

int exist_menu(char*jour, char *temps){
FILE*f=NULL;
menu t;
f=fopen("menu.txt","r");// ouverture du fichier menu en  mode lecture 
while(fscanf(f,"%s %s %s %s %s %s \n",t.jour,t.temps,t.date,t.entree,t.plat_principal,t.dessert)!=EOF){
if(strcmp(t.jour,jour)==0 &&strcmp(t.temps,temps)==0)
return 1;   //id existe deja 
}
fclose(f);
return 0;
}

//modifier
void modifier_menu(char *jour, char *temps, menu MN)

{

	menu MN1;
   	FILE *f=NULL;
    	FILE *f2=NULL;
    	f=fopen("menu.txt","r");
    	f2=fopen("tempo.txt","a+");
	if (f!=NULL&& f2!=NULL)
	{
        	while
        	(fscanf(f,"%s %s %s %s %s %s\n",MN1.jour,MN1.temps,MN1.date,MN1.entree,MN1.plat_principal,MN1.dessert)!=EOF)
		{
			if(strcmp(jour ,MN1.jour)==0 && strcmp(temps ,MN1.temps)==0)
			{
				fprintf(f2,"%s %s %s %s %s %s\n",MN.jour,MN.temps,MN.date,MN.entree,MN.plat_principal,MN.dessert);
			}
 			else 
			{
				fprintf(f2,"%s %s %s %s %s %s\n",MN1.jour,MN1.temps,MN1.date,MN1.entree,MN1.plat_principal,MN1.dessert);
			}
		}
        fclose(f);
        fclose(f2);
        remove("menu.txt");
        rename("tempo.txt","menu.txt");
    	}
}




//supprimer tr
void supprimer_menu(char*jour, char *temps)
{
FILE*f=NULL;
FILE*f1=NULL;
menu t ;
f=fopen("menu.txt","r");
f1=fopen("tempo.txt","w+");//mode lecture et ecriture 
while(fscanf(f,"%s %s %s %s %s %s\n",t.jour,t.temps,t.date,t.entree,t.plat_principal,t.dessert)!=EOF)
{
if(strcmp(jour,t.jour)!=0||strcmp(temps,t.temps)!=0)
fprintf(f1,"%s %s %s %s %s %s\n",t.jour,t.temps,t.date,t.entree,t.plat_principal,t.dessert);
}
fclose(f);
fclose(f1);
remove("menu.txt");
rename("tempo.txt","menu.txt");

}

//******************************************************************
//menu meilleur_menu(char* trouve_menu)
//{
    //menu t;
    //menu meilleur_menu;
    //dechet dech;
    //dechet mindech;
    //FILE*f=NULL;
    //f=fopen("dechet.txt","r");
    //if(f!=NULL)
    //{
        //fscanf(f,"%d %d %f",&mindech.jour,&mindech.temps,&mindech.poid);
        //while
        //(fscanf(f,"%d %d %f",&dech.jour,&dech.temps,&dech.poid)!=EOF)
        //{
            //if
            //(dech.poid<mindech.poid)
                //mindech=dech;
        //}
        //fclose(f);

    //}
//char mindech_jour[5];
//char mindech_temps[5];
//sprintf(mindech_jour,"%d",mindech.jour);
//sprintf(mindech_temps,"%d",mindech.temps);
    //FILE*f1=NULL;
    //f1=fopen("menu.txt","r");
    //if(f1!=NULL)
    //{
        //while
        //(fscanf(f1,"%s %s %s %s %s %s \n",t.jour,t.temps,t.date,t.entree,t.plat_principal,t.dessert)!=EOF)
        //{
            //if(strcpy(t.jour,mindech_jour)==0 && strcpy(t.temps,mindech_temps)==0)
            //{
		//meilleur_menu=t;
		//*trouve_menu=1;
	    //}
        //}
        //fclose(f1);
    //}
//return meilleur_menu;
//}

//menu meille
//{

     //menu mm ;
     //mm=menu meilleur_menu(char* trouve_menu);
     //char m[100];
     //for(i=1,i<=3;i++)
     //{ 
    //switch(i):
    //case 1:
   //strcpy(m,"petitdej");
    //break ;
    //case 2:
   //strcpy(m,"repas");
     //break ;
    //case 3:
   //strcpy(m,"diner");
     //break ;
      //}
//strcat(m,"de_jour");
//strcat(m,":");
//strcat(m,mm.jour);
//strcat(m,"/");
//strcat(m,mm.entree);
//strcat(m,"/");
//strcat(m,mm.plat_principale);
//strcat(m,"/");
//strcat(m,mm.dessert);
//return meille ;
//}

     













