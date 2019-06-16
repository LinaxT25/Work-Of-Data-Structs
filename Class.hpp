#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class Text
{
public:
	int *Support;
	/* Função que realiza do padrão desejado na string que foi recebida pelo arquivo */
	int KMP(string Text, string Search)
	{
		int T_index, S_index; // Indices de Text & Search respectivamente         
		
		T_index = 0;  S_index = 0;
		CalPrefix(Search, Search.size()); // Chamada para criar o array Support

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
				S_index = Support[S_index - 1];
				return 0;
			}
			if((unsigned)T_index < Text.size() && Search[S_index] != Text[T_index])
			{
				if(S_index == 0)
					T_index++;
				else
					S_index = Support[S_index - 1];
			}
		}
		return -1;
	}

	/* Encontra o maior prefixo que também é sufixo para auxilar no metodo KMP, e 
	reduzir comparações desnecessárias a serem realizadas pelo mesmo */
	void CalPrefix(string Search, int S_size)
	{
		int k; // Indice e tamanho max da string Support
		int j; // Indice que localiza as posições de matching

		Support = new int[S_size];
		Support[0] = 0;
		j = 0, k = 0;

		while(k < S_size)
		{
			if(Search[k + 1] == Search[j]) // Se der match
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
					j = Support[j - 1]; // J recebe a posição anterior não incrementa i nem j;
			}    
		}      
	}
};