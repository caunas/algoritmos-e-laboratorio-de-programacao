#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX 100

int i = 0, opcao;
long long mat;

struct Aluno {
    long long matricula;
    char nome[50];
    int idade;
    float nota;
    char turma[10];
    char curso[50];    
};

struct Aluno aluno[MAX];

void imprimir(int y) {
    printf("Matricula: %lld\n", aluno[y].matricula);
    printf("Nome: %s\n", aluno[y].nome);
    printf("Idade: %d\n", aluno[y].idade);
    printf("Nota: %.1f\n", aluno[y].nota);
    printf("Turma: %s\n", aluno[y].turma);
    printf("Curso: %s\n\n", aluno[y].curso);
}

void cadastrar() {
    char continuar;

    do {
        printf("Digite a matricula do aluno: ");
        scanf("%lld", &aluno[i].matricula);

        getchar(); // limpa o buffer
        printf("Digite o nome do aluno: ");
        fgets(aluno[i].nome, sizeof(aluno[i].nome), stdin);
        aluno[i].nome[strcspn(aluno[i].nome, "\n")] = '\0';

        printf("Digite a idade do aluno: ");
        scanf("%d", &aluno[i].idade);

        printf("Digite a nota do aluno: ");
        scanf("%.1f", &aluno[i].nota);

        printf("Digite a turma do aluno: ");
        scanf("%s", &aluno[i].turma);

        getchar(); // limpa o buffer
        printf("Digite o curso do aluno: ");
        fgets(aluno[i].curso, sizeof(aluno[i].curso), stdin);
        aluno[i].curso[strcspn(aluno[i].curso, "\n")] = '\0';

        i++;

        printf("Deseja cadastrar outro aluno? (S/N): ");
        scanf("%c", &continuar);
        system("clear");
    } while ((continuar == 'S' || continuar == 's') && i < MAX);
}

void alterar(int x) {
    char op;    
    printf("1 - Matricula\n2 - Nome\n3 - Idade\n4 - Nota\n5 - Turma\n6 - Curso\n\n O que você deseja alterar? : ");
    scanf("%c", &op);

    switch (op) {
        case '1':
            printf("Digite a nova matricula: ");
            scanf("%lld", &aluno[x].matricula);
            break;
        case '2':
            getchar();
            printf("Digite o novo nome: ");
            fgets(aluno[x].nome, sizeof(aluno[x].nome), stdin);
            aluno[x].nome[strcspn(aluno[x].nome, "\n")] = '\0';
            break;
        case '3':
            printf("Digite a nova idade: ");
            scanf("%d", &aluno[x].idade);
            break;
        case '4':
            printf("Digite a nova nota: ");
            scanf("%.1f", &aluno[x].nota);
            break;
        case '5':
            printf("Digite a nova turma: ");
            scanf("%s", &aluno[x].turma);
            break;
        case '6':
            getchar();
            printf("Digite o novo curso: ");
            fgets(aluno[x].curso, sizeof(aluno[x].curso), stdin);
            aluno[x].curso[strcspn(aluno[x].curso, "\n")] = '\0';
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }
}

void excluir(int z){    
    for(int x=z;x<i;x++){
        aluno[x]=aluno[x+1];
    }
    i--;
}

bool consultar(long long mat) {
    bool enc = false;
    int x = 0;

    while (x < i && enc == false) {
        if (strcmp(aluno[x].matricula, mat) == 0) {
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

void main() {
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
                    printf("Digite a matricula do aluno: ");
                    scanf("%lld",&mat);

                    if (!consultar(mat)) {
                        printf("Aluno nao cadastrado.\n");
                        sleep(3000); // pausa de 3 segundos (em milissegundos)
                    }
                } else {
                    printf("Nenhum aluno cadastrado.\n");
                    sleep(3000); // pausa de 3 segundos (em milissegundos)
                }
                break;
            case 5:
                if (i > 0) {
                    printf("\n--- Dados dos Alunos ---\n");
                    for (int x = 0; x < i; x++) {
                        imprimir(x);
                    }
                    sleep(3000); // pausa de 3 segundos (em milissegundos)
                } else {
                    printf("Nenhum aluno cadastrado.\n");
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
}
