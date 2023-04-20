#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;
template <class T>
class Stack{
	struct Node{
	T data;
	Node *next;
	
};

    private:
        Node * top; 
    public:
        Stack(){
        	this->top = NULL;
        }

        ~Stack(){
        	
        }

        void add(T item){
           Node *newTemp = new Node();
           if(newTemp == NULL ){
	        throw std::overflow_error("Stack Overflow");
	    
		   }else{
			   	newTemp->data = item;
			  	newTemp->next = top;
			  	top = newTemp;
		   } 	
		}
		

        T pop(){
	        if(top == NULL){
	          	throw std::underflow_error("Stack Underflow");
			}else{
			  	Node * temp = top;
			  	T aux= top->data;
			  	top = top-> next;
			  	delete(temp);
                return aux;
            }
}

        void imprimir(){
        	Node *aux = new Node();
        	aux= top;
            while(aux != NULL){
            	cout << aux->data << " ";
            	aux = aux->next;
			}
        }
};

