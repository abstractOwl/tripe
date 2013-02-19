#include <string>

using namespace std;

typedef struct HeapNode HeapNode;
struct HeapNode
{
	int		grade;
	string	name;
};

class Heap
{
public:
	Heap();
	void		add(int grade, string name);
	HeapNode*	min();
	HeapNode*	remove();

private:
	HeapNode	*entries[100];
	int			insertPos;

	int		left(int index);
	int		parent(int index);
	int		right(int index);
	void	downHeap(int index);
	void	upHeap(int index);
	void	swap(int first, int second);
};
