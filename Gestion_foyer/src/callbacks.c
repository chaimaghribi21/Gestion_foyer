#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctions.h"


int paiement1;
int paiement2;
char conf[]="non confirmer";

//menu
void
on_CG_buttonInsc_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *windowInsc;
GtkWidget *windowMenu;
windowInsc=create_CG_Insc();
windowMenu=lookup_widget(button,"CG_menu");
gtk_widget_show (windowInsc);
gtk_widget_destroy(windowMenu);


}


void
on_CG_buttonModif_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *windowMenu;
GtkWidget *windowModif;
windowModif=create_CG_Modif();
windowMenu=lookup_widget(button,"CG_menu");
gtk_widget_show (windowModif);
gtk_widget_destroy(windowMenu);
}


void
on_CG_buttonSupp_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *windowMenu;
GtkWidget *windowSupp;
windowSupp=create_CG_supp();
windowMenu=lookup_widget(button,"CG_menu");
gtk_widget_show (windowSupp);
gtk_widget_destroy(windowMenu);
}


void
on_CG_buttonAff_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *windowMenu;
GtkWidget *windowAff;
GtkWidget *p;
windowAff=create_CG_Aff();
windowMenu=lookup_widget(button,"CG_menu");
gtk_widget_show (windowAff);
gtk_widget_destroy(windowMenu);

p=lookup_widget(windowAff,"CG_treeview1Affich");
        afficher(p);
//CG_treeview1Affich
}


void
on_CG_radiobutton1paye_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
paiement1=1;
}


void
on_CG_button1Aff_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowAff1;
windowAff1=create_CG_Aff();
gtk_widget_show (windowAff1);
}

//bouton retour
void
on_CG_button1R1_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *windowmenu1;
	GtkWidget *window1;
	windowmenu1=create_CG_menu();
	window1=lookup_widget(button,"CG_Insc");
	gtk_widget_show (windowmenu1);
	gtk_widget_destroy(window1);
}


void
on_CG_button1Insc_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *nom,*prenom,*id,*num_chambre,*etage,*paiement;

nom = lookup_widget(button,"CG_entry1N");
prenom = lookup_widget(button,"CG_entry1P");
id = lookup_widget(button,"CG_entry1Id");
etage = lookup_widget(button,"CG_combobox1");
num_chambre = lookup_widget(button,"CG_spinbutton1");


foyer F;


strcpy(F.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(F.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(F.id,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(F.etage,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etage)));
F.num_chambre = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(num_chambre));
printf("la valeur est%d",paiement1);
if (paiement1==1) strcpy(F.paiement,"paye");
	else if(paiement1==2) strcpy(F.paiement,"non_paye");
if (strcmp(conf,"confirmer"))
       {ajouter(F);}
}


void
on_CG_radiobutton2paye_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
paiement2=1;
}


void
on_CG_radiobutton2Npaye_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
paiement2=2;
}


void
on_CG_button2Modif_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *nom,*prenom,*id,*num_chambre,*etage,*paiement;

nom = lookup_widget(button,"CG_entry2N");
prenom = lookup_widget(button,"CG_entry2P");
id = lookup_widget(button,"CG_entry2Id");
etage = lookup_widget(button,"CG_combobox2");
num_chambre = lookup_widget(button,"CG_spinbutton2");


foyer F;


strcpy(F.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(F.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(F.id,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(F.etage,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etage)));
F.num_chambre = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(num_chambre));
if (paiement2==1) strcpy(F.paiement,"paye");
	else if(paiement2==2) strcpy(F.paiement,"non_paye");
modifier(F);
}

//retour
void
on_CG_button2R2_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *windowmenu2  ;
	GtkWidget *window1;
	windowmenu2=create_CG_menu();
	window1=lookup_widget(objet_graphique,"CG_Modif");
	gtk_widget_show (windowmenu2);
	gtk_widget_destroy(window1);
}

//retour
void
on_CG_button3R3_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *windowmenu3;
	GtkWidget *window1;
	windowmenu3=create_CG_menu();
	window1=lookup_widget(button,"CG_supp");
	gtk_widget_show (windowmenu3);
	gtk_widget_destroy(window1);

}


void
on_CG_button3Supp_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
char id[20];
GtkWidget *id1;
id1= lookup_widget(button,"CG_entry3Supp");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(id1)));
supprimer(id);
}


void
on_CG_treeview1Affich_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_CG_button4R4_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmenu4;
GtkWidget *window1;
windowmenu4=create_CG_menu();
window1=lookup_widget(button,"CG_Aff");
gtk_widget_show (windowmenu4);
gtk_widget_destroy(window1);
}


void
on_CG_radiobutton1Npaye_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
paiement1=2;
}

//consulter
void
on_button_cons_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *output;
	GtkWidget *nom,*prenom,*id,*num_chambre,*etage,*paiement;
	GtkWidget *paye, *nonpaye;
	char idt[20], message[200];
	foyer a;


	id = lookup_widget(button,"CG_entry2Id");

	output=lookup_widget(button,"CG_label_cons");
	strcpy(idt,gtk_entry_get_text(GTK_ENTRY(id)));
	
	if (verif_id(idt)==0){
		sprintf(message,"ID n'existe pas");
		gtk_label_set_text(GTK_LABEL(output),message);
	}else{

		//foyer a;
		strcpy(a.id,idt);
		strcpy(a.nom,recherche(idt).nom);
		strcpy(a.prenom,recherche(idt).prenom);
		strcpy(a.etage,recherche(idt).etage);
		strcpy(a.paiement,recherche(idt).paiement);
		a.num_chambre = recherche(idt).num_chambre;

		sprintf(message,"Veuillez saisir vos modifications\n");
		gtk_label_set_text(GTK_LABEL(output),message);

		nom = lookup_widget(button,"CG_entry2N");
		prenom = lookup_widget(button,"CG_entry2P");
		etage = lookup_widget(button,"CG_combobox2");
		num_chambre = lookup_widget(button,"CG_spinbutton2");
		
		paye=lookup_widget(button,"CG_radiobutton2paye");
		nonpaye=lookup_widget(button,"CG_radiobutton2Npaye");

		//remplissage 
		//combo_box_etage
		if(strcmp(a.etage,"A")==0){
			gtk_combo_box_set_active(etage,0);
		}else if(strcmp(a.etage,"B")==0){
			gtk_combo_box_set_active(etage,1);
		}else if(strcmp(a.etage,"C")==0){
			gtk_combo_box_set_active(etage,2);
		}else if(strcmp(a.etage,"D")==0){
			gtk_combo_box_set_active(etage,3);
		}
		
		//Radio_butt_paiement
		else if(strcmp(a.paiement,"paye")==0){
			gtk_toggle_button_set_active(paye,"TRUE");
		}else if(strcmp(a.paiement,"non_paye")==0){
			gtk_toggle_button_set_active(nonpaye,"TRUE");
		}

		//remplissage valeurs 
		char prenoma[20],noma[20];
		
		sprintf(prenoma,"%s",a.prenom);
		gtk_entry_set_text(GTK_ENTRY(prenom),prenoma);

		sprintf(noma,"%s",a.nom);
		gtk_entry_set_text(GTK_ENTRY(nom),noma);

		//spinbutton
		gtk_spin_button_set_value(num_chambre,a.num_chambre);

	}

}


void
on_CG_checkbutton1_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{    if( gtk_toggle_button_get_active(togglebutton))
	strcpy(conf,"confirmer");
}

