#ifndef LOSA_H

#define LOSA_H

//! Todas as funções de salvamento realizão o mesmo procedimento, utilizando a lista passada pelo main e o tamanho da mesma.
//! Função para armazenar DATA dos id's, utilizada para evitar que os id's conflitem com o tamanho da lista!
//! Diferente de outras funções, a salvar_id_data não precisa de tamanho, pois o tamanho deste vetor é fixo[2].
void salvar_id_data(int * id_data);

//! Função para armazenar DATA de alunos!
void salvar_alunos(aluno *lista_alunos, int tam);

//! Função para armazenar DATA de livros!
void salvar_livros(livro *lista_livros, int tam);

//! Função para armazenar DATA de recursos!
void salvar_recursos(recursos *lista_recursos, int tam);

#endif