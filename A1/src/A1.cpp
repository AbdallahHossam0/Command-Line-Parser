/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <A1.cpp>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: <4 - 4 -2021>
 *
 * [DESCRIPTION]: <Programming Assignment #1: Command Parser>
 * ---------------------------------------------------------------------------------------------------
 */

#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
using namespace std;

void printCommand(int argc, char **argv);
void reverseCommand(int argc, char **argv);
void upperCommand(int argc, char **argv);
void shuffleWordCommand(int argc, char **argv);
void shuffleStatementCommand(int argc, char **argv);
void deleteCommand(int argc, char **argv);
void middleCommand(int argc, char **argv);
void addCommand(int argc, char **argv);
void randomCommand(int argc, char **argv);

void toUpper(char*);
bool isNumber(const string&);

int main(int argc, char *argv[]) {
	bool definedCommandFlag = false, definedMinNoOfArg = false;
	char command[][20] = {"print", "reverse", "upper", "shuffle", "shuffleStatement", "delete", "middle", "add", "random"};

	void (*funcCommandPrt[])(int, char**) = {printCommand, reverseCommand, upperCommand, shuffleWordCommand, shuffleStatementCommand, deleteCommand, middleCommand, addCommand,randomCommand};

	for(int counter = 0; counter < 9; counter++){
		if(!(strcmp(command[counter], argv[1]))){
			switch(argc){
			case 1:
			case 2:
				cout << "Incorrect Number of Arguments";
				break;
			default:
				definedMinNoOfArg = true;
				break;
			}
			if(definedMinNoOfArg)
				funcCommandPrt[counter](argc, argv);
			definedCommandFlag = true;
		}
	}
	if(!definedCommandFlag)
		cout << "Undefined Command";
	return 0;
}
void printCommand(int argc, char **argv){
	for(int counter = 2; counter < argc; counter++){
		cout << argv[counter];
		if(counter != argc - 1){
			cout << " ";
		}
	}
}

void reverseCommand(int argc, char **argv){

	for(int counter = 2; counter < argc; counter++){
		cout << argv[argc + 1 - counter];
		if(counter != argc - 1){
			cout << " ";
		}
	}
}
void upperCommand(int argc, char **argv){
	for(int counter = 2; counter < argc; counter++){
		toUpper(argv[counter]);
		cout << argv[counter];
		if(counter != argc - 1){
			cout << " ";
		}
	}

}

void shuffleWordCommand(int argc, char **argv){
	if(argc > 3){
		cout << "Incorrect Number of Arguments";
	}
	else{
		for(unsigned int counter = 0; counter < strlen(argv[2]) - 1; counter += 2){
			argv[2][counter] 	= argv[2][counter] ^ argv[2][counter+1];
			argv[2][counter+1] 	= argv[2][counter] ^ argv[2][counter+1];
			argv[2][counter] 	= argv[2][counter] ^ argv[2][counter+1];
		}
		cout << argv[2];
	}

}

void shuffleStatementCommand(int argc, char **argv){
	for(int counter = 2; counter < argc - 1; counter += 2){
		swap(argv[counter], argv[counter + 1]);
	}
	printCommand(argc, argv);
}

void deleteCommand(int argc, char **argv){

	if(!isNumber(argv[2])){
		cout << "Incorrect Data Type";
		return;
	}
	int deleteIndex = stoi(argv[2]);
	if(argc < 4 || argc < deleteIndex + 2){
		cout << "Incorrect Number of Arguments";
		return;
	}
	else if(deleteIndex < 1){
			cout << "Incorrect Data Type";
			return;
		}
	else{
		for(int counter = 3; counter < argc; counter++){
			if(counter == 2 + deleteIndex){
				continue;
			}
			else{
				cout << argv[counter];
				if(counter != argc -1){
					cout << " ";
				}
			}
		}
	}
}

void middleCommand(int argc, char **argv){
	if(argc % 2){
		cout << argv[(argc / 2) + 1];
	}
	else
		cout << argv[argc / 2] << " " << argv[(argc / 2) + 1];
}

void addCommand(int argc, char **argv){
	int sum = 0;
	for(int counter = 2; counter < argc; counter++){
		if(isNumber(argv[counter])){
			sum += stoi(argv[counter]);
		}
		else{
			cout << "Incorrect Data Type";
			return;
		}
	}
	cout << sum;
}

void randomCommand(int argc, char **argv){
	if(argc != 6){
		cout << "Incorrect Number of Arguments";
		return;
	}
	else{
		for(int counter = 2; counter < 6; counter++){
			if(!isNumber(argv[counter])){
				cout << "Incorrect Data Type";
				return;
			}
		}
		srand(stoi(argv[5]));
		if(stoi(argv[2]) < 1 || stoi(argv[3]) > stoi(argv[4])){
			cout << "Incorrect Data Type";
			return;
		}
		for(int counter = 0; counter < stoi(argv[2]); counter++){
			cout << stoi(argv[3]) + (rand() % (stoi(argv[4]) - stoi(argv[3]) + 1));
			cout << " ";
		}
	}
}

void toUpper(char* string){
	for(int counter = 0; counter[string] != '\0'; counter++){
		if(counter[string] > 96 && counter[string] < 123)
			string[counter] &= ~(0x20);
	}
}

bool isNumber(const string& string)
{
	for (char const &c : string) {
		if (!isdigit(c) && c != 45)
			return false;
	}
	return true;
}
