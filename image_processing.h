//
//  image_processing.h
//  
//
//  Created by Sara Tarrés on 17/11/14.
//
//

#ifndef _image_processing_h
#define _image_processing_h


#endif

//We've created a .h document with all the declaration of the ppm.c functions and we've included it into the new document so that when we call the functions they exist in the joined document.

//============================================================================
//                           Function declarations
//============================================================================
// Write the image contained in <data> (of size <width> * <height>)
// into plain RGB ppm file <file>
void ppm_write_to_file(int width, int height, u_char* data, FILE* file, char * filename);

// Read the image contained in plain RGB ppm file <file>
// into <data> and set <width> and <height> accordingly
// Warning: data is malloc_ed, don't forget to free it
void ppm_read_from_file(int *width, int *height, u_char** data);

// Desaturate (transform to B&W) <image> (of size <width> * <height>)
void ppm_desaturate(u_char* image, int width, int height);

// Shrink image (of original size <width> * <height>) by factor <factor>
// <width> and <height> are updated accordingly
void ppm_shrink(u_char** image, int *width, int *height, int factor);
