/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:33:11 by ezhou             #+#    #+#             */
/*   Updated: 2024/09/10 13:18:40 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <iomanip>
# include <iostream>
# include <fstream>
# include <exception>
# include <cstdlib>
# include <ctime>

typedef std::map<std::string, float> map;

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange& src);
		~BitcoinExchange();

		map GetMap() const;
		map::size_type _data_size() const;

		struct Date FillDates(std::string key);
		void Append(std::string key, float value);
		void FillMap(std::string line);

		struct Date {
			std::string year;
			std::string month;
			std::string day;
		};

    private:
		map _data;
};

#endif