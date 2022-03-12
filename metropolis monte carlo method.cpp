#include <iostream>
#include <math.h>
double f_rand(void);

int main( )
{
    srand((unsigned)time(NULL));
    double g = 1;
    double x = 1;
    double y = 1;
    double m = 1;
    double kT = 1;
    double k = 1;
    double fsc = 1 / 137.;
    double E1=0; 
    double E2=0; 
    double a = 0.05;
    int nmax = 10000000;
    double E1a;
    double E2a;
    double dEa;
    double E1b;
    double E2b;
    double dEb;
    for (int i = 0; i < nmax; ++i) {
        double X = x + a * ((2 * f_rand()) - 1);
        double Y = y + a * ((2 * f_rand()) - 1);

        E1a = 0.5 * k * x * x;
        E2a = 0.5 * k * X * X;
        dEa = E2a - E1a;
        E1b = 0.5 * k * y * y;
        E2b = 0.5 * k * Y * Y;
        dEb = E2b - E1b;

        if (dEa <= 0) {
            x = X;
        }
        else if (dEa >= 0) {
            if (f_rand() <= exp((-1 * dEa) / (kT))) {
                x = X;
            }
        }
        E1 += (E1a / nmax);

        if (dEb <= 0) {
            y = Y;
        }
        else if (dEb >= 0) {
            if (f_rand() <= exp((-1 * dEb) / (kT))) {
                y = Y;
            }
        }
        E2 += (E1b / nmax);
    }
    std::cout << "x축의 에너지: ";
    std::cout << E1 << std::endl;
    std::cout << "y축의 에너지: ";
    std::cout << E2 << std::endl;
    double Etot = E1 + E2;
    std::cout << "전체 에너지: ";
    std::cout << Etot << std::endl;
    return 0;
}

double f_rand(void)
{
    double a;
    a = rand() / (double)RAND_MAX;
    return a;
}
