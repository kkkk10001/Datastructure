#include <iostream>
using namespace std;
class Stack {
public:
	Stack(int size) {
		m_size = size;
		m_item = new int[m_size];
		top = -1;
	}
	bool isFull();
	bool isEmpty();
	void push(int item);
	void pop();

	int m_size;
	int* m_item;
	int top;
};
bool Stack::isFull() {
	return (top == m_size - 1);
}
bool Stack::isEmpty() {
	return (top == -1);
}
void Stack::push(int item) {
	if (isFull()) return;
	m_item[++top] = item;
}
void Stack::pop() {
	if (isEmpty()) return;
	top--;
}
int main() {
	Stack s(100);

	for (int i = 1; i <= 100; i++) {
		s.push(i * i);
	}
	cout << s.m_item[s.top] << "\n";
}
