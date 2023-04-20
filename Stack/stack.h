#include <iostream>
#include <exception>
using namespace std;

template <class T>
class Stack{
    private:
        int capacity;
        int top;
        T * items;
    public:
        Stack(int capacity){
            this->items = new T[capacity];
            this->capacity = capacity;
            this->top = -1;
        }

        ~Stack(){
            delete[] items;
        }

        void add(T item){
            if(top == capacity){
                this->items[++top] = item;
            }
        }

        T pop(){
            if(top == -1){
                //  throw bad_alloc("ERROR");
            }else{
                return this->items[top--];
            }
        }

        void print(){
            for(int i = 0; i < this->capacity; i++){
            std::cout << "Element" << i << this->items[i] << std::endl;
            }
        }
};
