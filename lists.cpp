#include <iostream>

using namespace std;

template <class T>
class TNode {
public:
	T data;
	TNode* next;

	TNode() {}
	TNode(const int& _data) { data = _data; }
};

template <class T>
class TList {
private:
	TNode *head;
	int size;
public:
	TList() { size = 0; }
	int getSize() { return size; }
	void push_front(const T& val);
	T pop(const int& index);
	void sort(TList<T> list);
};

template <class T> 
void TList<T>::push_front(const T& val) {
	TNode<T> *_head = new TNode<T>(val);
	_head->next = head;
	head = _head;
	size++;
}

template <class T>
T TList<T>::pop(const int& index) {
	TNode<T> *current;
	TNode<T> *prev;
	for (int i = 1; i < index; i++) {
		
	}
	size--;

}

template <class T>
void TList<T>::sort(TList<T> list) {
	TNode<T> *curr;
	TNode<T> *tmp;
	int size = list.getSize();
	for (int i = 0; i < size; i++) {
		for (int i = size - 1; i > 0; i--) {
			if (curr->data > curr->next->data) {
				tmp =  
			}
		}
	}
}

int main() {


	system("pause");
	return 0;
}
