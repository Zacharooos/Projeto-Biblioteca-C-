#ifndef FUNRE_H

#define FUNRE_H

// Seção de Funções implícitas de _recursos.

//! Função Swap, específica para o quickSort de recursos.
void swap_recursos(recursos *v, int iEsq, int iDir);

//! Função Partição, específica para o quickSort de recursos.
int particao_recursos(recursos *v, int esq, int dir);

//! Função QuickSort principal, para a ordenação decrescente de recursos.
void quicksort_recursos(recursos * v, int esq, int dir);

//! Função para reduzir o espaço de linhas necessário para checar a pendência.
void pendencia_recursos(int pendencia);

//! Função para buscar aluno por id, específica para ser usada nas funções deste header.
int buscaBin_alunos_r(aluno *v, int id, int tam);

//! Função pra buscar aluno por id.
int buscaBin_recursos(recursos *v, int id, int tam);

// Seção de Funções explícitas de _recursos.

//! Função para realizar a busca de um determinado recurso através de seu id, recebe a referência do vetor, o id e o tam.
void buscar_recursos(recursos *lista_recursos, aluno * lista_alunos, int id, int tam_recursos, int tam_alunos);

//! Função para mostrar todos os recursos.
void mostrar_recursos(recursos * lista_recursos, aluno * lista_alunos, int tam_recursos, int tam_alunos);

//! Função para a criação de recursos.
int criar_recursos(recursos **lista_recursos, int tam);

//! Função para remover recursos, define id do aluno como -1.
int remover_recursos(recursos *lista_recursos, int id, int tam);

//! Função para cadastrar recurso no alunos.
void registro_recursos(recursos *lista_recursos, aluno *lista_alunos, int id, int id_aluno, int tam_recursos, int tam_alunos);

//! Função para devolução do recurso.
void deregistro_recursos(recursos *lista_recursos, aluno *lista_alunos, int id, int id_aluno, int tam_recursos, int tam_alunos);

#endif