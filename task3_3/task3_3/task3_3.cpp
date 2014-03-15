/*
* @file			task3_3.cpp
* @brief		Program shows all words that include defined character

* Copyright 2014 by Yuliia Lyubchik Inc.,
*
* This software is the confidential and proprietary information
* of Yuliia Lyubchik. ("Confidential Information").  You
* shall not disclose such Confidential Information and shall use
* it only with permission from Yuliia.
*
*/

#include "stdafx.h"
#include "task3_3.h"	/*defines prototypes of used in this file functions*/
#include <stdlib.h>
#include <string.h>


const unsigned char ERROR = 0;
const unsigned char SUCCESS = 1;
const unsigned int MAIN_SUCCESS = 0;



int main( )
{
	Interface();

	char* riadok = NULL;
	char character[2] = {0,0};
	unsigned char retCode;
	char* begin = NULL;		/*pointer to the begin of the word that include character*/
	char* end;				/*pointer to the end of the word that include character*/
	char* copy = NULL;

	retCode = Input(&riadok, character);
	if (retCode == ERROR)
	{
		printf("Error occurs while trying to input string.\n");
		return (int)ERROR;
	}

	if (riadok != NULL && strlen(riadok) != 0)
	{
		copy = (char*)malloc(strlen(riadok) * sizeof(char));
		strcpy(copy, riadok);
	}

	printf("\nWords that include character: ");
	begin = copy;
	unsigned int n = 0;
	while (begin != NULL)
	{
		end = Find(copy, &begin, character);
		if (end == NULL)
		{
			printf("\nSorry, there are no words with such character.\n");
			break;
		}
		else if (end == begin)
		{
			printf("%s;", begin);
			break;
		}
		printf("%s, ", begin);
		n += (end - copy);
		strcpy(copy, riadok + n);
	}

	printf("\n");
	free(riadok);
	system("pause");
	return MAIN_SUCCESS;
}

void Interface(void)
{
	printf("------------------------------------------------------------------\n");
	printf("Hi! Welcome to the genius character finder.\n");
	printf("Enter sentences and character and program will find for you words that include that character. \n");
	printf("Program made by Yuliia Lyubchik.\n");
	printf("------------------------------------------------------------------\n\n");
}

unsigned char Input(char** riadok, char* character)
{
	unsigned char retCode;
	do
	{
		char temp;
		int count = 0;
		printf("Please enter sentence: ");
		do
		{
			scanf("%c", &temp);

			++count;
			*riadok = (char*) realloc(*riadok, count * sizeof(char));

			if (*riadok != NULL) 
			{
				*(*riadok + count - 1) = temp;
			}
			else 
			{
				free(riadok);
				puts("Error (re)allocating memory. \n");
				return ERROR;
			}

		} 
		while (temp != '\n' && temp != EOF);
		fflush(stdin);
		*(*riadok + count - 1) = '\0';
	} 
	while (riadok == NULL || strlen(*riadok) == 0);
	
	do
	{
		printf("Please enter character that you want to find in words: ");
		retCode = scanf("%c", &(*character));
		fflush(stdin);
		if (*character >= 'A' && *character <= 'Z')
		{
			break;
		}
		else if (*character >= 'a' && *character <= 'z')
		{
			break;
		}
		else
		{
			retCode = ERROR;
		}
	} while (*character == '\n' || retCode == ERROR);

	return SUCCESS;
}

char* Find(char* sentence, char** begin, const char* character)
{
	if (sentence == NULL)
	{
		printf("Can not get access to memory. \n");
		return NULL;
	}

	char* temp;
	char* token;
	char* end = NULL;
	

	const char delimiters[] = { ' ', ',', '-', '.', ':', ';', '(', ')', '[', ']', '!', '?' };

	token = strtok(sentence, delimiters);
	while (token != NULL)
	{
		temp = strpbrk(token, character);
		if (temp != NULL)
		{
			end = strtok(NULL, delimiters);
			*begin = token;
			if (end == NULL)
			{
				end = *begin;
			}
			break;
		}
		else
		{
			token = strtok(NULL, delimiters);
		}
	}
	return end;
}
