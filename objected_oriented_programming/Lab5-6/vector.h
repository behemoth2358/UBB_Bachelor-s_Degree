#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>
#include <cstring>
#include <cstdlib>

template<typename T>
class vector{

private:
	T *arr;
	size_t vSize = 0;
	size_t vCapacity = 0;

	void _realloc(size_t newCapacity)
	{
		if(this->arr == nullptr)
		{
			this->arr = new T[ newCapacity ];
			this->vCapacity = newCapacity;
			this->vSize = 0;
		}
		else{
			T *new_arr = new T[ newCapacity ];
			for(size_t i = 0; i < this->vCapacity; i++)
			{
                new_arr[ i ] = this->arr[ i ];
			}
		//	delete[] this->arr;
			this->arr = new_arr;
			this->vCapacity = newCapacity;
		}
	}

	void _check_index(size_t index)
	{
		if(index >= this->vSize)
		{
			throw std::invalid_argument("Invalid index!");
		}
	}

public:

	vector(size_t n) : vCapacity(n), vSize(n)
	{
		this->arr = new T[ n ];
	}

	vector(size_t n, const T& val) : vCapacity(n), vSize(n)
	{
		this->arr = new T[ n ];

		for(size_t i = 0; i < this->vSize; i++)
		{
			this->arr[ i ] = val;
		}
	}

	vector(const vector& other)
	{
		if(this->vCapacity != 0)
		{
			delete[] this->arr;
		}

		this->vSize = other.size();

		_realloc(this->vSize);

		for(size_t i = 0; i < this->vSize; i++)
		{
			this->arr[ i ] = other[ i ];
		}
	}

	vector() : vSize(0), vCapacity(0), arr(nullptr)
	{}

	~vector()
	{
        if(this->vCapacity != 0)
		{
            delete[] this->arr;
        }
	}

	size_t size() const
	{
		return vSize;
	}

	bool empty() const
	{
		return this->vSize == 0;
	}

	void push_back(const T& val)
	{
		if(this->vSize >= this->vCapacity)
		{
			_realloc(2 * this->vSize + 1);
		}

		this->arr[ this->vSize ] = val;
		this->vSize++;
	}

	void pop_back()
	{
		if(this->vSize == 0)
		{
			return;
		}

		this->vSize--;
	}

	T& operator[](size_t index)
	{
	//	_check_index(index);
		return this->arr[ index ];
	}

	const T& operator[](size_t index) const
	{
	//	_check_index(index);
		return this->arr[ index ];
	}

	int find(const T& val)
	{
		for(size_t i = 0; i < this->vSize; i++)
		{
			if(this->arr[i] == val)
			{
				return i;
			}
		}
		return -1;
	}

	void erase(const size_t index)
	{
	//	_check_index(index);

		for(size_t i = index; i < this->vSize - 1; i++)
		{
			this->arr[ i ] = this->arr[ i + 1 ];
		}

		this->vSize--;
	}

	void clear()
	{
        if(this->vCapacity)
        {
            delete[] this->arr;
            this->arr = nullptr;
            this->vSize = 0;
            this->vCapacity = 0;}
	}

	vector<T>& operator=(const vector<T>& other)
	{
		if(this == &other)
		{
			return *this;
		}

		this->vSize = other.size();
		this->vCapacity = other.size();

		delete[] this->arr;

		this->arr = new T[ this->vCapacity ];

		for(size_t i = 0; i < this->vSize; i++)
		{
			this->arr[ i ] = other[ i ];
		}

		return *this;
	}

	vector<T>& operator-(T& val)
	{
        int pos=find(val);
        if(pos==-1)
        {
            return *this;
        }
        erase(pos);
        return *this;
	}
};

#endif
