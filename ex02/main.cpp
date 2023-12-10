/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:56:18 by iecharak          #+#    #+#             */
/*   Updated: 2023/12/10 12:40:29 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void    test()
{
    MutantStack<int> mutantStack;

    // Push some elements onto the stack
    for (int i = 1; i <= 5; ++i) {
        mutantStack.push(i);
    }

    // Use iterators to iterate through the stack and print its elements
    std::cout << "Stack elements (from top to bottom): ";
    for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Use reverse iterators to iterate through the stack in reverse order
    std::cout << "Stack elements in reverse (from bottom to top): ";
    for (MutantStack<int>::reverse_iterator rit = mutantStack.rbegin(); rit != mutantStack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;
}

int main()
{
   // test();
    {
        std::list<int> mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << "back: " << mstack.back() << std::endl;
        mstack.pop_back();
        std::cout << "Size after pop: " << mstack.size() << std::endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);
        std::cout << "Iterating using iterators (std::list):" << std::endl;
        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::list<int> s(mstack);
    }
    std::cout << "*******************************\n";
    {    
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "top: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "Size after pop: " << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        
        std::cout << "Iterating using iterators:" << std::endl;
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::stack<int> s(mstack);
    }
    return 0;
}