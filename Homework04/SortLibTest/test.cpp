/**
* @file test.cpp
*
* @author  Joseph Roy-Plommer
* @version <1.0>
* @date 2020-02-02
*
* @section Academic Integrity
*  I certify that this work is solely my own and complies with
*  NBCC Academic Integrity Policy (policy 1111)
*
* @section DESCRIPTION
*	Tests sort functions defined in Sort namespace.
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

#include "sort.h"
#include <gtest/gtest.h>
#include <vector>
#include <sstream>

TEST(SortLibTest, testSelectionSort01) {
    std::vector<int> v1 = { 5, 1, 56, 13, 9, 22, 7 };
    std::string expected = "1 5 7 9 13 22 56 ";
    std::stringstream result;

    Sort::selectionSort(v1);

    for (auto l : v1) {
        result << l << " ";
    }

    EXPECT_EQ(expected, result.str());
}

TEST(SortLibTest, testBubbleSort01) {
    std::vector<int> v1 = { 5, 1, 56, 13, 9, 22, 7 };
    std::string expected = "1 5 7 9 13 22 56 ";
    std::stringstream result;

    Sort::bubbleSort(v1);

    for (auto l : v1) {
        result << l << " ";
    }

    EXPECT_EQ(expected, result.str());
}

TEST(SortLibTest, quickSort01) {
    std::vector<int> v1 = { 5, 1, 56, 13, 9, 22, 7 };
    std::string expected = "1 5 7 9 13 22 56 ";
    std::stringstream result;

    Sort::quickSort(v1, 0, v1.size() - 1);

    for (auto l : v1) {
        result << l << " ";
        //std::cout << l << " ";
    }

    //std::cout << result.str();

    EXPECT_EQ(expected, result.str());
}