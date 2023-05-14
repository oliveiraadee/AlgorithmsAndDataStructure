

#include <iostream>
#include <stdlib.h>
#include <chrono>

#include "util.h"

using namespace std;


int subseqMaxBF(int * array, int len, int & ini, int & end, long & count) {
	int max = -9999, sum;
	ini = end = -1;
	for (int i = 0; i < len; i++) {
		sum = 0;
		for (int j = i; j < len; j++) {
			count++;

			sum += array[j];
			if (sum > max) {
				max = sum;
				ini = i;
				end = j;
			}
		}

	}
	return max;
}


int subseqMaxMiddle(int * array, int start, int middle, int finish, int & ini, int & end, long & count) {
	int maxL = 0, maxR = 0;
	int sumL = 0, sumR = 0;

	ini = end = middle;

	for (int i = middle - 1; i >= start; i--) {
		count ++;
		sumL += array[i];
		if (sumL > maxL) {
			maxL = sumL;
			ini = i;
		}
	}

	for (int i = middle + 1; i <= finish; i++) {
		count ++;
		sumR += array[i];
		if (sumR > maxR) {
			maxR = sumR;
			end = i;
		}
	}

	return maxL + maxR + array[middle];
}

int __subseqMaxDC(int * array, int start, int finish, int & ini, int & end, long & count) {
	if (start > finish) return -9999;

	int maxL, iniL, endL;
	int maxR, iniR, endR;
	int maxM, iniM, endM;
	int MAX;

	int mid = (start + finish) / 2;

	maxL = __subseqMaxDC(array, start, mid - 1, iniL, endL, count);
	maxR = __subseqMaxDC(array, mid + 1, finish, iniR, endR, count);

	maxM = subseqMaxMiddle(array, start, mid, finish, iniM, endM, count);

	MAX = max(maxM, max(maxL, maxR));

	if (MAX == maxM) { ini = iniM; end = endM; }
	else if (MAX == maxL) { ini = iniL; end = endL; }
	else { ini = iniR; end = endR; }

	return MAX;
}

int subseqMaxDC(int * array, int len, int & ini, int & end, long & count) {
	return __subseqMaxDC(array, 0, len - 1, ini, end, count);
}


int seqMax(int * array, int pos, int & ini, long & count) {
	if (pos < 0) return 0;
	int sum, iniPrev;

	count ++;
	int x = array[pos];
	int sumPrev = x + seqMax(array, pos - 1, iniPrev, count);

	if ( x > sumPrev) {		
		sum = array[pos];
		ini = pos;
	} else {				
		sum = sumPrev;
		ini = iniPrev;
	}

	return sum;
}

int subseqMaxRec(int * array, int len, int & ini, int & end, long & count) {
	int sum = 0;
	ini = end = -1;

	for (int i = 0; i < len; i++) {
		int _ini, _sum;
		_sum = seqMax(array, i, _ini, count);

		if (_sum > sum) {
			sum = _sum;
			ini = _ini;
			end = i;
		}
	}

	return sum;
}


int seqMaxMemo(int * array, int pos, int & ini, int * SUM, int * INI, long & count) {
	if (pos < 0) return 0;

	count ++;
	int x = array[pos];
	SUM[pos-1] = x + seqMaxMemo(array, pos - 1,ini,SUM, INI, count);

	if ( x > SUM[pos-1]) {		
		SUM[pos] = array[pos];
		INI[pos] = pos;
	} else {				
		SUM[pos] = SUM[pos-1];
		INI[pos] = INI[pos-1];
	}

	return SUM[pos];
}

int subseqMaxMemo(int * array, int len, int & ini, int & end, long & count) {
    int sum = 0;
	ini = end = -1;

	for (int i = 0; i < len; i++) {
		int _ini, _sum;
		_sum = seqMaxMemo(array, i, ini, count);

		if (_sum > sum) {
			sum = _sum;
			ini = _ini;
			end = i;
		}
	}

	return sum;
}


int subseqMaxPD(int * array, int len, int & ini, int & end, long & count) {
	// TODO

	return 0;
}


void runSubseqMax(const char * name, int func(int *, int, int&, int&, long &), int * array, int len, int printSeq) {
	long count = 0;

	int ini, end;

	auto start = std::chrono::high_resolution_clock::now();

	int max = func(array, len, ini, end, count);

	auto finish = std::chrono::high_resolution_clock::now();
	long elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() / 1000;

	cout << name << ": " << max << " ";

	if (printSeq) { cout << "[ "; print(array, ini, end); cout << "] "; }

	cout << "[time: "<< elapsed << "us] ";
	cout << "[count: "<< count << "]" << endl;

}

int main() {

	int printSeq = 0;
	int size = 1000;

	int * array = new int[size];

	for (int i = 0; i < 10; i++) {

		for (int i = 0; i < size; i++) {
			array[i] = (rand() % size) - (size / 2);
		}
		cout << i << ": " << endl; // print(array, size);

		runSubseqMax("Bruteforce     ", subseqMaxBF, array, size, printSeq);
		runSubseqMax("Divide&Conquer ", subseqMaxDC, array, size, printSeq);
		runSubseqMax("Recursive      ", subseqMaxRec, array, size, printSeq);
		runSubseqMax("Memoization    ", subseqMaxMemo, array, size, printSeq);
		runSubseqMax("Dynamic Prog.  ", subseqMaxPD, array, size, printSeq);
	}

	delete [] array;

}






