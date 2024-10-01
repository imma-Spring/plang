#pragma once
#include <stdlib.h>

typedef struct Token {
  char *beg;
  char *end;
  struct Token *next;
} Token;

Token *create_token(char *beg, char *end);
void free_tokens_ll(Token *tokens);
void free_tokens_array(Token *tokens, size_t length);
Token **token_array(Token *tokens, size_t *length);
void print_tokens_ll(Token *tokens);
void print_tokens_array(Token **tokens, size_t length);
