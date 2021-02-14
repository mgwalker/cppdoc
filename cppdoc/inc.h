#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string strToUpper(string inStr);
void cppdocGen(ostream& output, string className, string classDerived, string funcName,
			   string inClass, vector<string> mFuncType,
			   vector<string> mFuncAccess, vector<string> mFuncName,
			   vector<string> mFuncDesc, vector<string> mDataType,
			   vector<string> mDataAccess, vector<string> mDataName,
			   vector<string> mDataDesc, string createdName, string createdDate,
			   vector<string> modName, vector<string> modDate,
			   vector<string> paramType, vector<string> paramName,
			   vector<string> paramDesc, string returnType, string returnDesc,
			   string overallDesc);
void cppdoc(fstream& inFile, ofstream& outFile);

