#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <inttypes.h>
#include <map>
#include <math.h>
#include "../utils.cpp"

std::vector<std::string> input;

std::vector<std::string> getInput() {
    std::vector<std::string> input;
    std::ifstream infile("./input");
    std::string val;

    while (getline(infile, val)) {
        input.emplace_back(val);
    }

    return input;
}

int transform(int subj, int loopSize) {
  return modpow(subj, loopSize, 20201227);
}

int main() {
  input = getInput();

  int cardKey = std::stoi(input[0]);
  int doorKey = std::stoi(input[1]);

  int cardLoopSize = 0;
  while (transform(7, cardLoopSize) != cardKey) {
    ++cardLoopSize;
  }

  printf("PART 1 %d\n", transform(doorKey, cardLoopSize));

  return 0;
}
