#ifndef DICT_H
#define DICT_H
#include <cstddef>
#include <stdexcept>
#include <string>

template <typename V>
class Dict { // Es una clase abstracta pura y genérica	
	public:
	// Métodos virtuales puros y genéricos
		virtual void insert (std::string key, V value) = 0;
		virtual V search (std::string key) = 0;
		virtual V remove (std::string key) = 0;
		virtual int entries() = 0; 
};

#endif
