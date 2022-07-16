#ifndef LIVRO_H
#define LIVRO_H

typedef struct {
  int num_livro;
  char titulo[100];
  char autor[50];
  int matricula_aluno;
  time_t data_hora_emprestimo;
  time_t data_hora_devolucao;
}livro;

void livros_para_arquivo(livro *l, int *n);
livro* le_livros_arquivo(livro *v, int *n, int *total_livros);
livro le_livro();
livro * insere_livro(livro * l, int * n, livro novo);
livro * remove_livro(livro * l, int * n);
void listar_livro(livro * l, int * n);

#endif 