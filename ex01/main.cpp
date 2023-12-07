/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:47:11 by iecharak          #+#    #+#             */
/*   Updated: 2023/12/07 21:57:51 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
    try
    {   
        Span sp = Span(9);
        sp.addNumber(-1);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "longest Span: " << sp.longestSpan() << std::endl;

        std::cout << "\n--------------------------\n\n";
        
        // Adding numbers using a range of iterators
        std::vector<int> additionalNumbers;
        additionalNumbers.push_back(2);
        additionalNumbers.push_back(8);
        additionalNumbers.push_back(1);
        additionalNumbers.push_back(20);
        sp.addNumbers(additionalNumbers.begin() + 1, additionalNumbers.end());

        std::cout << "shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "longest Span: " << sp.longestSpan() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << "\n*************************\n\n";
    try
    {    
        // Test Case 1: Basic functionality with single numbers
        Span span1(8);
        span1.addNumber(10);
        span1.addNumber(5);
        span1.addNumber(20);
        std::cout << "shortest Span: " << span1.shortestSpan() << std::endl;
        std::cout << "longest Span: " << span1.longestSpan() << std::endl;

        std::cout << "\n--------------------------\n\n";
        
        // Test Case 2: Add a range of numbers using push_back
        std::vector<int> numbers;
        numbers.push_back(7);
        numbers.push_back(15);
        numbers.push_back(3);
        numbers.push_back(9);
        span1.addNumbers(numbers.begin(), numbers.end());
         std::cout << "shortest Span: " << span1.shortestSpan() << std::endl;
        std::cout << "longest Span: " << span1.longestSpan() << std::endl;

        std::cout << "All tests passed!" << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << "\n*************************\n\n";
    try
    {
        Span sp;
        int span = sp.shortestSpan();
        std::cout << "shortest Span: " << span << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
    
    return 0;
}