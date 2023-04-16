#include <iostream>
#include <cstdlib>

#include "Patient.hpp"
#include "HospitalDeque.hpp"

using namespace std;

int main(){
	
	system("color 0A");
	
	HospitalDeque vavilov("VAVILOV");

	vavilov.AddBegin('m', "Carlos");
	vavilov.AddEnd('G', "Mike OHearn");
	vavilov.AddEnd('m', "Charles");
	vavilov.AddBegin('g', "Rafik");

	
	vavilov.PrintAllDeque();
	
	return 0;
}
