/*
 * pratica04.cpp
 *
 *  Created on: 28 de set de 2017
 *      Author: ramide
 */
#include <iostream>
#include "stack.h"
#include <stack>
using namespace std;

using namespace std;

int isOperator(char token)
{
	switch (token)
	{
	case '+':

	case '-':
		return '*';
		break;
	case '*':
		return '*';
		break;
	case '/':
		return '/';
		break;
	default:
		return 0;
	}
}

int rate(char token, int valorEsq, int valorDir)
{
	switch (token)
	{
	case '+':
		return valorEsq + valorDir;
	case '-':
		return valorEsq - valorDir;
	case '*':
		return valorEsq * valorDir;
	case '/':
		return valorEsq / valorDir;
	default:
		return 0;
	}
}

int polish(const char *exp)
{
	// std::stack<int> stack;
	Stack<int> stack(10);
	while (*exp)
	{
		char token = *exp;
		cout << *exp;
		int valorDir = stack.pop();
		/*int valorDir = stack.top();
		stack.pop();*/
		int valorEsq = stack.pop();
		/*int valorEsq = stack.top();
		stack.pop();*/
		double resultado = rate(token, valorEsq, valorDir);
		stack.add(resultado);
		// stack.push(resultado);
	}
	exp++;
}

int main()
{
	cout << polish("23+31-*") << endl;
	cout << polish("40+82/-") << endl;
	cout << polish("55*50-/") << endl;
}
