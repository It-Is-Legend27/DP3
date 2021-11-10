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
 * @param  infile file stream stream by reference. 
 * @param  arr    A vector of type Task by reference.
 * @param  size   Number of tasks in the input file.
 * 
 * @return Nothing.
 */
void getData(ifstream &infile, vector<Task> &arr, int size);

/**
 * @brief Sorts the vector of tasks via insertion
 *        sort, sorting the tasks by earliest to latest end time.
 *
 * @param arr A vector of type Task by reference.
 *
 * @return Nothing.
 */
void insertionSort(vector<Task> &arr);

/**
 * @brief Sorts the vector of type Task via insertion
 *        sort, sorting the tasks by end time.
 *
 * @param arr A vector of type Task by reference
 *
 * @return Nothing
 */
int findMin(const vector<Task> &arr);

/**
 * @brief Prints the contents of the vector of tasks.
 * 
 * @param arr A vector of type Task by reference.
 * 
 * @return Nothing. 
 */
void print(const vector<Task> &arr);

/**
 * @brief Tests an integer, n, to determine if it follows 1 <= n <= 20.
 * 
 * @param n An integer in the interval [1,20].
 * @return True if n is within [1,20], false otherwise.
 */
bool isValid(const int n);

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
 * @param  arr    A vector of type Task by reference.
 * @param  size   Number of tasks in the input file.
 *
 * @return Nothing.
 */
void getData(ifstream &infile, vector<Task> &arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        //
        arr.push_back(Task(infile));
    }
}

/**
 * @brief Sorts the vector of tasks via insertion
 *        sort, sorting the tasks by earliest to latest end time.
 *
 * @param arr A vector of type Task by reference.
 *
 * @return Nothing.
 */
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

/**
 * @brief Sorts the vector of type Task via insertion
 *        sort, sorting the tasks by end time.
 *
 * @param arr A vector of type Task by reference
 *
 * @return Nothing
 */
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

void print(const vector<Task> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << '\n';
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
