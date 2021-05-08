#include "hash.h"

HashMap::HashMap(int size) {
    this->size = size;
    table = new Entry*[size];
    for (int i= 0; i < size; i++)
        table[i] = NULL;
}
HashMap::~HashMap() {
    for (int i = 0; i < size; i++)                  
		if (table[i] != NULL)                        
			delete table[i];            
	delete[] table;
}
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

 Entry* HashMap::get(string key){
    int index = myHash(key) % size;
    int startIndex = index;
    while (table[index] != NULL && table[index]->getKey() != key) {                  
		index = (index + 1) % size;
        if(index == startIndex) return NULL;
    }
    return table[index];
}
unsigned long HashMap::myHash(string str){

}

