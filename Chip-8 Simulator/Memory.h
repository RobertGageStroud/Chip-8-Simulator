#pragma once
/*
	File: Memory.h
	Desc: Declares the memory class which contains the program stack and RAM then defines the interface to access RAM and Program Stack.

	Author: Robert Stroud
*/
#ifndef MEMORY_H
#define MEMORY_H

#include <cstdint>
#include <cstdio>
#include <iostream>
#include "Values.h"
#include "Registers.h"

class Memory
{
	//Private Member Data
	uint8_t		memory[MEM_SIZE];
	uint16_t	stack[STACK_SIZE];
	FILE*		file;
	uint8_t*	progStart = &memory[0x200];
	Registers*	regs;
	//Private Member Functions

	//Public Member Functions
	public:

		//Constructor
		Memory(Registers* r);

		//General RAM accessor and mutator functions
		uint8_t		getMemByte(uint64_t byteAddress);
		void		putMemByte(uint64_t byteAddress, uint8_t value);

		//Stack accessor and mutator functions.
		uint16_t	pop();
		void		push(uint16_t value);

		//Methods used to restore Memory to intial state.
		void		reset();
		void		preload();

		//Methods used to load programs into Memory.
		void		load(int select);
	
};
#endif

