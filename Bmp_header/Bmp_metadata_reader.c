#include<stdio.h>
#pragma warning(disable : 4996)
#pragma pack(1)

struct BMP_file_header
{
	unsigned char identification_two_b;
	unsigned char identification_two_c;
	unsigned int size_of_image;
	char unsigned reserved_one_two_b[4];
	unsigned int start_of_bitmap;
};

/*				[TO ADD IN BITMAPCOREHEADER]
* ColorTable	4 * NumColors bytes	0036h	present only if Info.BitsPerPixel less than 8
colors should be ordered by importance
		Red	1 byte	 	Red intensity
Green	1 byte	 	Green intensity
Blue	1 byte	 	Blue intensity
reserved	1 byte	 	unused (=0)
repeated NumColors times
Pixel Data	InfoHeader.ImageSize bytes	 	The image data
* 
*/

struct BITMAPCOREHEADER 
{
	char remove_pad_1;
	unsigned int header_size;
	unsigned int width_in_pixels;
	//short remove_pad_2;
	unsigned int height_in_pixals;
	//short remove_pad_3;
	unsigned short colour_plains;	//Supposed to be 1
	unsigned short bits_per_pixel;
	unsigned int compression;
	unsigned int image_size;
	unsigned int x_pixals_per_m;	//horizontal resolution: Pixels/meter
	unsigned int y_pixals_per_m;	//vertical resolution: Pixels/meter
	unsigned int colours_used;		//	Number of actually used colors. For a 8-bit / pixel bitmap this will be 100h or 256
	unsigned int important_colours;  //Number of important colors 0 = all
		
};

struct BMP_file_header header1;
struct BITMAPCOREHEADER core_header1;

int read_and_display_bmp_file_header(FILE* fp);
int read_and_display_bmp_core_header(FILE* fp);


int main()
{
	FILE* fp;
	fp = fopen("C:\\Users\\pc\\Desktop\\Test.bmp", "rb");
	if (fp == NULL)
	{
		printf("\nfile was not open\n");
		return 0;
	}

	read_and_display_bmp_file_header(fp);
	read_and_display_bmp_core_header(fp);

	fclose(fp);
	return 0;
}
	
int read_and_display_bmp_file_header(FILE* fp)
{
	fgets(&header1, sizeof(header1), fp);

	if (fgets == NULL)
	{
		printf("\n\"fgets\" failed while reading file_header\n");
	}


	printf("\n\t----==== { BMP file header } ====----\n");
	printf("Identification [ %c%c ]\n", header1.identification_two_b, header1.identification_two_c);
	printf("\nSize of Image %u \n", header1.size_of_image);
	printf("\nReserved %s\n", &header1.reserved_one_two_b);
	printf("\nBit map starting address : %d\n", header1.start_of_bitmap);

	return 0;
}

int read_and_display_bmp_core_header(FILE* fp)	//bmp file header has to be read first (else skip the first 12 bytes)
{
	printf("\n\t----==== { BMP core header } ====----\n");
	//fclose(fp);
	/*fp = fopen("C:\\Users\\pc\\Desktop\\Test.bmp", "rb");
	if (fp == NULL)
	{
		printf("\nFile was not open\n");
		return 0;
	}*/
	fgets(&core_header1, sizeof(core_header1), fp);

	if (fgets == NULL)
	{
		printf("\n\"fgets\" failed while reading core_header\n");
	}




	printf("Core header size : ( %d )\n", core_header1.header_size);
	printf("\nWidth in pixels : ( %d ) ", core_header1.width_in_pixels);
	printf("\nHeight in pixels : ( %d ) \n", core_header1.height_in_pixals);
	printf("\nColour plains : ( %d ) [SUPPOSED TO BE 1]\n", core_header1.colour_plains);
	printf("\nBits per pixel : ( %d )\n", core_header1.bits_per_pixel);
	printf("\nCompression : %d\n", core_header1.compression);
	printf("\nImage size : %d\n", core_header1.image_size);
	printf("\nHorizontal resolution: Pixels/meter : %d\n", core_header1.x_pixals_per_m);
	printf("\nVertical resolution: Pixels/meter : %d\n", core_header1.y_pixals_per_m);
	printf("\nColours used : %d\n", core_header1.colours_used);
	printf("\nImportant colours : %d\n", core_header1.important_colours);


	
	return 0;


}