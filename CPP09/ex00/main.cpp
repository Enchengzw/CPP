/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: encheng <encheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:46:00 by ezhou             #+#    #+#             */
/*   Updated: 2024/09/11 12:21:45 by encheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/BitcoinExchange.hpp"

void check_key(std::string key) {
	std::stringstream ss(key);
	std::string token;
	int year;
	int month;
	int day;
	char dash;

	std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);

	static int daysInMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	ss >> year >> dash >> month >> dash >> day;
	if (year % 4 == 0 && year % 100 != 0)
		daysInMonths[1] = 29;
	else if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0)
		daysInMonths[1] = 29;
	else
		daysInMonths[1] = 28;
	if (year > now->tm_year + 1900 || year < 2009)
		throw std::logic_error("Year outside boundaries");
	if (month > 12 || month < 1)
		throw std::logic_error("Month bigger than 12 or smaller than 1");
	if (year == (now->tm_year + 1900)) {
		if (month > (now->tm_mon))
			throw std::logic_error("Date Month is in the future");
		else {
			if (month == now->tm_mon && day > now->tm_mday)
				throw std::logic_error("Date Day is in the future");
		}
	}
	if (year == 2009 && (month < 1 || (month == 1 && day < 02)))
		throw std::logic_error("There's no data before 2009");
	if (day < 1 || day > daysInMonths[month - 1])
		throw std::logic_error("Date value is illegal");
}

int main(int argc, char *argv[])
{
	std::fstream	fs;
	std::string		line;
	BitcoinExchange	data;
	map map_data;

	(void)argc;
	(void)argv;
	fs.open("./data.csv", std::fstream::in);
	if (!fs.is_open()) {
		std::cerr << "Error: could not open database" << std::endl;
		return 1;
	}
	while (std::getline(fs, line)) {
		data.FillMap(line);
	}
	fs.close();
	fs.open(argv[1], std::fstream::in);
	if (!fs.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}
	map_data = data.GetMap();
	while (std::getline(fs, line))
	{
		std::stringstream	ss(line);
		std::string			key;
		float				value;

		if (line.find('|') == line.npos) {
			std::cerr << "Error: Bad input => " << line << std::endl;
			continue;
		}
		std::getline(ss, key, '|');
		if (key == "date ")
			continue;
		key.erase(key.end() - 1);
		ss >> value;
		try {
			check_key(key);
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << " on: " << key << std::endl;
			continue;
		}
		if (value > 1000)	{
			std::cerr << "Error: value is too large." << std::endl;
			continue;
		}
		if (value <= 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		std::cout << key << " => " << value << 	" = " << value * map_data[key] << std::endl;
	} 
	return 0;
}