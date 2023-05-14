
#include <iostream>
#include <stdlib.h>
#include <chrono>

#include "util.h"

using namespace std;


void reset(int * array, int len) {
	for (int i = 0; i < len; i++) array[i] = 0;
}

int sum(const int * array, const int * subset, int len) {
	int sum = 0;
	for (int i = 0; i < len; i++)
		if (subset[i])
			sum += array[i];
	return sum;
}

int finished(const int * subset, int len) {
	for (int i = 0; i < len; i++) if(!subset[i]) return 0;
	return 1;
}

void next(int * subset, int len) {
	for (int i = 0; i < len; i++) {
		if (subset[i]) {
			subset[i] = 0;
		} else {
			subset[i] = 1;
			break;
		}
	}
}

int subsetSumBF(int * array, int len, int value, int * subset, long & count) {
	int tmp = 0;
	reset(subset, len);
	while(!((tmp = sum(array, subset, len)) == value) && !finished(subset, len)) {
		next(subset, len);
		count++;
	}
	return tmp == value;
}


int __subseqSumBT(int * array, int len, int value, int * subset, int pos, int sum, long & count) {
	if (pos >= len) return 0;
	count++;

	if (sum == value) return 1;

	subset[pos] = 1;
	if (__subseqSumBT(array, len, value, subset, pos + 1, sum + array[pos], count)) return 1;

	subset[pos] = 0;
	if (__subseqSumBT(array, len, value, subset, pos + 1, sum, count)) return 1;

	return 0;
}

int subsetSumBT(int * array, int len, int value, int * subset, long & count) {
	return __subseqSumBT(array, len, value, subset, 0, 0, count);
}


int __subsetSumBTv2(int * array, int len, int value, int * subset, int pos, int sum, long & count) {
	if (pos >= len) return 0;
	count++;

	if (sum == value) return 1;

	if (sum > value) return 0;

	subset[pos] = 1;
	if (__subsetSumBTv2(array, len, value, subset, pos + 1, sum + array[pos], count)) return 1;

	subset[pos] = 0;
	if (__subsetSumBTv2(array, len, value, subset, pos + 1, sum, count)) return 1;

	return 0;
}

int subsetSumBTv2(int * array, int len, int value, int * subset, long & count) {

	int sum = 0;
	for (int i = 0; i < len; i++) sum += array[i];
	if (value > sum) return 0;



	return __subsetSumBTv2(array, len, value, subset, 0, 0, count);
}


void runSubseqMax(const char * name,	int func(int *, int, int, int *, long &), int * array, int len, int value) {
	long count = 0;
	int * subset = new int[len];
	reset(subset, len);

	auto start = std::chrono::high_resolution_clock::now();

	int found = func(array, len, value, subset, count);

	auto finish = std::chrono::high_resolution_clock::now();
	long elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() / 1000;

	cout << name << ": " << (found?"YES ":" NO ");
	if (found) {
		cout << "[ ";
		for (int i = 0; i < len; i++) {
			if (subset[i])
				cout << array[i] << " ";
		}
		cout << "] ";
	}
	cout << "[time: "<< elapsed << "us] ";
	cout << "[count: "<< count << "]" << endl;


	delete [] subset;
}

int subsetsumGreedy(int *array, int len, int value, int *subset, long & count){
   
   if(value == 0){
   	 return 1;
   }
   
   if(value > 0 && len == 0 ){
   	return 0;
   }

   for(int i = 0; i <= len; i++){
   	if(array[i] <= value){
   	    count++;
   		subset[i] = array[i];
   		value-=subset[i];
	   }
   }
   
   len--;
   return value == 0;
}


int main() {

	int size = 20;

	int * array = new int[size];

	for (int i = 0; i < size; i++) {
		cout << (array[i] = rand() % (size * 2)) << " ";
	}
	cout << endl;

	int value = 0;
	for (int i = 0; i < 20; i++) {
		 value += (rand() % (size * 2));
		cout << i << ": Trying " << value << " ..." << endl;

//		runSubseqMax("Bruteforce     ", subsetSumBF, array, size, value);
//		runSubseqMax("Backtracking   ", subsetSumBT, array, size, value);
//		runSubseqMax("Backtracking V2", subsetSumBTv2, array, size, value);
		runSubseqMax("SubsetsumGreedy", subsetsumGreedy, array, size, value);
	}

	return 0;
}



