#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

bool is_vowel(char c) { 
   return strchr("aeiouAEIOU", (int) c) != NULL; 
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
    int out_buf_index = 0;
    int i;
    for (i = 0; i < num_chars; i++) {
        if (!is_vowel(in_buf[i])) {
            out_buf[out_buf_index] = in_buf[i];
            out_buf_index++;
        }
    }


    return out_buf_index;
}

void disemvowel(FILE* inputFile, FILE* outputFile) { 
    char *inBuffer = (char*) calloc(BUF_SIZE + 1, sizeof(char));
    char *outBuffer = (char*) calloc(BUF_SIZE, sizeof(char));
    int num_read = 0;
    int num_non_vowels;

    do {
        num_read = fread(inBuffer, sizeof(char), BUF_SIZE, inputFile);
        num_non_vowels = copy_non_vowels(num_read, inBuffer, outBuffer);
        fwrite(outBuffer, sizeof(char), num_non_vowels, outputFile);
    } while (num_read != 0);


    free(inBuffer);
    free(outBuffer);
}

int main(int argc, char *argv[]) { 
    FILE *inputFile; 
    FILE *outputFile;

    inputFile = stdin;
    outputFile = stdout;
    
    if (argc >= 2) {
        inputFile = fopen(argv[1], "r");
    }

    if (argc >= 3) {
        outputFile = fopen(argv[2], "w");
    }

    disemvowel(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);
    
    return 0; 
}
