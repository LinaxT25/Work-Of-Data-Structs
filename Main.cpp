#include "Class.hpp"

int main(int argc, char* argv[])
{
  /* Variáveis do programa */
  string text_lines;  // Pega as linhas do texto & string auxiliar
  string word;        // Palavras a serem buscadas nos arquivos
  string text_files;  // String contendo o nome de cada arquivo verificado
  ifstream filearq;   // Arquivo de entrada
  fstream file_test;  // Testador de arquivos
  ifstream word_arq;  // Arquivo das palavras a serem buscadas
  int n;              // Armazena a quantidade total de arquivo existentes
  int aux_files = 0;  // Variável inteira auxiliar

  /* Lendo o arquivo de entrada e mandando seu conteúdo para text_lines */
  filearq.open(argv[1]);
  getline(filearq, text_lines); 

  /* Verificando a quantidade de arquivos de entrada */
  if(text_lines.size() == 3)
  {
    n = (int)(text_lines[0] - '0') * 100;
    n += (int)(text_lines[1] - '0') * 10;
    n += (int)(text_lines[2] - '0');
  }
  else if(text_lines.size() == 2)
  {
    n = (int)(text_lines[0] - '0') * 10;
    n += (int)(text_lines[1] - '0');
  }
  else
    n = (int)text_lines[0] - '0';
  
  /* Verifica a existencia dos arquivos recebidos */
  for (int i = 0; i < n; i++)
  {
    getline(filearq, text_lines); 
    file_test.open(text_lines);   
    if(file_test.is_open())       
    {
      aux_files++; // Incrementa o indice dos arquivos que existem
      text_files.append(text_lines + "/"); // Armazena o nome dos arquivos
    }
    file_test.close(); 
  }
  n = aux_files; // Recebe a quantidade total de arquivos existentes

  /* Recebendo o arquivo contendo as palavras a serem buscadas */
  getline(filearq, text_lines);
  word_arq.open(text_lines);
  if(!word_arq.is_open())
    cout << "Não foi possível encontrar o arquivo contendo os padrões a serem buscados\n";

  /* Variáveis para buscar o nome dos arquivos armazenados dentro da string */
  int pos = 0;        // Posição inicial do nome dos arquivos na string
  int found = 0;      // Ultima posição da barra na string

  /* Enquanto não for o fim do arquivo ainda terá palavras a serem buscadas */
  while(!word_arq.eof())
  {
    getline(word_arq, word); // Pegando a palavra a ser buscada
    if(!word_arq.eof()) // Caso seja diferente do final do arquivo, continue
    { 
      for (int i = 1; i <= n; i++)  // Procurando em todos os arquivos
      {
        found = text_files.find_first_of('/', pos);
        if((unsigned)found != string::npos)
        {
          text_lines.assign(text_files, pos, found - pos);
          pos = found + 1;
        }
        file_test.open(text_lines); 
        while(!file_test.eof()) // Enquanto for diferente do final do arquivo texto
        {
          getline(file_test, text_lines);
          // MANDAR PARA O KMP
        } 
        file_test.close();
      }
    }
  }
  
  filearq.close();
    
  return 0;
}

/* Função que realiza do padrão desejado na string que foi recebida pelo arquivo */
int
Text::KMP(string Text, string Search)
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
            cout << "Houve casamento!\n";
            cout << "Posicao:" << T_index - S_index << endl;
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
