#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *read_file(char *file_path) {
  FILE fp;
  fp = fopen("%s", file_path);

int main(int argc, char **argv) {
  printf("%s\n", argv[1]);
  return 0;
}
