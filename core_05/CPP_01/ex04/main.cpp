/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:41:20 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/24 10:55:26 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

// Function to replace all occurrences of s1 in str with s2
std::string replaceAll(std::string str, const std::string& s1, const std::string& s2) {
	size_t pos = 0;
	while ((pos = str.find(s1, pos)) != std::string::npos)
	{
		str.erase(pos, s1.length());
		str.insert(pos, s2);
		pos += s2.length();
	}
	return str;
}

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>\n";
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty())
	{
		std::cerr << "Error: The string to be replaced cannot be empty.\n";
		return 1;
	}

	std::ifstream inputFile(filename);
	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file: " << filename << std::endl;
		return 1;
	}

	std::stringstream buffer;
	buffer << inputFile.rdbuf();
	inputFile.close();

	std::string content = replaceAll(buffer.str(), s1, s2);

	std::string outputFilename = filename + ".replace";
	std::ofstream outputFile(outputFilename);
	if (!outputFile.is_open())
	{
		std::cerr << "Error creating file: " << outputFilename << std::endl;
		return 1;
	}

	outputFile << content;
	if (outputFile.fail())
	{
		std::cerr << "Error writing to file: " << outputFilename << std::endl;
		return 1;
	}
	outputFile.close();

	return 0;
}
