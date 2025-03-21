#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

char caminho[9];
char j[3][3];
char jogador1[20], jogador2[20];
char simb ='O';
int nj=0, j1=0, j2=0, emp=0, op=0;
_Bool enc=false;

void inicializar(){
  for (int id=0;id<9;id++){
    caminho[id] = ""; 
  }

  for(int lin=0;lin<3;lin++){
    for(int col=0;col<3;col++){
      j[lin][col]="";
    }
  }

  nj=0;
}

char simbolo(){
  if (simb == 'O'){
    simb = 'X';
  }else{
    simb ='O';
  }
  nj++;
  return simb;
}

void menu(){
  printf("***************************\n");
  printf("*       GAME VELHA        *\n");
  printf("***************************\n");
  printf("*                         *\n");
  printf("*   1 - INICIAR           *\n");
  printf("*   2 - ESTATISTICA       *\n");
  printf("*   3 - SAIR              *\n");
  printf("*                         *\n");
  printf("***************************\n\n");
  printf("ESCOLHA A OPCAO DESEJADA: ");
}

void game(){
  printf("    0        1       2   \n");
  printf("         *       *       \n");
  printf("0   %c     *   %c    *   %c \n", j[0][0], j[0][1], j[0][2]);
  printf("         *       *       \n");
  printf(" * * * * * * * * * * * * \n");
  printf("         *       *       \n");
  printf("1   %c     *   %c    *   %c \n", j[1][0], j[1][1], j[1][2]);
  printf("         *       *       \n");
  printf(" * * * * * * * * * * * * \n");
  printf("         *       *       \n");
  printf("2   %c     *   %c    *   %c \n", j[2][0], j[2][1], j[2][2]);
  printf("         *       *       \n\n");  
}

void estatistica(){
  printf("***************************\n");
  printf("*       ESTATISTICA       *\n");
  printf("***************************\n");
  printf("*                         *\n");
  printf("*   %c = %i   *\n",jogador1,j1);
  printf("*   %c = %i   *\n",jogador2,j2);
  printf("*   Empate = %i       *\n",emp);
  printf("*                         *\n");
  printf("***************************\n");
}

_Bool verificarjogada(int l, int c){
  _Bool per=false;
  if (j[l][c]==""){
    per=true;
  }else{
    per=false;
  }
  return per;
}

void armazenar(int l,int c){
  if(l==0 && c==0){
    caminho[1]+=j[l][c];
    caminho[6]+=j[l][c];
    caminho[8]+=j[l][c];
  }else if (l==0 && c==1){
    caminho[1]+=j[l][c];
    caminho[5]+=j[l][c];
  }else if (l==0 && c==2){
    caminho[1]+=j[l][c];
    caminho[4]+=j[l][c];
    caminho[7]+=j[l][c];
  }else if (l==1 && c==0){
    caminho[2]+=j[l][c];
    caminho[6]+=j[l][c];
  }else if (l==1 && c==1){
    caminho[2]+=j[l][c];
    caminho[5]+=j[l][c];
    caminho[7]+=j[l][c];
    caminho[8]+=j[l][c];
  }else if (l==1 && c==2){
    caminho[2]+=j[l][c];
    caminho[4]+=j[l][c];
  }else if (l==2 && c==0){
    caminho[3]+=j[l][c];
    caminho[6]+=j[l][c];
    caminho[7]+=j[l][c];
  }else if (l==2 && c==1){
    caminho[3]+=j[l][c];
    caminho[5]+=j[l][c];
  }else if (l==2 && c==2){
    caminho[3]+=j[l][c];
    caminho[4]+=j[l][c];
    caminho[8]+=j[l][c];
  }
}

/*_Bool verificarvitoria(){
  _Bool ver=false;
  if (nj>=5){

  }
  return ver;
}*/

int main(){
  do{
    menu();
    scanf("%d",&op);
    system("clear");
    switch(op){
      case 1:{
        game();
        break;
      }
      case 2:{
        estatistica();
        break;
      }
      default:{
        if(op>3){
          printf("Opcao invalida!\n");             
        }
        break;
      }
    }
  }while(op<3); 
  system("clear");
}
