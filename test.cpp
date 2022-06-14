#include <iostream>
#include "stringtool.hpp"

using namespace std;

int main() {

	string sample = "		  this apple is the second apple test statment is invoking.   ";
	
	printf("'%s' (Trim) --> '%s'\n", sample.c_str(), st_Trim(sample).c_str());
	sample = st_Trim(sample);

	string upper = st_UpperCase(sample);
	string lower = st_LowerCase(sample);
	printf("%s uppercase --> %s\n", sample.c_str(), upper.c_str());
	printf("%s lowercase--> %s\n", sample.c_str(), lower.c_str());

	printf("Does [%s] start with 'This'? %s\n", sample.c_str(), (st_StartsWith(sample, "This") ? "Yes" : "No"));
	printf("Does [%s] end with 'king.'? %s\n", sample.c_str(), (st_EndsWith(sample, "king.") ? "Yes" : "No"));
	printf("Does [%s] contain 'is'? %s\n", sample.c_str(), (st_Contains(sample, "is") ? "Yes" : "No"));

	int io = st_IndexOf(sample, "is");
	printf("Index Of 'is' --> '%s'\n", sample.substr(io).c_str());

	io = st_LastIndexOf(sample, "apple");
	printf("Last Index Of 'apple' --> '%s'\n", sample.substr(io).c_str());

	printf("%s --> %s\n", sample.c_str(), st_ReplaceAll(sample, "apple", "straberry").c_str());

	return 0;
}