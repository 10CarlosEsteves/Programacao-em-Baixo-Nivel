#ifndef HOSPITALDEQUE_HPP
#define HOSPITALDEQUE_HPP

#include <iostream>

using namespace std;

class HospitalDeque{

	private:
		int dequeSize;
		int passwordGenerator;
		string hospitalName;
		Patient* firstPatient;
		Patient* lastPatient;

	public:
		//Funções Construtoras
		HospitalDeque(string newHospitalname);

		//Funções Getters
		int getDequeSize() const ;
		int getPassGen() const ;
		string getHospitalName() const ;
		Patient* getFirstPatient() const ;
		Patient* getLastPatient() const ;

		//Funções Setters
		void setHospitalName(string newHospitalname);

		//Funções da Classe
		bool IsFull() const;
		bool IsEmpty() const;

		//Funções para acrescentar ao inicio
		void AddBegin(Patient* newPatient);
		void AddBegin(char newCondition, string newName);

		//Funções para acrescentar ao final
		void AddEnd(Patient* newPatient);
		void AddEnd(char newCondition, string newName);
		

		void PrintAllDeque();
};

#endif