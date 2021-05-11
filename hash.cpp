#include "hash.h"
//constructor
HashMap::HashMap(int size) {
    this->size = size;
    table = new Entry*[size];
    for (int i= 0; i < size; i++)
        table[i] = NULL;
}
//Deconstructor
HashMap::~HashMap() {
    for (int i = 0; i < size; i++)                  
		if (table[i] != NULL)                        
			delete table[i];            
	delete[] table;
}
//add entries to hashmap
void HashMap::put(Entry *e){
    string key = e->getKey();
    int index = myHash(key) % size;
    int startIndex = index;
    while(table[index] !=NULL && table[index]->getKey() != key && table[index]->getKey() != "empty"){
        index = (index + 1) % size;
        if (index == startIndex) throw Overflow();
    }
    table[index] = e;
}
//get data from the hashmap
 Entry* HashMap::get(string key){
    int index = myHash(key) % size;
    int startIndex = index;
    while (table[index] != NULL && table[index]->getKey() != key) {                  
		index = (index + 1) % size;
        if(index == startIndex) return NULL;
    }
    return table[index];
}
//Hashing a using DJB2 hash algorithm
unsigned long HashMap::myHash(string str){
    const char* cstr = str.c_str();
    unsigned long hash = 5381;
    int c;
    while (c = *cstr++)
        hash = hash * 33 + c;
    return hash;
}

