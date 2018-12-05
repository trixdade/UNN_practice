#include <iostream>
#include <string>

using namespace std;

struct Node 
{
	string name;
	Node *next;
	Node *prev;
	Node *first_child;
};

class University 
{
private:
	Node* head;
public:
	University(string str) {
		head = new Node();
		head->name = str;
	}

	void insert(string _faculty, string _cathedra = "0");
};

void University::insert(string _faculty, string _cathedra = "0") {
	Node *faculty = head->first_child;
	while (faculty->next) {
		if (faculty->name != _faculty) {
			faculty = faculty->next;
		}
		else {
			if (_cathedra != "0") {
				return;
			}

			Node *cathedra = faculty->first_child;
			if (faculty->first_child == NULL) {
				Node* new_cathedra = new Node();
				new_cathedra->name = _cathedra;
				new_cathedra->next = NULL;
				faculty->first_child = new_cathedra;
			}
			while (cathedra->next) {
				if (cathedra->name != _cathedra) {
					cathedra = cathedra->next;
				}
				else {
					return;
				}
			}
			Node *new_cathedra = new Node();
			new_cathedra->name = _faculty;
			cathedra->next = new_cathedra;
		}

	}
	Node *new_faculty = new Node();
	new_faculty->name = _cathedra;
}