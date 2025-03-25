#include "student.h"
#include <iostream>
#include <iomanip>

// Default Constructor
Student::Student() : 
    studentID(""), 
    firstName(""), 
    lastName(""), 
    emailAddress(""), 
    age(0), 
    degreeProgram(SOFTWARE) 
{
    daysInCourse[0] = 0;
    daysInCourse[1] = 0;
    daysInCourse[2] = 0;
}

// Parameterized Constructor
Student::Student(std::string studentID, std::string firstName, std::string lastName, 
                 std::string emailAddress, int age, int daysInCourse1, 
                 int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) :
    studentID(studentID),
    firstName(firstName),
    lastName(lastName),
    emailAddress(emailAddress),
    age(age),
    degreeProgram(degreeProgram)
{
    daysInCourse[0] = daysInCourse1;
    daysInCourse[1] = daysInCourse2;
    daysInCourse[2] = daysInCourse3;
}

// Destructor
Student::~Student() {
    // No dynamic memory to free in this implementation
}

// Getter Methods
std::string Student::getStudentID() const {
    return studentID;
}

std::string Student::getFirstName() const {
    return firstName;
}

std::string Student::getLastName() const {
    return lastName;
}

std::string Student::getEmailAddress() const {
    return emailAddress;
}

int Student::getAge() const {
    return age;
}

const int* Student::getDaysInCourse() const {
    return daysInCourse;
}

DegreeProgram Student::getDegreeProgram() const {
    return degreeProgram;
}

// Setter Methods
void Student::setStudentID(std::string studentID) {
    this->studentID = studentID;
}

void Student::setFirstName(std::string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(std::string lastName) {
    this->lastName = lastName;
}

void Student::setEmailAddress(std::string emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
    daysInCourse[0] = daysInCourse1;
    daysInCourse[1] = daysInCourse2;
    daysInCourse[2] = daysInCourse3;
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

// Print Method
void Student::print() const {
    // Convert degree program to string
    std::string degreeString;
    switch(degreeProgram) {
        case SECURITY: degreeString = "SECURITY"; break;
        case NETWORK: degreeString = "NETWORK"; break;
        case SOFTWARE: degreeString = "SOFTWARE"; break;
    }

    std::cout << std::left 
              << studentID << "\t"
              << "First Name: " << firstName << "\t"
              << "Last Name: " << lastName << "\t"
              << "Age: " << age << "\t"
              << "daysInCourse: {" << daysInCourse[0] << ", " 
              << daysInCourse[1] << ", " 
              << daysInCourse[2] << "} "
              << "Degree Program: " << degreeString 
              << std::endl;
}