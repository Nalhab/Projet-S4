#include "move.h"

// COORDINATES OF ATTRACTIONS :
// PARC 1 :  x = 310
//           y = 110
//------------------
// PARC 2 :  x = 470
//           y = 110
//------------------
// PARC 3 :  x = 537
//           y = 161
//------------------
// PARC 4 :  x = 581
//           y = 205
//------------------
// PARC 5 :  x = 580
//           y = 295
//------------------
// PARC 6 :  x = 537
//           y = 338
//------------------
// PARC 7 :  x = 470
//           y = 390
//------------------
// PARC 8 :  x = 310
//           y = 390
//------------------
// PARC 9 :  x = 241
//           y = 339
//------------------
// PARC 10 : x = 197
//           y = 295
//------------------
// PARC 11 : x = 197
//           y = 204
//------------------
// PARC 12 : x = 238
//           y = 163

// Signal handler for the "draw" signal of the drawing area.
gboolean on_draw(__attribute__((unused)) GtkWidget *widget, cairo_t *cr, 
    gpointer user_data)
{
    // Gets the rectangle.
    Game* game = user_data;

    // Draws the rectangle in red.
    cairo_set_source_rgb(cr, 1, 0, 0);
    cairo_rectangle(cr, game->disc.rect.x, game->disc.rect.y,
        game->disc.rect.width, game->disc.rect.height);
    cairo_fill(cr);

    // Propagates the signal.
    return FALSE;
}

void redraw_item(GtkDrawingArea *area, GdkRectangle *old, GdkRectangle *new)
{
    gdk_rectangle_union(old, new, old);
    gtk_widget_queue_draw_area(GTK_WIDGET(area), old->x, old->y, old->width,
        old->height);
}

gboolean on_move_disc(gpointer user_data)
{
    // Gets the `Game` structure passed as parameter.
    Game* game = user_data;

    // Gets the largest coordinate for the disc.
    //gint x_max = gtk_widget_get_allocated_width(GTK_WIDGET(game->ui.area))
    //    - game->disc.rect.width;
    //gint y_max = gtk_widget_get_allocated_height(GTK_WIDGET(game->ui.area))
    //    - game->disc.rect.height;

    gint x_max = 584;
    gint y_max = 390;

    // Gets the current position of the disc.
    GdkRectangle old = game->disc.rect;

    if (game->disc.rect.x == 291 && game->disc.rect.y == 110)
        if (game->disc.step.x == -1)
            game->disc.step.y *= -1;
    if (game->disc.rect.x == 485 && game->disc.rect.y == 110)
        if (game->disc.step.x == 1)
            game->disc.step.y *= -1;
    if (game->disc.rect.x == 584 && game->disc.rect.y == 208)
        if (game->disc.step.y == -1)
            game->disc.step.x *= -1;
    if (game->disc.rect.x == 584 && game->disc.rect.y == 291)
        if (game->disc.step.y == 1)
            game->disc.step.x *= -1;
    if (game->disc.rect.x == 485 && game->disc.rect.y == 390)
        if (game->disc.step.x == 1)
            game->disc.step.y *= -1;
    if (game->disc.rect.x == 291 && game->disc.rect.y == 390)
        if (game->disc.step.x == -1)
            game->disc.step.y *= -1;
    if (game->disc.rect.x == 193 && game->disc.rect.y == 291)
        if (game->disc.step.y == 1)
            game->disc.step.x *= -1;
    if (game->disc.rect.x == 193 && game->disc.rect.y == 208)
        if (game->disc.step.y == -1)
            game->disc.step.x *= -1;
    
    //TESTS//TESTS//TESTS//TESTS//TESTS//TESTS//TESTS//TESTS//TESTS//TESTS
    /*if (game->disc.rect.x == 310 && game->disc.rect.y == 110)
    {
        g_source_remove(game->disc.event);
        game->disc.event = 0;
        sleep(1);
        game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
    }
    if (game->disc.rect.x == 470 && game->disc.rect.y == 110)
    {
        g_source_remove(game->disc.event);
        game->disc.event = 0;
        sleep(1);
        game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
    }
    if (game->disc.rect.x == 537 && game->disc.rect.y == 161)
    {
        g_source_remove(game->disc.event);
        game->disc.event = 0;
        sleep(1);
        game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
    }
    if (game->disc.rect.x == 581 && game->disc.rect.y == 205)
    {
        g_source_remove(game->disc.event);
        game->disc.event = 0;
        sleep(1);
        game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
    }
    if (game->disc.rect.x == 580 && game->disc.rect.y == 295)
    {
        g_source_remove(game->disc.event);
        game->disc.event = 0;
        sleep(1);
        game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
    }
    if (game->disc.rect.x == 537 && game->disc.rect.y == 338)
    {
        g_source_remove(game->disc.event);
        game->disc.event = 0;
        sleep(1);
        game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
    }
    if (game->disc.rect.x == 470 && game->disc.rect.y == 390)
    {
        g_source_remove(game->disc.event);
        game->disc.event = 0;
        sleep(1);
        game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
    }
    if (game->disc.rect.x == 310 && game->disc.rect.y == 390)
    {
        g_source_remove(game->disc.event);
        game->disc.event = 0;
        sleep(1);
        game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
    }
    if (game->disc.rect.x == 241 && game->disc.rect.y == 339)
    {
        g_source_remove(game->disc.event);
        game->disc.event = 0;
        sleep(1);
        game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
    }
    if (game->disc.rect.x == 197 && game->disc.rect.y == 295)
    {
        g_source_remove(game->disc.event);
        game->disc.event = 0;
        sleep(1);
        game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
    }
    if (game->disc.rect.x == 197 && game->disc.rect.y == 204)
    {
        g_source_remove(game->disc.event);
        game->disc.event = 0;
        sleep(1);
        game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
    }
    if (game->disc.rect.x == 238 && game->disc.rect.y == 163)
    {
        g_source_remove(game->disc.event);
        game->disc.event = 0;
        sleep(1);
        game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
    }*/
    //TESTS//TESTS//TESTS//TESTS//TESTS//TESTS//TESTS//TESTS//TESTS//TESTS

    // Works out the new position of the disc.
    game->disc.rect.x = CLAMP(game->disc.rect.x + game->disc.step.x, 193,
        x_max);
    game->disc.rect.y = CLAMP(game->disc.rect.y + game->disc.step.y, 110,
        y_max);

    // Redraws the disc.
    redraw_item(game->ui.area, &old, &game->disc.rect);

    // Enables the next call.
    return TRUE;
}

// Event handler for the "clicked" signal of the start button.
void on_start(__attribute__((unused)) GtkButton *button, gpointer user_data)
{
    // Gets the `Game` structure.
    Game* game = user_data;

    // If the timeout function is not activated, activates it.
    // (The event ID is saved into game->disc.event.)
    if (game->disc.event == 0)
        game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);

    // If the timeout function is already activated.
    else
    {
        // Deactivates it.
        g_source_remove(game->disc.event);

        // Resets the event ID to zero.
        //game->disc.event = 0;
    }
}