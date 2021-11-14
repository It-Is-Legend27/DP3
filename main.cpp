/****************************************************************************
 * Name: Angel Badillo
 *
 * Course: CMPS-2433-101, Fall 2021, Springfellow
 *
 * Purpose:
 *
 ****************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "task.hpp"

using namespace std;

const int MIN = 1;  // Minimum value for n (number of tasks)
const int MAX = 20; // Maximum value for n (numbers of tasks)

/**
 * @brief Prompts the user for i/o file names. Opens the i/o files and
 *        "returns" them via the arguments passed by reference.
 *
 * @param infile  input file stream by reference.
 * @param outfile output file stream by reference.
 *
 * @return Nothing.
 */
void openFiles(ifstream &infile, ofstream &outfile);

/**
 * @brief  Gets data from the input file and stores it the vector of tasks.
 *
 * @param  infile input file stream by reference.
 * @param  vect    A vector of type Task by reference.
 *
 * @return Nothing.
 */
void getData(ifstream &infile, vector<Task> &vect);

/**
 * @brief Sorts the vector of tasks via selection sort
 *        sort, sorting the tasks by increasing end time.
 *
 * @param vect A vector of type Task by reference.
 *
 * @return Nothing.
 */
void sort(vector<Task> &vect);

/**
 * @brief Swaps the value of the element on the left to the element on
 *        the right and vice-versa.
 *
 * @param lhs A Task object by reference
 * @param rhs A Task object by reference
 * 
 * @return Nothing.
 */
void swapTask(Task &lhs, Task &rhs);

/**
 * @brief Prints the contents of the vector of tasks.
 *
 * @param infile
 * @param vect A vector of type Task by reference.
 *
 * @return Nothing.
 */
void print(ofstream &outfile, const vector<Task> &vect);

/**
 * @brief Tests an integer, n, to determine if it follows 1 <= n <= 20.
 *
 * @param n An integer in the interval [1,20].
 * @return True if n is within [1,20], false otherwise.
 */
bool isValid(const int n);

int main()
{
    ifstream infile;  // Input file stream
    ofstream outfile; // Output file stream
    infile.open("data.txt");
    outfile.open("output1.txt");
    int n;                 // Number of activities(tasks) to process
    vector<Task> tasks;    // Vector containing N task objects
    vector<Task> schedule; // Vector containing schedule

    // Opens i/o files
    // openFiles(infile, outfile);

    // Prints header and column names to output file
    outfile << "Angel Badillo\n"
            << "Program 3: Greedy Scheduling\n\n";

    infile >> n;

    if (isValid(n))
    {
        tasks.resize(n);        // Sets the vector to size N
        getData(infile, tasks); // Gets data from input file
        sort(tasks);            // Sorts by end times via insertion sort

        schedule.push_back(tasks[0]); // Push Task that ends the earliest

        int i, j;
        for (i = 0, j = 0; i < tasks.size(); i++)
        {
            if (schedule[j].end_time <= tasks[i].start_time)
            {
                schedule.push_back(tasks[i]);
                j++;
            }
        }

        cout << "Tasks\n";
        for (Task t : tasks)
        {
            cout << t << '\n';
        }
        cout << "Schedule\n";
        for (int i = 0; i < schedule.size(); i++)
        {
            cout << schedule[i] << '\n';
        }
    }

    infile.close();
    outfile.close();
    return 0;
}

/**
 * @brief Prompts the user for i/o file names. Opens the i/o files and
 *        "returns" them via the arguments passed by reference.
 *
 * @param infile  input file stream by reference.
 * @param outfile output file stream by reference.
 *
 * @return Nothing.
 */
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

/**
 * @brief  Gets data from the input file and stores it the vector of tasks.
 *
 * @param  infile file stream stream by reference.
 * @param  vect    A vector of type Task by reference.
 *
 * @return Nothing.
 */
void getData(ifstream &infile, vector<Task> &vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        infile >> vect[i]; // Reads value from input file for entire Task
                           // object (Overloaded stream insertion ops in
                           // task.hpp)
    }
}

/**
 * @brief Sorts the vector of tasks via selection sort
 *        sort, sorting the tasks by increasing end time.
 *
 * @param vect A vector of type Task by reference.
 *
 * @return Nothing.
 */
void sort(vector<Task> &vect)
{
    int i, j, min;
    for (i = 0; i < vect.size(); i++)
    {
        min = i;
        for (j = i + 1; j < vect.size(); j++)
        {
            if (vect[j].end_time < vect[min].end_time)
            {
                min = j;
            }
        }
        swapTask(vect[min], vect[i]);
    }
}

/**
 * @brief Swaps the value of the element on the left to the element on
 *        the right and vice-versa.
 *
 * @param lhs A Task object by reference
 * @param rhs A Task object by reference
 * 
 * @return Nothing.
 */
void swapTask(Task &lhs, Task &rhs)
{
    Task temp = lhs;
    lhs = rhs;
    rhs = temp;
}

void print(ofstream &outfile, const vector<Task> &vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        outfile << vect[i] << '\n';
    }
}

/**
 * @brief Tests an integer, n, to determine if it follows 1 <= n <= 20.
 *
 * @param n An integer in the interval [1,20].
 * @return True if n is within [1,20], false otherwise.
 */
bool isValid(const int n)
{
    return (MIN <= n && n <= MAX);
}
