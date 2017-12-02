/*
Autores:
Gabriela Barrozo Guedes - 16/0121612 - JJ
Iago de Andrade Sousa - 16/0124701- JJ
*/

#include <stdio.h>

//  O struct foi utilizado para salvar as variaveis que contam a quantidade de cada
//numero que aparece na linha, na coluna e na matriz 3x3 do elemento que esta sendo
//avaliado no momento
typedef struct{
    int a1, a2, a3, a4, a5, a6, a7, a8, a9;
} contagem;

//  A função qual_numero soma na variavel correspodente do numero que apareceu
contagem qual_numero (char n, contagem possibilidade){

    if (n==49){
        possibilidade.a1++;
    } else if (n==50){
        possibilidade.a2++;
    } else if (n==51){
        possibilidade.a3++;
    } else if (n==52){
        possibilidade.a4++;
    } else if (n==53){
        possibilidade.a5++;
    } else if (n==54){
        possibilidade.a6++;
    } else if (n==55){
        possibilidade.a7++;
    } else if (n==56){
        possibilidade.a8++;
    } else if (n==57){
        possibilidade.a9++;
    }

    return possibilidade;
}

//  A função divide_matriz separa a matriz do sudoku 9x9 em 9 matrizes 3x3, de
//acordo com as seções separadas pelo proprio jogo
void divide_matriz(char m[9][9], char m11[3][3], char m12[3][3], char m13[3][3], char m21[3][3], char m22[3][3], char m23[3][3], char m31[3][3], char m32[3][3], char m33[3][3]){
    int linha, coluna;

    for(linha=0; linha<3; linha++){
        for(coluna=0; coluna<3; coluna++){
            m11[linha][coluna] = m[linha][coluna];
            m12[linha][coluna] = m[linha][coluna+3];
            m13[linha][coluna] = m[linha][coluna+6];

            m21[linha][coluna] = m[linha+3][coluna];
            m22[linha][coluna] = m[linha+3][coluna+3];
            m23[linha][coluna] = m[linha+3][coluna+6];

            m31[linha][coluna] = m[linha+6][coluna];
            m32[linha][coluna] = m[linha+6][coluna+3];
            m33[linha][coluna] = m[linha+6][coluna+6];
        }
    }
}

//  A função transforma_matriz transforma a letra X presente na matriz pelo
//caractere zero
void transforma_matriz(char m[9][9]) {
    int i, j;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (m[i][j] == 'X') {
                m[i][j] = 48;
            }
        }
    }
}

//  A função verifica_matriz verifica e conta nas variaveis os numeros que aparecem
//na seção do sudoku a ser analisada
contagem verifica_matriz(char matriz[3][3], contagem possibilidade){
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            possibilidade = qual_numero(matriz[i][j], possibilidade);
        }
    }

    return possibilidade;
}

//  A função print_sudoku faz o printf da matriz do sudoku 9x9, separando-a em
//seções de matrizes 3x3
void print_sudoku (char sudoku[9][9]) {
  int i, j, h = 0, v, j2;

  for (i = 0; i < 9; i++) {
    v = 0;

    for (j = 0; j < 8; j++) {

      if (h == 3) {
        for (j2 = 0; j2 < 10; j2++) {
          printf("- ");
        }

        printf("-");
        printf("\n");
        h = 0;
      }

      printf("%c ", sudoku[i][j]);
      v++;

      if (v == 3) {
        printf("| ");

        v = 0;
      }
    }

    printf("%c", sudoku[i][j]);
    h++;

    printf("\n");
  }
}

int main(){
    contagem possibilidade;
    char sudoku[9][9], s11[3][3], s12[3][3], s13[3][3], s21[3][3], s22[3][3], s23[3][3], s31[3][3], s32[3][3], s33[3][3];
    int linha, coluna, o, i;

    for (linha = 0; linha < 9; linha++) {
        for (coluna = 0; coluna < 9; coluna++) {
            if (linha == 8 && coluna == 8) {
                scanf("%c", &sudoku[linha][coluna]);
            } else {
                scanf("%c ", &sudoku[linha][coluna]);
            }
        }
    }

    transforma_matriz(sudoku);

    divide_matriz(sudoku, s11, s12, s13, s21, s22, s23, s31, s32, s33);

//  Antes de começar a resolver o sudoku, é necessário ver se o mesmo precisa ser
//resolvido, dessa forma, verificamos se ha zeros na matriz
    o = 0;

    for (linha = 0; linha < 9; linha++) {
        for (coluna = 0; coluna < 9; coluna++) {
            if (sudoku[linha][coluna]==48) {
                o++;
            }
        }
    }

//  Se a matriz do sudoku possui zeros, entramos no while para resolver esses
//espaços
    while (o > 0 ) {

        for (linha = 0; linha < 9; linha++) {
            for (coluna = 0; coluna < 9; coluna++) {

//  Ao encontrar o numero zero, começamos a resolver o problema
                if (sudoku[linha][coluna]==48) {

//  Primeiro igualamos as variaveis correspondentes as possibilidades a zero
                    possibilidade.a1=0; possibilidade.a2=0; possibilidade.a3=0;
                    possibilidade.a4=0; possibilidade.a5=0; possibilidade.a6=0;
                    possibilidade.a7=0; possibilidade.a8=0; possibilidade.a9=0;

//  Verificamos, então, os numeros presentes na linha e na coluna do que esta
//sendo examinado, e somamos nas variaveis correspondentes
                    for (i = 0; i < 9; i++) {
                        //  Linha
                        possibilidade = qual_numero(sudoku[linha][i], possibilidade);
                        //  Coluna
                        possibilidade = qual_numero(sudoku[i][coluna], possibilidade);
                    }

//  Após a linha e a coluna, verificamos a seção em que o numero examinado se
//encontra, os numeros presentes nessa matriz 3x3 são somados nas variaveis
//correspondetes a cada numero
                    if(linha<3){
                        if (coluna<3) {
                            possibilidade = verifica_matriz(s11, possibilidade);
                        }else if(coluna<6){
                            possibilidade = verifica_matriz(s12, possibilidade);
                        }else if(coluna<9){
                            possibilidade = verifica_matriz(s13, possibilidade);
                        }
                    }else if(linha<6){
                        if (coluna<3) {
                            possibilidade = verifica_matriz(s21, possibilidade);
                        }else if(coluna<6){
                            possibilidade = verifica_matriz(s22, possibilidade);
                        }else if(coluna<9){
                            possibilidade = verifica_matriz(s23, possibilidade);
                        }
                    }else if(linha<9){
                        if (coluna<3) {
                            possibilidade = verifica_matriz(s31, possibilidade);
                        }else if(coluna<6){
                            possibilidade = verifica_matriz(s32, possibilidade);
                        }else if(coluna<9){
                            possibilidade = verifica_matriz(s33, possibilidade);
                        }
                    }

//  Após toda essa analise, verificamos se uma das variaveis das possibilidades
//de numeros de 1 a 9 continua igual a zero (se a variavel continua zero é porque
//o seu numero não foi encontrado na linha, na coluna nem na seção), se somente
//uma das 9 variaveis for zero, então esse é o numero que estamos procurando
                    if (possibilidade.a1==0 && possibilidade.a2>0 && possibilidade.a3>0 && possibilidade.a4>0 && possibilidade.a5>0 && possibilidade.a6>0 && possibilidade.a7>0 && possibilidade.a8>0 && possibilidade.a9>0){
                        sudoku[linha][coluna] = 49;
                    } else if (possibilidade.a1>0 && possibilidade.a2==0 && possibilidade.a3>0 && possibilidade.a4>0 && possibilidade.a5>0 && possibilidade.a6>0 && possibilidade.a7>0 && possibilidade.a8>0 && possibilidade.a9>0) {
                        sudoku[linha][coluna] = 50;
                    } else if (possibilidade.a1>0 && possibilidade.a2>0 && possibilidade.a3==0 && possibilidade.a4>0 && possibilidade.a5>0 && possibilidade.a6>0 && possibilidade.a7>0 && possibilidade.a8>0 && possibilidade.a9>0) {
                        sudoku[linha][coluna] = 51;
                    } else if (possibilidade.a1>0 && possibilidade.a2>0 && possibilidade.a3>0 && possibilidade.a4==0 && possibilidade.a5>0 && possibilidade.a6>0 && possibilidade.a7>0 && possibilidade.a8>0 && possibilidade.a9>0) {
                        sudoku[linha][coluna] = 52;
                    } else if (possibilidade.a1>0 && possibilidade.a2>0 && possibilidade.a3>0 && possibilidade.a4>0 && possibilidade.a5==0 && possibilidade.a6>0 && possibilidade.a7>0 && possibilidade.a8>0 && possibilidade.a9>0) {
                        sudoku[linha][coluna] = 53;
                    } else if (possibilidade.a1>0 && possibilidade.a2>0 && possibilidade.a3>0 && possibilidade.a4>0 && possibilidade.a5>0 && possibilidade.a6==0 && possibilidade.a7>0 && possibilidade.a8>0 && possibilidade.a9>0) {
                        sudoku[linha][coluna] = 54;
                    } else if (possibilidade.a1>0 && possibilidade.a2>0 && possibilidade.a3>0 && possibilidade.a4>0 && possibilidade.a5>0 && possibilidade.a6>0 && possibilidade.a7==0 && possibilidade.a8>0 && possibilidade.a9>0) {
                        sudoku[linha][coluna] = 55;
                    } else if (possibilidade.a1>0 && possibilidade.a2>0 && possibilidade.a3>0 && possibilidade.a4>0 && possibilidade.a5>0 && possibilidade.a6>0 && possibilidade.a7>0 && possibilidade.a8==0 && possibilidade.a9>0) {
                        sudoku[linha][coluna] = 56;
                    } else if (possibilidade.a1>0 && possibilidade.a2>0 && possibilidade.a3>0 && possibilidade.a4>0 && possibilidade.a5>0 && possibilidade.a6>0 && possibilidade.a7>0 && possibilidade.a8>0 && possibilidade.a9==0) {
                        sudoku[linha][coluna] = 57;
                    }
                }
            }
        }

        divide_matriz(sudoku, s11, s12, s13, s21, s22, s23, s31, s32, s33);

//  Vemos novamente se o sudoku ainda tem espaços para ser resolvido
        o = 0;

        for (linha = 0; linha < 9; linha++) {
            for (coluna = 0; coluna < 9; coluna++) {
                if (sudoku[linha][coluna]==48) {
                    o++;
                }
            }
        }
    }

//  Ao sair do while, temos um resultado
    print_sudoku(sudoku);

    return 0;
}
