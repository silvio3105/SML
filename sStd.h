/**
 * @file sStd.h
 * @author silvio3105 (www.github.com/silvio3105)
 * @brief sStd header file.
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

#ifndef _SSTD_H_
#define _SSTD_H_

// ----- INCLUDE FILES
#include            <stdint.h>


/** \addtogroup sStd
 * 
 * Custom library with miscellaneous functions. 
 * @{
*/

// ----- MACRO FUNCTIONS
// MATH FUNCTIONS
/**
 * @brief Code snippet for mapping value.
 * 
 * @param _in Input value.
 * @param _inMin Input minimum value.
 * @param _inMax Input maximum value.
 * @param _outMin Output minimum value.
 * @param _outMax Output maximum value.
 */
#define _sSTD_MAP(_in, _inMin, _inMax, _outMin, _outMax) \
	(_in - _inMin) * (_outMax - _outMin) / (_inMax - _inMin) + _outMin

/**
 * @brief Find lowest value between 2 input values.
 * 
 * @param _in1 Input value 1.
 * @param _in2 Input value 2.
 */
#define _sSTD_MIN2(_in1, _in2, _in3) \
	(_in1 < _in2) ? _in1 : _in2

/**
 * @brief Find greatest value between 2 input values.
 * 
 * @param _in1 Input value 1.
 * @param _in2 Input value 2.
 */
#define _sSTD_MAX2(_in1, _in2, _in3) \
	(_in1 > _in2) ? _in1 : _in2

/**
 * @brief Find lowest value between 3 input values.
 * 
 * @param _in1 Input value 1.
 * @param _in2 Input value 2.
 * @param _in3 Input value 3.
 */
#define _sSTD_MIN3(_in1, _in2, _in3) \
	(_in1 < _in2) ? (_in1 < _in3 ? _in1 : _in3) : (_in2 < _in3 ? _in2 : _in3)

/**
 * @brief Find greatest value between 3 input values.
 * 
 * @param _in1 Input value 1.
 * @param _in2 Input value 2.
 * @param _in3 Input value 3.
 */
#define _sSTD_MAX3(_in1, _in2, _in3) \
	(_in1 > _in2) ? (_in1 > _in3 ? _in1 : _in3) : (_in2 > _in3 ? _in2 : _in3)


// BITFIELDS OPERATIONS
/**
 * @brief Set \c _bit of \c _value to 1.
 * 
 * @param _value Input value.
 * @param _bit Bit number of \c _value to change to 1.
 */
#define _sSTD_BIT_SET(_value, _bit) \
	_value |= 1 << _bit

/**
 * @brief Set \c _bit of \c _value to 0. 
 * 
 * @param _value Input value.
 * @param _bit Bit number of \c _value to change to 0. 
 */
#define _sSTD_BIT_CLEAR(_value, _bit) \
	_value &= ~(1 << _bit) 

/**
 * @brief Fetch \c _bit from \c _value
 * 
 * @param _value Input value.
 * @param _bit Bit number of \c _value to fetch.
 * 
 * @note Function returns \c 0 for \c _bit = 0 or any positive number for \c _bit = 1.
 */
#define _sSTD_BIT(_value, _bit) \
	_value & (1 << _bit)

/**
 * @brief Fetch \c _bit from \c _value
 * 
 * @param _value Input value.
 * @param _bit Bit number of \c _value to fetch.
 * 
 * @note Function returns \c 0 or \c 1.
 */
#define _sSTD_BBIT(_value, _bit) \
	(_value & (1 << _bit)) >> _bit

/**
 * @brief Toggle \c _bit in \c _value
 * 
 * @param _value Input value.
 * @param _bit Bit number of \c _value to toggle.
 */
#define _sSTD_TOGGLE(_value, _bit) \
	_value ^= 1 << _bit


// ----- STRUCTS
struct sScanData { /**< sScan result data struct. */
	char *data;
	uint16_t len;
};


// ----- CLASSES
class sScanResult { /**< Class for \ref sScan result. */
	// PUBLIC STUFF
	public:


	// PRIVATE STUFF
	private:
	sScanData data;
};

// ----- NAMESPACES
namespace sStd /**< @brief Namespace for sStd. */
{
	// STRING MANIPULATION FUNCTIONS DECLARATIONS
	/**
	 * @brief Replace desired character with NULL character.
	 * 
	 * Replaces \c separator in \c input C-string and returns address of next character if it is not NULL character.
	 * 
	 * @param input C-string input.
	 * @param separator Separator character
	 * @return \c nullptr if end of \c input C-string is reached.
	 * @return Pointer to next token in \c input C-string.
	 */
	char* tok(char* input, char separator);

	// STRING SCAN FUNCTIONS DECLARATIONS
	/**
	 * @brief Scan C-string and finds start of wanted parameter. 
	 * 
	 * This function is replacment for scanf function. C-string format must be known to use this function. Function does not modify C-string.
	 * For example C-string: \c test1,test2,hello,test123 and call \c sScan(string,',',2,output), output.data will be pointing at letter 'h' and output.len will be 5.
	 * Parameter \c 2 because there are two separators before wanted token. \c output.len is 5 because text \c hello is 5 letters long before new separator is found.
	 * If next function was called: \c sScan(string,',',3,output), then output.data will point to start of \c test123 text and output.len will be 7 because text is 7 characters long before NULL charater is found(end of C-string).
	 * 
	 * @param input Pointer to first character in C-string.
	 * @param separator Character used as separator between tokens.
	 * @param separatorCnt Number of separators before wanted token.
	 * @param output Reference to scan data output struct. 
	 * @return SSTD_NOK if no token was found.
	 * @return SSTD_OK if token was found.
	 * 
	 * @note C-string has to be NULL terminated.
	 */
	uint8_t scan(char* input, char separator, uint8_t separatorCnt, sScanData& output);
};

/** @}*/

#endif // _SSTD_H_

// END WITH NEW LINE
