#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H
#include "aluno.h"
#include "livro.h"

livro * emprestar_livro(livro * l, aluno * v, int * n_livro, int * n_aluno);
livro * devolver_livro(livro * l, int * n_livro);
void listar_emprestimos(livro * l, aluno * v, int * n_livro, int * n_aluno);

#endif