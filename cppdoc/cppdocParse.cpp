#include "inc.h"

void cppdoc(fstream& inFile, ofstream& outFile)
{
	cout << "Parsing cppdoc information..." << endl;
	string html;
	string css = "";

	fstream cssExt("cppdoc.css");
	if(!cssExt)
	{
		css  = "body { background-color: #000000; font-family: arial; }\n";
		css += "h2 { background-color: #CFCFCF; margin-top: 0px; ";
		css += "border-bottom: 1px solid black; }\n";
		css += "div.box { background-color: #FFFFFF; border: 1px solid black; padding-bottom: 10px; }\n";
		css += "h3.params {margin-left: 30px; margin-bottom: 0px; }\n";
		css += "p.body { margin-left: 50px; margin-top: 0px; margin-bottom: 0px; }\n";
	}
	else
	{
		string tmpCss;
		while(!cssExt.eof())
		{
			cssExt >> tmpCss;
			css += tmpCss + " ";
		}
	}
	html =  "<html><head>\n\t<title>cppdoc</title>\n\t";
	html += "<style type=\"text/css\">\n\t\t<!--\n";
	html += css;
	html += "\n\t\t-->\n\t</style>\n</head>\n<body>\n";
	outFile << html;

	outFile << "<table width=\"75%\" align=\"center\">\n<tr><td>" << endl;

	string directive;
	bool cppdocBlock = false;

	////////////////////
	string className;
	string classDerived;
	string funcName;
	string inClass;
	
	vector<string> mFuncType;
	vector<string> mFuncAccess;
	vector<string> mFuncName;
	vector<string> mFuncDesc;

	vector<string> mDataType;
	vector<string> mDataAccess;
	vector<string> mDataName;
	vector<string> mDataDesc;

	string createdName;
	string createdDate;
	vector<string> modName;
	vector<string> modDate;

	vector<string> paramType;
	vector<string> paramName;
	vector<string> paramDesc;

	string returnType;
	string returnDesc;

	string overallDesc;
	////////////////////

	while(!inFile.eof())
	{
		inFile >> directive;
		if(directive.substr(0,3) == "/*@")
		{
			mFuncType.clear();
			mFuncAccess.clear();
			mFuncName.clear();
			mFuncDesc.clear();

			mDataType.clear();
			mDataAccess.clear();
			mDataName.clear();
			mDataDesc.clear();

			modName.clear();
			modDate.clear();

			paramType.clear();
			paramName.clear();
			paramDesc.clear();

			cppdocBlock = true;
			while(!inFile.eof() && cppdocBlock)
			{
				inFile >> directive;
				if(directive.substr(0,1) == "@")
				{
					directive = strToUpper(directive);

					if(directive == "@CLASS")
					{
						inFile >> className;
						inFile >> classDerived;
					}
					else if(directive == "@FUNCTION")
					{
						inFile >> funcName;
						inFile >> inClass;
					}
					else if(directive == "@MFUNCTION")
					{
						string type;
						string access;
						string name;
						string desc;
						string tmp;

						inFile >> type;
						inFile >> access;
						inFile >> name;
						inFile >> tmp;
						desc = tmp;
						while(tmp.substr(tmp.size() - 1, 1) != "\"")
						{
							inFile >> tmp;
							desc = desc + " " + tmp;
						}
						if(desc.size() > 2)
							desc = desc.substr(1, desc.size() - 2);
						else
							desc = "";

						mFuncType.push_back(type);
						mFuncAccess.push_back(access);
						mFuncName.push_back(name);
						mFuncDesc.push_back(desc);
					}
					else if(directive == "@MDATA")
					{
						string type;
						string access;
						string name;
						string desc;
						string tmp;

						inFile >> type;
						inFile >> access;
						inFile >> name;
						inFile >> tmp;
						desc = tmp;
						while(tmp.substr(tmp.size() - 1, 1) != "\"")
						{
							inFile >> tmp;
							desc = desc + " " + tmp;
						}
						if(desc.size() > 2)
							desc = desc.substr(1, desc.size() - 2);
						else
							desc = "";

						mDataType.push_back(type);
						mDataAccess.push_back(access);
						mDataName.push_back(name);
						mDataDesc.push_back(desc);
					}
					else if(directive == "@CREATED")
					{
						string tmp;

						inFile >> tmp;
						createdName = tmp;
						while(tmp.substr(tmp.size() - 1, 1) != "\"")
						{
							inFile >> tmp;
							createdName = createdName + " " + tmp;
						}
						if(createdName.size() > 2)
							createdName = createdName.substr(1, createdName.size() - 2);
						else
							createdName = "";

						inFile >> tmp;
						createdDate = tmp;
						while(tmp.substr(tmp.size() - 1, 1) != "\"")
						{
							inFile >> tmp;
							createdDate = createdDate + " " + tmp;
						}
						if(createdDate.size() > 2)
							createdDate = createdDate.substr(1, createdDate.size() - 2);
						else
							createdDate = "";
					}
					else if(directive == "@MODIFIED")
					{
						string mName;
						string mDate;
						string tmp;

						inFile >> tmp;
						mName = tmp;
						while(tmp.substr(tmp.size() - 1, 1) != "\"")
						{
							inFile >> tmp;
							mName = mName + " " + tmp;
						}
						if(mName.size() > 2)
							mName = mName.substr(1, mName.size() - 2);
						else
							mName = "";

						inFile >> tmp;
						mDate = tmp;
						while(tmp.substr(tmp.size() - 1, 1) != "\"")
						{
							inFile >> tmp;
							mDate = mDate + " " + tmp;
						}
						if(mDate.size() > 2)
							mDate = mDate.substr(1, mDate.size() - 2);
						else
							mDate = "";

						modName.push_back(mName);
						modDate.push_back(mDate);
					}
					else if(directive == "@PARAM")
					{
						string type;
						string name;
						string desc;
						string tmp;

						inFile >> type;
						inFile >> name;

						inFile >> tmp;
						desc = tmp;
						while(tmp.substr(tmp.size() - 1, 1) != "\"")
						{
							inFile >> tmp;
							desc = desc + " " + tmp;
						}
						if(desc.size() > 2)
							desc = desc.substr(1, desc.size() - 2);
						else
							desc = "";

						paramName.push_back(name);
						paramType.push_back(type);
						paramDesc.push_back(desc);
					}
					else if(directive == "@RETURNS")
					{
						string tmp;

						inFile >> returnType;

						inFile >> tmp;
						returnDesc = tmp;
						while(tmp.substr(tmp.size() - 1, 1) != "\"")
						{
							inFile >> tmp;
							returnDesc = returnDesc + " " + tmp;
						}
						if(returnDesc.size() > 2)
							returnDesc = returnDesc.substr(1, returnDesc.size() - 2);
						else
							returnDesc = "";
					}
					else if(directive == "@DESC")
					{
						string tmp;

						inFile >> tmp;
						overallDesc = tmp;
						string lstTwo = tmp.substr(tmp.size() - 2, 2);
						while(lstTwo == "\\\"" || lstTwo.substr(1,1) != "\"")
						{
							inFile >> tmp;
							if(tmp.size() > 1)
								lstTwo = tmp.substr(tmp.size() - 2, 2);
							else
								lstTwo = "  ";

							if(tmp.substr(0,2) == "\\\"")
								tmp = tmp.substr(1, tmp.size() - 1);
							if(lstTwo == "\\\"")
								tmp = tmp.substr(0, tmp.size() - 2) + "\"";
							overallDesc = overallDesc + " " + tmp;
						}
						if(overallDesc.size() > 2)
							overallDesc = overallDesc.substr(1, overallDesc.size() - 2);
						else
							overallDesc = "";
					}
				}
				if(directive.size() > 2)
				{
					if(directive.substr(directive.size() - 3, 3) == "@*/")
					{
						cppdocBlock = false;
						//cout << "cppdoc block end" << endl;
					}
				}//if(directive.size() > 2)
			}//while
			/* */
			outFile << "\n<div class=\"box\">\n";
			cppdocGen(outFile, className, classDerived, funcName, inClass, mFuncType,
				      mFuncAccess, mFuncName, mFuncDesc, mDataType, mDataAccess,
					  mDataName, mDataDesc, createdName, createdDate, modName,
					  modDate, paramType, paramName, paramDesc, returnType,
					  returnDesc, overallDesc);//*/
			outFile << "\n</div><br>\n";
			outFile << endl;
		}//if
	}//while

	outFile << "\n</td></td>\n</table>\n</body></html>";
	cout << "Parsing finished.  Output file completed." << endl;
}