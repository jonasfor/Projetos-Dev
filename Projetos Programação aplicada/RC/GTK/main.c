#include <gtk/gtk.h>

static void destroy( GtkWidget *widget,
                     gpointer   data );

int main( int   argc,
          char *argv[] )
{
    GtkWidget *window;
    
    gtk_init (&argc, &argv);
    
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    g_signal_connect (G_OBJECT (window), "destroy",
		      G_CALLBACK (destroy), NULL);

/*  TODO: type some code */

    gtk_widget_show  (window);
    
    gtk_main ();
    
    return 0;
}

static void destroy( GtkWidget *widget,
                     gpointer   data )
{
    gtk_main_quit ();
}
