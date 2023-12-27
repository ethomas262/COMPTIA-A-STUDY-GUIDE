#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Define a structure to represent a question
struct Question {
	string prompt;
	string Option1;
	string Option2;
	string Option3;
	string Option4;
	char CorrectAnswer;
};

// Global vector to store loaded questions
vector<Question> questions;

// Function to load questions from a CSV file
void loadQuestions(vector<Question>* vector) {
	// Open the CSV file
	ifstream input_file;
	input_file.open("PracticeQuestions.csv", ios::in);

	// Check if the file is opened successfully
	if (!input_file.is_open()) {
		throw runtime_error("Error: File not opened correctly");
	}

	// Variables to store temporary values while reading CSV
	string temp_Question, temp_1, temp_2, temp_3, temp_4, temp_answer;
	string line;
	bool firstLine = true;

	// Read each line from the CSV file
	while (getline(input_file, line)) {
		stringstream ss(line);
		string item;

		// Parse CSV values
		getline(ss, temp_Question, ',');
		getline(ss, temp_1, ',');
		getline(ss, temp_2, ',');
		getline(ss, temp_3, ',');
		getline(ss, temp_4, ',');
		getline(ss, temp_answer, ',');

		// Create a new Question and add it to the vector
		vector->push_back(Question{ temp_Question, temp_1, temp_2, temp_3, temp_4, temp_answer[0] });
	}
}

// Function to prompt the user with a question
void prompt(Question* question) {
	printf("%s \n", question->prompt.c_str());
	printf("A:  %s\n", question->Option1.c_str());
	printf("B:  %s\n", question->Option2.c_str());
	printf("C:  %s\n", question->Option3.c_str());
	printf("D:  %s\n", question->Option4.c_str());
}

// Function to get and validate user response
char getResponse() {
	char response;
	bool invalidResponse = true;
	cin >> response;

	// Validate the user's response
	while (invalidResponse) {
		switch (response) {
		case 'A':
		case 'B':
		case 'C':
		case 'D':
			invalidResponse = false;
			return response;
		default:
			invalidResponse = true;
			printf("Error: Invalid entry, try again...");
			cin >> response;
			break;
		}
	}
}

// Function to take the quiz and return user answers
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

// Function to convert the user's answer into its corresponding option
string convertAns(Question* question, char input) {
	switch (input) {
	case 'A':
		return question->Option1;
	case 'B':
		return question->Option2;
	case 'C':
		return question->Option3;
	default:
		return question->Option4;
	}
}

// Function to print quiz results
void printResults(vector<Question> questions, vector<char> answers) {
	unsigned int numQuestions = questions.size();

	for (int i = 0; i < numQuestions; i++) {
		if (answers.at(i) == questions.at(i).CorrectAnswer) {
			printf("Question %d: %s : Correct!! %s \n\n", i + 1, questions.at(i).prompt.c_str(), convertAns(&questions.at(i), answers.at(i)).c_str());
		}
		else {
			printf("Question %d: %s : Incorrect-> Correct Answer: %c %s \n\n", i + 1, questions.at(i).prompt.c_str(), questions.at(i).CorrectAnswer, convertAns(&questions.at(i), questions.at(i).CorrectAnswer).c_str());
		}
	}
}

// Main function
int main() {
	vector<Question> questions;

	// Load questions from the CSV file
	loadQuestions(&questions);

	// Take the quiz and get user answers
	vector<char> answers = TakeTest(questions);

	// Print quiz results
	printResults(questions, answers);

	return 0;
}
