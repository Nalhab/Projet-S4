#include "move.h"

// COORDINATES OF ATTRACTIONS :
// PARC 1 :  x = 310
//           y = 110
//------------------
// PARC 2 :  x = 469
//           y = 110
//------------------
// PARC 3 :  x = 536
//           y = 161
//------------------
// PARC 4 :  x = 580
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
// PARC 9 :  x = 240
//           y = 339
//------------------
// PARC 10 : x = 196
//           y = 295
//------------------
// PARC 11 : x = 197
//           y = 204
//------------------
// PARC 12 : x = 238
//           y = 163
//------------------
// MID :     x = 389
//           y = 250
//------------------
// MID N :   x = 389
//           y = 110
//------------------
// MID W :   x = 193
//           y = 250
//------------------
// MID E :   x = 584
//           y = 250
//------------------
// MID S :   x = 389
//           y = 390

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
    if (game->disc.rect.x == 584 && game->disc.rect.y == 209)
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
    if (game->disc.rect.x == 193 && game->disc.rect.y == 292)
        if (game->disc.step.y == 1)
            game->disc.step.x *= -1;
    if (game->disc.rect.x == 193 && game->disc.rect.y == 208)
        if (game->disc.step.y == -1)
            game->disc.step.x *= -1;


    if (game->disc.attractionIn == 0)
    {
        if (game->disc.attractionGo >= 4 && game->disc.attractionGo <= 7)
        {
            if (game->disc.rect.x == 389 &&  game->disc.rect.y == 110)
            {
                game->disc.step.x = 0;
                game->disc.step.y = 1;
                g_source_remove(game->disc.event);
                game->disc.event = 0;
                game->disc.event = g_timeout_add(15, on_move_disc, game);
            }
            else if (game->disc.rect.x == 389 &&  game->disc.rect.y == 390)
            {
                if (game->disc.attractionGo == 7)
                    game->disc.step.x = -1;
                else
                    game->disc.step.x = 1;

                g_source_remove(game->disc.event);
                game->disc.event = 0;
                game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
            }
            else if (game->disc.attractionGo == 4)
            {
                if (game->disc.rect.x == 389 && game->disc.rect.y == 250)
                {
                    game->disc.step.x = 1;
                    game->disc.step.y = 0;
                }
                else if (game->disc.rect.x == 584 && game->disc.rect.y == 250)
                {
                    game->disc.step.y = 1;
                    g_source_remove(game->disc.event);
                    game->disc.event = 0;
                    game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
                }
            }
        }
        else
            if (game->disc.posOrNeg == FALSE)
                if (game->disc.attractionGo > 7)
                {
                    game->disc.step.x = -1;
                    game->disc.posOrNeg = TRUE;
                }
    }
    else if (game->disc.attractionIn == 1)
    {
        if (game->disc.attractionGo >= 6 && game->disc.attractionGo <= 9)
        {
            if (game->disc.rect.x == 389 &&  game->disc.rect.y == 110)
            {
                game->disc.step.x = 0;
                game->disc.step.y = 1;
                g_source_remove(game->disc.event);
                game->disc.event = 0;
                game->disc.event = g_timeout_add(15, on_move_disc, game);
            }
            else if (game->disc.rect.x == 389 &&  game->disc.rect.y == 390)
            {
                if (game->disc.attractionGo == 6)
                    game->disc.step.x = 1;
                else
                    game->disc.step.x = -1;

                g_source_remove(game->disc.event);
                game->disc.event = 0;
                game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
            }
            else if (game->disc.attractionGo == 9)
            {
                if (game->disc.rect.x == 389 && game->disc.rect.y == 250)
                {
                    game->disc.step.x = -1;
                    game->disc.step.y = 0;
                }
                else if (game->disc.rect.x == 193 && game->disc.rect.y == 250)
                {
                    game->disc.step.y = 1;
                    g_source_remove(game->disc.event);
                    game->disc.event = 0;
                    game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
                }
            }
        }
        else
            if (game->disc.posOrNeg == FALSE)
                if (game->disc.attractionGo > 1 && game->disc.attractionGo < 10)
                {
                    game->disc.step.x = 1;
                    game->disc.posOrNeg = TRUE;
                }
    }
    else if (game->disc.attractionIn == 2)
    {
        if (game->disc.attractionGo >= 7 && game->disc.attractionGo <= 10)
        {
            if (game->disc.rect.x == 389 &&  game->disc.rect.y == 110)
            {
                game->disc.step.x = 0;
                game->disc.step.y = 1;
                g_source_remove(game->disc.event);
                game->disc.event = 0;
                game->disc.event = g_timeout_add(15, on_move_disc, game);
            }
            else if (game->disc.rect.x == 389 &&  game->disc.rect.y == 390)
            {
                game->disc.step.x = -1;
                g_source_remove(game->disc.event);
                game->disc.event = 0;
                game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
            }
            else if (game->disc.attractionGo >= 9)
            {
                if (game->disc.rect.x == 389 && game->disc.rect.y == 250)
                {
                    game->disc.step.x = -1;
                    game->disc.step.y = 0;
                }
                else if (game->disc.rect.x == 193 && game->disc.rect.y == 250)
                {
                    if (game->disc.attractionGo == 10)
                        game->disc.step.y = -1;
                    else
                        game->disc.step.y = 1;

                    g_source_remove(game->disc.event);
                    game->disc.event = 0;
                    game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
                }
            }
        }
        
        if (game->disc.posOrNeg == FALSE)
        {
            if (game->disc.attractionGo > 2 && game->disc.attractionGo < 7)
            {
                game->disc.step.x = 1;
                game->disc.step.y = 1;
                game->disc.posOrNeg = TRUE;
            }
            else
            {
                game->disc.step.y = -1;
                game->disc.posOrNeg = TRUE;
            }
        }
    }
    else if (game->disc.attractionIn == 3)
    {
        if (game->disc.attractionGo >= 7 && game->disc.attractionGo <= 10)
        {
            if (game->disc.rect.x == 584 &&  game->disc.rect.y == 250)
            {
                game->disc.step.x = -1;
                game->disc.step.y = 0;
                g_source_remove(game->disc.event);
                game->disc.event = 0;
                game->disc.event = g_timeout_add(15, on_move_disc, game);
            }
            else if (game->disc.rect.x == 193 &&  game->disc.rect.y == 250)
            {
                if (game->disc.attractionGo == 10)
                    game->disc.step.y = -1;
                else
                    game->disc.step.y = 1;

                g_source_remove(game->disc.event);
                game->disc.event = 0;
                game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
            }
            else if (game->disc.attractionGo <= 8)
            {
                if (game->disc.rect.x == 389 && game->disc.rect.y == 250)
                {
                    game->disc.step.x = 0;
                    game->disc.step.y = 1;
                }
                else if (game->disc.rect.x == 389 && game->disc.rect.y == 390)
                {
                    game->disc.step.x = -1;
                    g_source_remove(game->disc.event);
                    game->disc.event = 0;
                    game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
                }
            }
        }

        if (game->disc.posOrNeg == FALSE)
        {
            if (game->disc.attractionGo < 3 || game->disc.attractionGo == 11)
            {
                game->disc.step.x = -1;
                game->disc.step.y = -1;
                game->disc.posOrNeg = TRUE;
            }
            else
            {
                game->disc.step.y = 1;
                game->disc.posOrNeg = TRUE;
            }
        }
    }
    else if (game->disc.attractionIn == 4)
    {
        if (game->disc.attractionGo >= 8 && game->disc.attractionGo <= 11)
        {
            if (game->disc.rect.x == 584 &&  game->disc.rect.y == 250)
            {
                game->disc.step.x = -1;
                game->disc.step.y = 0;
                g_source_remove(game->disc.event);
                game->disc.event = 0;
                game->disc.event = g_timeout_add(15, on_move_disc, game);
            }
            else if (game->disc.rect.x == 193 &&  game->disc.rect.y == 250)
            {
                if (game->disc.attractionGo == 9)
                    game->disc.step.y = 1;
                else
                    game->disc.step.y = -1;

                g_source_remove(game->disc.event);
                game->disc.event = 0;
                game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
            }
            else if (game->disc.attractionGo == 11 || game->disc.attractionGo == 0)
            {
                if (game->disc.rect.x == 389 && game->disc.rect.y == 250)
                {
                    game->disc.step.x = 0;
                    game->disc.step.y = -1;
                }
                else if (game->disc.rect.x == 389 && game->disc.rect.y == 110)
                {
                    game->disc.step.x = -1;
                    g_source_remove(game->disc.event);
                    game->disc.event = 0;
                    game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
                }
            }
        }

        if (game->disc.posOrNeg == FALSE)
        {
            if (game->disc.attractionGo > 4 && game->disc.attractionGo < 9)
            {
                game->disc.step.x = -1;
                game->disc.step.y = 1;
                game->disc.posOrNeg = TRUE;
            }
            else
            {
                game->disc.step.y = -1;
                game->disc.posOrNeg = TRUE;
            }
        }
    }
    else if (game->disc.attractionIn == 5)
    {
        if (game->disc.attractionGo >= 9 || game->disc.attractionGo == 0)
        {
            if (game->disc.rect.x == 389 &&  game->disc.rect.y == 390)
            {
                game->disc.step.x = 0;
                game->disc.step.y = -1;
                g_source_remove(game->disc.event);
                game->disc.event = 0;
                game->disc.event = g_timeout_add(15, on_move_disc, game);
            }
            else if (game->disc.rect.x == 389 &&  game->disc.rect.y == 110)
            {
                game->disc.step.x = -1;
                g_source_remove(game->disc.event);
                game->disc.event = 0;
                game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
            }
            else if (game->disc.attractionGo <= 10)
            {
                if (game->disc.rect.x == 389 && game->disc.rect.y == 250)
                {
                    game->disc.step.x = -1;
                    game->disc.step.y = 0;
                }
                else if (game->disc.rect.x == 193 && game->disc.rect.y == 250)
                {
                    if (game->disc.attractionGo == 10)
                        game->disc.step.y = -1;
                    else
                        game->disc.step.y = 1;

                    g_source_remove(game->disc.event);
                    game->disc.event = 0;
                    game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
                }
            }
        }
        
        if (game->disc.posOrNeg == FALSE)
        {
            if (game->disc.attractionGo > 0 && game->disc.attractionGo < 5)
            {
                game->disc.step.x = 1;
                game->disc.step.y = -1;
                game->disc.posOrNeg = TRUE;
            }
            else
            {
                game->disc.step.y = 1;
                game->disc.posOrNeg = TRUE;
            }
        }
    }
    else if (game->disc.attractionIn == 6)
    {
        if (game->disc.attractionGo <= 1 || game->disc.attractionGo >= 10)
        {
            if (game->disc.rect.x == 389 &&  game->disc.rect.y == 390)
            {
                game->disc.step.x = 0;
                game->disc.step.y = -1;
                g_source_remove(game->disc.event);
                game->disc.event = 0;
                game->disc.event = g_timeout_add(15, on_move_disc, game);
            }
            else if (game->disc.rect.x == 389 &&  game->disc.rect.y == 110)
            {
                if (game->disc.attractionGo == 1)
                    game->disc.step.x = 1;
                else
                    game->disc.step.x = -1;

                g_source_remove(game->disc.event);
                game->disc.event = 0;
                game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
            }
            else if (game->disc.attractionGo == 10)
            {
                if (game->disc.rect.x == 389 && game->disc.rect.y == 250)
                {
                    game->disc.step.x = -1;
                    game->disc.step.y = 0;
                }
                else if (game->disc.rect.x == 193 && game->disc.rect.y == 250)
                {
                    game->disc.step.y = -1;
                    g_source_remove(game->disc.event);
                    game->disc.event = 0;
                    game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
                }
            }
        }
        else if (game->disc.posOrNeg == FALSE)
            if (game->disc.attractionGo < 6)
            {
                game->disc.step.x = 1;
                game->disc.posOrNeg = TRUE;
            }
    }
    else if (game->disc.attractionIn == 7)
    {
        if (game->disc.attractionGo <= 3)
        {
            if (game->disc.rect.x == 389 &&  game->disc.rect.y == 390)
            {
                game->disc.step.x = 0;
                game->disc.step.y = -1;
                g_source_remove(game->disc.event);
                game->disc.event = 0;
                game->disc.event = g_timeout_add(15, on_move_disc, game);
            }
            else if (game->disc.rect.x == 389 &&  game->disc.rect.y == 110)
            {
                if (game->disc.attractionGo == 0)
                    game->disc.step.x = -1;
                else
                    game->disc.step.x = 1;

                g_source_remove(game->disc.event);
                game->disc.event = 0;
                game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
            }
            else if (game->disc.attractionGo == 3)
            {
                if (game->disc.rect.x == 389 && game->disc.rect.y == 250)
                {
                    game->disc.step.x = 1;
                    game->disc.step.y = 0;
                }
                else if (game->disc.rect.x == 584 && game->disc.rect.y == 250)
                {
                    game->disc.step.y = -1;
                    g_source_remove(game->disc.event);
                    game->disc.event = 0;
                    game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
                }
            }
        }
        else if (game->disc.posOrNeg == FALSE)
            if (game->disc.attractionGo > 7)
            {
                game->disc.step.x = -1;
                game->disc.posOrNeg = TRUE;
            }
    }
    else if (game->disc.attractionIn == 8)
    {
        if (game->disc.attractionGo >= 1 && game->disc.attractionGo <= 4)
        {
            if (game->disc.rect.x == 389 &&  game->disc.rect.y == 390)
            {
                game->disc.step.x = 0;
                game->disc.step.y = -1;
                g_source_remove(game->disc.event);
                game->disc.event = 0;
                game->disc.event = g_timeout_add(15, on_move_disc, game);
            }
            else if (game->disc.rect.x == 389 &&  game->disc.rect.y == 110)
            {
                game->disc.step.x = 1;
                g_source_remove(game->disc.event);
                game->disc.event = 0;
                game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
            }
            else if (game->disc.attractionGo >= 3)
            {
                if (game->disc.rect.x == 389 && game->disc.rect.y == 250)
                {
                    game->disc.step.x = 1;
                    game->disc.step.y = 0;
                }
                else if (game->disc.rect.x == 584 && game->disc.rect.y == 250)
                {
                    if (game->disc.attractionGo == 3)
                        game->disc.step.y = -1;
                    else
                        game->disc.step.y = 1;

                    g_source_remove(game->disc.event);
                    game->disc.event = 0;
                    game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
                }
            }
        }

        if (game->disc.posOrNeg == FALSE)
        {
            if (game->disc.attractionGo > 8)
            {
                game->disc.step.x = -1;
                game->disc.step.y = -1;
                game->disc.posOrNeg = TRUE;
            }
            else
            {
                game->disc.step.y = 1;
                game->disc.posOrNeg = TRUE;
            }
        }
    }
    else if (game->disc.attractionIn == 9)
    {
        if (game->disc.attractionGo >= 1 && game->disc.attractionGo <= 4)
        {
            if (game->disc.rect.x == 193 &&  game->disc.rect.y == 250)
            {
                game->disc.step.x = 1;
                game->disc.step.y = 0;
                g_source_remove(game->disc.event);
                game->disc.event = 0;
                game->disc.event = g_timeout_add(15, on_move_disc, game);
            }
            else if (game->disc.rect.x == 584 &&  game->disc.rect.y == 250)
            {
                if (game->disc.attractionGo == 4)
                    game->disc.step.y = 1;
                else
                    game->disc.step.y = -1;

                g_source_remove(game->disc.event);
                game->disc.event = 0;
                game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
            }
            else if (game->disc.attractionGo <= 2)
            {
                if (game->disc.rect.x == 389 && game->disc.rect.y == 250)
                {
                    game->disc.step.x = 0;
                    game->disc.step.y = -1;
                }
                else if (game->disc.rect.x == 389 && game->disc.rect.y == 110)
                {
                    game->disc.step.x = 1;
                    g_source_remove(game->disc.event);
                    game->disc.event = 0;
                    game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
                }
            }
        }

        if (game->disc.posOrNeg == FALSE)
        {
            if (game->disc.attractionGo > 9 || game->disc.attractionGo < 5)
            {
                game->disc.step.y = -1;
                game->disc.posOrNeg = TRUE;
            }
            else
            {
                game->disc.step.x = 1;
                game->disc.step.y = 1;
                game->disc.posOrNeg = TRUE;
            }
        }
    }
    else if (game->disc.attractionIn == 10)
    {
        if (game->disc.attractionGo >= 3 && game->disc.attractionGo <= 6)
        {
            if (game->disc.rect.x == 193 &&  game->disc.rect.y == 250)
            {
                game->disc.step.x = 1;
                game->disc.step.y = 0;
                g_source_remove(game->disc.event);
                game->disc.event = 0;
                game->disc.event = g_timeout_add(15, on_move_disc, game);
            }
            else if (game->disc.rect.x == 584 &&  game->disc.rect.y == 250)
            {
                if (game->disc.attractionGo == 3)
                    game->disc.step.y = -1;
                else
                    game->disc.step.y = 1;

                g_source_remove(game->disc.event);
                game->disc.event = 0;
                game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
            }
            else if (game->disc.attractionGo >= 5)
            {
                if (game->disc.rect.x == 389 && game->disc.rect.y == 250)
                {
                    game->disc.step.x = 0;
                    game->disc.step.y = 1;
                }
                else if (game->disc.rect.x == 389 && game->disc.rect.y == 390)
                {
                    game->disc.step.x = 1;
                    g_source_remove(game->disc.event);
                    game->disc.event = 0;
                    game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
                }
            }
        }

        if (game->disc.posOrNeg == FALSE)
        {
            if (game->disc.attractionGo == 11 || game->disc.attractionGo < 3)
            {
                game->disc.step.x = 1;
                game->disc.step.y = -1;
                game->disc.posOrNeg = TRUE;
            }
            else
            {
                game->disc.step.y = 1;
                game->disc.posOrNeg = TRUE;
            }
        }
    }
    else
    {
        if (game->disc.attractionGo >= 3 && game->disc.attractionGo <= 6)
        {
            if (game->disc.rect.x == 389 &&  game->disc.rect.y == 110)
            {
                game->disc.step.x = 0;
                game->disc.step.y = 1;
                g_source_remove(game->disc.event);
                game->disc.event = 0;
                game->disc.event = g_timeout_add(15, on_move_disc, game);
            }
            else if (game->disc.rect.x == 389 &&  game->disc.rect.y == 390)
            {
                game->disc.step.x = 1;
                g_source_remove(game->disc.event);
                game->disc.event = 0;
                game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
            }
            else if (game->disc.attractionGo <= 4)
            {
                if (game->disc.rect.x == 389 && game->disc.rect.y == 250)
                {
                    game->disc.step.x = 1;
                    game->disc.step.y = 0;
                }
                else if (game->disc.rect.x == 584 && game->disc.rect.y == 250)
                {
                    if (game->disc.attractionGo == 3)
                        game->disc.step.y = -1;
                    else
                        game->disc.step.y = 1;

                    g_source_remove(game->disc.event);
                    game->disc.event = 0;
                    game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
                }
            }
        }

        if (game->disc.posOrNeg == FALSE)
        {
            if (game->disc.attractionGo > 6)
            {
                game->disc.step.x = -1;
                game->disc.step.y = 1;
                game->disc.posOrNeg = TRUE;
            }
            else
            {
                game->disc.step.y = -1;
                game->disc.posOrNeg = TRUE;
            }
        }
    }

    if (game->disc.rect.x == game->disc.posX && game->disc.rect.y == game->disc.posY)
    {
        g_source_remove(game->disc.event);
        game->disc.event = 0;
        game->disc.attractionIn = game->disc.attractionGo;
        //game->disc.event = g_timeout_add(game->disc.period, on_move_disc, game);
    }

    //printf("X : %i\nY : %i\n", game->disc.rect.x, game->disc.rect.y);

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
        game->disc.event = 0;
    }
}