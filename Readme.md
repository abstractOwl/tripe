#CS130A Programming Assignment 2

This data structure is a combination of a Trie and a binary minHeap, which we will call *Tripe*.

##Objective:

* The tripe will perform the following operations:

	* **Initialization**: Create initial data structure from given .txt file
		* Parse file line-by-line for name and grade
		* From corresponding Trie node, point to heap node
		* Insert heap node into heap (array impl)
	* **Insertion**: Insert single name-grade pair into tripe
	* **Search**: For given prefix, search through tripe and output all name-grade pairs with given prefix in name.
	* **Find Min**: Should output minimum grade entry. Assume *NO* duplicated grades.

* **Function prototypes**:

```cpp
// initialize tripe
void initialize (string filename)

// insert pair into tripe
void insert (string name, int grade)

// print list of entries matching prefix
void search (string prefix)

// print minimum grade pair
void findMin()
```

* **Additional contraints/details**:

	* Assume no duplicate grades
	* Use any data structure to implement Trie (e.g. Array, Tree-LL, etc)
	* Use array for MinHeap impl
	* HeapNode should include name + grade to make findMin easier
	* Remember to point Trie entries to heap nodes for use in search operation
	* Use bool or any kind of pointer to indicate current character is end of a name
	* Assume no space between first/last name
	* `findMin()` can be done on minHeap. Do not need to make any operations on Trie
	* Max number of entries is 100
	* Use Tripe as name of class providing essential functions

## Extra Credit:

### Implement `deleteMin()`:

* Delete the minimum element from the heap and corresponding name from Trie.
* Should be careful not to delete characters that are part of other names.
* Function prototype: `void deleteMin()`
