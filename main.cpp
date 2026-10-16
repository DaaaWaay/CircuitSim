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
    GUI GUI;
    //Set some values here
    GUI.titleScreen();

    double R        = GUI.getR();
    double C        = GUI.getC();
    double L        = GUI.getL();
    bool iscontroller = GUI.getControll();
    double targetVoltage = 0;
    double maxVoltage = 0;
    double minVoltage = 0;
    double propotonalK = 0;
    double vin = 0;

    if (iscontroller)
    {
        targetVoltage = GUI.getTargetVoltage();
        maxVoltage = GUI.getmaxVoltage();
        minVoltage = GUI.getminVoltage();
        propotonalK = GUI.getPorportaonalK();
    }
    else
    {
        vin = GUI.getVin();
    }

    double dt       = 0.01;
    double duration = 5.0;
    
    int resolution = GUI.getRes();

    //Calculate the steps
    int steps = (int)(duration / dt);

    //Initialize the plotter object
    Plotter plotter;
             
    //initalize the controller object
    Controller controller(targetVoltage, maxVoltage, minVoltage , propotonalK);
    //Initialize your circuit object
    RCCircuit circuit(R, C, L);
    if (!(iscontroller))
    {
        circuit.setVin(vin);
    } 
    else
    {
        circuit.setVin(controller.calculateOutputProp(circuit.getVc()));
    }
    // Store the results
    vector<double> results;

    cout << "Initialized " << endl;

    //Simulate the circuit over time
    for (int i = 1; i <= steps; i++) {
        circuit.step(dt); //Step the simulation by dt
        results.push_back(circuit.getVc()); //Add result to the results vector
        if (iscontroller)
        {
            circuit.setVin(controller.calculateOutputProp(circuit.getVc()));
        }
    }

    
    //uses the plotter.h i made
    for (int i = 0; i < results.size(); i += resolution){
        if (iscontroller)
        {
            plotter.plotLine(results[i], maxVoltage );
        }
        else
        {
            plotter.plotLine(results[i], vin );
        }
    }
}