#include <string>
#include "formula_class.h"
#include "parse.h"

using namespace std;


#ifndef _subinverter_h_
#define _subinverter_h_


// class Adder - inheritance from Formula
class Subinverter: public Formula
{   
    public:

    // flags stating if the first or second operand is a variable
    int op1var;

	//----------------------------------------------------------
	// constructor that specifies the character string representing the formula
	// and creates the formula object and all the subformulas within
	// input 
	// pointer to the string representing the formula 
	// pointer to an array of Variable classes that are used within the Formula
    //Adder(string fstr1, string fstr2, Variable* vararray, int numvar, string opsigns);

	// constructor using function parse()
	Subinverter(string fstr1, Variable* vararray, int numvar, string opsigns, int ndepth, int &index)
	{
		find = ++index;
		// create the first and second operand using the parse f-n
		op1 = parse(fstr1, vararray, numvar, opsigns, op1var, ndepth+1, index);
		// 
		op2 = NULL; //parse(fstr2, vararray, numvar, opsigns, op1var);
		val = 0;
		fstr = "-" + fstr1;
		depth = ndepth;
		fstrop1 = fstr;
		fopsign = "-";

	}

	Subinverter(string fstr1, int ndepth, int ind)
	{
		find = ind;
		// create the first and second operand using the parse f-n
		op1 = NULL;
		// 
		op2 = NULL; //parse(fstr2, vararray, numvar, opsigns, op1var);
		val = 0;
		fstr = "-" + fstr1;
		depth = ndepth;
		fstrop1 = fstr;
		fopsign = "-";

	}
	~Subinverter()
	{
		if (op1var == 0) delete op1;
		//if (op2var == 0) delete op2;
	}

	// method evaluate
	int Evaluate()
	{
		val =  - op1->Evaluate();
		return val;
	}

	int Print(ostream &fs)
	{
		int a;
		
		fs<<"depth "<<depth<<" Sign inverter "<<find<<" ; "<<fstr<<";   value = "<<val<<"."<<endl;
		
		if (op1var==0)
		{
			a = op1->Print(fs);
		}
		else
		{
			a = op1->Print(fs, depth+1);
		}

		//a = op2->Print(fs);
		return 0;
	}
};


//int findopsign(string fstr, string& fstr1, string& fstr2, string& foundsign, string opsigns);
//Variable* findvar(string fstri, Variable* vararray, int numvar);

#endif
