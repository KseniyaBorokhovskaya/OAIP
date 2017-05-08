//---------------------------------------------------------------------------

#pragma hdrstop

#include "Tree.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)

Tree::~Tree()
{
	Delete(head);
}

void Tree::Create(Node **tree, String name, int workmanID){
	Node *newElement = new Node;
	newElement->left = NULL;
	newElement->right = NULL;
	newElement->Name = name;
	newElement->WorkmanID = workmanID;
	*tree = newElement;
}


void Tree::Add(String name, int workmanID){
	Node *newElement = new Node;
	newElement->Name = name;
	newElement->WorkmanID = workmanID;
	if (head == NULL) {
		Create(&head, name, workmanID);
	}
	else {
		current = head;
		while (true){
			if (workmanID == current->WorkmanID) {
				return;
			}
			else if (workmanID > current->WorkmanID) {
				if (current->right) {
					current = current->right;
				}
				else {
					Create(&current->right, name, workmanID);
					return;
				}

			}
			else {
				if (current->left) {
					current = current->left;
				}
				else {
					Create(&current->left, name, workmanID);
					return;
				}
			}
		}
	}
}

void Tree::Delete(Node *node)
{
	if (node != NULL)
	{
		Delete(node->left);
		node->left = NULL;
		Delete(node->right);
		node->right = NULL;
		delete node;
	}
}

Node* Tree::Find(int workmanID)
{
	Node *nodeToFind = head;
	prev = nodeToFind;
	if (nodeToFind != NULL) {
		while (nodeToFind != NULL && nodeToFind->WorkmanID != workmanID) {
			if (workmanID > nodeToFind->WorkmanID) {
				prev = nodeToFind;
				nodeToFind = nodeToFind->right;
			}
			else if (workmanID < nodeToFind->WorkmanID) {
				prev = nodeToFind;
				nodeToFind = nodeToFind->left;
			}
		}
	}
	return nodeToFind;
}

// �������� �������� �� �����
void Tree::Delete(TMemo *Memo, int workmanID, bool &isDeletedSuccesful){
	if (head == NULL) {
		ShowMessage("������� �������� ������� � ������!");
		isDeletedSuccesful = false;
		return;
	}
	Node *workmanToDelete = Find(workmanID);
	if (workmanToDelete != NULL) {
		if (!workmanToDelete->right && !workmanToDelete->left) {
			if (prev->right == workmanToDelete) {
				prev->right = NULL;
			}
			else if (prev->left == workmanToDelete) {
				prev->left = NULL;
			}
			if (workmanToDelete == head) {
				head = NULL;
			}
			delete workmanToDelete;
		}
		else if ((workmanToDelete->right != NULL && workmanToDelete->left == NULL)) {
			if (prev->right == workmanToDelete) {
				prev->right = workmanToDelete->right;
			}
			else if (prev->left == workmanToDelete) {
				prev->left = workmanToDelete->right;
			}
			if (workmanToDelete == head) {
				head = workmanToDelete->right;
			}
			delete workmanToDelete;
		}
		else if ((workmanToDelete->right == NULL && workmanToDelete->left != NULL)) {
			if (prev->right == workmanToDelete) {
				prev->right = workmanToDelete->left;
			}
			else if (prev->left == workmanToDelete) {
				prev->left = workmanToDelete->left;
			}
			if (workmanToDelete == head) {
				head = workmanToDelete->left;
			}
			delete workmanToDelete;
		}
		else if (workmanToDelete->right != NULL && workmanToDelete->left != NULL) {
			Node *max = workmanToDelete, *previous;
			while (max->right != NULL) {
				previous = max;
				max = max->right;
			}
			previous->right = max->left;
			workmanToDelete->WorkmanID = max->WorkmanID;
			workmanToDelete->Name = max->Name;
			delete max;
		}
	}

	Memo->Lines->Add("������� " + workmanToDelete->Name + " ��� ������");
}
// �������� ����� � �������� ������(�������������� �������)
void Tree::DeleteNode(TMemo *Memo, int workmanID){
	if (head == NULL) {
		ShowMessage("������� �������� ������� � ������!");
		return;
	}
	Node *workmanToDelete = Find(workmanID);
	Delete(workmanToDelete);
	if (prev->right == workmanToDelete) {
		prev->right = NULL;
	}
	else
	{
		prev->left = NULL;
	}
	Memo->Lines->Add("������� " + workmanToDelete->Name + " ��� ������");
}

void Tree::Search(TMemo *Memo, int workmanID){
	if (head == NULL) {
		ShowMessage("������� �������� ������� � ������!");
	}
	else {
		Node *element = head;
		while (true){
			if (element == NULL) {
				ShowMessage("������� �� ��� ������!");
				return;
			}
			else {
				if (element->WorkmanID == workmanID) {
					Memo->Lines->Add(element->Name + " " + element->WorkmanID);
					return;
				}
				else if (element->WorkmanID > workmanID) {
					 element = element->left;
				}
				else
					element = element->right;
			}
		}
	}
}



//������ ������
void Tree::Preorder()
{
	stringToShowTraverse = "";
	Preorder(head);
}

void Tree::Preorder(Node *node)
{
	if (!node) return;
	stringToShowTraverse += IntToStr(node->WorkmanID) + " ";
	if (node->left) Preorder(node->left);
	if (node->right) Preorder(node->right);
}



 //������ � �����������
void Tree::Inorder()
{
	stringToShowTraverse = "";
	Inorder(head);
}

void Tree::Inorder(Node *node)
{
	if (!node) return;
		if (node->left) Inorder(node->left);
		stringToShowTraverse += IntToStr(node->WorkmanID) + " ";
		if (node->right) Inorder(node->right);
}



 // �������� ������ ������
void Tree::Postorder()
{
	stringToShowTraverse = "";
	Postorder(head);
}

void Tree::Postorder(Node *node)
{
	if (!node) return;
	if (node->left) Postorder(node->left);
	if (node->right) Postorder(node->right);
	stringToShowTraverse += IntToStr(node->WorkmanID) + " ";
}




// ������������ ������
void Tree::Balance()
{
	Node *temp = new Node;
	temp->right = head;
	int amount;
	treeToLiana(temp, &amount);
	lianaToTree(temp, &amount);
	head = temp->right;
	delete temp;
}

void Tree::treeToLiana(Node *node, int *amount)
{
	Node *remainder, *lianaTail, *temp;
	lianaTail = node;
	remainder = lianaTail->right;
	*amount = 0;
	while (remainder) {
		if (!remainder->left) {
			lianaTail = remainder;
			remainder = remainder->right;
			(*amount)++;
		} else {
			temp = remainder->left;
			remainder->left = temp->right;
			temp->right = remainder;
			remainder = temp;
			lianaTail->right = temp;
		}
	}
}

void Tree::lianaToTree(Node *node, int *amount)
{
	int leafs;
	leafs = *amount + 1 - (int)pow(2.0, floor(log(double(*amount + 1)) / log(double(2))));
	Compression(node, leafs);
	*amount = *amount - leafs;
	while (*amount > 1) {
		Compression(node, *amount / 2);
		*amount /= 2;
    }
}

void Tree::Compression(Node *node, int amount)
{
	Node *child, *scanner = node;
	for (int i = 1; i <= amount; i++) {
		child = scanner->right;
		scanner->right = child->right;
		scanner = scanner->right;
		child->right = scanner->left;
		scanner->left = child;
	}
}


