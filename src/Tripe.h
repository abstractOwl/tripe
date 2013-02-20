#ifndef TRIPE_H
#define TRIPE_H

#include <string>
#include "Heap.h"
#include "Trie.h"

using namespace std;

class Tripe
{
public:
	Tripe();
	void initialize(string filename);
	void insert(string name, int grade);
	void print(TrieNode* node);
	void search(string prefix);
	void findMin();
	void deleteMin();
	void printTrie();
private:
	Heap heap;
	Trie trie;

	void print(TrieNode node);
};

#endif

