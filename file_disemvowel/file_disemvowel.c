#include <stdio.h>
#include <stdbool.h>

#define BUF_SIZE 1024

bool is_vowel (char x) { 
 	if (x=='a' || x=='e' || x=='i' || x=='o' || x=='u' || x=='A' || x=='E' || x=='I' || x=='O' || x=='U') {
		return true;
	}
  else {
  return false;
  }
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf){
	int letter = 0;
	for (int i = 0; i < num_chars; i++){
 		if (is_vowel (int_buf[i])) {
			out_buf[letter] = in_buf[i];
			letter++;	
		}
 	}
	return letter;	
}

void disemvowel(FILE* inputFile, FILE* outputFile) { 
    /*
     * Copy all the non-vowels from inputFile to outputFile.
     * Create input and output buffers, and use fread() to repeatedly read
     * in a buffer of data, copy the non-vowels to the output buffer, and
     * use fwrite to write that out. 
     */
}

int main(int argc, char *argv[]) { 
    FILE *inputFile; 
    FILE *outputFile;

    // Code that processes the command line arguments 
    // and sets up inputFile and outputFile.

    disemvowel(inputFile, outputFile);

    return 0; 
}
