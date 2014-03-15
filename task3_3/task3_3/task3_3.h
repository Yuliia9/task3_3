#ifndef TASK3_3_H_
#define TASK3_3_H_

/*
*@file		task3_3.h
*@brief		header file that defines prototypes of functions used in file task3_3.cpp
*/

#include "stdafx.h"


/*
* @brief				This function displays general information about program to users
* @param	void
* @return	void
*/
void Interface(void);


/*
* @brief					Function for inputing string
* @param	[in/out]		char** riadok - a pointer to null pointer to string of sentences
			[in/out]		char* character - a pointer to input character needed to be find
*
*@return	unsigned char	Return ERROR if error occurs while trying to allocate memory for string
							Return SUCCESS if string and character were inputed
*/
unsigned char Input(char** riadok, char* character);



/*
* @brief					Function for finding words in sentences
* @param	[in/out]		char* sentence - a pointer to sentences for finding words
			[in/out]		char** begin - begin of word that include character
			[in]			const char* character - character that needed to be found
*
*@return	char*			Return pointer to the end of word that include character 
							Return NULL if character wasn't find
*/
char* Find(char* sentence, char** begin, const char* character);

#endif