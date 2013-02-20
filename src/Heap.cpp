#include <cmath>
#include "Heap.h"

// constructor
Heap::Heap()
{
	insertPos = 0; // First empty index
}

// Add new node to heap
HeapNode* Heap::add(int grade, string name)
{
	HeapNode* node		=	new HeapNode;
	node->name			=	name;
	node->grade			=	grade;
	entries[insertPos]	=	node;

	upHeap(insertPos);

	insertPos++;

	return node;
}

// Get minimum node in heap (root)
HeapNode* Heap::min()
{
	return entries[0];
}

// Remove minimum node from heap
HeapNode* Heap::remove()
{
	HeapNode* target = entries[0];

	// Replace root with last element
	entries[0] = entries[insertPos - 1];
	entries[insertPos - 1] = NULL;
	insertPos--;

	downHeap(0);

	return target;
}

// Return index of current node's left child
int Heap::left(int index)
{
	return 2 * index + 1;
}
// Return index of current node's right child
int Heap::right(int index)
{
	return left(index) + 1;
}
// Return index of current node's parent
int Heap::parent(int index)
{
	return (int)(floor((index - 1) / 2));
}

// Swap nodes
void Heap::swap(int first, int second)
{
	HeapNode* tmp		=	entries[first];
	entries[first]	=	entries[second];
	entries[second]	=	tmp;
}

// Reconstruct heap after delete
void Heap::downHeap(int index)
{
	HeapNode* curr		=	entries[index];
	HeapNode* lChild	=	entries[left(index)];
	HeapNode* rChild	=	entries[right(index)];

	if (left(index) < insertPos
		&& lChild->grade < rChild->grade
		&& lChild->grade < curr->grade) {
		swap(index, left(index));
		downHeap(left(index));
	} else if (right(index) < insertPos
		&& rChild->grade < lChild->grade
		&& rChild->grade < curr->grade) {
		swap(index, right(index));
		downHeap(right(index));
	}
}

// Reconstruct heap after insert
void Heap::upHeap(int index)
{
	if (index == 0) return;

	if (entries[index]->grade < entries[parent(index)]->grade) {
		swap(index, parent(index));
	}

	upHeap(parent(index));
}
