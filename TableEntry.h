#ifndef TABLEENTRY_H
#define TABLEENTRY_H
#include <string>
#include <ostream>

template <typename V>
class TableEntry {
	public: 
	// Atributos
	std::string key;
	V value;
	
	//Métodos constructores
	TableEntry (std::string key, V value) : key(key), value(value) {} // Inicializamos todos los valores
	TableEntry (std::string key): key(key), value(V()) {}
	TableEntry() : key (""), value (V()) {}

	//Métodos sobrecargadores operacionales:
	friend bool operator == (const TableEntry<V> &te1, const TableEntry<V> &te2){ 
		return (te1.key == te2.key);
	}
	friend bool operator != (const TableEntry<V> &te1, const TableEntry<V> &te2){
		return (te1.key != te2.key);
	}

	friend std::ostream& operator << (std::ostream &out, const TableEntry<V> &te){
		out << "(Clave: " << te.key << ")" << " (Valor: " << te.value << ")";
		return out;
	}
	friend bool operator<(const TableEntry<V> &te1, const TableEntry<V> &te2){
		return (te1.key < te2.key);
	}
	friend bool operator>(const TableEntry<V> &te1, const TableEntry<V> &te2){
		return (te1.key > te2.key);
	}
};
#endif
