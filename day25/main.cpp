#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <inttypes.h>
#include <map>

std::vector<std::string> input;

std::vector<std::string> getInput() {
    std::vector<std::string> input;
    std::ifstream infile("./input.prod");
    std::string val;

    while (getline(infile, val)) {
        input.emplace_back(val);
    }

    return input;
}

int determineLoopSize(std::string key) {
  int i = 0;
  while () {

  }
  return i;
}

int main() {
  input = getInput();

  std::string cardKey = input[0];
  std::string doorKey = input[1];



  return 0;
}
