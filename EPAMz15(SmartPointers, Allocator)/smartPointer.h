#pragma once
#include <algorithm>
#include <memory>

namespace EPAM
{
	template<typename T>
	class unique_ptr
	{
	public:
		constexpr      unique_ptr () noexcept = default;
		explicit       unique_ptr (T* ptr) noexcept : p_ptr{ ptr } {}
		explicit       unique_ptr (unique_ptr<T>&& other) noexcept;

		unique_ptr<T>& operator = (unique_ptr&& other) noexcept;

		~unique_ptr();

		explicit       unique_ptr (const unique_ptr<T>& other) = delete;
		unique_ptr<T>& operator = (const unique_ptr<T>& other) = delete;
	public:
		T& operator *  () { return *this->p_ptr; }
		T* operator -> () { return  this->p_ptr; }

		operator bool() { return this->p_ptr != nullptr; }
	public:
		void swap   (unique_ptr<T>& other) noexcept;
		void reset  (T* anotherPtr)        noexcept;
		void release()                     noexcept;

		[[nodiscard]] T* get() const noexcept { return this->p_ptr; }
	private:
		T* p_ptr{};
	};



	template<typename T>
	unique_ptr<T>::unique_ptr(unique_ptr<T>&& other) noexcept
	{
		this->p_ptr = other.p_ptr;

		other.p_ptr = nullptr;
	}
	template<typename T>
	unique_ptr<T>& unique_ptr<T>::operator = (unique_ptr&& other) noexcept
	{
		if (this->p_ptr == other.p_ptr)
			return *this;

		this->p_ptr = other.p_ptr;

		other.p_ptr = nullptr;
	}
	template<typename T>
	unique_ptr<T>::~unique_ptr()
	{
		if (this->p_ptr)
		{
			delete this->p_ptr;
			this->p_ptr = nullptr;
		}
	}

	template<typename T>
	void unique_ptr<T>::swap(unique_ptr<T>& other) noexcept
	{
		std::swap(this->p_ptr, other.p_ptr);
	}
	template<typename T>
	void unique_ptr<T>::reset(T* anotherPtr) noexcept
	{
		if (this->p_ptr)
		{
			delete this->p_ptr;
			this->p_ptr = nullptr;
		}

		this->p_ptr = anotherPtr;
	}
	template<typename T>
	void unique_ptr<T>::release() noexcept
	{
		if (this->p_ptr)
		{
			delete this->p_ptr;
			this->p_ptr = nullptr;
		}
	}



	template<typename T, typename... Args>
	[[nodiscard]] unique_ptr<T> make_unique(Args&&... args)
	{
		return unique_ptr<T>(new T(std::forward<Args>(args)...));
	}
}