#include <stdio.h>
#include <stdlib.h>

void toBinary(int num, char *binary, int index) 
{
    if (index < 0)
        return;

    binary[index] = (num % 2) ? '1' : '0';
    toBinary(num / 2, binary, index - 1);
}

int main(int argc, char *argv[]) 
{
    if (argc != 4) {
        printf("Usage: %s <n> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);  
    FILE *infile = fopen(argv[2], "r");
    FILE *outfile = fopen(argv[3], "w");

    if (infile == NULL || outfile == NULL) {
        printf("Error: Unable to open input or output file.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int number;
        if (fscanf(infile, "%d", &number) != 1) break;

        char binary[17];
        binary[16] = '\0';  

        toBinary(number, binary, 15);  

        fprintf(outfile, "The binary equivalent of %d is %s\n", number, binary);
    }

    fclose(infile);
    fclose(outfile);

    printf("Program executed successfully. Check %s for output.\n", argv[3]);
    return 0;
}

