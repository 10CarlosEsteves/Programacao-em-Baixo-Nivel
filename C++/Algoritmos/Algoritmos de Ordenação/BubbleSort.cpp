#include <iostream>
#include <fstream>


using namespace std;

void Preencha(int arr[], int size);
void BubbleSort(int arr[], int size);
void Swap(int& var1, int& var2);
void Print(int arr[], int size);
int* Extratora(string nomeDoArquivo, int& size);


int main(){

	int size = 0;
    int *vetor = Extratora("csvCozido", size);
	
	Print(vetor, size); 
    BubbleSort(vetor, size);
    Print(vetor, size);

    return 0;
}


void Preencha(int arr[], int size){
	for(int index=0; index<size; index++){
		cout<<"Digite um valor para a posicao "<<index+1<<": ";
		cin>>arr[index];
	}
}


void BubbleSort(int arr[], int size){
	
	int vezes = size;

	for(int i = 0; i < vezes ;i++){
		
		for(int atual=0; atual < size; atual++){
            if(arr[atual] > arr[atual + 1] and atual + 1 < size)	
                Swap(arr[atual], arr[atual+1]);
        }

    }
}

void Swap(int& var1, int& var2){
	
	int temp;
	
	temp = var1;
	var1 = var2;
	var2 = temp;	
}

void Print(int arr[], int size){

    for(int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
    
    cout<<endl;
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
