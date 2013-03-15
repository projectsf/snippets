/**
 * Illustrates the use of boost property tree
 *
 *
 * @file boostPropertyTree.cpp
 */

#include <string>
#include <boost/foreach.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>

using namespace boost::property_tree;
using namespace std;

int main()
{
	string propertyTreeExampleFileName("./input/three-level-nest.xml");

	ptree root;
	try
	{
		xml_parser::read_xml(propertyTreeExampleFileName, root);
	}
	catch(xml_parser::xml_parser_error& exc)
	{
		cerr << "Parsing error: " << exc.what() << endl;
		exit(-1);
	}


	//look for node
	ptree config = root.get_child("Config");
	ptree::const_assoc_iterator iter = config.find("Realm");
	if (iter == root.not_found())
	{
		cout << "Can't find it" << endl;
	}
}

