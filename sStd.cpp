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
	return SSTD_SCALE(in, inMin, inMax, outMin, outMax);
}

template<typename T>
T min2(T in1, T in2)
{
	return SSTD_MIN2(in1, in2);
}

template<typename T>
T max2(T in1, T in2)
{
	return SSTD_MAX2(in1, in2);
}

template<typename T>
T min3(T in1, T in2, T in3)
{
	return SSTD_MIN3(in1, in2, in3);
}

template<typename T>
T max3(T in1, T in2, T in3)
{
	return SSTD_MAX3(in1, in2, in3);
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

uint16_t sStd::len(char* input, char endChar)
{
	// Copy string address to local variable
	char* tmp = input;

	// Move pointer until endChar is found
	while (*tmp != endChar) tmp++;

	// Return length of string.
	return tmp - input;
}

uint16_t sStd::count(char* input, char character, char endChar)
{
	uint16_t count = 0;

	// If selected character is not equal to end character
	while (*input != endChar)
	{
		// If selected character is equal to wanted character, increas counter
		if (*input == character) count++;

		// Move to next character	
		input++;
	}

	// Return number of character in input C-string
	return count;
}

uint8_t sStd::cmp(char* input1, char* input2, char endChar)
{
	// While both characters are not equal to endChar
	while (*input1 != endChar)
	{
		// If characters are not equal return SSTD_NOK
		if (*input1 != *input2) return SSTD_NOK;
		
		// Move to next character
		input1++;
		input2++;
	}

	// Return SSTD_NOK if strings do not end with same character. This is input C-string length check
	if (*input1 != *input2) return SSTD_NOK;

	// Return equal status
	return SSTD_OK;
}


// STRING SCAN FUNCTIONS DEFINITIONS
uint8_t sStd::sscan(char* input, char sepBegin, uint8_t sepCntBegin, char sepEnd, uint8_t sepCntEnd, sStd::Data<char>& output)
{
	// If first character is NULL
	if (!*input)
	{
		// Set data to nullptr and 0 length and return not OK status
		output.set(nullptr, 0);
		return SSTD_NOK;		
	}

	char* start = nullptr;
	
	// Set start to first character if sepBegin param is NULL character
	if (sepBegin) start = findToken(input, sepBegin, sepCntBegin, 1);
		else start = input;

	// If start of the token was not found
	if (!start)
	{
		// Set data to nullptr and 0 length and return not OK status
		output.set(nullptr, 0);
		return SSTD_NOK;
	}
	else if (start[1]) // If next character is not \0
	{
		// Move start to next character
		start++;
		
		// Set output data to start address and end - start length
		if (sepBegin) output.set(start, findToken(start, sepEnd, sepCntEnd, 0) - start);
			else output.set(start - 1, findToken(start, sepEnd, sepCntEnd, 0) - start + 1); // -1 byte for start address abd +1 to include first character
		return SSTD_OK;
	}

	return SSTD_NOK;
}

uint8_t sStd::sscan(char* input, sStd::scanData* data, const uint8_t len, const uint8_t sorted)
{
	uint8_t total = 0;

	// Loop through input list
	for (uint8_t i = 0; i < len; i++)
	{
		// Call single sscan function.
		if (sscan(input, data[i].sepBegin, data[i].sepCntBegin, data[i].sepEnd, data[i].sepCntEnd, data[i].output) == SSTD_OK) total++;

		// Calculate new start position if input list is sorted
		if (sorted) input += data[i].output.len() + 1;
	}

	return total;

}


// STATIC FUNCTION DEFINITIONS
static char* sStd::findToken(char* input, char sep, char sepCnt, uint8_t retNull)
{
	// If character is not \0
	while (*input) 
	{
		// If wanted character is found
		if (*input == sep)
		{
			// If that is wanted separator
			if (!sepCnt) return input;
				else sepCnt--;
		}

		// Move to next character
		input++;		
	}

	// Return nullptr if retNull param is not 0, otherwise return address of \c character
    if (retNull) return nullptr;
	    else return input;
}


// ----- FUNCTION DEFINITIONS
