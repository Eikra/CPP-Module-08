/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:14:09 by iecharak          #+#    #+#             */
/*   Updated: 2023/11/28 20:37:05 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
#include <algorithm>

class Span {
private:
    std::vector<int> numbers;
    unsigned int maxSize;
    Span() : maxSize(0){}

public:
    // Constructor
    Span(unsigned int N) : maxSize(N) {}

    // Copy constructor
    Span(const Span& other) : numbers(other.numbers), maxSize(other.maxSize) {}

    // Copy assignment operator
    Span& operator=(const Span& other) {
        if (this != &other) {
            numbers = other.numbers;
            maxSize = other.maxSize;
        }
        return *this;
    }

    // Destructor
    ~Span() {}

    // Member functions
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

        std::vector<int> tmp = numbers;
        std::sort(tmp.begin(), tmp.end());
        int minSpan = std::numeric_limits<int>::max();

        for (std::vector<int>::iterator it = std::next(tmp.begin()); it != tmp.end(); ++it) {
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

#endif