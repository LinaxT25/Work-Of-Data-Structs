#include "Class.hpp"

int main(int argc, char* argv[])
{
  /* Variables */
  Text object;        // Object for call methods of class
  string text_lines;  // String to store text lines also works as auxiliary string
  string word;        // Word which need searching in archives
  string text_files;  // String stores the name of verified files 
  string aux;         // Store the number of files which we need searching recieved by infile
  ifstream filearq;   // Infile
  fstream file_test;  // Test the files
  ifstream word_arq;  // File with content the words for need be searching
  ofstream exit;      // Outfile
  int n;              // Store the amount of files(can exist or not)
  int aux_files = 0;  // Aux variable
  
  /* Variables to searching the name of verified files */
  int pos;            // Initial position of files in string
  int found;          // Last position of bar in string(files names separated by character '/' in string)

  /* Reading the infile passed by command arguments and sending the content for text_lines*/
  filearq.open(argv[1]);
  getline(filearq, text_lines); 

  /* Converting the first line(numbers caracters) in integers */
  n = stoi(text_lines);
  
  /* Verifies the existence of files recieved from infile */
  for (int i = 0; i < n; i++)
  {
    getline(filearq, text_lines); 
    file_test.open(text_lines);  
    if(file_test && !filearq.eof())       
    {
      aux_files++; // Increment the index of verified files
      text_files.append(text_lines + "/"); // Store the name of verified file
    }
    file_test.close(); 
  }
  n = aux_files; // Recieve the total amount of verifies files

  /* Recieving the file with words to be searched */
  getline(filearq, text_lines);
  word_arq.open(text_lines);
  if(!word_arq)
    cout << "Error in opening the file\n";
  filearq.close();

  /* Searching the desires words in the verified files */
  while(!word_arq.eof())
  {
    getline(word_arq, word, ' '); // Catching the word to be searched
    transform(word.begin(),word.end(),word.begin(), ::tolower); // Transforming the word in lowercase
    found = 0, pos = 0;
    for (int i = 1; i <= n; i++)  // Searching in all verified files
    {
      found = text_files.find_first_of('/', pos);
      if((unsigned)found != string::npos)
      {
        text_lines.assign(text_files, pos, found - pos);
        pos = found + 1;
      }
      file_test.open(text_lines);
      aux_files = 1; // Variable used to store the line of occurency
      while(!file_test.eof())
      {
        getline(file_test, text_lines);
        transform(text_lines.begin(),text_lines.end(),text_lines.begin(), ::tolower); // Transforming the line in lowercase
        if(object.KMP(text_lines, word) != 0) // Calling the method for searching the word in line
        {
          aux.append(' ' + to_string(i) + ',' + to_string(aux_files)); // Storing the line and the file where occur matching
        } 
        aux_files++;
      }
      file_test.close(); 
    }
    text_lines.assign(argv[1]); // Aux to recieve the name of infile
    exit.open(text_lines + ".out", ofstream::out | ofstream::app);
    if(!aux.empty()) // If the word have been founded in some position
      exit << word << aux << endl;
    exit.close();
    aux.clear(), text_lines.clear();
  }
   
  return 0;
}


