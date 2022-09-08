#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//! Função para armazenar DATA dos id's!
void salvar_id_data(int * id_data){
    FILE * pasta_escrever;
    pasta_escrever = fopen("id_data.txt", "w+");

    fprintf(pasta_escrever, "%d\n", id_data[0]);
    fprintf(pasta_escrever, "%d\n", id_data[1]);

    fclose(pasta_escrever);
}

//! Função para armazenar DATA de alunos!
void salvar_alunos(aluno *lista_alunos, int tam){
    FILE * pasta_escrever;
    pasta_escrever = fopen("alunos.txt", "w+");

    int i = 0, contador = 0;
    while(contador < tam){
        if (lista_alunos[i].id > -1){
            fprintf(pasta_escrever, "%s|", lista_alunos[i].nome);
            fprintf(pasta_escrever, "%s|", lista_alunos[i].matricula);
            fprintf(pasta_escrever, "%d|", lista_alunos[i].id);
            fprintf(pasta_escrever, "%d|\n", lista_alunos[i].pendencia);
            i++;
            contador++;
        } else {
            i++;
        }
    }

    fclose(pasta_escrever);
}

//! Função para armazenar DATA de livros!
void salvar_livros(livro *lista_livros, int tam){
    FILE * pasta_escrever;
    pasta_escrever = fopen("livros.txt", "w+");

    int i = 0, contador = 0;
    while(contador < tam){
        if (lista_livros[i].id > -1){
            fprintf(pasta_escrever, "%s|", lista_livros[i].nome);
            fprintf(pasta_escrever, "%s|", lista_livros[i].categoria);
            fprintf(pasta_escrever, "%d|", lista_livros[i].ano);
            fprintf(pasta_escrever, "%d|", lista_livros[i].id);
            fprintf(pasta_escrever, "%d|", lista_livros[i].pendencia);
            fprintf(pasta_escrever, "%d|\n", lista_livros[i].aluno_id);
            i++;
            contador++;
        } else {
            i++;
        }
    }

    fclose(pasta_escrever);
}

//! Função para armazenar DATA de recursos!
void salvar_recursos(recursos *lista_recursos, int tam){
    FILE * pasta_escrever;
    pasta_escrever = fopen("recursos.txt", "w+");

    int i = 0, contador = 0;;
    while(contador < tam){
        if(lista_recursos[i].id > -1){
            fprintf(pasta_escrever, "%d|", lista_recursos[i].id);
            fprintf(pasta_escrever, "%d|", lista_recursos[i].aluno_id);
            fprintf(pasta_escrever, "%c|", lista_recursos[i].tipo);
            fprintf(pasta_escrever, "%d|\n", lista_recursos[i].estado);
            i++;
            contador++;
        } else {
            i++;
        }
    }

    fclose(pasta_escrever);
}