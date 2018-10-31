#include <iostream>
using std::endl;
using std::cout;

const int N = 3;

template <class T> 
class Stack {
private:
	int top;
	T *value;
public:
	// constructors
	Stack() { value = new T[N]; top = -1; }
	
	// methods
	T pop();
	void push(const T &x);
	bool isEmpty();
	bool isFull();
	void resize();
};

template <class T>
bool Stack <T>::isEmpty() {
	if (top == -1)
		return true;
	else return false;
}

template <class T>
void Stack <T>::push(const T &x) {
	if (!isFull()) 
		value[++top] = x;
	else (*this).resize();
}

template <class T>
T Stack <T>::pop() {
	if (!isEmpty()) 
		return value[top--];
	else throw "Stack is empty";
}

template <class T>
bool Stack <T>::isFull() {
	if (top >= N - 1) 
		return 1;
	return 0;
}

template <class T> 
void Stack <T>::resize() {
	if (isFull()) {
		T* tmp = new T[N];
		for (int i = 0; i < N; i++) {
			tmp[i] = value[i];
		}

		value = new T[2*N];
		for (int i = 0; i < N; i++) {
			value[i] = tmp[i];
		}
		delete[] tmp;
	}
}

int main() {
	Stack <int> stack;
	
	cout << stack.isEmpty() << endl;
	cout << stack.isFull() << endl;
	stack.push(5);
	stack.push(6);
	stack.push(7);
	cout << stack.isEmpty() << endl;
	cout << stack.isFull() << endl;
	stack.push(4);
	stack.push(5);
	cout << stack.isFull() << endl;

	cout << stack.pop() << endl;
	cout << stack.pop() << endl;

	cout << stack.isEmpty() << endl;

	system("pause");
	return 0;
}