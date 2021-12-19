#include <gtk/gtk.h>
typedef struct
{
char jour[30];
char temps[30];
char date[30];
char entree[30];
char plat_principal[50];
char dessert[50];
}menu;

void ajouter_menu(menu t );
void modifier_menu(char *jour, char *temps, menu MN);
int exist_menu(char*jour, char *temps);
void supprimer_menu(char*jour, char *temps);
