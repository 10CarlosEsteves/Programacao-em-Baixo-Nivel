#include <iostream>

#include "Patient.hpp"
#include "HospitalDeque.hpp"

#define MAX_SIZE 100

using namespace std;

HospitalDeque::HospitalDeque(string newHospitalname){
	dequeSize = 0;
	passwordGenerator = 1000;
	hospitalName = newHospitalname;
	firstPatient = NULL;
	lastPatient  = NULL;
}

int HospitalDeque::getDequeSize() const {
	return dequeSize;
}

int HospitalDeque::getPassGen() const {
	return passwordGenerator;
}

string HospitalDeque::getHospitalName() const {
	return hospitalName;
}

Patient* HospitalDeque::getFirstPatient() const {
	return firstPatient;
}

Patient* HospitalDeque::getLastPatient() const {
	return lastPatient;
}

void HospitalDeque::setHospitalName(string newHospitalname){
	hospitalName = newHospitalname;
}

bool HospitalDeque::IsFull() const{
	return (dequeSize == MAX_SIZE ? true : false);
}

bool HospitalDeque::IsEmpty() const{
	return (dequeSize == 0 ? true : false);
}

void HospitalDeque::AddBegin(Patient* newPatient){

	if( IsFull() ){
		cout<<"ERROR: A fila esta na capacidade maxima"<<endl;
		return;
	}

	else if( IsEmpty() ){
		firstPatient = newPatient;
		lastPatient = newPatient;
	}

	else{
		newPatient->setNextPatient(firstPatient);
		firstPatient = newPatient;
	}

	newPatient->setPassword(passwordGenerator);
	
	passwordGenerator++;
	dequeSize++;
}

void HospitalDeque::AddBegin(char newCondition, string newName){
	
	Patient* newPatient = new Patient(newCondition, newName, passwordGenerator, NULL);

	if( IsFull() ){
		cout<<"ERROR: A fila esta na capacidade maxima"<<endl;
		return;
	}

	else if( IsEmpty() ){
		firstPatient = newPatient;
		lastPatient = newPatient;
	}

	else{
		newPatient->setNextPatient(firstPatient);
		firstPatient = newPatient;
	}

	passwordGenerator++;
	dequeSize++;
}

void HospitalDeque::AddEnd(Patient* newPatient){

	if( IsFull() ){
		cout<<"ERROR: A fila esta na capacidade maxima"<<endl;
		return;
	}

	else if ( IsEmpty() ){
		firstPatient = newPatient;
		lastPatient  = newPatient; 
	}

	else{
		lastPatient->setNextPatient(newPatient);
		lastPatient = newPatient;
	}

	newPatient->setPassword(passwordGenerator);

	passwordGenerator++;
	dequeSize++;
}

void HospitalDeque::AddEnd(char newCondition, string newName){

	Patient* newPatient = new Patient(newCondition, newName, passwordGenerator, NULL);

	if( IsFull() ){
		cout<<"ERROR: A fila esta na capacidade maxima"<<endl;
		return;
	}

	else if (IsEmpty() ){
		firstPatient = newPatient;
		lastPatient  = newPatient; 
	}

	else{
		lastPatient->setNextPatient(newPatient);
		lastPatient = newPatient;
	}

	passwordGenerator++;
	dequeSize++;
}

void HospitalDeque::PrintAllDeque(){

	Patient* currentPatient = firstPatient;

	if( IsEmpty() ){
		cout<<"                                                                                                                       "<<endl;
		cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"                                           HOSPITAL "<<hospitalName<<" DEQUE INFORMACAO                                "<<endl;
		cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"TAMANHO ATUAL: "<<getDequeSize()<<endl;
		cout<<"PROXIMA SENHA A SER GERADA: "<<getPassGen()<<endl;
	}

	else{
		cout<<"                                                                                                                       "<<endl;
		cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"                                           HOSPITAL "<<hospitalName<<" DEQUE INFORMACAO                                "<<endl;
		cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"TAMANHO ATUAL: "<<getDequeSize()<<endl;
		cout<<"PROXIMA SENHA A SER GERADA: "<<getPassGen()<<endl;
		cout<<"\n";

		int contador = 1;

		while(currentPatient != NULL){
			cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
			cout<<"                                              INFORMACAO DO PACIENTE  "<<contador<<"                                   "<<endl;
			cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
			currentPatient->PrintInfo();
			currentPatient = currentPatient->getNextPatient();
			contador++;
		}
	}
}
