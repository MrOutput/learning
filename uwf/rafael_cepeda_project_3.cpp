/*
 * File name: rafael_cepeda_project_3.cpp
 * Author: Rafael Cepeda
 * Email: r.cepeda@linux.com, rlc50@students.uwf.edu
 * Assignment Number: 3
 * Last Changed: 31 August 2017 
 */
#include <iostream>

using namespace std;

const double M_PER_FT = 0.3048;

double
m2ft(double m)
{
    return m / M_PER_FT;
}

double
ft2m(double ft)
{
    return ft * M_PER_FT;
}

double
quad_area_m2ft(double l, double w)
{
    return m2ft(l*w);
}

double
quad_area_ft2m(double l, double w)
{
    return ft2m(l*w);
}

int
menu() {
    int sel;

    cout << "English-Metric Junior" << endl
         << "    1) Convert from meters to feet" << endl
         << "    2) Convert from feet to meters" << endl
         << "    3) Compute the area of a rectangle in square feet given length and width in meters" << endl
         << "    4) Compute the area of a rectangle in square meters given the length and width in feet" << endl
         << "    5) Quit the Program" << endl;

    do {
        cout << "Please enter a number (1-5) -> ";
        cin >> sel;
    } while ((sel<1) || (sel>5));

    return sel;
}

void
display_m2ft()
{
    double m;

    cout << "Meters: ";
    cin >> m;

    cout << endl << m << "m is " << m2ft(m) << "ft." << endl;
}

void
display_ft2m()
{
    double ft;

    cout << "Feet: ";
    cin >> ft;

    cout << endl << ft << "ft is " << ft2m(ft) << "m." << endl;
}

void
display_qarea_ft2m()
{
    double l, w;

    cout << "Length (ft): ";
    cin >> l;
    cout << "Width (ft): ";
    cin >> w;

    cout << endl << "Area is " << ft2m(l*w) << "m^2." << endl;
}

void
display_qarea_m2ft()
{
    double l, w;

    cout << "Length (m): ";
    cin >> l;
    cout << "Width (m): ";
    cin >> w;

    cout << endl << "Area is " << m2ft(l*w) << "ft^2." << endl;
}

int
main(int argc, char const* argv[])
{
    enum selection { M2FT = 1, FT2M, QAREA_FT2M, QAREA_M2FT };

    for (;;) {
        int sel = menu();

        if (sel == M2FT) {
            display_m2ft();
        } else if (sel == FT2M) {
            display_ft2m();
        } else if (sel == QAREA_FT2M) {
            display_qarea_ft2m();
        } else if (sel == QAREA_M2FT) {
            display_qarea_m2ft();
        } else {
            return 0;
        }

        cout << endl;
    }
}
