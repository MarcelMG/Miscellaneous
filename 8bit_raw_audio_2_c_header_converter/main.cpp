/*  little code snippet to convert a "RAW headerless unsigned 8bit PCM"
 *  audio file into a C-header file containing the samples as an array
 *
 *  written in 2018 by Marcel Meyer-Garcia
 *  see LICENCE.txt
 * */
#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
using namespace std;

int main(int argc, char* argv[])
{
    if( argc > 3){
        cout << "error: too many arguments!\n";
        return 1;
    }
    if( argc == 2 ){
        if( string(argv[1]) == string("-h") || string(argv[1]) == string("--help") ){
            cout << "this tool converts a RAW(headerless) 8bit unsigned WAVE audio file into a C-array\n";
            cout << "usage:\nfirst argument: name/path to input file\n";
            cout << "second argument: name of output file\n";
            return 0;
        }
        else{
        cout << "error: too few arguments!\n";
        return 1;
        }
    }
    if( argc == 1 ){
        cout << "you must specify arguments. use -h or --help argument for help\n";
        return 1;
    }
    string input_filename = argv[1];
    string output_filename = argv[2];
    ifstream input_file(input_filename);
    if( !input_file ){
        cout << "error opening " << input_filename << "\n";
        return 1;
    }
    ofstream output_file( output_filename + string(".h") );
    if( !output_file ){
        cout<<"error opening " << output_filename << "\n";
        return 1;
    }
    // determine length of input file
    input_file.seekg(0, ios::end);
    unsigned int length = input_file.tellg() + 1;
    // return to beginning of the file
    input_file.seekg(0);
    // convert name to uppercase for the #define
    char uppercase_output_filename[20];
    string tmp_str(output_filename);
    tmp_str.copy(uppercase_output_filename, tmp_str.length(), 0);
    uppercase_output_filename[tmp_str.length()] = '\0';
    char* str = uppercase_output_filename;
    while (*str){
        *(str++) = toupper(*str);
    }
    // create header file
    output_file << "#ifndef " << uppercase_output_filename << "_H\n#define " << uppercase_output_filename << "_H";
    output_file << "\n\n#define " << uppercase_output_filename << "_LENGTH " << length;
    output_file << "\n\nconst uint8_t " << output_filename << "[" << length << "] = {\n\t";
    // write sample values in header file
    unsigned int i = 0;
    while( !input_file.eof() && !output_file.eof() && !input_file.fail() && !output_file.fail() ){
        // newline after 10 values
        if( i<10 ){
            ++i;
        }else{
            output_file << '\n' << '\t';
            i = 0;
        }
        unsigned int tmp = (uint8_t) input_file.get();
        output_file << tmp;
        if(!input_file.eof()){
            output_file << ", ";
        }
    }
    input_file.close();
    output_file << "};\n#endif";
    output_file.close();
    cout << "finished successfully!\n" << endl;
    return 0;
}
