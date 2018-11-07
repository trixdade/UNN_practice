#include <iostream>
#include <string>
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
	else this->resize();
}

template <class T>
T Stack <T>::pop() {
	if (!isEmpty())
		return value[top--];
	else throw (std::string)"Stack is empty";
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
		value = new T[2 * N];
		for (int i = 0; i < N; i++) {
			value[i] = tmp[i];
		}
		delete[] tmp;
	}
}

template <class T>
class Queue {
private:
	Stack <T> s1;
	Stack <T> s2;
public:
	void push(const T &x);
	T pop();
	bool isEmpty();
};

template <class T>
void Queue <T>::push(const T &x) {
	s2.push(x);
}

template <class T>
T Queue <T>::pop() {
	if (!s1.isEmpty()) {
		return s1.pop();
	}
	else {
		while (!s2.isEmpty()) {
			s1.push(s2.pop());
		}
		return s1.pop();
	}
}

template <class T> 
bool Queue <T>::isEmpty() {
	return s1.isEmpty() && s2.isEmpty();
}

int main() {
	try {
		Queue <int> Queue;
		Queue.push(1);
		Queue.push(2);
		cout << Queue.pop() << endl;
		cout << Queue.pop() << endl;
		cout << Queue.pop() << endl;
	}
	catch (std::string s)
	{
		cout << s << endl;
	}
	system("pause");
	return 0;
}
