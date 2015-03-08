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
*/
#include <stdio.h>

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




int main()
{
	//Vars
	char *file;
	
	//Get File from input

	generateReport(file);
	

	return 0;
}






int testFindLength()
{
	//Vars

	//Implement Tests Here

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













