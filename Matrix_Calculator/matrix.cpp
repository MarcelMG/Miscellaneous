/*  a little exerceice creating a class for mathematical matrix operations
 *
 *  written in 2019 by Marcel Meyer-Garcia
 *  see LICENCE.txt
 * */
 #include "matrix.h"

matrix::matrix(unsigned int rows, unsigned int columns){
    (this->dim).rows = rows;
    (this->dim).columns = columns;
    (this->values).resize(rows, vector<double>(columns));
}
// TODO: make this function more error-proof
bool matrix::enter_data(){
    cout<<"enter values separated by blank spaces, rows by semicolon: ";
    string str;
    getline(cin, str);
    vector<string> row_str((this->dim).rows);
    // extract a sub-string for each row of the matrix, separated by semicolons
    for(unsigned int row_iterator=0; row_iterator < (this->dim).rows; ++row_iterator){
        int semicolon_pos = str.find(';');
        // if we didn't find no semicolon, this is the last row
        if(semicolon_pos == string::npos){
            row_str[row_iterator] = str;
        // extract the sub-string with the values of 1 row
        }else{
            row_str[row_iterator] = str.substr(0, semicolon_pos);
            str.erase(0, semicolon_pos+1);
        }
    }
    // parse row-strings into values to fill the matrix row-data-vectors
    for(unsigned int row_iterator=0; row_iterator < (this->dim).rows; ++row_iterator){
        stringstream sstream;
        sstream<<row_str[row_iterator];
        for(unsigned int column_iterator=0; column_iterator < (this->dim).columns; ++column_iterator){
            sstream>>values[row_iterator][column_iterator];
        }
    }
    return 0;
}
// returns dimension struct, with two members: rows & columns
dimension matrix::get_dimension(){
    return this->dim;
}

vector<vector<double>> matrix::get_values(){
    return this->values;
};
// change one value of the matrix
bool matrix::change_value(unsigned int row, unsigned int column, double new_value){
    if(
    row>(this->dim).rows || column>(this->dim).columns){
        cerr<<"ERROR: index out of range"<<endl;
        return 1;
    }
    this->values[row][column] = new_value;
    return 0;
};

void matrix::print(){
    for(int y=0; y<(this->dim).rows; ++y){
    for(int x=0; x<(this->dim).columns; ++x){
        cout<<this->values[y][x]<<" ";
    }
    cout<<endl;
    }
}

// matrix multiplication
matrix matrix::operator*(matrix& B){
    if( (this->dim).columns != B.get_dimension().rows  ){
        cerr<<"ERROR: dimension mismatch in matrix multiplication"<<endl;
        matrix C(1, 1);
        return C;
    }
    matrix C((this->dim).rows, B.get_dimension().columns);
    for(unsigned int i=0; i<C.get_dimension().rows; ++i){
        for(unsigned int k=0; k<C.get_dimension().columns; ++k){
            double result = 0;
            for(unsigned int j=0; j<(this->dim).columns; ++j){
                result += (this->values[i][j]) * (B.get_values()[j][k]);
            }
            C.change_value(i,k,result);
        }
    }
    return C;
};

// multiply matrix with a scalar
matrix matrix::operator*(double scalar){
    matrix C((this->dim).rows, (this->dim).columns);
    for(unsigned int i=0; i<(this->dim).rows; ++i){
        for(unsigned int k=0; k<(this->dim).columns; ++k){
            double result = (this->values[i][k]) * scalar;
            C.change_value(i,k,result);
        }
    }
    return C;
}
// matrix (element-wise) addition
matrix matrix::operator+(matrix& B){
    if( (this->dim).columns != B.get_dimension().columns || (this->dim).rows != B.get_dimension().rows  ){
        cerr<<"ERROR: dimension mismatch in matrix addition"<<endl;
        matrix C(1, 1);
        return C;
    }
    matrix C((this->dim).rows, (this->dim).columns);
    for(unsigned int i=0; i<(this->dim).rows; ++i){
        for(unsigned int k=0; k<(this->dim).columns; ++k){
            double result = (this->values[i][k]) + (B.get_values()[i][k]);
            C.change_value(i,k,result);
        }
    }
    return C;
}
// matrix (element-wise) subtraction
matrix matrix::operator-(matrix& B){
    if( (this->dim).columns != B.get_dimension().columns || (this->dim).rows != B.get_dimension().rows  ){
        cerr<<"ERROR: dimension mismatch in matrix subtraction"<<endl;
        matrix C(1, 1);
        return C;
    }
    matrix C((this->dim).rows, (this->dim).columns);
    for(unsigned int i=0; i<(this->dim).rows; ++i){
        for(unsigned int k=0; k<(this->dim).columns; ++k){
            double result = (this->values[i][k]) - (B.get_values()[i][k]);
            C.change_value(i,k,result);
        }
    }
    return C;
}
// transposition
matrix matrix::transpose(){
    matrix B((this->dim).columns, (this->dim).rows);
    for(unsigned int i=0; i<(this->dim).rows; ++i){
        for(unsigned int k=0; k<(this->dim).columns; ++k){
            B.change_value(k,i,this->values[i][k]);
        }
    }
    return B;
}
// exponential
matrix matrix::operator^(int exponent){
    // check if matrix is quadratic
    if( (this->dim).columns != (this->dim).rows ){
        cerr<<"ERROR: exponentiation only defined for quadratic matrices"<<endl;
        return *this;
    }
    // if exponent is zero, return unity matrix
    if( exponent==0 ){
        return unity((this->dim).columns);
    }
    if( exponent==-1){
        cerr<<"sadly, matrix inversion is not (yet?) implemented."<<endl;
        return *this;
    }
    // calculate exponential of matrix by multiple multiplication
    for(unsigned int i=1; i<exponent; ++i){
        *this = (*this)*(*this);
    }
    return *this;
}

matrix matrix::operator^(double exponent){
    cerr<<"ERROR: exponent must be a positive integer or 0 or -1"<<endl;
}
// create a unity matrix of certain dimension
matrix unity(unsigned int dim){
    if(dim==0){
        cerr<<"ERROR: zero dimension not defined"<<endl;
        dim = 1;
    }
    matrix I(dim, dim);
    for(unsigned int i=0; i<dim; ++i){
        for(unsigned int k=0; k<dim; ++k){
            if(i==k){
                I.change_value(i,k,1);
            }else{
                I.change_value(i,k,0);
            }
        }
    }
    return I;
}









