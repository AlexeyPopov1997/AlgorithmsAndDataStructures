#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using Segment = std::pair<int, int>;

// Comprator
bool sortBySecondValue(const std::pair<int,int> &firstElement, const std::pair<int,int> &secondElement) {
    return (firstElement.second < secondElement.second);
}

// Points Covering
std::vector <int> getCoveringSet(std::vector <Segment> segments) {
  std::vector <int> points;

  std::sort(segments.begin(), segments.end(), sortBySecondValue);

  for (auto segment : segments) {
    if (points.empty() or (segment.first > points.back())) {
      points.push_back(segment.second);
    }
  }

  return points;
}

int main(void) {
  int segmentsCount;
  std::cin >> segmentsCount;
  std::vector <Segment> segments(segmentsCount);
  for (auto &segment:segments) {
    std::cin >> segment.first >> segment.second;
  }

  auto points = getCoveringSet(std::move(segments));
  std::cout << points.size() << std::endl;
  for (auto point:points) {
    std::cout << point << '\t';
  }
  std::cout << std::endl;
}