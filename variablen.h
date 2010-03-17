#ifndef VARIABLEN_H
#define VARIABLEN_H

#define		INPUT		1
#define		OUTPUT		0

#define		HIGH		1
#define		LOW			0

#define		ENABLE_CS	0
#define		DISABLE_CS	1

#define 	true		1
#define 	false		0

#define		RUNNING		1

typedef unsigned char 			uint8; 			///< This datatype is represented by one unsigned Byte.
typedef unsigned int 			uint16; 		///< This datatype is represented by two unsigned Byte.
//typedef unsigned short long 	uint24; 		///< This datatype is represented by three unsigned Byte.
typedef unsigned long 			uint32; 		///< This datatype is represented by four unsigned Byte.
typedef signed char 			int8; 			///< This datatype is represented by one signed Byte.
typedef signed int 				int16; 			///< This datatype is represented by two signed Byte.
//typedef signed short long 		int24; 			///< This datatype is represented by three signed Byte.
typedef signed long 			int32; 			///< This datatype is represented by four signed Byte.
typedef unsigned char 			bool;			///< This datatype represents a boolean value.

typedef union
{
	struct
	{
		uint8 bit0:1;
		uint8 bit1:1;
		uint8 bit2:1;
		uint8 bit3:1;
		uint8 bit4:1;
		uint8 bit5:1;
		uint8 bit6:1;
		uint8 bit7:1;
	}bits;
	uint8 byte;
} Byte;

struct CANMessage
{
    uint8 data[8];
    uint8 length;
    uint32 id;
    uint8 flags;
    bool success;
};



#endif //WOBRACING_H
