#include "elements.h"
#include <sstream>

elements::elements()
{
	sum = "";
	s += "";
}

elements::elements(const char* cadena)
{
	std::ostringstream tmp;
	int sum=0;
	s+= cadena;	
	for (int i=0; i<s.length();i++)
		sum+= (int) s[i];
        tmp << sum;
	this->sum = tmp.str();
}


elements::elements(const elements &copyin)   // Copy constructor to handle pass by value.
{                             
   sum = copyin.sum;
   s = copyin.s;
}

ostream &operator<<(ostream &output, const elements &bbb)
{
   output << "Hash: " << bbb.sum << " Cadena:" << bbb.s << endl;
   return output;
}

elements& elements::operator=(const elements &rhs)
{
   this->sum = rhs.sum;
   this->s = rhs.s;
   return *this;
}

int elements::operator==(const elements &rhs) const
{
   if( this->sum != rhs.sum) return 0;
   if( this->s != rhs.s) return 0;
   return 1;
}

// This function is required for built-in STL list functions like sort
// o para containers de tipo ordinal como <set>

int elements::operator<(const elements &rhs) const
{
   if( this->sum == rhs.sum && this->s < rhs.s) return 1;
   if( this->sum < rhs.sum ) return 1;
   return 0;
}

elements::~elements()
{
}

