/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:34:05 by ezhou             #+#    #+#             */
/*   Updated: 2024/09/10 13:18:29 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _data(){
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src) {
	if (this != &src)
		_data = src._data;
	return *this;
}

std::map<std::string, float>::size_type BitcoinExchange::_data_size() const {
	return _data.size();
}

map BitcoinExchange::GetMap() const {
	return _data;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src): _data(src._data) {
}

void BitcoinExchange::Append(std::string key, float value) {
	std::pair<map::iterator, bool> ret;
	ret = _data.insert(std::make_pair(key, value));
	if (ret.second == false) {
		std::cout << "Changing rate for " << ret.first->first << std::endl;
		_data[key] = value;
	}
}

void BitcoinExchange::FillMap(std::string line) {
	std::stringstream	ss(line);
	std::string			key;
	float				value;

	if (!(line.find(',') == line.npos))
	{
		std::getline(ss, key, ',');
		if (key == "date")
			return ;
		ss >> value;
	}
	else {
		std::cerr << "Error: Bad input" << std::endl;
		return ;
	}
	Append(key, value);
}