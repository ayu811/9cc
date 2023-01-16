#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// Tokenizer
//
typedef enum {
  TK_RESERVED, // Keywords or punctuators
  TK_IDENT,    // identifier 
  TK_NUM,      // Integer literals
  TK_EOF,      // End-of-file markers
} TokenKind;

// Token type
typedef struct Token Token;
struct Token {
  TokenKind kind; // Token kind
  Token *next;    // Next token
  int val;        // If kind is TK_NUM, its value
  char *str;      // Token string
  int len;        // Token length
};

// Input program
extern char *user_input;
// Current token
extern Token *token;

void error(char *fmt, ...);
void error_at(char *loc, char *fmt, ...); 
bool consume(char *op);
void expect(char *op) ;
int expect_number();
bool at_eof();
bool startswith(char *p, char *q);
Token *new_token();
Token *tokenize();


//
// Parser
//
typedef enum {
  ND_ADD, // +
  ND_SUB, // -
  ND_MUL, // *
  ND_DIV, // /
  ND_EQ,  // ==
  ND_NE,  // !=
  ND_LT,  // < 
  ND_LE,  // <=
  ND_ASSGIN, // =
  ND_LVAR,// local var
  ND_NUM, // Integer
} NodeKind;

// AST node type
typedef struct Node Node;
struct Node {
  NodeKind kind; // Node kind
  Node *lhs;     // Left-hand side
  Node *rhs;     // Right-hand side
  int val;       // Used if kind == ND_NUM
  int offset;    // Used if kind == ND_LVAR
};

extern Node *code[];

Node *new_node(NodeKind kind);
Node *new_num(int val);
Node *new_binary(NodeKind kind, Node *lhs, Node *rhs);
Node *assgin();
Node *stmt();
Node *expr();
Node *equality();
Node *relational();
Node *add();
Node *mul();
Node *unary();
Node *primary();
void program();


//
// Code Gen
//
void gen(Node *node);
void gen_lval(Node *node);
