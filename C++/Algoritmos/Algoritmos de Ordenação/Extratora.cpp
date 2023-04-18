#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream entradaDeNumeros;
    int numeroExtraido;
    int tamanho = 0;

    entradaDeNumeros.open("txtCozido.txt");

    if(entradaDeNumeros.is_open()==false){
    	cout<<"Error: Falha ao abrir o arquivo"<<endl;
    	exit(1);
	}

    while (entradaDeNumeros>>numeroExtraido){
        tamanho++;
    }
    
    entradaDeNumeros.close();
    entradaDeNumeros.open("txtCozido.txt");
    
    
    int* vetor = new int [tamanho];
    int  indice = 0;
    
    while (entradaDeNumeros>>numeroExtraido){
        vetor[indice] = numeroExtraido;
        cout<<vetor[indice]<<" ";
		indice++;
    }
	
        
    
    


    return 0;
}
