#include <iostream>
#include <fstream>

using namespace std;

void Print(int arr[], int size);
void Swap(int& var1, int& var2);
void SelectionSort(int arr[], int size);
int* Extratora(string nomeDoArquivo, int& size);

int main(){


	int size = 0;
    int *vetor = Extratora("csvCozido", size);
	
	Print(vetor, size); 
    SelectionSort(vetor, size);
    Print(vetor, size);
    
    return 0;
}


void Print(int arr[], int size){
		
    for(int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
        
    cout<<endl;
}

void Swap(int& var1, int& var2){
	
	int temp;
	
	temp = var1;
	var1 = var2;
	var2 = temp;	
}

void SelectionSort(int arr[], int size){

	for(int times = 0; times < size;times++){
        
        int minVal = arr[times];
        int pos = times;
        
        for(int index = times; index < size; index++){
            if(arr[index] <= minVal){
                minVal = arr[index];
                pos = index;
            }
        }
        Swap(arr[times], arr[pos]);
	}
}


int* Extratora(string nomeDoArquivo, int& tamanho){

    ifstream entradaDeNumeros;
    int numeroExtraido;

    entradaDeNumeros.open(nomeDoArquivo + ".txt");

    if(entradaDeNumeros.is_open()==false){
    	cout<<"Error: Falha ao abrir o arquivo"<<endl;
    	exit(1);
	}

    while (entradaDeNumeros>>numeroExtraido){
        tamanho++;
    }
    
    entradaDeNumeros.close();
    entradaDeNumeros.open(nomeDoArquivo + ".txt");
    
    
    int* vetor = new int [tamanho];
    int  indice = 0;
    
    while (entradaDeNumeros>>numeroExtraido){
        vetor[indice] = numeroExtraido;
		indice++;
    }

    entradaDeNumeros.close();

    return vetor;
}