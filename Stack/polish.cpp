/*
 * pratica04.cpp
 *
 *  Created on: 28 de set de 2017
 *      Author: ramide
 */
#include <iostream>
#include "stack.h"

using namespace std;

int isOperator(char token) {
	switch(token) {
	case '+':
	case '-':
	case '*':
	case '/': return 1;
	default: return 0;
	}
}

int rate(char token, int valueLeft, int valueRight) {
	switch(token) {
	case '+': return valueLeft + valueRight;
	case '-': return valueLeft - valueRight;
	case '*': return valueLeft * valueRight;
	case '/': return valueLeft / valueRight;
	default: return 0;
	}
}

int polish(const char * exp) {
	Stack<int> stack;
	while (*exp) {
		char token = *exp;
		if (isOperator(token)) {
			int valueRight = stack.pop();
			int valueLeft = stack.pop();
			int resultado = rate(token, valueLeft, valueRight);
			stack.add(resultado);
		} else {
			int valor = (int)(token - '0');
			stack.add(valor);
		}
		exp++;
	}
	return stack.pop();
}

int main() {
	cout << polish("23+31-*") << endl;
	cout << polish("93*42/-") << endl;
	cout << polish("83*22/-") << endl;

}



