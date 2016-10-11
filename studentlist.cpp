
#include <vector>
#include <string.h>
#define ADD 1
#define PRINT 2
#define DELETE 3
#define EXIT 4

using namespace std;
parseCommand(char*input);
addEntry(vector<Student*> *list);
struct Student {
	char first[80];
	char last[80];
	int id;
	float gpa;
}
int main() {
	vector<Student*> *list = new vector<Student*>(80);
	bool continueoperations = true;
	while(continueoperations == true) {
		switch(parseCommand(char *input) {
			case ADD:
				
		}	
	}
	
	
return 0;

}

int parseCommand(char *input) {
	if(!strcmp(input, "ADD")) {
		return ADD;
	}
	if(!strcmp(input, "PRINT")) {
		return PRINT;
	}
	if(!strcmp(input, "DELETE")) {
		return DELETE;
	}	
	if(!strcmp(input, "EXIT")) {
		return EXIT;
	}
}

void addEntry(vector<Student*> *list) {
	bool valid;
	cin.push_back(new Student());
	cout << "Enter first name: ";
	while(!valid) {
		cin >> list[list.size() - 1].first;
		if(!cin.fail()) {
			valid = true;
		} else {
			cout << "Invalid input";
			cin.clear();
			cin.ignore(1000, '\n');
		}

	}
	

	//deals with last name
	cout << "Enter last name: ";
	while(!valid) {
		cin >> list[list.size() - 1].last;
		if(!cin.fail()) {
			valid = true;
		} else {
			cout << "Invalid input. Enter a string.";
			cin.clear();
			cin.ignore(1000, '\n');
		}

	}
	//deals with id
	cout << "Enter ID number: ";
	while(!valid) {
		cin >> list[list.size() - 1].id;
		if(!cin.fail()) {
			valid = true;
		} else {
			cout << "Invalid input. Enter an integer.";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	//deals with gpa
	cout << "Enter GPA: ";
	while(!valid) {
		cin >> list[list.size() - 1].gpa;
		if(!cin.fail()) {
			valid = true;
		} else {
			cout << "Invalid input. Enter a decimal.";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}	
}
//deletes an entry
void deleteEntry(vector<Student*> *list) {
	bool valid;
	int id;
	cout << "Enter the id of the student you want to delete: ";
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
	
	for(int i = 0; i < list.size(); i++) {
		if(list[i].id == id) {
			list.erase(id);

		}
	}

}
