#include "instrucoes.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
void Caminhar(int rows,int cols, int num_matriz){
    char** matriz;
    char** matrizConferePasso;
    int k,j, vida, sacolaGeral, sacolaJogo,N,TotalPosicoes,perigo;
    N=rows;
    vida=10;
    sacolaGeral=0;
    sacolaJogo=0;
    TotalPosicoes=0;
    perigo=0;

    //declara o arquivo de leitura
    ifstream input;

    //alocando as matrizes pra iniciar o trabalho
    matriz = new char*[rows]; // aloca um array de ponteiros
    for (int i = 0; i < rows; i++) {
        matriz[i] = new char[cols]; // aloca um array para cada linha
    }
   matrizConferePasso = new char*[rows]; // aloca um array de ponteiros
    for (int i = 0; i < rows; i++) {
        matrizConferePasso[i] = new char[cols]; // aloca um array para cada linha
    }


    //tem que ler a primeira matriz fora do laço de repetição
    input.open("dataset/matrizSalva0.data",std::ios::in);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            input>>matriz[i][j];
        }
    }
    //pronto, leu a matriz de trabalhar, ent fecha
    input.close();

    //agr abre dnv pra ler a outra matriz
    input.open("dataset/conferePasso0.data",std::ios::in);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            input>>matrizConferePasso[i][j];
        }
    }
    input.close();

    k=0;
    j=0;
    int aux=0;

    if(matriz[k][j]=='#'){
        matrizConferePasso[k][j]='1';
        TotalPosicoes+=1;
    }else if(matriz[k][j]=='*'){
        vida=vida-1;
        matrizConferePasso[k][j]='1';
        TotalPosicoes+=1;
        perigo+=1;
    }else{
        if(matriz[k][j]=='0'){
            matrizConferePasso[k][j]='1';
            TotalPosicoes+=1;
        }else{
            int numero=0;
            char num[2];
            numero = stoi(string(1, matriz[k][j]));
            numero = numero-1;
            sprintf(num, "%d", numero);
            matriz[k][j]= num[0];
            sacolaGeral=sacolaGeral+1;
            sacolaJogo=sacolaJogo+1;
            matrizConferePasso[k][j]='1';
            TotalPosicoes+=1;
        }
    }

            

    do{
       if(k==0 && j==0){ //primeira linha e primeira coluna
            if(vida==0){
                cout<< "Você perdeu e tem 0 vidas."<<endl;
                break;
            }else{
               if(sacolaJogo==4){
                     if(vida==10){
                        sacolaJogo=0;
                        Caminho0(matriz,matrizConferePasso,&k,&j,&vida,&sacolaGeral,&sacolaJogo,&TotalPosicoes,&perigo);
                     }else{
                        vida=vida+1;
                        sacolaJogo=0;
                        Caminho0(matriz,matrizConferePasso,&k,&j,&vida,&sacolaGeral,&sacolaJogo,&TotalPosicoes,&perigo);
                     }
                }else{
                    Caminho0(matriz,matrizConferePasso,&k,&j,&vida,&sacolaGeral,&sacolaJogo,&TotalPosicoes,&perigo);
                }
                
            }


        }else if((j==(N-1) && k==(N-1)) || TotalPosicoes%20==0){ // ultima linha e ultima coluna
            ofstream output;
            output.open("dataset/matrizSalva"+to_string(aux)+".data");
        
            for(int i=0; i<rows; i++){
                for(int j=0; j<cols; j++){
                    output<<matriz[i][j] << " ";
            }
                output<<endl;
            }
            output.close();

            output.open("dataset/conferePasso"+to_string(aux)+".data");
            for(int i=0; i<rows; i++){
                for(int j=0; j<cols; j++){
                    output<< matrizConferePasso[i][j]<< " ";
            }
                output<<endl;
            }
            output.close();

            aux++;
            if(aux==num_matriz){
                aux=0;
            }

           

            input.open("dataset/matrizSalva"+to_string(aux)+".data",std::ios::in);
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    input>>matriz[i][j];
                }
            }
            //pronto, leu a matriz de trabalhar, ent fecha
            input.close();

            //agr abre dnv pra ler a outra matriz
            input.open("dataset/conferePasso"+to_string(aux)+".data",std::ios::in);
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    input>>matrizConferePasso[i][j];
                }
            }
            input.close();
            
            TotalPosicoes=TotalPosicoes+1;
            srand(time(nullptr)); 
            k = rand() % rows ;

            srand(time(nullptr)); 
            j = rand() % cols ;

            if(aux==0 && k==0 && j==0 && sacolaGeral==0){
                cout<<"Você GANHOOOU!!!!"<<endl;
                break;
            }


        }else if(k==(N-1) && j==0){// ultima linha e primeira coluna
            if(vida==0){
                cout<< "Você perdeu e tem 0 vidas."<<endl;
                break;
            }else{
                if(sacolaJogo==4){
                     if(vida==10){
                        sacolaJogo=0;
                        Caminho1(matriz,matrizConferePasso,&k,&j,&vida,&sacolaGeral,&sacolaJogo,&TotalPosicoes,&perigo);
                     }else{
                        vida=vida+1;
                        sacolaJogo=0;
                        Caminho1(matriz,matrizConferePasso,&k,&j,&vida,&sacolaGeral,&sacolaJogo,&TotalPosicoes,&perigo);
                     }
                }else{
                    Caminho1(matriz,matrizConferePasso,&k,&j,&vida,&sacolaGeral,&sacolaJogo,&TotalPosicoes,&perigo);
                }
                
            }
        }
        else if(j==0){ // qualquer linha e primeira coluna
            if(vida==0){
                cout<< "Você perdeu e tem 0 vidas."<<endl;
                break;
            }else{
                if(sacolaJogo==4){
                     if(vida==10){
                        sacolaJogo=0;
                        Caminho2(matriz,matrizConferePasso,&k,&j,&vida,&sacolaGeral,&sacolaJogo,&TotalPosicoes,&perigo);
                     }else{
                        vida=vida+1;
                        sacolaJogo=0;
                        Caminho2(matriz,matrizConferePasso,&k,&j,&vida,&sacolaGeral,&sacolaJogo,&TotalPosicoes,&perigo);
                     }
                }else{
                    Caminho2(matriz,matrizConferePasso,&k,&j,&vida,&sacolaGeral,&sacolaJogo,&TotalPosicoes,&perigo);
                }
                
            }
        }
        else if(j==(N-1) && k==0){ // primeira linha e ultima coluna
           if(vida==0){
                cout<< "Você perdeu e tem 0 vidas."<<endl;
                break;
            }else{
                if(sacolaJogo==4){
                     if(vida==10){
                        sacolaJogo=0;
                        Caminho3(matriz,matrizConferePasso,&k,&j,&vida,&sacolaGeral,&sacolaJogo,&TotalPosicoes,&perigo);
                     }else{
                        vida=vida+1;
                        sacolaJogo=0;
                        Caminho3(matriz,matrizConferePasso,&k,&j,&vida,&sacolaGeral,&sacolaJogo,&TotalPosicoes,&perigo);
                     }
                }else{
                    Caminho3(matriz,matrizConferePasso,&k,&j,&vida,&sacolaGeral,&sacolaJogo,&TotalPosicoes,&perigo);
                }
                
            }
        }else if(j==(N-1)){ // ultima coluna e qualquer linha
            if(vida==0){
                cout<< "Você perdeu e tem 0 vidas."<<endl;
                break;
            }else{
                if(sacolaJogo==4){
                     if(vida==10){
                        sacolaJogo=0;
                        Caminho4(matriz,matrizConferePasso,&k,&j,&vida,&sacolaGeral,&sacolaJogo,&TotalPosicoes,&perigo);
                     }else{
                        vida=vida+1;
                        sacolaJogo=0;
                        Caminho4(matriz,matrizConferePasso,&k,&j,&vida,&sacolaGeral,&sacolaJogo,&TotalPosicoes,&perigo);
                     }
                }else{
                    Caminho4(matriz,matrizConferePasso,&k,&j,&vida,&sacolaGeral,&sacolaJogo,&TotalPosicoes,&perigo);
                }
                
            }
        }else if(k==(N-1)){ // ultima linha e qualquer coluna
            if(vida==0){
                cout<< "Você perdeu e tem 0 vidas."<<endl;
                break;
            }else{
                if(sacolaJogo==4){
                     if(vida==10){
                        sacolaJogo=0;
                        Caminho5(matriz,matrizConferePasso,&k,&j,&vida,&sacolaGeral,&sacolaJogo,&TotalPosicoes,&perigo);
                     }else{
                        vida=vida+1;
                        sacolaJogo=0;
                        Caminho5(matriz,matrizConferePasso,&k,&j,&vida,&sacolaGeral,&sacolaJogo,&TotalPosicoes,&perigo);
                     }
                }else{
                    Caminho5(matriz,matrizConferePasso,&k,&j,&vida,&sacolaGeral,&sacolaJogo,&TotalPosicoes,&perigo);
                }
                
            }
        }else if(k==0){//primeira linha e qualquer coluna
            if(vida==0){
                cout<< "Você perdeu e tem 0 vidas."<<endl;
                break;
            }else{
                if(sacolaJogo==4){
                     if(vida==10){
                        sacolaJogo=0;
                        Caminho6(matriz,matrizConferePasso,&k,&j,&vida,&sacolaGeral,&sacolaJogo,&TotalPosicoes,&perigo);
                     }else{
                        vida=vida+1;
                        sacolaJogo=0;
                        Caminho6(matriz,matrizConferePasso,&k,&j,&vida,&sacolaGeral,&sacolaJogo,&TotalPosicoes,&perigo);
                     }
                }else{
                    Caminho6(matriz,matrizConferePasso,&k,&j,&vida,&sacolaGeral,&sacolaJogo,&TotalPosicoes,&perigo);
                }
                
            }
        }else{ //qualquer linha e qualquer coluna
            if(vida==0){
                cout<< "Você perdeu e tem 0 vidas."<<endl;
                break;
            }else{
                if(sacolaJogo==4){
                     if(vida==10){
                        sacolaJogo=0;
                        Caminho7(matriz,matrizConferePasso,&k,&j,&vida,&sacolaGeral,&sacolaJogo,&TotalPosicoes,&perigo);
                     }else{
                        vida=vida+1;
                        sacolaJogo=0;
                        Caminho7(matriz,matrizConferePasso,&k,&j,&vida,&sacolaGeral,&sacolaJogo,&TotalPosicoes,&perigo);
                     }
                }else{
                    Caminho7(matriz,matrizConferePasso,&k,&j,&vida,&sacolaGeral,&sacolaJogo,&TotalPosicoes,&perigo);
                } 
            }
        }

    }while(true);

    cout<<"O seu viajante andou o total de "<<TotalPosicoes<<" posições"<<endl;
    cout<<"O seu viajante coletou "<<sacolaGeral<<" item(s)"<<endl;
    cout<< "O seu viajante foi muito corajoso e enfrentou "<< perigo<< " perigo(s)"<<endl;

    ofstream output;
    output.open("dataset/matrizSalva"+to_string(aux)+".data");
        
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            output<<matriz[i][j] << " ";
        }
            output<<endl;
    }
    output.close();

    output.open("dataset/conferePasso"+to_string(aux)+".data");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            output<< matrizConferePasso[i][j]<< " ";
        }
            output<<endl;
    }
    output.close();

    
}
// para direita
// para baixo
// para diagonal inferior direita
// para esquerda
// para diagonal inferior esquerda
// para cima
// para diagonal superior direita
// para diagonal superior esquerda 
void Caminho0(char** matriz, char** matrizConferePasso,int *k,int* j,int* vida,int* sacolaGeral, int* sacolaJogo, int* TotalPosicoes, int* perigo){ // direita, baixo, diagonal inferior direita
    std::srand(std::time(nullptr)); // inicializa a semente
    int num_aleatorio = std::rand() % 3 ; // gera um número aleatório entre 0 e 2

    while(true){

        if(num_aleatorio==0){
            //andando para direita
            if(matriz[*k][*j+1]=='#'){
                num_aleatorio = rand() % 2 + 1;
                continue;
                matrizConferePasso[*k][*j+1]='1';
                *TotalPosicoes+=1;
            }
            else if(matriz[*k][*j+1]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k][*j+1]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *j=*j+1;
                break;
            }else{
                if(matriz[*k][*j+1]=='0'){
                    matrizConferePasso[*k][*j+1]='1';
                    *TotalPosicoes+=1;
                    *j=*j+1;
                    break;
                }else{
                    int numero=0;
                    char num[2];
                    numero = stoi(string(1, matriz[*k][*j+1]));
                    numero = numero-1;
                    sprintf(num, "%d", numero);
                    matriz[*k][*j+1]= num[0];
                    *sacolaGeral=*sacolaGeral+1;
                    *sacolaJogo=*sacolaJogo+1;
                    matrizConferePasso[*k][*j+1]='1';
                    *TotalPosicoes+=1;
                    *j=*j+1;
                    break;
                }
            }

        }
        else if(num_aleatorio==1){
            //andando para baixo
            if(matriz[*k+1][*j]=='#'){
                do{
                    num_aleatorio=rand()%3;
                }while(num_aleatorio==1);
                matrizConferePasso[*k+1][*j]='1';
                *TotalPosicoes+=1;
                continue;
            }else if(matriz[*k+1][*j]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k+1][*j]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *k=*k+1;
                break;
            }else {
                if(matriz[*k+1][*j]=='0'){
                    matrizConferePasso[*k+1][*j]='1';
                    *TotalPosicoes+=1;
                    *k=*k+1;
                    break;
                }else{
                int numero=0;
                char num[2];
                numero = stoi(string(1, matriz[*k+1][*j]));
                numero = numero-1;
                sprintf(num, "%d", numero);
                matriz[*k+1][*j]= num[0];
                *sacolaGeral=*sacolaGeral+1;
                *sacolaJogo=*sacolaJogo+1;
                matrizConferePasso[*k+1][*j]='1';
                *TotalPosicoes+=1;
                *k=*k+1;
                break;
                }
            }
        }
        else if(num_aleatorio==2){
            // andando para a diagonal inferior direita
           if(matriz[*k+1][*j+1]=='#'){
                do{
                    num_aleatorio=rand()%3;
                }while(num_aleatorio==2);
                matrizConferePasso[*k+1][*j+1]='1';
                *TotalPosicoes+=1;
                continue;
           }else if(matriz[*k+1][*j+1]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k+1][*j+1]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *k=*k+1;
                *j=*j+1;
                break;
           }else{
             if(matriz[*k+1][*j+1]=='0'){
                    matrizConferePasso[*k+1][*j+1]='1';
                    *TotalPosicoes+=1;
                    *j=*j+1;
                    *k=*k+1;
                    break;
                }else{
                    int numero=0;
                    char num[2];
                    numero = stoi(string(1, matriz[*k+1][*j+1]));
                    numero = numero-1;
                    sprintf(num, "%d", numero);
                    matriz[*k+1][*j+1]= num[0];
                    *sacolaGeral=*sacolaGeral+1;
                    *sacolaJogo=*sacolaJogo+1;
                    matrizConferePasso[*k+1][*j+1]='1';
                    *TotalPosicoes+=1;
                    *k=*k+1;
                    *j=*j+1;
                    break;
                }
           }
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Caminho1(char** matriz,char** matrizConferePasso, int *k,int* j,int* vida,int* sacolaGeral, int* sacolaJogo, int* TotalPosicoes, int* perigo){//cima, direita,diagonal superior direita
    srand(time(nullptr)); 
    int num_aleatorio = rand() % 3 ;

    while(true){
        if(num_aleatorio==0){ // andando para direita
            if(matriz[*k][*j+1]=='#'){
                num_aleatorio = rand() % 2 + 1;
                matrizConferePasso[*k][*j+1]='1';
                *TotalPosicoes+=1;
                continue;
            }
            else if(matriz[*k][*j+1]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k][*j+1]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *j=*j+1;
                break;
            }else{
                if(matriz[*k][*j+1]=='0'){
                    matrizConferePasso[*k][*j+1]='1';
                    *TotalPosicoes+=1;
                    *j=*j+1;
                    break;
                }else{
                    int numero=0;
                    char num[2];
                    numero = stoi(string(1, matriz[*k][*j+1]));
                    numero = numero-1;
                    sprintf(num, "%d", numero);
                    matriz[*k][*j+1]= num[0];
                    *sacolaGeral=*sacolaGeral+1;
                    *sacolaJogo=*sacolaJogo+1;
                    matrizConferePasso[*k][*j+1]='1';
                    *TotalPosicoes+=1;
                    *j=*j+1;
                    break;
                }
            }
        }else if(num_aleatorio==1){ //andando para cima
            if(matriz[*k-1][*j]=='#'){
                do{
                    num_aleatorio=rand()%3;
                }while(num_aleatorio==1);
                matrizConferePasso[*k-1][*j]='1';
                *TotalPosicoes+=1;
                continue;
            }
            else if(matriz[*k-1][*j]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k-1][*j]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *k=*k-1;
                break;
            }else{
                if(matriz[*k-1][*j]=='0'){
                    *TotalPosicoes+=1;
                    matrizConferePasso[*k-1][*j]='1';
                    *k=*k-1;
                    break;
                }else{
                    int numero=0;
                    char num[2];
                    numero = stoi(string(1, matriz[*k-1][*j]));
                    numero = numero-1;
                    sprintf(num, "%d", numero);
                    matriz[*k-1][*j]= num[0];
                    *sacolaGeral=*sacolaGeral+1;
                    *sacolaJogo=*sacolaJogo+1;
                    matrizConferePasso[*k-1][*j]='1';
                    *TotalPosicoes+=1;
                    *k=*k-1;
                    break;
                }
            }
        }else if(num_aleatorio==2){ //andando para a diagonal superior direita
             if(matriz[*k-1][*j+1]=='#'){
                do{
                    num_aleatorio=rand()%3;
                }while(num_aleatorio==2);
                matrizConferePasso[*k-1][*j+1]='1';
                *TotalPosicoes+=1;
                continue;
           }else if(matriz[*k-1][*j+1]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k-1][*j+1]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *k=*k-1;
                *j=*j+1;
                break;
           }else{
                if(matriz[*k-1][*j+1]=='0'){
                    matrizConferePasso[*k-1][*j+1]='1';
                    *TotalPosicoes+=1;
                    *j=*j+1;
                    *k=*k-1;
                    break;
                }else{
                    int numero=0;
                    char num[2];
                    numero = stoi(string(1, matriz[*k-1][*j+1]));
                    numero = numero-1;
                    sprintf(num, "%d", numero);
                    matriz[*k-1][*j+1]= num[0];
                    *sacolaGeral=*sacolaGeral+1;
                    *sacolaJogo=*sacolaJogo+1;
                    matrizConferePasso[*k-1][*j+1]='1';
                    *TotalPosicoes+=1;
                    *k=*k-1;
                    *j=*j+1;
                    break;
                }
           }
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Caminho2(char** matriz,char** matrizConferePasso, int *k,int* j,int* vida,int* sacolaGeral, int* sacolaJogo, int* TotalPosicoes, int* perigo){
    srand(time(nullptr)); 
    int num_aleatorio = rand() % 5;

    while(true){
        if(num_aleatorio==0){ // andando para direita
            if(matriz[*k][*j+1]=='#'){
                do{
                    num_aleatorio=rand()%5;
                }while(num_aleatorio==0);
                matrizConferePasso[*k][*j+1]='1';
                *TotalPosicoes+=1;
                continue;
            }
            else if(matriz[*k][*j+1]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k][*j+1]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *j=*j+1;
                break;
            }else{
                if(matriz[*k][*j+1]=='0'){
                    matrizConferePasso[*k][*j+1]='1';
                    *TotalPosicoes+=1;
                    *j=*j+1;
                    break;
                }else{
                    int numero=0;
                    char num[2];
                    numero = stoi(string(1, matriz[*k][*j+1]));
                    numero = numero-1;
                    sprintf(num, "%d", numero);
                    matriz[*k][*j+1]= num[0];
                    *sacolaGeral=*sacolaGeral+1;
                    *sacolaJogo=*sacolaJogo+1;
                    matrizConferePasso[*k][*j+1]='1';
                    *TotalPosicoes+=1;
                    *j=*j+1;
                    break;
                }
            }
        }else if(num_aleatorio==1){ //andando para cima
            if(matriz[*k-1][*j]=='#'){
                do{
                    num_aleatorio=rand()%5;
                }while(num_aleatorio==1);
                matrizConferePasso[*k-1][*j]='1';
                *TotalPosicoes+=1;
                continue;
            }
            else if(matriz[*k-1][*j]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k-1][*j]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *k=*k-1;
                break;
            }else{
                if(matriz[*k-1][*j]=='0'){
                    matrizConferePasso[*k-1][*j]='1';
                    *TotalPosicoes+=1;
                    *k=*k-1;
                    break;
                }else{
                    int numero=0;
                    char num[2];
                    numero = stoi(string(1, matriz[*k-1][*j]));
                    numero = numero-1;
                    sprintf(num, "%d", numero);
                    matriz[*k-1][*j]= num[0];
                    *sacolaGeral=*sacolaGeral+1;
                    *sacolaJogo=*sacolaJogo+1;
                    matrizConferePasso[*k-1][*j]='1';
                    *TotalPosicoes+=1;
                    *k=*k-1;
                    break;
                }
            }
        }else if(num_aleatorio==2){ //andando para a diagonal superior direita
             if(matriz[*k-1][*j+1]=='#'){
                do{
                    num_aleatorio=rand()%5;
                }while(num_aleatorio==2);
                *TotalPosicoes+=1;
                matrizConferePasso[*k-1][*j+1]='1';
                continue;
           }else if(matriz[*k-1][*j+1]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k-1][*j+1]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *k=*k-1;
                *j=*j+1;
                break;
           }else{
                if(matriz[*k-1][*j+1]=='0'){
                    matrizConferePasso[*k-1][*j+1]='1';
                    *TotalPosicoes+=1;
                    *j=*j+1;
                    *k=*k-1;
                    break;
                }else{
                    int numero=0;
                    char num[2];
                    numero = stoi(string(1, matriz[*k-1][*j+1]));
                    numero = numero-1;
                    sprintf(num, "%d", numero);
                    matriz[*k-1][*j+1]= num[0];
                    *sacolaGeral=*sacolaGeral+1;
                    *sacolaJogo=*sacolaJogo+1;
                    matrizConferePasso[*k-1][*j+1]='1';
                    *TotalPosicoes+=1;
                    *k=*k-1;
                    *j=*j+1;
                    break;
                }
           }
        }else if(num_aleatorio==3){ //andando para baixo
            if(matriz[*k+1][*j]=='#'){
                do{
                    num_aleatorio=rand()%5;
                }while(num_aleatorio==3);
                matrizConferePasso[*k+1][*j]='1';
                *TotalPosicoes+=1;
                continue;
            }else if(matriz[*k+1][*j]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k+1][*j]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *k=*k+1;
                break;
            }else {
                if(matriz[*k+1][*j]=='0'){
                    matrizConferePasso[*k+1][*j]='1';
                    *TotalPosicoes+=1;
                    *k=*k+1;
                    break;
                }else{
                int numero=0;
                char num[2];
                numero = stoi(string(1, matriz[*k+1][*j]));
                numero = numero-1;
                sprintf(num, "%d", numero);
                matriz[*k+1][*j]= num[0];
                *sacolaGeral=*sacolaGeral+1;
                *sacolaJogo=*sacolaJogo+1;
                matrizConferePasso[*k+1][*j]='1';
                *TotalPosicoes+=1;
                *k=*k+1;
                break;
                }
            }
        }
        else if(num_aleatorio==4){
            // andando para a diagonal inferior direita
           if(matriz[*k+1][*j+1]=='#'){
                do{
                    num_aleatorio=rand()%5;
                }while(num_aleatorio==4);
                *TotalPosicoes+=1;
                matrizConferePasso[*k+1][*j+1]='1';
                continue;
           }else if(matriz[*k+1][*j+1]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k+1][*j+1]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *k=*k+1;
                *j=*j+1;
                break;
           }else{
            if(matriz[*k+1][*j+1]=='0'){
                matrizConferePasso[*k+1][*j+1]='1';
                *TotalPosicoes+=1;
                    *j=*j+1;
                    *k=*k+1;
                    break;
            }else{
                int numero=0;
                char num[2];
                numero = stoi(string(1, matriz[*k+1][*j+1]));
                numero = numero-1;
                sprintf(num, "%d", numero);
                matriz[*k+1][*j+1]= num[0];
                *sacolaGeral=*sacolaGeral+1;
                *sacolaJogo=*sacolaJogo+1;
                matrizConferePasso[*k+1][*j+1]='1';
                *TotalPosicoes+=1;
                *k=*k+1;
                *j=*j+1;
                break;
                }
            }
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Caminho3(char** matriz,char** matrizConferePasso, int *k,int* j,int* vida,int* sacolaGeral, int* sacolaJogo, int* TotalPosicoes, int* perigo){
    srand(time(nullptr)); 
    int num_aleatorio = rand() % 3;

    while(true){
        if(num_aleatorio==0){//andando para baixo
            if(matriz[*k+1][*j]=='#'){
                do{
                    num_aleatorio=rand()%3;
                }while(num_aleatorio==0);
                matrizConferePasso[*k+1][*j]='1';
                *TotalPosicoes+=1;
                continue;
            }else if(matriz[*k+1][*j]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k+1][*j]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *k=*k+1;
                break;
            }else {
                if(matriz[*k+1][*j]=='0'){
                    matrizConferePasso[*k+1][*j]='1';
                    *TotalPosicoes+=1;
                    *k=*k+1;
                    break;
                }else{
                int numero=0;
                char num[2];
                numero = stoi(string(1, matriz[*k+1][*j]));
                numero = numero-1;
                sprintf(num, "%d", numero);
                matriz[*k+1][*j]= num[0];
                *sacolaGeral=*sacolaGeral+1;
                *sacolaJogo=*sacolaJogo+1;
                matrizConferePasso[*k+1][*j]='1';
                *TotalPosicoes+=1;
                *k=*k+1;
                break;
                }
            }    
        }else if(num_aleatorio==1){//andando para diagonal inferior esquerda
            if(matriz[*k+1][*j-1]=='#'){
                do{
                    num_aleatorio=rand()%3;
                }while(num_aleatorio==1);
                matrizConferePasso[*k+1][*j-1]='1';
                *TotalPosicoes+=1;
                continue;
            }else if(matriz[*k+1][*j-1]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k+1][*j-1]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *k=*k+1;
                *j=*j-1;
                break;
            }else{
                if(matriz[*k+1][*j-1]=='0'){
                    matrizConferePasso[*k+1][*j-1]='1';
                    *TotalPosicoes+=1;
                    *k=*k+1;
                    *j=*j-1;
                    break;
                }else{
                int numero=0;
                char num[2];
                numero = stoi(string(1, matriz[*k+1][*j-1]));
                numero = numero-1;
                sprintf(num, "%d", numero);
                matriz[*k+1][*j-1]= num[0];
                *sacolaGeral=*sacolaGeral+1;
                *sacolaJogo=*sacolaJogo+1;
                matrizConferePasso[*k+1][*j-1]='1';
                *TotalPosicoes+=1;
                *k=*k+1;
                *j=*j-1;
                break;
                }
            }
        }else if(num_aleatorio==2){//andando pra esquerda
            if(matriz[*k][*j-1]=='#'){
                 do{
                    num_aleatorio=rand()%3;
                }while(num_aleatorio==2);
                matrizConferePasso[*k][*j-1]='1';
                *TotalPosicoes+=1;
                continue;
            }else if(matriz[*k][*j-1]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k][*j-1]='1';
                *perigo+=1;
                *TotalPosicoes+=1;
                *j=*j-1;
                break;
            }else{
                if(matriz[*k][*j-1]=='0'){
                    matrizConferePasso[*k][*j-1]='1';
                    *TotalPosicoes+=1;
                    *j=*j-1;
                    break;
                }else{
                    int numero=0;
                    char num[2];
                    numero = stoi(string(1, matriz[*k][*j-1]));
                    numero = numero-1;
                    sprintf(num, "%d", numero);
                    matriz[*k][*j-1]= num[0];
                    *sacolaGeral=*sacolaGeral+1;
                    *sacolaJogo=*sacolaJogo+1;
                    matrizConferePasso[*k][*j-1]='1';
                    *TotalPosicoes+=1;
                    *j=*j-1;
                    break;
            
                }
            }
        }
    }   
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Caminho4(char** matriz,char** matrizConferePasso, int *k,int* j,int* vida,int* sacolaGeral, int* sacolaJogo, int* TotalPosicoes, int* perigo){
    srand(time(nullptr)); 
    int num_aleatorio = rand() % 5;

    while(true){
         if(num_aleatorio==0){//andando para baixo
            if(matriz[*k+1][*j]=='#'){
                do{
                    num_aleatorio=rand()%5;
                }while(num_aleatorio==0);
                matrizConferePasso[*k+1][*j]='1';
                *TotalPosicoes+=1;
                continue;
            }else if(matriz[*k+1][*j]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k+1][*j]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *k=*k+1;
                break;
            }else {
                if(matriz[*k+1][*j]=='0'){
                    matrizConferePasso[*k+1][*j]='1';
                    *TotalPosicoes+=1;
                    *k=*k+1;
                    break;
                }else{
                int numero=0;
                char num[2];
                numero = stoi(string(1, matriz[*k+1][*j]));
                numero = numero-1;
                sprintf(num, "%d", numero);
                matriz[*k+1][*j]= num[0];
                *sacolaGeral=*sacolaGeral+1;
                *sacolaJogo=*sacolaJogo+1;
                matrizConferePasso[*k+1][*j]='1';
                *TotalPosicoes+=1;
                *k=*k+1;
                break;
                }
            }    
        }else if(num_aleatorio==1){//andando pra esquerda
            if(matriz[*k][*j-1]=='#'){
                 do{
                    num_aleatorio=rand()%5;
                }while(num_aleatorio==1);
                *TotalPosicoes+=1;
                matrizConferePasso[*k][*j-1]='1';
                continue;
            }else if(matriz[*k][*j-1]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k][*j-1]='1';
                *perigo+=1;
                *TotalPosicoes+=1;
                *j=*j-1;
                break;
            }else{
                if(matriz[*k][*j-1]=='0'){
                    matrizConferePasso[*k][*j-1]='1';
                    *TotalPosicoes+=1;
                    *j=*j-1;
                    break;
                }else{
                    int numero=0;
                    char num[2];
                    numero = stoi(string(1, matriz[*k][*j-1]));
                    numero = numero-1;
                    sprintf(num, "%d", numero);
                    matriz[*k][*j-1]= num[0];
                    *sacolaGeral=*sacolaGeral+1;
                    *sacolaJogo=*sacolaJogo+1;
                    matrizConferePasso[*k][*j-1]='1';
                    *TotalPosicoes+=1;
                    *j=*j-1;
                    break;
            
                }
            }
        }else if(num_aleatorio==2){ //andando para cima
            if(matriz[*k-1][*j]=='#'){
                do{
                    num_aleatorio=rand()%5;
                }while(num_aleatorio==2);
                matrizConferePasso[*k-1][*j]='1';
                *TotalPosicoes+=1;
                continue;
            }
            else if(matriz[*k-1][*j]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k-1][*j]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *k=*k-1;
                break;
            }else{
                if(matriz[*k-1][*j]=='0'){
                    matrizConferePasso[*k-1][*j]='1';
                    *TotalPosicoes+=1;
                    *k=*k-1;
                    break;
                }else{
                    int numero=0;
                    char num[2];
                    numero = stoi(string(1, matriz[*k-1][*j]));
                    numero = numero-1;
                    sprintf(num, "%d", numero);
                    matriz[*k-1][*j]= num[0];
                    *sacolaGeral=*sacolaGeral+1;
                    *sacolaJogo=*sacolaJogo+1;
                    matrizConferePasso[*k-1][*j]='1';
                    *TotalPosicoes+=1;
                    *k=*k-1;
                    break;
                }
            }
        }else if(num_aleatorio==3){ //andando diagonal superior esquerda
            if(matriz[*k-1][*j-1]=='#'){
                do{
                    num_aleatorio=rand()%5;
                }while(num_aleatorio==3);
                matrizConferePasso[*k-1][*j-1]='1';
                *TotalPosicoes+=1;
                continue;
            }
            else if(matriz[*k-1][*j-1]=='*'){
                *vida=*vida-1;
                 matrizConferePasso[*k-1][*j-1]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *k=*k-1;
                *j=*j-1;
                break;
            }else{
                if(matriz[*k-1][*j-1]=='0'){
                     matrizConferePasso[*k-1][*j-1]='1';
                    *TotalPosicoes+=1;
                    *k=*k-1;
                    *j=*j-1;
                    break;
                }else{
                    int numero=0;
                    char num[2];
                    numero = stoi(string(1, matriz[*k-1][*j-1]));
                    numero = numero-1;
                    sprintf(num, "%d", numero);
                    matriz[*k-1][*j-1]= num[0];
                    *sacolaGeral=*sacolaGeral+1;
                    *sacolaJogo=*sacolaJogo+1;
                     matrizConferePasso[*k-1][*j-1]='1';
                    *TotalPosicoes+=1;
                    *k=*k-1;
                    *j=*j-1;
                    break;
                }
            }
        }else if(num_aleatorio==4){ //andando para diagonal inferior esquerda
            if(matriz[*k+1][*j-1]=='#'){
                do{
                    num_aleatorio=rand()%5;
                }while(num_aleatorio==4);
                 matrizConferePasso[*k+1][*j-1]='1';
                *TotalPosicoes+=1;
                continue;
            }
            else if(matriz[*k+1][*j-1]=='*'){
                *vida=*vida-1;
                 matrizConferePasso[*k+1][*j-1]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *k=*k+1;
                *j=*j-1;
                break;
            }else{
                if(matriz[*k+1][*j-1]=='0'){
                     matrizConferePasso[*k+1][*j-1]='1';
                    *TotalPosicoes+=1;
                    *k=*k+1;
                    *j=*j-1;
                    break;
                }else{
                    int numero=0;
                    char num[2];
                    numero = stoi(string(1, matriz[*k+1][*j-1]));
                    numero = numero-1;
                    sprintf(num, "%d", numero);
                    matriz[*k+1][*j-1]= num[0];
                    *sacolaGeral=*sacolaGeral+1;
                    *sacolaJogo=*sacolaJogo+1;
                     matrizConferePasso[*k+1][*j-1]='1';
                    *TotalPosicoes+=1;
                    *k=*k+1;
                    *j=*j-1;
                    break;
                }
            }
        }
    }

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Caminho5(char** matriz, char** matrizConferePasso,int *k,int* j,int* vida,int* sacolaGeral, int* sacolaJogo, int* TotalPosicoes, int* perigo){
    srand(time(nullptr)); 
    int num_aleatorio = rand() % 5;

    while(true){
        if(num_aleatorio==0){ // andando para cima
            if(matriz[*k-1][*j]=='#'){
                do{
                    num_aleatorio=rand()%5;
                }while(num_aleatorio==0);
                 matrizConferePasso[*k-1][*j]='1';
                *TotalPosicoes+=1;
                continue;
            }
            else if(matriz[*k-1][*j]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k-1][*j]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *k=*k-1;
                break;
            }else{
                if(matriz[*k-1][*j]=='0'){
                    matrizConferePasso[*k-1][*j]='1';
                    *TotalPosicoes+=1;
                    *k=*k-1;
                    break;
                }else{
                    int numero=0;
                    char num[2];
                    numero = stoi(string(1, matriz[*k-1][*j]));
                    numero = numero-1;
                    sprintf(num, "%d", numero);
                    matriz[*k-1][*j]= num[0];
                    *sacolaGeral=*sacolaGeral+1;
                    *sacolaJogo=*sacolaJogo+1;
                    matrizConferePasso[*k-1][*j]='1';
                    *TotalPosicoes+=1;
                    *k=*k-1;
                    break;
                }
            }
        }else if(num_aleatorio==1){// andando para esquerda
            if(matriz[*k][*j-1]=='#'){
                 do{
                    num_aleatorio=rand()%5;
                }while(num_aleatorio==1);
                *TotalPosicoes+=1;
                matrizConferePasso[*k][*j-1]='1';
                continue;
            }else if(matriz[*k][*j-1]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k][*j-1]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *j=*j-1;
                break;
            }else{
                if(matriz[*k][*j-1]=='0'){
                    matrizConferePasso[*k][*j-1]='1';
                    *TotalPosicoes+=1;
                    *j=*j-1;
                    break;
                }else{
                    int numero=0;
                char num[2];
                numero = stoi(string(1, matriz[*k][*j-1]));
                numero = numero-1;
                sprintf(num, "%d", numero);
                matriz[*k][*j-1]= num[0];
                *sacolaGeral=*sacolaGeral+1;
                *sacolaJogo=*sacolaJogo+1;
                matrizConferePasso[*k][*j-1]='1';
                *TotalPosicoes+=1;
                *j=*j-1;
                break;
            
                }
            }
        }else if(num_aleatorio==2){//andando para direita
            if(matriz[*k][*j+1]=='#'){
                do{
                    num_aleatorio=rand()%5;
                }while(num_aleatorio==2);
                matrizConferePasso[*k][*j+1]='1';
                *TotalPosicoes+=1;
                continue;
            }
            else if(matriz[*k][*j+1]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k][*j+1]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *j=*j+1;
                break;
            }else{
                if(matriz[*k][*j+1]=='0'){
                    matrizConferePasso[*k][*j+1]='1';
                    *TotalPosicoes+=1;
                    *j=*j+1;
                    break;
                }else{
                    int numero=0;
                    char num[2];
                    numero = stoi(string(1, matriz[*k][*j+1]));
                    numero = numero-1;
                    sprintf(num, "%d", numero);
                    matriz[*k][*j+1]= num[0];
                    *sacolaGeral=*sacolaGeral+1;
                    *sacolaJogo=*sacolaJogo+1;
                    matrizConferePasso[*k][*j+1]='1';
                    *TotalPosicoes+=1;
                    *j=*j+1;
                    break;
                }
            }
        }else if(num_aleatorio==3){//andando para diagonal superior direita 
             if(matriz[*k-1][*j+1]=='#'){
                do{
                    num_aleatorio=rand()%5;
                }while(num_aleatorio==3);
                matrizConferePasso[*k-1][*j+1]='1';
                *TotalPosicoes+=1;
                continue;
           }else if(matriz[*k-1][*j+1]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k-1][*j+1]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *k=*k-1;
                *j=*j+1;
                break;
            }else{
                if(matriz[*k-1][*j+1]=='0'){
                    matrizConferePasso[*k-1][*j+1]='1';
                    *TotalPosicoes+=1;
                    *j=*j+1;
                    *k=*k-1;
                    break;
                }else{
                    int numero=0;
                    char num[2];
                    numero = stoi(string(1, matriz[*k-1][*j+1]));
                    numero = numero-1;
                    sprintf(num, "%d", numero);
                    matriz[*k-1][*j+1]= num[0];
                    *sacolaGeral=*sacolaGeral+1;
                    *sacolaJogo=*sacolaJogo+1;
                    matrizConferePasso[*k-1][*j+1]='1';
                    *TotalPosicoes+=1;
                    *k=*k-1;
                    *j=*j+1;
                    break;
                }
           }
        }else if(num_aleatorio==4){//andando para a diagonal superior esquerda 
            if(matriz[*k-1][*j-1]=='#'){
                do{
                    num_aleatorio=rand()%5;
                }while(num_aleatorio==4);
                matrizConferePasso[*k-1][*j-1]='1';
                *TotalPosicoes+=1;
                continue;
            }
            else if(matriz[*k-1][*j-1]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k-1][*j-1]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *k=*k-1;
                *j=*j-1;
                break;
            }else{
                if(matriz[*k-1][*j-1]=='0'){
                    matrizConferePasso[*k-1][*j-1]='1';
                    *TotalPosicoes+=1;
                    *k=*k-1;
                    *j=*j-1;
                    break;
                }else{
                    int numero=0;
                    char num[2];
                    numero = stoi(string(1, matriz[*k-1][*j-1]));
                    numero = numero-1;
                    sprintf(num, "%d", numero);
                    matriz[*k-1][*j-1]= num[0];
                    *sacolaGeral=*sacolaGeral+1;
                    *sacolaJogo=*sacolaJogo+1;
                    matrizConferePasso[*k-1][*j-1]='1';
                    *TotalPosicoes+=1;
                    *k=*k-1;
                    *j=*j-1;
                    break;
                }
            }
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Caminho6(char** matriz,char** matrizConferePasso, int *k,int* j,int* vida,int* sacolaGeral, int* sacolaJogo,int* TotalPosicoes, int* perigo){
    srand(time(nullptr)); 
    int num_aleatorio = rand() % 5;

    while(true){
        if(num_aleatorio==0){ // andando para baixo
            if(matriz[*k+1][*j]=='#'){
                do{
                    num_aleatorio=rand()%5;
                }while(num_aleatorio==0);
                matrizConferePasso[*k+1][*j]='1';
                *TotalPosicoes+=1;
                continue;
            }
            else if(matriz[*k+1][*j]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k+1][*j]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *k=*k+1;
                break;
            }else{
                if(matriz[*k+1][*j]=='0'){
                    matrizConferePasso[*k+1][*j]='1';
                    *TotalPosicoes+=1;
                    *k=*k+1;
                    break;
                }else{
                    int numero=0;
                    char num[2];
                    numero = stoi(string(1, matriz[*k+1][*j]));
                    numero = numero-1;
                    sprintf(num, "%d", numero);
                    matriz[*k+1][*j]= num[0];
                    *sacolaGeral=*sacolaGeral+1;
                    *sacolaJogo=*sacolaJogo+1;
                    matrizConferePasso[*k+1][*j]='1';
                    *TotalPosicoes+=1;
                    *k=*k+1;
                    break;
                }
            }
        }else if(num_aleatorio==1){// andando para esquerda
            if(matriz[*k][*j-1]=='#'){
                 do{
                    num_aleatorio=rand()%5;
                }while(num_aleatorio==1);
                matrizConferePasso[*k][*j-1]='1';
                *TotalPosicoes+=1;
                continue;
            }else if(matriz[*k][*j-1]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k][*j-1]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *j=*j-1;
                break;
            }else{
                if(matriz[*k][*j-1]=='0'){
                    matrizConferePasso[*k][*j-1]='1';
                    *TotalPosicoes+=1;
                    *j=*j-1;
                    break;
                }else{
                    int numero=0;
                char num[2];
                numero = stoi(string(1, matriz[*k][*j-1]));
                numero = numero-1;
                sprintf(num, "%d", numero);
                matriz[*k][*j-1]= num[0];
                *sacolaGeral=*sacolaGeral+1;
                *sacolaJogo=*sacolaJogo+1;;
                matrizConferePasso[*k][*j-1]='1';
                *TotalPosicoes+=1;
                *j=*j-1;
                break;
            
                }
            }
        }else if(num_aleatorio==2){//andando para direita
            if(matriz[*k][*j+1]=='#'){
                do{
                    num_aleatorio=rand()%5;
                }while(num_aleatorio==2);
                matrizConferePasso[*k][*j+1]='1';
                *TotalPosicoes+=1;
                continue;
            }
            else if(matriz[*k][*j+1]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k][*j+1]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *j=*j+1;
                break;
            }else{
                if(matriz[*k][*j+1]=='0'){
                    matrizConferePasso[*k][*j+1]='1';
                    *TotalPosicoes+=1;
                    *j=*j+1;
                    break;
                }else{
                    int numero=0;
                    char num[2];
                    numero = stoi(string(1, matriz[*k][*j+1]));
                    numero = numero-1;
                    sprintf(num, "%d", numero);
                    matriz[*k][*j+1]= num[0];
                    *sacolaGeral=*sacolaGeral+1;
                    *sacolaJogo=*sacolaJogo+1;
                    matrizConferePasso[*k][*j+1]='1';
                    *TotalPosicoes+=1;
                    *j=*j+1;
                    break;
                }
            }
        }else if(num_aleatorio==3){//andando para diagonal inferior direita
            if(matriz[*k+1][*j+1]=='#'){
                do{
                    num_aleatorio=rand()%5;
                }while(num_aleatorio==3);
                matrizConferePasso[*k+1][*j+1]='1';
                *TotalPosicoes+=1;
                continue;
           }else if(matriz[*k+1][*j+1]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k+1][*j+1]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *k=*k+1;
                *j=*j+1;
                break;
           }else{
                if(matriz[*k+1][*j+1]=='0'){
                    matrizConferePasso[*k+1][*j+1]='1';
                    *TotalPosicoes+=1;
                    *j=*j+1;
                    *k=*k+1;
                    break;
                }else{
                    int numero=0;
                    char num[2];
                    numero = stoi(string(1, matriz[*k+1][*j+1]));
                    numero = numero-1;
                    sprintf(num, "%d", numero);
                    matriz[*k+1][*j+1]= num[0];
                    *sacolaGeral=*sacolaGeral+1;
                    *sacolaJogo=*sacolaJogo+1;
                    matrizConferePasso[*k+1][*j+1]='1';
                    *TotalPosicoes+=1;
                    *k=*k+1;
                    *j=*j+1;
                    break;
                }
            }
        }else if(num_aleatorio==4){//andando para a diagonal inferior esquerda
            if(matriz[*k+1][*j-1]=='#'){
                do{
                    num_aleatorio=rand()%5;
                }while(num_aleatorio==4);
                matrizConferePasso[*k+1][*j-1]='1';
                *TotalPosicoes+=1;
                continue;
            }else if(matriz[*k+1][*j-1]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k+1][*j-1]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *k=*k+1;
                *j=*j-1;
                break;
            }else{
                if(matriz[*k+1][*j-1]=='0'){
                    matrizConferePasso[*k+1][*j-1]='1';
                    *TotalPosicoes+=1;
                    *k=*k+1;
                    *j=*j-1;
                    break;
                }else{
                int numero=0;
                char num[2];
                numero = stoi(string(1, matriz[*k+1][*j-1]));
                numero = numero-1;
                sprintf(num, "%d", numero);
                matriz[*k+1][*j-1]= num[0];
                *sacolaGeral=*sacolaGeral+1;
                *sacolaJogo=*sacolaJogo+1;
                matrizConferePasso[*k+1][*j-1]='1';
                *TotalPosicoes+=1;
                *k=*k+1;
                *j=*j-1;
                break;
                }
            }
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Caminho7(char** matriz,char** matrizConferePasso, int *k,int* j,int* vida,int* sacolaGeral, int* sacolaJogo, int* TotalPosicoes, int* perigo){
    srand(time(nullptr)); 
    int num_aleatorio = rand() % 8;

    while(true){
        if(num_aleatorio==0){ // andando para baixo
            if(matriz[*k+1][*j]=='#'){
                do{
                    num_aleatorio=rand()%8;
                }while(num_aleatorio==0);
                matrizConferePasso[*k+1][*j]='1';
                *TotalPosicoes+=1;
                continue;
            }
            else if(matriz[*k+1][*j]=='*'){
                matrizConferePasso[*k+1][*j]='1';
                *TotalPosicoes+=1;
                *vida=*vida-1;
                *perigo+=1;
                *k=*k+1;
                break;
            }else{
                if(matriz[*k+1][*j]=='0'){
                    matrizConferePasso[*k+1][*j]='1';
                    *TotalPosicoes+=1;
                    *k=*k+1;
                    break;
                }else{
                    int numero=0;
                    char num[2];
                    numero = stoi(string(1, matriz[*k+1][*j]));
                    numero = numero-1;
                    sprintf(num, "%d", numero);
                    matriz[*k+1][*j]= num[0];
                    *sacolaGeral=*sacolaGeral+1;
                    *sacolaJogo=*sacolaJogo+1;
                    matrizConferePasso[*k+1][*j]='1';
                    *TotalPosicoes+=1;
                    *k=*k+1;
                    break;
                }
            }
        }else if(num_aleatorio==1){// andando para esquerda
            if(matriz[*k][*j-1]=='#'){
                 do{
                    num_aleatorio=rand()%8;
                }while(num_aleatorio==1);
                *TotalPosicoes+=1;
                matrizConferePasso[*k][*j-1]='1';
                continue;
            }else if(matriz[*k][*j-1]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k][*j-1]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *j=*j-1;
                break;
            }else{
                if(matriz[*k][*j-1]=='0'){
                    matrizConferePasso[*k][*j-1]='1';
                    *TotalPosicoes+=1;
                    *j=*j-1;
                    break;
                }else{
                    int numero=0;
                char num[2];
                numero = stoi(string(1, matriz[*k][*j-1]));
                numero = numero-1;
                sprintf(num, "%d", numero);
                matriz[*k][*j-1]= num[0];
                *sacolaGeral=*sacolaGeral+1;
                *sacolaJogo=*sacolaJogo+1;
                matrizConferePasso[*k][*j-1]='1';
                *TotalPosicoes+=1;
                *j=*j-1;
                break;
            
                }
            }
        }else if(num_aleatorio==2){//andando para direita
            if(matriz[*k][*j+1]=='#'){
                do{
                    num_aleatorio=rand()%8;
                }while(num_aleatorio==2);
                matrizConferePasso[*k][*j+1]='1';
                *TotalPosicoes+=1;
                continue;
            }
            else if(matriz[*k][*j+1]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k][*j+1]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *j=*j+1;
                break;
            }else{
                if(matriz[*k][*j+1]=='0'){
                    matrizConferePasso[*k][*j+1]='1';
                    *TotalPosicoes+=1;
                    *j=*j+1;
                    break;
                }else{
                    int numero=0;
                    char num[2];
                    numero = stoi(string(1, matriz[*k][*j+1]));
                    numero = numero-1;
                    sprintf(num, "%d", numero);
                    matriz[*k][*j+1]= num[0];
                    *sacolaGeral=*sacolaGeral+1;
                    *sacolaJogo=*sacolaJogo+1;
                    matrizConferePasso[*k][*j+1]='1';
                    *TotalPosicoes+=1;
                    *j=*j+1;
                    break;
                }
            }
        }else if(num_aleatorio==3){//andando para diagonal inferior direita
            if(matriz[*k+1][*j+1]=='#'){
                do{
                    num_aleatorio=rand()%8;
                }while(num_aleatorio==3);
                matrizConferePasso[*k+1][*j+1]='1';
                *TotalPosicoes+=1;
                continue;
           }else if(matriz[*k+1][*j+1]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k+1][*j+1]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *k=*k+1;
                *j=*j+1;
                break;
           }else{
                if(matriz[*k+1][*j+1]=='0'){
                    matrizConferePasso[*k+1][*j+1]='1';
                    *TotalPosicoes+=1;
                    *j=*j+1;
                    *k=*k+1;
                    break;
                }else{
                    int numero=0;
                    char num[2];
                    numero = stoi(string(1, matriz[*k+1][*j+1]));
                    numero = numero-1;
                    sprintf(num, "%d", numero);
                    matriz[*k+1][*j+1]= num[0];
                    *sacolaGeral=*sacolaGeral+1;
                    *sacolaJogo=*sacolaJogo+1;
                    matrizConferePasso[*k+1][*j+1]='1';
                    *TotalPosicoes+=1;
                    *k=*k+1;
                    *j=*j+1;
                    break;
                }
            }
        }else if(num_aleatorio==4){//andando para a diagonal inferior esquerda
            if(matriz[*k+1][*j-1]=='#'){
                do{
                    num_aleatorio=rand()%8;
                }while(num_aleatorio==4);
                matrizConferePasso[*k+1][*j-1]='1';
                *TotalPosicoes+=1;
                continue;
            }else if(matriz[*k+1][*j-1]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k+1][*j-1]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *k=*k+1;
                *j=*j-1;
                break;
            }else{
                if(matriz[*k+1][*j-1]=='0'){
                    matrizConferePasso[*k+1][*j-1]='1';
                    *TotalPosicoes+=1;
                    *k=*k+1;
                    *j=*j-1;
                    break;
                }else{
                int numero=0;
                char num[2];
                numero = stoi(string(1, matriz[*k+1][*j-1]));
                numero = numero-1;
                sprintf(num, "%d", numero);
                matriz[*k+1][*j-1]= num[0];
                *sacolaGeral=*sacolaGeral+1;
                *sacolaJogo=*sacolaJogo+1;
                matrizConferePasso[*k+1][*j-1]='1';
                *TotalPosicoes+=1;
                *k=*k+1;
                *j=*j-1;
                break;
                }
            }
        }else if(num_aleatorio==5){ // andando para cima
            if(matriz[*k-1][*j]=='#'){
                do{
                    num_aleatorio=rand()%8;
                }while(num_aleatorio==5);
                matrizConferePasso[*k-1][*j]='1';
                *TotalPosicoes+=1;
                continue;
            }
            else if(matriz[*k-1][*j]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k-1][*j]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *k=*k-1;
                break;
            }else{
                if(matriz[*k-1][*j]=='0'){
                    matrizConferePasso[*k-1][*j]='1';
                    *TotalPosicoes+=1;
                    *k=*k-1;
                    break;
                }else{
                    int numero=0;
                    char num[2];
                    numero = stoi(string(1, matriz[*k-1][*j]));
                    numero = numero-1;
                    sprintf(num, "%d", numero);
                    matriz[*k-1][*j]= num[0];
                    *sacolaGeral=*sacolaGeral+1;
                    *sacolaJogo=*sacolaJogo+1;
                    matrizConferePasso[*k-1][*j]='1';
                    *TotalPosicoes+=1;
                    *k=*k-1;
                    break;
                }
            }
        }else if(num_aleatorio==6){//andando para diagonal superior direita 
             if(matriz[*k-1][*j+1]=='#'){
                do{
                    num_aleatorio=rand()%8;
                }while(num_aleatorio==6);
                matrizConferePasso[*k-1][*j+1]='1';
                *TotalPosicoes+=1;
                continue;
           }else if(matriz[*k-1][*j+1]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k-1][*j+1]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *k=*k-1;
                *j=*j+1;
                break;
            }else{
                if(matriz[*k-1][*j+1]=='0'){
                    matrizConferePasso[*k-1][*j+1]='1';
                    *TotalPosicoes+=1;
                    *j=*j+1;
                    *k=*k-1;
                    break;
                }else{
                    int numero=0;
                    char num[2];
                    numero = stoi(string(1, matriz[*k-1][*j+1]));
                    numero = numero-1;
                    sprintf(num, "%d", numero);
                    matriz[*k-1][*j+1]= num[0];
                    *sacolaGeral=*sacolaGeral+1;
                    *sacolaJogo=*sacolaJogo+1;
                    matrizConferePasso[*k-1][*j+1]='1';
                    *TotalPosicoes+=1;
                    *k=*k-1;
                    *j=*j+1;
                    break;
                }
           }
        }else if(num_aleatorio==7){//andando para a diagonal superior esquerda 
            if(matriz[*k-1][*j-1]=='#'){
                do{
                    num_aleatorio=rand()%8;
                }while(num_aleatorio==7);
                matrizConferePasso[*k-1][*j-1]='1';
                *TotalPosicoes+=1;
                continue;
            }
            else if(matriz[*k-1][*j-1]=='*'){
                *vida=*vida-1;
                matrizConferePasso[*k-1][*j-1]='1';
                *TotalPosicoes+=1;
                *perigo+=1;
                *k=*k-1;
                *j=*j-1;
                break;
            }else{
                if(matriz[*k-1][*j-1]=='0'){
                    matrizConferePasso[*k-1][*j-1]='1';
                    *TotalPosicoes+=1;
                    *k=*k-1;
                    *j=*j-1;
                    break;
                }else{
                    int numero=0;
                    char num[2];
                    numero = stoi(string(1, matriz[*k-1][*j-1]));
                    numero = numero-1;
                    sprintf(num, "%d", numero);
                    matriz[*k-1][*j-1]= num[0];
                    *sacolaGeral=*sacolaGeral+1;
                    *sacolaJogo=*sacolaJogo+1;
                    matrizConferePasso[*k-1][*j-1]='1';
                    *TotalPosicoes+=1;
                    *k=*k-1;
                    *j=*j-1;
                    break;
                }
            }
        }
    }
}