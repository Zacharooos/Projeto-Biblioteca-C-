#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include "struct.h"

// Seção de Funções implícitas de _livros

void pendencia_livros(int pendencia){
    if(pendencia == 0){
        puts("Livro disponível pra empréstimo!");
    } else {
        puts("Livro atualmente emprestado!");
    }    
}

int buscaBin_alunos_l(aluno *v, int id, int tam){
    int inicio = 0;
    int fim = tam;
 
    while (inicio <= fim) {
        int meio = inicio
                  + (fim - inicio) / 2;
        if (id == v[meio].id) {
            return meio;
        }
        else if (id < v[meio].id) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }
    return -1;
}

void swap_livros(livro *v, int iEsq, int iDir){
    char aux_nome[52], aux_cat[12];
    int aux_id, aux_ano, aux_aluno_id; 
    bool aux_bool;

    strcpy(aux_nome, v[iEsq].nome);
    strcpy(aux_cat, v[iEsq].categoria);
    aux_id = v[iEsq].id;
    aux_ano = v[iEsq].ano;
    aux_aluno_id = v[iEsq].aluno_id;
    aux_bool = v[iEsq].pendencia;

    strcpy(v[iEsq].nome, v[iDir].nome);
    strcpy(v[iEsq].categoria, v[iDir].categoria);
    v[iEsq].id = v[iDir].id;
    v[iEsq].ano = v[iDir].ano;
    v[iEsq].aluno_id = v[iDir].aluno_id;
    v[iEsq].pendencia = v[iDir].pendencia;

    strcpy(v[iDir].nome, aux_nome);
    strcpy(v[iDir].categoria, aux_cat);
    v[iDir].id = aux_id;
    v[iDir].ano = aux_ano;
    v[iDir].aluno_id = aux_aluno_id;
    v[iDir].pendencia = aux_bool;

    //printf("%s %s %d %d\n", v[iDir].nome, v[iDir].categoria, v[iDir].id, v[iDir].pendencia);
    //printf("%s %s %d %d\n", v[iEsq].nome, v[iEsq].categoria, v[iEsq].id, v[iEsq].pendencia);

}

int particao_livros(livro *v, int esq, int dir) {
    int pivot = v[dir].id;
    int esq_p = esq - 1;
    int dir_p = dir;
    for (;;) {
        while (v[++esq_p].id > pivot) {
        }
        while (dir_p > 0 && v[--dir_p].id < pivot) {
        }
        if (esq_p >= dir_p) {
            break;
        } else {
            swap_livros(v, esq_p, dir_p);
        }
    }
    swap_livros(v, esq_p, dir);
    return esq_p;
}

void quicksort_livros(livro * v, int esq, int dir) {
    if (esq < dir) {
        int particao = particao_livros(v, esq, dir);
        quicksort_livros(v, esq, particao - 1);
        quicksort_livros(v, particao + 1, dir);
    }
}

int buscaBin_livros(livro *v, int id, int tam){
    int inicio = 0;
    int fim = tam;
 
    while (inicio <= fim) {
        int meio = inicio
                  + (fim - inicio) / 2;
        if (id == v[meio].id) {
            return meio;
        }
        else if (id < v[meio].id) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }
    return -1;
}

// Seção de funções explícitas de _livros

//! Função para realizar a busca de um determinado livro através de seu id, recebe a referência do vetor, o id e o tam.
void buscar_livros(livro *lista_livros, aluno * lista_alunos, int id, int tam_livros, int tam_alunos){
    int i = buscaBin_livros(lista_livros, id, tam_livros);
    if (i >= 0){
        printf("Livro id [%d] encontrado!\n", lista_livros[i].id);
        printf("Nome: %s\n", lista_livros[i].nome);
        printf("Categoria: %s\n", lista_livros[i].categoria);
		printf("Publicação: %d\n", lista_livros[i].ano);
		pendencia_livros(lista_livros[i].pendencia);

        if(lista_livros[i].pendencia == true){
            int i_aluno = buscaBin_alunos_l(lista_alunos, lista_livros[i].aluno_id, tam_alunos);
            printf("Matricula do aluno: %s\n", lista_alunos[i_aluno].matricula);
        }
        

    } else {
        printf("Erro: Id não cadastrado!\n");
    }
}

//! Função para mostrar todos os livros
void mostrar_livros(livro * lista_livros, aluno * lista_alunos, int tam_livros, int tam_alunos){
    int contador = 0;
    int i = 0;
    while(contador < tam_livros){
        if(lista_livros[i].id < 0){
            i++;
        } else {
            puts("<=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=>");
            printf("Livro id [%d] encontrado!\n", lista_livros[i].id);
            printf("Nome: %s\n", lista_livros[i].nome);
            printf("Categoria: %s\n", lista_livros[i].categoria);
            printf("Publicação: %d\n", lista_livros[i].ano);
            pendencia_livros(lista_livros[i].pendencia);

            if(lista_livros[i].pendencia == true){
                int i_aluno = buscaBin_alunos_l(lista_alunos, lista_livros[i].aluno_id, tam_alunos);
                printf("Matricula do aluno: %s\n", lista_alunos[i_aluno].matricula);
            }
            i++;
            contador++;
        }
    }
    puts("");
}

//! Função utilizada para criação de livros
int criar_livros(livro **lista_livros, int tam, int *id_data){
    if(tam + 1 % 32 == 0){
        *lista_livros = realloc(*lista_livros, ((tam + 1) + 32) * sizeof(livro));
    }
    id_data[1]++;
    (*lista_livros)[tam].id = id_data[1];
    __fpurge(stdin);
    printf("Iniciado registro ID: %d\n", (*lista_livros)[tam].id);
    
    printf("Inserir nome do livro: ");
    scanf("%[^\n]s", (*lista_livros)[tam].nome);

    printf("Inserir categoria do livro: ");
    scanf("%s", (*lista_livros)[tam].categoria);

    printf("Inserir ano de publicação do livro: ");
    scanf("%d", &(*lista_livros)[tam].ano);

    __fpurge(stdin);

    (*lista_livros)[tam].pendencia = 0;

    (*lista_livros)[tam].aluno_id = -2;

    quicksort_livros((*lista_livros), 0, tam);

    puts("O cadastro foi um sucesso!");

    return tam+1;
}

//! Função para remover livros, define id do aluno como -1;
int remover_livros(livro *lista_livros, int id, int tam){
    int i = buscaBin_livros(lista_livros, id, tam);
    if (i > -1){
        if(lista_livros[i].pendencia == 0){
            printf("Deletando livro '%s'!\n", lista_livros[i].nome);
            lista_livros[i].id = -1;
            quicksort_livros(lista_livros, 0, tam);
            return tam-1;
        } else {
            puts("Erro: Não foi possível deletar o livro!\nMotivo: Pendência");
        }
    } else {
        puts("Erro: Id não cadastrado!");
    }
    return tam;
}

//! Função para cadastrar livro no alunos
void registro_livros(livro *lista_livros, aluno *lista_alunos, int id, int id_aluno, int tam_livros, int tam_alunos){
    int i_livro = buscaBin_livros(lista_livros, id, tam_livros);
    int i_aluno = buscaBin_alunos_l(lista_alunos, id_aluno, tam_alunos);
    
    //Checar se o livro existe
    if (i_livro < 0){
        puts("Erro: Livro não encontrado!");
        return;
    }

    //Checar se o aluno existe
    if (i_aluno < 0){
        puts("Erro: Aluno não encontrado!");
        return;
    }

    //Checar se o livro está emprestado
    if (lista_livros[i_livro].pendencia == 0){
        lista_livros[i_livro].pendencia = 1;
        lista_livros[i_livro].aluno_id = lista_alunos[i_aluno].id;
        lista_alunos[i_aluno].pendencia++;
        puts("Cadastro realizado com sucesso!");

    } else {
        puts("Erro: Impossível emprestar, livro não disponível!");
    }
}

//! Função para devolução do livro
void deregistro_livros(livro *lista_livros, aluno *lista_alunos, int id, int id_aluno, int tam_livros, int tam_alunos){
    int i_livro = buscaBin_livros(lista_livros, id, tam_livros);
    int i_aluno = buscaBin_alunos_l(lista_alunos, id_aluno, tam_alunos);
    
    //Checar se o livro existe
    if (i_livro < 0){
        puts("Erro: Livro não encontrado!");
        return;
    }

    //Checar se o aluno existe
    if (i_aluno < 0){
        puts("Erro: Aluno não encontrado!");
        return;
    }

    //Checar se o livro está emprestado
    if (lista_livros[i_livro].pendencia == 1){
        if (lista_livros[i_livro].aluno_id == lista_alunos[i_aluno].id){
            lista_livros[i_livro].pendencia = 0;
            lista_livros[i_livro].aluno_id = -2;
            lista_alunos[i_aluno].pendencia--;
            puts("Devolução realizada com sucesso!");
        } else {
            puts("Livro não vinculado a este aluno, falha no processo!");
        }
    } else {
        puts("Erro: Impossível devolver, livro está no estoque!");
    }
}