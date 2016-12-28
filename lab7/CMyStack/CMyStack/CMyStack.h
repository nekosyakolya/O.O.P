#pragma once
#include <memory>

template <typename T>
class CMyStack
{

	struct Node
	{
		Node(const T &value, const std::shared_ptr<Node> &next = nullptr)
			: value(value)
			, next(next)
		{
		};
		T value;
		std::shared_ptr<Node> next;
	};
public:
	CMyStack():
		m_size(0),
		m_top(nullptr)
	{
	};


	Clear()
	{
		while (m_top != nullptr)
		{

		}
	}

	~CMyStack()
	{
		Clear();
	};

private:
	std::shared_ptr<Node> m_top;
	size_t m_size;
};

