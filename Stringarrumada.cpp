// Example program
#include <iostream>
#include <string>

using namespace std;

int main()
{
string name = "arquivo_1.txt/arquivo_2.txt/arquivo_3.txt/";
string substri;
//int n = 3;           /// quantidade de barras que tem
int barras = 0;
int pos = 0;        /// posição da string
int tam = -1;      /// tamanho da string
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
