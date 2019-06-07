#include <iostream>
#include <fstream>

using namespace std;

class Text
{
public:
	int *Support;
	int KMP(string,string);
	void CalPrefix(string,int);
};
