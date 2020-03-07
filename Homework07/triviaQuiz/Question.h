#pragma once
/**
* @file Question.h
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

#include <string>
#include <vector>

class Question
{

public:

	Question();

	void setQuestion(const std::string);
	std::string getQuestion();

	void addAnswer(const std::string);
	std::vector<std::string> getAnswers();

	void setCorrectAnswerIndex(const int n);

	bool guessAnswer(const int n);

private:

	std::string question;
	std::vector<std::string> answers;
	int correctAnswerIndex;

};

