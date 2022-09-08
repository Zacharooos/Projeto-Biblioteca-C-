#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include "struct.h"

// Seção de Funções implícitas de _alunos

void swap_alunos(aluno *v, int iEsq, int iDir){
    char aux_nome[52], aux_mat[12];
    int aux_id, aux_pen;

    strcpy(aux_nome, v[iEsq].nome);
    strcpy(aux_mat, v[iEsq].matricula);
    aux_id = v[iEsq].id;
    aux_pen = v[iEsq].pendencia;

    strcpy(v[iEsq].nome, v[iDir].nome);
    strcpy(v[iEsq].matricula, v[iDir].matricula);
    v[iEsq].id = v[iDir].id;
    v[iEsq].pendencia = v[iDir].pendencia;

    strcpy(v[iDir].nome, aux_nome);
    strcpy(v[iDir].matricula, aux_mat);
    v[iDir].id = aux_id;
    v[iDir].pendencia = aux_pen;

    //printf("%s %s %d %d\n", v[iDir].nome, v[iDir].matricula, v[iDir].id, v[iDir].pendencia);
    //printf("%s %s %d %d\n", v[iEsq].nome, v[iEsq].matricula, v[iEsq].id, v[iEsq].pendencia);

}

int particao_alunos(aluno *v, int esq, int dir) {
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
            swap_alunos(v, esq_p, dir_p);
        }
    }
    swap_alunos(v, esq_p, dir);
    return esq_p;
}

void quicksort_alunos(aluno * v, int esq, int dir) {
    if (esq < dir) {
        int particao = particao_alunos(v, esq, dir);
        quicksort_alunos(v, esq, particao - 1);
        quicksort_alunos(v, particao + 1, dir);
    }
}

//! Função para reduzir o espaço de linhas necessário para checar a pendência
void pendencia_alunos(int pendencia){
    if(pendencia == 0){
        puts("Aluno sem pendências!");
    } else {
        printf("Aluno com %d pendencia(s)!\n", pendencia);
    }    
}

int buscaBin_alunos(aluno *v, int id, int tam){
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

// Sessão de funções explícitas de _alunos

//! Função para realizar a busca de um determinado aluno através de seu id, recebe a referência do vetor, o id e o tam.
void buscar_alunos(aluno *lista_alunos, int id, int tam){
    int i = buscaBin_alunos(lista_alunos, id, tam);
    if (i >= 0){
        printf("Aluno id [%d] encontrado!\n", lista_alunos[i].id);
        printf("Nome: %s\n", lista_alunos[i].nome);
        printf("Matrícula: %s\n", lista_alunos[i].matricula);
        pendencia_alunos(lista_alunos[i].pendencia);

    } else {

        printf("id não cadastrado!\n");
    }
}

 
void mostrar_alunos(aluno * lista_alunos, int tam){
    int contador = 0;
    int i = 0;
    while(contador < tam){
        if(lista_alunos[i].id < 0){
            i++;
        } else {
            puts("<=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=>");
            printf("Id: %d\n", lista_alunos[i].id);
            printf("Matrícula: %s\n", lista_alunos[i].matricula);
            printf("Nome: %s\n", lista_alunos[i].nome);
            pendencia_alunos(lista_alunos[i].pendencia);
            contador++;
            i++;
        }
    }
    puts("");
}

//! Função para criação de novos alunos, cria um aluno apenas.
int criar_alunos(aluno **lista_alunos, int tam, int *id_data){
    if(tam + 1 % 32 == 0){
        *lista_alunos = realloc(*lista_alunos, ((tam + 1) + 32) * sizeof(aluno));
    }

    id_data[0]++;
    (*lista_alunos)[tam].id = id_data[0];
    printf("Iniciado registro ID: %d\n", (*lista_alunos)[tam].id);
    
    __fpurge(stdin);

    printf("Inserir nome do aluno: ");
    scanf("%[^\n]s", (*lista_alunos)[tam].nome);

    printf("Inserir matrícula do aluno, modelo xxxxxx@yyyy: ");
    scanf("%s", (*lista_alunos)[tam].matricula);

    __fpurge(stdin);

    (*lista_alunos)[tam].pendencia = 0;

    quicksort_alunos((*lista_alunos), 0, tam);

    puts("O cadastro foi um sucesso!");

    return tam+1;

}

//! Função para remover alunos, define id do aluno como -1;
int remover_alunos(aluno *lista_alunos, int id, int tam){
    int i = buscaBin_alunos(lista_alunos, id, tam);
    if (i >= 0){
        if(lista_alunos[i].pendencia == 0){
            printf("Deletando aluno '%s', matricula: %s!\n", lista_alunos[i].nome, lista_alunos[i].matricula);
            lista_alunos[i].id = -1;
            quicksort_alunos(lista_alunos, 0, tam);
            return tam-1;
        } else {
            puts("Erro: Não foi possível deletar o aluno!\nMotivo: Pendência");
        }
    } else {
        puts("Erro: Id não cadastrado!");
    }
    return tam;
}
 