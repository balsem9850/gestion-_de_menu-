#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"tree.h"
#include"CRUD.h"

GtkWidget *acceuilw;
GtkWidget *gestionw;
void
on_AcceuilGestionw_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
/////////////////////////////////////*preparation du treeView*/////////////////////////////////////////
GtkWidget *p;

acceuilw=lookup_widget(button,"acceuilw");
gestionw = create_gestionw ();
gtk_widget_show (gestionw);
p=lookup_widget(gestionw,"treeview2w");
Affichermenu(p,"menu.txt");
gtk_widget_hide (acceuilw);
}


void
on_Ajoutermenu_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
menu t;
GtkWidget *entrytempsw;
GtkWidget *entryIdw;

GtkWidget *entryDatew;
GtkWidget *entryentreew;
GtkWidget *labelIdw;
GtkWidget *labeltempsw;

GtkWidget *labelDatew;
GtkWidget *labelentreew;
GtkWidget *existew;
GtkWidget* successw;
GtkWidget *calw;
GtkWidget *entrymenu;
GtkWidget *labelmenu;
GtkWidget *labeldessert;
GtkWidget *entrydessert;
GtkWidget *input7,*input8,*input9;

char datejour[5],datemois[5],dateannee[5];
int b=1;

gtk_widget_hide (successw);

entryIdw=lookup_widget(gestionw,"entry5w");
entrytempsw=lookup_widget(gestionw,"combobox1w");
entrymenu=lookup_widget(gestionw,"entrymenu");
entrydessert=lookup_widget(gestionw,"entrydessert");

input7=lookup_widget(gestionw,"spinbuttonjour"); 
input8=lookup_widget(gestionw,"spinbuttonmois");
input9=lookup_widget(gestionw,"spinbuttonannee");

entryentreew=lookup_widget(gestionw,"entry3w");
labelIdw=lookup_widget(gestionw,"label13w");
labeltempsw=lookup_widget(gestionw,"label7w");
labelmenu=lookup_widget(gestionw,"labellabel");
labeldessert=lookup_widget(gestionw,"label68");
labelentreew=lookup_widget(gestionw,"label10w");
existew=lookup_widget(gestionw,"label34w");
successw=lookup_widget(gestionw,"label35w");

        strcpy(t.jour,gtk_entry_get_text(GTK_ENTRY(entryIdw)));
        strcpy(t.temps,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrytempsw)));
sprintf(datejour,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7)));
sprintf(datemois,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8)));
sprintf(dateannee,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9)));
strcpy(t.date,datejour);
strcat(t.date,"/");
strcat(t.date,datemois);
strcat(t.date,"/");
strcat(t.date,dateannee);
        strcpy(t.entree,gtk_entry_get_text(GTK_ENTRY(entryentreew)));
        strcpy(t.plat_principal,gtk_entry_get_text(GTK_ENTRY(entrymenu)));
	strcpy(t.dessert,gtk_entry_get_text(GTK_ENTRY(entrydessert)));
 


// controle saisie////
if(strcmp(t.jour,"")==0)
{
gtk_widget_show (labelIdw);
b=0;
}
else 
{
gtk_widget_hide(labelIdw);
}

if(strcmp(t.temps,"")==0)
{
gtk_widget_show (labeltempsw);
b=0;
}
else 
{
gtk_widget_hide(labeltempsw);
}


if(strcmp(t.entree,"")==0)
{
gtk_widget_show (labelentreew);
b=0;
}
else
{
gtk_widget_hide(labelentreew);
}

if(strcmp(t.plat_principal,"")==0){
		  gtk_widget_show (labelmenu);
b=0;
}
else 
{
gtk_widget_hide(labelmenu);
}
if(strcmp(t.dessert,"")==0)
{
gtk_widget_show (labeldessert);
b=0;
}
else 
{
gtk_widget_hide(labeldessert);
}
if(b==1)
{

        if(exist_menu(t.jour, t.temps)==1)
        {
	gtk_widget_hide (successw);
	gtk_widget_show (existew);
        }
	else
	{
	gtk_widget_hide (existew);
	ajouter_menu(t);
	gtk_widget_show (successw);
	////////mise a jour du treeView
	GtkWidget* p=lookup_widget(gestionw,"treeview2w");
	Affichermenu(p,"menu.txt");
	}
}

}

char jourm[20];
char tempsm[20];

void
on_Modifiermenu_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
     	GtkWidget *combobox3w;
     	combobox3w=lookup_widget(gestionw,"combobox3w");
       	menu t;
	char datejour[5]="",datemois[5]="",dateannee[5]="";
GtkWidget *input71,*input81,*input91;
input71=lookup_widget(gestionw,"spinbuttonjour1"); 
input81=lookup_widget(gestionw,"spinbuttonmois1");
input91=lookup_widget(gestionw,"spinbuttonannee1");
        strcpy(t.jour,gtk_label_get_text(GTK_LABEL(lookup_widget(gestionw,"label20w"))));
        strcpy(t.temps,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestionw,"combobox3w"))));
sprintf(datejour,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input71)));
sprintf(datemois,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input81)));
sprintf(dateannee,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input91)));
strcpy(t.date,datejour);
strcat(t.date,"/");
strcat(t.date,datemois);
strcat(t.date,"/");
strcat(t.date,dateannee);
        strcpy(t.entree,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionw,"entry8w"))));
	strcpy(t.plat_principal,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionw,"entryrec"))));
	strcpy(t.dessert,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionw,"entrydes"))));
	


        modifier_menu(jourm, tempsm, t);
////////mise ajour du tree view 
        //Affichermenu(lookup_widget(gestionw,"treeview1"),"menu.txt");
	gtk_widget_show(lookup_widget(gestionw,"label37w"));
        GtkWidget *p=lookup_widget(gestionw,"treeview2w");

        Affichermenu(p,"menu.txt");
}





void
on_cherchermenu_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *p1w;
GtkWidget *entryw;
GtkWidget *labelidw;
GtkWidget *nbResultatw;
GtkWidget *messagew;
char jour[30];
char chnb[30];
int b=0,nb; //b=0  entry  cherche vide

entryw=lookup_widget(gestionw,"entry10w");
labelidw=lookup_widget(gestionw,"label28w");
p1w=lookup_widget(gestionw,"treeview2w");
strcpy(jour,gtk_entry_get_text(GTK_ENTRY(entryw)));

if(strcmp(jour,"")==0){
  gtk_widget_show (labelidw);b=0;
}else{
b=1;
gtk_widget_hide (labelidw);}

if(b==0)
    {return;
    }
    else
    {

nb=Cherchermenu(p1w,"menu.txt",jour);
////// afficher le tempsbre de resultats obtenue par la recherche
 

sprintf(chnb,"%d",nb);       // //conversion int==> chaine car la fonction gtk_label_set_text naccepte que chaine
nbResultatw=lookup_widget(gestionw,"label27");
messagew=lookup_widget(gestionw,"label26w");
gtk_label_set_text(GTK_LABEL(nbResultatw),chnb);

gtk_widget_show (nbResultatw);
gtk_widget_show (messagew);

}
}


void
on_GestionAcceuilw_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (acceuilw);
gtk_widget_destroy (gestionw);

}




void
on_bmodifier_clickedw                   (GtkButton       *button,
                                        gpointer         user_data)
{
        gchar *jour;
        gchar *temps;
        gchar *date;
        gchar *entree;
	gchar *plat_principal;
	gchar *dessert;
	char datejour[5],datemois[5],dateannee[5];
	GtkWidget *p;
	p=lookup_widget(gestionw,"treeview2w");	
        GtkTreeModel *model;
        GtkTreeIter iter;
	GtkTreeSelection *selection1;
	selection1=gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
GtkWidget* msgId=lookup_widget(gestionw,"label20w");
GtkWidget *input71,*input81,*input91;
input71=lookup_widget(gestionw,"spinbuttonjour1"); 
input81=lookup_widget(gestionw,"spinbuttonmois1");
input91=lookup_widget(gestionw,"spinbuttonannee1");



     	GtkWidget *combobox3w;
     	combobox3w=lookup_widget(gestionw,"combobox3w");

        if (gtk_tree_selection_get_selected(selection1, &model, &iter))
        {
////cacher label modifier avec succees
        gtk_widget_hide(lookup_widget(gestionw,"label37w"));
////////recuperer les information de la ligne selectionneé
        gtk_tree_model_get (model,&iter,0,&jour,1,&temps,2,&date,3,&entree,4,&plat_principal,5,&dessert,-1);
//// //remplir les champs de entry

                
                gtk_label_set_text(GTK_LABEL(msgId),jour);
                gtk_widget_show(msgId);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entry8w")),entree);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entryrec")),plat_principal);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entrydes")),dessert);
		strcpy(tempsm,temps);
		strcpy(jourm,jour);
char slash[1]="/";
int i,j,k;
/*for(i=0,j=0;date[i]!=slash[0];i++,j++) {datejour[j]=date[i];k=i+1;}
for(i=k,j=0;date[i]!=slash[0];i++,j++) {datemois[j]=date[i];k=i+1;}
for(i=k,j=0;i<strlen(date);i++,j++) dateannee[j]=date[i];
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(input71),atoi(datejour));
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(input81),atoi(datemois));
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(input91),atoi(dateannee));*/
char tempsr[3][15]={"petit_dejeuner","repas_midi","diner"};

i=0;
while(i<3 && (strcmp(temps,tempsr[i])!=0)) {i++;}
gtk_combo_box_set_active(GTK_COMBO_BOX(combobox3w),i);
                GtkWidget* msg1=lookup_widget(gestionw,"label36w");
                gtk_widget_show(msg1);
                gtk_widget_show(lookup_widget(gestionw,"button4w"));//afficher le bouton modifier
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(gestionw,"notebook1w")));//redirection vers la page precedente
                
             
        }

}


void
on_bsupprimer_clickedw                  (GtkButton       *button,
                                        gpointer         user_data)
{
    gchar *jour;
    gchar *temps;
    gchar *date;
    gchar *entree;
    gchar *plat_principal;
    gchar *dessert;
    GtkTreeModel *model;
    GtkTreeIter iter;
    GtkTreeSelection *selection1;
    GtkWidget *p;
    p=lookup_widget(gestionw,"treeview2w");	
    selection1=gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
       if (gtk_tree_selection_get_selected(selection1, &model, &iter))
        {
        gtk_tree_model_get (model,&iter,0,&jour,1,&temps,-1);//recuperer les information de la ligne selectionneé
        //gtk_list_store_remove(GTK_LIST_STORE(model),&iter);
	supprimer_menu(jour, temps);      
        Affichermenu(lookup_widget(gestionw,"treeview2w"),"menu.txt");  
        }
}


void
on_bafficher12w_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *p=lookup_widget(button,"treeview2w");
        Affichermenu(p,"menu.txt");
}
