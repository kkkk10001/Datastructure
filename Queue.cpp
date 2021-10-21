#include <iostream>
using namespace std;
class Queue {
private:
	int maxSize;
	int rear;
	int front;
	int* data;
public:
	Queue(int maxSize)
	{
		this->maxSize = maxSize + 1;
		data = new int[maxSize];
		rear = 0;
		front = 0;
	}
	void push(int value);
	void pop();
	int GetFront();
	int GetSize();
	bool empty();
	bool full();
};
void Queue::push(int value)
{
	if ((rear + 1) % maxSize == front % maxSize) {
		cout << "Queue is full" << endl;
		return;
	}
	data[rear++] = value;
	if (rear >= maxSize) rear %= maxSize;
}
void Queue::pop()
{
	data[front++] = -1;
}

int Queue::GetFront()
{
	if (front >= maxSize) front %= maxSize;
	return data[front];
}
int Queue::GetSize()
{
	return (rear - front + maxSize) % maxSize;
}
bool Queue::empty()
{
	return GetSize() == 0;
}
bool Queue::full()
{
	return GetSize() == maxSize - 1;
}
int main()
{
	Queue qu(10);

	for (int i = 0; i < 10; i++) {
		qu.push(i);
	}
	while(qu.GetSize() > 0) 
	{
		cout << qu.GetFront() << "\n";
		qu.pop();
	}
}
