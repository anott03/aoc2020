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
std::vector<std::vector<int>> states;

std::vector<std::string> getInput() {
    std::vector<std::string> input;
    std::ifstream infile("./input.prod");
    std::string val;

    while (getline(infile, val)) {
        input.emplace_back(val);
    }

    return input;
}

int calculateScore(std::vector<int> d) {
  int s = 0;

  for (int i = 0; i < d.size(); ++i) {
    s += d[i] * (d.size() - i);
  }

 return s;
}

void win(std::vector<int> d) {
  int score = calculateScore(d);
  printf("PART 2 %d\n", score);
}

int move(std::vector<int> d1, std::vector<int> d2) {
  if (std::find(states.begin(), states.end(), d1) != states.end() ||
      std::find(states.begin(), states.end(), d2) != states.end()) {
    printf("match\n");
    return 1;
  }

  states.emplace_back(d1);
  states.emplace_back(d2);

  int p1 = d1[0];
  int p2 = d2[0];
  d1.erase(d1.begin());
  d2.erase(d2.begin());

  if (d1.size() >= p1 && d2.size() >= p2) {
    return move(d1, d2);
  } else {
    if (d1.size() != 0 && d2.size() != 0) {
      if (p1 > p2) {
        d1.emplace_back(p1);
        d1.emplace_back(p2);
      } else {
        d2.emplace_back(p2);
        d2.emplace_back(p1);
      }
      return move(d1, d2);
    }
    if (p1 > p2) return 1;
    else return 2;
  }

  return -1;
}

int main() {
  input = getInput();

  std::vector<int> d1;
  std::vector<int> d2;
  
  for (int i = 1; i < input.size(); ++i) {
    if (input[i] == "" || input[i].at(0) == 'P') continue;
    if (i < input.size()/2) {
      d1.emplace_back(std::stoi(input[i]));
      continue;
    }
    d2.emplace_back(std::stoi(input[i]));
  }

  int w = move(d1, d2);
  if (w == 1) win(d1);
  else if (w == 2) win(d2);
  else printf("error\n");

  // printf("%d %d\n", calculateScore(d1), calculateScore(d2));

  return 0;
}
