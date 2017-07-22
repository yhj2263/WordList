#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

class Word {
public:
  std::string _en;
  std::string _ch;
  Word(std::string en, std::string ch){_en = en; _ch = ch;}
};

std::vector<Word> readFile(std::string fileName) {
  std::ifstream infile;
  std::vector<Word> vec;
  std::string en;
  std::string ch;

  infile.open(fileName);
  while ((infile >> en) && (infile >> ch)) {
    Word word = Word(en, ch);
    vec.push_back(word);
  }
  infile.close();
  return vec;
}

std::vector<std::string> quizTime(std::vector<std::string> wordList) {
  std::string input;
  std::vector<std::string> vec;
  for (auto word : wordList) {
    std::cout << word << "\n";
    getline(std::cin, input);
    if ("" == input) {

    }
    else {
      vec.push_back(word);
    }
  }
  return vec;
}

int writeFile(std::vector<std::string> wordList) {
  std::ofstream outfile;
  std::string fileName;
  int count = 0;

  std::cout << "Name of the output file: ";
  getline(std::cin, fileName);
  outfile.open(fileName);

  for (auto word : wordList) {
    outfile << word << "\n";
    count++;
  }
  outfile.close();
  std::cout << count << " words successfully saved to " << fileName << "\n";
  return 0;
}

int main(int argc, char *argv[]) {
  std::string fileName = argv[1];
  auto wordList = readFile(fileName);

  int count = 1;
  std::string dummy;

  std::cout << "Word list loaded, length is " << wordList.size() << std::endl;
  while(wordList.size()) {
    std::random_shuffle(wordList.begin(), wordList.end());
    std::cout << "\n**** # " << count << ": " << wordList.size()
      << " left ****\n\n";

  /*  if (1 != count) {
      std::string wFlag;
      std::cout << "Write current list to a file? (y/n)";
      getline(std::cin, wFlag);
      if ("y" == wFlag) {
        auto write = writeFile(wordList);
      }
      else {
        std::cout << "\n****Continue****\n\n";
      }
    }*/

    for (auto word : wordList) {
      int wordNum = 1;
      if (!(wordNum % 50)) {
        std::cout << "**** " << wordNum << " ****\n";
      }
      std::cout << word._en;
      getline(std::cin, dummy);
      std::cout << word._ch << "\n\n";
      wordNum++;
    }
    count ++;
  }
  return 0;
}
