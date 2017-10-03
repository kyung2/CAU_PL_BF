#include <stdio.h>

#include <fstream> //file 
#include <string>
#include <iostream> //default
#include "decodeBF.h"

#pragma warning (disable : 4996)

using namespace std;
int main(int argc, char* argv[]) {
	int s;
	
	ifstream fp(argv[1]);
	//ifstream fp("test.bf");
	string bfcode,source = "";
	
	while (getline(fp, bfcode)) {
		source += bfcode;

	}
	cout << source;

	decodeBF bf;
	bf.compile(source);



	//cmd 창 꺼지는거 방지

	scanf("%d", &s);
	return 0;
}



/*
참고 url 
example ./BF hellowrold.bf : http://mwultong.blogspot.com/2006/12/c-argc-argv-main-function-parameter.html

*/