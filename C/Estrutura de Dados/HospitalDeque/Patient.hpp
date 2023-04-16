#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <iostream>

#define MAX_SIZE 100

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
        
        //Funções Getters
        char getCondition();
        string getName();
        int getPassword();
        Patient* getNextPatient();
        
        //Funções de Tester
        void PrintInfo();
        
        
        
};


#endif
