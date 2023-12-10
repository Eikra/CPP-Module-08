/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:34:05 by iecharak          #+#    #+#             */
/*   Updated: 2023/12/10 12:26:12 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : maxIntegers(0) {}

Span::Span(unsigned int n) : maxIntegers(n) {}

Span::Span(const Span &src) : maxIntegers(src.maxIntegers)
{
    this->arr = src.arr;
}

Span &Span::operator=(const Span &src)
{
    if (this != &src)
    {
        this->maxIntegers = src.maxIntegers;
        this->arr = src.arr;
    }
    return *this;
}

Span::~Span()
{
    arr.clear();
}

void Span::addNumber(int i)
{
    if (arr.size() < maxIntegers)
        arr.push_back(i);
    else
        throw std::out_of_range("Span is already full");
}

unsigned int Span::shortestSpan()
{
    if (arr.size() <= 1)
        throw std::logic_error("Not enough numbers to find a span");

    std::vector<int> tmp = arr;
    std::sort(tmp.begin(), tmp.end());
    
    int minSpan = std::numeric_limits<int>::max();
    for (std::vector<int>::iterator it = std::next(tmp.begin()); it != tmp.end(); ++it)
    {
        int tmpSpan = *(it) - *(std::prev(it));
        if (minSpan > tmpSpan)
            minSpan = tmpSpan;
    }
    return minSpan;
}

unsigned int Span::longestSpan()
{
    if (arr.size() <= 1)
        throw std::logic_error("Not enough numbers to find a span");

    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> tmpPair;
    tmpPair = std::minmax_element(arr.begin(), arr.end());
    return *(tmpPair.second) - *(tmpPair.first);
}

// template <class ForwardIterator>
// void Span::addNumbers(ForwardIterator first, ForwardIterator last)
// {
//     if (arr.size() == maxIntegers)
//         throw std::out_of_range("Span is already full");

//     unsigned int rangeSize = 0;
//     ForwardIterator tmpIterator = first;
//     while (tmpIterator != last)
//     {
//         rangeSize++;
//         tmpIterator++;
//     }

//     if ((arr.size() + rangeSize) < maxIntegers)
//     {
//         for (ForwardIterator it = first; it != last; ++it)
//             arr.push_back(*it);
//     }
//     else
//         throw std::out_of_range("Filling your Span using this range of iterators will exceed its capacity");
// }