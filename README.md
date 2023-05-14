# Algorithms And Data Structure

Algorithms and Data Structure project for demonstrate the usage of them.

# Language
 
 C++
 
# Code Snippet
 
 
# Running
 
 ### List
 
 #### 1. Inserting a element inside a list
 ```c++
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
 ```
 
  #### 2. Removing a element inside a list
 ```c++
     void remove(int idx){
          if((idx < capacity || idx > capacity)){
            for(int i = idx; i < size; i++){
              items[i] = items[i+1];
            }
          size--;
          }
		} 
   ```
   
   ### Queue
   
   #### 1. Adding a element
 ```c++
 void queue(const T & item){
            if(this->length < this->capacity){
	            this->items[(this->initPos+this->length) % this->capacity] = item;
	            this->length = this->length+1;
            }else{
               throw std::bad_alloc();
            }
        }
   ```
      
   #### 2. Removing a element
 ```c++
T unqueue(){
            if(this->length > 0 ){
              this->length = this->length-1;
             return this->items[ (this->initPos++) % this->capacity];
            }else{
              throw std::bad_alloc();
            }
        }

   ```

### Stack

  
  #### 1. Add a element
  ```c++
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
   ```
    
 #### 2. Removing a element
 ```c++
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
   ```
   
   ## Install and Running

### Compile

 ```g++ -o <gaven name of executable> <main class>.cpp```

### Run

```./<executable name>```

##### Example

```g++ -o printer printer.cpp```

```./printer```

