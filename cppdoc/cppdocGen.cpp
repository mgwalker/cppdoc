#include "inc.h"

void cppdocGen(ostream& output, string className, string classDerived, string funcName,
			   string inClass, vector<string> mFuncType,
			   vector<string> mFuncAccess, vector<string> mFuncName,
			   vector<string> mFuncDesc, vector<string> mDataType,
			   vector<string> mDataAccess, vector<string> mDataName,
			   vector<string> mDataDesc, string createdName, string createdDate,
			   vector<string> modName, vector<string> modDate,
			   vector<string> paramType, vector<string> paramName,
			   vector<string> paramDesc, string returnType, string returnDesc,
			   string overallDesc)
{
	cout << "Generating and writing cppdoc block...";
	int i;
	if(className != "")
	{
		output << "<h2><i>" << className << "</i> class";
		if(strToUpper(classDerived) != "VOID")
			output << " (derived from <i>" << classDerived << "</i>";
		output << "</h2>" << endl;
		output << "<p class=\"l1\">" << endl;
	}


	if(funcName != "")
	{
		output << "<h2>Function: <i>" << funcName << "</i>";
		if(strToUpper(inClass) != "VOID")
			output << " - Class <i>" << inClass << "</i>";
		output << "</h2>" << endl;

		output << "<p class=\"l1\"><i>";

		output << returnType << " " << funcName << "(";
		for(i = 0; i < paramName.size(); i++)
		{
			if(i != 0)
				output << ", ";
			output << paramType[i] << " " << paramName[i];
		}
		output << ")</i><br><br>" << endl;
	}

	output << overallDesc << "<br>" << endl;


	if(createdName != "")
	{
		output << "Created by ";
		output << createdName << " (" << createdDate << ")" << endl;
	}

	output << "<br>" << endl;


	for(i = 0; i < modName.size(); i++)
	{
		output << "Modified by ";
		output << modName[i] << " (" << modDate[i] << ")<br>" << endl;
	}

	for(i = 0; i < mFuncName.size(); i++)
	{
		if(i == 0)
		{
			output << "<h3 class=\"params\">Member Functions</h3>\n";
			output << "<p class=\"l2\">" << endl;
		}

		output << mFuncAccess[i] << " " << mFuncType[i] << " " << mFuncName[i];
		output << " - " << mFuncDesc[i] << "<br>" << endl;
	}
	if(mFuncName.size() > 0)
		output << "</p>" << endl;


	for(i = 0; i < paramName.size(); i++)
	{
		if(i == 0)
		{
			output << "<h3 class=\"params\">Parameters</h3>" << endl;
			output << "<p class=\"l2\">" << endl;
		}

		output << paramType[i] << " " << paramName[i];
		output << " - " << paramDesc[i] << "<br>" << endl;
	}
	if(paramName.size() > 0)
		output << "</p>" << endl;


	for(i = 0; i < mDataName.size(); i++)
	{
		if(i == 0)
		{
			output << "<h3 class=\"params\">Member Data</h3>" << endl;
			output << "<p class=\"l2\">" << endl;
		}

		output << mDataAccess[i] << " " << mDataType[i] << " " << mDataName[i];
		output << " - " << mDataDesc[i] << "<br>" << endl;
	}
	if(mDataName.size() > 0)
		output << "</p>" << endl;

	if((strToUpper(returnType) != "VOID" && returnType != "") && funcName != "")
	{
		output << "<h3 class=\"params\">Returns</h3>";
		
		output << "<p class=\"l2\">" << returnType;
		output << " - " << returnDesc << "</p>" << endl;
	}
	else if(funcName != "")
	{
		output << "<h3 class=\"params\">Returns</h3>";		
		output << "<p class=\"l2\"><i>none</i></p>" << endl;
	}

	output << "</p>" << endl;

	cout << "Done" << endl;
}
