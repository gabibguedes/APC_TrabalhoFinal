// Velho, nao sei pq ele ta funcionando kkkk, eu nao resolvi aquele problema, eu
//so tava digitando os comentarios e qndo eu vi funcionou!!!!!!
//Entao viva nois so falta ajustar isso pra char e colocar aquela função q vc fez
//pra dar o printf!!!

// Teoricamente o usuario teria que escrever o sudoku na entrada colocando o numero
//zero no lugar dos espaços em branco

#include <stdio.h>

// Eu usei struct pra salvar as variaveis que contam os numeros que faltam.
typedef struct{
    int a1, a2, a3, a4, a5, a6, a7, a8, a9;
} contagem;

// Essa funçao, "qual_numero", soma um a variavel que o numero selecionado pertence.
contagem qual_numero (int n, contagem bla){
    if (n==1){
        bla.a1++;
    } else if (n==2){
        bla.a2++;
    } else if (n==3){
        bla.a3++;
    } else if (n==4){
        bla.a4++;
    } else if (n==5){
        bla.a5++;
    } else if (n==6){
        bla.a6++;
    } else if (n==7){
        bla.a7++;
    } else if (n==8){
        bla.a8++;
    } else if (n==9){
        bla.a9++;
    }

    return bla;
}

// Essa função divide a matriz original 9x9, em 9 matrizes 3x3, q seriam as matrizes
//dentro do sudoku, essas matrizes devem ser sempre atualizadas.
int divide_matriz(int m[9][9], int m11[3][3], int m12[3][3], int m13[3][3], int m21[3][3], int m22[3][3], int m23[3][3], int m31[3][3], int m32[3][3], int m33[3][3]){
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

// Esta função verifica quais numeros ja estao presentes na matriz 3x3 em que o
//numero pertence, utilizando a função "qual_numero" e somando um as variaveis q
//representam os numeros ja existentes.
contagem verifica_matriz(int matriz[3][3], contagem bla){
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            bla = qual_numero(matriz[i][j], bla);
        }
    }

    return bla;
}

int main(){
    contagem bla;
    int sudoku[9][9], s11[3][3], s12[3][3], s13[3][3], s21[3][3], s22[3][3], s23[3][3], s31[3][3], s32[3][3], s33[3][3];
    int linha, coluna, o, i;

    printf("Escreva o seu sudoku, onde for um espaco em branco preencha com o numero zero:\n");

    for (linha = 0; linha < 9; linha++) {
        for (coluna = 0; coluna < 9; coluna++) {
            scanf("%d", &sudoku[linha][coluna]);
        }
    }

    divide_matriz(sudoku, s11, s12, s13, s21, s22, s23, s31, s32, s33);

    o = 0;

// Neste for verifica-se se o sudoku precisa ser resolvido
    for (linha = 0; linha < 9; linha++) {
        for (coluna = 0; coluna < 9; coluna++) {
            if (sudoku[linha][coluna]==0) {
                o++;
            }
        }
    }

// Se ainda tiverem zeros na matriz do sudoku, entra-se no while para reslver
    while (o > 0 ) {
        for (linha = 0; linha < 9; linha++) {
            for (coluna = 0; coluna < 9; coluna++) {

                if (sudoku[linha][coluna]==0) {

// As variaveis que contam os numeros existentes sao, inicialmente zero.
                    bla.a1=0; bla.a2=0; bla.a3=0;
                    bla.a4=0; bla.a5=0; bla.a6=0;
                    bla.a7=0; bla.a8=0; bla.a9=0;

//Neste for verificamos os numeros existentes na linha e na coluna do elemento a
//ser analisado, somando os existentes a variavel em que pertencem.
                    for (i = 0; i < 9; i++) {
                        //linha
                        bla = qual_numero(sudoku[linha][i], bla);
                        //coluna
                        bla = qual_numero(sudoku[i][coluna], bla);
                    }

//Nessa sequencia de ifs e else ifs, verificamos qual matriz 3x3 o elemento a ser
//analisado pertence e entao, assim como foi feito na linha e na coluna, verifica-se
//quais numeros ja estao presentes
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

// O printf serve para ver como o programa esta reagindo, mostra quais variaveis
//ainda sao zero para o elemento q estamos analisando
                    printf("Em (%dx%d), A1= %d; A2= %d; A3= %d; A4= %d; A5= %d; A6= %d; A7= %d; A8= %d; A9= %d\n",(linha+1), (coluna+1), bla.a1, bla.a2, bla.a3, bla.a4, bla.a5, bla.a6, bla.a7, bla.a8, bla.a9);

//Se somente uma variavel continua zero, o programa subtitui o 0 que estava na
//matriz pelo numero representado pela variavel
                    if (bla.a1==0 && bla.a2>0 && bla.a3>0 && bla.a4>0 && bla.a5>0 && bla.a6>0 && bla.a7>0 && bla.a8>0 && bla.a9>0){
                        sudoku[linha][coluna] = 1;
                    } else if (bla.a1>0 && bla.a2==0 && bla.a3>0 && bla.a4>0 && bla.a5>0 && bla.a6>0 && bla.a7>0 && bla.a8>0 && bla.a9>0) {
                        sudoku[linha][coluna] = 2;
                    } else if (bla.a1>0 && bla.a2>0 && bla.a3==0 && bla.a4>0 && bla.a5>0 && bla.a6>0 && bla.a7>0 && bla.a8>0 && bla.a9>0) {
                        sudoku[linha][coluna] = 3;
                    } else if (bla.a1>0 && bla.a2>0 && bla.a3>0 && bla.a4==0 && bla.a5>0 && bla.a6>0 && bla.a7>0 && bla.a8>0 && bla.a9>0) {
                        sudoku[linha][coluna] = 4;
                    } else if (bla.a1>0 && bla.a2>0 && bla.a3>0 && bla.a4>0 && bla.a5==0 && bla.a6>0 && bla.a7>0 && bla.a8>0 && bla.a9>0) {
                        sudoku[linha][coluna] = 5;
                    } else if (bla.a1>0 && bla.a2>0 && bla.a3>0 && bla.a4>0 && bla.a5>0 && bla.a6==0 && bla.a7>0 && bla.a8>0 && bla.a9>0) {
                        sudoku[linha][coluna] = 6;
                    } else if (bla.a1>0 && bla.a2>0 && bla.a3>0 && bla.a4>0 && bla.a5>0 && bla.a6>0 && bla.a7==0 && bla.a8>0 && bla.a9>0) {
                        sudoku[linha][coluna] = 7;
                    } else if (bla.a1>0 && bla.a2>0 && bla.a3>0 && bla.a4>0 && bla.a5>0 && bla.a6>0 && bla.a7>0 && bla.a8==0 && bla.a9>0) {
                        sudoku[linha][coluna] = 8;
                    } else if (bla.a1>0 && bla.a2>0 && bla.a3>0 && bla.a4>0 && bla.a5>0 && bla.a6>0 && bla.a7>0 && bla.a8>0 && bla.a9==0) {
                        sudoku[linha][coluna] = 9;
                    }

//Outro printf para ver como o programa esta reagindo, nele vemos o valor que foi
//substituido e por qual numero
                    printf("Logo, (%dx%d) eh : %d\n", (linha+1), (coluna+1), sudoku[linha][coluna]);

                }
            }
        }

        divide_matriz(sudoku, s11, s12, s13, s21, s22, s23, s31, s32, s33);

        o = 0;

// verifica-se novamente se ainda tem zeros no sudoku, se tiver o while sera repetido
        for (linha = 0; linha < 9; linha++) {
            for (coluna = 0; coluna < 9; coluna++) {
                if (sudoku[linha][coluna]==0) {
                    o++;
                }
            }
        }

// O printf da matriz 9x9 ainda esta sendo repetido em todo o while, para vermos
//como o programa esta funcionando
        for (linha = 0; linha < 9; linha++) {
            for (coluna = 0; coluna < 9; coluna++) {
                printf("%d ", sudoku[linha][coluna]);
            }
            printf("\n");
        }

    }

    return 0;
}
