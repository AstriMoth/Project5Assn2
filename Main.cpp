#include <fstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct STUDENT_DATA {
	string firstName;
	string lastName;
};


vector<STUDENT_DATA> ParseStudentData(string fileName) {
	vector<STUDENT_DATA> studentVector;
	STUDENT_DATA student;
	string buffer;
	string delimiter = ", ";
	vector<string> names;
	size_t pos;
	ifstream StudentData(fileName);

	while (!StudentData.eof()) {
		getline(StudentData, buffer);
		
		pos = buffer.find(",");
		student.lastName = buffer.substr(0, pos);
		buffer.erase(0, pos + 2);
		student.firstName = buffer;
		studentVector.push_back(student);
	}

	return studentVector;
}



void main() 
{

}