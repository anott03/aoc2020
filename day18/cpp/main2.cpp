#include <vector>
#include <string>
#include <iostream>
#include "../../utils.cpp"

std::vector<std::string> input;

int evaluate(std::string exp) {
  while (exp.find("(") != -1) {
    int close_idx = (int) exp.find(")");
    int open_idx;
    for (int i = close_idx; i >= 0; --i) {
      if (exp[i] == '(') {
        open_idx = i;
        break;
      }
    }
    int sub_answer = evaluate(exp.substr(open_idx + 1, close_idx - open_idx - 1));
    exp = exp.substr(0, open_idx) + std::to_string(sub_answer) + exp.substr(close_idx+1);
  }

  std::vector<std::string> tokens = split(exp, " ");
  int result = std::stoi(tokens[0]);

  for (int i = 1; i < tokens.size() - 1; i += 2) {
    int num = std::stoi(tokens[i+1]);
    if (tokens[i] == "+") {
      result += num;
    } else if (tokens[i] == "*") {
      result *= num;
    }
  }

  return result;
}

void part1() {
  // final data
  int sum = 0;
  for (int i = 0; i < input.size(); ++i) {
    sum += evaluate(input[i]);
  }
  printf("PART 1 %d\n", sum);

  // test data
  // printf("%d\n", evaluate("1 + (2 * 3) + (4 * (5 + 6))"));
  // printf("%d\n", evaluate("2 * 3 + (4 * 5)"));
  // printf("%d\n", evaluate("5 + (8 * 3 + 9 + 3 * 4 * 3)"));
  // printf("%d\n", evaluate("5 * 9 * (7 * 3 * 3 + 9 * 3 + (8 + 6 * 4))"));
  // printf("%d\n", evaluate("((2 + 4 * 9) * (6 + 9 * 8 + 6) + 6) + 2 + 4 * 2"));
}

int main() {
  input = getInput("./input.prod");
  part1();
  return 0;
}

