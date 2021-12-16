/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *CG_menu;
  GtkWidget *CG_Insc;
  GtkWidget *CG_Modif;
  GtkWidget *CG_supp;
  GtkWidget *CG_Aff;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  CG_menu = create_CG_menu ();
  gtk_widget_show (CG_menu);
  /*CG_Insc = create_CG_Insc ();
  gtk_widget_show (CG_Insc);
  CG_Modif = create_CG_Modif ();
  gtk_widget_show (CG_Modif);
  CG_supp = create_CG_supp ();
  gtk_widget_show (CG_supp);
  CG_Aff = create_CG_Aff ();
  gtk_widget_show (CG_Aff);
*/
  gtk_main ();
  return 0;
}

