#pragma once

#include "CoreMinimal.h"

template <class NodeType, class ElementType>
class TCircularLinkedListIterator
{
public:

	explicit TCircularLinkedListIterator(NodeType* StartingNode)
		: CurrentNode(StartingNode)
	{ }

	/** conversion to "bool" returning true if the iterator is valid. */
	FORCEINLINE explicit operator bool() const
	{
		return CurrentNode != nullptr;
	}

	TCircularLinkedListIterator& operator++()
	{
		checkSlow(CurrentNode);
		CurrentNode = CurrentNode->GetNextNode();
		return *this;
	}

	TCircularLinkedListIterator operator++(int)
	{
		auto Tmp = *this;
		++(*this);
		return Tmp;
	}

	TCircularLinkedListIterator& operator--()
	{
		checkSlow(CurrentNode);
		CurrentNode = CurrentNode->GetPrevNode();
		return *this;
	}

	TCircularLinkedListIterator operator--(int)
	{
		auto Tmp = *this;
		--(*this);
		return Tmp;
	}

	// Accessors.
	ElementType& operator->() const
	{
		checkSlow(CurrentNode);
		return CurrentNode->GetValue();
	}

	ElementType& operator*() const
	{
		checkSlow(CurrentNode);
		return CurrentNode->GetValue();
	}

	NodeType* GetNode() const
	{
		checkSlow(CurrentNode);
		return CurrentNode;
	}

private:
	NodeType* CurrentNode;

	friend bool operator==(const TCircularLinkedListIterator& Lhs, const TCircularLinkedListIterator& Rhs) { return Lhs.CurrentNode == Rhs.CurrentNode; }
	friend bool operator!=(const TCircularLinkedListIterator& Lhs, const TCircularLinkedListIterator& Rhs) { return Lhs.CurrentNode != Rhs.CurrentNode; }
};


/**
 * Double linked list.
 *
 * @see TIntrusiveDoubleLinkedList
 */
template <class ElementType>
class TCircularLinkedList
{
public:
	class TCircularLinkedListNode
	{
	public:
		friend class TCircularLinkedList;

		/** Constructor */
		TCircularLinkedListNode(const ElementType& InValue)
			: Value(InValue), NextNode(nullptr), PrevNode(nullptr)
		{ }

		const ElementType& GetValue() const
		{
			return Value;
		}

		ElementType& GetValue()
		{
			return Value;
		}

		TCircularLinkedListNode* GetNextNode()
		{
			return NextNode;
		}

		const TCircularLinkedListNode* GetNextNode() const
		{
			return NextNode;
		}

		TCircularLinkedListNode* GetPrevNode()
		{
			return PrevNode;
		}

		const TCircularLinkedListNode* GetPrevNode() const
		{
			return PrevNode;
		}

	protected:
		ElementType            Value;
		TCircularLinkedListNode* NextNode;
		TCircularLinkedListNode* PrevNode;
	};

	/**
	 * Used to iterate over the elements of a linked list.
	 */
	typedef TCircularLinkedListIterator<TCircularLinkedListNode, ElementType> TIterator;
	typedef TCircularLinkedListIterator<TCircularLinkedListNode, const ElementType> TConstIterator;

	/** Constructors. */
	TCircularLinkedList()
		: HeadNode(nullptr)
		, ListSize(0)
	{ }

	TCircularLinkedList(TCircularLinkedListNode* InitialNode)
		:  ListSize(0)
	{
		AddHead(InitialNode);
	}

	/** Destructor */
	virtual ~TCircularLinkedList()
	{
		Empty();
	}

	// Adding/Removing methods

	/**
	 * Add the specified value to the beginning of the list, making that value the new head of the list.
	 *
	 * @param	InElement	the value to add to the list.
	 * @return	whether the node was successfully added into the list.
	 * @see GetHead, InsertNode, RemoveNode
	 */
	bool AddHead(const ElementType& InElement)
	{
		return AddHead(new TCircularLinkedListNode(InElement));
	}

	bool AddHead(TCircularLinkedListNode* NewNode)
	{
		if (NewNode == nullptr)
		{
			return false;
		}

		if (HeadNode == nullptr)
		{
			HeadNode = NewNode;
			HeadNode->NextNode = NewNode;
			HeadNode->PrevNode = NewNode;
			SetListSize(ListSize + 1)

			return true;
		}
		return InsertNode(NewNode, HeadNode->NextNode);
	}

	/**
	 * Insert the specified value into the list at an arbitrary point.
	 *
	 * @param	InElement			the value to insert into the list
	 * @param	NodeToInsertBefore	the new node will be inserted into the list at the current location of this node
	 *								if nullptr, the new node will become the new head of the list
	 * @return	whether the node was successfully added into the list
	 * @see Empty, RemoveNode
	 */
	bool InsertNode(const ElementType& InElement, TCircularLinkedListNode* NodeToInsertBefore = nullptr)
	{
		return InsertNode(new TCircularLinkedListNode(InElement), NodeToInsertBefore);
	}

	bool InsertNode(TCircularLinkedListNode* NewNode, TCircularLinkedListNode* NodeToInsertBefore = nullptr)
	{
		if (NewNode == nullptr)
		{
			return false;
		}

		if (NodeToInsertBefore == nullptr)
		{
			return AddHead(NewNode);
		}

		NewNode->PrevNode = NodeToInsertBefore->PrevNode;
		NewNode->NextNode = NodeToInsertBefore;

		NodeToInsertBefore->PrevNode->NextNode = NewNode;
		NodeToInsertBefore->PrevNode = NewNode;

		SetListSize(ListSize + 1);
		return true;
	}

	/**
	 * Remove the node corresponding to InElement.
	 *
	 * @param InElement The value to remove from the list.
	 * @see Empty, InsertNode
	 */
	void RemoveNode(const ElementType& InElement)
	{
		TCircularLinkedListNode* ExistingNode = FindNode(InElement);
		RemoveNode(ExistingNode);
	}

	/**
	 * Removes the node specified.
	 *
	 * @param NodeToRemove The node to remove.
	 * @see Empty, InsertNode
	 */
	void RemoveNode(TCircularLinkedListNode* NodeToRemove, bool bDeleteNode = true)
	{
		if (NodeToRemove != nullptr)
		{
			// if we only have one node, just call Clear() so that we don't have to do lots of extra checks in the code below
			if (Num() == 1)
			{
				checkSlow(NodeToRemove == HeadNode);
				if (bDeleteNode)
				{
					Empty();
				}
				else
				{
					NodeToRemove->NextNode = NodeToRemove->PrevNode = nullptr;
					HeadNode = nullptr;
					SetListSize(0);
				}
				return;
			}

			if (NodeToRemove == HeadNode)
			{
				HeadNode = HeadNode->NextNode;
				HeadNode->PrevNode = nullptr;
			}

			else
			{
				NodeToRemove->NextNode->PrevNode = NodeToRemove->PrevNode;
				NodeToRemove->PrevNode->NextNode = NodeToRemove->NextNode;
			}

			if (bDeleteNode)
			{
				delete NodeToRemove;
			}
			else
			{
				NodeToRemove->NextNode = NodeToRemove->PrevNode = nullptr;
			}
			SetListSize(ListSize - 1);
		}
	}

	/** Removes all nodes from the list. */
	void Empty()
	{
		TCircularLinkedListNode* Node;
		while (HeadNode != nullptr)
		{
			Node = HeadNode->NextNode;
			delete HeadNode;
			HeadNode = Node;
		}

		HeadNode = nullptr;
		SetListSize(0);
	}

	// Accessors.

	/**
	 * Returns the node at the head of the list.
	 *
	 * @return Pointer to the first node.
	 */
	TCircularLinkedListNode* GetHead() const
	{
		return HeadNode;
	}

	/**
	 * Finds the node corresponding to the value specified
	 *
	 * @param	InElement	the value to find
	 * @return	a pointer to the node that contains the value specified, or nullptr of the value couldn't be found
	 */
	TCircularLinkedListNode* FindNode(const ElementType& InElement)
	{
		TCircularLinkedListNode* Node = HeadNode;
		int Count = 0;
		while (Node != nullptr || Count < Num())
		{
			Count++;
			if (Node->GetValue() == InElement)
			{
				break;
			}

			Node = Node->NextNode;
		}

		return Node;
	}

	bool Contains(const ElementType& InElement)
	{
		return (FindNode(InElement) != nullptr);
	}

	/**
	 * Returns true if the list is empty and contains no elements.
	 *
	 * @returns True if the list is empty.
	 * @see Num
	 */
	bool IsEmpty() const
	{
		return ListSize == 0;
	}

	/**
	 * Returns the number of items in the list.
	 *
	 * @return Item count.
	 */
	int32 Num() const
	{
		return ListSize;
	}

protected:

	/**
	 * Updates the size reported by Num().  Child classes can use this function to conveniently
	 * hook into list additions/removals.
	 *
	 * @param	NewListSize		the new size for this list
	 */
	virtual void SetListSize(int32 NewListSize)
	{
		ListSize = NewListSize;
	}

private:
	TCircularLinkedListNode* HeadNode;
	int32 ListSize;

	TCircularLinkedList(const TCircularLinkedList&);
	TCircularLinkedList& operator=(const TCircularLinkedList&);

	friend TIterator      begin(TCircularLinkedList& List) { return TIterator(List.GetHead()->NextNode); }
	friend TConstIterator begin(const TCircularLinkedList& List) { return TConstIterator(List.GetHead()->NextNode); }
	friend TIterator      end(TCircularLinkedList& List) { return TIterator(List.GetHead()); }
	friend TConstIterator end(const TCircularLinkedList& List) { return TConstIterator(List.GetHead()); }
};