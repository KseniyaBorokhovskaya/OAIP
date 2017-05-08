//---------------------------------------------------------------------------

#ifndef TreeH
#define TreeH
#include <vcl.h>
//---------------------------------------------------------------------------
class Node {
public:
	int WorkmanID;
	String Name;
	Node *left;
	Node *right;
};

class Tree {
private:
	Node * head, *current, *prev;
	AnsiString stringToShowTraverse;
public:

	Tree(){}
	~Tree();

	Node* GetHead()
	{
	 return head;
	}


	void Create(Node **root, String name, int workmanID);
	void Add(String name, int workmanID);


	void Delete(Node *node);
	Node* Find(int workmanID);

	// �������� �������� �� �����
	void Delete(TMemo *Memo, int workmanID, bool &isDeletedSuccesful);

	// �������� ����� � �������� ������(�������������� �������)
	void DeleteNode(TMemo *Memo, int workmanID);


	void Search(TMemo *Memo, int workmanID);




	//������ ������
	void Preorder();
	void Preorder(Node *node);

	//������ � �����������
	void Inorder();
	void Inorder(Node *node);

	// �������� ������ ������
	void Postorder();
	void Postorder(Node *node);

	// �����, ������� ���������� ������
	AnsiString GetStringToShowTraverse()
	{
		return stringToShowTraverse;
	};

	//�������������� ������
	void Balance();
	void treeToLiana(Node *node, int *amount);
	void lianaToTree(Node *node, int *amount);
	void Compression(Node *node, int amount);


};
#endif
