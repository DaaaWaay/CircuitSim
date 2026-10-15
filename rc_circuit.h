#ifndef RC_CIRCUIT_H
#define RC_CIRCUIT_H

//The minimum implementation of an RC circuit class
class RCCircuit 
{
    public:
        RCCircuit(double resistance, double capacitance, double inductance)
        :R(resistance)
        ,C(capacitance)
        ,L(inductance)
        {

        }
        void setVin(double volts) // Sets the input voltage vin
        {
            vin = volts;
        }
        void step(double dt) // Updates Vc to the next time step
        {
            I +=(vin - R * I - vc) / L * dt;
            vc += I / C * dt;
        }

        double getVc(){
            return vc;
        }
        // Add other methods here.... e.g. getTimeConstant(), reset()...
        // Think about it yourself, what might be useful to add?

    private:
        double R;
        double C;
        double L;
        double I = 0;
        double vin = 0;
        double vc = 0;
};

class Controller 
{
    private:
        double trgV;
        double maxOUT;
        double minOUT;
        double K;
    
    public:
        Controller(double targetVoltage, double maximumOutputVoltage, double minimumOutputVoltage, double K)
        :trgV(targetVoltage)
        ,maxOUT(maximumOutputVoltage)
        ,minOUT(minimumOutputVoltage)
        ,K(K)
        {
            
        }
        double calculateOutputBANGBANG(double currentVoltage)
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

        double calculateOutputProp(double currentVoltage)
        {
            double newV = -(currentVoltage - trgV) * K;
            if (newV > maxOUT)
            {
                return maxOUT;
            }
            if (newV < minOUT)
            {
                return minOUT;
            }
            return newV;
        }

};

#endif
