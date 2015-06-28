#include <cairo.h>
#include<cstdio>

#define M_PI 3.1415926

#define WIDTH 400
#define HEIGHT 400


int main (int argc, char *argv[])
{
    cairo_surface_t *surface =
        cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 400, 400);
    cairo_t *cr =
        cairo_create (surface);
    
    cairo_surface_t* patternSurface = cairo_image_surface_create_from_png("../res/image/pattern.png");

    float img_width = cairo_image_surface_get_width(patternSurface);
    float img_height = cairo_image_surface_get_height(patternSurface);
    
    cairo_pattern_t* pattern = NULL;
    if(patternSurface)
    {
        pattern = cairo_pattern_create_for_surface(patternSurface);
    }

    int width = 400;

    cairo_move_to(cr, 0,0);
    cairo_line_to(cr, width,0);
    cairo_line_to(cr, width,width);
    cairo_line_to(cr,0,width);
    cairo_close_path(cr);
   
    cairo_set_source(cr,pattern);
                
    
    float wScale = img_width/width ;
    float hScale = img_height/width  ;

   
    cairo_matrix_t matrix;
   
    
    
    //cairo_matrix_init_translate(&matrix,-width/2,-width/2);
    cairo_matrix_init_scale(&matrix,wScale,hScale);

    
    
    cairo_pattern_set_matrix(pattern,&matrix);
    

    cairo_fill(cr);
    
    cairo_destroy (cr);
    cairo_surface_write_to_png (surface, "hello.png");
    cairo_surface_destroy (surface);

        return 0;
}


