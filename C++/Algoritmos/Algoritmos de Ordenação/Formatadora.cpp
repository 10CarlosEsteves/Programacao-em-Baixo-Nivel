#include <iostream>
#include <fstream>

using namespace std;

void Formatadora(string arqEntrada, string arqSaida, string formato);

int main(){
	
	string entrada,saida, formato;

	cout<<"Digite o nome do arquivo que se extrai os dados: ";
	cin>>entrada;
	cout<<"Digite o nome do arquivo que se salva os dados: ";
	cin>>saida;
	cout<<"Digite o nome do formato de arquivo: ";
	cin>>formato;

	Formatadora(entrada, saida,formato);
	
    return 0;
}



void Formatadora(string arqEntrada, string arqSaida, string formato){

	int numeroReal;
	int i = 0;
	ifstream entradaDeNumeros;
	ofstream saidaDeNumeros;


	entradaDeNumeros.open(arqEntrada + formato);
	saidaDeNumeros.open(arqSaida + ".txt");

	if(entradaDeNumeros.is_open() == false || saidaDeNumeros.is_open() == false){
		cout<<"Error: Falha ao abrir os arquivos"<<endl;
		exit(1);
	}

	string numeroString, numeroExtraido;
	
	entradaDeNumeros>>numeroString;

	//Se estivermos lidando com txt ou csv, use essa parte
	if(formato == ".txt" or formato == ".csv"){
		for(i = 0; i<numeroString.length()+1;i++){
			if( numeroString[i] == ',' or numeroString[i] == '\0'){
				numeroReal = stoi(numeroExtraido);
				
				saidaDeNumeros<<numeroReal<<endl;
				
				numeroReal = 0;
				numeroExtraido = ' ';
			}
			else{
				numeroExtraido += numeroString[i];
			}
		}
		cout<<"Salvo com sucesso!"<<endl;
	}

	//Se estivermos lidando com arquivos .json
	else if(formato == ".json"){

		for(i = 0; i < numeroString.length();i++){
			if(numeroString[i] == '[')
				break;
		}

		i++;
		
		for(i; i<numeroString.length();i++){
			
			if( numeroString[i] == ',' or numeroString[i] == ']'){
				numeroReal = stoi(numeroExtraido);
				saidaDeNumeros<<numeroReal<<endl;
				numeroReal = 0;
				numeroExtraido = ' ';
			}
			else{
				numeroExtraido += numeroString[i];
			}
		}
		cout<<"Salvo com sucesso!"<<endl;
	}

	
	else{
		cout<<"Error: Formato invalido"<<endl;
	}
	
	entradaDeNumeros.close();
	saidaDeNumeros.close();
	
}
