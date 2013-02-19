#include <string>
#include "Heap.h"

using namespace std;

typedef struct TrieNode TrieNode;
struct TrieNode
{
	string		prefix;
	HeapNode*	heapNode;
	bool		end;
};

class Trie
{
public:
	Trie();
	void		add(string name, HeapNode heapNode);
	void		remove(string name);
	TrieNode*	find(string prefix);
private:
};

