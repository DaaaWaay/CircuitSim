#include <iomanip>
#include <iostream>
#include <vector>
#include <cstdio>
#include <limits>

using namespace std;

class Plotter
{   
private:
    const int width;
public:
    Plotter(int width = 60)
    :width(width)
    {
    }
    ~Plotter()
    {
    }
    void plotLine(float value, float vin)
    {
        printf("%.3fV |", value);
        int number_of_space = (value / vin) * width;
        for(int i = number_of_space; i > 0; i--)
        {
        printf(" ");
        }
            
        printf("*\n");
        return;
        }
    
    };

class GUI
{
private:

public:
    GUI()
    {

    }

    void titleScreen()
    {
        cout << "\033[2J\033[1;1H"; // ascii art form google ai thing when you search stuff
        printf("Circuit sim \n"
                            "R                 L                C             \n"
                            "+----//////------+------( ( ( ) ) )------+------| |--+  \n"
                            "|                |                        |           | \n"
                            "|                +------------------------+           | \n"
                            "|                                                     | \n");
        system("pause");
    }

    double getR()
    {
        double R;
        cout << "\033[2J\033[1;1H";

        cout << "Enter Resistor Value eg. 100" << endl;

        while (!(cin >> R))
        {
            cout << "Error: please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return R;
    }
    
    double getC()
    {
        double C;
        cout << "\033[2J\033[1;1H";        
        cout << "Enter Capacitor Value eg. 0.01" << endl;

        while (!(cin >> C))
        {
            cout << "Error: please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return C;
    }

    double getL()
    {
        double L;
        cout << "\033[2J\033[1;1H";        
        cout << "Enter inductor Value" << endl;

        while (!(cin >> L))
        {
            cout << "Error: please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return L;
    }
    
    double getVin()
    {
        double Vin;
        cout << "\033[2J\033[1;1H";

        cout << "Enter input Voltage only for non controll" << endl;

        while (!(cin >> Vin))
        {
            cout << "Error: please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return Vin;
    }

    double getTargetVoltage()
    {
        double Vt;
        cout << "\033[2J\033[1;1H";        
        cout << "Enter Target Voltage. only for controll" << endl;

        while (!(cin >> Vt))
        {
            cout << "Error: please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return Vt;
    }

    double getmaxVoltage()
    {
        double Vmax;
        cout << "\033[2J\033[1;1H";        
        cout << "Enter maximum Voltage should be greater than targetVoltage. only for controll" << endl;

        while (!(cin >> Vmax))
        {
            cout << "Error: please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return Vmax;
    }

    double getminVoltage()
    {
        double Vmin;
        cout << "\033[2J\033[1;1H";        
        cout << "Enter Minimum Voltage, should be less than target voltage. only for controll" << endl;

        while (!(cin >> Vmin))
        {
            cout << "Error: please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return Vmin;
    }

    double getPorportaonalK()
    {
        double k;
        cout << "\033[2J\033[1;1H";        
        cout << "Enter K value. only for controll" << endl;

        while (!(cin >> k))
        {
            cout << "Error: please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return k;
    }
    
    int getRes()
    {
        double Res;
        cout << "\033[2J\033[1;1H";        
        cout << "Enter a resolution for the graph, 1 is full ress, more number less detail" << endl;

        while (!(cin >> Res))
        {
            cout << "Error: please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return Res;
    }
     
    bool getControll()
        {   
            char YorN;
            cout << "Do you want this to be a controll system type Y or N" << endl;
            cin >> YorN;
            if (toupper(YorN) == 'Y')
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};