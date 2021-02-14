#include "inc.h"

string strToUpper(string inStr)
{
	for(int i = 0; i < inStr.size(); i++)
	{
		if(inStr.substr(i, 1) == "a")
			inStr.replace(i, 1, "A");
		else if(inStr.substr(i, 1) == "b")
			inStr.replace(i, 1, "B");
		else if(inStr.substr(i, 1) == "c")
			inStr.replace(i, 1, "C");
		else if(inStr.substr(i, 1) == "d")
			inStr.replace(i, 1, "D");
		else if(inStr.substr(i, 1) == "e")
			inStr.replace(i, 1, "E");
		else if(inStr.substr(i, 1) == "f")
			inStr.replace(i, 1, "F");
		else if(inStr.substr(i, 1) == "g")
			inStr.replace(i, 1, "G");
		else if(inStr.substr(i, 1) == "h")
			inStr.replace(i, 1, "H");
		else if(inStr.substr(i, 1) == "i")
			inStr.replace(i, 1, "I");
		else if(inStr.substr(i, 1) == "j")
			inStr.replace(i, 1, "J");
		else if(inStr.substr(i, 1) == "k")
			inStr.replace(i, 1, "K");
		else if(inStr.substr(i, 1) == "l")
			inStr.replace(i, 1, "L");
		else if(inStr.substr(i, 1) == "m")
			inStr.replace(i, 1, "M");
		else if(inStr.substr(i, 1) == "n")
			inStr.replace(i, 1, "N");
		else if(inStr.substr(i, 1) == "o")
			inStr.replace(i, 1, "O");
		else if(inStr.substr(i, 1) == "p")
			inStr.replace(i, 1, "P");
		else if(inStr.substr(i, 1) == "q")
			inStr.replace(i, 1, "Q");
		else if(inStr.substr(i, 1) == "r")
			inStr.replace(i, 1, "R");
		else if(inStr.substr(i, 1) == "s")
			inStr.replace(i, 1, "S");
		else if(inStr.substr(i, 1) == "t")
			inStr.replace(i, 1, "T");
		else if(inStr.substr(i, 1) == "u")
			inStr.replace(i, 1, "U");
		else if(inStr.substr(i, 1) == "v")
			inStr.replace(i, 1, "V");
		else if(inStr.substr(i, 1) == "w")
			inStr.replace(i, 1, "W");
		else if(inStr.substr(i, 1) == "x")
			inStr.replace(i, 1, "X");
		else if(inStr.substr(i, 1) == "y")
			inStr.replace(i, 1, "Y");
		else if(inStr.substr(i, 1) == "z")
			inStr.replace(i, 1, "Z");
	}
	return inStr;
}