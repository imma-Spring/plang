#include "common.h"

void print_error(Error err) {
  assert(ERROR_TYPE_MAX == 2 && "Not all errors are handled");
  switch (err.type) {
    case ERROR_TYPE_LEX: {
      printf("Error while lexing:`%s`", err.msg);
      break;
    }
    default: return;
  }
  putchar('\n');
}
