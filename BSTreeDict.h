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
    ~BSTreeDict() {delete tree;}
    
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
        TableEntry<V> entrada(key, value);
        tree->insert(entrada);
    }

    V search(std::string key) override{
        TableEntry<V> consulta(key);
        TableEntry<V> res = tree->search(consulta);
        V valor = res.value;
        return valor;
    }

    V remove(std::string key) override{
        TableEntry<V> consulta(key);
        TableEntry<V> res = tree->search(consulta);
        V valor = res.value;
        tree->remove(consulta);
        return valor;
    }
};

#endif
