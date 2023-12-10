/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:14:09 by iecharak          #+#    #+#             */
/*   Updated: 2023/12/10 11:12:18 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <limits>
#include <stdexcept>

class Span
{
    private:
        std::vector<int> arr;
        unsigned int maxIntegers;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span &src);
        Span &operator=(const Span &src);
        ~Span();

        void addNumber(int i);
        unsigned int shortestSpan();
        unsigned int longestSpan();

        template <class T>
        void addNumbers(T first, T last)
        {
            if (arr.size() == maxIntegers)
                throw std::out_of_range("Span is already full");

            unsigned int rangeSize = 0;
            T tmpIterator = first;
            while (tmpIterator != last)
            {
                rangeSize++;
                tmpIterator++;
            }

            if ((arr.size() + rangeSize) <= maxIntegers)
            {
                for (T it = first; it != last; ++it)
                    addNumber(*it);
            }
            else
                throw std::out_of_range("Filling your Span using this range of iterators will exceed its capacity");
        }
};

#endif