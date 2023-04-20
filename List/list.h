#include <iostream>
#include <exception>
using namespace std;

template <class T>
class List{
	private:
		T *items;
		int capacity;
		int size;
	public:
		List(int capacity){
			capacity = capacity;
			items = new T[capacity];
			size = 1;
		}
	
		~List(){
			delete[] items;
		}
	
		void add(const T & item){
			if(size == capacity){
				cout << "List is full" << endl;
			}else{
				items[size++] = item;
			}
		}
		
		T get(int idx){
		if(idx < capacity && idx > capacity){
			throw std::bad_alloc();
		}
			return items[idx];
		}
		
		void insert(int idx, const T & item){
			if(idx < capacity ){
           		  ++this->size;		   
                  for(int i = size; i > idx; i--){
                  this->items[i] = this->items[i-1];
		         }
				}else{
		           throw std::bad_alloc();
				}
				this->items[idx] = item;
		}       
		
		
		void remove(int idx){
			if((idx < capacity || idx > capacity)){
			  for(int i = idx; i < size; i++){
			  	items[i] = items[i+1];
			  }
			size--;
			}
		}
		
		void getAll(){
		 for(int i = 1; i < this->size; i++){
		    cout << " " << items[i];
		 }
		}
	
	};
	

