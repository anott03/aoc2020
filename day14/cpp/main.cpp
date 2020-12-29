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

std::string parseMask(std::string line) {
  return line.substr(7);
}

std::string base10toBinary(unsigned int convertFrom) {
    std::string answer;

    while (convertFrom != 0){
        int digit = convertFrom % 2;

        char stringDigit;
        if (digit < 10) {
            stringDigit = '0' + digit;
        } else {
            stringDigit = digit - 10 + 'A';
        }
        answer.insert(answer.begin(), stringDigit);
        convertFrom /= 2;                
    }
    return answer;
}

std::string applyMask(std::string line, std::string mask) {
  std::string val = line.substr(line.find("=") + 1);
  val = base10toBinary(std::stoi(val));
  val.insert(val.begin(), 36-val.length(), '0');

  for (int i = 0; i < val.length(); i++) {
    if (mask.at(i) != 'X') {
      val[i] = mask.at(i);
    }
  }

  // printf("%s\n", mask.c_str());
  // printf("%s\n", val.c_str());

  return val;
}

int main() {
  input = getInput();
  std::string mask;
  std::map<int, int> mem;

  for (int i = 0; i < input.size(); ++i) {
    if (input[i].substr(0, 4) == "mask") {
      mask = parseMask(input[i]);
      continue;
    }
    int val = (int) std::stol(applyMask(input[i], mask), 0, 2);
    // printf("%lu\n", val);
    int address = std::stoi(input[i].substr(input[i].find("[") + 1,
        input[i].find("]") - input[i].find("[") - 1));
    // printf("%d\n", address);
    mem[address] = val;
  }

  long int sum = 0;
  std::map<int, int>::iterator i = mem.begin();
  while (i != mem.end()) {
    sum += i->second;
    i++;
  }

  printf("PART 1 %ld\n", sum);

  return 0;
}
