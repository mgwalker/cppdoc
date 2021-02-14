#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

/*@****************************************************************************
@CLASS		cppdocBaseClass		VOID
@CREATED	"Parallel Minds"	"11/10/2002"

@MDATA	string			public	name		"Name of the object"
@MDATA	string			public	parent		"Name of the object's parent"
@MDATA	bool			public	hasParent	"True if the object has a parent"
@MDATA	string			public	creator		"Creator's name"
@MDATA	string			public	created		"Date of creation"
@MDATA	vector<string>	public	modifiers	"List of modifiers' names"
@MDATA	vector<string>	public	modified	"List of modification dates"
@MDATA	string			public	desc		"Description of the object"
@MDATA	string			public	docObjectType	"What kind of object this is"

@DESC	"This is the base class from which the two primary cppdoc classes are
		 derived.  This class declares the member data that is common to both
		 classes."
****************************************************************************@*/
class cppdocBaseClass
{
	public:
		string name;
		string parent;
		bool hasParent;
		string creator;
		string created;
		vector<string> modifiers;
		vector<string> modified;
		string desc;
		string docObjectType;
};

/*@****************************************************************************
@CLASS		cdGlobal			cppdocBaseClass
@CREATED	"Parallel Minds"	"11/28/2002"

@MDATA	string	public	type	"Data type"

@DESC	"This class stores information about GLOBAL variable objects in cppdoc
         comments.  The class is essentially just a collection of data."
****************************************************************************@*/
class cdGlobal : public cppdocBaseClass
{
	public:
		string type;
};

/*@****************************************************************************
@CLASS		cdClass				cppdocBaseClass
@CREATED	"Parallel Minds"	"11/10/2002"

@MFUNCTION	VOID	public	cdClass	"Constructor.  Initializes the docObject
									 type to CLASS."

@MDATA	vector<string>	public	mFType		"List of member function types"
@MDATA	vector<string>	public	mFAcces		"List of member function accesses"
@MDATA	vector<string>	public	mFName		"List of member function names"
@MDATA	vector<string>	public	mFDesc		"List of member function
											 descriptions"
@MDATA	vector<string>	public	mDType		"List of member data types"
@MDATA	vector<string>	public	mDAccess	"List of member data accesses"
@MDATA	vector<string>	public	mDName		"List of member data names"
@MDATA	vector<string>	public	mDDesc		"List of member data descriptions"

@DESC	"This class stores information about CLASS objects in cppdoc comments.
		 The class is essentially just a collection of data since it contains
		 no functions, other than the constructor."
****************************************************************************@*/
class cdClass : public cppdocBaseClass
{
	public:
		cdClass(){ docObjectType = "CLASS"; }
		vector<string> mFType;
		vector<string> mFAccess;
		vector<string> mFName;
		vector<string> mFDesc;
		vector<string> mDType;
		vector<string> mDAccess;
		vector<string> mDName;
		vector<string> mDDesc;
};

/*@****************************************************************************
@CLASS		cdFunction			cppdocBaseClass
@CREATED	"Parallel Minds"	"11/10/2002"

@MFUNCTION	VOID	public	cdFunction	"Constructor.  Initializes the
										 docObject type to FUNCTION."

@MDATA	vector<string>	public	paramType	"List of parameter types"
@MDATA	vector<string>	public	paramName	"List of parameter names"
@MDATA	vector<string>	public	paramDesc	"List of parameter descriptions"
@MDATA	string			public	retType		"Function return type"
@MDATA	string			public	retDesc		"Return description"

@DESC	"This class stores information about FUNCTION objects in cppdoc
		 comments. The class is essentially just a collection of data since it
		 contains no functions, other than the constructor."
****************************************************************************@*/
class cdFunction : public cppdocBaseClass
{
	public:
		cdFunction(){ docObjectType = "FUNCTION"; }
		vector<string> paramType;
		vector<string> paramName;
		vector<string> paramDesc;
		string retType;
		string retDesc;
};

int getFlags(char* args[], int num, char& flags);
void printHelp();
void cppdocParse(vector<string>& filelist, string& outputdir, char flags);
void writeDoc(string& outputdir, char flags);
void doParse(ifstream& inFile, char flags);
string strToUpper(string inStr);
string strToLower(string inStr);
string stripHTML(string inStr);
string trim(string inStr);
void printWrap(string msg, string front);