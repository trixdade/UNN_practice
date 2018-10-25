#include <iostream>

using namespace std;

template <class ValType> 
class Queue {
protected:
        int start;
        int end;
        int currentS; // количество элементов в очереди
        int size; // вместимость
        ValType *pQueue;
public:
        Queue(int _size);
        Queue(const Queue &q);
        ~Queue();

        int getSize() const { return size; }
        bool isFull();
        bool isEmpty();
        void push(const ValType& val);
		ValType pop();
};

template <class ValType>
Queue<ValType>::Queue(int _size) {
        size = _size;
        start = 0;
        end = 0;
        currentS = 0;
        pQueue = new ValType[size];
}

template <class ValType>
Queue<ValType>::Queue(const Queue &q) {
        size = q.size;
        currentS = q.currentS;
        start = q.start;
        end = q.end;
        pQueue = new ValType[size];
         for(int i = 0; i < size; i++) {
                pQueue[i] = q.pQueue[i];
        }
}

template <class ValType>
Queue<ValType>::~Queue() {
        delete[] pQueue;
}

template <class ValType>
bool Queue<ValType>::isFull() {
        if (currentS == size) {
                return true;
        }
        return false;
}

template <class ValType>
bool Queue<ValType>::isEmpty() {
        if (currentS == 0) {
                return true;
        }
        return false;
}

template <class ValType> 
void Queue <ValType>::push(const ValType& val) {
        if (isFull() == 0) {
                pQueue[end] = val;
                currentS++;
                end = (end + 1) % size;
        }
}

template <class ValType> 
ValType Queue <ValType>::pop() {
        if (isEmpty() == 0) {
                ValType val = pQueue[start];
                currentS--;
                start = (start + 1) % size;
                return val;
        }
}


int main() {
        Queue<int> q(3),q1(3),q2(3);
        q.push(5);
        q.push(6);
        q.push(10);
        q1.push(5);
        cout << "q, isEmpty: " << q.isEmpty() << endl;
        cout << "q, isFull: " << q.isFull() << endl;
        cout << "q1, isEmpty: " << q1.isEmpty() << endl;
        cout << "q1, isFull: " << q1.isFull() << endl;
        cout << "q2, isEmpty: " << q2.isEmpty() << endl;
        cout << "q2, isFull: " << q2.isFull() << endl;

        Queue<int> que(1);
        que.push(5);
        cout << que.isEmpty() << endl;
        que.pop();
        cout << que.isEmpty() << endl;

        system("pause");
        return 0;
}
