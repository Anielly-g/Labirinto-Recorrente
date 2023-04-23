#ifndef INSTRUCOES_HPP 
#define INSTRUCOES_HPP
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;



void Caminhar(int rows,int cols, int num_matriz);
void Caminho0(char** matriz, char** matrizConferePasso, int *k,int* j,int* vida,int* sacolaGeral, int* sacolaJogo, int* TotalPosicoes,int* perigo);
void Caminho1(char** matriz,char** matrizConferePasso, int *k,int* j,int* vida,int* sacolaGeral, int* sacolaJogo, int* TotalPosicoes,int* perigo);
void Caminho2(char** matriz, char** matrizConferePasso,int *k,int* j,int* vida,int* sacolaGeral, int* sacolaJogo, int* TotalPosicoes,int* perigo);
void Caminho3(char** matriz, char** matrizConferePasso,int *k,int* j,int* vida,int* sacolaGeral, int* sacolaJogo, int* TotalPosicoes,int* perigo);
void Caminho4(char** matriz,char** matrizConferePasso, int *k,int* j,int* vida,int* sacolaGeral, int* sacolaJogo, int* TotalPosicoes,int* perigo);
void Caminho5(char** matriz, char** matrizConferePasso,int *k,int* j,int* vida,int* sacolaGeral, int* sacolaJogo, int* TotalPosicoes,int* perigo);
void Caminho6(char** matriz,char** matrizConferePasso, int *k,int* j,int* vida,int* sacolaGeral, int* sacolaJogo, int* TotalPosicoes,int* perigo);
void Caminho7(char** matriz, char** matrizConferePasso,int *k,int* j,int* vida,int* sacolaGeral, int* sacolaJogo, int* TotalPosicoes,int* perigo);

#endif