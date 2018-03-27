using namespace std;

#include <string>
#include <sstream>

class ReverseICS 
{
	/* reverse int-char-string */
public:
	int int2char(int &in, char &out) {
		out = in + '0';
		return 0;
	}
	int char2int(char &in, int &out) {
		out = in - '0';
		return 0;
	}

	int str2charp(string &in, char *out) {
		if (0) {
			strcpy_s(out, in.size(), in.c_str());
		}
		else {
			stringstream ss;
			ss << in;
			ss >> out;
		}
		return 0;
	}

	int str2char(string &in, char &out) {
		stringstream ss;
		ss << in;
		ss >> out;
		return 0;
	}

	int charp2str(char *in, string &out) {
		out = in;
		return 0;	
	}
};

int main() {
	ReverseICS re = ReverseICS();
	int i = 8;
	char c ;
	string s = { "hello" };
	re.str2char(s, c);
	return 0;
}