#include "Function.h"

//TASK 1
//PRE: receives pointer to the head of the list  
//POST: prints through the list
void traversePrint(Node<string>* head) {
    //set temp ptr
	Node<string>* currentNode = head;
    //loop through linked list & print data
	while (currentNode != nullptr) {
		cout << currentNode->data << endl;
		currentNode = currentNode->next;
	}
}

//TASK 2
//PRE: Pointers to the head of the list and the location of insertion are provided
//     as well as data(name)
//POST:  New node is added prior to the location of insertion
void addBefore(Node<string>* head, Node<string>* given, string data) {

    // if the list is empty 
    // What might be a better way to handle this case?

    if (head == nullptr)
        throw std::exception("empty list!");
  
    // if the new node is the head
	if (head == given) {
		head = new Node<string>(data, head);
		return;
	}

    //standard case
    //set currentNode to head value passed in
    //loop checking currentNode next pointer 
    //  if not 'given' advance node
    Node<string>* currentNode = head;
	while (currentNode->next != given && currentNode->next != nullptr) {
		currentNode = currentNode->next;
	}


    // if currentNode is nullptr -> we've reached the end, and didn't find Sam
	if (currentNode == nullptr)
		throw std::exception("Node not found");
    //create the new node & adjust pointer
    Node<string>* newNode = new Node<string>(data, currentNode->next);
    currentNode->next = newNode;
}


//TASK 3
//PRE: receives pointer to the item prior to deletion  
//POST: deletes the next node
void remove(Node<string>* delNext) {
	//check for special cases
	//if the next node is null, we can't delete it
	if (delNext == nullptr || delNext->next == nullptr)
		throw std::exception("Cannot delete the next node");

	//set temp node to the next node
	Node<string>* temp = delNext->next;
	//adjust pointers
	delNext->next = temp->next;
	//delete the node
	delete temp;


}


//TASK 4
//PRE: Pointers to the head of the list and the location of item to delete are provided
//POST:  New node is deleted prior to the node provided
void deleteBefore(Node<string>* head, Node<string>* given) {

    //check for special cases
    //list is empty or only contains one item (can not delete 'before')
    if (head == nullptr || head->next == nullptr || head == given)
        throw std::exception("Cannot delete the previous node");

    //check if we are deleting the head pointer
    if (head->next == given) {//the node we want to delete is the head
        Node<string>* temp = head;
        head = head->next;
        delete temp;
        return; //done
    }
    //otherwise, the standard case
    //set temp node to head node
    Node<string>* currentNode = head;

    //as long as the current node & next nodes are not null 
    //check if the current->next->next node is the one to delete
    //if so, adjust pointers & break/return
    //otherwise advance pointer
	while (currentNode->next->next != nullptr) {
		if (currentNode->next->next == given) {
			Node<string>* temp = currentNode->next;
			currentNode->next = temp->next;
			delete temp;
			return;
		}
		currentNode = currentNode->next;
	}



}