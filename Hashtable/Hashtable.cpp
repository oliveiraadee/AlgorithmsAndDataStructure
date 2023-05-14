#include <iostream>
#include <string>

using namespace std;


template <class T_key, class T_value>
class Hashtable {
private:
	struct Node {
		T_key key;
		T_value value;
		Node * next;
		Node(T_key key, T_value value) : key(key), value(value), next(NULL) {}
	};
	Node ** data;
	int cap, size;
	T_value notFound;
public:
	Hashtable(int cap, T_value notFound) {
		this->cap = cap;
		this->size = 0;
		this->notFound = notFound;
		data = new Node*[cap];
		for (int i = 0; i < cap; i++) {
			data[i] = NULL;
		}
	}

	~Hashtable() {
		for (int i = 0; i < cap; i++) {
			while (data[i] != NULL)
		 		remove(data[i], data[i]->key);
		}
		delete [] data;
	}

	void insert(T_key key, T_value value) {
		int idx = hash(key);
		insert(data[idx], key, value);
	}

	T_value remove(T_key key) {
		int idx = hash(key);
	    return remove(data[idx], key);
		
	}

	T_value search(T_key key) {
		int idx = hash(key);
		return search(data[idx], key);
	}

	void show() {
		for (int i = 0; i < cap; i++) {
			cout << i << ":";
			show(data[i]);
			cout << endl;
		}
	}

private:
	int hash(int x) {
	if(x <= 0){
			x = x * (-1);
		}
		return x % this->cap; 
	}

	int hash(string key) {
		const char * str = key.c_str();
		int hash = 1;
		while(*str) hash = (*str++ + hash)  ;
		return hash  % cap; 
	}

	void show(Node * node) {
		while (node != NULL) {
			cout << "(" << node->key << ", " << node->value << ") ";
			node = node->next;
		}
	}

	void insert(Node * &node, T_key key, T_value value) {
		Node * tmp = new Node(key, value);
		tmp->next = node;
		node = tmp;
	}

	T_value remove(Node * &node, T_key key) {
		if (node == NULL) return notFound;
		if (node->key == key) {
			Node * old = node;
			T_value tmp = node->value;
			node = node->next;
			delete old;
			return tmp;
		} else {
			return remove(node->next, key);
		}
	}

	T_value search(Node * node, T_key key) {
		while (node != NULL) {
			if (node->key == key) {
				return node->value;
			}
			node = node->next;
		}
		return notFound;
	}

};

int main() {
	Hashtable<string, float> notas(10, -1);

	notas.insert(string("Joao"), 5);
	notas.insert(string("Pedro"), 7);
	notas.insert(string("Larissa"), 10);
	notas.insert(string("Tereza"), 7.5);
	notas.insert(string("Victor"), 8);
	notas.insert(string("Mario"), 4);

	cout << "TABELA: " << endl;
	notas.show();


	cout << endl;

	cout << "NOTAS: " << endl;
	cout << "Joao: " << notas.search(string("Joao")) << endl;
	cout << "Carlos: " << notas.search(string("Carlos")) << endl;
	cout << "Pedro: " << notas.search(string("Pedro")) << endl;
	cout << "Maria: " << notas.search(string("Maria")) << endl;
	cout << "Mario: " << notas.search(string("Mario")) << endl;
	return 0;
}



