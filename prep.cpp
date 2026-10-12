#include "plotter.h"
#include <vector>
#include <cmath>


int main()
{
    const double PI = 3.14159265358979323846;
    Plotter plotter;   //creates a plotter object with default width 60
    vector<double> an = {5.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
    vector<double> bn = {0.0, 2.0 / PI,         // n = 1
                        -2.0 / (2 * PI),   // n = 2
                        2.0 / (3 * PI),   // n = 3
                        -2.0 / (4 * PI),   // n = 4
                        2.0 / (5 * PI)};  // n = 5

    double  period         = 1.0;   // period T of the signal
    int     numPeriods     = 2;     // how many repeats to show
    int     pointsPerPeriod = 40;   // rows per period

    // Store the results
    vector<double> results;

    for (int i = 1; i < pointsPerPeriod * numPeriods * period; i++)
    {
        double t = i * period / pointsPerPeriod;   // time for this sample
        double sum = an[0] / 2;                    // DC term

        for (int n = 1; n < an.size(); n++)
        {
            sum += an[n] * cos(2 * PI * n * t / period)
                + bn[n] * sin(2 * PI * n * t / period);
        }

        results.push_back(sum);
    }   

    for (int i = 1; i < pointsPerPeriod * numPeriods * period; i++)
    {
        plotter.plotLine(results[i], 5, i, pointsPerPeriod);
    }
}