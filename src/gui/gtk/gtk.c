/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 00:31:16 by valentin          #+#    #+#             */
/*   Updated: 2017/03/29 08:33:57 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

// static gboolean
// render (GtkGLArea *area, GdkGLContext *context)
// {
//   // inside this function it's safe to use GL; the given
//   // #GdkGLContext has been made current to the drawable
//   // surface used by the #GtkGLArea and the viewport has
//   // already been set to be the size of the allocation
//
//   // we can start by clearing the buffer
//   glClearColor (0, 0, 0, 0);
//   glClear (GL_COLOR_BUFFER_BIT);
//
//   // draw your object
//   draw_an_object ();
//
//   // we completed our drawing; the draw commands will be
//   // flushed at the end of the signal emission chain, and
//   // the buffers will be drawn on the window
//   return TRUE;
// }
//
// static void			create_gl_area(t_env *e, GtkWidget *window)
// {
// 	(void)e;
// 	GtkWidget *gl_area = gtk_gl_area_new();
// 	g_signal_connect (gl_area, "render", G_CALLBACK (render), NULL);
// }

static void			create_buttons(GtkWidget *window)
{
	GtkWidget		*grid;
	GtkWidget		*button;

	grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(window), grid);
	button = gtk_button_new_with_label("Start Mlx");
	// g_signal_connect(button, "clicked", G_CALLBACK(start_mlx), e);
	gtk_grid_attach(GTK_GRID(grid), button, 0, 0, 1, 1);
	button = gtk_button_new_with_label("Button 2");
	// g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
	gtk_grid_attach(GTK_GRID(grid), button, 1, 0, 1, 1);
	button = gtk_button_new_with_label("Quit");
	g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);
	gtk_grid_attach(GTK_GRID(grid), button, 2, 0, 1, 1);
}

void				start_gtk(t_env *e)
{
	GtkWidget 		*window;

	(void)e;
	gtk_init(0, NULL);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "rt");
	gtk_window_maximize(GTK_WINDOW(window));
	create_buttons(window);
	// create_gl_area(e, window);
	gtk_widget_show_all(window);
	gtk_main();
}
