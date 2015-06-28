#include <cairo.h>
#include <cairo-xlib.h>
#include  <X11/Xlib.h>

#define M_PI 3.1415926

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

        cairo_surface_t* patternSurface = cairo_image_surface_create_from_png("../res/image/pattern.png");

        float img_width = cairo_image_surface_get_width(patternSurface);
        float img_height = cairo_image_surface_get_height(patternSurface);
        
        cairo_pattern_t* pattern = NULL;
        if(patternSurface)
        {
            pattern = cairo_pattern_create_for_surface(patternSurface);
        }

        int width = 400;

        while(true)
        {
             cairo_save(cr);

             cairo_move_to(cr, 0,0);
             cairo_line_to(cr, width,0);
             cairo_line_to(cr, width,width);
             cairo_line_to(cr,0,width);
             cairo_close_path(cr);

             cairo_set_source(cr,pattern);
                         
             
             float wScale = img_width/width ;
             float hScale = img_height/width  ;

             cairo_matrix_t matrix;

             
             
             cairo_matrix_init_scale(&matrix,wScale,hScale);                   
             cairo_matrix_translate(&matrix,-width/2,-width/2);
             

             /*
             cairo_matrix_init_translate(&matrix,-width/2,-width/2);
             cairo_matrix_scale(&matrix,wScale,hScale);
             */
             
             cairo_pattern_set_matrix(pattern,&matrix);
             
             cairo_save( cr );
             cairo_clip( cr );
             cairo_paint_with_alpha( cr, 0.0);
             cairo_restore( cr );

             cairo_restore(cr);
        }

        cairo_pattern_destroy(pattern); 
        cairo_destroy (cr);

        cairo_surface_destroy (surface);

        return 0;
}



