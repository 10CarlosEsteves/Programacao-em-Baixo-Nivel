#include <iostream>

using namespace std;

void Preencha(int arr[], int size);
void BubbleSort(int arr[], int size);
void Swap(int& var1, int& var2);
void Print(int arr[], int size);

int main(){

	int tam = 5;
	int vetor[tam] = {5,4,3,2,1};
	
	Print(vetor, tam); 
    BubbleSort(vetor, tam);
    Print(vetor, tam);

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
