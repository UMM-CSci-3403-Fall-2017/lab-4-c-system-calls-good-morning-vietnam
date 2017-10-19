#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

static int num_dirs, num_regular;

bool is_dir(const char* path) {
   struct stat buff;
   return stat(path, &buff) != -1 && S_ISDIR(buff.st_mode);
}

/* 
 * I needed this because the multiple recursion means there's no way to
 * order them so that the definitions all precede the cause.
 */
void process_path(const char*);

void process_directory(const char* path) {
   DIR * dir = opendir(path);
   
   chdir(path);
   struct dirent * dp;
   while ((dp = readdir(dir)) != NULL) {
       if(strcmp(dp->d_name, ".") != 0 &&
            strcmp(dp->d_name, "..") != 0)
       {
            //printf("%s\n", dp -> d_name);
            process_path(dp -> d_name);
       }
   }
   
   num_dirs++;
   if(strcmp(".", path) != 0)
        chdir("..");
   closedir(dir);
}

void process_file(const char* path) {
   num_regular++;
}

void process_path(const char* path) {
  if (is_dir(path)) {
    process_directory(path);
  } else {
    process_file(path);
  }
}

int main (int argc, char *argv[]) {
  // Ensure an argument was provided.
  if (argc != 2) {
    printf ("Usage: %s <path>\n", argv[0]);
    printf ("where <path> is the file or root of the tree you want to summarize.\n");
    return 1;
  }

  num_dirs = 0;
  num_regular = 0;

  process_path(argv[1]);

  printf("There were %d directories.\n", num_dirs);
  printf("There were %d regular files.\n", num_regular);
  
  return 0;
}
