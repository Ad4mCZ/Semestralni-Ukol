#include <stdbool.h>
GtkWidget *Login_box;
GtkComboBox *Test_select;
GtkEntry *Family_name;
GtkEntry *Given_name;
GtkEntry *age;
GtkComboBox *Gender_select;
GtkWidget *Confirm_button;

const gchar *selected_test;
const gchar *selected_gender;
const gchar *name;
const gchar *family_name;
const gchar *age_entry;

gboolean Check()
{

  selected_test = gtk_combo_box_get_active_id(Test_select);
  name = gtk_entry_get_text(Given_name);
  family_name = gtk_entry_get_text(Family_name);
  age_entry = gtk_entry_get_text(age);
  selected_gender = gtk_combo_box_get_active_id(Gender_select);

  // if (name[0] != '\0')
  // {
  //   g_print("pizduch");
  // }
  // if (family_name[0] != '\0')
  // {
  //   g_print("debil");
  // }
  // if (age_entry[0] != '\0')
  // {
  //   g_print("kokot");
  // }
  // if (selected_test != NULL)
  // {
  //   g_print("prdel");
  // }
  // if (selected_gender != NULL)
  // {
  //   g_print("kunda");
  // }

  if (name[0] != '\0' && family_name[0] != '\0' && age_entry[0] != '\0' && selected_test != NULL && selected_gender != NULL)
  {
    // g_print("kreten");
    gtk_widget_set_sensitive(GTK_WIDGET(Confirm_button), TRUE);
    return FALSE;
  }

  return TRUE;
}
