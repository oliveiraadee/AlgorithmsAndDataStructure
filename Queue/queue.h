#include <iostream>
#include <exception>
using namespace std;

template <class T>
class Queue{
    private:
        T *items;
        int capacity;
        int length;
        int initPos;
        int finalPos;
    public:
        Queue(int cap){
            capacity = cap;
            items = new T[cap];
            initPos = 0;
            length = 0;
        }

        ~Queue(){
            delete[] items;
        }

        void queue(const T & item){
            if(this->length < this->capacity){
	            this->items[(this->initPos+this->length) % this->capacity] = item;
	            this->length = this->length+1;
            }else{
               throw std::bad_alloc();
            }
        }

        T unqueue(){
            if(this->length > 0 ){
              this->length = this->length-1;
             return this->items[ (this->initPos++) % this->capacity];
            }else{
              throw std::bad_alloc();
            }
        }

        int full(){
            if(this->length == this->capacity){
                return 1;
            }else{
                return 0
        ;
            }
        }
        int empty(){
            if(this->length == 0){
                return 1;
            }else{
                return 0;
            }
        }
        int size(){
                return this->length;
            }
        };
