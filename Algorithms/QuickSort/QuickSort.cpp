#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <iostream>


using Line = std::pair<int, int>;


int main() {
    unsigned linesCount, poinsCount;
    std::cin >> linesCount >> poinsCount;

    std::vector<Line> lines(linesCount);
    for (Line &line : lines) {
        std::cin >> line.first >> line.second;
    }

    std::vector<int> points(poinsCount);
    std::vector<unsigned> counts(poinsCount);
    for (int &point : points) {
        std::cin >> point;
    }

    std::sort(lines.begin(), lines.end());

    std::vector<unsigned> pointsIndexes(poinsCount);
    std::iota(pointsIndexes.begin(), pointsIndexes.end(), 0u);
    std::sort(pointsIndexes.begin(), pointsIndexes.end(), [&](unsigned left, unsigned right) { return points[left] < points[right]; });

    auto sortedByEnds = [](const Line *lhs, const Line *rhs) { return lhs->second < rhs->second; };
    std::multiset<const Line *, decltype(sortedByEnds)> activeLines(sortedByEnds);

    auto lineIter = lines.begin();
    for (unsigned pointIndex : pointsIndexes) {
        int point = points[pointIndex];

        while (!activeLines.empty() && (*activeLines.begin())->second < point) {
            activeLines.erase(activeLines.begin());
        }

        for (; lineIter != lines.end() && lineIter->first <= point; ++lineIter) {
            if (lineIter->second >= point) {
                activeLines.insert(&*lineIter);
            }
        }

        counts[pointIndex] = activeLines.size();
    }

    for (unsigned count : counts) {
        std::cout << count << " ";
    }
    std::cout << std::endl;
}