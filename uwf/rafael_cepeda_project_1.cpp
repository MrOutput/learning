/*
 * File name: rafael_cepeda_project_1.cpp
 * Author: Rafael Cepeda
 * Email: r.cepeda@linux.com, rlc50@students.uwf.edu
 * Assignment Number: 1
 * Last Changed: 29 August 2017 
 */
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/* Calculates compound interest
 * Formula derived from: wikipedia.org/wiki/Compound_interest
 */
float
cmpd_interest(float prin, float rate, int freq, int years)
{
    return prin * pow((1+rate/freq), freq*years);
}

int
main(int argc, char const* argv[])
{
    float bal, iprin, limit, rate;
    int year;

    cout << "Credit Card Balance: ";
    cin >> bal;

    cout << "Card Limit: ";
    cin >> limit;

    cout << "Interest Rate (whole number): ";
    cin >> rate;
    cout << endl;

    rate /= 100;

    cout.precision(2);
    cout.setf(ios_base::fixed);
    for (year = 1; year < 4; year++) {
        /* assumes yearly compound */
        iprin = cmpd_interest(bal, rate, 1, year);

        cout << "Year " << year << ": " << iprin;
        if (iprin > limit) {
            float diff = iprin - limit;
            cout << " (over by " << diff << ")";
        }
        cout << endl;
    }

    return 0;
}
