#include "fonctions.h"
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

enum
{
	ENOM,
	EPRENOM,
	EIDENTIFIANT,
	EPAIEMENT,
	ENUMCHAMBRE,
	EETAGE,
	COLUMNS,
};
void ajouter(foyer f)
{
FILE *fo;

fo=fopen("hebergement.txt","a+");
fprintf(fo,"%s %s %s %s %d %s\n", f.nom,f.prenom,f.id,f.paiement, f.num_chambre,f.etage);
fclose(fo);
}
void supprimer(char idt[20])
{
  FILE* fo;
    FILE* f_tmp;
   foyer f;

    fo=fopen("hebergement.txt","r");
    f_tmp=fopen("hebergement.tmp","a+");
    if (fo!=NULL)
    {
      while(fscanf(fo,"%s %s %s %s %d %s\n", f.nom,f.prenom,f.id,f.paiement, &f.num_chambre,f.etage)!=EOF)
            {
                  if (strcmp(idt,f.id)!=0)
                    {
                        fprintf(f_tmp,"%s %s %s %s %d %s\n", f.nom,f.prenom,f.id,f.paiement, f.num_chambre,f.etage);
                    }

            }
            fclose(fo);
            fclose(f_tmp);

            remove("hebergement.txt");
            rename("hebergement.tmp","hebergement.txt");
    }

}
void afficher(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char nom[20];
	char prenom[20];
	char paiement[10];
	int num_chambre;
	char etage[20];
	char id[20];

	store=NULL;

	FILE *f;
	store = gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("nom",renderer, "text",ENOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("prenom",renderer, "text",EPRENOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("identifiant",renderer, "text",EIDENTIFIANT, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("num_chambre",renderer, "text",ENUMCHAMBRE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


 		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("paiement",renderer, "text",EPAIEMENT, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


 		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("etage",renderer, "text",EETAGE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		



		

		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING);

		f = fopen("hebergement.txt","r");

		if(f==NULL)
		{
			return;
		}
		else
		{
			f = fopen("hebergement.txt","a+");
			while(fscanf(f,"%s %s %s %s %d %s\n",nom,prenom,id,etage,&num_chambre,paiement)!=EOF)
			{
		gtk_list_store_append(store,&iter);
		gtk_list_store_set (store, &iter, ENOM, nom, EPRENOM, prenom, EIDENTIFIANT, id, ENUMCHAMBRE, num_chambre,EETAGE,etage, EPAIEMENT, paiement, -1 );
			}
			fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
 		g_object_unref(store);
}
}
}


void modifier(foyer g)
{
  FILE* fo;
    FILE* f_tmp;
    foyer f;

    fo=fopen("hebergement.txt","r");
    f_tmp=fopen("hebergement.tmp","a+");
    if (fo!=NULL)
    {
      while(fscanf(fo,"%s %s %s %s %d %s\n", f.nom,f.prenom,f.id,f.paiement, &f.num_chambre,f.etage)!=EOF)
            {
                  if (strcmp(g.id,f.id)!=0)
                    {
                        fprintf(f_tmp,"%s %s %s %s %d %s\n", f.nom,f.prenom,f.id,f.paiement, f.num_chambre,f.etage);
                    }
                  else
                    {
                        fprintf(f_tmp,"%s %s %s %s %d %s\n", g.nom,g.prenom,g.id,g.paiement, g.num_chambre,g.etage);
                    }

            }
            fclose(fo);
            fclose(f_tmp);

            remove("hebergement.txt");
            rename("hebergement.tmp","hebergement.txt");
    }

}



//consulter
int verif_id(char id[])
{
	foyer a;
	FILE *f;
	f=fopen("hebergement.txt","r");
	if (f!=NULL)
	{
		while (fscanf(f,"%s %s %s %s %d %s\n",a.nom,a.prenom,a.id,a.paiement, &a.num_chambre,a.etage)!=EOF)
		{ 
			if(strcmp(a.id,id)==0){
				return 1;
			}

		}

	}
	fclose(f);
	return 0;

}


foyer recherche( char id[])
{
foyer a;
FILE *f;
f=fopen("hebergement.txt","r");
if ( f!=NULL)
{
 	while (fscanf(f,"%s %s %s %s %d %s\n",a.nom,a.prenom,a.id,a.paiement, &a.num_chambre,a.etage)!=EOF)
	{ 
	if(strcmp(a.id,id)==0)
           { return a;         
	   }
	}

}
fclose(f);
return;
}

