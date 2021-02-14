#include "stdinc.h"

/*@*********************************************************
@FUNCTION	strToUpper			VOID
@CREATED	"Parallel Minds"	"10/10/2002"

@PARAM		string	inStr	"String to convert to uppercase"
@RETURNS	string	"inStr, in all capital letters"

@DESC		"Converts a string to all uppercase letters."
*********************************************************@*/
string strToUpper(string inStr)
{
	// Loop once for each character in the string
	for(unsigned int i = 0; i < inStr.size(); i++)
	{
		// Temporary character array - must be two characters
		// for the string.replace function (the second is null)
		char tmpChar[2];

		// The first character in the temporary array is the
		// character at the ith position in the string.  The
		// second character is a null.
		tmpChar[0] = inStr.at(i);(inStr.substr(i, 1).c_str());
		tmpChar[1] = 0;

		// If the character is a lowercase letter, convert it
		// to uppercase by clearing the 6th bit (of 8 bits)
		if((int)tmpChar[0] > 96 && (int)tmpChar[0] < 123)
			tmpChar[0] = tmpChar[0] & 0xDF;

		// Replace the character in the input string with the
		// new character.  The character is not necessarily
		// changed, but oh well.
		inStr.replace(i, 1, tmpChar);
	}

	// Return the modified string
	return inStr;
}

/*@********************************************************
@FUNCTION	strToLower			VOID
@CREATED	"Parallel Minds"	"11/8/2002"

@PARAM		string	inStr	"String to convert to lowercase"
@RETURNS	string	"inStr, in all lowercase letters"

@DESC		"Converts a string to all lowercase letters."
********************************************************@*/
string strToLower(string inStr)
{
	// Loop once for each character in the string
	for(unsigned int i = 0; i < inStr.size(); i++)
	{
		// Temporary character array - must be two characters
		// for the string.replace function (the second is null)
		char tmpChar[2];

		// The first character in the temporary array is the
		// character at the ith position in the string.  The
		// second character is a null.
		tmpChar[0] = inStr.at(i);(inStr.substr(i, 1).c_str());
		tmpChar[1] = 0;

		// If the character is an uppercase letter, convert it
		// to lowercase by setting the 6th bit (of 8 bits)
		if((int)tmpChar[0] > 64 && (int)tmpChar[0] < 91)
			tmpChar[0] = tmpChar[0] | 0x20;

		// Replace the character in the input string with the
		// new character.  The character is not necessarily
		// changed, but oh well.
		inStr.replace(i, 1, tmpChar);
	}

	// Return the modified string
	return inStr;
}

/*@****************************************************************************
@FUNCTION	stripHTML			VOID
@CREATED	"Parallel Minds"	"11/8/2002"

@PARAM		string	inStr	"String to strip HTML from"
@RETURNS	string	"inStr with HTML stripped"

@DESC		"Strips the HTML code from a string by converting < to &lt; and
			 & to &amp;.  This ensures that < and & will be displayed properly
			 on the web when generated."
****************************************************************************@*/
string stripHTML(string inStr)
{
	unsigned int i = 0;	// Iterator

	// Loop once for each character in the string
	for(i = 0; i < inStr.size(); i++)
	{
		// If the character is an ampersand, replace it
		// with &amp;
		if(inStr.at(i) == '&')
			inStr.replace(i, 1, "&amp;");
	}
	// Loop once for each character in the string
	for(i = 0; i < inStr.size(); i++)
	{
		// If the character is a "less-than" sign, replace
		// it with &lt;
		if(inStr.at(i) == '<')
			inStr.replace(i, 1, "&lt;");
	}

	// Return the modified string
	return inStr;
}

/*@****************************************************************************
@FUNCTION	trim				VOID
@CREATED	"Parallel Minds"	"11/28/2002"

@PARAM		string	inStr	"String to remove leading and trailing spaces from"
@RETURNS	string	"inStr with leading and trailing spaces stripped"

@DESC		"Removes any leading and trailing spaces from a string.  Does
             NOT strip other whitespace."
****************************************************************************@*/
string trim(string inStr)
{
	if(inStr.substr(0,1) == " ")
		inStr = inStr.replace(0, 1, "");
	if(inStr.substr(inStr.length() - 1, 1) == " ")
		inStr = inStr.replace(inStr.length() - 1, 1, "");

	return inStr;
}

/*@****************************************************************************
@FUNCTION	printWrap			VOID
@CREATED	"Parallel Minds"	"11/28/2002"

@PARAM		string	msg		"The string to print"
@PARAM		string	front	"What to append to each line of the message"
@RETURNS	VOID

@DESC		"Prints a string with word-wrapping, and appends each line with
             the string specified in front.  The length of front is taken
			 into account when calculating the string length."
****************************************************************************@*/
void printWrap(string msg, string front)
{
	for(unsigned int i = 0; i < msg.length(); i)
	{
		int backoff = 80 - front.length() - 2;
		if(i + backoff < msg.length())
		{
			while(msg.at(i + backoff) != ' ')
				backoff--;
		}

		cout << front << trim(msg.substr(i, backoff)) << endl;
		i += backoff;
	}
}
