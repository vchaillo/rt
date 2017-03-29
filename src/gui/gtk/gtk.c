/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 00:31:16 by valentin          #+#    #+#             */
/*   Updated: 2017/03/29 03:14:11 by valentinchaillou89###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			create_buttons(GtkWidget *window)
{
	GtkWidget		*grid;
	GtkWidget		*button;

	grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(window), grid);
	button = gtk_button_new_with_label("Button 1");
	// g_signal_connect(button, "clicked", G_CALLBACK (print_hello), NULL);
	gtk_grid_attach(GTK_GRID(grid), button, 0, 0, 1, 1);
	button = gtk_button_new_with_label("Button 2");
	// g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
	gtk_grid_attach(GTK_GRID(grid), button, 1, 0, 1, 1);
	button = gtk_button_new_with_label("Quit");
	g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);
	gtk_grid_attach(GTK_GRID(grid), button, 2, 0, 1, 1);
}

static void			activate(GtkApplication* app)
{
	GtkWidget 		*window;

	window = gtk_application_window_new(app);
	create_buttons(window);
	gtk_window_set_title(GTK_WINDOW(window), "rt");
	gtk_window_set_default_size(GTK_WINDOW(window), WIN_W, WIN_H);
	gtk_widget_show_all(window);
	gtk_window_maximize(GTK_WINDOW(window));
}

void				start_gtk(t_env *e)
{
	GtkApplication	*app;
	int				status;

	(void)e;
	app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), 0, NULL);
	g_object_unref(app);
}

// static void			print_hello (void)
// {
// 	g_print ("Hello World\n");
// }
//
// void				start_gtk(t_env *e)
// {
// 	GtkBuilder		*builder;
// 	GObject			*window;
// 	GObject			*button;
//
// 	(void)e;
// 	gtk_init (NULL, NULL);
// 	builder = gtk_builder_new();
// 	gtk_builder_add_from_file(builder, "doc/rt_gtk.ui", NULL);
//
// 	/* Connect signal handlers to the constructed widgets. */
// 	window = gtk_builder_get_object (builder, "rt");
// 	g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
//
// 	button = gtk_builder_get_object (builder, "button1");
// 	g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
//
// 	button = gtk_builder_get_object (builder, "button2");
// 	g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
//
// 	button = gtk_builder_get_object (builder, "quit");
// 	g_signal_connect (button, "clicked", G_CALLBACK (gtk_main_quit), NULL);
//
// 	gtk_main ();
// }
