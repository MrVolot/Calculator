#pragma once


template<typename T>
class Stack {
	struct stackStruct {
		T data{};
		stackStruct* pNext{nullptr};
	};
	stackStruct* Node{nullptr};
	void copy(stackStruct* Node);
public:
	Stack()=default;
	Stack(const Stack& rhs)=delete;
	void push(T data);
	void pop();
	stackStruct* begin() { return Node; }
	T retData();
	~Stack();
	T top();
	bool empty();
};

//template<typename T>
//Stack<T>::Stack(const Stack& rhs) {
//	auto tmp{rhs.begin() };
//	copy(tmp);
//}

template<typename T>
void Stack<T>::push(T data) {
	if (Node == nullptr) {
		Node = new stackStruct{data,nullptr};
		return;
	}
	auto newNode = new stackStruct{ data,nullptr };
	newNode->pNext = Node;
	Node = newNode;
}

template<typename T>
void Stack<T>::pop() {
	if (Node == nullptr) {
		return;
	}
	auto delNode = Node;
	Node = Node->pNext;
	delete delNode;
}

//template<typename T>
//auto Stack<T>::begin(){
//	return Node;
//}

template<typename T>
T Stack<T>::retData() {
	return Node->data;
}

template<typename T>
void Stack<T>::copy(stackStruct* outNode) {
 	if (outNode != nullptr) {
		while (outNode != nullptr) {
			push(outNode->data);
			outNode = outNode->pNext;
		}
	}
}

template<typename T>
Stack<T>::~Stack() {
	while (Node != nullptr) {
		pop();
	}
}

template<typename T>
T Stack<T>::top() {
	return Node->data;
}

template<typename T>
bool Stack<T>::empty() {
	if (Node == nullptr) {
		return true;
	}
	return false;
}