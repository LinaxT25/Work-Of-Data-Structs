# Work-Of-Data-Structs

**This work, is a implementation of KMP Algorithm, basically the code recieve one infile with contet the amout of files to be searched, the files with texts to be searched and the words used for this, one in each line in this order repectively, and the code create the outfile, which have the occurrencies as have matching, example below:**

* Infile:
  * 2       // Number of files which we need searching the words
  * File1   // Archive with any text
  * File2   // Another archive with another random text
  * Words   // Archive with words to be searched in above files
 

* File1:
Good programming is not learned from
generalities, but by seeing how significant
programs can be made clean, easy to read.

* File2:
They are also easy to maintain and modify,
human-engineered, efficient, and reliable,
by the application of common sense and
by the use of good programming practices.

* Outfile: // Archive created by program 
  * programming 1,1 2,4  //the pair represents the file and line of occurency respectively (File 1 & Line 1 and File 2 & Line 4)
  * programs 1,3
  * easy 1,3 2,1
  * by 1,2 2,3 2,4
  * human-engineered 2,2
  * and 2,1 2,2 2,3
  * be 1,3
  * to 1,3 2,1
  
*Work very well for simple cases, but have many bugs with more complicated things, feel free for use which you desire, que IDFile in Outfile, depend of the order which the file is writted in Infile(your respectively line in Infile).*

### Infile is passed by terminal argument when starting the program, remember this!!!
