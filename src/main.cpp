#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

std::vector<std::string> readFile(std::string fileName) {
  std::ifstream infile;
  std::vector<std::string> vec;
  std::string word;

  infile.open(fileName);
  while (infile >> word) {
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
  // std::random_shuffle(wordList.begin(), wordList.end());
  int count = 1;
  std::cout << "Word list loaded, length is " << wordList.size() << std::endl;
  while(wordList.size()) {

    std::cout << "\n**** # " << count << ": " << wordList.size()
      << " left ****\n\n";

    if (1 != count) {
      std::string wFlag;
      std::cout << "Write current list to a file? (y/n)";
      getline(std::cin, wFlag);
      if ("y" == wFlag) {
        auto write = writeFile(wordList);
      }
      else {
        std::cout << "\n****Continue****\n\n";
      }
    }

    wordList = quizTime(wordList);
    count ++;
  }
  return 0;
}
