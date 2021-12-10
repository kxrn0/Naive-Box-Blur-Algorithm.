#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<std::vector<int>> blur(const std::vector<std::vector<int>>& vImage, int nWidth) {
  std::vector<std::vector<int>> vBlurred;

  for (int y = 0; y < vImage.size(); y++) {
    std::vector<int> vRow;
    for (int x = 0; x < vImage[0].size(); x++) {
      int nAvg = 0;
      int nSize = nWidth / 2;

      for (int kx = -nSize; kx <= nSize; kx++)
        for (int ky = -nSize; ky <= nSize; ky++)
          if (0 <= x + kx && x + kx < vImage[0].size() && 0 <= y + ky && y + ky < vImage.size())
            nAvg += vImage[y + ky][x + kx];
      nAvg /= (nWidth * nWidth);
      vRow.push_back(nAvg);
    }
    vBlurred.push_back(vRow);
  }
  return vBlurred;
}

std::vector<std::vector<int>> create_image(int nWidth, int nHeight) {
  std::vector<std::vector<int>> vImage;

  for (int y = 0; y < nHeight; y++) {
    std::vector<int> vRow;

    for (int x = 0; x < nWidth; x++)
      vRow.push_back(rand() % 90 + 10);
    vImage.push_back(vRow);
  }
  return vImage;
}

void print_image(const std::vector<std::vector<int>>& vImage) {
    for (std::vector<int> v : vImage) {
      for (int n : v)
        std::cout << n << "  ";
      std::cout << '\n';
  }
}

int main() {
  srand(static_cast<unsigned>(time(0)));

  std::vector<std::vector<int>> vImage = create_image(25, 30);
  std::vector<std::vector<int>> vBlurred = blur(vImage, 7);

  print_image(vImage);
  std::cout << ".............................................................................\n";
  print_image(vBlurred);
} 
