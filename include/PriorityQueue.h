#pragma once

#include <iostream>
#include <list>
#include <exception>


template<class T>
struct MyComparator {
	T operator()(T a, T b) const {
		return a - b;
	}
};

template <class T>
class PriorityQueue {
   
public:
	
	void push(const T& t); 
	T poll();

private:
	std::list<T> m_queue;
};

template<class T>
inline void PriorityQueue<T>::push(const T& t)
{
	auto iter = m_queue.begin();
	while (iter != m_queue.end() && MyComparator<T>{}(*iter, t) < 0) {
		++iter;
	}
	m_queue.insert(iter, t);
}

template<class T>
inline T PriorityQueue<T>::poll()
{
	if (m_queue.empty())
		throw std::runtime_error("PriorityQueue empty !");
	T value = m_queue.front();
	m_queue.pop_front();
	return value;
}
