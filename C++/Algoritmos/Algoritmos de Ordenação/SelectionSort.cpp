#include <iostream>

using namespace std;

void Print(int arr[], int size);
void Swap(int& var1, int& var2);
void SelectionSort(int arr[], int size);


int main(){

	int size = 5;
	int arr[5] = {5, 4, 3, 2, 1};
    
    Print(arr, size);
    
    SelectionSort(arr,5);
    

    Print(arr,5);
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