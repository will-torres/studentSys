#include "roster.h"
#include <iostream>
#include <string>

// Default Constructor
Roster::Roster() : capacity(5), studentCount(0) {
    classRosterArray = new Student*[capacity]();
}

// Parameterized Constructor
Roster::Roster(int capacity) : capacity(capacity), studentCount(0) {
    classRosterArray = new Student*[capacity]();
}

// Destructor
Roster::~Roster() {
    // Free each dynamically allocated Student object
    for (int i = 0; i < studentCount; ++i) {
        delete classRosterArray[i];
    }
    // Free the array of pointers
    delete[] classRosterArray;
}

// Add a new student to the roster
void Roster::add(std::string studentID, std::string firstName, std::string lastName, 
                 std::string emailAddress, int age, int daysInCourse1, 
                 int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    // Check if there's space in the roster
    if (studentCount < capacity) {
        // Create a new Student object and add to the roster
        classRosterArray[studentCount] = new Student(
            studentID, firstName, lastName, emailAddress, age, 
            daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram
        );
        studentCount++;
    } else {
        std::cout << "Roster is full. Cannot add more students." << std::endl;
    }
}

// Remove a student from the roster by student ID
void Roster::remove(std::string studentID) {
    bool found = false;
    
    // Find the student with the given ID
    for (int i = 0; i < studentCount; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            // Delete the student object
            delete classRosterArray[i];
            
            // Shift remaining elements to fill the gap
            for (int j = i; j < studentCount - 1; ++j) {
                classRosterArray[j] = classRosterArray[j + 1];
            }
            
            // Decrease student count and mark as found
            studentCount--;
            found = true;
            break;
        }
    }
    
    // Print message if student not found
    if (!found) {
        std::cout << "Student with ID " << studentID << " not found." << std::endl;
    }
}

// Print all students in the roster
void Roster::printAll() {
    for (int i = 0; i < studentCount; ++i) {
        classRosterArray[i]->print();
    }
}

// Print average days in course for a specific student
void Roster::printAverageDaysInCourse(std::string studentID) {
    for (int i = 0; i < studentCount; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            const int* days = classRosterArray[i]->getDaysInCourse();
            double average = (days[0] + days[1] + days[2]) / 3.0;
            
            std::cout << "Student ID: " << studentID 
                      << ", Average days in course: " << average 
                      << std::endl;
            return;
        }
    }
    
    std::cout << "Student with ID " << studentID << " not found." << std::endl;
}

// Print invalid email addresses
void Roster::printInvalidEmails() {
    std::cout << "Invalid Email Addresses:" << std::endl;
    
    for (int i = 0; i < studentCount; ++i) {
        std::string email = classRosterArray[i]->getEmailAddress();
        
        // Check for invalid email conditions
        bool hasAt = email.find('@') != std::string::npos;
        bool hasPeriod = email.find('.') != std::string::npos;
        bool hasSpace = email.find(' ') != std::string::npos;
        
        // Print email if it's invalid
        if (!hasAt || !hasPeriod || hasSpace) {
            std::cout << email << std::endl;
        }
    }
}

// Print students in a specific degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    std::cout << "Students in " 
              << (degreeProgram == SECURITY ? "SECURITY" : 
                  degreeProgram == NETWORK ? "NETWORK" : "SOFTWARE") 
              << " program:" << std::endl;
    
    for (int i = 0; i < studentCount; ++i) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}
