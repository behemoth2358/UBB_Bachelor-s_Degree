#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

// basic exception class implementation
class vector_exception : public std::runtime_error
{
public:
	vector_exception(const std::string &message) : std::runtime_error(message) {}
};

template<typename T>
class vector
{
private:
	T* m_Data;
	size_t m_Size;
	size_t m_Capacity;

	void _realloc(size_t capacity) {
		if (m_Data == nullptr) {
			m_Data = new T[capacity];
			m_Capacity = capacity;
			return;
		}

		T *data = new T[capacity];

		for (size_t i = 0; i < m_Size; i++)
			data[i] = m_Data[i];

		if (data == nullptr) {
			throw vector_exception("Unnable to realloc vector memory!");
		}

		delete[] m_Data;

		m_Data = data;
		m_Capacity = capacity;
	}

	void check_bounds(size_t index) const {
		if (index >= m_Size)
			throw vector_exception("Index is out of bounds!");
	}

public:
	vector(size_t capacity) : m_Capacity(capacity),m_Size(capacity){
		m_Data = new T[capacity];
	}

	vector(size_t capacity, const T &val) : m_Capacity(capacity),m_Size(capacity) {
		m_Data = new T[capacity];

		for (size_t i = 0; i < m_Size; i++) {
			m_Data[i] = val;
		}
	}

	vector(const vector &x) {
		if(m_Size)
			delete [] m_Data;

		m_Size = x.size();

		_realloc(m_Size);

		for (size_t i = 0; i < m_Size; i++) {
			m_Data[i] = x[i];
		}
	}

	vector() : m_Size(0),m_Capacity(0),m_Data(nullptr) {
	}

	~vector() {
		delete[] m_Data;
	}

	T &at(size_t index) {
		return m_Data[index];
	}

	const T &back() const {
		check_bounds(m_Size - 1);

		return m_Data[m_Size - 1];
	}

	T &back() {
		check_bounds(0);

		return m_Data[m_Size - 1];
	}

	const T &front()const {
		check_bounds(0);

		return m_Data[0];
	}

	T &front() {
		check_bounds(0);
		return m_Data[0];
	}

	size_t capacity() const {
		return m_Capacity;
	}

	size_t size() const{
		return m_Size;
	}

	bool empty() const{
		return m_Size == 0;
	}

	void push_back(const T &val){
		if (m_Size >= m_Capacity) {
			_realloc(2 * m_Capacity + 1);
		}

		m_Data[m_Size++] = val;
	}

	void pop_back(){
		if (!m_Size) return;

		// call the destructor for the object
		(reinterpret_cast<T*>(m_Data)[m_Size - 1]).~T();

		// decrease the current vector size
		m_Size--;
	}

	T &operator [](size_t index) {
		check_bounds(index);

		return m_Data[index];
	}

	const T &operator[](size_t index) const {
		check_bounds(index);

		return m_Data[index];
	}

	size_t find(const T &val) const {
		for (size_t i = 0; i < m_Size; i++) {
			if (m_Data[i] == val) {
				return i;
			}
		}

		return -1;
	}

	void erase(const size_t position) {
		check_bounds(position);
		
		// call the destructor for the element
		(reinterpret_cast<T*>(m_Data)[position]).~T();

		// shift the elements to the left
		for (size_t i = position; i < m_Size - 1; i++) {
			m_Data[i] = m_Data[i + 1];
		}

		m_Size--;
	}

	vector<T> &operator =(const vector<T> &x) {
		vector temp(x);

		return temp;
	}
};

#endif