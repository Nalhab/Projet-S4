#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include <unistd.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <gdk/gdkscreen.h>
#include <cairo.h>
#include "move.h"
#include "../../IA/src/population.h"

GtkWidget* window1;
GtkWidget* fixed1;

GtkWidget* button1;
GtkWidget* check1;
GtkWidget* spin1;
GtkWidget* spin2;
GtkBuilder* builder;

GtkWidget* window2;
GtkWidget* fixed2;
GtkWidget* button1bis;
GtkDrawingArea* GDA;

GtkWidget* icon1;
GtkWidget* icon2;
GtkWidget* icon3;
GtkWidget* icon4;
GtkWidget* icon5;
GtkWidget* icon6;
GtkWidget* icon7;
GtkWidget* icon8;
GtkWidget* icon9;
GtkWidget* icon10;
GtkWidget* icon11;
//GtkWidget* icon12;

GtkWidget* label1bis;
GtkWidget* label2bis;
GtkWidget* label3bis;
GtkWidget* label4bis;
GtkWidget* label5bis;
GtkWidget* label6bis;
GtkWidget* label7bis;
GtkWidget* label8bis;
GtkWidget* label9bis;
GtkWidget* label10bis;
GtkWidget* label11bis;
//GtkWidget* label12bis;
GtkWidget* labelTimer;
GtkWidget* labelHumans;

GtkWidget* road1;
GtkWidget* road2;
GtkWidget* road3;
GtkWidget* road4;
GtkWidget* road5;
GtkWidget* road6;
GtkWidget* road7;
GtkWidget* road8;
GtkWidget* road9;
GtkWidget* road10;
GtkWidget* road11;
GtkWidget* road12;

GtkWidget* buttonIcon1;
GtkWidget* buttonIcon2;
GtkWidget* buttonIcon3;
GtkWidget* buttonIcon4;
GtkWidget* buttonIcon5;
GtkWidget* buttonIcon6;
GtkWidget* buttonIcon7;
GtkWidget* buttonIcon8;
GtkWidget* buttonIcon9;
GtkWidget* buttonIcon10;
GtkWidget* buttonIcon11;
GtkWidget* buttonIcon12;

GtkWidget* buttonPath;

GtkWidget* checkIcon1;
GtkWidget* checkIcon2;
GtkWidget* checkIcon3;
GtkWidget* checkIcon4;
GtkWidget* checkIcon5;
GtkWidget* checkIcon6;
GtkWidget* checkIcon7;
GtkWidget* checkIcon8;
GtkWidget* checkIcon9;
GtkWidget* checkIcon10;
GtkWidget* checkIcon11;

GtkWidget* iconSmall1;
GtkWidget* iconSmall2;
GtkWidget* iconSmall3;
GtkWidget* iconSmall4;
GtkWidget* iconSmall5;
GtkWidget* iconSmall6;
GtkWidget* iconSmall7;
GtkWidget* iconSmall8;
GtkWidget* iconSmall9;
GtkWidget* iconSmall10;
GtkWidget* iconSmall11;

// VARIABLES FOR ALGORITHMS -----------------

int nbOfHumans = 5;
int nbOfAttractions = 2;
int isRaining = 0; // 1 -> False    0 -> True

parc* parcGUI;

GtkWidget* icon[12];
GtkWidget* label[11];
GtkWidget* road[12];
GtkWidget* buttonIcon[12];
GtkWidget* checkIcon[11];
GtkWidget* iconSmall[11];

typedef struct
{
    int number;
    int posX;
    int posY;
}Attraction;

Attraction attractions[12] = {{0, 310, 110},
                              {1, 469, 110},
                              {2, 536, 161},
                              {3, 580, 205},
                              {4, 580, 295},
                              {5, 537, 338},
                              {6, 470, 390},
                              {7, 310, 390},
                              {8, 240, 339},
                              {9, 196, 295},
                              {10, 197, 204},
                              {11, 238, 163}};

int attractionToggled[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int step[12] = { 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1 };

int nbSeconds = 0;
guint threadID = 0;
guint humanID = 0;
guint iaID = 0;

// ------------------------------------------

// + or - nb of people in the attraction
void updateLabel(GtkLabel *sum, int num)
{
    gchar *display;
    display = g_strdup_printf("%d", num);         //convert num to str
    gtk_label_set_text (GTK_LABEL(sum), display); //set label to "display"
    g_free(display);                              //free display
}

//convert label text to an int
int get_int_from_label(GtkWidget* lb)
{
    int num = atoi(gtk_label_get_text(GTK_LABEL(lb)));

    return num;
}

//create array of the icons
void create_icon_array(GtkWidget* icon[12])
{
    icon[0] = icon1;
    icon[1] = icon2;
    icon[2] = icon3;
    icon[3] = icon4;
    icon[4] = icon5;
    icon[5] = icon6;
    icon[6] = icon7;
    icon[7] = icon8;
    icon[8] = icon9;
    icon[9] = icon10;
    icon[10] = icon11;
    //icon[11] = icon12;
}

//create array of the buttons of icons
void create_buttonIcon_array(GtkWidget* buttonIcon[12])
{
    buttonIcon[0] = buttonIcon1;
    buttonIcon[1] = buttonIcon2;
    buttonIcon[2] = buttonIcon3;
    buttonIcon[3] = buttonIcon4;
    buttonIcon[4] = buttonIcon5;
    buttonIcon[5] = buttonIcon6;
    buttonIcon[6] = buttonIcon7;
    buttonIcon[7] = buttonIcon8;
    buttonIcon[8] = buttonIcon9;
    buttonIcon[9] = buttonIcon10;
    buttonIcon[10] = buttonIcon11;
    buttonIcon[11] = buttonIcon12;
}

//create array of the labels
void create_label_array(GtkWidget* label[12])
{
    label[0] = label1bis;
    label[1] = label2bis;
    label[2] = label3bis;
    label[3] = label4bis;
    label[4] = label5bis;
    label[5] = label6bis;
    label[6] = label7bis;
    label[7] = label8bis;
    label[8] = label9bis;
    label[9] = label10bis;
    label[10] = label11bis;
    //label[11] = label12bis;
}

void create_road_array(GtkWidget* road[12])
{
    road[0] = road1;
    road[1] = road2;
    road[2] = road3;
    road[3] = road4;
    road[4] = road5;
    road[5] = road6;
    road[6] = road7;
    road[7] = road8;
    road[8] = road9;
    road[9] = road10;
    road[10] = road11;
    road[11] = road12;
}

void create_iconSmall_array(GtkWidget* iconSmall[11])
{
    iconSmall[0] = iconSmall1;
    iconSmall[1] = iconSmall2;
    iconSmall[2] = iconSmall3;
    iconSmall[3] = iconSmall4;
    iconSmall[4] = iconSmall5;
    iconSmall[5] = iconSmall6;
    iconSmall[6] = iconSmall7;
    iconSmall[7] = iconSmall8;
    iconSmall[8] = iconSmall9;
    iconSmall[9] = iconSmall10;
    iconSmall[10] = iconSmall11;
}

void create_check_array(GtkWidget* checkIcon[11])
{
    checkIcon[0] = checkIcon1;
    checkIcon[1] = checkIcon2;
    checkIcon[2] = checkIcon3;
    checkIcon[3] = checkIcon4;
    checkIcon[4] = checkIcon5;
    checkIcon[5] = checkIcon6;
    checkIcon[6] = checkIcon7;
    checkIcon[7] = checkIcon8;
    checkIcon[8] = checkIcon9;
    checkIcon[9] = checkIcon10;
    checkIcon[10] = checkIcon11;
}

Game game =
    {
        .disc =
            {
                .rect = { 310, 110, 9, 9 }, //310 110
                .step = { 1, -1 },
                .event = 0,
                .period = DISC_PERIOD,
                .attractionIn = 0,
                .attractionGo = 1,
                .posX = 469,
                .posY = 110,
                .posOrNeg = FALSE,
            },
    };

int main(int agrc, char* argv[])
{
    gtk_init(&agrc, &argv);

    builder = gtk_builder_new_from_file("resources/gui_main.glade");

    window1 = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
    window2 = GTK_WIDGET(gtk_builder_get_object(builder, "window2"));

    g_signal_connect(window1, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(window2, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_builder_connect_signals(builder, NULL);

    GDA = GTK_DRAWING_AREA(gtk_builder_get_object(builder, "GDA"));

    game.ui.area = GDA;
    game.ui.window = GTK_WINDOW(window2);

    g_signal_connect(GDA, "draw", G_CALLBACK(on_draw), &game);

    fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
    fixed2 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
    button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
    check1 = GTK_WIDGET(gtk_builder_get_object(builder, "check1"));
    spin1 = GTK_WIDGET(gtk_builder_get_object(builder, "spin1"));
    spin2 = GTK_WIDGET(gtk_builder_get_object(builder, "spin2"));

    icon1 = GTK_WIDGET(gtk_builder_get_object(builder, "icon1"));
    icon2 = GTK_WIDGET(gtk_builder_get_object(builder, "icon2"));
    icon3 = GTK_WIDGET(gtk_builder_get_object(builder, "icon3"));
    icon4 = GTK_WIDGET(gtk_builder_get_object(builder, "icon4"));
    icon5 = GTK_WIDGET(gtk_builder_get_object(builder, "icon5"));
    icon6 = GTK_WIDGET(gtk_builder_get_object(builder, "icon6"));
    icon7 = GTK_WIDGET(gtk_builder_get_object(builder, "icon7"));
    icon8 = GTK_WIDGET(gtk_builder_get_object(builder, "icon8"));
    icon9 = GTK_WIDGET(gtk_builder_get_object(builder, "icon9"));
    icon10 = GTK_WIDGET(gtk_builder_get_object(builder, "icon10"));
    icon11 = GTK_WIDGET(gtk_builder_get_object(builder, "icon11"));
    //icon12 = GTK_WIDGET(gtk_builder_get_object(builder, "icon12"));

    label1bis = GTK_WIDGET(gtk_builder_get_object(builder, "label1bis"));
    label2bis = GTK_WIDGET(gtk_builder_get_object(builder, "label2bis"));
    label3bis = GTK_WIDGET(gtk_builder_get_object(builder, "label3bis"));
    label4bis = GTK_WIDGET(gtk_builder_get_object(builder, "label4bis"));
    label5bis = GTK_WIDGET(gtk_builder_get_object(builder, "label5bis"));
    label6bis = GTK_WIDGET(gtk_builder_get_object(builder, "label6bis"));
    label7bis = GTK_WIDGET(gtk_builder_get_object(builder, "label7bis"));
    label8bis = GTK_WIDGET(gtk_builder_get_object(builder, "label8bis"));
    label9bis = GTK_WIDGET(gtk_builder_get_object(builder, "label9bis"));
    label10bis = GTK_WIDGET(gtk_builder_get_object(builder, "label10bis"));
    label11bis = GTK_WIDGET(gtk_builder_get_object(builder, "label11bis"));
    //label12bis = GTK_WIDGET(gtk_builder_get_object(builder, "label12bis"));
    labelTimer = GTK_WIDGET(gtk_builder_get_object(builder, "labelTimer"));
    labelHumans = GTK_WIDGET(gtk_builder_get_object(builder, "labelHumans"));

    road1 = GTK_WIDGET(gtk_builder_get_object(builder, "road1"));
    road2 = GTK_WIDGET(gtk_builder_get_object(builder, "road2"));
    road3 = GTK_WIDGET(gtk_builder_get_object(builder, "road3"));
    road4 = GTK_WIDGET(gtk_builder_get_object(builder, "road4"));
    road5 = GTK_WIDGET(gtk_builder_get_object(builder, "road5"));
    road6 = GTK_WIDGET(gtk_builder_get_object(builder, "road6"));
    road7 = GTK_WIDGET(gtk_builder_get_object(builder, "road7"));
    road8 = GTK_WIDGET(gtk_builder_get_object(builder, "road8"));
    road9 = GTK_WIDGET(gtk_builder_get_object(builder, "road9"));
    road10 = GTK_WIDGET(gtk_builder_get_object(builder, "road10"));
    road11 = GTK_WIDGET(gtk_builder_get_object(builder, "road11"));
    road12 = GTK_WIDGET(gtk_builder_get_object(builder, "road12"));

    buttonIcon1 = GTK_WIDGET(gtk_builder_get_object(builder, "buttonIcon1"));
    buttonIcon2 = GTK_WIDGET(gtk_builder_get_object(builder, "buttonIcon2"));
    buttonIcon3 = GTK_WIDGET(gtk_builder_get_object(builder, "buttonIcon3"));
    buttonIcon4 = GTK_WIDGET(gtk_builder_get_object(builder, "buttonIcon4"));
    buttonIcon5 = GTK_WIDGET(gtk_builder_get_object(builder, "buttonIcon5"));
    buttonIcon6 = GTK_WIDGET(gtk_builder_get_object(builder, "buttonIcon6"));
    buttonIcon7 = GTK_WIDGET(gtk_builder_get_object(builder, "buttonIcon7"));
    buttonIcon8 = GTK_WIDGET(gtk_builder_get_object(builder, "buttonIcon8"));
    buttonIcon9 = GTK_WIDGET(gtk_builder_get_object(builder, "buttonIcon9"));
    buttonIcon10 = GTK_WIDGET(gtk_builder_get_object(builder, "buttonIcon10"));
    buttonIcon11 = GTK_WIDGET(gtk_builder_get_object(builder, "buttonIcon11"));
    buttonIcon12 = GTK_WIDGET(gtk_builder_get_object(builder, "buttonIcon12"));

    button1bis = GTK_WIDGET(gtk_builder_get_object(builder, "button1bis"));

    buttonPath = GTK_WIDGET(gtk_builder_get_object(builder, "buttonPath"));

    checkIcon1 = GTK_WIDGET(gtk_builder_get_object(builder, "checkIcon1"));
    checkIcon2 = GTK_WIDGET(gtk_builder_get_object(builder, "checkIcon2"));
    checkIcon3 = GTK_WIDGET(gtk_builder_get_object(builder, "checkIcon3"));
    checkIcon4 = GTK_WIDGET(gtk_builder_get_object(builder, "checkIcon4"));
    checkIcon5 = GTK_WIDGET(gtk_builder_get_object(builder, "checkIcon5"));
    checkIcon6 = GTK_WIDGET(gtk_builder_get_object(builder, "checkIcon6"));
    checkIcon7 = GTK_WIDGET(gtk_builder_get_object(builder, "checkIcon7"));
    checkIcon8 = GTK_WIDGET(gtk_builder_get_object(builder, "checkIcon8"));
    checkIcon9 = GTK_WIDGET(gtk_builder_get_object(builder, "checkIcon9"));
    checkIcon10 = GTK_WIDGET(gtk_builder_get_object(builder, "checkIcon10"));
    checkIcon11 = GTK_WIDGET(gtk_builder_get_object(builder, "checkIcon11"));

    iconSmall1 = GTK_WIDGET(gtk_builder_get_object(builder, "iconSmall1"));
    iconSmall2 = GTK_WIDGET(gtk_builder_get_object(builder, "iconSmall2"));
    iconSmall3 = GTK_WIDGET(gtk_builder_get_object(builder, "iconSmall3"));
    iconSmall4 = GTK_WIDGET(gtk_builder_get_object(builder, "iconSmall4"));
    iconSmall5 = GTK_WIDGET(gtk_builder_get_object(builder, "iconSmall5"));
    iconSmall6 = GTK_WIDGET(gtk_builder_get_object(builder, "iconSmall6"));
    iconSmall7 = GTK_WIDGET(gtk_builder_get_object(builder, "iconSmall7"));
    iconSmall8 = GTK_WIDGET(gtk_builder_get_object(builder, "iconSmall8"));
    iconSmall9 = GTK_WIDGET(gtk_builder_get_object(builder, "iconSmall9"));
    iconSmall10 = GTK_WIDGET(gtk_builder_get_object(builder, "iconSmall10"));
    iconSmall11 = GTK_WIDGET(gtk_builder_get_object(builder, "iconSmall11"));

    gtk_widget_show(window1);

    //TO START
    //g_signal_connect(button1, "clicked", G_CALLBACK(on_start), &game);
    //g_signal_connect(button1bis, "clicked", G_CALLBACK(on_start), &game);
    // TO STOP
    // g_source_remove(game->disc.event);
    // game->disc.event = 0;

    gtk_main();

    return 0;
}

int TimerCallback()
{
    // --- Another second has gone by ---
    nbSeconds += 1;
    updateLabel(GTK_LABEL(labelTimer), nbSeconds);

    if (nbOfHumans == 0)
        return 0;
    else
        return 1;
}

//toutes les 5s att->capacity personne sortent de l'att et retourne
//dans une autre attractions
int loop2()
{
    attraction** atts = parcGUI->att;
    attraction* att = *atts;
    //srand(time(NULL));
    //sleep(2);

    for(size_t i = 0; i < parcGUI->nbatt; i++)
    {
        att = *(atts+i);

        for (size_t j = 0; j < att->capacity && att->nbpeople > 0; j++)
        {
            dest(parcGUI);
            att->nbpeople--;
        }
    }

    att = *(atts + parcGUI->nbatt);
    att->likeness += 3;
    parcGUI->totlikeness += 3;
    
    if (parcGUI->nbpeople > 0)
        parcGUI->nbpeople = 0;
    
    if (nbOfHumans == 0)
        return 0;
    else
        return 1;
}

int timeoutLabel()
{
    nbOfHumans = 0;

    for(size_t i = 0; i < parcGUI->nbatt; i++)
    {
        attraction* att = *(parcGUI->att+i);
        updateLabel(GTK_LABEL(label[i]), att->nbpeople);
        nbOfHumans += att->nbpeople;
    }

    updateLabel(GTK_LABEL(labelHumans), nbOfHumans);

    if (nbOfHumans == 0)
        return 0;
    else
        return 1;
}

void on_button1_clicked(__attribute__((unused)) GtkButton *button)
{
    // Start the simulation

    nbOfAttractions = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin1));
    nbOfHumans = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin2));

    create_icon_array(icon);
    create_label_array(label);
    create_road_array(road);
    create_buttonIcon_array(buttonIcon);
    create_iconSmall_array(iconSmall);
    create_check_array(checkIcon);

    for (int i = 11; i >= 0; i -= 1)
        gtk_widget_set_opacity(buttonIcon[i], 0);

    for (int i = 11; i > 1; i -= 1)
    {
        //gtk_widget_show(icon[i]);
        //gtk_widget_show(label[i]);
        gtk_widget_show(road[i]);
        gtk_widget_show(buttonIcon[i]);
    }

    for (int i = 10; i > 1; i -= 1)
    {
        gtk_widget_show(icon[i]);
        gtk_widget_show(label[i]);
        gtk_widget_show(iconSmall[i]);
        gtk_widget_show(checkIcon[i]);
    }

    for (int i = 10; i > nbOfAttractions - 1; i -= 1)
    {
        gtk_widget_hide(icon[i]);
        gtk_widget_hide(label[i]);
        gtk_widget_hide(iconSmall[i]);
        gtk_widget_hide(checkIcon[i]);
    }

    for (int i = 11; i > nbOfAttractions; i -= 1)
    {
        //gtk_widget_hide(icon[i]);
        //gtk_widget_hide(label[i]);
        gtk_widget_hide(road[i]);
        gtk_widget_hide(buttonIcon[i]);
    }

    //START TIMER
    nbSeconds = 0;
    updateLabel(GTK_LABEL(labelTimer), nbSeconds);
    threadID = g_timeout_add(1000, TimerCallback, NULL);

    gtk_widget_hide(window1);
    gtk_widget_show(window2);

    gtk_widget_show(icon1);

    //START ALGORITHMS

    parcGUI = init_parc(nbOfAttractions);
    pop_init(nbOfHumans, parcGUI);
    timeoutLabel();
    humanID = g_timeout_add(200, timeoutLabel, NULL);
    iaID = g_timeout_add(2000, loop2, NULL);

    // TEST :
    //printf("%i\n", nbOfHumans);
    //printf("%i\n", isRaining);
    //printf("%i\n", nbOfAttractions);
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

void on_check1_toggled(GtkCheckButton* check)
{
    // Goes here if weather is changed

    gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(check));
    if (T)
        isRaining = 1;
    else
        isRaining = 0;
}

void on_button1bis_clicked()
{
    gtk_widget_show(window1);
    gtk_widget_hide(window2);

    if (nbOfHumans != 0)
    {
        g_source_remove(threadID);
        g_source_remove(humanID);
        g_source_remove(iaID);
    }

    for (int i = 0; i < nbOfAttractions; i += 1)
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkIcon[i])))
            gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkIcon[i]), FALSE);

    game.disc.rect.x = 310;
    game.disc.rect.y = 110;

    //TEMP
    if (game.disc.event != 0)
        g_source_remove(game.disc.event);

    game.disc.event = 0;
    game.disc.step.x = 1;
    game.disc.step.y = -1;
    game.disc.attractionIn = 0;
    game.disc.attractionGo = 1;
    game.disc.posX = 469;
    game.disc.posY = 110;
}

void on_buttonIcon1_clicked()
{

}

void on_buttonIcon2_clicked()
{

}

void on_buttonIcon3_clicked()
{

}

void on_buttonIcon4_clicked()
{
    
}

void on_buttonIcon5_clicked()
{
    
}

void on_buttonIcon6_clicked()
{
    
}

void on_buttonIcon7_clicked()
{
    
}

void on_buttonIcon8_clicked()
{
    
}

void on_buttonIcon9_clicked()
{
    
}

void on_buttonIcon10_clicked()
{
    
}

void on_buttonIcon11_clicked()
{
    
}

void on_buttonIcon12_clicked()
{
    
}

void on_buttonPath_clicked(GtkButton* button)
{
    //game.disc.posOrNeg = FALSE;
    //game.disc.step.x = step[game.disc.attractionIn];
    on_start(button, &game);
}

void on_checkIcon1_toggled()
{
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkIcon[0])))
        attractionToggled[0] = 0;
    else
        attractionToggled[0] = 1;
}

void on_checkIcon2_toggled()
{
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkIcon[1])))
        attractionToggled[1] = 0;
    else
        attractionToggled[1] = 1;
}

void on_checkIcon3_toggled()
{
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkIcon[2])))
        attractionToggled[2] = 0;
    else
        attractionToggled[2] = 1;
}

void on_checkIcon4_toggled()
{
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkIcon[3])))
        attractionToggled[3] = 0;
    else
        attractionToggled[3] = 1;
}

void on_checkIcon5_toggled()
{
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkIcon[4])))
        attractionToggled[4] = 0;
    else
        attractionToggled[4] = 1;
}

void on_checkIcon6_toggled()
{
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkIcon[5])))
        attractionToggled[5] = 0;
    else
        attractionToggled[5] = 1;
}

void on_checkIcon7_toggled()
{
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkIcon[6])))
        attractionToggled[6] = 0;
    else
        attractionToggled[6] = 1;
}

void on_checkIcon8_toggled()
{
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkIcon[7])))
        attractionToggled[7] = 0;
    else
        attractionToggled[7] = 1;
}

void on_checkIcon9_toggled()
{
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkIcon[8])))
        attractionToggled[8] = 0;
    else
        attractionToggled[8] = 1;
}

void on_checkIcon10_toggled()
{
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkIcon[9])))
        attractionToggled[9] = 0;
    else
        attractionToggled[9] = 1;
}

void on_checkIcon11_toggled()
{
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkIcon[10])))
        attractionToggled[10] = 0;
    else
        attractionToggled[10] = 1;
}

void on_buttonValidate_clicked(GtkButton* button)
{
    game.disc.posOrNeg = FALSE;
    game.disc.step.x = step[game.disc.attractionIn];

    for (int i = 0; i < nbOfAttractions; i += 1)
    {
        if (attractionToggled[i] == 0)
        {
            game.disc.attractionGo = attractions[i + 1].number;
            game.disc.posX = attractions[i + 1].posX;
            game.disc.posY = attractions[i + 1].posY;
            on_start(button, &game);
            break;
        }
    }
}

//WHEN SOMEONE GOES IN AN ATTRACTION
/*  int nb = get_int_from_label(label1bis);
    nb += 1;
    updateLabel(GTK_LABEL(label1bis), nb);  */
