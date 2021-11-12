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
     * @brief  Overloads insertion operator for ostream so Task object can
     *         be printed to standard output easier and neater.
     *
     * @param  output An output stream object by reference.
     * @param  T      A Task object by reference.
     * @return ostream&
     */
    friend ostream &operator<<(ostream &output, const Task &T);

    /**
     * @brief  Overloads insertion operator for ofstream so Task object can
     *         be printed to output file easier and neater.
     *
     * @param  outfile An output file stream by reference.
     * @param  T       A Task object by reference.
     * @return ofstream&
     */
    friend ofstream &operator<<(ofstream &outfile, const Task &T);

    /**
     * @brief  Overloads insertion operator for istream so Task object can
     *         be assigned values from standard input easier.
     *
     * @param  input An input stream object by reference.
     * @param  T     A Task object by reference.
     * @return istream&
     */
    friend istream &operator>>(istream &input, Task &T);

    /**
     * @brief  Overloads insertion operator for ifstream so Task object can
     *         be assigned values from an input file easier.
     *
     * @param  infile An input file by reference.
     * @param  T      A Task object by reference.
     * @return ifstream&
     */
    friend ifstream &operator>>(ifstream &infile, Task &T);
};

/**
 * @brief  Construct a new Task object with default values.
 *
 * @return Nothing.
 */
Task::Task()
{
    this->start_time = 0;
    this->length = 0;
    this->end_time = 0;
}

/**
 * @brief  Construct a new Task object using parameters, and calculates the
 *         end time by adding start time and length.
 *
 * @param  s_t An integer, start time of the task.
 * @param  len An integer, duration of the task.
 *
 * @return Nothing.
 */
Task::Task(int s_t, int len)
{
    this->start_time = s_t;
    this->length = len;
    this->end_time = s_t + len;
}

/**
 * @brief  Overloads insertion operator for ostream so Task object can
 *         be printed to standard output easier and neater.
 *
 * @param  output An output stream object by reference.
 * @param  T      A Task object by reference.
 * @return ostream&
 */
ostream &operator<<(ostream &output, const Task &T)
{
    output << right << setw(3) << T.start_time << setw(10)
           << T.length << setw(10)
           << T.end_time;
    return output;
}

/**
 * @brief  Overloads insertion operator for ofstream so Task object can
 *         be printed to output file easier and neater.
 *
 * @param  outfile An output file stream by reference.
 * @param  T       A Task object by reference.
 * @return ofstream&
 */
ofstream &operator<<(ofstream &outfile, const Task &T)
{
    outfile << right << setw(3) << T.start_time << setw(10)
            << T.length << setw(10)
            << T.end_time;
    return outfile;
}

/**
 * @brief  Overloads insertion operator for istream so Task object can
 *         be assigned values from standard input easier.
 *
 * @param  input An input stream object by reference.
 * @param  T     A Task object by reference.
 * @return istream&
 */
istream &operator>>(istream &input, Task &T)
{
    input >> T.start_time >> T.length;
    T.end_time = T.start_time + T.length;
    return input;
}

/**
 * @brief  Overloads insertion operator for ifstream so Task object can
 *         be assigned values from an input file easier.
 *
 * @param  infile An input file by reference.
 * @param  T      A Task object by reference.
 * @return ifstream&
 */
ifstream &operator>>(ifstream &infile, Task &T)
{
    infile >> T.start_time >> T.length;
    T.end_time = T.start_time + T.length;
    return infile;
}