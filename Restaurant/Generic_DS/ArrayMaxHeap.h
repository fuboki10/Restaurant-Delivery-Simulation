#ifndef _ARRAY_MAX_HEAP
#define _ARRAY_MAX_HEAP
#include "HeapInterface.h"
#include <iostream>
#include <exception> // exception()
#include <cstdlib>   // exit() 

template<class T>
class ArrayMaxHeap : public HeapInterface<T>
{
	static const int DEFAULT_CAPACITY = 15;
	T** items; // Array of pointers to heap items
	int Count; // Current count of heap items
	int maxItems; // Maximum capacity of the heap
    /* /////////////////////////
			Utility Functions
	*///////////////////////////

	// Gets the array index of the left child node
	int LeftChild(int nodeIndex) const;

	// Gets the array index of the right child node
	int RightChild(int nodeIndex) const;

	// Gets the array index of the parent node
	int Parent(int nodeIndex) const;

	// sees whether this node is a leaf
	bool isLeaf(int nodeIndex) const;

	// Converts a semiheap to a heap.
	void heapRebuild(int subTreeRootIndex);

	// Creates a heap from an unordered array.
	void heapCreate();

	// Swaps 2 elements
	void Swap(T* & item_1, T* & item_2);

	// Doubles the capacity of the array
	void Double_Capacity();

	// Shrinks the capacity of the array in half
	void Shrink_Capacity();
	////////////////////////////
public:
	ArrayMaxHeap();
	ArrayMaxHeap(T* Array[], const int Size);
	ArrayMaxHeap(const ArrayMaxHeap<T>& Array); // Copy constructor
	ArrayMaxHeap<T>& operator= (const ArrayMaxHeap<T>& Array); // Assignment Operator
	virtual ~ArrayMaxHeap();
	
	/* /////////////////////////
			Methods
	*///////////////////////////

	// Gets the Capacity of the Heap
	int Capacity() const;
	
	int Size() const;

	// sees whether the heap is empty
	bool isEmpty() const;

	// Gets the number of nodes
	int getNumberOfNodes() const;

	// Gets the Height of the heap
	int getHeight() const;

	// Gets the data that is in the root (top) of this heap
	T* peekTop() const;

	// Adds new node to the heap
	bool add(T* newData);

	// Remove the root (top) node
	bool remove();

	// Removes all nodes from the heap
	void clear();
};
// Gets the array index of the left child node
template<class T>
int ArrayMaxHeap<T>::LeftChild(int nodeIndex) const
{
	return 2 * nodeIndex + 1;
}

// Gets the array index of the right child node
template<class T>
int ArrayMaxHeap<T>::RightChild(int nodeIndex) const
{
	return 2 * nodeIndex + 2;
}

// Gets the array index of the parent node
template<class T>
int ArrayMaxHeap<T>::Parent(int nodeIndex) const
{
	return (nodeIndex - 1) / 2;
}

// sees whether this node is a leaf
template<class T>
bool ArrayMaxHeap<T>::isLeaf(int nodeIndex) const
{
	return LeftChild(nodeIndex) > Count && RightChild(nodeIndex) > Count;
}

// Creates a heap from an unordered array.
template<class T>
void ArrayMaxHeap<T>::heapCreate()
{
	for (int i = Count / 2; i >= 0; i--)
	{
		heapRebuild(i);
	}
}

// Converts a semiheap to a heap.
template<class T>
void ArrayMaxHeap<T>::heapRebuild(int subTreeRootIndex)
{
	if (!isLeaf(subTreeRootIndex))
	{
		int maxIndex = LeftChild(subTreeRootIndex);
		if (RightChild(subTreeRootIndex) < Count)
		{
			if (*items[RightChild(subTreeRootIndex)] > *items[maxIndex])
			{
				maxIndex = RightChild(subTreeRootIndex);
			}
		}
		if (*items[subTreeRootIndex] < *items[maxIndex])
		{
			Swap(items[subTreeRootIndex], items[maxIndex]);
			heapRebuild(maxIndex);
		}
	}
}

// Swaps 2 elements
template<class T>
void ArrayMaxHeap<T>::Swap(T* & item_1, T* & item_2)
{
	T* temp = item_1;
	item_1 = item_2;
	item_2 = temp;
}

// Doubles the capacity of the array
template<class T>
void ArrayMaxHeap<T>::Double_Capacity()
{
	T** temp = new T* [maxItems];
	for (int i = 0; i < Count; i++)
	{
		temp[i] = items[i];
	}
	delete[] items;
	items = new T* [maxItems * 2];
	for (int i = 0; i < Count; i++)
	{
		items[i] = temp[i];
	}
	delete[] temp;
	maxItems *= 2;
}

// Shrinks the capacity of the array in half
template<class T>
void ArrayMaxHeap<T>::Shrink_Capacity()
{
	maxItems /= 2;
	T** temp = new T* [maxItems];
	for (int i = 0; i < Count; i++)
	{
		temp[i] = items[i];
	}
	delete[] items;
	items = new T* [maxItems];
	for (int i = 0; i < Count; i++)
	{
		items[i] = temp[i];
	}
	delete[] temp;
}

template<class T>
ArrayMaxHeap<T>::ArrayMaxHeap() :
	Count(0), maxItems(DEFAULT_CAPACITY)
{
	items = new T* [DEFAULT_CAPACITY];	
}
template<class T>
ArrayMaxHeap<T>::ArrayMaxHeap(T* Array[], const int Size) : 
	Count(Size), maxItems(2 * Size)
{
	items = new T* [maxItems];

	// Copy
	for (int i = 0; i < Size; i++)
	{
		items[i] = Array[i];
	}

	// Create the heap from the unordered items array
	heapCreate();
}
template<class T>
ArrayMaxHeap<T>::ArrayMaxHeap(const ArrayMaxHeap<T>& Array) // Copy constructor
{
	Count = Array.Count;
	maxItems = Array.maxItems;

	items = new T* [maxItems];

	// Copy
	for (int i = 0; i < Count; i++)
	{
		T* temp = new T(*Array.items[i]);
		items[i] = temp;
	}
}
template<class T>
ArrayMaxHeap<T>& ArrayMaxHeap<T>::operator= (const ArrayMaxHeap<T>& Array) // Assignment Operator
{
	clear();
	Count = Array.Count;
	maxItems = Array.maxItems;

	items = new T* [maxItems];

	// Copy
	for (int i = 0; i < Count; i++)
	{
		items[i] = new T(*Array.items[i]);
	}
	return *this;
}
template<class T>
ArrayMaxHeap<T>::~ArrayMaxHeap()
{
	clear();
}

// Gets the Capacity of the Heap
template<class T>
int ArrayMaxHeap<T>::Capacity() const
{
	return maxItems;
}

// sees whether the heap is empty
template<class T>
bool ArrayMaxHeap<T>::isEmpty() const
{
	return Count == 0;
}
// Gets the number of nodes
template<class T>
int ArrayMaxHeap<T>::getNumberOfNodes() const
{
	return Count;
}

// Gets the Height of the heap
template<class T>
int ArrayMaxHeap<T>::getHeight() const
{
	int lastNodeIndex = Count - 1;
	int Count = 0;
	while (lastNodeIndex > 0)
	{
		lastNodeIndex = Parent(lastNodeIndex);
		Count++;
	}
	return Count;
}

// Gets the data that is in the root (top) of this heap
template<class T>
T* ArrayMaxHeap<T>::peekTop() const
{
	try
	{
		if (isEmpty())
		{
			throw std::exception("The Heap is Empty\n");
		}
		return items[0];
	}
	catch(std::exception& e)
	{
		std::cout << "ERROR: " << e.what();
		std::exit(0);
	}
}

// Adds new node to the heap
template<class T>
bool ArrayMaxHeap<T>::add(T* newData)
{
	if (Count == maxItems)
	{
		Double_Capacity();
	}
	items[Count] = newData;

	int newDataIndex = Count;
	bool RightPlace = false;
	bool added = false;

	while (newDataIndex > 0 && !RightPlace)
	{
		int parentIndex = Parent(newDataIndex);
		if (*items[newDataIndex] < *items[parentIndex])
		{
			RightPlace = 1;
		}
		else
		{
			added = true;
			Swap(items[newDataIndex], items[parentIndex]);
			newDataIndex = parentIndex;
		}
	}

	Count++;
	return added;
}

// Remove the root (top) node
template<class T>
bool ArrayMaxHeap<T>::remove()
{
	if (Count == 0)
	{
		return false;
	}

	if (Count == 1)
	{
		Count--;
	}
	else
	{
		items[0] = items[Count - 1];
		Count--;

		heapRebuild(0);

	}

	if (Count < (maxItems - DEFAULT_CAPACITY) / 2)
	{
		Shrink_Capacity();
	}
	return true;
}

// Removes all nodes from the heap
template<class T>
void ArrayMaxHeap<T>::clear()
{
	if (items)
	{
		for (int i = 0; i < Count; i++)
		{
			delete items[i];
		}
		delete[] items;
		Count = 0;
		maxItems = 0;
	}
}

template<class T>
int ArrayMaxHeap<T>::Size() const
{
	return Count;
}
#endif _ARRAY_MAX_HEAP
