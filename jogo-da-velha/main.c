#include <stdio.h> // Entrada e saida
// #include <string.h> // Manipular strings
#include <stdbool.h> // Manipular booleanos
#include <stdlib.h> // Sla, essa lib faz tanta coisa, https://www.ibm.com/docs/pt-br/i/7.5?topic=files-stdlibh
#include <locale.h> // necessário para utilizar o setlocale

// Necessário para usar o cls
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

char caminho[10];
char jogador1[4],jogador2[4];
char simb ='O';
int nj=0, j1_win=0, j2_win=0, emp=0; // j1 eh um nome reservado da math.h, n use j1
_Bool enc=false; // essa é uma variável para declarar o vencedor aparentemente

// utilitarios

// encerra o programa
void sair(){
  printf("\nEncerrando...");
  exit(EXIT_SUCCESS);
}

// limpa a tela (eu sei, eh redundante)
void limpartela(){
  system("cls");
}

int impar(int num){
  if(num % 2 == 0){
    return 0;
  } else{
    return 1;
  }
}

// exibe menu principal
void menu(){
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
  printf("*        %s = %i          *\n",jogador1,j1_win);
  printf("*        %s = %i          *\n",jogador2,j2_win);
  printf("*       Empate = %i        *\n",emp);
  printf("*                         *\n");
  printf("***************************\n");
}

void nomear_jogadores(){
  printf("\nDigite o nome do jogador 1 (Maximo de 3 letras): ");
  scanf("%3s", jogador1);

  printf("\nDigite o nome do jogador 2 (Máximo de 3 letras): ");
  scanf("%3s", jogador2);
}
// fim dos utilitarios

// recursos de partida
void inicializar(){
  nj = 1;
  for (int id=0;id<10;id++){
    for (int c=0;c<3;c++){
      caminho[id]='?';
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
    printf("   %c    *   %c   *   %c   \n", caminho[1], caminho[2], caminho[3]);
    printf("        *       *       \n");
    printf("* * * * * * * * * * * * \n");
    printf("        *       *       \n");
    printf("   %c    *   %c   *   %c   \n", caminho[4], caminho[5], caminho[6]);
    printf("        *       *       \n");
    printf("* * * * * * * * * * * * \n");
    printf("        *       *       \n");
    printf("   %c    *   %c   *   %c   \n", caminho[7], caminho[8], caminho[9]);
    printf("        *       *       \n");
    printf("* * * * * * * * * * * * \n");
}

// funcao principal do jogo, pode ser chamada para iniciar uma partida
int verificar_jogada(int jogada, char* jogador){
  if(caminho[jogada] != '?'){
    /*
    printf("Jogada de %s na casa: %i\n", jogador, jogada);
    jogada -=1;
    caminho[jogada][0] = simb;
    Sleep(2);
    */
    return 1;
  } else{
    //printf("Quadrado ocupado...");
    return 0;
  }
}

// verifica vitoria
_Bool verificar_vitoria(){
  _Bool ver = false;

  if(nj < 5){
    return ver;
  } else{
    if(caminho[1] == caminho[2] && caminho[2] == caminho[3]){
      if(caminho[1] != '?'){
        ver = true;
      }
    }else if(caminho[4] == caminho[5] && caminho[5] == caminho[6]){
      if(caminho[4] != '?'){
        ver = true;
      }
    }else if(caminho[7] == caminho[8] && caminho[8] == caminho[9]){
      if(caminho[7] != '?'){
        ver = true;
      }
    }else if(caminho[1] == caminho[4] && caminho[4] == caminho[7]){
      if(caminho[1] != '?'){
        ver = true;
      }
    }else if(caminho[2] == caminho[5] && caminho[5] == caminho[8]){
      if(caminho[2] != '?'){
        ver = true;
      }
    }else if(caminho[3] == caminho[6] && caminho[6] == caminho[9]){
      if(caminho[3] != '?'){
        ver = true;
      }
    }else if(caminho[1] == caminho[5] && caminho[5] == caminho[9]){
      if(caminho[1] != '?'){
        ver = true;
      }
    }else if(caminho[3] == caminho[5] && caminho[5] == caminho[7]){
      if(caminho[3] != '?'){
        ver = true;
      }
    }
  }
  return ver;
}

// funcao principal do jogo
void game(){
  inicializar();
  int jogada, turno = 1;

  while(1){
    limpartela();
    printf("Jogada N: %i\n", nj);
    gindex();

    // verifica jogador pelo turno

    // turno do jogador 1
    if(impar(turno) == 1){

      printf("\nTurno de %s", jogador1);
      printf("\nFaça sua jogada: ");
      scanf("%i", &jogada);
      // verifica se a jogada eh valida
      if(verificar_jogada (jogada, jogador1) == 0){
        printf("Jogada Valida\n");
        caminho[jogada] = simb;
        // verificar vitoria
        if(nj >= 4){
          if(verificar_vitoria() == true){
            limpartela();
            gindex();
            printf("Fim de jogo. Vitoria de %s\n", jogador1);
            j1_win++;
            Sleep(3);
            break;
          } else{
            if(nj >= 10){
              limpartela();
              gindex();
              printf("Fim de jogo. Empate...\n");
              emp++;
              Sleep(3);
              break;
            }
          }
        }
        Sleep(2);
      } else{
        printf("\nJogada Invalida. Turno perdido.\n");
        Sleep(2);
      }
    } else{
      // turno do jogador 2
      printf("\nTurno de %s", jogador2);
      printf("\nFaça sua jogada: ");
      scanf("%i", &jogada);
      // verifica se a jogada eh valida
      if(verificar_jogada (jogada, jogador2) == 0){
        printf("\nJogada Valida\n");
        caminho[jogada] = simb;
        if(nj >= 4){
          if(verificar_vitoria() == true){
            limpartela();
            gindex();
            printf("Fim de jogo. Vitoria de %s\n", jogador2);
            j2_win++;
            Sleep(3);
            break;
          } else{
            if(nj >= 10){
              limpartela();
              gindex();
              printf("Fim de jogo. Empate...\n");
              emp++;
              Sleep(3);
              break;
            }
          }
        }
        Sleep(2);
      } else{
        printf("\nJogada Invalida. Turno perdido.\n");
        Sleep(2);
      }
    }
    simbolo();
    turno++;
    continue;
  }
}

void jogar_novamente(){
  char escolha;
  while (getchar() != '\n'); // limpar o stdin atual, corrige bugs de entrada dupla
  while(1){
    printf("Deseja jogar novamente (S/N)? ");
    scanf("%c", &escolha);
  
    if(escolha == 's'){
      system("cls");
      game();
    } else if(escolha == 'n'){
      break;
    } else{
      printf("Escolha invalida. ");
      continue;
    }
  }
    

}
// fim dos recursos de partida

// main
int main(){
  setlocale(LC_ALL,"Portuguese");
  int escolha;

  nomear_jogadores();
  limpartela();
  
  while(1){
    menu();
    scanf("%i", &escolha);

    switch(escolha){
      case 1:
        game();
        jogar_novamente();
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
        Sleep(3);
        while (getchar() != '\n');
    }
    Sleep(3);
    limpartela();
  }
}