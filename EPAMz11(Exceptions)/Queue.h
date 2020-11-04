#pragma once
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <cassert>
#include <iostream>

namespace EPAM
{
	template<typename Type>
	class Queue
	{
	public:
		Queue() = default;
		Queue(const Queue<Type>& old);
		Queue(Queue<Type>&& old);
		Queue(const std::initializer_list<Type>&& lst);

		~Queue();
	public:
		const Type& back () const noexcept { return this->mp_back->m_data;  }
		const Type& front() const noexcept { return this->mp_front->m_data; }
		size_t      size () const noexcept { return this->m_size;           }
		bool        empty() const noexcept { return this->m_size == 0;      }

		void push(Type elem);
		void push(const std::initializer_list<Type>&& elems);
		void pop ();
	public:
		template<typename Type>
		friend std::ostream& operator << (std::ostream& out, const Queue<Type>& object);
	private:
		void clear();
	private:
		template<typename Type>
		struct QueueNode
		{
			Type       m_data{};
			QueueNode<Type>* mp_next{};
			QueueNode<Type>* mp_prev{};

			QueueNode() = default;
			QueueNode(Type elem)
			{
				this->m_data = elem;
			}
			QueueNode(QueueNode<Type>* other)
			{
				this->m_data  = other->m_data;
				this->mp_next = other->mp_next;
				this->mp_prev = other->mp_prev;

				other->mp_next = nullptr;
				other->mp_prev = nullptr;
			}
			QueueNode<Type>& operator = (const QueueNode<Type>* other)
			{
				if (this == other)
					return *this;

				this->m_data  = other->m_data;
				this->mp_next = other->mp_next;
				this->mp_prev = other->mp_prev;
				
				return *this;
			}

			bool operator == (const QueueNode<Type>* other)
			{
				return this->m_data == other->m_data && this->mp_next == other->mp_next && this->mp_prev == other->mp_prev;
			}
			bool operator != (const QueueNode<Type>* other)
			{
				return this->m_data != other->m_data && this->mp_next != other->mp_next && this->mp_prev != other->mp_prev;
			}
		};

		QueueNode<Type> *mp_front{};
		QueueNode<Type> *mp_back{};
		size_t     m_size{};
	private:
		template<typename Type>
		class QueueIterator
		{
		public:
			QueueIterator(QueueNode<Type>* ptr) : mp_iter{ ptr } {}
		public:
			QueueNode<Type>* operator -> () const { return mp_iter;         }
			Type&            operator *  () const { return mp_iter->m_data; }
		public:
			QueueIterator<Type>& operator ++ ()
			{
				this->mp_iter = this->mp_iter->mp_prev;
				return *this;
			}
			QueueIterator<Type>  operator ++ (int)
			{
				QueueIterator<Type> temp(this->mp_iter);

				this->mp_iter = this->mp_iter->mp_prev;

				return temp;
			}
			QueueIterator<Type>& operator -- ()
			{
				this->mp_iter = this->mp_iter->mp_next;

				return *this;
			}
			QueueIterator<Type>  operator -- (int)
			{
				QueueIterator<Type> temp(this->mp_iter);

				this->mp_iter = this->mp_iter->mp_next;

				return temp;
			}
		public:
			bool operator == (const QueueIterator<Type>& other) { return this->mp_iter == other.mp_iter; }
			bool operator != (const QueueIterator<Type>& other) { return this->mp_iter != other.mp_iter; }
		public:
			friend class Queue<Type>;
		private:
			QueueNode<Type>* mp_iter{};
		};

		QueueIterator<Type> begin() const { return QueueIterator<Type>(this->mp_front);         }
		QueueIterator<Type> end  () const { return QueueIterator<Type>(this->mp_back->mp_prev); }

		using iterator = QueueIterator<Type>;
	};



	template<typename Type>
	Queue<Type>::Queue(const Queue<Type>& old)
	{
		Queue<Type>::iterator it(old.begin());

		for (const auto elem : old)
			this->push(elem);
	}
	template<typename Type>
	Queue<Type>::Queue(Queue<Type>&& old)
	{
		Queue<Type>::iterator it(old.begin());

		for (const auto elem : old)
			this->push(elem);

		old.clear();
	}
	template<typename Type>
	Queue<Type>::Queue(const std::initializer_list<Type>&& lst)
	{
		this->push(std::move(lst));
	}

	template<typename Type>
	void Queue<Type>::push(Type elem)
	{
		if (this->m_size == 0)
		{
			this->mp_front = new QueueNode<Type>(elem);
			this->mp_back  = this->mp_front;

			this->m_size++;
		}
		else if (this->m_size == 1)
		{
			this->mp_back           = new QueueNode<Type>(elem);
			this->mp_back->mp_next  = this->mp_front;
			this->mp_front->mp_prev = this->mp_back;

			this->m_size++;
		}
		else
		{
			try
			{
				auto temp = new QueueNode<Type>(this->mp_back);
				temp->mp_prev           = this->mp_back;

				temp->mp_next->mp_prev = temp;

				this->mp_back->m_data   = elem;
				this->mp_back->mp_next  = temp;

				this->m_size++;
			}
			catch (const std::bad_alloc& e)
			{
				assert(e.what());
			}
		}
	}
	template<typename Type>
	void Queue<Type>::push(const std::initializer_list<Type>&& elems)
	{
		for (const auto& elem : elems)
			this->push(elem);
	}
	template<typename Type>
	void Queue<Type>::pop()
	{
		if (this->m_size <= 0)
			throw std::exception("The queue is empty!");

		if (this->m_size == 1)
		{
			delete this->mp_front;

			this->m_size--;
		}
		else
		{
			QueueNode<Type>* temp = this->mp_front->mp_prev;
			delete this->mp_front;
			this->mp_front = temp;
			this->mp_front->mp_next = nullptr;

			this->m_size--;
		}
	}

	template<typename Type>
	void Queue<Type>::clear()
	{
		while (!empty())
			this->pop();
	}

	template<typename Type>
	Queue<Type>::~Queue()
	{
		this->clear();
	}

	template<typename Type>
	std::ostream& operator << (std::ostream& out, const Queue<Type>& object)
	{
		auto it{ object.begin() };
		auto itEnd{ object.end() };

		for (; it != itEnd; it++)
			out << *it << ' ';

		return out;
	}
};