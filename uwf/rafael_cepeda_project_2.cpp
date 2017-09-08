/*
 * File name: rafael_cepeda_project_2.cpp
 * Author: Rafael Cepeda
 * Email: r.cepeda@linux.com, rlc50@students.uwf.edu
 * Assignment Number: 2
 * Last Changed: 29 August 2017 
 */
#include <iostream>
#include <cmath>
#define INVALID -1

using namespace std;

enum pkgtype { A, B, C };
int basecosts[] = { 15, 25, 50 };

signed char
getpkg(char in)
{
    switch (in) {
    case 'A':
    case 'a':
        return A;
    case 'B':
    case 'b':
        return B;
    case 'C':
    case 'c':
        return C;
    default:
        return -1;
    }
}

signed int
mbrange(int mb)
{
    return (mb >= 0 && mb <= 10000) - 1;
}

float
pkgcharge(enum pkgtype pkg, int mb)
{
    int base = basecosts[pkg], thresh = 0;
    float rate, fee = 0;

    if (pkg == A) {
        thresh = 200;
        rate = 0.06;
    } else if (pkg == B) {
        thresh = 2000;
        rate = 0.02;
    } else if (pkg != C) {
        base = -1;
    }

    if (thresh && mb > thresh)
        fee = (mb-thresh) * rate;

    return base + fee;
}

void
display_savings(float charges, int mb, enum pkgtype pkg)
{
    string ptnames[] = { "A", "B", "C" };
    float delta = pkgcharge(pkg, mb) - charges;
    if (delta < 0) {
        cout << "By switching to Package "
             << ptnames[pkg]
             << " you would save $"
             << abs(delta) << endl;
    }
}

int
main(int argc, char const* argv[])
{
    char pkg;
    do {
        cout << "Which package does the customer use (A, B, or C)? ";
        cin >> pkg;
    } while ((pkg = getpkg(pkg)) == INVALID);

    int mb;
    do {
        cout << "How many MB did the customer use last month? (0--10000) ";
        cin >> mb;
    } while (mbrange(mb) == INVALID);

    float charges = pkgcharge((enum pkgtype) pkg, mb);
    cout << "The charges are $" << charges << endl;

    /* show potential savings by upgrading package */
    if (charges != basecosts[pkg]) {
        if (pkg == A) {
            display_savings(charges, mb, B);
            display_savings(charges, mb, C);
        } else if (pkg == B) {
            display_savings(charges, mb, C);
        }
    }

    return 0;
}
