/* 
CNIT 315
Lab 04
Testing Team

Functions to Test
􏰃Accept a string from the user.
􏰃Find the length of a string.
􏰃Count the number of vowels in a string. [Extra credits if your function uses recursion!] 􏰃 
Count the number of words in a string. [Extra credits if your function uses recursion!] 􏰃 
Determine if a character is alpha-numeric. (i.e. it lies between a-z, A-Z, or 0-9)
􏰃Create a sub-string by specifying the indices.
􏰃Concatenate two strings.
􏰃Remove a particular word from the string.


Collaborators:

	Some functions copied from lab 03
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Function : Test Find Length
Purpose: runs test on indicated function
@return
	0 - Passed All Tests
	-1 - Return Incorrect Result
	-2 - Did Not Return Result
	1 - Failed to Run
*/
int testFindLength();

/*
Function : Test Number Vowels
Purpose: runs test on indicated function
@return
	0 - Passed All Tests
	-1 - Return Incorrect Result
	-2 - Did Not Return Result
	1 - Failed to Run
*/
int testVowels();

/*
Function : Test Number Words
Purpose: runs test on indicated function
@return
	0 - Passed All Tests
	-1 - Return Incorrect Result
	-2 - Did Not Return Result
	1 - Failed to Run
*/
int testNumberWords();

/*
Function : Test Alpha Numeric Word
Purpose: runs test on indicated function
@return
	0 - Passed All Tests
	-1 - Return Incorrect Result
	-2 - Did Not Return Result
	1 - Failed to Run
*/
int testAlphaNumericWord();

/*
Function : Test Substring
Purpose: runs test on indicated function
@return
	0 - Passed All Tests
	-1 - Return Incorrect Result
	-2 - Did Not Return Result
	1 - Failed to Run
*/
int testSubString();

/*
Function : Test Concatenation 
Purpose: runs test on indicated function
@return
	0 - Passed All Tests
	-1 - Return Incorrect Result
	-2 - Did Not Return Result
	1 - Failed to Run
*/
int testConcat();

/*
Function : Test Remove Word
Purpose: runs test on indicated function
@return
	0 - Passed All Tests
	-1 - Return Incorrect Result
	-2 - Did Not Return Result
	1 - Failed to Run
*/
int testRemove();

/*
Function : generate report
Purpose: using testing functions, generate report and push out to .txt file
					specified in main input.
*/
int generateReport(char* file);



/**
 * Function: deep_copy_string()
 *
 * Duplicates the input array and stores the deep copy in the output array.
 *
 * Parameters:
 * @param array_from	The array that needs to be copied.
 * @param array_to  	The new array which will hold a deep copy of the input
 * 						array.
 * @param array_length	The length of the input array.
 *
 * Returns:
 * 	@return 	0 - Successful completion of the function.
 * 				1 - An error during operation.
 *
 * Expectations:
 * 	- All parameters are valid, i.e.:
 * 			* array_from is declared.
 *			* array_to has enough memory allocated.
 *			* array_length accurately portrays the number of elements in
 *			  array_from
 * Coppied From Lab 3
 */
void deep_copy_string(char* array_from, char* array_to, int array_length);

/**
 * Function: generate_random_string()
 *
 * Generates an integer array of specified size filled with random chars.
 *
 *
 * Parameters:
 * 	@param array 			Pointer to the char array.
 * 	@param array_length 	Number elements to be stored in the array.
 *
 * Returns:
 * 	@return 	0 - Successful.
 * 				1 - Fail/Error.
 *
 * Expectations:
 * 	- None
 * Modified From Lab 3
 */
int generate_random_string(char* array, int array_length);

int addStrings(char *array_main, char *array_add);


typedef int (*tester_function)();

struct RandomString
{
	int length;
	char *value;
};

struct TesterFunction
{
	char *name;
	tester_function function;
	
};

//Global Vars
int numArrays = 5;
struct RandomString strings[5];



int main(int argc, char *argv[])
{
	//Check to make sure arugment was included for filename
	if (argc != 2)
	{
		printf("usage : %s filename\n", argv[0]);
		return 1;
	}



	//Create some random char arrays and put inside strings array
	int i, currentArrayLength = 10;
	for (i = 0; i < numArrays; i++)
	{
		char array[currentArrayLength];
		generate_random_string_array(array,currentArrayLength);

		strings[i].value = malloc(currentArrayLength);
		strcpy(strings[i].value, array);

		strings[i].length = currentArrayLength;

		currentArrayLength *= 5;
	}

	//Generate Report and put in file specified in arugments
	generateReport(argv[1]);

	return 0;
}






int testFindLength()
{
	//Vars
	int i, strLength, strLengthResponse = NULL, returnValue;
	for (i=0; i<numArrays; i++)
	{
		strLength = strings[i].length;
		char *string = malloc(strLength);
		string = strings[numArrays].value;

		//Use Function to find length of string
		//returnValue = findLength(&strLengthResponse)

		if (returnValue != 0)
		{
			return 1;
		}
		if (strLengthResponse == NULL)
		{
			return -2;
		}
		if (strLengthResponse != strLength)
		{
			return -1;
		}

	}


	return 0;
}


int testVowels()
{
	//Vars
	int i,e,numVowels, strLength, strVowelResponse = NULL, returnValue;
	for (e=0; e<numArrays; e++)
	{
		strLength = strings[e].length;
		char *string = malloc(strLength);
		string = strings[numArrays].value;

		//Find number of vowels
		//Source -- http://www.programiz.com/c-programming/examples/vowel-consonant-frequency-string
		for(i=0;string[i]!='\0';++i) 
		{ 
			if(string[i]=='a' || string[i]=='e' || string[i]=='i' || 
			string[i]=='o' || string[i]=='u' || string[i]=='A' || 
			string[i]=='E' || string[i]=='I' || string[i]=='O' || 
			string[i]=='U') numVowels++;
		}
		//Use Function to find length of string
		//returnValue = findLength(&strVowelResponse)

		if (returnValue != 0)
		{
			return 1;
		}
		if (strVowelResponse == NULL)
		{
			return -2;
		}
		if (strVowelResponse != numVowels)
		{
			return -1;
		}

	}


	return 0;
}


int testNumberWords()
{
	//Vars
	int i,e,numWords = 0, strLength, strWordResponse = NULL, returnValue;
	for (e=0; e<numArrays; e++)
	{
		strLength = strings[e].length;
		char *string = malloc(strLength);
		string = strings[numArrays].value;

		//Find number of Words
		for(i=0;string[i]!='\0';++i) 
		{ 
			if(string[i]==' ' && i < strLength -1) 
			{
				numWords++;
			}
		}
		if (numWords > 0)
		{
			numWords++;
		}

		//Use Function to find length of string
		//returnValue = findLength(&strWordResponse)

		if (returnValue != 0)
		{
			return 1;
		}
		if (strWordResponse == NULL)
		{
			return -2;
		}
		if (strWordResponse != numWords)
		{
			return -1;
		}

	}


	return 0;
}


int testAlphaNumericWord()
{
	//Vars

	//Implement Tests Here

	return 0;
}


int testSubString()
{
	//Vars

	//Implement Tests Here

	return 0;
}


int testConcat()
{
	//Vars

	//Implement Tests Here

	return 0;
}


int testRemove()
{
	//Vars

	//Implement Tests Here

	return 0;
}


int generateReport(char* file)
{
	//Vars
	FILE *outFile;
	char *report = malloc(0*sizeof(char));
	int functionResponse, i, numFunctions = 7, numErrors = 0;
	struct TesterFunction functions[7] = {
		{"Find Length Function",&testFindLength},
		{"Find Vowels Function",&testVowels},
		{"Find Number of Words Function",&testNumberWords},
		{"Test if char is alpha-numeric",&testAlphaNumericWord},
		{"Create Substring function",&testSubString},
		{"Contatenate Function",&testConcat},
		{"Remove Word Function",&testRemove},
	};


	#define add(line) addStrings(report, line)



	//Generate Report Here
	for (i=0; i< numFunctions; i++)
	{
		printf("%d\n", i);
		//NOT WORKING CURRENTLY
		//functionResponse = functions[i].function();
		// printf("%d\n", functionResponse);
		// printf("%s\n", functions[i].name);
		//add("test");
		// switch (functionResponse)
		// {
		// case 0:
		// 	add(" function has passed all tests.\n");
		// 	break;
		// case 1:
		// 	add(" function failed to run.\n");
		// 	break;
		// case -1:
		// 	add(" function did not return the correct result");
		// 	break;
		// case -2:
		// 	add(" function did not return result");
		// }

	}


	printf("%s\n", report);


	


	//Save to specified file
	outFile = fopen(file,"w");

	if (outFile == 0)
	{
		printf("There was an error saving to the file\n");
		return 1;
	}

	fputs(report,outFile);

	fclose(outFile);

	return 0;
}




/*
Helper Functions
*/

void deep_copy_string(char* array_from, char* array_to, int array_length){
	//Read more about memcpy over here: http://www.cplusplus.com/reference/cstring/memcpy/

	memcpy(array_to, array_from, array_length * sizeof(char));
}

/*
 * Pro-tip:use this function to generate random arrays.
 */
int generate_random_string_array(char* array, int array_length){
	/* Initialize */
	int i;
	/* Validate input */
	if(!array){
		printf("Error: Input array was NULL\n");
		return 1;
	}
	if(array_length < 1){
		printf("Error: required array size < 1\n");
		return 1;
	}
	/* Generate random values */
	for (i = 0; i < array_length; i++) {

		switch (rand() % 5)
		{
			case 0:
				array[i] = 'A' + (rand() % 26);
				break;
			case 1:
				array[i] = ' ';
				break;
			default:
				array[i] = 'a' + (rand() % 26);
				break;


		}
		
	}
	return 0;
}

int addStrings(char *array_main, char *array_add)
{
	
	int length_main = strlen(array_main);
	int length_add = strlen(array_add)+1;
	//Expand Array
	char *arrayBuffer = realloc(array_main,length_main+length_add);	
	//Check if expansion was successful
	if (arrayBuffer == NULL)
	{
		printf("ERROR : There was an error processing \
			your request (addItemHandler arrayBuffer NULL)\n");
		return 1;
	}
	
	deep_copy_string(array_add, arrayBuffer + length_main*sizeof(char), length_add);
	
	array_main = arrayBuffer;
	return 0;
}







