#include <iostream>
using namespace std;

template <class T> class Node;
template <class T> class Tree;

template <class T> class Node {
	public:
		T value;
		Node( T value_, Node<T>* leftPtr_ = nullptr, Node<T>* rightPtr_ = nullptr );

	protected:
		Node <T>* rightPtr;
		Node <T>* leftPtr;
		friend class Tree <T>;
};

template<class T> 
Node<T>::Node( T value_, Node<T>* leftPtr_, Node<T>* rightPtr_ ) {
	value = value_;
	leftPtr = leftPtr_;
	rightPtr = rightPtr_;
}

template <class T> 
class Tree {
	public:
		Tree( Node<T>* root = nullptr );
		void insert( T val );
		void inorder( Node <T>* ptr );
		void examine( Node <T>* ptr );

		//korzen
		Node <T>* root;

		void DeleteTree( Node <T>* tmp );

		bool isEmpty();

		bool contains( Node<T>* ptr, T val );
};

template<class T> 
Tree<T>::Tree( Node<T>* root ) :root( root ) {}

template<class T> 
void Tree<T>::examine( Node<T>* ptr ) {
	cout << ptr->value << " ";
}

template <class T> 
void Tree <T> ::inorder( Node <T>* ptr ) {
	if (ptr) {
		inorder( ptr->leftPtr ); examine( ptr );
		inorder( ptr->rightPtr );
	}
}

//WSTAWIANIE DO DRZEWA
template <class T> 
void Tree <T> ::insert( T val ) {
	if (root) {
		Node <T>* current = root, * child;
		while (current) {
			if (current->value > val) {
				child = current->leftPtr;
				if (not child) {
					current->leftPtr = new Node<T>( val );
					return;
				}
			}
			else {
				child = current->rightPtr;
				if (not child) {
					current->rightPtr = new Node<T>( val );
					return;
				}
			}
			current = child;
		}
	}
	else root = new Node <T>( val );
}

template <class T> 
void Tree <T>::DeleteTree( Node <T>* tmp ) {
	if (tmp != nullptr) {
		if (tmp->leftPtr != nullptr) {
			DeleteTree( tmp->leftPtr );
		}

		if (tmp->rightPtr != nullptr) {
			DeleteTree( tmp->rightPtr );
		}

		delete tmp;
		root = nullptr;
	}
}

template <class T>
bool Tree<T>::isEmpty() {
	if (root == nullptr) {
		return true;
	}
	else {
		return false;
	}
}
template <class T>
bool Tree <T>::contains( Node<T>* ptr, T val ) {
	if (ptr == nullptr) return false;
	else if (ptr->value == val) return true;
	else if (val <= ptr->value) contains( ptr->leftPtr, val );
	else contains( ptr->rightPtr, val );
}
