#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
    BSTree<TableEntry<V>>* tree;

    public:
    BSTreeDict(){
        tree = new BSTree<TableEntry<V>>();
    }
    ~BSTreeDict() {delete tree;} // O delete[] ?
    
    friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs){
        out << "BSTree: " << *bs.tree << std::endl;
        return out;
    }

    V operator[](std::string key){
        return search(key);
    }

    int entries() override{ 
        return tree->size();
    }

    void insert(std::string key, V value) override{
        TableEntry<V> entry(key, value);
        //if(tree->search(entry)){
        //throw std::runtime_error("La llave ya existe");
        //}
        tree->insert(entry);
    }

    V search(std::string key) override{
        TableEntry<V> query(key);
        TableEntry<V> result = tree->search(query);
        /*if (!result) {*/
        /*    throw std::runtime_error("Key not found in the dictionary");*/
        /*}*/
        V value = result.value;
        return value;
    }

    V remove(std::string key) override{
        TableEntry<V> query(key);
        TableEntry<V> result = tree->search(query);
        /*if (!result) {*/
        /*    throw std::runtime_error("Key not found in the dictionary");*/
        /*}*/
        V value = result.value;
        tree->remove(query);
        return value;
    }
};

#endif
