#ifndef TRIE_H
#define TRIE_H

#include <string>
#include "Heap.h"

using namespace std;

typedef struct TrieNode TrieNode;
struct TrieNode
{
	char		key;
	HeapNode*	value;
	bool		end;
	TrieNode*	child;
	TrieNode*	next;
};

class Trie
{
public:
	Trie();
	TrieNode*	add(string name, HeapNode* heapNode);
	TrieNode*	add(TrieNode* node, string name, HeapNode* heapNode);
	TrieNode*	get(TrieNode* node, char needle);
	bool		has(TrieNode* node, char needle);
	void		remove(string name);
	bool		remove(TrieNode* node, string name);
	TrieNode*	find(string prefix);
	TrieNode*	find(TrieNode* node, string prefix);
	void		printTree();
	void		printTree(TrieNode* node, string spacing);
private:
	TrieNode*	root;
};

#endif

