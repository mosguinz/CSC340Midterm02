// Multiple correct solutions accepted.


// COPY CONSTRUCTOR (the reverse)
template<typename ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag, const string& mode) {

	itemCount = aBag.itemCount;
	Node<ItemType>* origChainPtr = aBag.headPtr;

	if (origChainPtr == nullptr) {
		headPtr = nullptr;
	}
	else {
		headPtr = new Node<ItemType>(origChainPtr->getItem());
		origChainPtr = origChainPtr->getNext();

		while (origChainPtr != nullptr)
		{
			Node<ItemType>* newNodePtr = new Node<ItemType>(origChainPtr->getItem(), headPtr);
			headPtr = newNodePtr;
			origChainPtr = origChainPtr->getNext();
		}
	}
} // end COPY CONSTRUCTOR (the reverse)

/* OUTPUT

!Display bag : e l e c t r i c a l
-----------> 10 item(s) total

!Display bag : l a c i r t c e l e
-----------> 10 item(s) total

*/



// removeLastThree
// Assumption: It is OK to use either the head item or the tail item
// to replace the item which we need to remove.
template<typename ItemType>
bool LinkedBag<ItemType>::removeLastThree(const ItemType& itemToRemove)
{
	const int totalToRemove = 3;
	int totalRemoved = 0;

	LinkedBag<ItemType>* revBag{ new LinkedBag(*this, "reverse") };
	Node<ItemType>* curPtr{ revBag->headPtr };

	while (curPtr != nullptr && totalRemoved != totalToRemove)
	{
		if (itemToRemove != curPtr->getItem()) {
			curPtr = curPtr->getNext();
		}
		else {
			curPtr->setItem(revBag->headPtr->getItem());
			Node<ItemType>* nodeToDelete{ revBag->headPtr };

			revBag->headPtr = revBag->headPtr->getNext();
			curPtr = curPtr->getNext();

			nodeToDelete->setNext(nullptr);
			delete nodeToDelete;
			nodeToDelete = nullptr;

			totalRemoved++;
			itemCount--;
		}
	}

	LinkedBag<ItemType>* retBag{ new LinkedBag(*revBag, "reverse") };
	this->headPtr = retBag->headPtr;

	return true;
} // end removeLastThree

/* OUTPUT

----- removeLastThree TEST -----

 !Display bag: r e e n i g n e l a c i r t c e l e
  -----------> 18 item(s) total

 !Display bag: r e e n i g n l l a c i r t c
  -----------> 15 item(s) total

*/