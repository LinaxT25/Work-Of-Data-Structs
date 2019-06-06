#include <iostream>
#include <vector>

using namespace std;

class Text
{
public:
	vector<int> Support;
	int KMP(string,string);
	void CalPrefix(string,int);
};
