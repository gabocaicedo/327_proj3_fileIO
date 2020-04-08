/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"
#include <string>

using namespace std;

//trys to open filename, and return its contents in contents
//it will strip out only \n's (char return\line feed)
//returns:
//SUCCESS all worked, contents string contains all in the file
//COULD_NOT_OPEN_FILE_TO_READ contents string is cleared
int KP_FileIO::getFileContents(const std::string &filename,
		std::string &contents) {

	//contents should be empty
	contents.clear();

	//open filename
	ifstream filestream;
	filestream.open(filename, ios::in);

	if (filestream.is_open()) {
		std::string line;

		//get next line from filename and append to contents
		while (!filestream.eof()) {
			getline(filestream, line);
			contents = contents + " " + line;

		}
		filestream.close();

	} else {
		return COULD_NOT_OPEN_FILE_TO_READ;
	}
	//close file if open
	if (filestream.is_open())
		filestream.close();

	return SUCCESS;
}

//trys to open filename, and serialize  myEntryVector contents to it
//returns:
//SUCCESS all worked, filename contains myEntryVector strings
//COULD_NOT_OPEN_FILE_TO_WRITE
int KP_FileIO::writeVectortoFile(const std::string filename,
		std::vector<std::string> &myEntryVector) {

	//open 'filename' to write
	ofstream fostream;
	fostream.open(filename, ios::out);

	//if file opened, loop through vector
	if (fostream.is_open()) {

		for (std::vector<string>::iterator it = myEntryVector.begin();
				it != myEntryVector.end(); ++it) {
			fostream << *it << ' ';
		}
		fostream << '\n';
		fostream.close();
	} else {
		return COULD_NOT_OPEN_FILE_TO_WRITE;
	}

	//close output filestream
	if (fostream.is_open())
		fostream.close();

	return SUCCESS;

}

