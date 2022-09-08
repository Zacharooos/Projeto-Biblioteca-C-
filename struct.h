#ifndef STRUCT_H

#define STRUCT_H

#include <stdbool.h>

//Biblioteca para para guardar declaração de Structs
//! Struct aluno
typedef struct aluno{
    int id; //!< Id do aluno, máximo suportado sendo o limite de representação dos números inteiros em C.
    int pendencia; //!< Valor da pendencia, alunos podem acumular diferentes pendencias, acumulando as mesmas.
    char nome[52]; //!< Espaço para nome, considerando o maior nome registrado no Brasil.
    char matricula[12]; //!< Matricula considerando o formato ENG de Computação CEFET, sendo este: xxxxxx@yyyy.

} aluno;

//! Struct para guardar Livro
typedef struct livro{
    int ano; //!< Ano de publicação do livro
    int id; //!< Id do livro, máximo suportado sendo o limite de representação dos números inteiros em C.
    int aluno_id; //!< Id do aluno associado, quando não há aluno com o livro, o id aponta para um valor negativo.
    char nome[101]; //!< Nome do livro.
    char categoria[51]; //!< Categoria do livro, utilize uma palavra única como identificador.
    bool pendencia; //!< Valor booleano de pendencia, ou o livro está emprestado, ou não está.
    
} livro;

//! Struct para guardar Recursos
typedef struct recursos{
    int id; //!< Id do recurso, máximo suportado sendo o limite de representação dos números inteiros em C.
    int aluno_id; //!< Id do aluno associado, quando não há aluno com o recurso, o id aponta para um valor negativo.
    char tipo; //!< Caractér único responsável por atribuir tipo ao recurso, podendo este representar "C" para Computadores, "S" para Salas e "A" para Armários.
    bool estado; //!< Valor booleano de pendencia, ou o recurso está emprestado, ou não está.

} recursos;

#endif