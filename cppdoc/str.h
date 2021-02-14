#include <iostream>
using namespace std;

#ifndef STR_JPGW_CLASS
#define STR_JPGW_CLASS

class Str
{
	public:
		Str();
		Str(char *_in)
		{
			int i = 0;
			int len = 0;

			while(_in[i] != 0)
				i++;

			len = i + 1;
			_chrArr = new char[len];

			for(i = 0; i < len; i++)
				_chrArr[i] = _in[i];
		}
		~Str()
		{
			delete(_chrArr);
		}

		int length()
		{
			int i = 0;
			while(_chrArr[i] != 0)
				i++;

			return i;
		}

		Str& operator= (char *_newStr)
		{
			int i = 0;
			int len = 0;

			while(_newStr[i] != 0)
				i++;

			len = i + 1;
			_chrArr = new char[len];

			for(i = 0; i < len; i++)
				_chrArr[i] = _newStr[i];

			return *this;
		}

		friend ostream& operator<<(ostream& out, Str& _printStr)
		{
			out << _printStr._chrArr;
			return out;
		}

		friend istream& operator>>(istream& in, Str& _inStr)
		{
			in >> _inStr._chrArr;
			return in;
		}

		friend bool operator==(Str& _lhs, Str& _rhs)
		{
			int llen = _lhs.length();
			int rlen = _rhs.length();

			if(llen != rlen)
				return false;
			else
			{
				for(int i = 0; i < llen; i++)
					if(_lhs._chrArr[i] != _rhs._chrArr[i])
						return false;
			}

			return true;
		}

		friend bool operator==(Str& _lhs, char* _crhs)
		{
			Str _rhs(_crhs);
			return (_lhs == _rhs);
		}

	private:
		char *_chrArr;
};

#endif