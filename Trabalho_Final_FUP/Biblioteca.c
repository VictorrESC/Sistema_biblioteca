#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "aluno.h"
#include "livro.h"
#include "emprestimo.h"
#include "menu.h"

int main() {
  
  int n_alunos = 0, n_livros = 0, total_alunos = 1, total_livros = 1;
  aluno * v = 0;
  livro * l = 0;
  v = le_alunos_arquivo(v, &n_alunos, &total_alunos);
  l = le_livros_arquivo(l, &n_livros, &total_livros);
  do {
    int opcao = 0;
    int retorno;
    primeiro_menu();
    printf("\n Opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1: {
      menu_aluno();
      int op_aluno = 0;
      scanf("%d", &op_aluno);

      switch (op_aluno) {
      case 1: {
        aluno a = le_aluno(&total_alunos);
        v = insere_aluno(v, &n_alunos, a);
        alunos_para_arquivo(v, &n_alunos);
        break;
      }
      case 2: {
        v = remove_aluno(v, &n_alunos);
        alunos_para_arquivo(v, &n_alunos);
        break;
      }
      case 3: {
        listar_aluno(v, &n_alunos);
        break;
      }
      }
      break;
    }
    case 2: {
      menu_livro();
      int op_livro = 0;
      scanf("%d", &op_livro);

      switch (op_livro) {
      case 1: {
        livro b = le_livro(&total_livros);
        l = insere_livro(l, &n_livros, b);
        livros_para_arquivo(l, &n_livros);
        break;
      }
      case 2: {
        l = remove_livro(l, &n_livros);
        livros_para_arquivo(l, &n_livros);
        break;
      }
      case 3: {
        listar_livro(l, &n_livros);
        break;
      }
      }
      break;
    }
    case 3: {
      menu_emprestimo();
      int op_emprestimo = 0;
      scanf("%d", &op_emprestimo);

      switch (op_emprestimo) {
      case 1: {
        emprestar_livro(l, v, &n_livros, & n_alunos);
        livros_para_arquivo(l, &n_livros);
        break;
      }
      case 2: {
        devolver_livro(l, &n_livros);
        livros_para_arquivo(l, &n_livros);
        break;
      }
      case 3: {
        listar_emprestimos(l, v, &n_livros, & n_alunos);
        break;
      }
      }
      break;
    }

    default:
      system("cls");
      printf(" Opcao Invalida, Tente novamente!\n");
      break;
    }
    printf("\n Para retornar ao menu digite: 1 \n");
    scanf("%d", & retorno);
    if (retorno != 1) {
      printf("\n");
      printf("*==================================*\n");
      printf("|           DESENVOLVIDO           |\n");
      printf("|               POR:               |\n");
      printf("*==================================*\n");
      printf("|        - MATHEUS CONRADO         |\n");
      printf("|        - VICTOR EMANUEL          |\n");
      printf("|        - JEFERSON AIRES          |\n");
      printf("*==================================*\n");
      printf("|    CIENCIA DA COMPUTACAO 2022.1  |\n");
      printf("*==================================*\n");
      printf("|     UFC - CAMPUS DE QUIXADA      |\n");
      printf("*==================================*\n");
      printf("|        PROFESSOR ORIENTADOR:     |\n");
      printf("|        -  CRISTON SOUZA          |\n");
      printf("*==================================*\n");
      break;
    } else {
      system("cls");
      continue;
    }
  } while (1);
}