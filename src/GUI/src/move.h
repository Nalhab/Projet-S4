#ifndef _MOVE_H_
#define _MOVE_H_

#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include <unistd.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <gdk/gdkscreen.h>
#include <cairo.h>

#define DISC_PERIOD 30

typedef struct Disc
{
    GdkRectangle rect;              // Position and size
    GdkPoint step;                  // Horizontal and verical steps in pixels
    guint period;                   // Period in milliseconds
    guint event;                    // Event ID used to move the disc
} Disc;

typedef struct UserInterface
{
    GtkWindow* window;              // Main window
    GtkDrawingArea* area;           // Drawing area
} UserInterface;

typedef struct Game
{
    Disc disc;                      // Disc
    UserInterface ui;               // User interface
} Game;

gboolean on_draw(__attribute__((unused)) GtkWidget *widget, cairo_t *cr, gpointer user_data);

void redraw_item(GtkDrawingArea *area, GdkRectangle *old, GdkRectangle *new);

gboolean on_move_disc(gpointer user_data);

void on_start(__attribute__((unused)) GtkButton *button, gpointer user_data);

#endif
