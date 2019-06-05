#include "Class.hpp"

int main()
{
    Text object; // Instanciação do objeto da classe
    string teste, busca;

    getline(cin, teste);
    getline(cin, busca);
 
    cout << object.KMP(teste, busca);
    cout << "\n";
    return 0;
}

int
Text::KMP(string Text, string Search)
{
  int T_index, S_index; // Indices de Text & Search respectivamente
  int T_size, S_size;   // Tamanho de Text & Search
  bool equal;           

  T_size = Text.size();
  S_size = Search.size();
  T_index = 0;  S_index = 0;
  Text::CalSupport(Search, S_size);

  while(T_index <= T_size - S_size)
    {
        equal = true;
        while(S_index < S_size && equal)
        {
            if(Text[T_index + 1] == Search[S_index + 1])
            {
                T_index++;
                S_index++;
            }
            else 
                equal = false;  
        }
        if(equal)
        {
            cout << "Houve casamento!\n";
            return T_index - S_size + 1;
        }
        if(S_index == 0)
            T_index++;
        else
            S_index = Text::Support[S_index];    
    }
    cout << "Nao houve casamento!\n";
    return -1;
}

void
Text::CalSupport(string Search, int S_size)
{
    int j, k;

    Text::Support[0] = 0;
    j = 0;

    k = 1;
    while(k < S_size)
    {
        if(Search[k + 1] == Search[j + 1])
        {
            k++, j++;
            Text::Support[k] = j;
        }
        else
        {
            if(j == 0)
            {
                k++;
                Text::Support[k] = 0;
            }
            else
                j = Text::Support[j];      
        }     
    }       
}
