#include "Class.hpp"

int main()
{
    // variaveis 
  string text_lines; // pegar linhas de texto
  string nome_arq;  // nome do arquivo de entrada
  string word;
  string text_files; // lista de strings contendo o nome de cada arquivo que será armazenado
  ifstream filearq; // arquivo de entrada
  fstream file_test;  // testador de arquivos
  ifstream word_arq;
  int n;              // numero recebido pelo arq_in
  int aux_files = -1; 

// lendo o arquivo de entrada e abrindo
  cout << "Entre com o nome do arquivo: \n";
  getline(cin,nome_arq);
  filearq.open(nome_arq);

// pegando a primeira linha do arquivo contendo o numero de arquivos que entrarâo
  getline(filearq, text_lines);
  n = text_lines[0]- '0'; // convertendo o caractere recebido para um inteiro

  // rodando n vezes recebendo os arquivos de texto
  for (int i = 0; i < n; i++)
  {
    getline(filearq, text_lines); //pegando o nome do arquivo daquela linha
    file_test.open(text_lines); //abrindo o arquivo
    if(file_test.is_open())  // caso esteja aberto, significa que não foi criado
    {
      aux_files++; //incrementando a quantidade de arquivos que podem ser aberto
      text_lines.append(text_files); // armazenando o nome do arquivo
      text_files.append("/");
    }
    file_test.close(); //fechando o arquivo independente se foi criado ou aberto
  } // fim for
  n = aux_files; // recebe a real quantidade de arquivos que há dentro da string;

  // Até esta parte, já foi possivel, ler o arquivo texto de entrada, ler o numero
  // de arquivos, e reconhecer se estão funcionando ou não, caso não estejam não 
  // armazenará o determinado arquivo

// Recebendo o arquivo contendo as palavras
  getline(filearq, text_lines);
  word_arq.open(text_lines);
  if(word_arq.is_open() == 0)
    cout << "Não foi possível encontrar o arquivo contendo os padrões a serem buscados\n";

// Enquanto não for o fim do arquivo ainda terá palavras a serem buscadas
  while(!word_arq.eof())
  {
    getline(word_arq, word); //pegando a palavra a ser buscada
    if(!word_arq.eof()) // caso seja diferente do final do arquivo, continue
      for (int i = 0; i <= n; i++)  // procurando em todos os arquivos
      {
        file_test.open(text_files); //abrindo o arquivo para busca
        while(!file_test.eof()) // enquanto for diferente do final do arquivo texto
        {
          getline(file_test, text_lines);//mandando uma linha por vez do arquivo para o aux
          // MANDAR PARA O KMP
        } // fim while
        file_test.close(); // após acabarem as buscas, fechar arquivo
      }// fim for, acabaram os arquivos
  }// fim while palavras, acabaram as palavras a serem buscadas

   
  filearq.close();

    
    return 0;
}
/* Função que realiza do padrão desejado na string que foi recebida pelo arquivo */
int
Text::KMP(string Text, string Search)
{
  int T_index, S_index; // Indices de Text & Search respectivamente         
    
  T_index = 0;  S_index = 0;
  CalPrefix(Search, Search.size()); //Chamada para criar o array Support

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
