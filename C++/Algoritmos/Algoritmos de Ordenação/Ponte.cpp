#include <iostream>

using namespace std;


void Print(int arr[], int size);
void Swap(int& var1, int& var2);
void Preencha(int arr[], int size);
void BubbleSort(int arr[], int size);
void SelectionSort(int arr[], int size);



int main(){

    int tam;

    cout<<"Por favor, digite o tamanho do vetor: ";cin>>tam;


    int* vetor = new int[tam];

    Preencha(vetor, tam);

	Print(vetor, tam);
    SelectionSort(vetor, tam);
    Print(vetor, tam);

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