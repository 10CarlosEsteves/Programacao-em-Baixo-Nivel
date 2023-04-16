#include <iostream>
#include <cctype>

#include "Patient.hpp"

using namespace std;

Patient::Patient(){
	condition = '0';
	name = "NAO DEFINIDO PREVIAMENTE";
	password = 0;
	nextPatient = NULL;
}

Patient::Patient(char newCondition, string newName){
	setCondition(newCondition);
	setName(newName);
	setPassword(0);
	setNextPatient(NULL);

}

Patient::Patient(char newCondition, string newName, int newPassword, Patient* newNextPatient){
	setCondition(newCondition);
	setName(newName);
	setPassword(newPassword);
	setNextPatient(newNextPatient);
}


void Patient::setCondition(char newCondition){

	newCondition = toupper(newCondition);
	
	if(newCondition != 'M' and newCondition !='G'){
		cout<<"ERROR: Condicao inserida eh invalida"<<endl;
		exit(1);
	}
	
	condition = newCondition;
}

void Patient::setName(string newName){
	name = newName;
}

void Patient::setPassword(int newPassword){
	password = newPassword;
}

void Patient::setNextPatient(Patient* newNextPatient){
	nextPatient = newNextPatient;
}

void Patient::setPatient(char newCondition, string newName, int newPassword, Patient* newNextPatient){
	setCondition(newCondition);
	setName(newName);
	setPassword(newPassword);
	setNextPatient(newNextPatient);
}

char Patient::getCondition() const {
	return condition;
}

string Patient::getName()const {
	return name;
}

int Patient::getPassword() const {
	return password;
}

Patient* Patient::getNextPatient() const {
	return nextPatient;
}


void Patient::PrintInfo() const {
	cout<<"NOME: "<<name<<endl;
	cout<<"CONDICAO: "<<condition<<endl;
	cout<<"SENHA: "<<password<<endl;
}
