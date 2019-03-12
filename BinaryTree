#include <iostream>
#include <queue>
#include <stack>

using namespace std;

template <typename T>
struct Node {
	T data;
	Node<T> *left = nullptr;
	Node<T> *right = nullptr;

	Node<T>() = default;
	Node<T>(T _data) { data = _data; }
};

template <typename T>
class Tree {
private:
	Node<T> *root;
public:
	Tree() {
		root = new Node<T>();
		root->left;
		root->right;
	}
	~Tree() {}

	Node<T>* getRoot() { return root; }

	void Fill();
	void BFS(); // обход в ширину
	void DFS();
};



template <typename T>
void Tree<T>::Fill()
{
	Node<T> *curr = root;
	curr->data = 1;
	curr->left = new Node<T>(2);
	curr->right = new Node <T>(3);
	curr->left->left = new Node <T>(4);
	curr->left->left->left = nullptr;
	curr->left->left->right = nullptr;
	curr->left->right = new Node <T>(5);
	curr->left->right->left = nullptr;
	curr->left->right->right = nullptr;
	curr->right->left = new Node <T>(6);
	curr->right->left->left = nullptr;
	curr->right->left->right = nullptr;
	curr->right->right = new Node <T>(7);
	curr->right->right->left = nullptr;
	curr->right->right->right = nullptr;
}

template <typename T>
void Tree<T>::BFS() // обход в ширину
{
	queue <Node<T>*> Queue;
	Queue.push(root);
	while (!Queue.empty()) {
		Node<T> *newNode = Queue.front();

		if (newNode->left) {
			Queue.push(newNode->left);
		}
		if (newNode->right) {
			Queue.push(newNode->right);
		}
		
		cout << newNode->data << endl;
		Queue.pop();
		delete newNode;
	}
}

template <typename T>
void Tree<T>::DFS()
{
	stack <Node<T>*> Stack;
	Node<T> *curr = root;
	Stack.push(curr);
	while (!Stack.empty()) {
		Node<T>* tmp = Stack.top();
		cout << tmp->data << endl;
		Stack.pop();
		if (tmp->right) {
			Stack.push(tmp->right);
		}
		if (tmp->left) {
			Stack.push(tmp->left);
		}
	}
}

int main() {
	Tree<int> tree;
	
	tree.Fill();
	
	tree.DFS();

	cout << endl;

	tree.Fill();

	tree.BFS();

	
	system("pause");
	return 0;
}
