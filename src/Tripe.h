#include <string>
#include "Trie.h"

using namespace std;

class Tripe
{
public:
	void initialize(string filename);
	void insert(string name, int grade);
	void search(string prefix);
	void findMin();
private:
	Heap heap;
	Trie trie;
};

