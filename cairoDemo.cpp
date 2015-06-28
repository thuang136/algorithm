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
         float rMin = 0.3f;
         float rMax = 0.4f;

         float radius = (rMin + rMax)/2;

         cairo_set_source_rgba(cr,1.0,0.0,0.0,1.0);

         cairo_set_line_width(cr,rMax-rMin);
         
         cairo_save(cr);

         cairo_translate(cr, WIDTH/2,HEIGHT/2);

         cairo_scale(cr,200,200);
         
         cairo_arc(cr,0,0,radius, 0, 2 * M_PI);
         
         cairo_stroke(cr);

         cairo_restore(cr);
         
        }


        cairo_destroy (cr);

        cairo_surface_destroy (surface);

        return 0;
}


