#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <stdbool.h>

int i = 0, opcao;
long long mat;

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
    struct Disciplina disciplinas[MAX_DISCIPLINAS];
    int qtdDisciplinas; // Para saber quantas estão em uso
};

struct Professor professor[MAX];

void imprimir(int y) {
    printf("Matricula: %lld\n", professor[y].matricula);
    printf("Nome: %s\n", professor[y].nome);
    printf("Escolaridade: %s\n", professor[y].escolaridade);
    printf("Especialista: %s\n", professor[y].especialista);
    printf("Disciplinas: %i\n", professor[y].qtdDisciplinas);
}

void cadastrar() {
    char continuar;

    do {
        printf("Digite a matricula do professor: ");
        scanf("%lld", &professor[i].matricula);

        getchar(); // limpa o buffer
        printf("Digite o nome do professor: ");
        fgets(professor[i].nome, sizeof(professor[i].nome), stdin);
        professor[i].nome[strcspn(professor[i].nome, "\n")] = '\0';

        printf("Digite a escolaridade do professor: ");
        scanf("%s", &professor[i].escolaridade);

        printf("Digite a especialização do professor: ");
        scanf("%s", &professor[i].especialista);

        printf("Digite quantas disciplinas estão em uso: ");
        scanf("%i", &professor[i].qtdDisciplinas);

        getchar(); // limpa o buffer

        i++;

        printf("Deseja cadastrar outro professor? (S/N): ");
        scanf("%c", &continuar);
        system("clear");
    } while ((continuar == 'S' || continuar == 's') && i < MAX);
}

void alterar(int x) {
    char op;    
    printf("1 - Matricula\n2 - Nome\n3 - Escolaridade\n4 - Especialização\n5 - Disciplinas\n\n O que você deseja alterar? : ");
    scanf("%c", &op);

    switch (op) {
        case '1':
            printf("Digite a nova matricula: ");
            scanf("%lld", &professor[x].matricula);
            break;
        case '2':
            getchar();
            printf("Digite o novo nome: ");
            fgets(professor[x].nome, sizeof(professor[x].nome), stdin);
            professor[x].nome[strcspn(professor[x].nome, "\n")] = '\0';
            break;
        case '3':
            printf("Digite a nova escolaridade: ");
            scanf("%s", &professor[x].escolaridade);
            break;
        case '4':
            printf("Digite a especialização: ");
            scanf("%s", &professor[x].especialista);
            break;
        case '5':
            printf("Quantas disciplinas o professor tem? ");
            scanf("%i", &professor[x].qtdDisciplinas);
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }
}

void excluir(int z){    
    for(int x=z;x<i;x++){
        professor[x]=professor[x+1];
    }
    i--;
}

bool consultar(long long mat) {
    bool enc = false;
    int x = 0;

    while (x < i && enc == false) {
        if (strcmp(professor[x].matricula, mat) == 0) {
            if (opcao == 2) {
                imprimir(x);                
            } else if (opcao == 3) {
                alterar(x);
                printf("Registro alterado com sucesso!");
            } else if (opcao == 4){
                excluir(x);
                printf("Registro excluido com sucesso!");
            }    
            sleep(3000); // pausa de 3 segundos (em milissegundos)        
            enc = true;
            return enc;
        }        
        x++;
    }
    return enc;
}

void menu() {
    system("clear");
    printf("*****************************\n");
    printf("*       MENU PRINCIPAL      *\n");
    printf("*****************************\n");
    printf("*   1 - CADASTRAR           *\n");
    printf("*   2 - CONSULTAR           *\n");
    printf("*   3 - ALTERAR             *\n");
    printf("*   4 - EXCLUIR             *\n"); 
    printf("*   5 - IMPRIMIR            *\n");
    printf("*   6 - SAIR                *\n");
    printf("*****************************\n");
    printf("ESCOLHA A OPCAO DESEJADA: ");
}

int main(){
    system("clear");
    setlocale(LC_ALL, "Portuguese");
    do {
        menu();
        scanf("%d", &opcao);
        system("clear");

        switch (opcao) {
            case 1:
                cadastrar();
                break;
            case 2:
            case 3:
            case 4:
                if (i > 0) {                    
                    printf("Digite a matricula do professor: ");
                    scanf("%lld",&mat);

                    if (!consultar(mat)) {
                        printf("Professor não cadastrado.\n");
                        sleep(3000); // pausa de 3 segundos (em milissegundos)
                    }
                } else {
                    printf("Nenhum professor cadastrado...\n");
                    sleep(3000); // pausa de 3 segundos (em milissegundos)
                }
                break;
            case 5:
                if (i > 0) {
                    printf("\n--- Dados dos Professores ---\n");
                    for (int x = 0; x < i; x++) {
                        imprimir(x);
                        printf("\n")
                    }
                    sleep(3000); // pausa de 3 segundos (em milissegundos)
                } else {
                    printf("Nenhum professor cadastrado...\n");
                    sleep(3000); // pausa de 3 segundos (em milissegundos)
                }
                break;                 
            case 6:
                printf("... saindo...\n");
                sleep(3000); // pausa de 3 segundos (em milissegundos)
                break;
            default:
                printf("Opção invalida!\n");
                sleep(3000); // pausa de 3 segundos (em milissegundos)
                break;
        }        
    } while (opcao != 6);

    printf("Sistema finalizado com sucesso!\n");
    return 0;
}