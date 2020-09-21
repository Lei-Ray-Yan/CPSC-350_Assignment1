#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>

using namespace std;

class FileProcessor{
  public:
    FileProcessor();
    ~FileProcessor();

    void processFile(string filename);

    bool getFileContent(ifstream& file, string filename);
    string extractNextString(ifstream& file);
    bool fileEndReached(ifstream& file);
    void stringToUpperCase(string& myStr);

    void getNucleotides(string myStr, int& total, int& nA, int& nC, int& nT, int& nG);
    void getBigram(string myStr, int& numB, int& bAA, int& bAC, int& bAT, int& bAG,
                                        int& bCA, int& bCC, int& bCT, int& bCG,
                                        int& bTA, int& bTC, int& bTT, int& bTG,
                                        int& bGA, int& bGC, int& bGT, int& bGG);

    void nucleotidesProb(int& numN, int& nA, int& nC, int& nT, int& nG, float& pA, float& pC, float& pT, float& pG);
    void bigramProb(int& numB, int& bAA, int& bAC, int& bAT, int& bAG,
                                        int& bCA, int& bCC, int& bCT, int& bCG,
                                        int& bTA, int& bTC, int& bTT, int& bTG,
                                        int& bGA, int& bGC, int& bGT, int& bGG,
                                        float& pAA, float& pAC, float& pAT, float& pAG,
                                        float& pCA, float& pCC, float& pCT, float& pCG,
                                        float& pTA, float& pTC, float& pTT, float& pTG,
                                        float& pGA, float& pGC, float& pGT, float& pGG);

    int generateRandomLength(float fMean, float fSD);
    char generateRandomNucleotide(float pA, float pC, float pT, float pG); 
};


















