

#include <math.h>
#include <stdio.h>

int indice_l, indice_c;
int matrix[41][41];
int matrix2[41][41];


//Cria a base para as matrizes finais
void desenha_quadrado_xis() {
  for (indice_l =0; indice_l < 41; indice_l++) {
    for (indice_c =0; indice_c < 41; indice_c++) {
      if (indice_c == indice_l)
        matrix[indice_l][indice_c] = 0;
      else {
        if ((indice_c + indice_l) == 40)
          matrix[indice_l][indice_c] = 0;
        else
          matrix[indice_l][indice_c] = 1;
      }
    }
  }
}

//Cria telhado da casa
void desenha_triangulo_casa() {
  int arco = 0;
  indice_c = 20;
  for (indice_l = 15; indice_l < 35; indice_l++) {
    //for (indice_c = 10; indice_c < 40; indice_c++) {
    if (indice_l == 15) {
        matrix2[indice_l][indice_c] = 1;
        arco++;
      } else {
        matrix2[indice_l][indice_c+arco] = 1;
        matrix2[indice_l][indice_c-arco] = 1;
        arco++;
    }
  }
}


//Cria parede da casa
void desenha_parede_casa() {
  for (indice_l = 35; indice_l < 41; indice_l++) {
    for (indice_c = 2; indice_c < 39; indice_c++) {
      matrix2[indice_l][indice_c] = 1;
    }
  }
}


//  Soma a matriz base com a matriz 1 para formar o X
void somatorio_matrix() {
  int somatorio = 0;
  for (indice_l = 0; indice_l < 41; indice_l++) {
    for (indice_c = 0; indice_c < 41; indice_c++) {
      somatorio = somatorio + matrix[indice_l][indice_c];
      if (matrix[indice_l][indice_c] > 0)
        printf("%d ", matrix[indice_l][indice_c]);
        if (matrix[indice_l][indice_c] == 0)
        printf("0");
      else
        printf("");
    }
    printf("\n");
  }

}

// Soma a matriz base com as demais matrizes que tiveram a matriz 2 como base para desenhar a casa

void somatorio_matrix2() {
  int somatorio = 0;
  for (indice_l = 0; indice_l < 41; indice_l++) {
    for (indice_c = 0; indice_c < 41; indice_c++) {
      somatorio = somatorio + matrix2[indice_l][indice_c];
      if (matrix2[indice_l][indice_c] > 0)
        printf("%d ", matrix2[indice_l][indice_c]);
      else
        printf(" .");
    }
    printf("\n");
  }

}

// Função main para chamar as demais funções

int main(void) {
  desenha_quadrado_xis();
  desenha_parede_casa();
  desenha_triangulo_casa();
  somatorio_matrix();
  somatorio_matrix2();
  return 0;
}