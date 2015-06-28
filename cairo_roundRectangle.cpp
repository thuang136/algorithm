#include <cairo.h>
#include <cairo-xlib.h>
#include  <X11/Xlib.h>

#define M_PI 3.1415926

#define WIDTH 400
#define HEIGHT 400

int main (int argc, char *argv[])
{

    Display* dsp;
    Drawable da;

    int screen;
        cairo_surface_t *surface;

    if( (dsp = XOpenDisplay(NULL)) == NULL)
    {
            return 0;
    }

    screen = DefaultScreen(dsp);
    da = XCreateSimpleWindow(dsp,DefaultRootWindow(dsp),0,0,400,400,0,0,0);

    XMapWindow(dsp,da);

    surface = cairo_xlib_surface_create(dsp,da,DefaultVisual(dsp,screen),400,400);

    cairo_xlib_surface_set_size(surface,400,400);
    

    cairo_t *cr =
    cairo_create (surface);



    int running = 1;

    while(true)
    {
       double x = 25.6,
              y = 25.6,
              width = 100.8,
              height = 304.8,
              radius = width / 2;

       double degrees = M_PI / 180.0;

       cairo_set_line_width(cr,10.0);

       cairo_set_source_rgba(cr,1,0.2,0.2,0.6);

       cairo_arc_negative(cr, x + radius, y ,radius, 180 * degrees, 90 * degrees);

       cairo_arc_negative(cr, x + width - radius, y, radius ,90 * degrees, 0 * degrees);

       cairo_line_to(cr, x + width , y + height - radius);

       cairo_arc(cr, x + width - radius, y + height - radius, radius, 0 * degrees, 90 * degrees);

       cairo_arc(cr, x + radius, y + height - radius, radius, 90 * degrees, 180 * degrees);

       cairo_close_path(cr);

       cairo_stroke(cr);
     
    }
    
    
    cairo_destroy (cr);
    
    cairo_surface_destroy (surface);

        return 0;
}



