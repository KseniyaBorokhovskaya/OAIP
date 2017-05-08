//---------------------------------------------------------------------------

#pragma hdrstop

#include "ShowTree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void ShowTree(TTreeView *show, TTreeNode *treeNode, TreeItem *node)
{
	if (node != NULL) {
		if (node == tree->GetRoot()) {
			treeNode = show->Items->Add(NULL, node->Name + "(" + IntToStr(node->StudentID) + ")");
		}
		else {
			treeNode = show->Items->AddChild(treeNode, node->Name + "(" + IntToStr(node->StudentID) + ")");
		}
		ShowTree(show, treeNode, node->left);
		ShowTree(show, treeNode, node->right);
	}
	else return;
}
