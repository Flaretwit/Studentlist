
#include <vector>
#include <string.h>
#include <iostream>
#include <string>
#define ADD 1
#define PRINT 2
#define DELETE 3
#define EXIT 4

using namespace std;
struct Student {
	char first[80];
	char last[80];
	int id;
	float gpa;
};
char* getInput();
int parseCommand(char*input);
void addEntry(vector<Student*> *list);
void deleteEntry(vector<Student*> *list);
void printAll(vector<Student*> *list);

int main() {
	char *input;
	vector<Student*> *list = new vector<Student*>();
	bool continueoperations = true;
	while(continueoperations == true) {
		cin.clear();
		cout << "Do you want to: ADD, DELETE, PRINT or EXIT?" << endl;
		input = getInput();
		cout << "Input: " << input << "end" << endl;
		switch(parseCommand(input)) {
			case ADD:
				addEntry(list);
				break;
			case DELETE:
			//if it returns 1, there is such an entry;
				deleteEntry(list);
				break;
			case PRINT:
				printAll(list);
				break;
			case EXIT:
				continueoperations = false;
				break;
			case 0:
				cout << "You didn't enter a valid command.";
				break;
		}
			
	}
	
return 0;

}

char* getInput() {
	char *input = new char[80];
	bool valid = false;
	while(valid == false) {
		cin.getline(input, 80);	
		valid = true;
	       if(cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please enter in nontroll input.";
			valid = false;			
	       }	       
	return input;
}
}
void printAll(vector<Student*> *list) { 
	for(int i = 0; i < list->size(); i++) {
		cout << list->at(i)->first << " " << list->at(i)->last << ", " << list->at(i)->id
			<< ", " << list->at(i)->gpa << endl;
	}
}

int parseCommand(char *input) {
	if(!strcmp(input, "ADD")) {
		return ADD;
	}
	else if(!strcmp(input, "PRINT")) {
		return PRINT;
	}
	else if(!strcmp(input, "DELETE")) {
		return DELETE;
	}	
	else if(!strcmp(input, "EXIT")) {
		return EXIT;
	}
	else {
		return 0;
	}
}

void addEntry(vector<Student*> *list) {
	bool valid;
	Student *student = new Student();
	while(!valid) {
		cout << "Enter first name: ";
		cin >> student->first;
		if(!cin.fail()) {
			valid = true;
		} else {
			cout << "Invalid input. Enter a string." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}

	}
	cin.clear();
	valid = false;

	//deals with last name
	cout << "Enter last name: ";
	while(!valid) {
		cin >> student->last;
		if(!cin.fail()) {
			valid = true;
		} else {
			cout << "Invalid input. Enter a string." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}

	}	
	cin.clear();
	valid = false;
	
	//deals with id
	cout << "Enter ID number: ";
	while(!valid) {
		cin >> student->id;
		if(!cin.fail()) {
				valid = true;
		} else {
			cout << "Invalid input. Enter an integer." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	cin.clear();	
	//deals with gpa
	valid = false;
	cout << "Enter GPA: ";
	while(!valid) {
		cin >> student->gpa;
		if(!cin.fail()) {
			valid = true;
		} else {
			cout << "Invalid input. Enter a decimal." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	
	}
	cin.ignore();
	list->push_back(student);
	cout << "Student added." << endl;
}

//deletes an entry by ID of student
//returns if successful, if not, outputs that it failed
void deleteEntry(vector<Student*> *list) {
	bool valid;
	int id;
	cin.ignore(1000, '\n');
	cin.clear();
	cout << "Enter the id of the student you want to delete: " << endl;
	while(!valid) {
		cin >> id;
		if(!cin.fail()) {
			valid = true;
		} else {
			cout << "Enter an integer.";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	
	for(int i = 0; i < list->size(); i++) {
		if(list->at(i)->id == id) {
			list->erase(list->begin() +i);
			cout << "Deleted student" << endl;
			return;
		}
	}
	cout << "Student was not found in database" << endl;
	
}
