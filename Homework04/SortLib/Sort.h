#pragma once

/**
* @file Sort.h
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
*	Free utility functions for sorting a vector of integers.
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
#include <iostream>

namespace Sort {

	/**
	*	Sorts a vector of integers into ascending order.
	*	Uses Selections sort algorithm to sort in O(n2) comparisons and O(n) swaps (on average).
	*
	*	@param list reference to vector to be sorted
	*/
	void selectionSort(std::vector<int>& list) {
	
		for (int fillPosition = 0; fillPosition < list.size(); fillPosition++) {
			int swapPosition = fillPosition;
			int lowestValue = list.at(fillPosition);
			for (int swapCandidate = swapPosition; swapCandidate < list.size(); swapCandidate++) {
				if (list.at(swapCandidate) < lowestValue) {
					lowestValue = list.at(swapCandidate);
					swapPosition = swapCandidate;
				}
			}
			int temp = list.at(fillPosition);
			list.at(fillPosition) = list.at(swapPosition);
			list.at(swapPosition) = temp;
		}
		
	}

	/**
		*	Sorts a vector of integers into ascending order.
		*	Uses bubble sort algorithm to sort in O(n2) comparisons and O(n2) swaps (average performance).
		*
		*	@param list reference to vector to be sorted
		*/
	void bubbleSort(std::vector<int>& list) {
		bool sorted = false;
		while (!sorted) {
			sorted = true;
			for (int i = 0; i < list.size() - 1; i++) {
				if (list.at(i) > list.at(i + 1)) {
					sorted = false;
					int temp = list.at(i);
					list.at(i) = list.at(i + 1);
					list.at(i + 1) = temp;
				}
			}
		}
	}

	int partition(std::vector<int>& list, int start, int end) {
		int pivotValue = list.at(end);
		int pivotPosition = start;
		for (int i = start; i < end; i++) {
			if (list.at(i) <= pivotValue) {
				int temp = list.at(i);
				list.at(i) = list.at(pivotPosition);
				list.at(pivotPosition) = temp;
				pivotPosition++;
			}
		}
		// swap pivot position with end
		int temp = list.at(pivotPosition);
		list.at(pivotPosition) = list.at(end);
		list.at(end) = temp;

		return pivotPosition;
	}

	/**
		*	Sorts a vector of integers into ascending order.
		*	Uses quick sort algorithm to sort in O() comparisons and O() swaps (average performance).
		*
		*	@param list reference to vector to be sorted
		*/
	void quickSort(std::vector<int>& list, int start, int end) {
		if (start < end) {
			int pivot = partition(list, start, end);
			quickSort(list, start, pivot - 1);
			quickSort(list, pivot + 1, end);
		}
		return;
	}

	

}



