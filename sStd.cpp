/**
 * @file sStd.cpp
 * @author silvio3105 (www.github.com/silvio3105)
 * @brief sStd source file.
 * @version v1.0
 * @date 2022-10-29
 * 
 * @copyright Copyright (c) 2022, silvio3105
 * 
 */

/*
Copyright (c) 2022, silvio3105 (www.github.com/silvio3105)

Access and use of this Project and its contents are granted free of charge to any Person.
The Person is allowed to copy, modify and use The Project and its contents only for non-commercial use.
Commercial use of this Project and its contents is prohibited.
Modifying this License and/or sublicensing is prohibited.

THE PROJECT AND ITS CONTENT ARE PROVIDED "AS IS" WITH ALL FAULTS AND WITHOUT EXPRESSED OR IMPLIED WARRANTY.
THE AUTHOR KEEPS ALL RIGHTS TO CHANGE OR REMOVE THE CONTENTS OF THIS PROJECT WITHOUT PREVIOUS NOTICE.
THE AUTHOR IS NOT RESPONSIBLE FOR DAMAGE OF ANY KIND OR LIABILITY CAUSED BY USING THE CONTENTS OF THIS PROJECT.

This License shall be included in all functional textual files.
*/


// ----- INCLUDE FILES
#include            <sStd.h>


// ----- CLASSES
// DATA CLASS
template<typename T>
sStd::Data<T>::Data(void)
{
	// Set to default values
	dataAddr = nullptr;
	length = 0;
}

template<typename T>
sStd::Data<T>::~Data(void)
{
	// Set to default values
	dataAddr = nullptr;
	length = 0;
}

template<typename T>
inline T* sStd::Data<T>::get(void) const
{
	// Return address of the first byte
	return dataAddr;
}

template<typename T>
void sStd::Data<T>::set(T* newData, uint16_t newLen)
{
	// Set new data pointer and length
	dataAddr = newData;
	length = newLen;
}

template<typename T>
inline uint16_t sStd::Data<T>::len(void) const
{
	// Return length of data
	return length;
}


// ----- FUNCTIONS DEFINITIONS
// MATH FUNCTIONS
template<typename T>
T scale(T in, T inMin, T inMax, T outMin, T outMax)
{
	return _sSTD_SCALE(in, inMin, inMax, outMin, outMax);
}

template<typename T>
T min2(T in1, T in2)
{
	return _sSTD_MIN2(in1, in2);
}

template<typename T>
T max2(T in1, T in2)
{
	return _sSTD_MAX2(in1, in2);
}

template<typename T>
T min3(T in1, T in2, T in3)
{
	return _sSTD_MIN3(in1, in2, in3);
}

template<typename T>
T max3(T in1, T in2, T in3)
{
	return _sSTD_MAX3(in1, in2, in3);
}


// STRING MANIPULATION FUNCTIONS DEFINITIONS
char* sStd::tok(char* input, char separator)
{
	// Move pointer until separator is found or end of C-string is reached
	while (*input != '\0' && *input != separator) input++;

	// If NULL character is found, return nullptr
	if (!*input) return nullptr;

	// Place NULL char over separator
	*input = '\0';

	// Move pointer to next character
	input++;

	// Return nullptr if character is NULL overwise return address of next character
	if (!*input) return nullptr;
		else return input;
}

uint16_t sStd::len(char* input, char endChar = '\0')
{
	// Copy string address to local variable
	char* tmp = input;

	// Move pointer until endChar is found
	while (*tmp != endChar) tmp++;

	// Return length of string.
	return tmp - input;
}


// STRING SCAN FUNCTIONS DEFINITIONS



// ----- FUNCTION DEFINITIONS
