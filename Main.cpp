#include "Class.hpp"

int main()
{
    Text object; // Instanciação do objeto da classe
    string teste, busca;

    getline(cin, teste);
    getline(cin, busca);

    object.KMP(teste,busca);
    return 0;
}

void
Text::KMP(string Text, string Search)
{
  int T_index, S_index; // Indices de Text & Search respectivamente         
    
  T_index = 0;  S_index = 0;
  Text::CalPrefix(Search, Search.size());

  while((unsigned)T_index <= Text.size())
    {
        if(Text[T_index] == Search[S_index])
        {
            T_index++;
            S_index++;
        }
        if((unsigned)S_index == Search.size())
        {
            cout << "Houve casamento!\n";
            cout << "Posicao:" << T_index - S_index << endl;
            S_index = Text::Support[S_index - 1];
        }
        if((unsigned)T_index < Text.size() && Search[S_index] != Text[T_index])
        {
            if(S_index == 0)
                T_index++;
            else
                S_index = Text::Support[S_index - 1];
        }
    }
    cout << "Nao houve casamento!\n";
}
/* Encontra o maior prefixo que também é sufixo para auxilar no metodo KMP, e 
   reduzir comparações desnecessárias a serem realizadas pelo mesmo */
void
Text::CalPrefix(string Search, int S_size)
{
    int k; // Indice e tamanho max da string Support
    int j; // Indice que localiza as posições de matching

    Text::Support = new int[S_size];
    Support[0] = 0;
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
}
