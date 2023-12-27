#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;

struct Question {
	string prompt;
	string Option1;
	string Option2;
	string Option3;
	string Option4;
	char CorrectAnswer;
};


vector<Question> questions;

void loadQuestions(vector<Question>* vector) {
	ifstream input_file;
	input_file.open("PracticeQuestions.csv", ios::in);

	if (!input_file.is_open()) {
		throw runtime_error("Error File not Opened Correctly");
	}


	string temp_Question, temp_1, temp_2, temp_3, temp_4, temp_answer;
	
	string line;
	bool firstLine = true;


	while (getline(input_file, line)) {
		stringstream ss(line);
		string item;



		getline(ss, temp_Question, ',');
		
		getline(ss, temp_1, ',');
		getline(ss, temp_2, ',');
		getline(ss, temp_3, ',');
		getline(ss, temp_4, ',');
		getline(ss, temp_answer, ',');

		vector->push_back(Question{ temp_Question, temp_1, temp_2, temp_3, temp_4, temp_answer[0]});
	}
}

void prompt(Question* question) {
	printf("%s \n", question->prompt.c_str());
	printf("A:  %s\n", question->Option1.c_str());
	printf("B:  %s\n", question->Option2.c_str());
	printf("C:  %s\n", question->Option3.c_str());
	printf("D:  %s\n", question->Option4.c_str());
}

char getResponse() {
	char response;
	bool invalidResponse = true;
	cin >> response;

	while (invalidResponse) {
		switch (response) {
		case 'A':
			invalidResponse = false;
			return response;
			break;
		case 'B':
			invalidResponse = false;
			return response;
			break;
		case 'C':
			invalidResponse = false;
			return response;
			break;
		case 'D':
			invalidResponse = false;
			return response;
			break;
		default:
			invalidResponse = true;
			printf("Error: Invalid entry try again...");
			cin >> response;
			break;
		}

	}
	
}

vector<char> TakeTest(vector<Question> questions) {
	char ans;
	vector<char> answers;

	for (auto& question : questions) {
		prompt(&question);
		ans = getResponse();
		answers.push_back(ans);
	}
	return answers;
}
string convertAns(Question* question, char input) {
	switch (input) {
	case 'A':
		return question->Option1;
		break;
	case 'B':
		return question->Option1;
		break;
	case 'C':
		return question->Option3;
		break;
	default:
		return question->Option4;
		break;
	}
	string None;
	return None;
}

void printResults(vector<Question> questions, vector<char> answers) {
	unsigned int numQuestions = questions.size();
	

	for (int i = 0; i < numQuestions; i++) {
		if (answers.at(i) == questions.at(i).CorrectAnswer) {
			
			printf("Question %d: %s : Correct!! %s \n\n", i+1, questions.at(i).prompt.c_str(), convertAns(&questions.at(i), answers.at(i)).c_str());
		}
		else {
			printf("Question %d: %s : Incorrect-> Correct Answer: %c %s \n\n", i+1, questions.at(i).prompt.c_str(), questions.at(i).CorrectAnswer, convertAns(&questions.at(i), questions.at(i).CorrectAnswer).c_str());
		}
	}

}
int main() {
	vector<Question> questions;


	loadQuestions(&questions);


	vector<char> answers = TakeTest(questions);

	printResults(questions, answers);

	return 0;
}