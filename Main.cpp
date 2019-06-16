#include "Class.hpp"

int main(int argc, char* argv[])
{
  /* Variáveis do programa */
  Text object;        // Objeto para chamar os metodos da classe
  string text_lines;  // Pega as linhas do texto & string auxiliar
  string word;        // Palavras a serem buscadas nos arquivos
  string text_files;  // String contendo o nome de cada arquivo verificado
  string aux;         // Armazenar a quantidade de vezes e a linha que a palavra aparece num arquivo
  ifstream filearq;   // Arquivo de entrada
  fstream file_test;  // Testador de arquivos
  ifstream word_arq;  // Arquivo das palavras a serem buscadas
  ofstream exit;      // Arquivo de saida com as ocorrências
  int n;              // Armazena a quantidade total de arquivo existentes
  int aux_files = 0;  // Variável inteira auxiliar
  /* Variáveis para buscar o nome dos arquivos armazenados dentro da string */
  int pos;            // Posição inicial do nome dos arquivos na string
  int found ;         // Ultima posição da barra na string

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

  filearq.close(); // Fechando o arquivo de entrada

  /* Enquanto não for o fim do arquivo ainda terá palavras a serem buscadas */
  while(!word_arq.eof())
  {
    getline(word_arq, word, ' '); // Pegando a palavra a ser buscada
    transform(word.begin(),word.end(),word.begin(), ::tolower); // Tranformando a palavra buscada em minuscula
    found = 0, pos = 0;
    for (int i = 1; i <= n; i++)  // Procurando em todos os arquivos
    {
      found = text_files.find_first_of('/', pos);
      if((unsigned)found != string::npos)
      {
        text_lines.assign(text_files, pos, found - pos);
        pos = found + 1;
      }
      file_test.open(text_lines);
      aux_files = 1; // Auxilar para escrever a linha da ocorrencia
      while(!file_test.eof()) // Enquanto for diferente do final do arquivo texto
      {
        getline(file_test, text_lines);
        transform(text_lines.begin(),text_lines.end(),text_lines.begin(), ::tolower); // Transformando a linha do arquivo em minuscula
        if(object.KMP(text_lines, word) != 0) // Se encontrou a palavra na linha
        {
          aux.append(' ' + to_string(i) + ',' + to_string(aux_files)); // Armazena a linha e o arquivo em que foi encontrado na string
        } 
        aux_files++;
      }
      file_test.close(); 
    }
    if(!aux.empty()) // Se a palavra foi encontrada em alguma posição
    {
      text_lines.assign(argv[1]); // Auxilar para receber o nome do arquivo de entrada
      exit.open(text_lines + ".out", ofstream::out | ofstream::app);
      exit << word << aux << endl;
      exit.close(); 
    }
    aux.clear(), text_lines.clear();
  }
   
  return 0;
}


