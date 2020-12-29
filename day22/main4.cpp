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

int calculateScore(std::vector<int> d) {
  int s = 0;

  for (int i = 0; i < d.size(); ++i) {
    s += d[i] * (d.size() - i);
  }

 return s;
}

std::vector<std::vector<int>> states;
int play(std::vector<int> d1, std::vector<int> d2) {
  if (std::find(states.begin(), states.end(), d1) != states.end() || std::find(states.begin(), states.end(), d2) != states.end()) {
    return 1;
  }
  int winner;
  int c1 = d1[0];
  int c2 = d2[0];
  d1.erase(d1.begin());
  d2.erase(d2.begin());

  if (d1.size() >= c1 && d2.size() >= c2) {
    // sub round
    std::vector<int> new_d1;
    std::vector<int> new_d2;

    for (int i = 0; i < c1; ++i) new_d1.emplace_back(d1[i]);
    for (int i = 0; i < c2; ++i) new_d2.emplace_back(d2[i]);
    // for (int i = 0; i < c1; ++i) printf("%d %d\n", d1[i], new_d1[i]);
    for (int i = 0; i < c2; ++i) printf("%d %d\n", d2[i], new_d2[i]);

    return play(new_d1, new_d2);
  } else {
    if (c1 > c2) {
      winner = 1;
      d1.emplace_back(c1);
      d1.emplace_back(c2);
    } else {
      winner = 2;
      d2.emplace_back(c2);
      d2.emplace_back(c1);
    }
  }

  if (d1.size() != 0 && d2.size() != 0) return play(d1, d2);

  return winner;
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

  int w = play(d1, d2);
  int s = calculateScore(w == 1 ? d1 : d2);
  printf("PART 2 %d\n", s);

  return 0;
}
