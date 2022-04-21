#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>

GtkWidget* window1;
GtkWidget* window2;
GtkWidget* fixed1;
GtkWidget* fixed2;
GtkWidget* button1;
GtkWidget* check1;
GtkWidget* spin1;
GtkWidget* spin2;
GtkBuilder* builder;


// VARIABLES FOR ALGORITHMS

int nbOfHumans = 5;
int nbOfAttractions = 2;
int isRaining = 0; // 1 -> False    0 -> True

int main(int agrc, char* argv[])
{
    gtk_init(&agrc, &argv);

    builder = gtk_builder_new_from_file("resources/gui_main.glade");
    
    window1 = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
    window2 = GTK_WIDGET(gtk_builder_get_object(builder, "window2"));

    g_signal_connect(window1, "destroy", G_CALLBACK(gtk_main_quit), NULL);      //
    g_signal_connect(window2, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_builder_connect_signals(builder, NULL);

    fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
    fixed2 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
    button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
    check1 = GTK_WIDGET(gtk_builder_get_object(builder, "check1"));
    spin1 = GTK_WIDGET(gtk_builder_get_object(builder, "spin1"));
    spin2 = GTK_WIDGET(gtk_builder_get_object(builder, "spin2"));

    gtk_widget_show(window1);

    gtk_main();

    return 0;
}

void on_button1_clicked(__attribute__((unused)) GtkButton *button)
{
    // Start the simulation

    gtk_widget_hide(window1);
    gtk_widget_show(window2);

    // TEST :
    //printf("%i\n", nbOfAttractions);
    //printf("%i\n", nbOfHumans);
    //printf("%i\n", isRaining);
}

void on_spin1_value_changed(GtkSpinButton* spin)
{
    // Goes here if + or - has been clicked

    nbOfAttractions = gtk_spin_button_get_value_as_int(spin);
}

void on_spin2_value_changed(GtkSpinButton* spin)
{
    // Goes here if + or - has been clicked

    nbOfHumans = gtk_spin_button_get_value_as_int(spin);
}

void on_check1_toggled(GtkCheckButton * check)
{
    // Goes here if weather is changed

    gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(check));
    if (T)
        isRaining = 1;
    else
        isRaining = 0;
}