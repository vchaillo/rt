/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 00:31:16 by valentin          #+#    #+#             */
/*   Updated: 2017/03/29 10:23:21 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			create_buttons(GtkWidget *grid)
{
	GtkWidget		*button;

	button = gtk_button_new_with_label("Button 1");
	// g_signal_connect(button, "clicked", G_CALLBACK(start_mlx), e);
	gtk_grid_attach(GTK_GRID(grid), button, 0, 0, 1, 1);
	button = gtk_button_new_with_label("Button 2");
	gtk_grid_attach(GTK_GRID(grid), button, 1, 0, 1, 1);
	button = gtk_button_new_with_label("Quit");
	g_signal_connect(button, "clicked", G_CALLBACK(gtk_main_quit), NULL);
	gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 2, 1);
}

void				start_gtk(t_env *e)
{
	GtkWidget 		*window;
	GtkWidget		*grid;
	GtkWidget		*image;

	(void)e;
	gtk_init(0, NULL);

	// create window and set properties
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "rt");
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	// gtk_window_maximize(GTK_WINDOW(window));

	// create grid and add it in window
	grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(window), grid);
	image = gtk_image_new_from_file("doc/screenshots/20170322_061703.bmp");
	gtk_grid_attach(GTK_GRID(grid), image, 2, 0, 1, 10);

	// fill the grid with button and gl_area
	create_buttons(grid);

	gtk_widget_show_all(window);
	gtk_main();
}
