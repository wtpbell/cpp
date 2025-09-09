/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:51:46 by bewong            #+#    #+#             */
/*   Updated: 2025/09/09 14:23:10 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <vector>

#include "Serializer.hpp"

void printData(Data* data, const std::string& prefix = "")
{
	if (data)
	{
		std::cout << prefix << "Name: " << data->name << " | Age: " << data->age
					<< std::endl;
	}
	else
	{
		std::cout << prefix << "Null pointer!" << std::endl;
	}
}

// This is direct pointer to integer conversion
void testBasicSerialization()
{
	std::cout << "\n=== Basic Serialization Test ===" << std::endl;
	Data* person = new Data{"Alice", 30};
	printData(person, "Original: ");

	uintptr_t serialized = Serializer::serialize(person);
	std::cout << "Serialized value: " << serialized << std::endl;

	Data* deserialized = Serializer::deserialize(serialized);
	printData(deserialized, "Deserialized: ");

	delete person;
}

void testArraySerialization()
{
	std::cout << "\n=== Array Serialization Test ===" << std::endl;
	Data* people[3] = {new Data{"Bob", 25}, new Data{"Charlie", 35},
						new Data{"Diana", 28}};

	for (int i = 0; i < 3; ++i)
	{
		std::cout << "Original person " << i << ": ";
		printData(people[i], "");
	}
	
	// Serialize array of pointers
	uintptr_t serialized[3];
	for (int i = 0; i < 3; ++i)
	{
		serialized[i] = Serializer::serialize(people[i]);
		std::cout << "Serialized person " << i << ": " << serialized[i]
					<< std::endl;
	}


	for (int i = 0; i < 3; ++i)
	{
		Data* deserialized = Serializer::deserialize(serialized[i]);
		std::cout << "Deserialized person " << i << ": ";
		printData(deserialized, "");
	}

	for (int i = 0; i < 3; ++i)
		delete (people[i]);
}

// 
void testFileSerialization()
{
	std::cout << "\n=== File Serialization Test ===" << std::endl;

	// Create and serialize data
	Data* original = new Data{"Eve", 42};
	uintptr_t serialized = Serializer::serialize(original); // a number representing a memory address
	std::cout << "Serialized value: " << serialized << std::endl;
	// create an output file stream with file name and open the file in binary mode without translation
	std::ofstream outFile("serialized_data.bin", std::ios::binary);
	if (!outFile)
	{
		std::cerr << "Error creating file!" << std::endl;
		delete (original);
		return ;
	}

	// Write the serialized data (as bytes)
	outFile.write(reinterpret_cast<const char*>(&serialized), //tell compiler treat the memory at &serialized as a const char *
					sizeof(serialized));
	outFile.close();

	std::cout << "Data written to file. Now reading back..." << std::endl;

	// create an input file stream 
	std::ifstream inFile("serialized_data.bin", std::ios::binary);
	if (!inFile)
	{
		std::cerr << "Error opening file!" << std::endl;
		delete (original);
		return ;
	}

	uintptr_t fileData;
	inFile.read(reinterpret_cast<char*>(&fileData), sizeof(fileData));
	inFile.close();

	// Deserialize and display
	Data* fromFile = Serializer::deserialize(fileData);
	printData(fromFile, "Data from file: ");

	delete (original);
}

int main()
{
	testBasicSerialization();
	testArraySerialization();
	testFileSerialization();
	return (0);
}
