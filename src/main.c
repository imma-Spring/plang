#include "common.h"

size_t file_length(FILE *fp) {
  assert(!fseek(fp, 0L, SEEK_END) && "Error seeking to the end of the file");
  long int length = ftell(fp);
  assert(length >= 0 && "Error telling the file position");
  assert(!fseek(fp, 0L, SEEK_SET) && "Error reseting file pointer");
  return (size_t)length;
}

Error lex(char *path_to_file, Token **tokens) {
  Error err = ERROR_OK;
  printf("%s\n", path_to_file);
  FILE *file = fopen(path_to_file, "r");
  if (!file) {
    ERROR_PREP(err, ERROR_TYPE_LEX, "File does not exist");
    return err;
  }

  size_t length = file_length(file);
  printf("%zu\n", length);
  //Token *token_start = create_token();
  fclose(file);
  return err;
}

void print_usage(char **argv) {
  printf("Usage: %s `file-to-compile`\n", argv[0]);
}

int main(int argc, char **argv) {
  if (argc == 1) {
    print_usage(argv);
    return EXIT_FAILURE;
  }

  Error err;
  Token **tokens;
  err = lex(argv[1], tokens);
  if (err.type != ERROR_TYPE_NONE) {
    print_error(err);
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
