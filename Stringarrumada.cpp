#include <iostream>
#include <string>

using namespace std;

int main()
{
string name = "arquivo_3.txt/arquivo_1.txt/arquivo_3.txt/arquivo_5.txt/arquivo_6.txt/";
string substri;
int n = 5;         /// quantidade de barras que tem
int pos = 0;        /// posição da string
int found = 0;       /// Ultima posição encontrada da barra

    
    for (int i = 0; i < n; i++)
    {
        found = name.find_first_of('/', pos);
        if((unsigned)found != string::npos)
        {
            substri.assign(name, pos, found - pos);
            pos = found + 1;
        }
        cout << substri << endl; 
    }

    return 0;
}

/* Versão do Wilson guardada para caso seja necessária */
/*
int main()
{
string name = "arquivo_3.txt/arquivo_1.txt/arquivo_3.txt/arquivo_5.txt/";
string substri;
//int n = 3;           /// quantidade de barras que tem
int barras = 0;
int pos = 0;        /// posição da string
int tam = 0;      /// tamanho da string
int ult_pos = -1; /// ultima posição do barra

    for (int i = ult_pos + 1; name[i] != '\0'; i++)
    {
        if(name[ult_pos] == '/')
            pos = i;
            
        if(name[i] != '/')
            tam++;  
        ult_pos++;
        if(name[ult_pos] == '/' )
        {
            barras++;
            substri.assign(name, pos, tam);
            cout << substri << endl;
            tam = 0;
        }
            
    }

    return 0;
}
*/
