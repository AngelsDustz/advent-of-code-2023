#include <fstream>
#include <iostream>
#include <map>

auto main() -> int {
  std::fstream stream;
  int sum = 0;
  stream.open("input.txt");

  if (!stream.is_open()) {
    perror("Failed to open `input.txt` check you have permissions and the file exists.");
    return 1;
  }

  while (!stream.eof()) {
    std::string line;
    int firstNumber = 0;
    int lastNumber = 0;
    
    std::getline(stream, line);

    for (auto c : line) {
      // Lovely ascii magic.
      if (c >= 48 && c <= 57) {
        lastNumber = (c-48);

        if (firstNumber == 0) {
          firstNumber = (c-48);
        }
      }

    }

    sum += (firstNumber*10)+lastNumber;
  }

  std::cout << "Total is: " << sum << std::endl;

  return 0;
}
