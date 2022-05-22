//Code to extract all bytes of an image file into a text file to be added to an arary
#include <stdio.h>

FILE* output_file_create();
void generate_img_array(image, output_file);
void close_buffers(FILE* image, FILE* output_file);


int main(int argc, char** argv)
{
    FILE* image = fopen(argv[1], "r");

    if (!image)
    {
        printf("[File Not Opened]\n");
        return 1;
    }

    FILE* output_file = output_file_create();
    
    generate_img_array(image, output_file);

    close_buffers(image, output_file);

    return 0;
}

FILE* output_file_create()
{
    FILE* fp = fopen("output_file.txt", "w");
    if (!fp)
    {
        printf("[Output File was not created]\n");
    }

    return fp;
}

/*
    --- [ENCRYPTION] ---

    byte shifted by char input times
*/

void generate_img_array(image, output_file)
{
    unsigned char read_write_byte;
    int newline_till = 40;
    while(!feof(image))
    {
        int read_size = fread(&read_write_byte, sizeof(unsigned char), 1, image);
        fprintf(output_file, "%d ,", read_write_byte);
        newline_till--;
        if (!newline_till)
        {
            newline_till = 40;      
            fprintf(output_file, "\n");
        }

        if (read_size != 1)
        {
            printf("Problem Reading image byte. Current pos: %d", ftell(image));
            break;
        }
    }
}

void close_buffers(FILE* image, FILE* output_file)
{
    fclose(image);
    fclose(output_file);
}