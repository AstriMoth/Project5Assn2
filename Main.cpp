#include <fstream>
#include <vector>
#include <string>
#include <iostream>

//#define PRE_RELEASE

using namespace std;

struct STUDENT_DATA {
	string firstName;
	string lastName;
	string email;
};

#ifdef _DEBUG
#define LOG(x) std::cout << "LOG: " << x << endl;
#endif // _DEBUG


#ifdef PRE_RELEASE
#define INPUT_FILE "StudentData_Emails.txt"
#else
#define INPUT_FILE "StudentData.txt"
#endif
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
		pos = buffer.find(",");
		student.firstName = buffer.substr(0,pos);
		student.email = buffer.substr(pos +1);
		studentVector.push_back(student);
	}

	return studentVector;
}




void main() 
{
	vector<STUDENT_DATA> students;
	students = ParseStudentData(INPUT_FILE);

#ifdef _DEBUG
	#ifdef PRE_RELEASE
		LOG("Running PreRelease Build")
	#else
		LOG("Running Standard Build")
	#endif
#endif


#ifdef _DEBUG
	#ifdef PRE_RELEASE
		for (STUDENT_DATA student : students) {
			cout << student.firstName << " " << student.lastName << " " << student.email << endl;
		}
	#else
		for (STUDENT_DATA student : students) {
			cout << student.firstName << " " << student.lastName <<  endl;
		}
	#endif
#endif

}