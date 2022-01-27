#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <cstdlib>

using namespace std;



class Person{
private:

  string name;
  int day = 1;
  int status = 0;
	//0 = healthy but not vaccinated
	//-1 = recovered
	//-2 = vaccinated
	//n = infected for n days


public:

  Person (string name) {
	this->name = name;
  }

  string status_string(){
	string insert;
	if (is_susceptible()) {insert = "susceptible";}
	if (status = -1) {insert = "recovered";}
	if (status = -2) {insert = "vaccinated";}
	if (status > 0) {insert = "sick {" + to_string(status) + " days to go)";}
	string ret = "On day " + to_string(day) + ", " + name + " is " + insert;
  }

  void update(){
	day++;
	if(this->status > 0){
		this->status--;
		if(this->status==0){
			this->status = -1;
		}
	}
	
	
	
  }

  void infect(int n){
	if(is_susceptible())
        	this->status = n;
  }

  void vaccinate() {
	status = -2;
  }


  int get_status(){
	return status;
  }

  bool is_stable(){
	return status == -1;
  }

  bool is_vaccinated(){
	return status == -2;
  }

  bool is_susceptible() {
	return status == 0;
  }

  bool is_infected() {
	return status > 0;
  }

};



class Population{
private:
  vector<Person> vec;
  int numOfPeople;
  double p;
  double percentVaccinated;
  int contacts = 3;
  int numDaysInfected = 5;
public:

  Population(int num){ 
    for(int i=0; i< num; i++){
	Person person("Person " + to_string(i));
	vec.push_back(person);
    }
  }

  void set_probability_of_transfer(double probability){
	p = probability;
  }

  void set_percentage_vaccinated(double percent) {
	percentVaccinated = percent;
  }

  void random_vaccination();

  void random_infection();

  int count_infected(){
	int count = 0;
	for( int i=0; i< vec.size(); i++){
	    if(vec[i].is_infected())
		count++;
	}
  	return count;
  }

  int count_vaccinated(){
	int count = 0;
	for( int i=0; i< vec.size(); i++){
	    if(vec[i].is_vaccinated())
		count++;
	}
  	return count;
  }

  int count_recovered(){
	int count = 0;
	for( int i=0; i< vec.size(); i++){
	    if(vec[i].is_stable())
		count++;
	}
  	return count;
  }

  int count_susceptible(){
	int count = 0;
	for( int i=0; i< vec.size(); i++){
	    if(vec[i].is_susceptible())
		count++;
	}
  	return count;
  }

  void update(){
	for( int i=0; i< vec.size(); i++)
	    vec[i].update();
  }


  void infect_contacts();

  void infect_neighbors();

  void print_vector() {
	for(int i=0; i<vec.size(); i++) {
	    cout << "vec[" << i << "]: " << vec[i].get_status() << endl;
	}
  }

  double get_percent_vaccinated(){
	return percentVaccinated;
  }

};


