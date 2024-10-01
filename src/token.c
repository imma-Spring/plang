#include "common.h"

Token *create_token(char *beg, char *end) {
  Token *tok = malloc(sizeof(Token));
  assert(tok && "Coubld not allocate momory for token.");
  tok->beg = beg;
  tok->end = end;
  tok->next = NULL;
  return tok;
}

void token_free_ll(Token *tokens) {
  Token *next_token = NULL;
  while (tokens) {
    next_token = tokens->next;
    free(tokens);
    tokens = next_token;
  }
}

void token_free_array(Token **tokens, size_t length) {
  for (size_t i = 0; i < length; ++i) {
    free(tokens[i]);
  }
  free(tokens);
}

static size_t get_length(Token *tokens) {
  size_t count = 0;
  Token *token_it = tokens;
  while (token_it) {
    token_it = token_it->next;
    count++;
  }
  return count;
}

Token **token_array(Token *tokens, size_t *length) {
  *length = get_length(tokens);
  Token **token_array = calloc(*length, sizeof(Token *));
  for (size_t i = 0; i < *length; ++i) {
    token_array[i] = tokens;
    tokens = tokens->next;
  }
  return token_array;
}

void print_tokens_ll(Token *tokens) {
  Token *token_it = tokens;
  while (token_it) {
    printf("Token: %.*s\n", token_it->end - token_it->beg, token_it->beg);
    token_it = token_it->next;
  }
}

void print_tokens_array(Token **tokens, size_t length) {
  for (size_t i = 0; i < length; ++i) {
    printf("Token: %.*s\n", tokens[i]->end - tokens[i]->beg, tokens[i]->beg);
  }
}
