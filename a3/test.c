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
	FILE * in;
    Bitmap *bmp = (Bitmap *)malloc( sizeof( Bitmap ) );
    if (bmp == NULL){
    	return NULL;
    }
    in = fopen("dog.bmp","rb");
    // the header size
    fseek(in, BMP_HEADER_SIZE_OFFSET, SEEK_SET);
    fread(&(bmp->headerSize), 1, 4, in);
    // the header data
    // bmp->header = malloc(sizeof(char)*(bmp->headerSize));
    // fseek(in, 0, SEEK_SET);
    // fread(bmp->header, 1, bmp->headerSize, in); 

    // the BMP_WIDTH_OFFSET 
    fseek(in, BMP_WIDTH_OFFSET, SEEK_SET);
    fread(&(bmp->width), 1, 4, in);

    // the BMP_HEIGHT_OFFSET 
    fseek(in, BMP_WIDTH_OFFSET, SEEK_SET);
    fread(&(bmp->height), 1, 4, in);

	printf("now the header size is %d\n", bmp->headerSize);
	printf("now the width is %d\n", bmp->width);
	//printf("now the header data is %s\n", bmp->header);
	printf("now the height is %d\n", bmp->height);

    return bmp;
}


int main() {
	Bitmap *bmp = read_header();
	if (bmp == NULL){
		printf("return null. SHIT\n");
	}
	else{
		printf("now the header size is %d\n", bmp->headerSize);
		printf("now the width is %d\n", bmp->width);
		printf("now the height is %d\n", bmp->height);	
	}
	
	//free(bmp->header);

    free(bmp);
    return 0;
}



