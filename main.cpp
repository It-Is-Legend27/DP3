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
#include "task.hpp"

using namespace std;

const int MIN = 1;  // Minimum value for n
const int MAX = 20; // Maximum value for n

// Purpose:  Prompts user for names of input & output file, then opens them.
// Receives: ifstream object by reference, input file,
//           ofstream object by reference, output file
// Returns:  ifstream and ofstream by reference (input and output file)
void openFiles(ifstream &infile, ofstream &outfile);

void getData(ifstream &infile, vector<Task> &tasks, int n);

// Purpose:  Determines whether n is 1 <= n <= 20
// Receives: int n by value, an integer
// Returns:  bool value 0 or 1, 1 if valid, 0 if invalid
bool isValid(int n);

int main()
{
    ifstream infile;    // Input file stream
    ofstream outfile;   // Output file stream
    int n;              // Number of activities(tasks) to process
    vector<Task> tasks; // Vector containing N task objects

    // Opens i/o files
    openFiles(infile, outfile);

    // Prints header and column names to output file
    outfile << "Angel Badillo\n"
            << "Program 3: Greedy Scheduling\n\n";

    infile >> n;

    if (isValid(n))
    {
        getData(infile, tasks, n);

        for (int i = 0; i < n; i++)
        {
            cout << tasks[i];
        }
    }
    else
    {
    }

    infile.close();
    outfile.close();
    return 0;
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

void getData(ifstream &infile, vector<Task> &tasks, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        tasks.push_back(Task(infile));
    }
}

// Purpose:  Determines whether n is 1 <= n <= 100
// Receives: int n by value, an integer
// Returns:  bool value 0 or 1, 1 if valid, 0 if invalid
bool isValid(int n)
{
    return MIN <= n && n <= MAX;
}