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

// MACRO FUNCTIONS
#define _sSTD_MAP(_in, _inMin, _inMax, _outMin, _outMax) \
	(_in - _inMin) * (_outMax - _outMin) / (_inMax - _inMin) + _outMin

#define _sSTD_MIN(_in1, _in2, _in3) \
	(_in1 < _in2) ? (_in1 < _in3 ? _in1 : _in3) : (_in2 < _in3 ? _in2 : _in3)

#define _sSTD_MAX(_in1, _in2, _in3) \
	(_in1 > _in2) ? (_in1 > _in3 ? _in1 : _in3) : (_in2 > _in3 ? _in2 : _in3)


// ----- NAMESPACES
/**
 * @brief Namespace for sStd
 * 
 */
namespace sStd
{

};

/** @}*/

#endif // _SSTD_H_

// END WITH NEW LINE
