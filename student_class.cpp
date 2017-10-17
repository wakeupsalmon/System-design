// second trial of the students class
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> // required for exit(0)
#include <iomanip> // required for setw (set width) in cout

using namespace std; 
/*******************************/// class defintion and constructors.
class Student
{
	private: // data 
	string fname;
	string lname;
	char level;
	char sex;
	int id;
	int rank; 
	double gpa;
	
	public:
	// constructors 
	Student(); // class default constructor 
	Student(string first_name,string last_name, char lv, char sx, int ID,int rnk, double GPS); // constructor for intilization,
	~Student(); // class destructor 
	
	// member functions (getters and setters , show, )
	
	// Getters 	
	string get_fname()
	{
		return fname;
	}
	
	string get_lname()
	{
		return lname;
	}
	
	char get_level()
	{
		return level;
	}
	
	char get_sex()
	{
		return sex;
	}
	
	int get_id()
	{
		return id;
	}
	
	int get_rank()
	{
		return rank;
	}
	
	double get_gpa()
	{
		return gpa;
	}
	
	// Setters 
	void set_fname(string Fname)
	{
	  fname = Fname;
	}
	
	 void set_lname(string Lname) 
	{
		lname = Lname;
	}
	
	 void set_level(char Level)
	{
		 level = Level;
	}
	
	 void set_sex(char Sex)
	{
	    sex = Sex;
	}
	
	void set_id(int ID)
	{
		id = ID;
	}
	
	 void set_rank(int Rank)
	{
		 rank = Rank;
	}
	
	 void set_gpa(double GPA)
	{
		gpa = GPA;
	}
	
	//  prints all the records in array one by one
void show() {
        // setw reserves a number of free spaces after each element
        cout << fname << setw(10) << lname << setw(10);
        cout << gpa << setw(10) << level << setw(10);
        cout << sex << setw(10) << id  << endl;
}
	
};

// Class defintions (member functions and constructors)
Student::Student()
{
	fname = " ";
	lname = " ";
	level = ' ';
	sex = ' ';
	id = 0;
	rank = 1; 
	gpa = 0.0;
}

Student::Student(string f_name, string l_name, char L, char S,int I, int R, double G )
{
	fname = f_name;
	lname = l_name;
	level = L;
	sex = S;
	id = I;
	rank = R; 
	gpa = G;
}
// class destructor
Student::~Student()
{
}

/**********************************/// reading the file as an array of objects (of type student)
Student* readRecFile(string FilePath, unsigned int& counter) {
	Student* recordsArray;
	ifstream reader;
	string First_name;
	string Last_name;
	char Level;
	char Sex;
	int Id;
	int Rank; 
	double Gpa;

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
		recordsArray = new Student[counter];
		for (int i = 0; i < counter; i++){
			// object initlization 
			recordsArray[i] = Student();  // default constructor 
            // the following line means that read the next entry from file
            // and store it in field fname of i-th index of recordsArray
            reader >> First_name;
            recordsArray[i].set_fname(First_name);
            reader >> Last_name;
            recordsArray[i].set_lname(Last_name);
            reader >> Gpa;
            recordsArray[i].set_gpa(Gpa);
            reader >> Level;
            recordsArray[i].set_level(Level);
            reader >> Sex;
            recordsArray[i].set_sex(Sex);
            reader >> Id;
            recordsArray[i].set_id(Id);
		}
	
		
	}
	
		// return pointer to first ellement of dynamic array
	return recordsArray;
}

/************************************************************/// Sorting 
// this method sorts array of student records based on gpa (Descending)
void sortGPA(Student* recordArray, unsigned int arrSize) {
    bool flag = true;

    // simple bubble sort (if you don't know it, just search for bubble sort on the Internet)
    for(int i = 1; (i < arrSize) & flag ; i++) {
        flag = false;
        for(int j = 0; j < arrSize-1; j++) {
            if(recordArray[j].get_gpa() < recordArray[j+1].get_gpa()) {
                Student temp = recordArray[j+1];
                recordArray[j+1] = recordArray[j];
                recordArray[j] = temp;
                // in cases that all elements are already sorted
                flag = true;
            }
        }
    }
    
    
}

	

int main()
{
	
	 // variable holding size of array (number of elements in file)
    unsigned int arrSize = 0;
    // a refrence to above variable
    unsigned int& counter= arrSize;

	Student* storedRecords = readRecFile("student.txt", counter);
	
   	storedRecords[0].show();
	 storedRecords[1].show();
	
	 sortGPA(storedRecords, arrSize);
	 
	 storedRecords[0].show();
	 storedRecords[1].show();
	 
	
	return 0;
}
