#ifndef RC_CIRCUIT_H
#define RC_CIRCUIT_H

//The minimum implementation of an RC circuit class
class RCCircuit 
{
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

class Controller 
{
    private:
        double trgV;
        double maxOUT;
        double minOUT;
    
    public:
        Controller(double targetVoltage, double maximumOutputVoltage, double minimumOutputVoltage)
        :trgV(targetVoltage)
        ,maxOUT(maximumOutputVoltage)
        ,minOUT(minimumOutputVoltage)
        {
            
        }
        double calculateOutput(double currentVoltage)
        {
            if (currentVoltage >= trgV){
                return minOUT;
            }
            else if (currentVoltage < trgV)
            {
                return maxOUT;
            }
            else
            {
                return minOUT;
            }
        }

};

#endif
