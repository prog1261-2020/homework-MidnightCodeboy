/**
* @file Source.cpp
*
* @author  Joseph Roy-Plommer
* @version <1.0>
* @date 2020-03-09
*
* @section Academic Integrity
*  I certify that this work is solely my own and complies with
*  NBCC Academic Integrity Policy (policy 1111)
*
* @section DESCRIPTION
*	Counts the occurrences of words in a text file.
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
#include <sstream>
#include <algorithm>
#include <map>

void sanitize(std::string &);

/**
* Entry point for program.
*/
int main() {

	std::map<std::string, int> wordCounts;
	std::fstream wordFile("fox.txt", std::ios::in);

	if (!wordFile) {
		std::cerr << "Failed to open file for reading" << std::endl;
		exit(EXIT_FAILURE);
	}

	// Process unique words (read, sanitize and count)
	std::string word;
	while (!wordFile.eof()) {
		wordFile >> word;

		sanitize(word);

		wordCounts[word] += 1;
	}

	wordFile.close();

	// Output word and count pairs
	std::cout << "Word : Count" << std::endl;

	for (std::pair<std::string, int> p : wordCounts) {
		std::cout << p.first << ": " << p.second << std::endl;
	}

	return 0;

}

/**
* Converts string to lowercase and with all punctuation removed.
*/
void sanitize(std::string & unSafeWord) {

	// to lower
	std::transform(unSafeWord.begin(), unSafeWord.end(), unSafeWord.begin(), [](char c) {return std::tolower(c); });

	// strip punctuation
	std::string alpha = "abcdefghijklmnopqrstuvwxyz";

	// Left whitespace characters at the ends of words where it removed punctuation so I abandoned it.
	//std::transform(unSafeWord.begin(), unSafeWord.end(), unSafeWord.begin(), [alpha](char c) { if (alpha.find(c) != std::string::npos) return c; });

	std::stringstream clean;
	for (char c : unSafeWord) {
		if (alpha.find(c) != std::string::npos)
			clean << c;
	}
	unSafeWord = clean.str();
}
