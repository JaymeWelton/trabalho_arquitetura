#include <omp.h>
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

void sequencial(int linha, int coluna){
  int matrizA[linha][coluna];
  int matrizB[linha][coluna];
  int matrizResultado[linha][coluna];
  int limite = 50;
  int loop = 10000;
  double tempo_final = 0;
  double tempo_final_trocado = 0;
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
  inicio = time(NULL);
  for(int k = 0; k < loop; k++)
    for(int i = 0; i < linha; i++){
      for(int j = 0; j < coluna; j++){
        matrizResultado[i][j] = matrizA[i][j] * matrizB[i][j];
      }
    }
  fim = time(NULL);

  inicio_trocado = time(NULL);
  for(int k = 0; k < loop; k++)
    for(int i = 0; i < linha; i++){
      for(int j = 0; j < coluna; j++){
        matrizResultado[j][i] = matrizA[j][i] * matrizB[j][i];
      }
    }
  fim_trocado = time(NULL);

  tempo_final = difftime(fim, inicio);
  tempo_final_trocado = difftime(fim_trocado, inicio_trocado);

  cout << "Tempo total sequencial: " << tempo_final << "\n";
  cout << "Tempo total com I e J trocados sequencial: " << tempo_final_trocado << "\n";

}

void paralelo(int linha, int coluna){
  int matrizA[linha][coluna];
  int matrizB[linha][coluna];
  int matrizResultado[linha][coluna];
  int limite = 50;
  int loop = 10000;
  int tempo_final = 0;
  int tempo_final_trocado = 0;
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
  inicio = time(NULL);
  #pragma omp parallel for num_threads(4)
    for(int k = 0; k < loop; k++)
      for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
          matrizResultado[i][j] = matrizA[i][j] * matrizB[i][j];
        }
      }
  fim = time(NULL);

  inicio_trocado = time(NULL);
  #pragma omp parallel for num_threads(4)
    for(int k = 0; k < loop; k++)
      for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
          matrizResultado[j][i] = matrizA[j][i] * matrizB[j][i];
        }
      }
  fim_trocado = time(NULL);

  tempo_final = difftime(fim, inicio);
  tempo_final_trocado = difftime(fim_trocado, inicio_trocado);

  cout << "Tempo total paralelo: " << tempo_final << endl;
  cout << "Tempo total com I e J trocados paralelo: " << tempo_final_trocado << endl;
}

int main(){
  //Teste 1
 cout << "Teste 1: " << endl;
 paralelo(100, 100);
 sequencial(100, 100);

 //Teste 2
 cout << "Teste 2: " << endl;
 paralelo(200, 200);
 sequencial(200, 200);

 // Teste 3
 cout << "Teste 3: " << endl;
 paralelo(400, 400);
 sequencial(400, 400);

 // Teste 4
 cout << "Teste 4: " << endl;
 paralelo(500, 500);
 sequencial(500, 500);

 // Teste 5
 cout << "Teste 5: " << endl;
 paralelo(420, 420);
 sequencial(420, 420);

 // Teste 6
 cout << "Teste 6: " << endl;
 paralelo(1, 1);
 sequencial(1, 1);

 // Teste 7
 cout << "Teste 7: " << endl;
 paralelo(600, 600);
 sequencial(600, 600);

  return 0;
}
