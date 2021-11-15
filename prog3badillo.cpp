/****************************************************************************
 * Name: Angel Badillo
 *
 * Course: CMPS-2433-101, Fall 2021, Springfellow
 *
 * Purpose: The program is designed to create a schedule using a greedy
 *          algorithm approach. It prompts the user for i/o file names,
 *          determines if the input file is valid (i.e, number of Tasks
 *          must be in the closed interval [1,20]). Reads in tasks from
 *          input file to vector, sorts by increasing end time via selection
 *          sort. Builds schedule using the vector. Initializes schedule with
 *          first task from sorted vector, the next task in the vector
 *          is put in the schedule if it starts after the first one ends, 
 *          and so on. Then, prints out the schedule to the output file and 
 *          the maximum number of tasks that can be performed.
 *
 ****************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

const int MIN_N = 1;  // Minimum value for n (number of tasks)
const int MAX_N = 20; // Maximum value for n (numbers of tasks)

struct Task
{
    int start_time; // Start time of task
    int length;     // Duration of task
    int end_time;   // End time of task

    /**
     * @brief  Construct a new Task object with default values.
     */
    Task() : start_time{0}, length{0}, end_time{0} {}
};

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
void sortEndTime(vector<Task> &vect);

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
 * @brief Creates a schedule using a vector of Tasks sorted by increasing
 *        order. A task is included if the start time is <= the end time of
 *        the previous.
 *
 * @param tasks A vector of tasks (sorted by increasing order).
 * @param schedule An empty vector to put the schedule in.
 * @return Nothing.
 */
void scheduleBuilder(vector<Task> &tasks, vector<Task> &schedule);

/**
 * @brief Prints the contents of the vector containing the schedule
 *        to an output file.
 *
 * @param infile   An output file object by reference.
 * @param schedule A vector of type Task by reference.
 *
 * @return Nothing.
 */
void printSchedule(ofstream &outfile, const vector<Task> &schedule);

int main()
{
    ifstream infile;  // Input file stream
    ofstream outfile; // Output file stream
    int n;            // Number of activities (tasks) to process

    cout << "Angel Badillo\n"
         << "Program 3: Greedy Scheduling\\Sorting Program\n\n";

    openFiles(infile, outfile); // Prompts for file names & opens them
    
    infile >> n;

    if (MIN_N <= n && n <= MAX_N) // False if n is not 1 <= n <= 20
    {
        vector<Task> tasks(n, Task()); // Vector containing N task objects
        vector<Task> schedule;         // Vector for schedule

        getData(infile, tasks); // Gets data from input file
        sortEndTime(tasks);     // Sorts by end times via selection sort

        scheduleBuilder(tasks, schedule);

        outfile << "Angel Badillo\n"
                << "Program 3: Greedy Scheduling\\Sorting Program\n\n";

        printSchedule(outfile, schedule);
    }
    else
    {
        cout << "Invalid input file!\n"
        << "I.e, number of activities is invalid, empty file, "
        << "or wrong format.\n"
        << "Number of activities, n, must be 1 <= n <= 20\n";
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
 * @param  infile input file stream by reference.
 * @param  vect    A vector of type Task by reference.
 *
 * @return Nothing.
 */
void getData(ifstream &infile, vector<Task> &vect)
{
    for (int i = 0; i < vect.size(); i++)
    {   
        // Reads in from input file
        infile >> vect[i].start_time >> vect[i].length;

        // Calculates end time
        vect[i].end_time = vect[i].start_time + vect[i].length;
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
void sortEndTime(vector<Task> &vect)
{
    for (int i = 0; i < vect.size()-1; i++)
    {
        int min = i; // Index of found min value
        for (int j = i + 1; j < vect.size(); j++)
        {
            // If end time at current element is smaller than the prev min element,
            // update index of min
            if (vect[j].end_time < vect[min].end_time)
            {
                min = j;
            }
        }
        // Swaps elements
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

/**
 * @brief Creates a schedule using a vector of Tasks sorted by increasing
 *        order. A task is included if the start time is <= the end time of
 *        the previous.
 *
 * @param tasks A vector of tasks (sorted by increasing order).
 * @param schedule An empty vector to put the schedule in.
 * @return Nothing.
 */
void scheduleBuilder(vector<Task> &tasks, vector<Task> &schedule)
{
    schedule.push_back(tasks[0]); // Push Task that ends the earliest

    int i, j;
    for (i = 1, j = 0; i < tasks.size(); i++)
    {
        if (schedule[j].end_time <= tasks[i].start_time) // If start of next
        {                                                // task is <= end of
            schedule.push_back(tasks[i]);                // next task, include
            j++;                                         // it in the schedule
        }
    }
}

/**
 * @brief Prints the contents of the vector containing the schedule
 *        to an output file.
 *
 * @param infile   An output file object by reference.
 * @param schedule A vector of type Task by reference.
 *
 * @return Nothing.
 */
void printSchedule(ofstream &outfile, const vector<Task> &schedule)
{
    // Column Headings
    outfile << right << "Start_Time" << setw(11)
            << "Length" << setw(14) << "End_Time\n";

    // Prints start time, length, end time (in that order)
    // of each Task in the schedule
    for (int i = 0; i < schedule.size(); i++)
    {
        outfile << right << setw(2) << schedule[i].start_time
                << setw(15) << schedule[i].length
                << setw(11) << schedule[i].end_time << '\n';
    }

    outfile << "\nMaximum number of activities scheduled is " << schedule.size() <<'.';
}