//
//  main.cpp
//  Pi Recipes
//
//  Created by Hitesh Bhatia on 1/26/21.
//

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int    MAX_ITERATIONS = 20;
const double TOLERANCE      = 1.0e-17;

/**
 * Compute the factorial of an integer value.
 * @param n the value.
 * @return n! as a double.
 */
double factorial(int n);

/**
 * Compute the arctangent of a double value.
 * @param x the value.
 * @return an estimate of arctan(x).
 */
double arctangent(double x);

/**
 * Compute an estimate of pi using a formula by Ramanujan.
 * @return an estimate of pi.
 */
void Ramanujan_0();

/**
 * Compute an estimate of pi using a formula by Ramanujan.
 * @return an estimate of pi.
 */
void Ramanujan_1();

/**
 * Compute an estimate of pi using a formula by Ramanujan.
 * @return an estimate of pi.
 */
void Ramanujan_2();

/**
 * Compute an estimate of pi using a formula by the Chudnovsky brothers.
 * @return an estimate of pi.
 */
void Chudnovsky();

/**
 * Compute an estimate of pi using an arctangent formula by Machin.
 * @return an estimate of pi.
 */
void Machin();
/*
int main()
{
    cout << fixed << setprecision(16);

    cout << endl;
    cout << "Ramanujan pi recipe #0:" << endl << endl;
    Ramanujan_0();

    cout << endl;
    cout << "Ramanujan pi recipe #1:" << endl << endl;
    Ramanujan_1();

    cout << endl;
    cout << "Ramanujan pi recipe #2:" << endl << endl;
    Ramanujan_2();

    cout << endl;
    cout << "Chudnovsky pi recipe:" << endl << endl;
    Chudnovsky();

    cout << endl;
    cout << "Machin pi recipe:" << endl << endl;
    Machin();

    return 0;
}
*/

double factorial(int n)
{
    double nf = 1;
    for (int i = 2; i <= n; i++) nf *= i;
    return nf;
}

void Ramanujan_0()
{
    
    double factor0 = 12/sqrt(190);
    double factor1 = 2*sqrt(2) + sqrt(10);
    double factor2 = 3 + sqrt(10);
    
    double pi = factor0 * log(factor1*factor2);
    
    cout<< " Estimate:" <<"  " << pi << endl;
}

void Ramanujan_1()
{
    cout << "  Iteration  Estimate" << endl;

    double one_over_pi;
    double factor0 = sqrt((double) 8)/(99*99);
    double sum  = 0.0;
    double prev = 0.0;
    double diff = 0.0;

    int n = 0;

    do
    {
        double factor1 = factorial(4*n)/pow((pow(4.0, n)*factorial(n)), 4);
        double factor2 = ((double) 1103 + 26390*n)/pow((double) 99, 4*n);

        sum += factor1*factor2;

        one_over_pi = factor0*sum;
        cout << setw(11) << n+1 << "  " << 1.0/one_over_pi << endl;

        diff = abs(prev - one_over_pi);
        prev = one_over_pi;
        n++;
    } while ((diff > TOLERANCE) && (n <= MAX_ITERATIONS));
}

void Ramanujan_2()
{
    
    cout << "  Iteration  Estimate" << endl;
    
    double four_over_pi;
    double factor0 = ((double) 1)/882;
    double sum  = 0.0;
    double prev = 0.0;
    double diff = 0.0;

    int n = 0;
    
    do
    {
        double factor1 = (pow(-1, n)*factorial(4*n))/pow(pow(4,n)*factorial(n), 4);
        double factor2 = ((double)1123 + 21460*n)/pow(882, 2*n);
        
        sum += factor1*factor2;
        four_over_pi = sum*factor0;
        four_over_pi = 4.0/four_over_pi;
        cout << setw(11) << n+1 << "  " << four_over_pi << endl;
        
        diff = abs(prev - four_over_pi);
        prev = four_over_pi;
        n++;
    } while((diff > TOLERANCE) && (n <= MAX_ITERATIONS));
}

void Chudnovsky()
{
    double one_over_pi;
    double factor0 = 12.0;
    double prev = 0.0;
    double diff = 0.0;
    double sum = 0.0;
    
    int n=0;
    do
    {
        double factor1 = (pow(-1, n)*factorial(6*n))/(factorial(3*n)*pow(factorial(n), 3));
        double factor2 = ((double)13591409 + 545140134*n)/pow(pow(640320,3), ((double)n + 0.5));
        
        sum += factor1*factor2;
        one_over_pi = sum*factor0;
        cout << setw(11) << n+1 << "  " << 1.0/one_over_pi << endl;
        
        diff = abs(prev - one_over_pi);
        prev = one_over_pi;
        n++;
    }while((diff > TOLERANCE) && (n <= MAX_ITERATIONS));
}

double arctangent(double x)
{
    double arctan = x;
    int n1 = 0;
    int n2 = 1;
    
    double sum = 0.0;
    double prev = 0.0;
    double diff = 0.0;
    
    do
    {
        sum = (pow(-1, n1)*pow(arctan, n2))/n2;
        diff = abs(prev - sum);
        prev = sum;
        n1++;
        n2 += 2;
    }while(diff < TOLERANCE);
    
    return sum;
}

void Machin()
{
    double pi_over_4 = 4*arctangent(0.2) - arctangent(1.0/239.0);
    cout << "  Estimate:  " << 4*pi_over_4 << endl;
}
