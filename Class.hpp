#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class Text
{
public:
	int *Support;
	/* Function which search the pattern in string */
	int KMP(string Text, string Search)
	{
		int Match = 0;
		int T_index, S_index; // Index of Text & Search        
		
		T_index = 0;  S_index = 0;
		CalPrefix(Search, Search.size()); // Call for creating the string Support

		while((unsigned)T_index <= Text.size())
		{
			if(Text[T_index] == Search[S_index])
			{
				T_index++;
				S_index++;
			}
			if((unsigned)S_index == Search.size())
			{
				//cout << T_index - S_index << endl;
				Match++;
				S_index = Support[S_index - 1];
			}
			if((unsigned)T_index <= Text.size() && Search[S_index] != Text[T_index])
			{
				if(S_index == 0)
					T_index++;
				else
					S_index = Support[S_index - 1];
			}
		}
		return Match;
	}

	/* Function to creating the string which reduces the comparations to be realized by the KMP */   
	void CalPrefix(string Search, int S_size)
	{
		int k; // Index and max size of string Support
		int j; // Index for localize the matching positions in string

		Support = new int[S_size];
		Support[0] = 0;
		j = 0, k = 0;

		while(k < S_size)
		{
			if(Search[k + 1] == Search[j]) // If occur match
			{
				j++;
				Support[k] = j;
				k++;
			}
			else
			{
				if(j == 0)
				{
					Support[k] = 0;
					k++;
				}
				else
					j = Support[j - 1]; // J recieve the previous position ( i and j doesn't increased)
			}    
		}      
	}
};
