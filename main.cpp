//Replace the lines below with your library
//#include "your_graph_library.h"
#include "rc_circuit.h"
#include "plotter.h"

//Usual stuff
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    Plotter plotter;
    //Set some values here
    double R        = 1000.0;
    double C        = 0.001;
    double vin      = 5.0;
    double dt       = 0.01;
    double duration = 5.0;

    //Calculate the steps
    int steps = (int)(duration / dt);

    //Initialize your circuit object
    RCCircuit circuit(R, C);
    circuit.setVin(vin);

    // Store the results
    vector<double> results;

    cout << "Initialized " << endl;

    //Simulate the circuit over time
    for (int i = 1; i <= steps; i++) {
        circuit.step(dt); //Step the simulation by dt
        results.push_back(circuit.getVc()); //Add result to the results vector
    }

    //debug
    //for (auto value : results) {
        //cout << value << " " << endl;
    //}
    
    //uses the plotter.h i made
    for (int i =1; i <= results.size(); i += 5){
        plotter.plotLine(results[i], vin, i, dt);
    }
}