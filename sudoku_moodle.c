/*
Autores:
Gabriela Barrozo Guedes - 16/0121612 - JJ
Iago Andrade - 16/... - JJ
*/
#include <stdio.h>

typedef struct{
    int a1, a2, a3, a4, a5, a6, a7, a8, a9;
} contagem;

contagem qual_numero (char n, contagem bla){
    if (n==49){
        bla.a1++;
    } else if (n==50){
        bla.a2++;
    } else if (n==51){
        bla.a3++;
    } else if (n==52){
        bla.a4++;
    } else if (n==53){
        bla.a5++;
    } else if (n==54){
        bla.a6++;
    } else if (n==55){
        bla.a7++;
    } else if (n==56){
        bla.a8++;
    } else if (n==57){
        bla.a9++;
    }

    return bla;
}

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

contagem verifica_matriz(char matriz[3][3], contagem bla){
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            bla = qual_numero(matriz[i][j], bla);
        }
    }

    return bla;
}

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
    contagem bla;
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

    divide_matriz(sudoku, s11, s12, s13, s21, s22, s23, s31, s32, s33);

    transforma_matriz(sudoku);

    o = 0;

    for (linha = 0; linha < 9; linha++) {
        for (coluna = 0; coluna < 9; coluna++) {
            if (sudoku[linha][coluna]==48) {
                o++;
            }
        }
    }

    while (o > 0 ) {
        for (linha = 0; linha < 9; linha++) {
            for (coluna = 0; coluna < 9; coluna++) {

                if (sudoku[linha][coluna]==48) {
                    bla.a1=0; bla.a2=0; bla.a3=0;
                    bla.a4=0; bla.a5=0; bla.a6=0;
                    bla.a7=0; bla.a8=0; bla.a9=0;

                    for (i = 0; i < 9; i++) {
                        bla = qual_numero(sudoku[linha][i], bla);
                        bla = qual_numero(sudoku[i][coluna], bla);
                    }

                    if(linha<3){
                        if (coluna<3) {
                            bla = verifica_matriz(s11, bla);
                        }else if(coluna<6){
                            bla = verifica_matriz(s12, bla);
                        }else if(coluna<9){
                            bla = verifica_matriz(s13, bla);
                        }
                    }else if(linha<6){
                        if (coluna<3) {
                            bla = verifica_matriz(s21, bla);
                        }else if(coluna<6){
                            bla = verifica_matriz(s22, bla);
                        }else if(coluna<9){
                            bla = verifica_matriz(s23, bla);
                        }
                    }else if(linha<9){
                        if (coluna<3) {
                            bla = verifica_matriz(s31, bla);
                        }else if(coluna<6){
                            bla = verifica_matriz(s32, bla);
                        }else if(coluna<9){
                            bla = verifica_matriz(s33, bla);
                        }
                    }

                    if (bla.a1==0 && bla.a2>0 && bla.a3>0 && bla.a4>0 && bla.a5>0 && bla.a6>0 && bla.a7>0 && bla.a8>0 && bla.a9>0){
                        sudoku[linha][coluna] = 49;
                    } else if (bla.a1>0 && bla.a2==0 && bla.a3>0 && bla.a4>0 && bla.a5>0 && bla.a6>0 && bla.a7>0 && bla.a8>0 && bla.a9>0) {
                        sudoku[linha][coluna] = 50;
                    } else if (bla.a1>0 && bla.a2>0 && bla.a3==0 && bla.a4>0 && bla.a5>0 && bla.a6>0 && bla.a7>0 && bla.a8>0 && bla.a9>0) {
                        sudoku[linha][coluna] = 51;
                    } else if (bla.a1>0 && bla.a2>0 && bla.a3>0 && bla.a4==0 && bla.a5>0 && bla.a6>0 && bla.a7>0 && bla.a8>0 && bla.a9>0) {
                        sudoku[linha][coluna] = 52;
                    } else if (bla.a1>0 && bla.a2>0 && bla.a3>0 && bla.a4>0 && bla.a5==0 && bla.a6>0 && bla.a7>0 && bla.a8>0 && bla.a9>0) {
                        sudoku[linha][coluna] = 53;
                    } else if (bla.a1>0 && bla.a2>0 && bla.a3>0 && bla.a4>0 && bla.a5>0 && bla.a6==0 && bla.a7>0 && bla.a8>0 && bla.a9>0) {
                        sudoku[linha][coluna] = 54;
                    } else if (bla.a1>0 && bla.a2>0 && bla.a3>0 && bla.a4>0 && bla.a5>0 && bla.a6>0 && bla.a7==0 && bla.a8>0 && bla.a9>0) {
                        sudoku[linha][coluna] = 55;
                    } else if (bla.a1>0 && bla.a2>0 && bla.a3>0 && bla.a4>0 && bla.a5>0 && bla.a6>0 && bla.a7>0 && bla.a8==0 && bla.a9>0) {
                        sudoku[linha][coluna] = 56;
                    } else if (bla.a1>0 && bla.a2>0 && bla.a3>0 && bla.a4>0 && bla.a5>0 && bla.a6>0 && bla.a7>0 && bla.a8>0 && bla.a9==0) {
                        sudoku[linha][coluna] = 57;
                    }
                }
            }
        }

        divide_matriz(sudoku, s11, s12, s13, s21, s22, s23, s31, s32, s33);

        o = 0;

        for (linha = 0; linha < 9; linha++) {
            for (coluna = 0; coluna < 9; coluna++) {
                if (sudoku[linha][coluna]==48) {
                    o++;
                }
            }
        }
    }

    print_sudoku (sudoku);

    return 0;
}
