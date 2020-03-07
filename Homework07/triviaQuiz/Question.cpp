/**
* @file Question.cpp
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
*	Represents a question, with 4 posible answers and an index to the correct answer.
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

#include "Question.h"

/**
* No-arg constructor. Initializes variables: questino and correctAnswerIndex.
*/
Question::Question() :
	question(""), correctAnswerIndex(0)
{}

/**
* Mutator for question variable.
*/
void Question::setQuestion(const std::string q) {
	question = q;
}

/**
* Accessor for question variable.
*/
std::string Question::getQuestion() {
	return question;
}

/**
* Pushes a new answer to the answers vector.
*/
void Question::addAnswer(const std::string a) {
	answers.push_back(a);
}

/**
* Returns answers vector.
*/
std::vector<std::string> Question::getAnswers() {
	return answers;
}

/**
* Sets the index (in the answers vector) of the correct answer.
*/
void Question::setCorrectAnswerIndex(const int n) {
	correctAnswerIndex = n;
}

/**
* Guess the index of the correct answer. only the correct index will return true. all other input returns false.
*/
bool Question::guessAnswer(const int n) {
	if (correctAnswerIndex < 0 || correctAnswerIndex >= answers.size())
		return false;

	if (n == correctAnswerIndex)
		return true;
	else
		return false;
}