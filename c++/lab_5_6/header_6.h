#include <iostream>
#include <string>
#include<stdio.h> 
#include<stdlib.h> 
using namespace std;

template <class T> class Node;
template <class T> class Tree;

//FUNKCJE SPRAWDZAJ¥CE POPRAWNOŒÆ WPROWADZONYCH DANYCH
/*
double valueToCheck() {
	int tmp1;
	string tmp2;
	int sign;

	while (cin >> tmp2) {
		tmp1 = 0;
		sign = 0;
		if (tmp2[0] == '-') {
			tmp1 += 1;
		}
		for (int n = 0; n < tmp2.length(); n++) {
			if (('0' <= tmp2[n] and tmp2[n] <= '9') or tmp2[n] == '.') {
				if (tmp2[n] == '.') {
					sign += 1;
				}
				tmp1++;
			}
		}

		if (tmp1 == tmp2.length() and sign == 1) {
			float result = atof(tmp2.c_str());
			return result;
		}
		else if (tmp1 == tmp2.length() and sign == 0) {
			float result = atof(tmp2.c_str());
			return result;
		}
	}
}

int iToCheck() {
	int tmp1;
	string tmp2;

	while (cin >> tmp2) {
		tmp1 = 0;
		for (int n = 0; n < tmp2.length(); n++) {
			if ('0' <= tmp2[n] and tmp2[n] <= '9') {
				tmp1++;
			}
		}
		if (tmp1 == tmp2.length()) {
			int result = atoi(tmp2.c_str());
			return result;
		}
	}
}

int i2ToCheck() {
	int tmp1;
	string tmp2;

	while (cin >> tmp2) {
		tmp1 = 0;
		if (tmp2.length() == 1 and (tmp2[0] == '0' or tmp2[0] == '1' or tmp2[0] == '2')) {
			int result = atoi(tmp2.c_str());
			return result;
		}
	}
}
*/

//================================CLASS: ELEMENT=======================
template <class T>
class Node {
public:
	T value;

	int level;
	Node(T value, Node<T> *left_ptr = nullptr, Node<T> *right_ptr = nullptr);

protected:
	Node <T> *left_ptr;
	Node <T> *right_ptr;

	friend class Tree <T>;
};

//================================CLASS: TREE=======================
template <class T>
class Tree {
public:
	Tree(Node <T> *root = nullptr);
	Node <T> *root;

	void AddElement(T val);

	Node<T> *DeleteElement(Node<T> *ptr, T val);

	//pre-, in-, postorder
	void preorder(Node <T> *ptr);
	void postorder(Node <T> *ptr);
	void inorder(Node <T> *ptr);

	Node<T> *minValueNode(Node<T> * node);
	void examine(Node <T> *ptr);

	Node<T> *search(Node<T> * node);

	//display tree
	void PrintTree(Node <T> *ptr);

	//isEmpty
	bool isEmpty() {
		if (root == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	bool Search(Node<T> *ptr, T val)
	{
		if (ptr == NULL) { return false; }
		else if (ptr->value == val) { return true; }
		else if (val <= ptr->value) { Search(ptr->left_ptr, val); }
		else { Search(ptr->right_ptr, val); }
	}

};

template <class T>
Node<T>::Node(T value, Node<T> *left_ptr, Node<T> *right_ptr) :value(value), left_ptr(left_ptr), right_ptr(right_ptr) {}

//FUNKCJE pre-, in- oraz postorder.
//====================================================================
template <class T>
void Tree <T> ::preorder(Node <T> *ptr) {
	if (ptr) {
		examine(ptr);
		preorder(ptr->left_ptr);
		preorder(ptr->right_ptr);
	}
}

template <class T>
void Tree <T> ::postorder(Node <T> *ptr) {
	if (ptr) {
		postorder(ptr->left_ptr);
		postorder(ptr->right_ptr);
		examine(ptr);
	}
}

template <class T>
void Tree <T> ::inorder(Node <T> *ptr) {
	if (ptr) {
		inorder(ptr->left_ptr);
		examine(ptr);
		inorder(ptr->right_ptr);
	}
}

template <class T>
void Tree <T> ::PrintTree(Node <T> *ptr) {

	cout << "PreOrder: ";
	preorder(ptr);
	cout << endl;

	cout << "InOrder: ";
	inorder(ptr);
	cout << endl;

	cout << "PostOrder: ";
	postorder(ptr);
	cout << endl;

}
//====================================================================

template <class T>
void Tree <T> ::AddElement(T val) {
	if (Search(root, val))
		cout << "Wartosc "<<val<<" nie zostala dodana do BST. Wykryto duplikat!" << endl;
	else
	{
		if (root) {
			Node <T> *current = root, *child;
			while (current) {
				if (current->value > val) {
					child = current->left_ptr;
					if (!child) {
						current->left_ptr = new Node<T>(val);
						return;
					}
				}
				else {
					child = current->right_ptr;
					if (!child) {
						current->right_ptr = new Node<T>(val);
						return;
					}
				}
				current = child;
			}
		}
		else {
			root = new Node <T>(val);
		}
	}
}

template <class T>
Tree<T>::Tree(Node<T> *root) :root(root) {}

template<class T>
void Tree<T>::examine(Node<T> *ptr) {
	cout << ptr->value << " ";
}
//==================================REMOVE======================================
template <class T>
Node<T> * Tree<T>::minValueNode(Node<T> *ptr) {
	Node<T>* current = ptr;

	while (current->right_ptr != nullptr)
		current = current->right_ptr;

	return current;
}

template <class T>
Node<T> * Tree<T> ::DeleteElement(Node<T> *ptr, T val) {
	if (isEmpty()) {
		cout << "BST jest puste! ";
	}
	if (!Search(root,val)) {
		cout << "Wartosc "<<val<<" nie zostala usunieta. " << endl;
	}
	else {
		if (ptr == nullptr)
			return ptr;

		if (val > ptr->value)
			ptr->right_ptr = DeleteElement(ptr->right_ptr, val);

		else if (val < ptr->value)
			ptr->left_ptr = DeleteElement(ptr->left_ptr, val);

		else {
			/*
				if (ptr->left_ptr == nullptr) {
				Node<T> *tmp = ptr->right_ptr;
				delete ptr;
				return tmp;
			}
				else if (ptr->right_ptr == nullptr) {
				Node<T> *tmp = ptr->left_ptr;
				delete ptr;
				return tmp;
			}
			*/
			if (ptr->left_ptr == nullptr and ptr->right_ptr == nullptr) {
				Node<T> *tmp = nullptr;
				delete ptr;
				cout << "Usunieto lisc!" << endl;
				return tmp;
				
			}
			else {
				Node<T> *tmp = nullptr;
				cout << "Wartosc nie jest lisciem!" << endl;
				return tmp;
			}
			
				Node <T> *tmp = minValueNode(ptr->left_ptr);
				ptr->value = tmp->value;
				ptr->left_ptr = DeleteElement(ptr->left_ptr, tmp->value);

		}
		return ptr;
	}
	
}


