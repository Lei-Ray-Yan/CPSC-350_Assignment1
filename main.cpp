/*
- Raymond Raymond
- 2297956
- lyan@chapman.edu
- CPSC-350-01
- Assignment 1

- This is the file for main method of this program, it handles all other general functionalities required, wihtout the core function
of processing and outputing files.

*/


#include "FileProcessor.h"
#include <sstream>


/*
  the main method of the program, responsing for all general procedures, like handling user input commands, etc.
  the processing of the file will be in the FileProcessor class's processFile function. 
*/
int main(int argc, char** argv){
  string filename;
  FileProcessor ds;

  bool nextFile = true;
  istringstream inSS;
  string userInput;
  int safeExit = 0;   //preventing inifinite loop
  int loopLimit = 2000;   //max loop time

  //extract the provide file name;
  filename = argv[1];
  cout << "File Name: " << argv[1] << endl;

  //start processing data
  while (nextFile){
    safeExit += 1;

    cout<< "start to process file" << endl;
    ds.processFile(filename);

    //get user input, exit or process another file
    cout << "Enter EXIT to exit the program, or enter another filename to continue." << endl;
    cin >> userInput;
    ds.stringToUpperCase(userInput);

    if(userInput == "EXIT"){
      break;
    }
    filename = userInput;
    cout << "File Name: " << filename << endl;

    //preventing infinite loop
    if(safeExit >= loopLimit){
      cout << "Loop SafeExit triggered. Loop time exceeded: " << loopLimit << endl;
      break;
    }
  }


  return 0;
}