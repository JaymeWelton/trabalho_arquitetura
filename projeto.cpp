#include <omp.h>
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int main(){
  int n = 300;
  int matrizA[n][n];
  int matrizB[n][n];
  int matrizResultado[n][n];
  int limite = 50;
  int loop = 10000;
  double tempo_final = 0.0;
  double tempo_final_trocado = 0.0; 
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
  inicio = time(NULL);
  for(int k = 0; k < loop; k++)
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        matrizResultado[i][j] = matrizA[i][j] * matrizB[i][j];
      }
    }
  fim = time(NULL);

  inicio_trocado = time(NULL);
  for(int k = 0; k < loop; k++)
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        matrizResultado[i][j] = matrizA[j][i] * matrizB[j][i];
      }
    }
  fim_trocado = time(NULL);
  
  tempo_final = difftime(fim, inicio);
  tempo_final_trocado = difftime(fim_trocado, inicio_trocado);
  
  cout << "Tempo total: " << tempo_final << "\n";
  cout << "Tempo total com I e J trocados: " << fim_trocado - inicio_trocado << "\n";

  return 0;
}
