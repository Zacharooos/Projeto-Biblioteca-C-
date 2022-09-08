#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdio_ext.h>
#include <locale.h>
#include "struct.h"
#include "carregamento.h"
#include "funcoes_alunos.h"
#include "funcoes_livros.h"
#include "funcoes_recursos.h"

int main(){

    setlocale(LC_ALL, "");

    aluno *lista_alunos;
    livro *lista_livros;
    recursos *lista_recursos;

    lista_alunos = (aluno *) malloc(32 * sizeof(aluno));
    lista_livros = (livro *) malloc(32 * sizeof(livro));
    lista_recursos = (recursos *) malloc(32 * sizeof(recursos));

    int id_data[3];

    FILE *pasta_ler;    
    
    // Leitura do id_data
    char cadeia[100];
    pasta_ler = fopen("id_data.txt", "r");

    int boot;

    if (pasta_ler == NULL){
        puts("É a primeira vez que o programa é aberto ? 1 = Sim, 2 = Não");
        scanf("%d", &boot);
        if (boot == 1){
            pasta_ler = fopen("id_data.txt", "w+");
            fclose(pasta_ler);
            pasta_ler = fopen("alunos.txt", "w+");
            fclose(pasta_ler);
            pasta_ler = fopen("livros.txt", "w+");
            fclose(pasta_ler);
            pasta_ler = fopen("recursos.txt", "w+");
            fclose(pasta_ler);
        }
    }

    pasta_ler = fopen("id_data.txt", "r");

    if (pasta_ler == NULL){
        printf("FatalError! Pasta id_data não encontrada...\n");
        pasta_ler = fopen("id_data.txt", "w+");
        // Não funciona a escrita!
        fprintf(pasta_ler, "%d\n", 0);
        fprintf(pasta_ler, "%d\n", 0);
        fclose(pasta_ler);
        printf("Reinicie o programa!");
        return 0;
    }

    for (int i = 0; i < 3; ++i){
        fgets(cadeia, 11, pasta_ler);
        id_data[i] = atoi(cadeia);
    }
    
    // Inicio leitura alunos
    pasta_ler = fopen("alunos.txt", "r");

    if (pasta_ler == NULL){
        printf("Pasta não encontrada, criando diretório...\n");
        pasta_ler = fopen("alunos.txt", "w+");
        fclose(pasta_ler);
        return 0;
    }

    int k = 0;
    while(fgets(cadeia, 100, pasta_ler) != NULL){
        char *aux;

        aux = strtok(cadeia, "|");
        strcpy(lista_alunos[k].nome, aux);

        aux = strtok(NULL ,"|");
        strcpy(lista_alunos[k].matricula, aux);

        aux = strtok(NULL ,"|");
        lista_alunos[k].id = atoi(aux);

        
        aux = strtok(NULL ,"|");
        lista_alunos[k].pendencia = atoi(aux);
        k++;

        if(k+1 % 32 == 0){
            lista_alunos = realloc(lista_alunos, ((k + 1) + 32) * sizeof(aluno));
        }
    }  
    
    fclose(pasta_ler);

    int tam_alunos = k;
    // Fim leitura alunos
    // Inicio leitura livros
    
    pasta_ler = fopen("livros.txt", "r");

    if (pasta_ler == NULL){
        printf("Pasta não encontrada, criando diretório...\n");
        pasta_ler = fopen("livros.txt", "w+");
        fclose(pasta_ler);
    }

    k = 0;
    while(fgets(cadeia, 100, pasta_ler) != NULL){
        char *aux;

        aux = strtok(cadeia, "|");
        strcpy(lista_livros[k].nome, aux);

        aux = strtok(NULL ,"|");
        strcpy(lista_livros[k].categoria, aux);

        aux = strtok(NULL ,"|");
        lista_livros[k].ano = atoi(aux);

        aux = strtok(NULL ,"|");
        lista_livros[k].id = atoi(aux);
        
        aux = strtok(NULL ,"|");
        lista_livros[k].pendencia = (bool) atoi(aux);

        aux = strtok(NULL ,"|");
        lista_livros[k].aluno_id = atoi(aux);
        
        k++;
        if(k+1 % 32 == 0){
            lista_livros = realloc(lista_livros, ((k + 1) + 32) * sizeof(livro));
        }
    }
    
    fclose(pasta_ler);

    int tam_livros = k;
    //Fim leitura livros
    //Inicio leitura recursos

    pasta_ler = fopen("recursos.txt", "r");

    if (pasta_ler == NULL){
        printf("Pasta não encontrada, criando diretório...\n");
        pasta_ler = fopen("recursos.txt", "w+");
        fclose(pasta_ler);
        return 0;
    }

    k = 0;
    while(fgets(cadeia, 100, pasta_ler) != NULL){
        char *aux;

        aux = strtok(cadeia ,"|");
        lista_recursos[k].id = atoi(aux);

        aux = strtok(NULL ,"|");
        lista_recursos[k].aluno_id = atoi (aux);

        aux = strtok(NULL ,"|");
        lista_recursos[k].tipo = aux[0];

        aux = strtok(NULL ,"|");
        lista_recursos[k].estado = (bool) atoi(aux);

        k++;
        if(k+1 % 32 == 0){
            lista_recursos = realloc(lista_recursos, ((k + 1) + 32) * sizeof(recursos));
        }
    }  

    fclose(pasta_ler);

    int tam_recursos = k;

    // Menu

    int menu, menu2;
    while (1){
        puts("=-=-=-=-=-= MENU PRINCIPAL =-=-=-=-=-=");
        puts("1 - Operações com alunos .....");
        puts("2 - Operações com livros .....");
        puts("3 - Operações com recursos ...");
        puts("4 - Encerrar operações  ......");
        scanf("%d", &menu);
        switch (menu){
        
        case 1: //Operações alunos
            system("clear");
            __fpurge(stdin);
            puts("=-=-=-=-=-= MENU ALUNOS =-=-=-=-=-=");
            puts("1 - Mostrar todos .........");
            puts("2 - Buscar aluno via id ...");
            puts("3 - Adicionar aluno .......");
            puts("4 - Remover aluno via id ..");
            puts("5 - Retornar ..............");
            
            scanf("%d", &menu);
            
            switch (menu){
            
            case 1:// mostrar alunos
                system("clear");
                mostrar_alunos(lista_alunos, tam_alunos);
                break;

            case 2:
                system("clear");
                printf("Inserir id do aluno para busca!: ");
                scanf("%d", &menu);
                printf("\n");
                buscar_alunos(lista_alunos, menu, tam_alunos);
                break;

            case 3:
                system("clear");
                tam_alunos = criar_alunos(&lista_alunos, tam_alunos, id_data);
                break;

            case 4:
                system("clear");
                printf("Inserir id do aluno para deleção!: ");
                scanf("%d", &menu);
                printf("\n");
                tam_alunos = remover_alunos(lista_alunos, menu, tam_alunos);
                break;

            case 5:
                break;
            }
            break;
        
        case 2: //Operações livros
            system("clear");
            __fpurge(stdin);
            puts("=-=-=-=-=-= MENU LIVROS =-=-=-=-=-=");
            puts("1 - Mostrar todos .........");
            puts("2 - Buscar livro via id ...");
            puts("3 - Adicionar livro .......");
            puts("4 - Remover livro via id ..");
            puts("5 - Registrar empréstimo ..");
            puts("6 - Registrar devolução ...");
            puts("7 - Retornar ..............");

            scanf("%d", &menu);
            switch (menu){
            case 1:
                system("clear");
                mostrar_livros(lista_livros, lista_alunos, tam_livros, tam_alunos);
                break;
            
            case 2:
                system("clear");
                printf("Inserir id do livro para busca!: ");
                scanf("%d", &menu);
                printf("\n");
                buscar_livros(lista_livros, lista_alunos, menu, tam_livros, tam_alunos);
                break;

            case 3:
                system("clear");
                tam_livros = criar_livros(&lista_livros, tam_livros, id_data);
                break;
            
            case 4:
                system("clear");
                printf("Inserir id do livro para deleção!: ");
                scanf("%d", &menu);
                printf("\n");
                tam_livros = remover_livros(lista_livros, menu, tam_livros);
                break;

            case 5:
                system("clear");
                printf("Inserir id do livro para registro!: ");
                scanf("%d", &menu);
                printf("\nInserir id do aluno para registro!: ");
                scanf("%d", &menu2);
                printf("\n");
                registro_livros(lista_livros, lista_alunos, menu, menu2, tam_livros, tam_alunos);
                break;
            
            case 6:
                system("clear");
                printf("Inserir id do livro para devolução!: ");
                scanf("%d", &menu);
                printf("\nInserir id do livro para devolução!: ");
                scanf("%d", &menu2);
                printf("\n");
                deregistro_livros(lista_livros, lista_alunos, menu, menu2, tam_livros, tam_alunos);
                break;
            case 7:
                break;
            }
            break;

        case 3: //Operações recursos
            system("clear");
            __fpurge(stdin);
            puts("=-=-=-=-=-= MENU RECURSOS =-=-=-=-=-=");
            puts("1 - Mostrar todos ............");
            puts("2 - Buscar recursos via id ...");
            puts("3 - Adicionar recursos .......");
            puts("4 - Remover recursos via id ..");
            puts("5 - Registrar empréstimo .....");
            puts("6 - Registrar devolução ......");
            puts("7 - Retornar .................");
            scanf("%d", &menu);

            switch (menu){
            case 1:
                system("clear");
                mostrar_recursos(lista_recursos, lista_alunos, tam_recursos, tam_alunos);
                break;
            
            case 2:
                system("clear");
                printf("Inserir id do recursos para busca!: ");
                scanf("%d", &menu);
                printf("\n");
                buscar_recursos(lista_recursos, lista_alunos, menu, tam_recursos, tam_alunos);
                break;

            case 3:
                system("clear");
                tam_recursos = criar_recursos(&lista_recursos, tam_recursos);
                break;

            case 4:
                __fpurge(stdin);
                system("clear");
                printf("Inserir id do recurso para deleção!: ");
                scanf("%d", &menu);
                printf("\n");
                tam_recursos = remover_recursos(lista_recursos, menu, tam_recursos);
                break;

            case 5:
                system("clear");
                printf("Inserir id do recurso para registro!: ");
                scanf("%d", &menu);
                printf("\nInserir id do aluno para registro!: ");
                scanf("%d", &menu2);
                printf("\n");
                registro_recursos(lista_recursos, lista_alunos, menu, menu2, tam_recursos, tam_alunos);
                break;

            case 6:
                system("clear");
                printf("Inserir id do recurso para devolução!: ");
                scanf("%d", &menu);
                printf("\nInserir id do aluno para devolução!: ");
                scanf("%d", &menu2);
                printf("\n");
                deregistro_recursos(lista_recursos, lista_alunos, menu, menu2, tam_recursos, tam_alunos);
                break;
            
            case 7:
                break;
            }
            break;
        
        case 4:
            salvar_alunos(lista_alunos, tam_alunos);
            salvar_livros(lista_livros, tam_livros);
            salvar_recursos(lista_recursos, tam_recursos);
            salvar_id_data(id_data);

            free(lista_alunos);
            free(lista_livros);
            free(lista_recursos);

            system("clear");
            return 0;
        }
    }
     
    puts("Aviso!: Por algum motivo o programa encerrou de maneira indevida...");
    puts("Deseja que as informações atuais sejam salvas? Esse processo pode corromper os arquivos ...");
    puts("Digite 1 para confirmar salvamento, ou 2 para descartar alterações: ");
    scanf("%d", &menu);

    if (menu = 1){
        salvar_alunos(lista_alunos, tam_alunos);
        salvar_livros(lista_livros, tam_livros);
        salvar_recursos(lista_recursos, tam_recursos);
        salvar_id_data(id_data);
    }

    free(lista_alunos);
    free(lista_livros);
    free(lista_recursos);
    
    system("clear");
    return 0;
}