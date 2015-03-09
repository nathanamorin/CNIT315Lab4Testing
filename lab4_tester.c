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
Function : Test Alpha Numeric Char
Purpose: runs test on indicated function
@return
	0 - Passed All Tests
	-1 - Return Incorrect Result
	-2 - Did Not Return Result
	1 - Failed to Run
*/
int testAlphaNumericWor();

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
 * Function: deep_copy_array()
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
void deep_copy_array(int* array_from, int* array_to, int array_length);

/**
 * Function: generate_random_string_array()
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




struct RandomString
{
	int length;
	char *value;
};

//Global Vars
int numArrays = 5;
struct RandomString strings[5];



int main()
{
	//Vars
	char *file;

	//Create some random arrays
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



	
	//Get File from input

	//Generate Report
	//generateReport(file);
	testFindLength();



	

	return 0;
}






int testFindLength()
{
	//Vars
	int i, strLength, strLengthResponse = NULL, returnValue;
	for (i=0; i<numArrays; i++)
	{
		strLength = strings[numArrays].length;
		char string[strLength] = strings[numArrays].value;

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
		
		return 0;

	}


	return 0;
}


int testVowels()
{
	//Vars

	//Implement Tests Here

	return 0;
}


int testNumberWords()
{
	//Vars

	//Implement Tests Here

	return 0;
}


int testAlphaNumericWor()
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
	char *report;


	//Generate Report Here
	


	//Save to specified file
	outFile = fopen(file,"w");

	if (outFile == NULL)
	{
		printf("There was an error saving to the file\n");
	}

	fputs(report,outFile);

	fclose(outFile);

	return 0;
}




/*
Helper Functions
*/

void deep_copy_array(int* array_from, int* array_to, int array_length){
	//Read more about memcpy over here: http://www.cplusplus.com/reference/cstring/memcpy/
	memcpy(array_to, array_from, array_length * sizeof(int));
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








