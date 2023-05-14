#include <iostream>
#include <stdexcept>
using namespace std;

class SortedList {
private:
	int * items;
	int size, capacity;
public:
	SortedList(int cap) {
		this->capacity = cap;
		this->size = 0;
		items = new int[cap];
	}

	~SortedList() {
		delete [] items;
	}

	void insert(int key) {
		if (this->size >= this->capacity){
			throw std::overflow_error("fill list");
		}else{
	        int auxsize = size;
		    for(int i = 0; i < this->size; i++){
		    	if(key > this->items[auxsize-1]){
		    		i = this->size;
				}else{
					this->items[auxsize] = this->items[auxsize-1];
					auxsize--;
				}
			}
			this->items[auxsize] = key;
			this->size++;
		}
	}

	int sequenceSearch(int key) {
		for(int i =0; i < this->size; i++){
			if(this->items[i] == key){
				return i;
			}
		}
		return -1;
	}

	int binarySearch(int item) {
		return binarySearch(0, size - 1, item);
	}

	int valid() {
		for (int i = 0; i < size - 1; i++) {
			if (items[i] > items[i + 1]) return 0;
		}
		return 1;
	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << i << ": " << items[i] << "; ";
		}
		cout << endl;
	}
	void remove(int key){
	 	int idx = binarySearch(key);
		if (idx == -1){
			throw "Item not found";
		}else{
			for(int i = idx; i < this->size;i++){
				this->items[i] = this->items[i+1];
			}
		}
		this->size--;
	}

private:

	int binarySearch(int begin, int final, int item) {
	    if(begin > final){
		 return -1;
		}else{
			int mid = (begin+final)/2;
			if(this->items[mid] == item){
				return mid;
			}
			if(this->items[mid] < item){
				return binarySearch(mid+1, final, item);
			}else{
				return binarySearch(0, mid-1, item);
			}
		}
	}

};

int main () {

	SortedList list(10);

	int elements [] = {10, 5, 25, 1, 5, 13, 50, 99, 33, 12};

	for (int i = 0; i < 10; i++) {
		list.insert(elements[i]);
	}
	list.remove(99);

	cout << "Valid list: " << (list.valid()?"yes":"no") << endl;
	list.print();

	int teste [] = {5, 7, 16, 99, 45, 12, 33, 1, 60, 6};

	for (int i = 0; i < 10; i++) {
		cout << "Searching " << teste[i] << ": sequence = " << list.sequenceSearch(teste[i]) << " binaria = " << list.binarySearch(teste[i]) << endl;

	}

} 
