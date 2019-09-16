#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;


void paralelo(int linha, int coluna){
  int matrizA[linha][coluna];
  int matrizB[linha][coluna];
  int matrizResultado[linha][coluna];
  int limite = 50;
  clock_t inicio, inicio_trocado, fim, fim_trocado;
  srand(time(NULL));

  //Preenche a matriz com numeros aleatórios
  for(int i = 0; i < linha; i++){
    for(int j = 0; j < coluna; j++){
      matrizA[i][j] = rand() % limite;
      matrizB[i][j] = rand() % limite;
    }
  }

  //Começa a calcular o tempo daqui:
  inicio = clock();
  #pragma omp parallel for num_threads(4)
    for(int k = 0; k < 1000; k++)
      for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
          matrizResultado[i][j] = matrizA[i][j] * matrizB[i][j];
        }
      }
  fim = clock();

  inicio_trocado = clock();
  #pragma omp parallel for num_threads(4)
    for(int k = 0; k < 1000; k++)
      for(int j = 0; j < coluna; j++){
        for(int i = 0; i < linha; i++){
          matrizResultado[i][j] = matrizA[i][j] * matrizB[i][j];
        }
      }
  fim_trocado = clock();

  cout << "Tempo total em paralelo: " << fim - inicio << "\n";
  cout << "Tempo total em paralelo com I e J trocados: " << fim_trocado - inicio_trocado << "\n";

}



int main(){

     //Teste 1
    cout << "Teste 1: " << "\n";
    paralelo(100, 100);

    //Teste 2
    cout << "Teste 2: " << "\n";
    paralelo(200,200);

    // Teste 3
    cout << "Teste 3: " << "\n";
    paralelo(400, 400);

    // Teste 4
    cout << "Teste 4: " << "\n";
    paralelo(500, 500);

    // Teste 5
    cout << "Teste 5: " << "\n";
    paralelo(100, 500);

    return 0;
}
