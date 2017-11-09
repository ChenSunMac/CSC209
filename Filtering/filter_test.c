#define BMP_FILE_SIZE_OFFSET 2
#define BMP_HEADER_SIZE_OFFSET 10
#define BMP_WIDTH_OFFSET 18
#define BMP_HEIGHT_OFFSET 22

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} Pixel;

typedef struct {
    int headerSize;          // The size of the header.
    unsigned char *header;   // The contents of the image header.
    int width;               // The width of the image, in pixels.
    int height;              // The height of the image, in pixels.
} Bitmap;


Bitmap *read_header() {
	FILE *img;
	img = fopen("dog.bmp", "rb");
	if (img == NULL){
		printf("Error: fopen failed\n");
		return NULL; 
	}
	Bitmap *bmp = malloc(sizeof(Bitmap));

    // BMP header size offset
    fseek(img, BMP_HEADER_SIZE_OFFSET, SEEK_SET);
    fread(&(bmp->headerSize), 1, 4, img);

    // read header 
	bmp->header = malloc(sizeof(char)*bmp->headerSize);

    fread(bmp->header, sizeof(char), bmp->headerSize, img);

	// Capture dimensions
    fseek(img, BMP_WIDTH_OFFSET, SEEK_SET);
    fread(&(bmp->width), 1, 4, img);
    fseek(img, BMP_HEIGHT_OFFSET, SEEK_SET);
    fread(&(bmp->height), 1, 4, img);


    return bmp;
}


void write_header(const Bitmap *bmp) {
    //fwrite(bmp->header, bmp->headerSize, 1, stdout);
	printf("The BMP has header %s \n", (bmp->header));
	printf("The BMP has width %d \n", (bmp->width));
	printf("The BMP has height %d \n", (bmp->height));
}

/*
 * Free the given Bitmap struct.
 */
void free_bitmap(Bitmap *bmp) {
    free(bmp->header);
    free(bmp);
}


/*
 * The "main" function.
 *
 * Run a given filter function, and apply a scale factor if necessary.
 * You don't need to modify this function to make it work with any of
 * the filters for this assignment.
 */
void run_filter(void (*filter)(Bitmap *), int scale_factor) {
    Bitmap *bmp = read_header();

    // if (scale_factor > 1) {
    //     scale(bmp, scale_factor);
    // }

    write_header(bmp);

    // Note: here is where we call the filter function.
    filter(bmp);

    free_bitmap(bmp);
}

/*
 * Main filter loop.
 * This function is responsible for doing the following:
 *   1. Read in pixels one at a time (because copy is a pixel-by-pixel transformation).
 *   2. Immediately write out each pixel.
 *
 * Note that this function should allocate space only for a single Pixel;
 * do *not* store more than one Pixel at a time, it isn't necessary here!
 */
void copy_filter(Bitmap *bmp) {
    FILE * copy;
    copy = fopen("copy_dog.bmp","wb");

    // write header
    fwrite (bmp , sizeof(char), bmp->headerSize, copy);

    // write pixel by pixel
    
}


int main() {

    run_filter(copy_filter, 1);
    return 0;

}