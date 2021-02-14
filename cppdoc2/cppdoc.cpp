/*@****************************************************************************
@PROJECT	"cppdoc"	0.1.a
@COPY		2002		"Parallel Minds"

@DESC		"cppdoc generates HTML documentation from C++ (or other
             plain-text source files) that make use of the cppdoc commenting
			 convention."
****************************************************************************@*/
#include "stdinc.h"

string slash;

/*@****************************************************************************
@DATA	string	inputFilelist	"List of input files, separated by commas"
@DATA	string	sourceDir		"Source directory where input files are"
****************************************************************************@*/
string	inputFilelist;	//List of input files, separated by commas
string	sourceDir;		//Source directory where files are

/*@****************************************************************************
@FUNCTION	main				VOID
@CREATED	"Parallel Minds"	"11/10/2002"

@PARAM		int		argc	"Number of command-line parameters"
@PARAM		char*	argv[]	"Command-line arguments"
@RETURNS	VOID

@DESC	"cppdoc driver function"
****************************************************************************@*/
void main(int argc, char* argv[])
{
	slash = "/";
	#ifdef WIN32
		slash = "\\";
	#endif

	string			outputDir;		//Output directory
	vector<string>	inputFilenames;	//Vector of input files
	char			flags = 0;		//Flags byte
	int				switches;		//Number of command-line switches

	/*********************************
	* The flags variable is a        *
	* collection of one-bit flags,   *
	* bit-significance listed here   *
	*                                *
	* BITS                           *
	*   0 - batch cppdoc             *1
	*   1 - no CSS                   *2
	*   2 - user-specified CSS       *4
	*   3 - source directory         *8
	*   4 - disable frames           *10
	*   5 - UNUSED                   *20
	*   6 - UNUSED                   *40
	*   7 - help                     *80
	*********************************/

	switches = getFlags(argv, argc, flags);

	if((flags & 0x80) != 0)
	{
		printHelp();
		exit(0);
	}

	if((flags & 0x04) != 0)
		switches++;
	if((flags & 0x08) != 0)
		switches++;

	// If the file list is supplied in the command line, use it; otherwise,
	// prompt the user
	if(argc >= switches + 2 && inputFilelist.length() == 0)
		inputFilelist = argv[switches + 1];
	else if(inputFilelist.length() == 0)
	{
		cout << "Input files (for multiple files, separate with commas,"
			 << " no spaces):\n";
		cin >> inputFilelist;
	}

	// If the output directory is supplied in the command line, use it;
	// otherwise, prompt the user
	if(argc >= switches + 3)
		outputDir = argv[switches + 2];
	else
	{
		cout << "Output directory: ";
		cin >> outputDir;
	}
	
	// Split the input file list into individual file names
	// and put them into a vector
	while(inputFilelist.find(",") < inputFilelist.size())
	{
		int pos = inputFilelist.find(",");
		int sze = inputFilelist.size() - pos;
		
		inputFilenames.push_back(sourceDir + inputFilelist.substr(0, pos));
		inputFilelist = inputFilelist.substr(pos + 1, sze);
	}
	// Push the last filename
	inputFilenames.push_back(sourceDir + inputFilelist);

	// Parse the files
	cppdocParse(inputFilenames, outputDir, flags);
}

int getFlags(char* args[], int num, char& flags)
{
	string tmp, flag;
	int ret = 0;
	for(int i = 1; i < num; i++)
	{
		tmp = args[i];
		if(tmp.substr(0, 1) == "-")
		{
			flag = strToUpper(tmp);

			if(flag == "-B")
			{
				flags |= 0x01;
				ret++;

				ifstream inFile(args[i + 1]);

				if(!inFile)
				{
					cout << "Batch file not found." << endl;
					exit(0);
				}

				string tmpStr;
				while(!inFile.eof())
				{
					inFile >> tmpStr;
					if(inputFilelist.length() > 0)
						inputFilelist += ",";
					inputFilelist += tmpStr;
				}
				inFile.close();
			}
			if(flag == "-NOCSS")
			{
				flags |= 0x02;
				ret++;
			}
			if(flag == "-CSS")
			{
				flags |= 0x04;
				ret++;
			}
			if(flag == "-F")
			{
				flags |= 0x08;

				sourceDir = args[i + 1];
				if(sourceDir.at(sourceDir.length() - 1) != slash.at(0))
					sourceDir += slash;
				ret++;
			}
			if(flag == "-NOFRAMES")
			{
				flags |= 0x10;
				ret++;
			}
			if(flag == "-HELP")
			{
				flags |= 0x80;
				ret++;
			}
		}
		else if(tmp == "?")
		{
			flags |= 0x80;
			ret++;
		}
	}
	return ret;
}
void printHelp()
{
	string msg = "Generates cppdoc for the file or files from the input file section. ";
	msg += "Multiple files in the list should be separated by a comma.  If the ";
	msg += "files are not in the current working directory, the source directory ";
	msg += "should be appended to each filename in the list, unless you use the ";
	msg += "-f option.  cppdoc HTML files are stored in the specified output directory.";

	string options[6];
	int numOpts = 6;
	options[0]  = "-b <file> - Batch file processing.  The <file> should be in plain ";
	options[0] += "text with one input file per line.";
		
	options[1]  = "-f <source directory> - Set the source input directory.  All input ";
	options[1] += "files are assumed to be in the current working directory unless ";
	options[1] += "otherwise specified.  This allows you to set the source directory ";
	options[1] += "all files without having to explicitly specify it for each file.";

	options[2]  = "-css <file> - Use your own CSS document for the cppdoc.  CAUTION: ";
	options[2] += "If you specify a path, it will be included in all of the generated ";
	options[2] += "HTML files.";

	options[3]  = "-nocss - Disable stylesheets.  This option will prevent the ";
	options[3] += "external stylesheets from being linked into the generated HTML files.";

	options[4]  = "-noframes - Disable frames in the generated HTML files.";

	options[5]  = "-help (or ?) - View this help information.";

	cout << "\n   Usage: cppdoc [-<options>] <input file(s)> <output directory>\n\n";

	printWrap(msg, "   ");

	cout << "\n   OPTIONS:\n";
	for(int i = 0; i < numOpts; i++)
	{
		if(i > 0)
			cout << endl;
		printWrap(options[i], "      ");
	}
}