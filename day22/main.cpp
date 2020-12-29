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
std::vector<int> d1;
std::vector<int> d2;

std::vector<std::string> getInput() {
    std::vector<std::string> input;
    std::ifstream infile("./input.prod");
    std::string val;

    while (getline(infile, val)) {
        input.emplace_back(val); }

    return input;
}

int calculateScore(std::vector<int> d) {
  int s = 0;

  for (int i = 0; i < d.size(); ++i) {
    s += d[i] * (d.size() - i);
  }

 return s;
}

int main() {
  input = getInput();

  for (int i = 1; i < input.size(); ++i) {
    if (input[i] == "" || input[i].at(0) == 'P') continue;
    if (i < input.size()/2) {
      d1.emplace_back(std::stoi(input[i]));
      continue;
    }
    d2.emplace_back(std::stoi(input[i]));
  }

  while (d1.size() != 0 && d2.size() != 0) {
    int p1 = d1[0];
    int p2 = d2[0];

    if (p1 > p2) {
      d1.emplace_back(p1);
      d1.emplace_back(p2);
    } else {
      d2.emplace_back(p2);
      d2.emplace_back(p1);
    }

    d1.erase(d1.begin());
    d2.erase(d2.begin());
  }
  int score;
  if (d1.size() == 0) score = calculateScore(d2);
  else score = calculateScore(d1);

  printf("PART 1 %d\n", score);
  return 0;
}
