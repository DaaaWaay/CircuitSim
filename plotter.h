#include <iomanip>
#include <iostream>
#include <vector>
#include <cstdio>

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
    void plotLine(float value, float vin, int i, int dt)
    {
        printf("%.3fV %.3fs  |", value, i * dt);
        int number_of_space = (value / vin) * width;
        for(int i = number_of_space; i > 0; i--)
        {
        printf(" ");
        }
            
        printf("*\n");
        return;
        }
    
    };
