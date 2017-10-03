#ifndef decodeBF_h
#define decodeBF_h
#include <list>

using namespace std;

class decodeBF {
private:
	int p = 0;
	
	void checkASCII(char ascii);
	void checkLoop(string bfcode);
	list <char> mem;

public :
	decodeBF();
	~decodeBF(); 
	decodeBF(string code); 
	void compile(string code); 

};
#endif