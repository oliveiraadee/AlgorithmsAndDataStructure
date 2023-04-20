/*
 * printer.cpp
 *
 *  Created on: 28 de set de 2017
 *      Author: ramide
 */
#include <stdlib.h> // rand()
#include <iostream> // cout

#include <thread>
#include <chrono>
#define PAUSE(time) std::this_thread::sleep_for(std::chrono::milliseconds(time * 1000));

#include "queue.h"
//#include <queue>
using namespace std;

int main() {
	Queue<int> printer(10);
   //queue<int> printer;
   int i = 0;
	while (1) {
		// 70% de chance do usu�rio mandar imprimir um documento
		if ((rand() % 100) < 70) {
			if (!printer.full() /*printer.empty()*/) {
				cout << "Add document " << ++i << endl;
				printer.queue(i);
			//	printer.push(i);
			}
		}

		cout << "Status: " << printer.size() /*printer.size()*/ << " item(s) queue" << endl;

		// 50% de chance da printer imprimir um documento
		if ((rand() % 100) < 50) {
			if (!printer.empty() /*!printer.empty()*/) {
				cout << "Printing document " << printer.unqueue() /*printer.back()*/ << endl;
				//printer.pop();
			}
		}


		PAUSE(1);
	}
}


