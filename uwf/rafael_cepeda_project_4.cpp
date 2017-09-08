/*
 * File name: rafael_cepeda_project_4.cpp
 * Author: Rafael Cepeda
 * Email: r.cepeda@linux.com, rlc50@students.uwf.edu
 * Assignment Number: 4
 * Last Changed: 02 September 2017
 *
 * Compile with:
 * c++ --std=c++11 rafael_cepeda_project_4.cpp
 */
#include <iostream>
#include <fstream>
#include <iterator>
#define SENTINEL -1

using namespace std;

/* makes the assumption that
 * sales data is never neg.
 */
double * getsales()
{
    cout << "Enter file name: ";

    string fname;
    cin >> fname;

    ifstream fin(fname);

    if (fin.fail()) {
        return nullptr;
    }

    istream_iterator<double> iter(fin);

    const auto size { static_cast<int>(*iter++) };

    //free-store alloc'd in case of large input
    //+1 for sentinel val
    const auto dat { new double[size+1] };

    for (auto i = 0; i < size; i++) {
        dat[i] = *iter++;
    }

    dat[size] = SENTINEL;
    return dat;
}

class stats {
    public:
        double min, max, avg, sum;
        stats(double *dat);
};

stats::stats(double *dat)
{
    int i;
    double s, m, n;
    m = n = *dat;
    for (i = 0; dat[i] != SENTINEL; i++) {
        s += dat[i];
        if (dat[i] > m) {
            m = dat[i];
        }
        if (dat[i] < n) {
            n = dat[i];
        }
    }
    sum = s;
    avg = sum / (i+1);
    max = m;
    min = n;
}


int main()
{
    const auto data { getsales() };

    if (data == nullptr) {
        cerr << "Unable to open file.\n";
        return 1;
    }

    stats s(data);

    delete data;

    cout.precision(2);
    cout << fixed
         << "The total sales are " << s.sum << endl
         << "The average sales amount is " << s.avg << endl
         << "The highest sales amount is " << s.max << endl
         << "The lowest sales amount is " << s.min << endl;
}
