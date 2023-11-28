/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:56:18 by iecharak          #+#    #+#             */
/*   Updated: 2023/11/28 22:02:56 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
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