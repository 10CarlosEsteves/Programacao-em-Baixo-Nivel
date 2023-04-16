#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <iostream>

using namespace std;

class Patient{

    private:
        char condition;
        string name;
        int password;
        Patient* nextPatient;

    public:
    	//Funções Construtoras
        Patient();
        Patient(char newCondition, string newName);
        Patient(char newCondition, string newName, int newPassword, Patient* newNextPatient);
        
        //Funções Setters
        void setCondition(char newCondition);
        void setName(string newName);
        void setPassword(int newPassword);
        void setNextPatient(Patient* newNextPatient);
		void setPatient(char newCondition, string newName, int newPassword, Patient* newNextPatient);
        
        //Funções Getters
        char getCondition() const;
        string getName() const;
        int getPassword() const;
        Patient* getNextPatient() const;
        
		//Funções ordinárias
		void PrintInfo() const;
};



#endif
