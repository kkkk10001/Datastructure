#include <iostream>
#include <string>
using namespace std;
class Node {
private:
	int data;
	string name;
	Node* left;
	Node* right;
public:
	Node(int data, string name) 
	{
		this->data = data;
		this->name = name;
		this->left = NULL;
		this->right = NULL;
	}
	string GetName() { return name; }
	int GetData() { return data; }
	Node* GetLeft() { return left; }
	Node* GetRight() { return right; }
	void SetName(string s) { this->name = s; }
	void SetData(int n) { this->data = n; }
	void SetLeft(Node* left) { this->left = left; }
	void SetRight(Node* right) { this->right = right; }
};
class BinaryTree {
public:
	void InsertLeftChild(Node& parent, Node& leftChild); // 왼쪽 자식 노드 삽입
	void InsertRightChild(Node& parent, Node& rightChild); // 오른쪽 자식 노드 삽입
	void DrawBinaryTree(Node& draw, int level); // 트리 그리기
	void PreorderTraversal(Node& draw); // 전위순회
	void InorderTraversal(Node& draw); // 중위순회
	void PostorderTraversal(Node& draw); // 후위순회
	void RemoveLeftSubtree(Node& left); // 왼쪽 부분트리 제거
	void RemoveRightSubtree(Node& right); // 오른쪽 부분트리 제거
};
void BinaryTree::InsertLeftChild(Node& parent, Node& leftChild) // 왼쪽 자식 삽입
{
	parent.SetLeft(&leftChild);
}
void BinaryTree::InsertRightChild(Node& parent, Node& RightChild) // 오른쪽 자식 삽입
{
	parent.SetRight(&RightChild);
}
void BinaryTree::RemoveLeftSubtree(Node& parent) // 왼쪽 서브트리 제거
{ 
	parent.SetLeft(NULL);
}
void BinaryTree::RemoveRightSubtree(Node& parent) // 오른쪽 서브트리 제거
{
	parent.SetRight(NULL);
}
void BinaryTree::PreorderTraversal(Node& current)  // 전위 순회
{
	if (&current == NULL) return;

	cout << "현재 노드 : " << current.GetName() << " 값 : " << current.GetData() << "\n";
	BinaryTree::PreorderTraversal(*current.GetLeft());
	BinaryTree::PreorderTraversal(*current.GetRight());

}
void BinaryTree::InorderTraversal(Node & current) // 중위 순회
{

	if (&current == NULL) return;

	BinaryTree::InorderTraversal(*current.GetLeft());
	cout << "현재 노드 : " << current.GetName() << " 값 : " << current.GetData() << "\n";
	BinaryTree::InorderTraversal(*current.GetRight());
}
void BinaryTree::PostorderTraversal(Node & current) // 후위 순회
{
	if (&current == NULL) return;

	BinaryTree::PostorderTraversal(*current.GetLeft());
	BinaryTree::PostorderTraversal(*current.GetRight());
	cout << "현재 노드 : " << current.GetName() << " 값 : " << current.GetData() << "\n";
}
void BinaryTree::DrawBinaryTree(Node& current, int level) // 레벨 별로 순차적으로 , 전위 순회 기반!
{
	if (&current == NULL) return;

	for (int i = 0; i < level; i++) 
	{
		cout << "----";
	}
	cout << current.GetName() << endl;
	BinaryTree::DrawBinaryTree(*current.GetLeft(), level + 1);
	BinaryTree::DrawBinaryTree(*current.GetRight(), level + 1);
}
int main()
{
	BinaryTree BT;

	Node A(1, "A");
	Node B(4, "B");
	Node C(9, "C");
	Node D(16, "D");
	Node E(25, "E");
	Node F(36, "F");
	Node G(49, "G");

	BT.InsertLeftChild(A, B);
	BT.InsertRightChild(A, C);

	BT.InsertLeftChild(B, D);
	BT.InsertRightChild(B, E);

	BT.InsertLeftChild(C, F);
	BT.InsertRightChild(C, G);

	cout << "Preorder\n";
	BT.PreorderTraversal(A); // 전위 순회
	cout << "\n";
	cout << "Inorder\n";
	BT.InorderTraversal(A); // 중위 순회
	cout << "\n";
	cout << "Postorder\n";
	BT.PostorderTraversal(A); // 후위 순회
	cout << "\n";
	BT.DrawBinaryTree(A, 0);

}
