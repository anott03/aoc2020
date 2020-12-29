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

struct State {
  int w;
  std::vector<int> d1;
  std::vector<int> d2;
};

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

State playRound(std::vector<int> d1, std::vector<int> d2) {
  int winner;
  std::vector<std::vector<int>> states;
  states.emplace_back(d1);
  states.emplace_back(d2);

  while (d1.size() != 0 && d2.size() != 0) {
    states.emplace_back(d1);
    states.emplace_back(d2);

    int c1 = d1[0];
    int c2 = d2[0];
    d1.erase(d1.begin());
    d2.erase(d2.begin());

    if (d1.size() >= c1 && d2.size() >= c2) {
      std::vector<int> new_d1;
      std::vector<int> new_d2;
      for (int i = 0; i < c1; ++i) new_d1.emplace_back(d1[i]);
      for (int i = 0; i < c2; ++i) new_d2.emplace_back(d2[i]);
      winner = playRound(new_d1, new_d2).w;
    } else {
      winner = c1 > c2 ? 1 : 2;
    }

    if (winner == 1) {
      d1.emplace_back(c1);
      d1.emplace_back(c2);
    } else {
      d2.emplace_back(c2);
      d2.emplace_back(c1);
    }

    if (std::find(states.begin(), states.end(), d1) != states.end() || std::find(states.begin(), states.end(), d2) != states.end()) {
      State s; s.w = 1; s.d1 = d1; s.d2 = d2;
      return s;
    }

    // for (int i = 0; i < states.size(); ++i) {
      // if (states[i] == d1 || states[i] == d2) {
        // printf("IDENTICAL STATES FOUND\n");
        // for (int j = 0; j < states[i].size(); ++j) {
          // printf("%d %d %d\n", states[i][j], d1[j], d2[j]);
        // }
        // State s; s.w = 1; s.d1 = d1; s.d2 = d2;
        // return s;
      // }
    // }
  }

  State s; s.w = winner; s.d1 = d1; s.d2 = d2;
  return s;
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

  State _s = playRound(d1, d2);
  int s = calculateScore(_s.w == 1 ? _s.d1 : _s.d2);
  printf("PART 2 %d\n", s);

  return 0;
}
