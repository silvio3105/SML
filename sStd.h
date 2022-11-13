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

// ----- MACRO DEFINITIONS
// RETURN CODES
#define SSTD_NOK			0 /**< @brief Negative return code. */
#define SSTD_OK				1 /**< @brief Positive return code. */


// ----- MACRO FUNCTIONS
// MATH FUNCTIONS
/**
 * @brief Code snippet for scaling value.
 * 
 * @param _in Input value.
 * @param _inMin Input minimum value.
 * @param _inMax Input maximum value.
 * @param _outMin Output minimum value.
 * @param _outMax Output maximum value.
 */
#define _sSTD_SCALE(_in, _inMin, _inMax, _outMin, _outMax) \
	(_in - _inMin) * (_outMax - _outMin) / (_inMax - _inMin) + _outMin

/**
 * @brief Code snippet for finding lowest value between 2 input values.
 * 
 * @param _in1 Input value 1.
 * @param _in2 Input value 2.
 */
#define _sSTD_MIN2(_in1, _in2) \
	(_in1 < _in2) ? _in1 : _in2

/**
 * @brief Code snippet for finding greatest value between 2 input values.
 * 
 * @param _in1 Input value 1.
 * @param _in2 Input value 2.
 */
#define _sSTD_MAX2(_in1, _in2) \
	(_in1 > _in2) ? _in1 : _in2

/**
 * @brief Code snippet for finding lowest value between 3 input values.
 * 
 * @param _in1 Input value 1.
 * @param _in2 Input value 2.
 * @param _in3 Input value 3.
 */
#define _sSTD_MIN3(_in1, _in2, _in3) \
	(_in1 < _in2) ? (_in1 < _in3 ? _in1 : _in3) : (_in2 < _in3 ? _in2 : _in3)

/**
 * @brief Code snippet for finding greatest value between 3 input values.
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
#define _sSTD_BIT_TOGGLE(_value, _bit) \
	_value ^= 1 << _bit


#ifdef __cplusplus

// ----- NAMESPACES
namespace sStd /**< @brief Namespace for sStd. */
{
	// CLASSES
	template<typename T>
	/**
	 * @brief Class representing data \c T with \c len
	 * 
	 * @warning Maximum data length is 2^16!
	 */
	class Data {
		// PUBLIC STUFF
		public:
		// CONSTRUCTORS & DECONSTRUCTORS
		/**
		 * @brief Constructor for \c Data object.
		 * 
		 * @return No return value.
		 */
		Data(void);

		/**
		 * @brief Deconstructor for \c Data object.
		 * 
		 * @return No return value.
		 */
		~Data(void);

		// METHODS DECLARATIONS
		/**
		 * @brief Get address of the data.
		 * 
		 * @return Pointer to data.
		 */
		inline T* get(void) const;

		/**
		 * @brief Set new data.
		 * 
		 * @param newData Pointer to new data.
		 * @param newLen Length of new data.
		 * @return No return value.
		 */
		void set(T* newData, uint16_t newLen);

		/**
		 * @brief Get length of data.
		 * 
		 * @return Data's length.
		 */
		inline uint16_t len(void) const;

		// PRIVATE STUFF
		private:
		T* dataAddr; /**< Pointer to address where data is stored. */
		uint16_t length; /**< Length of \ref dataAddr. */
	};


	// STRUCTS
	struct scanData {
		sStd::Data<char> output; /**< \c char type output data. */
		char sepBegin; /**< Begin separator before wanted parameter. */
		uint8_t sepCntBegin; /**< Number of \c sepBegin before wanted parameter. */
		char sepEnd; /**< End separator after wanted parameter. */
		uint8_t sepCntEnd; /**< Number of \c sepEdn after wanted parameter is found. */
	};	


	// MATH FUNCTIONS
	template<typename T>
	/**
	 * @brief Scale input value to desired output value range.
	 * 
	 * @param in Input value.
	 * @param inMin Input minimum value.
	 * @param inMax Input maximum value.
	 * @param outMin Output minimum value.
	 * @param outMax Output maximum value.
	 * @return \c in value scaled to fit range defined with \c outMin and \c outMax
	 */
	T scale(T in, T inMin, T inMax, T outMin, T outMax);

	template<typename T>
	/**
	 * @brief Find lowest value between 2 input values.
	 * 
	 * @param in1 Input value 1.
	 * @param in2 Input value 2.
	 * @return Lowest value between \c in1 and \c in2
	 */
	T min2(T in1, T in2);

	template<typename T>
	/**
	 * @brief Find greatest value between 2 input values.
	 * 
	 * @param in1 Input value 1.
	 * @param in2 Input value 2.
	 * @return Greatest value between \c in1 and \c in2
	 */	
	T max2(T in1, T in2);

	template<typename T>
	/**
	 * @brief Find lowest value between 3 input values.
	 * 
	 * @param in1 Input value 1.
	 * @param in2 Input value 2.
	 * @param in3 Input value 3.
	 * @return Lowest value between \c in1 \c in2 and \c in3
	 */			
	T min3(T in1, T in2, T in3);

	template<typename T>
	/**
	 * @brief Find greatest value between 3 input values.
	 * 
	 * @param in1 Input value 1.
	 * @param in2 Input value 2.
	 * @param in3 Input value 3.
	 * @return Greatest value between \c in1 \c in2 and \c in3
	 */		
	T max3(T in1, T in2, T in3);	

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

	/**
	 * @brief Find length of input C-string.
	 * 
	 * @param input Pointer to C-string.
	 * @param endChar Character that marks end of C-string.
	 * @return Length of C-string.
	 * 
	 * @note By default, parameter \c endChar is set to \c \0 which is standard character for ending C-strings.
	 */
	uint16_t len(char* input, char endChar = '\0');

	/**
	 * @brief Count number of \c character in \c input C-string.
	 * 
	 * @param input Pointer to C-string.
	 * @param character Character to count.
	 * @param endChar Character where function should stop. This parameter is optional.
	 * @return Number of \c character in \c input
	 */
	uint16_t count(char* input, char character, char endChar = '\0');

	/**
	 * @brief Compare two C-strings.
	 * 
	 * @param input1 Pointer to first C-string.
	 * @param input2 Pointer to second C-string.
	 * @param endChar Character where function should stop. This parameter is optional.
	 * @return \c SSTD_NOK if strings are not equal.
	 * @return \c SSTD_OK if strings are equal. 
	 */
	uint8_t cmp(char* input1, char* input2, char endChar = '\0');

	// STRING SCAN FUNCTIONS DECLARATIONS
	/**
	 * @brief Scan C-string for wanted token. 
	 * 
	 * This function is replacment for scanf function. C-string format must be known to use this function. Function does not modify C-string.
	 * Function returns \c SSTD_OK and result even if \c \0 is encountered during searching for token's end.
	 * Set \c \0 as first separator to indicate that wanted token starts from begining of input C-string.
	 * 
	 * Example #1:
	 * C-string \c test1-test2.hello,test123 and call \c sscan(string,'.',0,'\0',0,output) -> output will be pointing at letter \c h and length will be 13. Output C-string will be \c hello,test123
	 * 
	 * Example #2:
	 * C-string \c test1,test2-test3-test4.test5,test6 and call \c sscan(string,'-',1,',',0,output) -> output C-string will be \c test4.test5 length will be 11.
	 * \c 1 because there is \c 1 \c - before wanted token, dash between \c test2 and \c test3
	 * \c 0 because there is \c 0 \c , after \c sepBegin
	 * 
	 * Example #3:
	 * C-string \c test1,test2,test3-test4.test5,test6 and call \c sscan(string,'\0',0,',',1,output) -> output C-string will be \c test1,test2 length will be 11.
	 * \c \0 as begin separator indicates that wanted token starts from begining. In that case, \c sepCntBegin parameter makes no effect.
	 * 
	 * See example code for more info.
	 * 
	 * @param input Pointer to first character in C-string.
	 * @param sepBegin Character used as separator before wanted token.
	 * @param sepCntBegin Number of separators before wanted token.
	 * @param sepEnd Character used as separator after wanted token.
	 * @param sepCntEnd Number of separators after wanted token is found.
	 * @param output Reference to char output data. 
	 * @return \c SSTD_NOK if no token was found.
	 * @return \c SSTD_OK if token was found.
	 * 
	 * @warning \c sepCntBegin and \c sepCntEnd start from 0!
	 * @note C-string has to be NULL terminated.
	 * @note Function scans from left to right.
	 */
	uint8_t sscan(char* input, char sepBegin, uint8_t sepCntBegin, char sepEnd, uint8_t sepCntEnd, sStd::Data<char>& output);

	/**
	 * @brief Scan C-string for wanted tokens.
	 * 
	 * This function works same as \ref uint8_t sscan(char* input, char separator, uint8_t separatorCnt, sStd::data<char>& output)
	 * Only difference is that this function can scan for multiple tokens.
	 * If output result is \c nullptr then wanted token was not found.
	 * See example code for more info.
	 * 
	 * @param input Pointer to first character in C-string.
	 * @param data Pointer to input-output data list.
	 * @param len Length of \c data
	 * @return \c SSTD_NOK if no tokens were found.
	 * @return Number of found tokens.
	 * 
	 * @note \c data list does not have to be sorted since this function depends on \ref uint8_t sscan(char* input, char separator, uint8_t separatorCnt, sStd::data<char>& output) and it will start from beginning for every entry in \c data
	 * @note C-string has to be NULL terminated.
	 * @note Function scans from left to right.
	 */
	uint8_t sscan(char* input, sStd::scanData* data, const uint8_t len);


	// STATIC FUNCTIONS
	/**
	 * @brief Find separator in C-string.
	 * 
	 * @param input Pointer to input C-string.
	 * @param sep Seperator character.
	 * @param sepCnt Number of separators before end of token.
	 * @param retNull Pass \c 1 to return \c nullptr if \c \0 character is found. Pass \c 0 to return address if \c \0 is found.
	 * @return \c nullptr if no token was found.
	 * @return Address of last found separator.
	 * @return \c nullptr if separator was not found.
	 */
	static char* findToken(char* input, char sep, char sepCnt, uint8_t retNull);
};

#pragma message ("Using full sStd.") 
#else
#pragma message ("Missing C++ part of sStd.") 
#endif // __cplusplus

/** @}*/

#endif // _SSTD_H_

// END WITH NEW LINE
