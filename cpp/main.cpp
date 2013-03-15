#include <string>
#include <stdint.h>
#include <boost/lexical_cast.hpp>
#include <fstream>

using namespace std;
using namespace boost;

int main()
{
	string pppConfFileName("./input/ppp.conf");
	fstream pppConfFile("./input/ppp.conf");

    while (!pppConfFile.eof())
    {
        string keyValuePair;
        getline(pppConfFile, keyValuePair);
		string delimiter("=");
        string::size_type index = keyValuePair.find(delimiter);
        if (index != string::npos)
        {
            string key(keyValuePair.substr(0, index));
            string value(keyValuePair.substr(index + 1, keyValuePair.size() - 1));
			cout << "Key: " << key << ", Value: " << value << endl;
        }
    }
	pppConfFile.clear();

	//write out new attributes to file
	pppConfFile.seekp(0, ios::beg);
	pppConfFile << "What's up dog?" << endl; 
}

