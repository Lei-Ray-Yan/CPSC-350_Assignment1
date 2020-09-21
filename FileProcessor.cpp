#include "FileProcessor.h"

using namespace std;

FileProcessor :: FileProcessor(){

}

FileProcessor :: ~FileProcessor(){

}


void FileProcessor :: processFile(string filename){
  ifstream file;
  FileProcessor fp;
  fstream newFile;

  string currString;
  int currLength = 0;

  //variabels for general stats
  int totalNum = 0;
  float lengthSum = 0;
  float lengthSumTemp = 0;
  float lengthMean = 0;
  float sumOfVariance = 0;
  float lengthVariance = 0;
  float lengthSD = 0;

  //variables for Nucleatides
  int numNucleotides = 0;

  int totalNumA = 0;
  int totalNumC = 0;
  int totalNumT = 0;
  int totalNumG = 0;

  float probA = 0;
  float probC = 0;
  float probT = 0;
  float probG = 0;

  //variables for Bigram stats
  int numBigram = 0;

  int numAA = 0;
  int numAC = 0;
  int numAT = 0;
  int numAG = 0;

  int numCA = 0;
  int numCC = 0;
  int numCT = 0;
  int numCG = 0;

  int numTA = 0;
  int numTC = 0;
  int numTT = 0;
  int numTG = 0;

  int numGA = 0;
  int numGC = 0;
  int numGT = 0;
  int numGG = 0;

  float probAA = 0;
  float probAC = 0;
  float probAT = 0;
  float probAG = 0;

  float probCA = 0;
  float probCC = 0;
  float probCT = 0;
  float probCG = 0;

  float probTA = 0;
  float probTC = 0;
  float probTT = 0;
  float probTG = 0;

  float probGA = 0;
  float probGC = 0;
  float probGT = 0;
  float probGG = 0;

  //for outputting
  int randomLength = 0;
  string newString = "";



  //using the for loop to calc the data without storing anything
  for (int i=0; i<2; ++i){
    //see if can find the file or not;
    if(!fp.getFileContent(file, filename)){
      cout << "Cannot find the file based on given file name. " << endl;
      return;
    }

    // get and parse through the file and record useful information \;
    while (!fp.fileEndReached(file)){
      currString = fp.extractNextString(file);
      fp.stringToUpperCase(currString);

      currLength = currString.length();
      lengthSumTemp += currLength;

      if(currString.length() < 1){
        continue;
      }

      if (i == 0){
        totalNum += 1;
        fp.getNucleotides(currString, numNucleotides, totalNumA, totalNumC, totalNumT, totalNumG);
        fp.getBigram(currString, numBigram, numAA, numAC, numAT, numAG, numCA, numCC, numCT, numCG, numTA, numTC, numTT, numTG, numGA, numGC, numGT, numGG);
      }
      if(i == 1){
        sumOfVariance += pow((currLength - lengthMean), 2);
      }
      //cout << sumOfVariance << endl;
    }

    if(i == 0){
      lengthSum = lengthSumTemp;
      lengthMean = lengthSum/ (float)totalNum;
      fp.nucleotidesProb(numNucleotides, totalNumA, totalNumC, totalNumT, totalNumG, probA, probC, probT, probG);
      fp.bigramProb(numBigram,
                    numAA, numAC, numAT, numAG, numCA, numCC, numCT, numCG, numTA, numTC, numTT, numTG, numGA, numGC, numGT, numGG,
                    probAA, probAC, probAT, probAG, probCA, probCC, probCT, probCG, probTA, probTC, probTT, probTG, probGA, probGC, probGT, probGG);
    }
    if(i == 1){
      lengthVariance = sumOfVariance/ totalNum;
      lengthSD = sqrt(lengthVariance);
    }

    file.close();
  }
  cout << "finished analysing file." << endl;

  //start to output file into txt
  cout << "start to output results to new file" << endl;
  newFile.open("RaymondYan.txt", ios :: app);

  if(!newFile.is_open()){
    cout << "Cannot create output file due to unknown reason." << endl;
    return;
  }

  newFile << "----------------------------------------------------"  << endl;
  newFile << "Student Name: Raymond Yan" << endl;
  newFile << "Student ID: 2297957" << endl;
  newFile << "Course: CPSC 350" << endl;
  newFile << "Assignment: Assignment 1" << endl;
  newFile << "Subject: DNA Analysis" << endl;
  newFile << "----------------------------------------------------"  << endl;

  newFile << ""  << endl;
  newFile << ""  << endl;

  newFile << "Sum of Length:                      " << lengthSum << endl;
  newFile << "Mean of Length:                     " << lengthMean << endl;
  newFile << "Variance of Length:                 " << lengthVariance << endl;
  newFile << "Standard Deviation of Length :      " << lengthSD << endl;
  newFile << ""  << endl;
  newFile << "Probability of Nucleotide A         " << probA << endl;
  newFile << "Probability of Nucleotide C         " << probC << endl;
  newFile << "Probability of Nucleotide T         " << probT << endl;
  newFile << "Probability of Nucleotide G         " << probG << endl;
  newFile << ""  << endl;
  newFile << "Probability of Bigram AA            " << probAA << endl;
  newFile << "Probability of Bigram AC            " << probAC << endl;
  newFile << "Probability of Bigram AT            " << probAT << endl;
  newFile << "Probability of Bigram AG            " << probAG << endl;
  newFile << ""  << endl;
  newFile << "Probability of Bigram CA            " << probCA << endl;
  newFile << "Probability of Bigram CC            " << probCC << endl;
  newFile << "Probability of Bigram CT            " << probCT << endl;
  newFile << "Probability of Bigram CG            " << probCG << endl;
  newFile << ""  << endl;
  newFile << "Probability of Bigram TA            " << probTA << endl;
  newFile << "Probability of Bigram TC            " << probTC << endl;
  newFile << "Probability of Bigram TT            " << probTT << endl;
  newFile << "Probability of Bigram TG            " << probTG << endl;
  newFile << ""  << endl;
  newFile << "Probability of Bigram GA            " << probGA << endl;
  newFile << "Probability of Bigram GC            " << probGC << endl;
  newFile << "Probability of Bigram GT            " << probGT << endl;
  newFile << "Probability of Bigram GG            " << probGG << endl;

  newFile << ""  << endl;
  newFile << ""  << endl;

  newFile << "----------------------------------------------------"  << endl;
  newFile << "Generated 1000 DNA Strings: " << endl;
  newFile << "----------------------------------------------------"  << endl;

  for (int i=0; i<1000; ++i){
    newString = "";
    randomLength = fp.generateRandomLength(lengthMean, lengthSD);
    for (int j=0; j<randomLength; ++j){
      newString += fp.generateRandomNucleotide(probA, probC, probT, probG);
    }
    newFile << newString << endl;
  }
  newFile << ""  << endl;

  newFile.close();
  cout << "Finished file writing. " << endl;
  cout << "Current file finished processing." << endl;


  // cout << lengthSum << endl;
  //cout << lengthMean << endl;
  // cout << lengthVariance << endl;
  //cout << lengthSD << endl;
  // cout << totalNumA << endl;
  // cout << totalNumC << endl;
  // cout << totalNumT << endl;
  // cout << totalNumG << endl;
  // cout << "numAA" << numAA << endl;
  // cout << "numCA" << numCA << endl;
}

bool FileProcessor :: getFileContent(ifstream& file, string filename){

  file.open(filename);
  if(!file.is_open()){
    return false;
  }

  return true;
}

string FileProcessor :: extractNextString(ifstream& file){
  string currString;

  file >> currString;

  return currString;
}

bool FileProcessor :: fileEndReached(ifstream& file){
  if(file.eof()){
    return true;
  }
  return false;
}

void FileProcessor :: stringToUpperCase(string& myStr){
  for (int i=0; i<myStr.length(); ++i){
    myStr[i] = toupper(myStr[i]);
  }
}

void FileProcessor :: getNucleotides(string myStr, int& total, int& nA, int& nC, int& nT, int& nG){
  for(int a=0; a<myStr.length(); ++a){
    if(myStr[a] == 'A'){
      nA += 1;
    }
    if(myStr[a] == 'C'){
      nC += 1;
    }
    if(myStr[a] == 'T'){
      nT += 1;
    }
    if(myStr[a] == 'G'){
      nG += 1;
    }
    total+=1;
  }
}

void FileProcessor :: getBigram(string myStr, int& numB, int& bAA, int& bAC, int& bAT, int& bAG,
                                    int& bCA, int& bCC, int& bCT, int& bCG,
                                    int& bTA, int& bTC, int& bTT, int& bTG,
                                    int& bGA, int& bGC, int& bGT, int& bGG){
  char char1;
  char char2;
  int bigramCase = 0;
  for (int a=0; a<myStr.length(); ++a){
    char1 = myStr[a];
    if(a+1 < myStr.length()){
      char2 = myStr[a+1];
    }else{
      char2 = myStr[0];
    }

    switch(char1){
      case 'A':
        bigramCase = 10;
        break;
      case 'C':
        bigramCase = 20;
        break;
      case 'T':
        bigramCase = 30;
        break;
      case 'G':
        bigramCase = 40;
        break;
    }

    switch(char2){
      case 'A':
        bigramCase += 1;
        break;
      case 'C':
        bigramCase += 2;
        break;
      case 'T':
        bigramCase += 3;
        break;
      case 'G':
        bigramCase += 4;
        break;
    }

    switch(bigramCase){
      case 11:
        bAA += 1;
        break;
      case 12:
        bAC += 1;
        break;
      case 13:
        bAT += 1;
        break;
      case 14:
        bAG += 1;
        break;
      case 21:
        bCA += 1;
        break;
      case 22:
        bCC += 1;
        break;
      case 23:
        bCT += 1;
        break;
      case 24:
        bCG += 1;
        break;
      case 31:
        bTA += 1;
        break;
      case 32:
        bTC += 1;
        break;
      case 33:
        bTT += 1;
        break;
      case 34:
        bTG += 1;
        break;
      case 41:
        bGA += 1;
        break;
      case 42:
        bGC += 1;
        break;
      case 43:
        bGT += 1;
        break;
      case 44:
        bGG += 1;
        break;
    }

    numB += 1;
    bigramCase = 0;
    a += 1;
  }
}

void FileProcessor :: nucleotidesProb(int& numN, int& nA, int& nC, int& nT, int& nG, float& pA, float& pC, float& pT, float& pG){
  //cout<<"numA: " << nA << endl;
  //cout<<"numN: " << numN << endl;
  nA == 0 ? pA = 0 : pA = (float)nA/ (float)numN;
  nC == 0 ? pC = 0 : pC = (float)nC/ (float)numN;
  nT == 0 ? pT = 0 : pT = (float)nT/ (float)numN;
  nG == 0 ? pG = 0 : pG = (float)nG/ (float)numN;
  //cout<<"probA: " << pA << endl;
}

void FileProcessor :: bigramProb(int& numB, int& bAA, int& bAC, int& bAT, int& bAG,
                                    int& bCA, int& bCC, int& bCT, int& bCG,
                                    int& bTA, int& bTC, int& bTT, int& bTG,
                                    int& bGA, int& bGC, int& bGT, int& bGG,
                                    float& pAA, float& pAC, float& pAT, float& pAG,
                                    float& pCA, float& pCC, float& pCT, float& pCG,
                                    float& pTA, float& pTC, float& pTT, float& pTG,
                                    float& pGA, float& pGC, float& pGT, float& pGG){
  bAA == 0 ? pAA = 0 : pAA = (float)bAA/ (float)numB;
  bAC == 0 ? pAC = 0 : pAC = (float)bAC/ (float)numB;
  bAT == 0 ? pAT = 0 : pAT = (float)bAT/ (float)numB;
  bAG == 0 ? pAG = 0 : pAG = (float)bAG/ (float)numB;

  bCA == 0 ? pCA = 0 : pCA = (float)bCA/ (float)numB;
  bCC == 0 ? pCC = 0 : pCC = (float)bCC/ (float)numB;
  bCT == 0 ? pCT = 0 : pCT = (float)bCT/ (float)numB;
  bCG == 0 ? pCG = 0 : pCG = (float)bCG/ (float)numB;

  bTA == 0 ? pTA = 0 : pTA = (float)bTA/ (float)numB;
  bTC == 0 ? pTC = 0 : pTC = (float)bTC/ (float)numB;
  bTT == 0 ? pTT = 0 : pTT = (float)bTT/ (float)numB;
  bTG == 0 ? pTG = 0 : pTG = (float)bTG/ (float)numB;

  bGA == 0 ? pGA = 0 : pGA = (float)bGA/ (float)numB;
  bGC == 0 ? pGC = 0 : pGC = (float)bGC/ (float)numB;
  bGT == 0 ? pGT = 0 : pGT = (float)bGT/ (float)numB;
  bGG == 0 ? pGG = 0 : pGG = (float)bGG/ (float)numB;
}

int FileProcessor :: generateRandomLength(float fMean, float fSD){
  int rand(void);
  int length = 0;

  float randA = 0;
  float randB = 0;
  float boxMullerC = 0;

  randA = rand()/ (double)RAND_MAX;
  randB = rand()/ (double)RAND_MAX;
  boxMullerC = sqrt(-2* log(randA))* cos(2* M_PI* randB);

  length = boxMullerC* fSD + fMean;

  return length;
  //cout << boxMullerC << endl;
  //cout << length << endl;
}

char FileProcessor :: generateRandomNucleotide(float pA, float pC, float pT, float pG){
  int rand(void);
  float upBound = pA + pC + pT + pG;
  float randPoint = 0;

  randPoint = (rand()/ (double)RAND_MAX)* upBound;

  if(randPoint <= pA){
    return 'A';
  }else if(randPoint <= pA+pC){
    return 'C';
  }else if(randPoint <= pA+pC+pT){
    return 'T';
  }else{
    return 'G';
  }

  cout << "ERROR: generateRandomNucleotide failed. " << endl;
}











