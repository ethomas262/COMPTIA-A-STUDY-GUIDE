# Quiz Application

This C++ program is a simple quiz application that reads questions from a CSV file, presents them to the user, collects their responses, and then evaluates and prints the results.

## How to Use

1. **Compile the Code:**
   - Compile the C++ code using a C++ compiler.

2. **Prepare Questions File:**
   - Ensure you have a CSV file named "PracticeQuestions.csv" containing the quiz questions. The format should be as follows:
     ```
     Question,Option1,Option2,Option3,Option4,CorrectAnswer
     ```

3. **Run the Executable:**
   - Execute the compiled program.
   
4. **Take the Quiz:**
   - Answer each question by entering the corresponding letter (A, B, C, or D).

5. **View Results:**
   - After completing the quiz, the program will display your results, indicating correct and incorrect answers.

## Code Overview

- The code defines a `Question` structure to store quiz questions and options.
- Questions are loaded from the "PracticeQuestions.csv" file into a vector of `Question` structures.
- The user takes the quiz, providing answers to each question.
- The program then evaluates the answers and prints the results.

## Code Structure

- `loadQuestions`: Reads questions from the CSV file and populates the `questions` vector.
- `prompt`: Displays a question and its options to the user.
- `getResponse`: Collects and validates the user's response.
- `TakeTest`: Conducts the quiz and returns a vector of user answers.
- `convertAns`: Converts the user's answer into its corresponding option.
- `printResults`: Displays the quiz results, indicating correct and incorrect answers.
- `main`: The entry point of the program.

## Dependencies

- This program relies on a CSV file named "PracticeQuestions.csv" for quiz data.

Feel free to customize the questions file and modify the code to suit your quiz needs.
