#ifndef _HEAP_PRIORITY_QUEUE 
#define _HEAP_PRIORITY_QUEUE
#include "ArrayMaxHeap.h"
#include "PriorityQueueInterface.h"

template<class ItemType>
class Heap_PriorityQueue :
	public PriorityQueueInterface<ItemType>,
	private ArrayMaxHeap<ItemType> 
{
public:
	Heap_PriorityQueue();
	bool isEmpty() const;
	bool add(ItemType* Item);
	bool remove();
	ItemType* peek() const;
	int Capcity() const;
	int Size() const;

};

template<class ItemType>
int Heap_PriorityQueue<ItemType>::Capcity() const
{
	return ArrayMaxHeap<ItemType>::Capacity();
}
template<class ItemType>
int Heap_PriorityQueue<ItemType>::Size() const
{
	return ArrayMaxHeap<ItemType>::Size();
}
template<class ItemType>
Heap_PriorityQueue<ItemType>::Heap_PriorityQueue()
{
	ArrayMaxHeap<ItemType>();
}

template<class ItemType>
bool Heap_PriorityQueue<ItemType>::isEmpty() const
{
	return ArrayMaxHeap<ItemType>::isEmpty();
}

template<class ItemType>
bool Heap_PriorityQueue<ItemType>::add(ItemType* Item)
{
	return ArrayMaxHeap<ItemType>::add(Item);
}

template<class ItemType>
bool Heap_PriorityQueue<ItemType>::remove()
{
	return ArrayMaxHeap<ItemType>::remove();
}

template<class ItemType>
ItemType* Heap_PriorityQueue<ItemType>::peek() const
{
	return ArrayMaxHeap<ItemType>::peekTop();
}

#endif _HEAP_PRIORITY_QUEUE