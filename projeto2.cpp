#include <omp.h>
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;


void paralelo(int linha, int coluna){
  int matrizA[linha][coluna];
  int matrizB[linha][coluna];
  int matrizResultado[linha][coluna];
  int limite = 50;
  int loop = 10000;
  double tempo_final = 0.0;
  clock_t inicio, fim;
  srand(time(NULL));

  //Preenche a matriz com numeros aleatórios
  for(int i = 0; i < linha; i++){
    for(int j = 0; j < coluna; j++){
      matrizA[i][j] = rand() % limite;
      matrizB[i][j] = rand() % limite;
    }
  }

  //Começa a calcular o tempo daqui:
  inicio = time(NULL);
  #pragma omp parallel
    for(int k = 0; k < loop; k++){
      for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
          matrizResultado[i][j] = matrizA[i][j] * matrizB[i][j];
        }
      }
    }
  fim = time(NULL);

  tempo_final = difftime(fim, inicio);

  cout << "Tempo total em paralelo: " <<  tempo_final << endl;

}

void sequencial(int linha, int coluna){
  int matrizA[linha][coluna];
  int matrizB[linha][coluna];
  int matrizResultado[linha][coluna];
  int limite = 50;
  int loop = 10000;
  int tempo_final = 0;
  clock_t inicio, fim;
  srand(time(NULL));

  for(int i = 0; i < linha; i++){
    for(int j = 0; j < coluna; j++){
      matrizA[i][j] = rand() % limite;
      matrizB[i][j] = rand() % limite;
    }
  }

  //Começa a calcular o tempo daqui:
  inicio = time(NULL);
  for(int k = 0; k < loop; k++)
    for(int i = 0; i < linha; i++){
      for(int j = 0; j < coluna; j++){
        matrizResultado[i][j] = matrizA[i][j] * matrizB[i][j];
      }
    }
  fim = time(NULL);

  tempo_final = difftime(fim, inicio);

  cout << "Tempo total sequencial: " << tempo_final << "\n";

}


int main(){

     //Teste 1
    cout << "Teste 1: " << "\n";
    paralelo(100, 100);
    sequencial(100, 100);

    //Teste 2
    cout << "Teste 2: " << "\n";
    paralelo(200, 200);
    sequencial(200, 200);

    // Teste 3
    cout << "Teste 3: " << "\n";
    paralelo(400, 400);
    sequencial(400, 400);

    // Teste 4
    cout << "Teste 4: " << "\n";
    paralelo(500, 500);
    sequencial(500, 500);

    // Teste 5
    cout << "Teste 5: " << "\n";
    paralelo(100, 500);
    sequencial(100, 500);

    // Teste 6
    cout << "Teste 6: " << "\n";
    paralelo(1, 1);
    sequencial(1, 1);

    return 0;
}
