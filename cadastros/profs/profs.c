#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_DISCIPLINAS 6
#define TAM_NOME 50
#define MAX 50

// Struct da disciplina
struct Disciplina{
    int cod;
    char nomeDisc[TAM_NOME];
};

// Struct do professor
struct Professor{
    long long matricula;
    char nome[TAM_NOME];
    char escolaridade[TAM_NOME];
    char especialista[TAM_NOME];
    Disciplina disciplinas[MAX_DISCIPLINAS];
    int qtdDisciplinas; // Para saber quantas estão em uso
};

struct Professor professor[MAX];

void imprimir(int y) {
    printf("Matricula: %lld\n", professor[y].matricula);
    printf("Nome: %s\n", professor[y].nome);
    printf("Escolaridade: %s\n", professor[y].escolaridade);
    printf("Especialista: %s\n", professor[y].especialista);
    printf("Disciplinas: %s\n", professor[y].qtdDisciplinas);
}



int main(){
    return 0;
}