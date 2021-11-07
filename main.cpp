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
#include <list>
using namespace std;

const int MIN = 1;  // Minimum value for n
const int MAX = 20; // Maximum value for n

bool earlierEnd(const Task &rhs, const Task &lhs)
{
    return (rhs.end_time < lhs.end_time);
}
// Purpose:  Prompts user for names of input & output file, then opens them.
// Receives: ifstream object by reference, input file,
//           ofstream object by reference, output file
// Returns:  ifstream and ofstream by reference (input and output file)
void openFiles(ifstream &infile, ofstream &outfile);

void getData(ifstream &infile, vector<Task> &arr, int size);

void insertionSort(vector<Task> &arr);

int findMin(const vector<Task> &arr);

void print(vector<Task> &arr);

// Purpose:  Determines whether n is 1 <= n <= 20
// Receives: int n by value, an integer
// Returns:  bool value 0 or 1, 1 if valid, 0 if invalid
bool isValid(int n);

int main()
{
    ifstream infile;    // Input file stream
    ofstream outfile;   // Output file stream
    infile.open("GreedyData1.txt");
    outfile.open("output1.txt");
    int n;              // Number of activities(tasks) to process
    vector<Task> tasks; // Vector containing N task objects
    vector<Task> schedule;
    

    // Opens i/o files
    // openFiles(infile, outfile);

    // Prints header and column names to output file
    outfile << "Angel Badillo\n"
            << "Program 3: Greedy Scheduling\n\n";

    infile >> n;

    getData(infile, tasks, n);

    insertionSort(tasks);

    print(tasks);

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

// Purpose: Gets data from input file and stores it in a vector
// Receives: ifstream &infile, ofstream object (input file) by reference,
//           vector<Task> &arr, a vector of Task objects,
//           int size, number of activities per file
//
void getData(ifstream &infile, vector<Task> &arr, int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        arr.push_back(Task(infile));
    }
}

void insertionSort(vector<Task> &arr)
{
    int i, j;
    Task temp;

    for (i = 0; i < arr.size(); i++)
    {
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j].end_time > temp.end_time)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}

int findMin(const vector<Task> &arr)
{
    int minVal = arr[0].end_time;
    int minIndex = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i].end_time < minVal)
        {
            minVal = arr[i].end_time;
            minIndex = i;
        }
    }
    return minIndex;
}

void print(vector<Task> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << '\n';
    }
}

// Purpose:  Determines whether n is 1 <= n <= 100
// Receives: int n by value, an integer
// Returns:  bool value 0 or 1, 1 if valid, 0 if invalid
bool isValid(int n)
{
    return MIN <= n && n <= MAX;
}