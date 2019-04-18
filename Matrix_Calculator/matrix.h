/*  a little exerceice creating a class for mathematical matrix operations
 *
 *  written in 2019 by Marcel Meyer-Garcia
 *  see LICENCE.txt
 * */
#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct dimension{
    unsigned int rows;
    unsigned int columns;
};

class matrix{
public:
    matrix(unsigned int rows, unsigned int columns);
    bool enter_data();
    dimension get_dimension();
    vector<vector<double>> get_values();
    bool change_value(unsigned int row, unsigned int column, double new_value);
    void print();
    matrix operator*(matrix&);
    matrix operator*(double);
    matrix operator+(matrix&);
    matrix operator-(matrix&);
    matrix transpose();
    matrix operator^(int);
    matrix operator^(double);
private:
    dimension dim;
    vector<vector<double>> values;
};

matrix unity(unsigned int dim);

#endif // MATRIX_H_INCLUDED
