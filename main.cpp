/****************************************************************************
 * Name: Angel Badillo
 *
 * Course: CMPS-2433-101, Fall 2021, Springfellow
 *
 *  Purpose:
 *
 ****************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Task.hpp"
#include "Task.hpp"
using namespace std;

const int MIN = 1;  // Minimum value for n
const int MAX = 20; // Maximum value for n

// Purpose:  Prompts user for names of input & output file, then opens them.
// Receives: ifstream object by reference, input file,
//           ofstream object by reference, output file
// Returns:  ifstream and ofstream by reference (input and output file)
void openFiles(ifstream &infile, ofstream &outfile);

/*int main()
{
    ifstream infile;  // Input file stream
    ofstream outfile; // Output file stream
    int n;            // Number of activities to process
    vector<Task> tasks;
    // Opens i/o files
    openFiles(infile, outfile);

    // Prints header and column names to output file
    outfile << "Angel Badillo\n"
            << "Program 3: Greedy Scheduling\n\n";
            
    infile.close();
    outfile.close();
    return 0;
}*/

int main()
{
    Task t1(1,2);
    cout << t1;
}

// Purpose:  Prompts user for names of input & output file, then opens them.
// Receives: ifstream object by reference, input file,
//           ofstream object by reference, output file
// Returns:  ifstream and ofstream by reference (input and output file)
void openFiles(ifstream &infile, ofstream &outfile)
{
    string inFileName;  // std::strings are better
    string outFileName; // in my opinion v. c-strings

    cout << "Enter the input file name: ";
    cin >> inFileName;

    infile.open(inFileName); // Open input file
    cout << "Enter the output file name: ";

    cin >> outFileName;
    outfile.open(outFileName); // Open output file
}
