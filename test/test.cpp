#include <iostream>
#include "../src/Tripe.h"

using namespace std;

int main ()
{
	Tripe tripe;
	tripe.initialize("pa2_test.txt");

	cout << "== Test 1: Search for \"an\" ==" << endl;
	tripe.search("an");
	cout << endl;

	cout << "== Test 2: Find minimum entry ==" << endl;
	tripe.findMin();
	cout << endl;

	cout << "== Test 3: Delete minimum entry and search for \"e\" ==" << endl;
	tripe.deleteMin();
	tripe.search("e");
	cout << endl;

	cout << "== Test 4: Find minimum entry ==" << endl;
	tripe.findMin();
	cout << endl;
}
