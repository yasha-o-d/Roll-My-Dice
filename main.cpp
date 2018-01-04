//  main.cpp
//  Jesse's Actual Second Challenge
//  Created by Yasha Ormut Durbin on 1/4/18.
//  Copyright © 2018 Yasha Ormut Durbin. All rights reserved.

#include <iostream>
using namespace std;

int main() {
    int nDice = 10;                                     //Defines number of dice to be rolled
    int nSides = 6;                                     //Defines number of side per dice
    int nSims = 1e8;                                    //Defines number of simulations
    int Rolls[nDice];                                   //Initializes Array of rolls per simulation
    int reUse = nDice*nSides;                           //Used twice in code
    int SumCount[reUse];                                //Initializes Array for the sum counter
    SumCount[reUse] = {0};                              //Set all values to 0
    int Sum = 0;                                        //Initialize sum to 0
    
    for (int sim = 0; sim < nSims; sim++){              //Increments through each simulation
        
        for (int i = 0; i < nDice; i++){                //Increments through dice per simulation
            
            Rolls[i] = (rand() % nSides)+1;             //Generates random roll
            Sum+=Rolls[i];                              //Adds up sum of all rolls for a given simulation
        }
        
        SumCount[Sum-1]++;                              //Counter for the sum of rolls for a given simulation
        Sum = 0;                                        //Resets sum of all rolls for a given simulation
    }
    
    for (int k = 0; k < reUse; k++){                    //Displays counter values
        cout << "A sum of " << k+1 << " was rolled " << SumCount[k] << " times." << endl;
    }
    
    return 0;
}


