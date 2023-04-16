#include "Patient.hpp"


Patient::Patient(){
	condition = '0';
	name = "NAO DEFINIDO PREVIAMENTE";
	password = 0;
	nextPatient = NULL;
}

Patient::Patient(char newCondition, string newName){
	condition = newCondition;
	name = newName;
	password = 0;
	nextPatient = NULL;
}

void Patient::setCondition(char newCondition){
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


char Patient::getCondition(){
	return condition;
}

string Patient::getName(){
	return name;
}

int Patient::getPassword(){
	return password;
}

Patient* Patient::getNextPatient(){
	return nextPatient;
}


void Patient::PrintInfo(){
	cout<<"-----------------------------"<<endl;
	cout<<"NOME: "<<name<<endl;
	cout<<"CONDICAO: "<<condition<<endl;
	cout<<"SENHA: "<<password<<endl;
	cout<<"PROXIMO PACIENTE: "<<nextPatient->getName()<<endl;	
}

