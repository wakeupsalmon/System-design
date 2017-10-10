#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> // required for exit(0)
#include <iomanip> // required for setw (set width) in cout

using namespace std;

// defining a new complex type to hold student records
struct stdRecord {
	string fname;
	string lname;
	char level;
	char sex;
	int id;
	double gpa;
};


stdRecord* readRecFile(string FilePath, unsigned int& counter) {
	stdRecord* recordsArray;
	ifstream reader;

	// open method of ifstream reader just accepts old fashion char* instead of string
	// therefore we used c_str method of string class to cast it to char*
	reader.open(FilePath.c_str());

	// in cases that file is not accessible or doesn't exist
	if(!reader){
		cout << "error opening" << FilePath;

		// terminate program
		exit(0);

	// normal operation of reading file
	}else {

        // reading number of records (stored in the first line of file)
		reader >> counter;

		// dynamic memory allocation to sture all recoreds
		recordsArray = new stdRecord[counter];

		for (int i = 0; i < counter; i++){
            // the following line means that read the next entry from file
            // and store it in field fname of i-th index of recordsArray
            reader >> recordsArray[i].fname;
			reader >> recordsArray[i].lname;
			reader >> recordsArray[i].gpa;
			reader >> recordsArray[i].level;
			reader >> recordsArray[i].sex;
			reader >> recordsArray[i].id;
		}
	}

	// return pointer to first ellement of dynamic array
	return recordsArray;
}

// this method sorts array of student records based on gpa (Descending)
void sortGPA(stdRecord* recordArray, unsigned int arrSize) {
    bool flag = true;

    // simple bubble sort (if you don't know it, just search for bubble sort on the Internet)
    for(int i = 1; (i < arrSize) & flag ; i++) {
        flag = false;
        for(int j = 0; j < arrSize-1; j++) {
            if(recordArray[j].gpa < recordArray[j+1].gpa) {
                stdRecord temp = recordArray[j+1];
                recordArray[j+1] = recordArray[j];
                recordArray[j] = temp;
                // in cases that all elements are already sorted
                flag = true;
            }
        }
    }
}


// prints all the records in array, one by one
void printRecArray(stdRecord* recordArray, unsigned int arrSize) {
    for(int i = 0; i < arrSize; i++) {
        // setw reserves a number of free spaces after each element
        cout << recordArray[i].fname << setw(10) << recordArray[i].lname << setw(10);
        cout << recordArray[i].gpa << setw(10) << recordArray[i].level << setw(10);
        cout << recordArray[i].sex << setw(10) << recordArray[i].id  << endl;
        if(i != arrSize-1)cout << string(55, '-') << endl;
    }

}

int main(int argc, char const *argv[])
{
    // variable holding size of array (number of elements in file)
    unsigned int arrSize = 0;
    // a refrence to above variable
    unsigned int& counter= arrSize;

    stdRecord* storedRecords = readRecFile("student.txt", counter);

    cout << "records are:" << endl;

    printRecArray(storedRecords, arrSize);

    sortGPA(storedRecords, arrSize);

    cout << endl << "records sorted by GPA are:" << endl;

    printRecArray(storedRecords, arrSize);

	char x;
	cin >> x;

	return 0;
}
