#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
	cerr << "usage: " << argv[0] << " file to be modified\n";
	return 1;
    }

    fstream in(argv[1]);

    if (!in.is_open()) {
	cerr << argv[0] << ": can't open " << argv[1] << '\n';
	return 2;
    }
    streampos position = 0;		
    for (string line; getline(in, line, 'T'); ) {
	    string temp = line.substr(0,4);
	    if (temp == "rump") {
		position -= 1;
		in.seekp(position);
		in << "Biden";

	    }
	    position = in.tellg();
	}
    in.close();
    
    
    return 0;
}

// Note that line.npos ≡ string::npos.
// It’s a static constant, part of the string class.
// It’s a number that means “Sorry, I couldn’t find that.”
