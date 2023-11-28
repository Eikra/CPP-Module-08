/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:15:22 by iecharak          #+#    #+#             */
/*   Updated: 2023/11/28 21:17:03 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>

typename T::iterator    easyfind(T& container, int i)
{
    typename T::iterator it;
    
    it = std::find(container.begin(), container.end(), i);
    if (it != container.end())
        return (it);
    throw   
        std::out_of_range("Value not found in container");
}

#endif