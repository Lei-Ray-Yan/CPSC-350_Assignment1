/*
- Raymond Raymond
- 2297956
- lyan@chapman.edu
- CPSC-350-01
- Assignment 1

- this is the header file for FileProcessor.cpp.

*/


#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>

using namespace std;

/*
  the class that handles the file process functionalities.
*/
class FileProcessor{
  public:
    /*
      default contructor.
    */
    FileProcessor();
    /*
      default destructor.
    */
    ~FileProcessor();

    /*
      the "main" method for the file processing, does all the procedures for the core function of the program.
      the real main method will be handling things like asking user if they want to process another file, etc.
    */
    void processFile(string filename);

    /*
      this function get a file's content from a file name.
    */
    bool getFileContent(ifstream& file, string filename);
    /*
      this function extract and returns the next string from ifstream.
    */
    string extractNextString(ifstream& file);
    /*
      this function checks if the end of file has been reached, returns true if end reached.
    */
    bool fileEndReached(ifstream& file);
    /*
      this function convert a string to all upper case.
    */
    void stringToUpperCase(string& myStr);

    /*
      this function records all nucleotides from the given string.
    */
    void getNucleotides(string myStr, int& total, int& nA, int& nC, int& nT, int& nG);
    /*
      this function records all bigram from the given string.
    */
    void getBigram(string myStr, int& numB, int& bAA, int& bAC, int& bAT, int& bAG,
                                        int& bCA, int& bCC, int& bCT, int& bCG,
                                        int& bTA, int& bTC, int& bTT, int& bTG,
                                        int& bGA, int& bGC, int& bGT, int& bGG);

    /*
      this function calculates the probability of each nucleotides.
    */
    void nucleotidesProb(int& numN, int& nA, int& nC, int& nT, int& nG, float& pA, float& pC, float& pT, float& pG);
    /*
      this function calculates the probability of each bigram.
    */
    void bigramProb(int& numB, int& bAA, int& bAC, int& bAT, int& bAG,
                                        int& bCA, int& bCC, int& bCT, int& bCG,
                                        int& bTA, int& bTC, int& bTT, int& bTG,
                                        int& bGA, int& bGC, int& bGT, int& bGG,
                                        float& pAA, float& pAC, float& pAT, float& pAG,
                                        float& pCA, float& pCC, float& pCT, float& pCG,
                                        float& pTA, float& pTC, float& pTT, float& pTG,
                                        float& pGA, float& pGC, float& pGT, float& pGG);

    /*
      this function generate a int representing random length based on given mean and SD.
    */
    int generateRandomLength(float fMean, float fSD);
    /*
      this function generate a randome nucleotide bansed on given probabilities. 
    */
    char generateRandomNucleotide(float pA, float pC, float pT, float pG);
};


















