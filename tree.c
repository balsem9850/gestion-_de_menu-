#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include <gtk/gtk.h>
#include "interface.h"
#include "callbacks.h"
#include "tree.h"
#include "CRUD.h"


GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;

void Affichermenu(GtkWidget* treeview1,char*l)
{

menu t;


        /////////////////////////////////* Creation du modele *///////////////////////////////////////////
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING);
                                     
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %s\n",t.jour,t.temps,t.date,t.entree,t.plat_principal,t.dessert)!=EOF)
        {GtkTreeIter pIter;

   //////////////////////     /* Creation de la nouvelle ligne *///////////////////////////////////////////////
         gtk_list_store_append(adstore, &pIter);
       ////////////////////////  /* Mise a jour des donnees */////////////////////////////////////////////////
         gtk_list_store_set(adstore, &pIter,
                            0,t.jour,
                            1,t.temps,
                            2,t.date,
                            3,t.entree,
			    4,t.plat_principal,
                            5,t.dessert,
                            -1);}
        fclose(f);
if(i==0)
	/////////////////////////////////////////* Creation de la 1ere colonne *//////////////////////////////////

	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("JOUR",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


      /////////////////////////////////////  /* Ajouter la 1er colonne à la vue *//////////////////////////////
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	//////////////////////////////////////////* Creation de la 2eme colonne *////////////////////////////////
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("TEMPS",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	//////////////////////////////////////////// Ajouter la 2emme colonne à la vue /////////////////////
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	

	//////////////////////////////////////////// Creation de la 4eme colonne ///////////////////////////
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	////////////////////////////////// Ajouter la 4emme colonne à la vue //////////////////////////////
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	////////////////////////////////// Creation de la 5eme colonne ///////////////////////////////////
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ENTREE ",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	////////////////////////////////////// Ajouter la 5emme colonne à la vue //////////////////////////
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

////////////////////////////////////////////// Creation de la 5eme colonne ////////////////////////////////////////////
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("PLAT_PRINCIPALE ",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	////////////////////////////////// Ajouter la 5emme colonne à la vue /////////////////////////////////////////
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


///////////////////////////////////////////////// Creation de la 6eme colonne ////////////////////////////////
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DESSERT",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	///////////////////////////////////////// Ajouter la 6emme colonne à la vue /////////////////////////////
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);





i++ ;
}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );


}





int Cherchermenu(GtkWidget* treeview1,char*l,char*jour)
{

menu t ;
int nb=0;

        //////////////////////////////////////////////// Creation du modele ///////////////////////////////////////
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING);
                                     
        ///////////////////////////////////////////// Insertion des elements /////////////////////////////
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %s \n",t.jour,t.temps,t.date,t.entree,t.plat_principal,t.dessert)!=EOF)
        {
	if( strcmp(jour,t.jour)==0){ nb++;
	GtkTreeIter pIter;
         /////////////////////////////////////////// Creation de la nouvelle ligne ///////////////////////
         gtk_list_store_append(adstore, &pIter);
         ///////////////////////////////////////////////// Mise a jour des donnees /////////////////////////////////
         gtk_list_store_set(adstore, &pIter,
                            0,t.jour,
                            1,t.temps,
                            2,t.date,
                            3,t.entree,
			    4,t.plat_principal,
                            5,t.dessert,
                            -1);}
}
        fclose(f);

	//////////////////////////////////////// Creation de la 1ere colonne ////////////////////////////////////////////
if(j==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("JOUR",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        ////////////////////////////////////// Ajouter la 1er colonne à la vue /////////////////////////////////
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/////////////////////////////////////////// Creation de la 2eme colonne //////////////////////////////////////////////////
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("TEMPS",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	///////////////////////////////////// Ajouter la 2emme colonne à la vue /////////////////////////////////////////////////
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	

	/////////////////////////////////////// Creation de la 3eme colonne ///////////////////////////////////////////////////
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	///////////////////////////////////// Ajouter la 3emme colonne à la vue //////////////////////////////////////
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	//////////////////////////////////////// Creation de la 4eme colonne ///////////////////////////////////////////////////
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ENTREE",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	///////////////////////////////////////// Ajouter la 4emme colonne à la vue ////////////////////////////////////////////
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


////////////////////////////////////////////// Creation de la 5eme colonne ///////////////////////////////////////////////////////////
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("plat_PRINCIPALE",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	//////////////////////////////////// Ajouter la 5emme colonne à la vue //////////////////////////////////////////
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);



////////////////////////////////////////////////// Creation de la 6eme colonne /////////////////////////////////////////
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DESSERT",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	////////////////////////////////// Ajouter la 6emme colonne à la vue /////////////////////////////////////////////////////////
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);




j++; }




 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );
return nb;
}


