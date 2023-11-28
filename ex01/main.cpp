
#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
#include <algorithm>

class Span {
private:
    std::vector<int> numbers;
    unsigned int maxSize;

public:
    Span(unsigned int N) : maxSize(N) {}

    void addNumber(int num) {
        if (numbers.size() >= maxSize) {
            throw std::out_of_range("Span is already full");
        }
        numbers.push_back(num);
    }

    void addNumbers(const std::vector<int>& nums) {
        if (numbers.size() + nums.size() > maxSize) {
            throw std::out_of_range("Adding these numbers will exceed the maximum size of Span");
        }
        numbers.insert(numbers.end(), nums.begin(), nums.end());
    }

    int shortestSpan() {
        if (numbers.size() <= 1) {
            throw std::logic_error("Not enough numbers to find a span");
        }

        std::sort(numbers.begin(), numbers.end());
        int minSpan = std::numeric_limits<int>::max();

        for (std::vector<int>::iterator it = std::next(numbers.begin()); it != numbers.end(); ++it) {
            int span = *it - *(std::prev(it));
            if (span < minSpan) {
                minSpan = span;
            }
        }

        return minSpan;
    }

    int longestSpan() {
        if (numbers.size() <= 1) {
            throw std::logic_error("Not enough numbers to find a span");
        }

        std::pair<std::vector<int>::iterator, std::vector<int>::iterator> minMax =
            std::minmax_element(numbers.begin(), numbers.end());

        return *(minMax.second) - *(minMax.first);
    }
};

int main() {
    try
    {   
        Span sp = Span(9);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        // Adding numbers using a range of iterators
        std::vector<int> additionalNumbers;
        additionalNumbers.push_back(2);
        additionalNumbers.push_back(8);
        additionalNumbers.push_back(1);
        additionalNumbers.push_back(20);
        sp.addNumbers(additionalNumbers);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    return 0;
}