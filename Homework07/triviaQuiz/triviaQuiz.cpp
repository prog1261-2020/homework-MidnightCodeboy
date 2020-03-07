/**
* @file triviaQuiz.cpp
*
* @author  Joseph Roy-Plommer
* @version <1.0>
* @date 2020-03-06
*
* @section Academic Integrity
*  I certify that this work is solely my own and complies with
*  NBCC Academic Integrity Policy (policy 1111)
*
* @section DESCRIPTION
*	Presents a series of questions and options for answers. Asks the user to select among the options.
*   Then checks to see if the answer is correct.
*
* @section LICENSE
*  <any necessary attributions>
*
*  Copyright 2019
*  Permission to use, copy, modify, and/or distribute this software for
*  any purpose with or without fee is hereby granted, provided that the
*  above copyright notice and this permission notice appear in all copies.
*
*  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
*  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
*  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
*  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
*  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
*  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
*  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Question.h"

int main()
{
    // Set up variables
    std::vector<Question> questions;
    int score = 0;

    std::cout << "Gex Quiz" << std::endl << std::endl;

    // Load data from file
    std::cout << "Attempting to open quiz file...";

    std::ifstream questionsFile("quiz.txt", std::ios::in);

    if (!questionsFile) {
        std::cerr << "Couldn't open file for input!" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "OK!" << std::endl;
    std::cout << "Loading Questions... ";

    // load lines from file into question objects and build a vector of these.
    std::string line;
    std::vector<std::string> lines;

    while (!questionsFile.eof()) {

        std::getline(questionsFile, line);

        // Discard empty lines
        if (line.empty())
            continue;
        
        // When we have all components of a question create a new question and push it onto questions vector
        lines.push_back(line);
        if (lines.size() == 6) {
            Question tmp;
            tmp.setQuestion(lines[0]);
            tmp.addAnswer(lines[1]);
            tmp.addAnswer(lines[2]);
            tmp.addAnswer(lines[3]);
            tmp.addAnswer(lines[4]);
            tmp.setCorrectAnswerIndex(std::stoi(lines[5]));
            questions.push_back(tmp);
            lines.clear();
        }
 
    }

    questionsFile.close();
    std::cout << "OK!" << std::endl;


    std::cout << "\nQuiz Begins" << std::endl;

    // Present questions and get guesses.
    int guess;
    for (int i = 0; i < questions.size(); i++) {
        // Ask the question
        std::cout << "\n" << questions[i].getQuestion() << std::endl;

        // Print options
        std::vector<std::string> answers = questions[i].getAnswers();
        for (int j = 0; j < 4; j++) {
            std::cout << j << ": " << answers[j] << std::endl;
        }

        // Get the guess
        std::cout << "(Guess 0 - 3)>>> ";
        std::cin >> guess;

        // Update score
        if (questions[i].guessAnswer(guess)) {
            std::cout << "\tCorrect!" << std::endl;
            score++;
        }
        else {
            std::cout << "\tWrong!" << std::endl;
        }
           
    }

    // Output results.
    std::cout << "\nEnd of quiz!" << std::endl;
    std::cout << "Your final score was " << score << " / " << questions.size() <<std::endl;

    return 0;
}
