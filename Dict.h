#ifndef DICT_H
#define DICT_H
#include <cstddef>
#include <stdexcept>
#include <string>

template <typename V>
class Dict { // Es una clase abstracta pura y genérica	
	public:
	// Métodos virtuales puros y genéricos
		void insert (std::string key, V value) = 0;
		V search (std::string key) = 0;
		V remove (std::string key) = 0;
		int enteries() = 0; 
};

#endif
