#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;

int main(){
  int n = 500;
  int matrizA[n][n];
  int matrizB[n][n];
  int matrizResultado[n][n];
  int limite = 50;
  clock_t inicio, inicio_trocado, fim, fim_trocado;
  srand(time(NULL));

  //Preenche a matriz com numeros aleatórios
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      matrizA[i][j] = rand() % limite;
      matrizB[i][j] = rand() % limite;
    }
  }

  //Começa a calcular o tempo daqui:
  inicio = clock();
<<<<<<< HEAD
  for(int k = 0; k < 100; k++)
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        matrizResultado[i][j] = matrizA[i][j] * matrizB[i][j];
      }
    }
  fim = clock();

  inicio_trocado = clock();
  for(int k = 0; k < 100; k++)
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        matrizResultado[i][j] = matrizA[j][i] * matrizB[j][i];
      }
    }
=======
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      matrizResultado[i][j] = matrizA[i][j] * matrizB[i][j];
    }
  }
  fim = clock();

  inicio_trocado = clock();
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      matrizResultado[i][j] = matrizA[j][i] * matrizB[j][i];
    }
  }
>>>>>>> 73f373704ac4cf284888e7df0f3d50c1a91cf901
  fim_trocado = clock();

  cout << "Tempo total: " << fim - inicio << "\n";
  cout << "Tempo total com I e J trocados: " << fim_trocado - inicio_trocado << "\n";

  return 0;
}
