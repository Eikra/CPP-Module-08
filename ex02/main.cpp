/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:56:18 by iecharak          #+#    #+#             */
/*   Updated: 2023/12/07 21:09:04 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    // Test with MutantStack
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    // Iterating using iterators
    std::cout << "Iterating using iterators:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    // Test with std::list for comparison
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << "Top: " << lst.back() << std::endl;
    lst.pop_back();
    std::cout << "Size after pop: " << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);

    // Iterating using iterators
    std::cout << "Iterating using iterators (std::list):" << std::endl;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}
// int main() 

// {
//     std::cout << "here\n";
//     MutantStack<int, std::deque<int> > mstack;
//     mstack.push(5);
//     mstack.push(17);

//     MutantStack<int, std::deque<int> > mstack_copy(mstack);

//     MutantStack<int, std::deque<int> >::reverse_iterator rit = mstack_copy.rbegin();
//     MutantStack<int, std::deque<int> >::reverse_iterator rend = mstack_copy.rend();
//     while (rit != rend) {
//         std::cout << *rit << std::endl;
//         ++rit;std::cout << "here";
//     }

//     // Assignment
//     MutantStack<int, std::deque<int> > mstack_assign;
//     mstack_assign = mstack_copy;
    
//     return 0;
// }