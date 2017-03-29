#include "rt.h"
#include <GL/gl.h>

// add this in makefile libs for compilation
// LIBGL	=	-lGL -lGLU -lglut

static gboolean		render(GtkGLArea *area, GdkGLContext *context)
{
	// inside this function it's safe to use GL; the given
	// #GdkGLContext has been made current to the drawable
	// surface used by the #GtkGLArea and the viewport has
	// already been set to be the size of the allocation

	// we can start by clearing the buffer
	(void)area;
	(void)context;
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	// draw your object
	// draw_an_object();

	// we completed our drawing; the draw commands will be
	// flushed at the end of the signal emission chain, and
	// the buffers will be drawn on the window
	return (TRUE);
}

static void			create_gl_area(GtkWidget *window, GtkWidget *grid)
{
	GtkWidget *gl_area;

	(void)window;
	gl_area = gtk_gl_area_new();
	g_signal_connect(gl_area, "render", G_CALLBACK(render), NULL);
	gtk_grid_attach(GTK_GRID(grid), gl_area, 0, 3, 2, 1);
}

static void			create_buttons(GtkWidget *window, GtkWidget *grid)
{
	GtkWidget		*button;

	(void)window;
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

	// fill the grid with button and gl_area
	create_buttons(window, grid);
	create_gl_area(window, grid);

	gtk_widget_show_all(window);
	gtk_main();
}
