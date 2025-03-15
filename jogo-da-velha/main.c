#include <stdio.h> // Entrada e saida
#include <string.h> // Manipular strings
#include <stdbool.h> // Manipular booleanos
#include <stdlib.h> // Sla, essa lib faz tanta coisa, https://www.ibm.com/docs/pt-br/i/7.5?topic=files-stdlibh

// Necessário para usar o clear
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

char* caminho[9][4];
char jogador1[4],jogador2[4];
char simb ='O';
int nj=0, j1_win=0, j2_win=0, emp=0; // j1 eh um nome reservado da math.h, n use j1
_Bool enc=false; // oq significa esse enc msm?

// utilitarios

// encerra o programa
void sair(){
  printf("\nEncerrando...");
  exit(EXIT_SUCCESS);
}

// limpa a tela (eu sei, eh redundante)
void limpartela(){
  system("clear");
}

int impar(int num){
  if(num % 2 == 0){
    return 0;
  } else{
    return 1;
  }
}
// fim dos utilitarios

void menu(){
  // exibe menu principal
  printf("***************************\n");
  printf("*       GAME VELHA        *\n");
  printf("***************************\n");
  printf("*                         *\n");
  printf("*   1 - INICIAR           *\n");
  printf("*   2 - ESTATISTICA       *\n");
  printf("*   3 - SAIR              *\n");
  printf("*                         *\n");
  printf("***************************\n");
  printf("ESCOLHA A OPCAO DESEJADA: ");
}

void estatistica(){
  // exibe estatisticas
  limpartela();
  printf("***************************\n");
  printf("*       ESTATISTICA       *\n");
  printf("***************************\n");
  printf("*                         *\n");
  printf("*        %c = %i          *\n",jogador1,j1_win);
  printf("*        %c = %i          *\n",jogador2,j2_win);
  printf("*       Empate = %i       *\n",emp);
  printf("*                         *\n");
  printf("***************************\n");
}

// recursos de partida

void inicializar(){

  for (int id=0;id<9;id++){
    for (int c=0;c<3;c++){
      caminho[id][c]="";
    }
  }
}

// so faz trocar o simbolo
char simbolo(){

  if (simb == 'O'){
    simb = 'X';
  }else{
    simb ='O';
  }
  nj++;
  return simb;
}

// exibe o jogo (incompleto)
void gindex(){
  printf("* * * * * * * * * * * * \n");
  printf("        *       *       \n");
  printf("   1    *   2   *   3   \n");
  printf("        *       *       \n");
  printf("* * * * * * * * * * * * \n");
  printf("        *       *       \n");
  printf("   4    *   5   *   6   \n");
  printf("        *       *       \n");
  printf("* * * * * * * * * * * * \n");
  printf("        *       *       \n");
  printf("   7    *   8   *   9   \n");
  printf("        *       *       \n");
  printf("* * * * * * * * * * * * \n");
}

// funcao principal do jogo, pode ser chamada para iniciar uma partida
void game(){
  int jogada, vez, turno;

  printf("\nDigite o nome do jogador 1 (Maximo de 3 letras): ");
  scanf("%3s", jogador1);

  printf("\nDigite o nome do jogador 2 (Máximo de 3 letras): ");
  scanf("%3s", jogador2);

  while(1){
    vez = impar(turno);

    gindex();

    if(vez == 0){
      printf("\nTurno de %s", jogador1);
      printf("\nFaça sua jogada: ");
      scanf("%i", &jogada);
    } else{
      printf("\nTurno de %s", jogador2);
      printf("\nFaça sua jogada: ");
      scanf("%i", &jogada);
    }

    printf("Jogada na casa: %i", jogada);

    continue;
  }
}
// fim dos recursos de partida

// main
int main(){
  int escolha;
  //limpartela();

  while(1){
    menu();
    scanf("%i", &escolha);

    switch(escolha){
      case 1:
        game();
        break;
      case 2:
        estatistica();
        break;
      case 3:
        sair();
        break;
      default:
        limpartela();
        printf("Opção Invalida! Tente Novamente!\n");
        sleep(3);
        while (getchar() != '\n');
    }
    sleep(3);
    limpartela();
  }
}

