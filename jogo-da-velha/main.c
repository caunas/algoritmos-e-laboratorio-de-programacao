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

// alguem me explica oq kct era pra ser essas variaveis?
char caminho[9][4];
char jogador1[],jogador2[];
char simb ='O';
int nj=0, j1=0, j2=0, emp=0;
_Bool enc=false;

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
  printf("***************************\n");
  printf("*       ESTATISTICA       *\n");
  printf("***************************\n");
  printf("*                         *\n");
  printf("*        %c = %i          *\n",jogador1,j1);
  printf("*        %c = %i          *\n",jogador2,j2);
  printf("*       Empate = %i       *\n",emp);
  printf("*                         *\n");
  printf("***************************\n");
}

// recursos de partida

// pra q kct isso aq serve?
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
  char j1_nome[4], j2_nome[4];
  int jogada;
  int turno, vez;

  printf("\nDigite o nome do jogador 1 (Maximo de 3 letras): ");
  scanf("%3s", j1_nome);

  printf("\nDigite o nome do jogador 2 (Máximo de 3 letras): ");
  scanf("%3s", j2_nome);

  while(1){
    vez = impar(turno);

    gindex();

    if(vez == 0){
      printf("\nTurno de %s", j1_nome);
      printf("\nFaça sua jogada: ");
      scanf("%2s", jogada);
    } else{
      printf("\nTurno de %s", j2_nome);
      printf("\nFaça sua jogada: ");
      scanf("%2s", jogada);
    }

    printf("Jogada na casa: %i", jogada);

    continue;
  }
}
// fim dos recursos de partida

//debug

// utilitarios de teste, quem descobrir isso aq vai literalmente xitar no jogo da velha
void dmenu(){
  printf("***************************\n");
  printf("*          DMENU          *\n");
  printf("***************************\n");
  printf("*                         *\n");
  printf("*       1 - RANKING       *\n");
  printf("*                         *\n");
  printf("***************************\n");
  printf("ESCOLHA A OPCAO DESEJADA: ");
}

void debug_tools(){
  printf("Debug mode = True");
  dmenu();
}

//fim do debug

// main
void main()
{
  int escolha;

  menu();
  scanf("%i", &escolha);
  limpartela();

  switch(escolha){
    case 1:
      game();
      break;
    case 2:
      estatistica();
      break;
    case 3:
      sair();
    case 76:
    debug_tools();
    break;
  }
}
