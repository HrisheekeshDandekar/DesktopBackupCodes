#include <stdio.h>
#include <string.h>

long int do_i_fit(FILE* fp);
void decrypt_n_provide(unsigned char* da_key, unsigned char* da_flag);

int main(int argc, char** argv)
{
    unsigned char da_key[30];
    //unsigned char da_flag[20] = "_s1z3_matt3r5_lm40_";
    unsigned char da_flag[20] = {
        110 ,68 ,0 ,75 ,7 ,105 ,92 ,86 ,69 ,69 ,7 ,68 ,4 ,104 ,93 ,92 ,0 ,6 ,110
    };
    FILE* fp = fopen(argv[0], "r");
    if (!fp)
    {
        fclose(fp);
        return 0;
    }

    long int thock = do_i_fit(fp);
    sprintf(da_key, "%ld",thock );


    fclose(fp);
    return 0;
    decrypt_n_provide(da_key, da_flag);
    printf("\n\t[HINT]:\n\t\tIf this made no sense, heres a hint,\n"
           "\t\tI have a weard faccination about my size and the total "
           "words in eng currently used ;)\n\n");
}

long int do_i_fit(FILE* fp)
{
    fseek(fp, 0L, SEEK_END);
    long int thicc_check = ftell(fp);
    return thicc_check;
}

void decrypt_n_provide(unsigned char* da_key, unsigned char* da_flag)
{
    int key_size = strlen(da_key);
    int flag_size = 19;
    int key_counter = 0;

    for (int i = 0; i < flag_size; i < i++)
    {
        da_flag[i] = da_flag[i] ^ da_key[i % key_size];
    }

    printf("\n");

    for (int i = 0; i < flag_size; i < i++)
    {
      printf("%c", da_flag[i]);
    }

    printf("\n");
}

