#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "student.h"
#include "degree.h"

class Roster {
private:
    int capacity;
    int studentCount;
    Student** classRosterArray;

public:
    // Constructor
    Roster();
    
    // Parameterized Constructor
    Roster(int capacity);

    // Destructor
    ~Roster();

    // Add a new student to the roster
    void add(std::string studentID, std::string firstName, std::string lastName, 
             std::string emailAddress, int age, int daysInCourse1, 
             int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

    // Remove a student from the roster by student ID
    void remove(std::string studentID);

    // Print all students in the roster
    void printAll();

    // Print average days in course for a specific student
    void printAverageDaysInCourse(std::string studentID);

    // Print invalid email addresses
    void printInvalidEmails();

    // Print students in a specific degree program
    void printByDegreeProgram(DegreeProgram degreeProgram);
};

#endif // ROSTER_H