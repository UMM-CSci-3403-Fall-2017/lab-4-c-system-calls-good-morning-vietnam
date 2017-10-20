#include <stdio.h>
#include <ftw.h>

#define MAX_FTW_DEPTH 16

static int num_dirs = 0;
static int  num_files = 0;

static int callback(const char *fpath, const struct stat *sb, int typeflag) {
    if (typeflag == FTW_F) {
        num_files++;
        return 0;
    } else if (typeflag == FTW_D) {
        num_dirs++;
        return 0;
    }
    return 1;
}

int main(int argc, char** argv) {
    // Check arguments and set things up

    if (argc != 2) {
        printf ("Usage: %s <path>\n", argv[0]);
        printf ("       where <path> is the file or root of the tree you want to summarize.\n");
        return 1;
    }
    ftw(argv[1], callback, MAX_FTW_DEPTH);

    // Print out the results 

    printf("There were %d directories.\n", num_dirs);
    printf("There were %d regular files.\n", num_files);
    
    return 0;
}
