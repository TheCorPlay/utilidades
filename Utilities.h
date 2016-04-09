/*
 *	External library: Utilities.h
 *	______________________________
 *
 *	By: Kramez
 *	E-Mail: thecorplay@gmail.com
 *	Current version: v0.0.1
 *	______________________________
 *	
 *	COPYRIGHT ©
 *
 *	This file has copyright assigned.
 *	It is free to use, but give credit used.
 * 	
 *	Example of minimum credits:
 *	Library Utilities.h made by Kramez
 *	you can find this and more done
 *	for him here:
 *
 *	https://github.com/TheCorPlay
 *	______________________________
 *	
 *	FUTURE UPDATES
 *	
 *	 +	Conversions of all possible
 *		standard types in both directions.
 *	 +	Various types of generic searches.
 *
*/
#ifndef _UTILITIES_H_
#define _UTILITIES_H

#include <string>
#include <iostream>

/// Given two integers (the base and the exponent) returns a to the power of b
long int u_exponents(int a, int b)
{
	if (b <= 0)
		return 1;
	else
		return a*u_exponents(a,b-1);
}

/// Given a string returns an integer ignoring any other character (CSTOI = Controlled string to int)
int u_cstoi (const std::string &text)
{
	unsigned int i = 0;
	bool positive = true;
	int sol = 0;
	
	while (positive && i < text.length() && (text[i] > 57 || text[i] < 48 || text[i] == '-')) {
		if (text[i] == '-')
			positive = false;
		i++;
	}
	
	while (i++ <= text.length())
		if (text [i-1] <= 57 && text [i-1] >= 48)
			sol = sol * 10 + text[i-1] - 48;
			
	if (!positive)
		sol = - sol;
	
	return sol;
}

/// Given a string returns an integer (STOI = String to int)
int u_stoi (const std::string &text)
{
	unsigned int i;
	bool positive = true;
	int sol = 0;
	
	i = (text[0] == '-');
	positive = !i;
	
	while (i++ < text.length())
			sol = sol * 10 + text[i-1] - 48;
	
	if (!positive)
		return - sol;
	
	return sol;
}

/// Given a string returns an unsigned integer ignoring any other character (STUI = Controlled string to unsigned int)
unsigned int u_stui (const std::string &text)
{
	unsigned int i = 0, sol = 0;

	while (i++ < text.length())
		if (text [i-1] <= 57 && text [i-1] >= 48)
			sol = sol * 10 + text[i-1] - 48;
	
	return sol;
}

/// Given a string and a char (that char means with what symbol start the decimal part) returns the equivalents double. (STOD = Controlled string to double)
double u_stod (const std::string &text, const char decimal)
{
	unsigned int i = 0, iaux;
	double sol = 0;
	bool positive = true;
	
	while (positive && i < text.length() && (text[i] > 57 || text[i] < 48 || text[i] == '-') && text[i-1] != decimal) {
		if (text[i] == '-')
			positive = false;
		i++;
	}
	
	while (i++ < text.length() && text[i-1] != decimal)
		if (text [i-1] <= 57 && text [i-1] >= 48)
			sol = sol * 10 + text[i-1] - 48;
	
	iaux = i;
	
	int dec = 0;
	while (i++ < text.length())
		if (text [i-1] <= 57 && text [i-1] >= 48)
			dec = dec * 10 + text[i-1] - 48;
		else
			iaux++;
	 
	sol = sol + (dec /(float) u_exponents(10,i - 1 - iaux));
	
	if (!positive)
		sol = - sol;
	
	return sol;
}

unsigned int u_words (const std::string &text, const char separator)
{
	unsigned int num = 0, i = 0;
	
	while (i++ <= text.length())
		if (text[i-1] == separator)
			num++;
			
	if (num != 0)
		num++;

	return num;
}

void u_split (std::string array[], std::string text, const unsigned int words, const char separator)
{
	unsigned int count = 0;
	std::size_t found;

	do {
		found = text.find(separator);
		array[count] = text.substr (0,found);
		text.erase(0, found+1);
		count++;		
	} while (found != std::string::npos && count < words);
}

unsigned int u_split (std::string array[], std::string text, const char separator)
{
	unsigned int count = 0;
	unsigned int words = u_words (text, separator);
	std::size_t found;

	do {
		found = text.find(separator);
		array[count] = text.substr (0,found);
		text.erase(0, found+1);
		count++;		
	} while (found != std::string::npos && count < words);
	
	return words;
}

/*int main ()
{
	std::string text = "256x256";
	unsigned int words = u_words (text, 'x');
	std::string array[words];
	
	u_split (array,text,words,'x');
	
	int op = 0;
	
	for (unsigned int i = 0; i < words; i++)
		op = op + u_cstoi (array[i]);
		
	std::cout << op << "\n";
	
	return 0;
}*/

#endif