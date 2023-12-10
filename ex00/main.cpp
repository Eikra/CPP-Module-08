/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:42:58 by iecharak          #+#    #+#             */
/*   Updated: 2023/12/10 12:41:20 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    // Test with std::vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try
    {
        std::vector<int>::iterator result = easyfind(vec, 4);
        std::cout << "Value found in container " << *result << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << e.what() << std::endl;
    }

    // Test with std::list
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);

    try
    {
        std::list<int>::iterator result = easyfind(lst, 25);
        std::cout << "Value found in container " << *result << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
