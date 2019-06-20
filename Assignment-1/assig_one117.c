/*file name: assig_one117.c
student: Jonathan Rochester, Sage Stainsby
student number: 964147, 390889
purpose: practice in c
date: 05-04-2017
percentage of work: 50-50*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MIN = 1, MAX = 118; // regularly used constants for the minimum and maximum input values
int first, last; // global variable for user input, used in output and collected during input function
char extras; // global variable for the users decision on printing the Lanthanum and Actinium groups

int main(int argc, char *argv[]) //main function, ties programm together and executes functions
{
	char *table[118][2] = { { "H", "1" }, { "He", "18" }, { "Li", "1" }, { "Be", "2" }, { "B", "13" }, { "C", "14" }, { "N", "15" }, { "O", "16" }, { "F", "17" }, { "Ne", "18" },
	{ "Na", "1" }, { "Mg", "2" }, { "Al", "13" }, { "Si", "14" }, { "P", "15" }, { "S", "16" }, { "Cl", "17" }, { "Ar", "18" }, { "K", "1" }, { "Ca", "2" },
	{ "Sc", "3" }, { "Ti", "4" }, { "V", "5" }, { "Cr", "6" }, { "Mn", "7" }, { "Fe", "8" }, { "Co", "9" }, { "Ni", "10" }, { "Cu", "11" }, { "Zn", "12" },
	{ "Ga", "13" }, { "Ge", "14" }, { "As", "15" }, { "Se", "16" }, { "Br", "17" }, { "Kr", "18" }, { "Rb", "1" }, { "Sr", "2" }, { "Y", "3" }, { "Zr", "4" },
	{ "Nb", "5" }, { "Mo", "6" }, { "Tc", "7" }, { "Ru", "8" }, { "Rh", "9" }, { "Pd", "10" }, { "Ag", "11" }, { "Cd", "12" }, { "In", "13" }, { "Sn", "14" },
	{ "Sb", "15" }, { "Te", "16" }, { "I", "17" }, { "Xe", "18" }, { "Cs", "1" }, { "Ba", "2" }, { "La", "-11" }, { "Ce", "-12" }, { "Pr", "-13" }, { "Nd", "-14" },
	{ "Pm", "-15" }, { "Sm", "-16" }, { "Eu", "-17" }, { "Gd", "-18" }, { "Tb", "-19" }, { "Dy", "-20" }, { "Ho", "-21" }, { "Er", "-22" }, { "Tm", "-23" }, { "Yb", "-24" },
	{ "Lu", "-25" }, { "Hf", "4" }, { "Ta", "5" }, { "W", "6" }, { "Re", "7" }, { "Os", "8" }, { "Ir", "9" }, { "Pt", "10" }, { "Au", "11" }, { "Hg", "12" },
	{ "Tl", "13" }, { "Pb", "14" }, { "Bi", "15" }, { "Po", "16" }, { "At", "17" }, { "Rn", "18" }, { "Fr", "1" }, { "Ra", "2" }, { "Ac", "-31" }, { "Th", "-32" },
	{ "Pa", "-33" }, { "U", "-34" }, { "Np", "-35" }, { "Pu", "-36" }, { "Am", "-37" }, { "Cm", "-38" }, { "Bk", "-39" }, { "Cf", "-40" }, { "Es", "-41" }, { "Fm", "-42" },
	{ "Md", "-43" }, { "No", "-44" }, { "Lr", "-45" }, { "Rf", "4" }, { "Db", "5" }, { "Sg", "6" }, { "Bh", "7" }, { "Hs", "8" }, { "Mt", "9" }, { "Ds", "10" },
	{ "Rg", "11" }, { "Cn", "12" }, { "Uut", "13" }, { "Fl", "14" }, { "Uup", "15" }, { "Lv", "16" }, { "Uus", "17" }, { "Uuo", "18" } };

	printf("Periodic Table Printer\n\n");

	extras_prompt(); // function to reference prompting the user on the choice of printing the extra elements

	user_input(); // function to collect user input for values first and last

	output(table,first,last); // function to output table with user selected values,  references table, first and last 
}

int user_input() // function to  collect user input, and change input to default when user gives input outside of acceptable parameters 
{
	printf("\nEnter number of first element to print: ");
	scanf_s("%d", &first);

	if (first < MIN || first > MAX)  // checks condition of first number input, defualts to 1
	{
		first = MIN;
		printf("...1 assumed...");
	}
	first--;

	printf("\nEnter number of last element to print: ");
	scanf_s("%d", &last);

	if (last > MAX || last < first)		// checks condition of last number input, defualts to 118
	{
		last = MAX;
		printf("...118 assumed...\n");
	}
	last--;

	return 0;
}

int output(char *table[118][2],int first,int last) // function to output table, with correct formatting and user specified parameters
{
	/*print tab spaces to first element*/
	for (int t = atoi(table[first][1]); t > 1; t--) 
	{
		printf("\t");
	}

	/*loop to output table, with tab formatting when appropriate for formatting*/
	for (int i = first; i <= last; i++)
	{
		int column;
		column = atoi(table[i][1]);

		printf("%.3d %s\t", (i + 1), table[i][0]);

		if ((i + 1) == 1)
		{
			printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
		}

		if ((i + 1) == 4)
		{
			printf("\t\t\t\t\t\t\t\t\t\t");
		}

		if ((i + 1) == 12)
		{
			printf("\t\t\t\t\t\t\t\t\t\t");
		}

		if ((i + 1) == 56)
		{
			printf("\t");
			i = 70;
		}

		if ((i + 1) == 88)
		{
			printf("\t");
			i = 102;
		}

		if (column == 18)
		{
			printf("\n");
		}
	}
	printf("\n\n");

	if (extras == 'Y' || extras == 'y')	// checks condition to print L and A
	{
		for (int j = 56; j <= 70; j++)
		{
			printf("%.3d %s\t", (j + 1), table[j][0]);
		}
		printf("\n");
		for (int k = 88; k <= 102; k++)
		{
			printf("%.3d %s\t", (k + 1), table[k][0]);
		}
	}
	printf("\n\n");
	return 0;
}

int extras_prompt() // prompt to ask the user if they would like to print extra elements and defualt to "N" when incorrect data is given
{
	printf("Print the Lanthanum/Actinium groups if necessary [Y/N]: ");
	scanf_s("%c", &extras);

	if (extras != 'Y' && extras != 'y')	// checks condition of yes
	{
		printf("...N assumed...");
	}
	return 0;
}