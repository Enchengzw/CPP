/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:04:38 by ezhou             #+#    #+#             */
/*   Updated: 2024/09/05 17:57:32 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <vector>
# include <cstddef>
# include <exception>
# include <algorithm>

typedef std::vector<int>::iterator IT;

class Span 
{	
	public:
		Span(unsigned int n);
		Span(const Span& other);
		~Span();

		Span& operator=(const Span& other);

		void addNumber(int n);
		void addRange(IT begin, IT end);

		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		std::size_t size() const;

        class FullException : public std::exception 
		{
			public: virtual const char* what() const throw();
		};

		class SmallException : public std::exception 
		{
			public: virtual const char* what() const throw();
		};
    
	private:
		Span();
		std::vector<int> _vector;
		std::size_t _size;
};

#endif