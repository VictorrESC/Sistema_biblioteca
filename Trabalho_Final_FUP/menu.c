#include <stdio.h>
#include <stdlib.h>
void primeiro_menu() {
  printf("\n <==============================>\n");
  printf("\n Escolha uma opcao: \n");
  printf("\n (1) Para a secao de alunos.\n");
  printf("\n (2) Para a secao de livros\n");
  printf("\n (3) Para o menu de emprestimos\n");
  printf("\n <==============================>\n");

}

void menu_aluno() {
  system("cls");
  printf("\n <==============================>\n");
  printf("\n Escolha uma opcao: \n");
  printf("\n (1) Para cadastrar aluno.\n");
  printf("\n (2) Para remover aluno\n");
  printf("\n (3) Para listar os alunos\n");
  printf("\n Opcao: ");
  printf("\n <==============================>\n");
}

void menu_livro() {
  system("cls");
  printf("\n <==============================>\n");
  printf("\n Escolha uma opcao: \n");
  printf("\n (1) Para cadastrar um livro.\n");
  printf("\n (2) Para remover um livro\n");
  printf("\n (3) Para listar os livros\n");
  printf("\n Opcao: ");
  printf("\n <==============================>\n");
}

void menu_emprestimo() {
  system("cls");
  printf("\n <==============================>\n");
  printf("\n Escolha uma opcao: \n");
  printf("\n (1) Para emprestar um livro.\n");
  printf("\n (2) Para devolver um livro\n");
  printf("\n (3) Para listar os emprestimos\n");
  printf("\n Opcao: ");
  printf("\n <==============================>\n");
}