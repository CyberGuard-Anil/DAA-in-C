#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) 
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main(int argc, char *argv[]) 
{
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *infile = fopen(argv[1], "r");
    FILE *outfile = fopen(argv[2], "w");

    if (infile == NULL || outfile == NULL) 
    {
        printf("Error: Unable to open input or output file.\n");
        return 1;
    }

    int a, b;
    while (fscanf(infile, "%d %d", &a, &b) == 2) 
    {
        int result = gcd(a, b);
        fprintf(outfile, "The GCD of %d and %d is %d\n", a, b, result);
    }

    fclose(infile);
    fclose(outfile);

    printf("Program executed successfully. Check %s for output.\n", argv[2]);
    return 0;
}

