#include "9cc.h"

Token *token;
char *user_input;

int main(int argc, char **argv) {
  if (argc != 2)
    error("%s: invalid number of arguments", argv[0]);

  // Tokenize and parse.
  user_input = argv[1];
  token = tokenize();
  program();

  // Print out the first half of assembly.
  printf(".intel_syntax noprefix\n");
  printf(".global main\n");
  printf("main:\n");

  printf("  push rbp\n");
  printf("  mov rbp, rsp\n");
  printf("  sub rsp, 208\n");
  // Traverse the AST to emit assembly.
  
  for (int i = 0; code[i]; i++) {
	  gen(code[i]);
    
	  printf("  pop rax\n");
  }
  // A result must be at the top of the stack, so pop it
  // to RAX to make it a program exit code.
  printf("  mov rsp, rbp\n");
  printf("  pop rbp\n");
  printf("  ret\n");
  return 0;
}
