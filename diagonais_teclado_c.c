

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

//Cria monitor
void desenha_monitor() {
  for (indice_l = 10; indice_l < 25; indice_l++) {
    for (indice_c = 2; indice_c < 39; indice_c++) {
      matrix2[indice_l][indice_c] = 8;
    }
  }
}

//Cria teclado
void desenha_teclado() {
  for (indice_l = 28; indice_l < 37; indice_l++) {
    for (indice_c = 3; indice_c < 30; indice_c++) {
      matrix2[indice_l][indice_c] = 1;
    }
  }
}

// Cria mouse
void desenha_mouse() {
  for (indice_l = 30; indice_l < 35; indice_l++) {
    for (indice_c = 35; indice_c < 39; indice_c++) {
      matrix2[indice_l][indice_c] = 7;
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


// Soma a matriz base com as demais matrizes que tiveram a matriz 2 como base para desenhar o setup de PC
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
  desenha_monitor();
  desenha_teclado();
  desenha_mouse();
  somatorio_matrix();
  somatorio_matrix2();
  return 0;
}