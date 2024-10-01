#pragma once

typedef struct {
  enum ErrorTpe {
    ERROR_TYPE_NONE = 0,
    ERROR_TYPE_LEX,
    ERROR_TYPE_MAX,
  } type;

  char *msg;
} Error;

#define ERROR_OK {ERROR_TYPE_NONE, ""}
#define ERROR_PREP(err, error_type, message) (err).type = (error_type); (err).msg = (message)

void print_error(Error err);
