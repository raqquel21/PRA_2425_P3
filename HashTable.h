#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <cstdio>
#include <ostream>
#include <stdexcept>
#include <string>
#include "Dict.h"
#include "TableEntry.h"
#include "../PRA_2324_P1/ListLinked.h"

template <typename V>
class HashTable: public Dict <V> {
	private:
	int n;
	int max;
	ListLinked<TableEntry<V>>* table;
	int h(std::string key){ // Convierte la key en un int 
		char c; 
		int valor_ascii = 0;
		for (int i = 0; i < key.size(); i++){
			c = key.at(i);
			valor_ascii += int(c); // Valor enetero de los carácteres ASCII de la key
		}
		return valor_ascii % max;
	}
	public:
	// Métodos de la tabla Hash
	HashTable(int size) {
		table = new ListLinked<TableEntry<V>>[size];
		max = size;
		n = 0;
	}
	~HashTable(){
		delete[] table;
	}
	int capacity() {
		return max;
	}
	friend std::ostream& operator << (std::ostream &out, const HashTable<V> &th) {
		out << "Tabla Hash: " << th.table << std::endl;
		return out;
	}
	V operator[](std::string key) {
		int pos = h(key); // Calcula el índice hash
		for (int i = 0; i < table[pos].size(); i++) {
			if (table[pos][i].key == key) {
			return table[pos][i].value; // Devuelve el valor asociado
			}
		}
		throw std::runtime_error("Error al encontrar key");
	}
	void insert (std::string key, V value){
		int tmp = h(key); 	
		if(search(key) != -1) { 
			throw std::runtime_error("La llave ya existe");
		}
		if(n == max){
			throw std::runtime_error("Tabla llena");
		}
		TableEntry<V> entrada(key,value); // Crea una nueva entrada con key y value
		table[tmp].insert(0, entrada); //Inserta la entrada en la posición correspondiente
		n++; // Incrementa el contador de elementos

	}

	V search (std::string key) {
		int pos = h(key);
		int indice = table[pos].search(key);
		if (indice == -1){
			throw std::runtime_error("Error al enncontrar key");
		}
		return table[pos][indice].value; 	
	}

	V remove (std::string key) {
		int pos = h(key);
		int indice = table[pos].search(key);
		if(indice == -1){
			throw std::runtime_error("Error al enncontrar key");
		}
		V value = table[pos][indice].value;
		table[pos].remove(indice);
		n--;
		return value;
	}
	int entries (){
		return n;
	}
};

#endif
/*
void insert(const std::string key, const V val) {
    int temp = h(key); // Calcula el índice hash
    int indice = search(key); // Llama a search para ver si la clave ya existe

    if (indice != -1) {
        throw std::runtime_error("Error al encontrar key"); // Si la clave existe, lanza la excepción
    }
    
    // Si la clave no existe, inserta el nuevo valor
    TableEntry<V> entry(key, val);
    table[temp].insert(0, entry);
    n++; // Incrementa el número de elementos
}
int search(const std::string& key) {
    int pos = h(key); // Calcula el índice hash
    for (int i = 0; i < table[pos].size(); ++i) {
        if (table[pos][i].key == key) {
            return i; // Devuelve el índice del elemento encontrado
        }
    }
    return -1; // Devuelve -1 si no se encuentra la clave
}
*/
