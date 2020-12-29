#include <vector>
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>

std::vector<std::string> getInput(std::string filename) {
    std::vector<std::string> input;
    std::ifstream infile(filename);
    std::string val;

    while (getline(infile, val)) {
        input.emplace_back(val);
    }

    return input;
}

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

std::vector<std::string> split(std::string s, std::string d) {
  size_t pos = 0;
  std::string token;
  std::vector<std::string> result = {};
  while ((pos = s.find(d)) != std::string::npos) {
      token = s.substr(0, pos);
      result.push_back(token);
      s.erase(0, pos + d.length());
  }
  result.push_back(s);
  return result;
}

// modpow code from https://stackoverflow.com/questions/8496182/calculating-powa-b-mod-n
// and then slightly modified
long int modpow(long int base, long int exp, long int modulus) {
  base %= modulus;
  long int result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

