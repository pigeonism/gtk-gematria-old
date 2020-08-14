#include <gtk/gtk.h>
#include <iostream>
#include "gematria.h"
// project properties, build targets, changed build type to window app
using namespace std;

string message;
string resultText;

static void buttonFunction (GtkWidget *widget, gpointer data){
    //cout << "testing..." << endl;
    //g_print("testing\n");

    // numerate(msgt);
    // gematria class
    gematria gem;
    gem.setMethod("english"); // or english or-ordinal
    gem.numerate(message);

    // for label
    resultText = gem.getResult();

}

//           changed from GtkWidget to GtkEntry for the get text function
static void textEntered (GtkEntry *widget, gpointer data) {

    //g_print("hi\n");
    //cout << gtk_entry_get_text (widget) << endl;

    // instead of entry from console, store updated txt to str for gematria class
    // use message in button callback
    message = gtk_entry_get_text (widget);

}
static void changeLabel (GtkLabel *widget, gpointer data){
    string msg = "Numerical value for: " + message + "\n" + resultText;
    // c_str() to convert str to const char*
    gtk_label_set_text(widget, msg.c_str());
}

static void activate (GtkApplication* app, gpointer user_data)
{
    //gtk
    GtkWidget *window;
    GtkWidget *entry;
    GtkWidget *button;
    GtkWidget *box;
    GtkWidget *label;
    GtkWidget *button_clear;

    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Gematria");
    gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

    // CONTAINER
    box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 7);
    gtk_container_add (GTK_CONTAINER (window), box);

    // BUTTON
    button = gtk_button_new_with_label (" Get Number ");
    g_signal_connect (button, "clicked", G_CALLBACK (buttonFunction), NULL);
    //g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);


    // ENTRY
    //entry = gtk_search_entry_new ();
    entry = gtk_entry_new();
    gtk_widget_set_hexpand (entry, TRUE);
    g_signal_connect(entry, "changed", G_CALLBACK(textEntered), NULL);

    // LABEL
    label = gtk_label_new("result:");
    // instead of connecting label, use secondary callback of button with label now defined to chng txt
    g_signal_connect_swapped (button, "clicked", G_CALLBACK (changeLabel), label);

    // CLEAR Button
    //button_clear = gtk_button_new_with_label (" Clear ");


    // PACK WIDGETS
    gtk_container_add (GTK_CONTAINER (box), entry);
    gtk_container_add (GTK_CONTAINER (box), button);
    gtk_container_add (GTK_CONTAINER (box), label);
    //gtk_container_add (GTK_CONTAINER (box), button_clear);

    gtk_widget_show_all (window);
}

int main (int argc, char **argv)
{
    // gtk
    GtkApplication *app;
    int status;

    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}
