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
#include <algorithm>
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
 * @brief Sorts the vector of tasks via insertion
 *        sort, sorting the tasks by increasing end time.
 *
 * @param vect A vector of type Task by reference.
 *
 * @return Nothing.
 */
void sortEndTime(vector<Task> &vect);

/**
 * @brief Sorts the vector of tasks via insertion
 *        sort, sorting the tasks by increasing duration (length).
 *
 * @param vect A vector of type Task by reference.
 *
 * @return Nothing.
 */
void sortLength(vector<Task> &vect);

/**
 * @brief Finds the index of the task with minimum length in the vector of
 *        tasks.
 *
 * @param vect A vector of type Task by reference
 *
 * @return Nothing
 */
int findMinLength(const vector<Task> &vect);

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
    infile.open("GreedyData1.txt");
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

    if (isValid(0))
    {
        tasks.resize(n);        // Sets the vector to size N
        getData(infile, tasks); // Gets data from input file
        sortEndTime(tasks);     // Sorts by end times via insertion sort

        schedule.push_back(tasks[0]); // Push Task that ends the earliest

        vector<Task> temp = tasks;    // Temp vector sorted by length
        temp.erase(temp.begin());
        
        int j = 0;
        for(int i = 0; i < temp.size(); i++)
        {
            if(schedule[j].end_time < temp[i].start_time)
            {
                
                schedule.push_back(temp[i]);
                j++;
            }
        }
        for(int i = 0; i < schedule.size(); i++)
        {
            cout << schedule[i] << '\n';
        }

    }

    tasks.resize(11);
    getData(infile, tasks);
    sortEndTime(tasks);
    for(Task y: tasks)
    {
        cout << y << '\n';
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
 * @brief Sorts the vector of tasks via insertion
 *        sort, sorting the tasks by earliest to latest end time.
 *
 * @param vect A vector of type Task by reference.
 *
 * @return Nothing.
 */
void sortEndTime(vector<Task> &vect)
{
    int i, j;
    Task temp;

    for (i = 0; i < vect.size(); i++)
    {
        temp = vect[i];
        j = i - 1;

        while (j >= 0 && vect[j].end_time > temp.end_time)
        {
            vect[j + 1] = vect[j];
            j = j - 1;
        }
        vect[j + 1] = temp;
    }
}

/**
 * @brief Sorts the vector of tasks via insertion
 *        sort, sorting the tasks by increasing length.
 *
 * @param vect A vector of type Task by reference.
 *
 * @return Nothing.
 */
void sortLength(vector<Task> &vect)
{
    int i, j;
    Task temp;

    for (i = 0; i < vect.size(); i++)
    {
        temp = vect[i];
        j = i - 1;

        while (j >= 0 && vect[j].length > temp.length)
        {
            vect[j + 1] = vect[j];
            j = j - 1;
        }
        vect[j + 1] = temp;
    }
}

Task findMinStartNEnd(vector<Task> &vect)
{
    Task minVal = vect[0];

    for (int i = 0; i < vect.size(); i++)
    {
        if ((vect[i].start_time < minVal.start_time) && (vect[i].length == minVal.length))
        {
            minVal = vect[i];
        }
    }
    return minVal;
}

void removeAll(vector<Task> &vect, int len)
{
    for(vector<Task>::iterator it = vect.begin(); it!= vect.end(); ++it)
    {
        if(it->length == len)
        {
            vect.erase(it);
        }
    }
}
/*void sortLength(vector<Task> &vect)
{

    for(vector<Task>::iterator i = vect.begin(); i != vect.end()-1; i++)
    {
        vector<Task>::iterator minimum = i;
        for(vector<Task>::iterator j = i+1; j < vect.end(); j++)
        {
            if(j->length < minimum->length)
            {
                minimum = j;
            }
        }
        // Find the minimum element in unsorted array
        iter_swap(minimum, i);
    }
}*/

/**
 * @brief Sorts the vector of type Task via insertion
 *        sort, sorting the tasks by end time.
 *
 * @param vect A vector of type Task by reference
 *
 * @return Nothing
 */
int findMinLength(const vector<Task> &vect)
{
    int minVal = vect[0].length;
    int minIndex = 0;

    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i].length < minVal)
        {
            minVal = vect[i].length;
            minIndex = i;
        }
    }
    return minIndex;
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
