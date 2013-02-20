#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include "Tripe.h"

using namespace std;

Tripe::Tripe()
{
}

void Tripe::initialize(string filename)
{
	ifstream	input;
	string		name;
	int			grade;

	input.open(filename.c_str());

	if (!input) {
		cout << "Invalid file" << endl;
		exit(1);
	}

	while (input >> name && input >> grade) {
		insert(name, grade);
	}
}

void Tripe::insert(string name, int grade)
{
	HeapNode* hNode = heap.add(grade, name);
	TrieNode* tNode = trie.add(name, hNode);
	tNode->value = hNode;
}

void Tripe::search(string prefix)
{
	print(trie.find(prefix));
}


void Tripe::print(TrieNode* node)
{
	if (node == NULL) return;

	if (node->end) {
		cout << node->value->name << "\t" << node->value->grade << endl;
	}

	for (TrieNode* iter = node->child; iter != NULL; iter = iter->next) {
		print(iter);
	}
}

void Tripe::findMin()
{
	HeapNode* min = heap.min();
	cout << min->name << "\t" << min->grade << endl;
}

void Tripe::deleteMin()
{
	HeapNode* min = heap.remove();
	trie.remove(min->name);
}

void Tripe::printTrie()
{
	trie.printTree();
}

