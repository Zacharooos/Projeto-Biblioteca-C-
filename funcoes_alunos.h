#ifndef FUNAL_H

#define FUNAL_H


// Seção de Funções implícitas de _alunos.

//! Função Swap, específica para o quickSort de alunos.
void swap_alunos(aluno *v, int iEsq, int iDir);

//! Função Partição, específica para o quickSort de alunos.
int particao_alunos(aluno *v, int left, int right);

//! Função QuickSort principal, para a ordenação decrescente de alunos.
void quicksort_alunos(aluno * v, int left, int right);

//! Função para reduzir o espaço de linhas necessário para checar a pendência.
void pendencia_alunos(int pendencia);

//! Função de busca de id principal.
int buscaBin_alunos(aluno *v, int id, int tam);

// Sessão de funções explícitas de _alunos.

//! Função para realizar a busca de um determinado aluno através de seu id, recebe a referência do vetor, o id e o tam.
void buscar_alunos(aluno *lista_alunos, int id, int tam);

//! Função para mostrar todos os alunos.
void mostrar_alunos(aluno * lista_alunos, int tam);

//! Função para criação de novos alunos, cria um aluno apenas.
int criar_alunos(aluno **lista_alunos, int tam, int *id_data);

//! Função para remover alunos, define id do aluno como -1.
int remover_alunos(aluno *lista_alunos, int id, int tam);
 
#endif