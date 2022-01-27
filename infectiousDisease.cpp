#include "infectiousDisease.h"

using namespace std;




  void Population::infect_contacts(){

    int numContacts = 6;
    for(int i=0; i<vec.size(); i++){
        if(vec[i].is_infected()) {
		
	      for(int j=0; j<contacts; j++) {
		
		double randomNum = rand() % vec.size();
		if(vec[randomNum].is_susceptible()) {
			double randProbability = (rand() % 100 + 1)/(double)100;
			if(randProbability < p) {vec[randomNum].infect(numDaysInfected);}
		}
	      
	      }	
	      
	    }
    }
  }

  void Population::infect_neighbors() {
	

	for(int i = 0; i<vec.size(); i++) {
	   if(vec[i].is_infected()) {
		   if(i>0) {
		     if(vec[i-1].is_susceptible()) {
			double randProbLeft = (rand() % 100 +1)/(double)100;
			if(randProbLeft < p) {vec[i-1].infect(numDaysInfected);}
		     }
		}
		if(i<vec.size()-1){
		     if(vec[i+1].is_susceptible()) {
			double randProbLeft = (rand() % 100 +1)/(double)100;
			if(randProbLeft < p) {vec[i+1].infect(numDaysInfected);}
		     }
		}
	   }		
	
	}
  }

  void Population::random_vaccination(){
	int vaxxed = round(vec.size()*percentVaccinated);
	for( int i=0; i<vaxxed; i++) {
	  int randNum = rand() % vec.size();
	  if(vec[randNum].is_susceptible()) {vec[randNum].vaccinate();}
	  else {i--;}
	}
  }

  void Population::random_infection(){
    bool infectionSuccessful = false;
    while(!infectionSuccessful){

	int randNum = rand() % vec.size() ;
    	vec[randNum].infect(numDaysInfected);
	if(vec[randNum].is_infected()) {infectionSuccessful = true;}

    }
  }


