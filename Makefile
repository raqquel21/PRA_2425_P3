bin/testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	g++ -o bin/testTableEntry testTableEntry.cpp
clean: 
	rm -rf *.o *.gch bin

bin/testHashTable: testHashTable.cpp Dict.h HashTable.h TableEntry.h  # modificar si hace falta
	mkdir -p bin
	g++ -o bin/testHashTable testHashTable.cpp

bin/testBSTree: testBSTree.cpp BSTree.h BSNode.h 
	mkdir -p bin
	g++ -o bin/testBSTree testBSTree.cpp
