#ifndef HASH_H
#define HASH_H

#include <string>

using namespace std;

class Entry {
		string name;
		string phone;
		float salary;
  public:
		Entry(string name, string phone, float salary) {
			this->name = name;
			this->phone = phone;
			this->salary = salary;
		}
		string getKey() { return name; }
		string getPhone() {  return phone; }
		float getSalary() { return salary; }
		void setKey(string str) { name = str; }
};

class HashMap {
  public:      
	class Overflow{};
	HashMap(int size);
	~HashMap();
	unsigned long myHash(string str);
	void put(Entry *e);
	Entry* get(string key);
	Entry* remove(string key);
  protected:
  	Entry **table;
	int size;
};
#endif