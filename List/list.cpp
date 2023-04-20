/*
 * list.cpp
 *
 *  Created on: 28 de set de 2017
 *      Author: ramide
 */
#include "list.h"
#include <iostream>
#include <list>
using namespace std;

int main(){
	List<char> list(10);
   
	list.add('a');	// a
	list.add('b');	// a b
	list.add('c');	// a b c
	list.add('d');	// a b c d
	list.add('e');	// a b c d e
    cout << "first" << endl; 			// a b c d e (sa�da)
    list.getAll();
    cout << endl;
	list.remove(3); 		// a b d e
	cout << "second"  << endl; 			// a b d e (sa�da)
    list.getAll();
    cout << endl;
	list.get(4); 			// e
	list.insert(2, 'f'); 	// a f b d e
	cout << "third" << endl; 			// a f b d e (sa�da)
     list.getAll();
         cout << endl;

	list.add('g'); 	// a f b d e g
	list.insert(4, 'h'); 	// a f b h d e g
	list.get(2); 			// f
	cout << "fourth" << endl;
	list.getAll(); //	a f b h d e g (sa�da)
}
 
