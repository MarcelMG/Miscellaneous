/*  a little exerceice creating a class for mathematical matrix operations
 *
 *  written in 2019 by Marcel Meyer-Garcia
 *  see LICENCE.txt
 * */
#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{

    cout << "enter new matrix A rows:" << endl;
    int rows, columns;
    cin>>rows;
    cin.ignore();
    cout<<"A columns"<<endl;
    cin>>columns;
    cin.ignore();

    matrix A(rows, columns);
    A.enter_data();
    A.print();

    cout<<"transpose"<<endl<<"A'="<<endl;
    matrix AT = A.transpose();
    AT.print();

    cout<<"exponent:";
    double exp;
    cin>>exp;
    cout<<"A^"<<exp<<"="<<endl;
    matrix Aexp = A^exp;
    Aexp.print();
    cout<<"create a unity matrix of dimension:";
    cin >> rows;
    unity(rows).print();

    cout <<endl<<"enter new matrix B rows:" << endl;
    cin>>rows;
    cin.ignore();
    cout<<"B columns"<<endl;
    cin>>columns;
    cin.ignore();

    matrix B(rows, columns);
    B.enter_data();
    B.print();

    matrix C = A*B;
    cout<<endl<<endl<<"C=A*B="<<endl;
    C.print();
    matrix D = A+B;
    cout<<endl<<endl<<"D=A+B="<<endl;
    D.print();
    matrix E = A-B;
    cout<<endl<<endl<<"E=A-B="<<endl;
    E.print();
    cout<<"enter scalar x:";
    double x;
    cin>>x;
    cout<<"A*x=";
    matrix F = A*x;
    F.print();

    cout<<"press any key to exit";
    cin.ignore();
    cin.get();


    return 0;
}
