#include <iostream>

using namespace std;

class Text
{
public:
	int T_size, S_size;
	string Text, Search, Support;
	int KMP(string,string,int,int);
	void CalSupport(string,int);
};
