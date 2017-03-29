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
