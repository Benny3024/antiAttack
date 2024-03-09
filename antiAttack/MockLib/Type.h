#ifndef _TYPE_H
#define _TYPE_H

#pragma once

/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*XX      PUBLIC TYPE DEFINITION                                             XX*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
typedef   signed char          s1;
typedef unsigned char          u1;
typedef   signed short         s2;
typedef unsigned short         u2;
typedef   signed long          s4;
typedef unsigned long          u4;
typedef          long long     s8;
typedef unsigned long long     u8;

typedef unsigned char          tf;
typedef   signed int           sint;
typedef unsigned int           uint;

#ifndef TRUE
# define TRUE                          (1U)
#endif

#ifndef FALSE
# define FALSE                         (0U)
#endif

/*=======================================================================*
 * Target hardware information
 *   Device type: Generic->32-bit Embedded Processor
 *   Number of bits:     char:   8    short:   16    int:  32
 *                       long:  32      native word size:  32
 *   Byte ordering: Unspecified
 *   Signed integer division rounds to: Zero
 *   Shift right on a signed integer as arithmetic shift: on
 *=======================================================================*/

 /*=======================================================================*
  * Fixed width word size data types:                                     *
  *   int8_T, int16_T, int32_T     - signed 8, 16, or 32 bit integers     *
  *   uint8_T, uint16_T, uint32_T  - unsigned 8, 16, or 32 bit integers   *
  *=======================================================================*/
typedef   signed char          int8_T;
typedef unsigned char          uint8_T;
typedef   signed short         int16_T;
typedef unsigned short         uint16_T;
typedef   signed long          int32_T;
typedef unsigned long          uint32_T;

/*===========================================================================*
 * Generic type definitions: boolean_T, int_T, uint_T, ulong_T, char_T,      *
 *                           and byte_T.                                     *
 *===========================================================================*/
typedef unsigned char          boolean_T;
typedef int                    int_T;
typedef unsigned int           uint_T;
typedef unsigned long          ulong_T;
typedef char                   char_T;
typedef unsigned char          uchar_T;
typedef char_T                 byte_T;

/*=======================================================================*
 * Min and Max:                                                          *
 *   int8_T, int16_T, int32_T     - signed 8, 16, or 32 bit integers     *
 *   uint8_T, uint16_T, uint32_T  - unsigned 8, 16, or 32 bit integers   *
 *=======================================================================*/
#define MAX_int8_T                     ((int8_T)(127))
#define MIN_int8_T                     ((int8_T)(-128))
#define MAX_uint8_T                    ((uint8_T)(255U)) 
#define MIN_uint8_T                    ((uint8_T)(0U))
#define MAX_int16_T                    ((int16_T)(32767)) 
#define MIN_int16_T                    ((int16_T)(-32768))
#define MAX_uint16_T                   ((uint16_T)(65535U))
#define MIN_uint16_T                   ((uint16_T)(0U))
#define MAX_int32_T                    ((int32_T)(2147483647))
#define MIN_int32_T                    ((int32_T)(-2147483647-1))
#define MAX_uint32_T                   ((uint32_T)(0xFFFFFFFFU))
#define MIN_uint32_T                   ((uint32_T)(0U))


typedef struct arr_bool {
	int* arr;
	int size;
} arr_bool;

typedef struct matrix_bool {
	arr_bool* arr;
	int size;
} matrix_bool;

typedef struct arr_char {
	char* arr;
	int size;
} arr_char;

typedef struct arr_string {
	char** arr;
	int size;
} arr_string;

typedef struct arr_int {
	int* arr;
	int size;
} arr_int;

typedef struct arr_long {
	long long* arr;
	int size;
} arr_long;

typedef struct arr_double {
	double* arr;
	int size;
} arr_double;

typedef struct matrix_char {
	arr_char* arr;
	int size;
} matrix_char;

typedef struct matrix_string {
	arr_string* arr;
	int size;
} matrix_string;

typedef struct matrix_int {
	arr_int* arr;
	int size;
} matrix_int;

typedef struct matrix_long {
	arr_long* arr;
	int size;
} matrix_long;

typedef struct matrix_double {
	arr_double* arr;
	int size;
} matrix_double;

#endif