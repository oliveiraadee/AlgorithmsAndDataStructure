
#include <iostream>
#include <stdlib.h>
#include <chrono>

using namespace std;

int validate(int * data, int size) {
	for (int i = 0; i < size - 1; i++) {
		if (data[i] > data[i + 1]) return 0;
	}
	return 1;
}

void print(int * data, int size) {
	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

int * clone(int * array, int size) {
	int * copy = new int[size];
	for (int i = 0; i < size; i++) { copy[i] = array[i]; }
	return copy;
}

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void noopsort(int * array, int size) {
}


void bubblesort(int * array, int size) {
	int ultimo = size-1; 
	int troca = 1;
	for(int j = 0; j < ultimo && troca ; j++ ){	 
	 troca = 0;
	for(int i = 0; i < ultimo-j; i++){
		if(array[i] >= array[i+1]){
			swap(array[i], array[i+1]);
			troca = 1;
			
		}
	}
  }
}

void selectionsort(int * array, int size) {
	//repetir at? i ser menor que size
	for(int i = 0; i < size; i++){
		int min = i; 
		for(int j = i+1; j < size ; j++){
			if(array[min] > array[j]){
				min = j;
			}
		}
		swap(array[min], array[i]);
	}
}

void insertionsort(int * array, int size) {
	
	for(int i = 0; i < size; i++){
		int temp = array[i];
		int j = i-1;
		while(array[j] > temp && j >=0){
			swap(array[j], array[j+1]);
			j--;
		}
		temp = array[j+1];
	}
}

void merge(int * target, int * buffer, int start, int mid, int finish) {
	    
	    int esquerda = start;
	    int direita = mid;
		int now = start ;
	while(esquerda<=mid-1 && direita<=finish){
        if(buffer[esquerda] <= buffer[direita]){
            target[now] = buffer[esquerda];
            esquerda++;
			}
        else{
            target[now] = buffer[direita];
            direita++;
			}
        now++;
    }
    while(esquerda< mid){
        target[now] = buffer[esquerda];
        esquerda++;
        now++;
    }
    while(direita<= finish){
        target[now]= buffer[direita];
        direita++;
        now++;
    }
}

void mergesort(int * target, int * buffer, int start, int finish) {
	if (start >= finish) return;

	int mid = (start + finish)/2;

	mergesort(buffer, target, start, mid);
	mergesort(buffer, target, mid + 1, finish);

	merge(target, buffer, start, mid + 1, finish);
}

void mergesort(int * array, int size) {
	int * copy = clone(array, size);
	mergesort(array, copy, 0, size - 1);
	delete [] copy;
}

int partition(int * array, int start, int finish) {
	int pivot = array[finish];
    int p = start -1;
    
    
    for(int i = start; i <=finish; i++){
    	if(array[i] <= pivot){
    		p++;
    		swap(array[i],array[p]);
		}
	}
	return p;
    
}

void quicksort(int * array, int start, int finish) {
	if (finish <= start) return;
	int pivot = partition(array, start, finish);
	quicksort(array, start, pivot - 1);
	quicksort(array, pivot + 1, finish);
}

void quicksort(int * array, int size) {
	quicksort(array, 0, size - 1);
}



void show(int * array, int size, const char * name, void function(int *, int), int printFlag) {
	int * copy = clone(array, size);
	auto start = std::chrono::high_resolution_clock::now();

	function(copy, size);

	auto finish = std::chrono::high_resolution_clock::now();
	long elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() / 1000;

	int valid = validate(copy, size);
	cout << name << ": " << (valid?"ok":"erro") << " (tempo[us] = " << elapsed << ") ";

	if (printFlag) print(copy, size);
	delete [] copy;
}

int main() {
	int size = 30;
	int print = 1;

	int * array = new int[size];

	for (int i = 0; i < size; i++) {
		array[i] = rand() % size;
	}

	show(array, size, "NoOpSort     ", noopsort, print);
	show(array, size, "BubbleSort   ", bubblesort, print);
	show(array, size, "SelectionSort", selectionsort, print);
	show(array, size, "InsertionSort", insertionsort, print);
	show(array, size, "MergeSort    ", mergesort, print);
	show(array, size, "QuickSort    ", quicksort, print);

	delete [] array;
}






