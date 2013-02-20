#include <iostream>
#include <string>
#include "Trie.h"

using namespace std;

Trie::Trie()
{
	root = new TrieNode;
	root->end = false;
	root->key = '\0';
}

TrieNode* Trie::add(string name, HeapNode* heapNode)
{
	return add(root, name, heapNode);
}

TrieNode* Trie::add(TrieNode* node, string name, HeapNode* heapNode)
{
	if (has(node, name.at(0))) {
		if (name.size() == 1) {
			TrieNode* needle	=	get(node, name.at(0));
			needle->end			=	true;
			needle->value		=	heapNode;
			return needle;
		} else {
			return add(get(node, name.at(0)),
				name.substr(1, name.size() - 1), heapNode);
		}
	} else {
		TrieNode* child = new TrieNode;
		child->end		=	(name.size() == 1);
		child->key		=	name.at(0);
		child->next		=	NULL;
		child->child	=	NULL;

		if (node->child == NULL) {
			node->child = child;
		} else if (child->key < node->child->key) {
			TrieNode* tmp = node->child;
			node->child = child;
			child->next = tmp;
		} else {
			TrieNode* iter;
			for (iter = node->child; iter->next != NULL
				&& iter->next->key < child->key;
					iter = iter->next);

			if (iter->next == NULL) {
					iter->next = child;
			} else {
					TrieNode* tmp = iter->next;
					iter->next = child;
					child->next = tmp;
			}
		}

	return (name.size() == 1) ? child :
		add(child, name.substr(1, name.size() - 1), heapNode);
	}
}

TrieNode* Trie::get(TrieNode* node, char needle)
{
	for (TrieNode* iter = node->child; iter != NULL;
		iter = iter->next) {
		if (iter->key == needle) return iter;
	}
	return NULL;
}

bool Trie::has(TrieNode* node, char needle)
{
	for (TrieNode* iter = node->child; iter != NULL;
		iter = iter->next) {
		if (iter->key == needle) return true;
	}
	return false;
}

void Trie::remove(string name)
{
	TrieNode* tmp = find(name);
	tmp->end = false;
	tmp->value = NULL;

	remove(get(root, name.at(0)), name.substr(1, name.size() - 1));
}

bool Trie::remove(TrieNode* node, string name) {
	if (name.size() > 0) {
		if (remove(get(node, name.at(0)), name.substr(1, name.size() - 1))) {
			if (node->child->key == name.at(0)) {
				node->child = node->child->next;
			} else {
				for (TrieNode* iter = node->child; iter->next != NULL;
					iter = iter->next) {
					if (iter->next->key == name.at(0)) {
						iter->next = iter->next->next;
						break;
					}
				}
			}
		}
	}
	
	if (!node->end && node->child == NULL) {
		return true;
	}
	return false;
}

TrieNode* Trie::find(string prefix)
{
	return find(root, prefix);
}

TrieNode* Trie::find(TrieNode* node, string prefix)
{
	if (prefix.size() == 0) return node;

	return find(get(node, prefix.at(0)), prefix.substr(1, prefix.size() - 1));
}

void Trie::printTree()
{
	printTree(root, "");
}

void Trie::printTree(TrieNode* node, string spacing)
{
	cout << spacing << node->key << endl;

	for (TrieNode* iter = node->child; iter != NULL; iter = iter->next) {
		printTree(iter, spacing + "  ");
	}
}

