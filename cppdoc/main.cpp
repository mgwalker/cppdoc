#include "inc.h"

void main(int argc, char* argv[])
{
	// Input and output path and filename
	string filename;
	string outputFile;

	// If there are two or more arguments, the second
	// is the input filename.  Otherwise prompt the user.
	if(argc >= 2)
		filename = argv[1];
	else
	{
		cout << "Enter the path/filename: ";
		cin >> filename;
	}

	// Get the filename portion and store it in fn
	int lastSlash = -1;
	int ls = filename.find("\\",0);
	while(ls != string::npos)
	{
		lastSlash = ls;
		ls = filename.find("\\",ls + 1);
	}
	string fn = filename.substr(lastSlash + 1, filename.size() - lastSlash - 1);

	// If there are three or more arguments, the third
	// is the output filename.  Otherwise prompt the user.
	if(argc >= 3)
		outputFile = argv[2];
	else
	{
		cout << "Please enter the path/filename for the cppdoc output for " << fn << ":\n";
		cin >> outputFile;
	}

	// Show the user the input filename and output filename/path
	cout << "Writing cppdoc information from " << fn << " to " << outputFile << "..." << endl;

	// Open the input and output files
	ofstream outFile(outputFile.c_str(),ios::ate);
	fstream	inFile(filename.c_str());

	// Make sure the input file exists
	if(!inFile)
	{
		cout << "No such file." << endl;
		exit(0);
	}

	if(!outFile)
	{
		cout << "Invalid output file." << endl;
		exit(0);
	}

	// Generate the cppdoc
	cppdoc(inFile, outFile);

	// Close the input and output files
	inFile.close();
	outFile.close();

	// Tell the user that everything is finished.
	cout << "Finished." << endl;
}

