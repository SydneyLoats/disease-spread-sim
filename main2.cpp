#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <cstdlib>
#include "infectiousDisease.h"

using namespace std;



int main(){

	srand(time(NULL));

	int populationSize;
	cout << "Population size: " << endl;
	cin >> populationSize;

	double percentVaccinated;
	cout << "Percent vaccinated (decimal): " << endl;
	cin >> percentVaccinated;

	double probTransfer;
	cout << "Probability of transmission: " << endl;
	cin >> probTransfer;
	 

	Population pop(populationSize);

	pop.random_infection();
	pop.set_percentage_vaccinated(percentVaccinated);
	pop.set_probability_of_transfer(probTransfer);
	pop.random_vaccination();

//	pop.print_vector();
//
	cout << "Percent vaccinated: " << pop.get_percent_vaccinated() << endl;
//	cout << "Number vaccinated: " << pop.count_vaccinated() << endl;
	cout << "Total population: " << populationSize << endl;

	int day = 0;
	while(pop.count_infected() > 0){
	//	cout << "Number infected: " << pop.count_infected() << endl;
		pop.update();
		pop.infect_neighbors();
//		pop.print_vector();
		day++;
	}

	cout << "Time it takes for the disease to run through the population: " << day << " days" << endl;
	cout << "Total recovered/Total infected: " << pop.count_recovered() << endl;
	cout << "Amount unvaccinated that were never infected: " << pop.count_susceptible() << endl;
	

	return 0;
}

