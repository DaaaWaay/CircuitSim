#ifndef RC_CIRCUIT_H
#define RC_CIRCUIT_H

//The minimum implementation of an RC circuit class
class RCCircuit {
public:
    RCCircuit(double resistance, double capacitance)
    :R(resistance)
    ,C(capacitance)
    {

    }
    void setVin(double volts) // Sets the input voltage vin
    {
        vin = volts;
    }
    void step(double dt) // Updates Vc to the next time step
    {
        vc += (vin - vc) / (R * C) * dt;
    }

    double getVc(){
        return vc;
    }
    // Add other methods here.... e.g. getTimeConstant(), reset()...
    // Think about it yourself, what might be useful to add?

private:
    double R;
    double C;
    double vin = 0;
    double vc = 0;
};

#endif
