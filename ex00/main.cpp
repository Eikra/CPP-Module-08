/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:42:58 by iecharak          #+#    #+#             */
/*   Updated: 2023/11/26 13:26:48 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

void testOne()
{
    try {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);

        int value_to_find = 3;

        std::vector<int>::iterator result = easyfind(vec, value_to_find);

        std::cout << "Value found at index: " << std::distance(vec.begin(), result) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void    testTwo()
{
    try {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        int value_to_find = 0;

        std::vector<int>::iterator result = easyfind(vec, value_to_find);

        std::cout << "Value found at index: " << std::distance(vec.begin(), result) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main()
{
    testOne();
    testTwo();
}

// void testOne()
// {
//     try {
//         int arr[] = {1, 2, 3, 4, 5};
//         int value_to_find = 3;

//         int* result = ::easyfind(arr, value_to_find);

//         std::cout << "Value found at index: " << std::distance(arr, result) << std::endl;
//     } catch (const std::out_of_range& e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//     }

// }

// void    testTwo()
// {
//     try {
//         char str[] = "hello";
//         char* result_str = ::easyfind(str, 'e');

//         std::cout << "Character found in string at index: " << std::distance(str, result_str) << std::endl;
//     } catch (const std::out_of_range& e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//     }
// }