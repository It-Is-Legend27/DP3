#pragma once

#include <ostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Task
{
public:
    int start_time; // Start time of task
    int length;     // Duration of task
    int end_time;   // End time of task

    /**
     * @brief  Construct a new Task object with default values.
     * 
     * @return Nothing.
     */
    Task();

    /**
     * @brief  Construct a new Task object using parameters, and calculates the
     *         end time by adding start time and length.
     * 
     * @param  s_t An integer, start time of the task.
     * @param  len An integer, duration of the task.
     * 
     * @return Nothing.
     */
    Task(int s_t, int len);

    /**
     * @brief  Construct a new Task object using an input file. Calculates
     *         end time by adding start time and length.
     * 
     * @param  infile An input file stream by reference.
     * 
     * @return Nothing.
     */
    Task(ifstream &infile);

    /**
     * @brief  Overloads ostream so Task object can be printed to standard
     *         output easier and neater.
     * 
     * @param  os An output stream object by reference.
     * @param  T  A Task object by reference.
     * @return ostream&
     */
    friend ostream &operator<<(ostream &os, const Task &T);

    // Purpose:  Overloads ofstream so Task object can be printed to output
    //           file easier.
    // Receives: ofstream &of, ofstream object (output file) by reference,
    //           const Task &T, Task object by reference
    // Returns:  ostream &of, ofstream object by reference
    //           (containing Task object data)
    friend ofstream &operator<<(ofstream &of, const Task &T);
};

// Purpose:  Constructs a Task object with default values
// Receives: Nothing
Task::Task()
{
    this->start_time = 0;
    this->length = 0;
    this->end_time = 0;
}

// Purpose:  Constructs a Task object using parameters, and calculates
//           end_time by adding start_time and length.
// Receives: int s_t, start time of the task, int len, duration of the task.
Task::Task(int s_t, int len)
{
    this->start_time = s_t;
    this->length = len;
    this->end_time = s_t + len;
}

// Purpose:  Constructs a Task object using input file, and calculates
//           end_time by adding start_time and length.
// Receives: ifstream &infile, ifstream object (input file) by reference.
Task::Task(ifstream &infile)
{
    infile >> this->start_time;
    infile >> this->length;
    this->end_time = this->start_time + this->length;
}

// Purpose:  Overloads ostream so Task object can be printed to standard
//           output easier.
// Receives: ostream &os, ostream object (standard output) by reference,
//           const Task &T, Task object by reference
// Returns:  ostream &os, ostream object by reference
//           (containing Task object data)
ostream &operator<<(ostream &os, const Task &T)
{
    os << right << setw(3) << T.start_time << setw(10)
       << T.length << setw(10)
       << T.end_time;
    return os;
}

// Purpose:  Overloads ofstream so Task object can be printed to output
//           file easier.
// Receives: ofstream &of, ofstream object (output file) by reference,
//           const Task &T, Task object by reference
// Returns:  ostream &of, ofstream object by reference
//           (containing Task object data)
ofstream &operator<<(ofstream &of, const Task &T)
{
    of << right << setw(3) << T.start_time << setw(10)
       << T.length << setw(10)
       << T.end_time;
    return of;
}
