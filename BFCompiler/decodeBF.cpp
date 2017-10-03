#include <iostream>
#include "decodeBF.h"

decodeBF::decodeBF() { 
	mem.insert(mem.begin(), NULL); //bf ptr은 1부터 시작이니까. 
}
decodeBF::~decodeBF() { }

decodeBF::decodeBF(string bfcode) {
	mem.insert(mem.begin(), NULL);
	compile(bfcode);
}


void decodeBF::compile(string bfcode) {
	checkLoop(bfcode);
	char ch = '0';
	int i = 0; //now code index
	list <char>::iterator itr = mem.begin();
	mem.push_back(0); //itr 배열에서 mem[p]에서 p역할
	itr++;
	while (i < bfcode.length()) {
		ch = bfcode.at(i);


		switch (ch) {

		case '>':
			if (itr == --mem.end()){
				mem.push_back(0);
			}
			itr++;
			break;
		case '<':
			itr--;
			if (itr == mem.begin()) {
				printf("Error : Pointers are not positive");
				exit(1);
			}
			break;
		case '.':
			cout << *itr;
			break;
		case '+':
			(*itr)++;
			checkASCII((*itr));
			break;
		case '-':
			(*itr)--;
			checkASCII((*itr));
			break;
		case '[':
			if ((*itr) == 0) {
				while (bfcode.at(i) != ']') {
					i++;
				}
			}
			break;
		case ']':
			if ((*itr) != 0) {
				while (bfcode.at(i) != '[') {
					i--;
				}
			}
			break;
		}
		i++;
	}
}

void decodeBF::checkASCII(char ascii) {
	if (!(0 <= ascii && ascii <= 255)) {
		printf("Error : pointers are not in ASCII code Number ranges");
		exit(1);
	}
}
void decodeBF::checkLoop(string bfcode) {
	int stratloop = 0;
	int i=0;
	char ch = '0';
	while (i < bfcode.length()) {
		ch = bfcode.at(i);
		if (ch == '[') stratloop++;
		else if (ch == ']') {
			stratloop--;
			if (stratloop < 0) {
				printf("Error: ""]""comes first!  ");
				exit(1);
			}
		}
		i++;
	}

	if (stratloop != 0) {
		printf("Error: Loop Not Close ([ & ] not same)");
		exit(1);
	}
}