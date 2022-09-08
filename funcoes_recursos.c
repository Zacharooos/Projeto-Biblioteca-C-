#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include "struct.h"

// Seção de Funções implícitas de _recursos

//! Função quick_sort para ajustar lista de recursos.

void swap_recursos(recursos *v, int iEsq, int iDir){
    int aux_id, aux_aluno_id;
    char aux_char;
    bool aux_bool;

    aux_id = v[iEsq].id;
    aux_aluno_id = v[iEsq].aluno_id;
    aux_char = v[iEsq].tipo;
    aux_bool = v[iEsq].estado;

    v[iEsq].id = v[iDir].id;
    v[iEsq].aluno_id = v[iDir].aluno_id;
    v[iEsq].tipo = v[iDir].tipo;
    v[iEsq].estado = v[iDir].estado;

    v[iDir].id = aux_id;
    v[iDir].aluno_id = aux_aluno_id;
    v[iDir].tipo = aux_char;
    v[iDir].estado = aux_bool;

    //printf("Id %d, al_id %d, tipo %c, est %d\n", v[iDir].id, v[iDir].aluno_id, v[iDir].tipo, v[iDir].estado);
    //printf("Id %d, al_id %d, tipo %c, est %d\n", v[iEsq].id, v[iEsq].aluno_id, v[iEsq].tipo, v[iEsq].estado);

}

int particao_recursos(recursos *v, int esq, int dir) {
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
            swap_recursos(v, esq_p, dir_p);
        }
    }
    swap_recursos(v, esq_p, dir);
    return esq_p;
}

void quicksort_recursos(recursos * v, int esq, int dir) {
    if (esq < dir) {
        int particao_recursosPoint = particao_recursos(v, esq, dir);
        quicksort_recursos(v, esq, particao_recursosPoint - 1);
        quicksort_recursos(v, particao_recursosPoint + 1, dir);
    }
}

//! Função para checar pendência.
void pendencia_recursos(int pendencia){
    if(pendencia == 0){
        puts("Recurso disponível pra empréstimo!");
    } else {
        puts("Recurso atualmente emprestado!");
    }    
}

int buscaBin_alunos_r(aluno *v, int id, int tam){
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

int buscaBin_recursos(recursos *v, int id, int tam){
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

// Seção de Funções explícitas de _recursos

//! Função para realizar a busca de um determinado recurso através de seu id, recebe a referência do vetor, o id e o tam.
void buscar_recursos(recursos *lista_recursos, aluno * lista_alunos, int id, int tam_recursos, int tam_alunos){
    int i = buscaBin_recursos(lista_recursos, id, tam_recursos);
    if (i >= 0){
        puts("<=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=>");
        printf("Recurso id [%d] encontrado!\n", lista_recursos[i].id);
        printf("Tipo: %c\n", lista_recursos[i].tipo);

		pendencia_recursos(lista_recursos[i].estado);
        if(lista_recursos[i].estado == true){
            int i_aluno = buscaBin_alunos_r(lista_alunos, lista_recursos[i].aluno_id, tam_alunos);
            printf("Matricula do aluno: %s\n", lista_alunos[i_aluno].matricula);
        }

    } else {
        printf("Erro: Id não cadastrado!\n");
    }
}

//! Função para mostrar todos os recursos
void mostrar_recursos(recursos * lista_recursos, aluno * lista_alunos, int tam_recursos, int tam_alunos){
    int contador = 0;
    int i = 0;
    while (contador < tam_recursos){
        if(lista_recursos[i].id < 0){ //MOD < 0  vira < -5
            i++;
        } else {
            printf("Recurso id [%d] encontrado!\n", lista_recursos[i].id);
            printf("Tipo: %c\n", lista_recursos[i].tipo);

            pendencia_recursos(lista_recursos[i].estado);
            if(lista_recursos[i].estado == true){
                int i_aluno = buscaBin_alunos_r(lista_alunos, lista_recursos[i].aluno_id, tam_alunos);
                printf("Matricula do aluno: %s\n", lista_alunos[i_aluno].matricula);
            }

            puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
            i++;
            contador++;
        }
    }
    puts("");
}

//! Função para a criação de recursos
int criar_recursos(recursos **lista_recursos, int tam){
    if(tam + 1 % 32 == 0){
        *lista_recursos = realloc(*lista_recursos, ((tam + 1) + 32) * sizeof(recursos));
    }

    int id_data;
    puts("Inserir id para cadastro: ");
    scanf("%d", &id_data);
    while(buscaBin_recursos((*lista_recursos), id_data, tam) > -1){
        puts("Erro! Id inválido! (em uso), tente outro a seguir: ");
        scanf("%d", &id_data);
    }
    __fpurge(stdin);

    (*lista_recursos)[tam].id = id_data;
    printf("Iniciado registro ID: %d\n", (*lista_recursos)[tam].id);
    
    printf("Categorias: 'S' = Sala, 'C' = Computador, 'A' = Armario.\n");
    printf("Inserir categoria do recurso: ");
    scanf("%c", &(*lista_recursos)[tam].tipo);

    (*lista_recursos)[tam].aluno_id = -2; 

    (*lista_recursos)[tam].estado = 0;

    quicksort_recursos((*lista_recursos), 0, tam);

    puts("O cadastro foi um sucesso!");

    return tam+1;
}

//! Função para remover recursos, define id do aluno como -1;
int remover_recursos(recursos *lista_recursos, int id, int tam){
    int i = buscaBin_recursos(lista_recursos, id, (tam));
    if (i > -1){
        if(lista_recursos[i].estado == 0){
            printf("Deletando recurso [%d]!\n", lista_recursos[i].id);
            lista_recursos[i].id = -2;
            quicksort_recursos(lista_recursos, 0, tam);
            return tam-1;
        } else {
            puts("Erro: Não foi possível deletar o recurso!\nMotivo: Pendência");
        }
    } else {
        puts("Erro: Id não cadastrado!");
    }
    return tam;
}

//! Função para cadastrar recurso no alunos
void registro_recursos(recursos *lista_recursos, aluno *lista_alunos, int id, int id_aluno, int tam_recursos, int tam_alunos){
    int i_recurso = buscaBin_recursos(lista_recursos, id, tam_recursos);
    int i_aluno = buscaBin_alunos_r(lista_alunos, id_aluno, tam_alunos);
    
    //Checar se o recurso existe
    if (i_recurso < 0){
        puts("Erro: recurso não encontrado!");
        return;
    }

    //Checar se o aluno existe
    if (i_aluno < 0){
        puts("Erro: Aluno não encontrado!");
        return;
    }

    //Checar se o recurso está emprestado
    if (lista_recursos[i_recurso].estado == 0){
        lista_recursos[i_recurso].estado = 1;
        lista_recursos[i_recurso].aluno_id = lista_alunos[i_aluno].id;
        lista_alunos[i_aluno].pendencia++;
        puts("Cadastro realizado com sucesso!");

    } else {
        puts("Erro: Impossível emprestar, recurso não disponível!");
    }
}

//! Função para devolução do recurso
void deregistro_recursos(recursos *lista_recursos, aluno *lista_alunos, int id, int id_aluno, int tam_recursos, int tam_alunos){
    int i_recurso = buscaBin_recursos(lista_recursos, id, tam_recursos);
    int i_aluno = buscaBin_alunos_r(lista_alunos, id_aluno, tam_alunos);
    
    //Checar se o recurso existe
    if (i_recurso < 0){
        puts("Erro: recurso não encontrado!");
        return;
    }

    //Checar se o aluno existe
    if (i_aluno < 0){
        puts("Erro: Aluno não encontrado!");
        return;
    }

    //Checar se o recurso está emprestado
    if (lista_recursos[i_recurso].estado == 1){
        if (lista_recursos[i_recurso].aluno_id == lista_alunos[i_aluno].id){
            lista_recursos[i_recurso].estado = 0;
            lista_recursos[i_recurso].aluno_id = -2;
            lista_alunos[i_aluno].pendencia--;
            puts("Devolução realizada com sucesso!");
        } else {
            puts("recurso não vinculado a este aluno, falha no processo!");
        }
    } else {
        puts("Erro: Impossível devolver, recurso está no estoque!");
    }
}