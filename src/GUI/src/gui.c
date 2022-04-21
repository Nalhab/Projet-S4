#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>

GtkWidget* window;
GtkWidget* fixed1;
GtkWidget* button1;
GtkWidget* label1;
GtkWidget* spin1;
GtkWidget* spin2;
GtkBuilder* builder;

int main(int agrc, char* argv[])
{
    gtk_init(&agrc, &argv);

    builder = gtk_builder_new_from_file("resources/gui_main.glade");
    
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_builder_connect_signals(builder, NULL);

    fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
    button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
    label1 = GTK_WIDGET(gtk_builder_get_object(builder, "label1"));
    spin1 = GTK_WIDGET(gtk_builder_get_object(builder, "spin1"));
    spin1 = GTK_WIDGET(gtk_builder_get_object(builder, "spin2"));

    gtk_widget_show(window);

    gtk_main();

    return 0;
}

void on_button1_clicked(__attribute__((unused)) GtkButton *b)
{
    // Start the simulation
}

void on_spin1_value_changed()
{
    // Goes here if + or - has been clicked
}

void on_spin2_value_changed()
{
    // Goes here if + or - has been clicked
}