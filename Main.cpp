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

    
  T_index = 0;  S_index = 0;
  Text::CalPrefix(Search, Search.size());
  cout << Text::Support[0];

  while(T_index <= Text.size())
    {
        if(Text[T_index + 1] == Search[S_index + 1])
        {
            T_index++;
            S_index++;
        }
        if(S_index == Search.size())
        {
            cout << "Houve casamento!\n";
            return T_index - S_index;
            S_index = Text::Support[S_index - 1];
        }           
        if(S_index == 0)
            T_index++;
        else
            S_index = Text::Support[S_index - 1];   
    }
    cout << "Nao houve casamento!\n";
    return -1;
}
/* Encontra o maior prefixo que também é sufixo para auxilar no metodo KMP, e 
   reduzir comparações desnecessárias a serem realizadas pelo mesmo */
void
Text::CalPrefix(string Search, int S_size)
{
    int k; // Indice e tamanho max da string Support
    int j; // Indice que localiza as posições de matching

    Text::Support[0] = 0;
   
    j = 0, k = 0;

    while(k < S_size)
    {
        if(Search[k + 1] == Search[j]) // Se der match
        {
            j++;
            Text::Support[k] = j;
            k++;
        }
        else
        {
            if(j == 0)
            {
                Text::Support[k] = 0;
                k++;
            }
            else
                j = Text::Support[j - 1]; // J recebe a posição anterior não incrementa i nem j;
        }    
    }
     cout << Text::Support;       
}
