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
		if(size <= 0) throw std::invalid_argument("Tamaño inválido");
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
		for(int i = 0; i < th.max; i++){
			out << i << ": " << th.table[i] << std::endl;
		}
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

	void insert(std::string key, V value) override{
		int tmp = h(key);
		// Verificar si la clave ya existe
		for (int i = 0; i < table[tmp].size(); i++) {
			if (table[tmp][i].key == key) {
			throw std::runtime_error("La llave ya existe");
			}
		}
		TableEntry<V> entrada(key, value); // Crea una nueva entrada con key y value
		table[tmp].insert(0, entrada); // Inserta la entrada en la posición correspondiente
		n++; // Incrementa el contador de elementos
	}
	V search (std::string key) override{
		int pos = h(key);
		
		if (table[pos].empty()) {
			throw std::runtime_error("No se ha encontrado key");
		}
		for(int i = 0; i < table[pos].size(); i++){
			if(table[pos][i].key == key){
				return table[pos][i].value;
			}
		}
		throw std::runtime_error("No se ha encontrado key");
	}

	V remove (std::string key) override{
		int pos = h(key);

		if (table[pos].empty()){
			throw std::runtime_error("No se ha encontrado key");
		}
		for(int i = 0; i < table[pos].size(); i++){
			if(table[pos][i].key == key){
				V valor = table[pos][i].value; 
				table[pos].remove(i);
				n--;
				return valor;
			}
		}
		throw std::runtime_error("No se ha encontrado key");

	}
	int entries () override{
		return n;
	}
};

#endif
