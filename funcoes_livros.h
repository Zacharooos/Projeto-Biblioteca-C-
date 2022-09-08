#ifndef FUNLI_H

#define FUNLI_H


// Seção de Funções implícitas de _livros.

//! Função para reduzir o espaço de linhas necessário para checar a pendência.
void pendencia_livros(int pendencia);

//! Função para buscar aluno por id, específica para ser usada nas funções deste header.
int buscaBin_alunos_l(aluno *v, int id, int tam);

//! Função Swap, específica para o quickSort de livros.
void swap_livros(livro *v, int iEsq, int iDir);

//! Função Partição, específica para o quickSort de livros.
int particao_livros(livro *v, int esq, int dir);

//! Função QuickSort principal, para a ordenação decrescente de livros.
void quicksort_livros(livro * v, int esq, int dir);

//! Função para buscar livro pelo id.
int buscaBin_livros(livro *v, int id, int tam);

// Seção de funções explícitas de _livros

//! Função para realizar a busca de um determinado livro através de seu id, recebe a referência do vetor, o id e o tam.
void buscar_livros(livro *lista_livros, aluno * lista_alunos, int id, int tam_livros, int tam_alunos);

//! Função para mostrar todos os livros.
void mostrar_livros(livro * lista_livros, aluno * lista_alunos, int tam_livros, int tam_alunos);

//! Função utilizada para criação de livros.
int criar_livros(livro **lista_livros, int tam, int *id_data);

//! Função para remover livros, define id do aluno como -1.
int remover_livros(livro *lista_livros, int id, int tam);

//! Função para cadastrar livro no alunos.
void registro_livros(livro *lista_livros, aluno *lista_alunos, int id, int id_aluno, int tam_livros, int tam_alunos);

//! Função para devolução do livro.
void deregistro_livros(livro *lista_livros, aluno *lista_alunos, int id, int id_aluno, int tam_livros, int tam_alunos);

#endif