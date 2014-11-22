




#include <sys/types.h> //to know the u_char type in a mac
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "image_processing.h"




//============================================================================
//                                  Structures
//============================================================================
struct image
{
    u_char* image;
    int width;
    int height;
};


//============================================================================
//                                  Main
//============================================================================
int main(int argc, char* argv[])
{
  //--------------------------------------------------------------------------
  // Read file "gargouille.ppm" into image (width and height)
  //--------------------------------------------------------------------------
  
  /* Old version to define an image:
  u_char* image = NULL;
  int width;
  int height;
  */

  // New version with the struct image:
  struct image newimage;
  newimage.image=NULL;
    
  
  ppm_read_from_file(&newimage.width, &newimage.height, &newimage.image);
  


  //--------------------------------------------------------------------------
  // Create a desaturated (B&W) copy of the image we've just read and
  // write it into "gargouille_BW.ppm"
  //--------------------------------------------------------------------------
  // Copy image into image_bw
  int width_bw  = newimage.width;
  int height_bw = newimage.height;
  u_char* image_bw = (u_char*)malloc(3*newimage.width*newimage.height*sizeof(*image_bw));
  memcpy(image_bw, newimage.image, 3 * newimage.width * newimage.height * sizeof(*image_bw));

  // Desaturate image_bw
  ppm_desaturate(image_bw, newimage.width, newimage.height);

  // Write the desaturated image into "gargouille_BW.ppm"
  FILE* ppm_output;
  char * fileBW = "gargouille_BW.ppm";
  ppm_write_to_file(newimage.width, newimage.height, image_bw, ppm_output, fileBW);
    
  free(image_bw);
  

  //--------------------------------------------------------------------------
  // Create a resized copy of the image and
  // write it into "gargouille_small.ppm"
  //--------------------------------------------------------------------------
  // Copy image into image_small
  int width_small  = newimage.width;
  int height_small = newimage.height;
  u_char* image_small = (u_char*)malloc(3*newimage.width*newimage.height*sizeof(*image_small));
  memcpy(image_small, newimage.image, 3 * width_small * height_small * sizeof(*image_small));

  // Shrink image_small size 2-fold
  ppm_shrink(&image_small, &width_small, &height_small, 2);

  // Write the desaturated image into "gargouille_small.ppm"
  
  char * filesmall = "gargouille_small.ppm";
  ppm_write_to_file(width_small, height_small, image_small, ppm_output, filesmall);
  

  // Free the not yet freed images
  free(newimage.image);
  free(image_small);
  return 0;
}




































