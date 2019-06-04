#include "Class.hpp"

int main()
{
    return 0;
}

int
Text::KMP(string Text, string Search, int T_size, int S_size)
{
  int i, j;
  bool equal;

  i = 0, j = i;
  while(i - j <= T_size - S_size)
    {
        equal = true;
        while(j < S_size && equal)
        {
            if(Text[i + 1] == Search[j + 1])
                i++, j++;
            else 
                equal = false;  
        }
        if(equal)
            return i - S_size + 1;
        if(j == 0)
            i++;
        else
            j = Text::Support[j];    
    }
}

void
Text::CalSupport(string Search, int S_size)
{
    int j, k;

    Text::Support[1] = 0, j = 0;
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