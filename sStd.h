/**
 * @file sStd.h
 * @author silvio3105 (www.github.com/silvio3105)
 * @brief sStd header file.
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

#ifndef SSTD_H_
#define SSTD_H_

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

// MACRO FUNCTION ALIASES
#define AL					SSTD_ARRAY /**< @brief Alias for \ref SSTD_ARRAY */

#define SCALE				SSTD_SCALE /**< @brief Alias for \ref SSTD_SCALE */
#define MAP					SSTD_SCALE /**< @brief Alias for \ref SSTD_SCALE */
#define MIN2				SSTD_MIN2 /**< @brief Alias for \ref SSTD_MIN2 */
#define MIN3				SSTD_MIN3 /**< @brief Alias for \ref SSTD_MIN3 */
#define MAX2				SSTD_MAX2 /**< @brief Alias for \ref SSTD_MAX2 */
#define MAX3				SSTD_MAX3 /**< @brief Alias for \ref SSTD_MAX3 */
#define ABS					SSTD_ABS /**< @brief Alias for \ref SSTD_ABS */

#define BSET				SSTD_BIT_SET /**< @brief Alias for \ref SSTD_BIT_SET */
#define BCLEAR				SSTD_BIT_CLEAR /**< @brief Alias for \ref SSTD_BIT_CLEAR */
#define BIT					SSTD_BIT /**< @brief Alias for \ref SSTD_BIT */
#define BBIT				SSTD_BBIT /**< @brief Alias for \ref SSTD_BBIT */
#define BTOGGLE				SSTD_BIT_TOGGLE /**< @brief Alias for \ref SSTD_BIT_TOGGLE */


// ----- MACRO FUNCTIONS
// MISC FUNCTIONS
/**
 * @brief Code snippet for calculating number of members in array.
 * 
 * @param _in Input array.
 */
#define SSTD_ARRAY(_in) \
	sizeof(_in) / sizeof(_in[0])

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
#define SSTD_SCALE(_in, _inMin, _inMax, _outMin, _outMax) \
	(_in - _inMin) * (_outMax - _outMin) / (_inMax - _inMin) + _outMin

/**
 * @brief Code snippet for finding lowest value between 2 input values.
 * 
 * @param _in1 Input value 1.
 * @param _in2 Input value 2.
 */
#define SSTD_MIN2(_in1, _in2) \
	(_in1 < _in2) ? _in1 : _in2

/**
 * @brief Code snippet for finding greatest value between 2 input values.
 * 
 * @param _in1 Input value 1.
 * @param _in2 Input value 2.
 */
#define SSTD_MAX2(_in1, _in2) \
	(_in1 > _in2) ? _in1 : _in2

/**
 * @brief Code snippet for finding lowest value between 3 input values.
 * 
 * @param _in1 Input value 1.
 * @param _in2 Input value 2.
 * @param _in3 Input value 3.
 */
#define SSTD_MIN3(_in1, _in2, _in3) \
	(_in1 < _in2) ? (_in1 < _in3 ? _in1 : _in3) : (_in2 < _in3 ? _in2 : _in3)

/**
 * @brief Code snippet for finding greatest value between 3 input values.
 * 
 * @param _in1 Input value 1.
 * @param _in2 Input value 2.
 * @param _in3 Input value 3.
 */
#define SSTD_MAX3(_in1, _in2, _in3) \
	(_in1 > _in2) ? (_in1 > _in3 ? _in1 : _in3) : (_in2 > _in3 ? _in2 : _in3)

/**
 * @brief Get absolute value from input value.
 * 
 * @param _in Input value.
 */
#define SSTD_ABS(_in) \
	if (_in < 0) _in *= -1


// BITFIELDS OPERATIONS
/**
 * @brief Set \c _bit of \c _value to 1.
 * 
 * @param _value Input value.
 * @param _bit Bit number of \c _value to change to 1.
 */
#define SSTD_BIT_SET(_value, _bit) \
	_value |= 1 << _bit

/**
 * @brief Set \c _bit of \c _value to 0. 
 * 
 * @param _value Input value.
 * @param _bit Bit number of \c _value to change to 0. 
 */
#define SSTD_BIT_CLEAR(_value, _bit) \
	_value &= ~(1 << _bit) 

/**
 * @brief Fetch \c _bit from \c _value
 * 
 * @param _value Input value.
 * @param _bit Bit number of \c _value to fetch.
 * 
 * @note Function returns \c 0 for \c _bit = 0 or any positive number for \c _bit = 1.
 */
#define SSTD_BIT(_value, _bit) \
	_value & (1 << _bit)

/**
 * @brief Fetch \c _bit from \c _value
 * 
 * @param _value Input value.
 * @param _bit Bit number of \c _value to fetch.
 * 
 * @note Function returns \c 0 or \c 1.
 */
#define SSTD_BBIT(_value, _bit) \
	(_value & (1 << _bit)) >> _bit

/**
 * @brief Toggle \c _bit in \c _value
 * 
 * @param _value Input value.
 * @param _bit Bit number of \c _value to toggle.
 */
#define SSTD_BIT_TOGGLE(_value, _bit) \
	_value ^= 1 << _bit


#ifdef __cplusplus

// ----- NAMESPACES
/**
 * @brief Namespace for Simple Standard Library.
 * 
 */
namespace sStd
{
	// ENUMATORS
	/**
	 * @brief Enumator for logger status.
	 * 
	 */
	typedef enum logStatus_t : uint8_t {
		LOG_OFF = 0, /**< @brief Logger is turned off. Print(f)s will be ignored. */
		LOG_ON = 1 /**< @brief Logger is turned on. */
	};

	/**
	 * @brief Enumator for logger type.
	 * 
	 */
	typedef enum logType_t : uint8_t {
		LOG_BLOCKING = 0, /**< @brief Blocking logger. Code execution will continue after transfer ends. */
		LOG_NON_BLOCKING = 1 /**< @brief Non-blocking logger. Transfer will be done in parallel with main code. New print(f)s will wait for semaphore. */
	};

	// TYPEDEFS
	typedef uint16_t rbIdx_t; /**< @brief Type for \ref RingBuffer length. */
	/**
	 * @brief Pointer to external function for sending log strings.
	 * 
	 * @param buffer Pointer to buffer to send.
	 * @param len Length of \c buffer
	 * @return No return value.
	 */
	typedef void (*extHandler)(const uint8_t* buffer, const uint16_t len);

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

	/**
	 * @brief Ring buffer class.
	 * 
	 * @tparam T Type of ring buffer data, eg. \c uint32_t
	 * @tparam N Number of data in ring buffer.
	 */
	template<typename T, rbIdx_t N>
	class RingBuffer {
		// PUBLIC STUFF
		public:
		// CONSTRUCTORS & DECONSTRUCTORS
		/**
		 * @brief Ring buffer constructor.
		 * 
		 * @return No return value.
		 */
		RingBuffer(void);

		/**
		 * @brief Ring buffer deconstructor.
		 * 
		 * @return No return value.
		 */
		~RingBuffer(void);

		// METHOD DECLARATIONS
		/**
		 * @brief Write single \c T type data to ring buffer.
		 * 
		 * @param data Data of \c T type.
		 * @return \c SSTD_NOK if data were not written.
		 * @return \c SSTD_OK if data were written.
		 */
		inline uint8_t write(T data);

		/**
		 * @brief Write multiple data to ring buffer.
		 * 
		 * @param data Pointer to data of \c T type.
		 * @param len Length of \c data
		 * @return \c SSTD_NOK if data is not written.
		 * @return \c SSTD_OK if data is written.
		 */
		uint8_t write(T* data, rbIdx_t len);

		/**
		 * @brief Read signle data from ring buffer.
		 * 
		 * @param output Reference for output of \c T type.
		 * @return \c SSTD_NOK if no data were read.
		 * @return \c SSTD_OK if data were read.
		 */
		uint8_t read(T& output);

		/**
		 * @brief Read multiple data from ring buffer.
		 * 
		 * @param output Pointer to array for output data of \c T type. 
		 * @param len Length of \c output array.
		 * @return \c SSTD_NOK if no data were read.
		 * @return \c SSTD_OK if some data were read.
		 */
		uint8_t read(T* output, rbIdx_t len);

		/**
		 * @brief Flush all data from ring buffer.
		 * 
		 * @return No return value.
		 */
		void flush(void);

		/**
		 * @brief Fetch number of used data in ring buffer.
		 * 
		 * @return Number of used data.
		 */
		inline rbIdx_t used(void) const;

		/**
		 * @brief Fetch number of free data in ring buffer.
		 * 
		 * @return Number of free data.
		 */
		inline rbIdx_t free(void) const;

		/**
		 * @brief Is ring buffer full.
		 * 
		 * @return \c SSTD_NOK if ring buffer is not full.
		 * @return \c SSTD_OK if ring buffer is full.
		 */
		uint8_t isFull(void) const;

		/**
		 * @brief Get length of ring buffer.
		 * 
		 * @return Length of ring buffer
		 */
		inline rbIdx_t len(void) const;



		// PRIVATE STUFF
		private:
		// VARIABLES
		T memory[N]; /**< @brief Array of \c T type where ring buffer data will be stored. */
		const rbIdx_t length = N; /**< @brief Length of \ref memory array. */
		rbIdx_t head = 0; /**< @brief Head data pointer. */
		rbIdx_t tail = 0; /**< @brief Tail data pointer. */
		rbIdx_t newCnt = 0; /**< @brief New data counter. */

		// METHOD DECLARATIONS
		/**
		 * @brief Write single \c T type data to ring buffer.
		 * 
		 * @param data Data of \c T type.
		 * @return \c SSTD_NOK if data were not written.
		 * @return \c SSTD_OK if data were written.
		 */
		uint8_t writeData(T data);

		/**
		 * @brief Increase tail pointer.
		 * 
		 * @return No return value.
		 */
		void increaseTail(void);
	};

	/**
	 * @brief Logger class.
	 * 
	 * @tparam N Buffer size in bytes.
	 */
	template<uint16_t N>
	class Logger
	{
		// PUBLIC STUFF
		public:
		// CONSTRUCTOR AND DECONSTRUCTOR DECLARATIONS
		/**
		 * @brief Logger constructor.
		 * 
		 * @param handler Pointer to external function for handling buffer transfer(printing).
		 * @param fix Prefix C-string. Has to be NULL terminated.
		 * @param type Logger type. See \ref logType_t
		 * @param status Logger initial status. See \ref logStatus_t
		 * @return No return value.
		 */
		Logger(sStd::extHandler handler, const char* fix = '\0', sStd::logType_t type = LOG_BLOCKING, sStd::logStatus_t status = LOG_ON);

		/**
		 * @brief Logger deconstructor.
		 * 
		 * @return No return value.
		 */
		~Logger(void);

		// METHOD DECLARATIONS
		/**
		 * @brief Print constant C-string.
		 * 
		 * @param str Pointer to C-string.
		 * @param len Length of \c str
		 * @return No return value.
		 */
		void print(const char* str, const uint16_t len);

		/**
		 * @brief Format and print string.
		 * 
		 * This method uses variable argument list and \c vsnprintf function for string formating.
		 * 
		 * @param str Pointer to C-string.
		 * @param ... Variable arguments.
		 * @return No return value.
		 */
		void printf(const char* str, ...);

		/**
		 * @brief Get size of logger's buffer.
		 * 
		 * @return Size of logger's buffer.
		 */
		inline uint16_t size(void) const;

		/**
		 * @brief Release logger semaphore.
		 * 
		 * This method releases logger semaphore. This method is called after non-blocking transfer has ended(eg. DMA transfer to UART).
		 * 
		 * @return No return value.
		 */
		inline void release(void);

		/**
		 * @brief Get logger status.
		 * 
		 * @return Logger status. See \ref sStd::logStatus_t
		 */
		sStd::logStatus_t status(void) const;

		/**
		 * @brief Set logger status.
		 * 
		 * @param newStatus New logger status. See \ref sStd::logStatus_t
		 * @return No return value.
		 */
		void status(sStd::logStatus_t newStatus);

		// PRIVATE STUFF
		private:
		// VARIABLES
		/**
		 * @brief Logger configuration.
		 * 
		 * Bit 0 = Logger status bit. See \ref sStd::logStatus_t
		 * 
		 * Bit 1 = Logger type bit. See \ref sStd::logType_t
		 * 
		 * Bit 2 = Logger semaphore bit. \c 0 means semaphore is free. \c 1 means semaphore is taken.
		 */
		uint8_t config = 0;
		uint8_t prefixLen = 0; /**< @brief Length of \ref prefix */
		char buffer[N] = { '\0' }; /**< @brief Logger buffer. */
		const char* prefix = nullptr; /**< @brief Logger prefix (C-string). Has to be NULL terminated. */
		const sStd::extHandler printHandler = nullptr; /**< @brief Pointer to external function that handles buffer transfer. */

		// METHOD DECLARATIONS
		/**
		 * @brief Handle semaphore and calls \ref printHandler
		 * 
		 * @param str Pointer to C-string.
		 * @param len Length of C-string pointed by \c str
		 * @return No return value.
		 */
		void out(const char* str, const uint16_t len);

		/**
		 * @brief Wait for released semaphore.
		 * 
		 * @return No return value.
		 */
		void wait(void);
	};


	// STRUCTS
	struct scanData {
		char sepEnd; /**< End separator after wanted parameter. */
		uint8_t sepCntEnd; /**< Number of \c sepEdn after wanted parameter is found. */
		char sepBegin; /**< Begin separator before wanted parameter. */
		uint8_t sepCntBegin; /**< Number of \c sepBegin before wanted parameter. */		
		sStd::Data<char> output; /**< \c char type output data. */
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

	template<typename T>
	/**
	 * @brief Sum all integer digits.
	 * 
	 * Example: Number 123456 will result with 21(1 + 2 + 3 + 4 + 5 + 6).
	 * 
	 * @param input Input number.
	 * @return Sum of all digits.
	 */
	uint8_t sumDigits(T input);

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
	uint16_t len(const char* input, const char endChar = '\0');

	/**
	 * @brief Count number of \c character in \c input C-string.
	 * 
	 * @param input Pointer to C-string.
	 * @param character Character to count.
	 * @param endChar Character where function should stop. This parameter is optional.
	 * @return Number of \c character in \c input
	 */
	uint16_t count(const char* input, const char character, const char endChar = '\0');

	/**
	 * @brief Compare two C-strings.
	 * 
	 * @param input1 Pointer to first C-string.
	 * @param input2 Pointer to second C-string.
	 * @param endChar Character where function should stop. This parameter is optional.
	 * @return \c SSTD_NOK if strings are not equal.
	 * @return \c SSTD_OK if strings are equal. 
	 */
	uint8_t cmp(const char* input1, const char* input2, char endChar = '\0');

	// STRING SCAN FUNCTIONS DECLARATIONS
	/**
	 * @brief Scan C-string for wanted token. 
	 * 
	 * This function is replacment for scanf function. C-string format must be known to use this function.
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
	 * @param modify Set to \c 1 to replace found separator with \c \0 char.
	 * @return \c SSTD_NOK if no token was found.
	 * @return \c SSTD_OK if token was found.
	 * 
	 * @warning \c sepCntBegin and \c sepCntEnd start from 0!
	 * @note C-string has to be NULL terminated.
	 * @note Function scans from left to right.
	 */
	uint8_t sscan(char* input, char sepBegin, uint8_t sepCntBegin, char sepEnd, uint8_t sepCntEnd, sStd::Data<char>& output, const uint8_t modify = 0);

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
	 * @param sorted Set to \c 1 if \c input list is sorted(from left to right). Function will continue where it ended during scan for previous entry in \c input list. This parameter is optional.
	 * @param modify Set to \c 1 to replace found separator with \c \0 char.
	 * @return Number of found tokens.
	 * 
	 * @warning \c modify can be used only when \c data list is \c sorted
	 * @note If \c data list is sorted, set param \c sorted to \c 1 to make scanning faster.  
	 * @note C-string has to be NULL terminated.
	 * @note Function scans from left to right.
	 */
	uint8_t sscan(char* input, sStd::scanData* data, const uint8_t len, const uint8_t modify = 0, const uint8_t sorted = 0);


	// STATIC FUNCTIONS
	/**
	 * @brief Find separator in C-string.
	 * 
	 * @param input Pointer to input C-string.
	 * @param sep Seperator character.
	 * @param sepCnt Number of separators before end of token.
	 * @param retNull Set to \c 1 to return \c nullptr if \c \0 character is found. Set to \c 0 to return address if \c \0 is found.
	 * @return \c nullptr if no token was found.
	 * @return Address of last found separator.
	 * @return \c nullptr if separator was not found.
	 */
	static char* findToken(char* input, char sep, char sepCnt, const uint8_t retNull);
};

#pragma message ("Using full sStd.") 
#else
#pragma message ("Missing C++ part of sStd.") 
#endif // __cplusplus

/** @}*/

#endif // SSTD_H_

// END WITH NEW LINE
