#include <iostream>
#include "instrucoes.hpp"
#include <cstdlib>
#include <ctime>
#include <string>
#include <chrono>

using namespace std;

int main() {
    auto inicio=chrono::high_resolution_clock::now();
    char** matriz;
    ifstream input;
    ofstream output;
    ofstream output2;
    int rows, cols , num_matriz;
   
    

    input.open("dataset/input.data",std::ios::in);
    if(!input){
        cout<<"Não foi possível abrir o arquivo!";
        return 0;
    }

     input >> rows >> cols >> num_matriz; // lê as dimensões da matriz
    matriz = new char*[rows]; // aloca um array de ponteiros
    for (int i = 0; i < rows; i++) {
        matriz[i] = new char[cols]; // aloca um array para cada linha
    }
   

    for(int x=0;x<num_matriz;x++){
       
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                input >> matriz[i][j];
            }
        }
        input.close();

        output.open("dataset/matrizSalva"+to_string(x)+".data");
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                output<<matriz[i][j] << " ";
            }
           output<<endl;
        }
        output2.open("dataset/conferePasso"+to_string(x)+".data");
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                output2<< '0'<< " ";
            }
           output2<<endl;
        }
        output.close();
        output2.close();

         
    }
    
    Caminhar(rows,cols,num_matriz);


    for(int x=0;x<num_matriz;x++){

        input.open("dataset/conferePasso"+to_string(x)+".data");
        int n_andou=0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                input>>matriz[i][j];
            }
        }

        input.close();

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(matriz[i][j]=='0'){
                    n_andou+=1;
                }
            }
           
        }

        cout<<"O seu viajante não visitou "<< n_andou << " casa(s) da matriz "<< x<<endl;
        

    }

    for (int i = 0; i < rows; i++) {
            delete[] matriz[i];
    }
    delete[] matriz;

    auto fim=chrono::high_resolution_clock::now();
    auto total=chrono::duration_cast<chrono::microseconds>(fim-inicio);

    cout<<" O tempo de execução foi de "<< total.count();
    cout<<" microsegundos."<<endl;
    return 0;
}
