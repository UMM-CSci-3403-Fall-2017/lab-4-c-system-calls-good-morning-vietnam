#include <stdio.h>
#include <ftw.h>


static int num_dirs, num_regular;

static int callback(const char *fpath, const struct stat *sb, int typeflag) {
    // if the typeflag equals FTW_F then increments the number of regualr files by 1
    // if the typrflag equals FTW_D then increments the number of directories by 1
    if (typeflag == FTW_F){
      num_regular++;
    }
    else if (typeflag == FTW_D){
      num_dirs++;

    }
    //function need to return an integer
    return 0;
}

#define MAX_FTW_DEPTH 16

int main(int argc, char** argv) {
    // Check arguments and set things up
    if (argc != 2) {
      printf ("Usage: %s <path>\n", argv[0]);
      printf ("where <path> is the file or root of the tree you want to summarize.\n");
      return 1;
    }

    ftw(argv[1], callback, MAX_FTW_DEPTH);

    // Print out the results
    printf("There were %d directories.\n", num_dirs);
    printf("There were %d regular files.\n", num_regular);
}
