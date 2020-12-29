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
std::vector<std::vector<int>> states = {};
std::vector<int> scores;

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

int move() {
  printf("move\n");

  int winner = 0;

  if (std::find(states.begin(), states.end(), d1) != states.end() ||
      std::find(states.begin(), states.end(), d2) != states.end()) {
    printf("match\n");
    return 1;
  }

  if (std::find(scores.begin(), scores.end(), calculateScore(d1)) != scores.end() ||
      std::find(scores.begin(), scores.end(), calculateScore(d2)) != scores.end()) {
    printf("match\n");
    return 1;
  }

  int p1 = d1[0];
  int p2 = d2[0];

  d1.erase(d1.begin());
  d2.erase(d2.begin());

  if (d1.size() >= p1 && d2.size() >= p2) {
    printf("recurse\n");
    winner = move();
  } else {
    if (p1 > p2) winner = 1;
    else winner = 2;
  }

  states.emplace_back(d1);
  states.emplace_back(d2);

  scores.emplace_back(calculateScore(d1));
  scores.emplace_back(calculateScore(d2));

  if (winner == 1) {
    d1.emplace_back(p1);
    d1.emplace_back(p2);
  } else if (winner == 2) {
    d2.emplace_back(p2);
    d2.emplace_back(p1);
  }
  return winner;
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

  int w = move();
  if (w == 1) win(d1);
  else win(d2);
  return 0;
}
