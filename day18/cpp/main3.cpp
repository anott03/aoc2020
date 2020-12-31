#include <vector>
#include <string>
#include "../../utils.cpp"

std::vector<std::string> input;

int evaluate(std::string exp) {
  std::vector<std::string> tokens = split(exp, ' ');
  int result = std::stoi(tokens[0]);
  for (int i = 1; i < tokens.size(); i += 2) {
    if (tokens[i] == "+") result += std::stoi(tokens[i + 1]);
    else result *= std::stoi(tokens[i+1]);
  }
  return result;
}

int solve(std::vector<std::string> tokens) {
  int result = 0;
  std::string op = "!";
  for (int i = 0; i < tokens.size(); ++i) {
    std::string token = tokens[i];
    if (std::string("*+").find(token) != -1) op = token;
    else if (token == ")") break;
    else if (token == "(") {
      // recurse
      auto start = tokens.begin() + i; 
      auto end = tokens.end(); 
      std::vector<std::string> result(tokens.size() - i + 1); 
      copy(start, end, result.begin());
      solve(result);
    } else {
      printf("%s\n", token.c_str());
      if (op == "!") result = std::stoi(token);
      else {
        if (op == "*") result *= std::stoi(token);
        else result += std::stoi(token);
      }
    }
  }
  return result;
}

int main() {
  input = getInput("./input.test");
  for (auto line : input) printf("%s\n", line.c_str());
  solve(split(input[0], ' '));
  return 0;
}
