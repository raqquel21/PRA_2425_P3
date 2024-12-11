#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T> 
class BSTree {
private:
        //miembros privados
	int nelem;
	BSNode<T> *root;
	// Búsqueda de elementos
	BSNode<T>* search(BSNode<T>*n, T e) const {
		if(n == nullptr){
			throw std::runtime_error("No se ha encontrado el elemento");
			return nullptr;
		} else if (n->elem < e){
			return search(n->right, e);
		} else if (n->elem > e){
			return search(n->left, e);
		} else {
			return n;
		}
	}

	// Insercion de elementos
	BSNode<T>* insert(BSNode<T>* n, T e) {
		BSNode<T>* newNode = new BSNode<T>(e); // newNode tenia que ser un puntero de tipo BSNode<T>
		if(n == nullptr){
			return newNode;
		}else if(n->elem == e) {
			throw std::runtime_error("El elemento ya existe");
		}else if (n->elem < e){
			n->right = insert(n->right, e);
		} else{
			n->left = insert(n->left, e);
		}
		return n;
	}

	// Recorrido e impresión del árbol
	void print_inorder (std::ostream &out, BSNode<T>* n) const {
		if(n != nullptr){
			print_inorder(out, n->left);
			out << n->elem << " ";
			print_inorder(out, n->right);
		}
	}

	// Eliminación de elementos
	BSNode<T>* remove(BSNode<T>* n, T e) {
		if(n == nullptr){
			throw std::runtime_error("No existe el elemento");
		} else if (n->elem < e){
			n->right = remove(n->right, e);
		} else if (n-> elem > e){
			n->left = remove(n->left, e);
		} else {
			if(n->left != nullptr && n->right != nullptr){
				n->elem = max(n->left);
				n->left = remove_max(n->left);
			} else {
				n = (n->left != nullptr) ? n->left: n->right; 
			}
		}
		return n;
	}

	T max(BSNode<T>* n) const {
		if (n == nullptr){
			throw std::runtime_error("No se ha encontrado el elemnto");
		} else if (n->right != nullptr) {
			return max(n->right);
		} else {
			return n->elem;
		}
	}
	BSNode<T>* remove_max(BSNode<T>* n) {
		if(n->right == nullptr){
			return n->left;
		} else {
			n->right = remove_max(n->right);
			return n;
		}
	}

	// Destrucción
	void delete_cascade(BSNode<T>* n) {
		if (n != nullptr){
			delete_cascade(n->left);
			delete_cascade(n->right);
			delete n;
		}
	}

public:
        // miembros públicos
	// Búsqueda de elementos
	BSTree() : nelem(0), root(nullptr){} // Crea un ABB vacio
	
	int size() const {
	    return nelem;
	}
	T search(T e) const {
		BSNode<T>* result = search(root, e);
		return result->elem;
	}
	T operator[] (T e) const {
		return search(e);
	}
	
	// Insercion de elementos
	void insert(T e) {
		root = insert(root, e);
	}
	// Recorrido e impresión del árbol
	friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst) {
		bst.print_inorder(out, bst.root);
		return out;
	}

	// Eliminación de elementos
	void remove(T e) {
		root = remove(root, e);
	}

	// Destrucción 
	~BSTree() {
		delete_cascade(root);
	}
};

#endif
