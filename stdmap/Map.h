#pragma once
#include <vector>
#include <initializer_list>
#include <iostream>

template<typename K, typename V>
class Map
{
private:
	std::vector<K> keys = std::vector<K>();
	std::vector<V> values = std::vector<V>();
	int size = 0;
public:
	Map() = default;	

#pragma region methods
public:

	void Insert(const K& _key, const V& _value);
	void Remove(const K& _key);
	void Clear();
	void Display() const;

	int IndexOf(const K& _key) const;
	bool IsEmpty() const;
	bool Contains(const K& _key) const;
	
	/// <summary>
	/// Set the value at index
	/// </summary>
	/// <param name="_index">index of map</param>
	/// <returns>return value of index</returns>
	V& At(int _index);

	/// <summary>
	/// Set the value at index
	/// </summary>
	/// <param name="_index">index of map</param>
	/// <returns>return value of index</returns>
	V& operator[](int _index);

#pragma endregion methods
};

#pragma region methods
template<typename K, typename V>
inline void Map<K, V>::Insert(const K& _key, const V& _value)
{
	if (Contains(_key)) {
		values.at(IndexOf(_key)) = _value;
		return;
	}
	keys.push_back(_key);
	values.push_back(_value);
}

template<typename K, typename V>
inline void Map<K, V>::Remove(const K& _key)
{
	if (!Contains(_key)) {
		std::cout << "Key not found." << std::endl;
	}
	int _index = IndexOf(_key);
	keys.erase(_index);
	values.erase(_index);
}

template<typename K, typename V>
inline void Map<K, V>::Clear()
{
	keys.clear();
	values.clear();
}

template<typename K, typename V>
inline void Map<K, V>::Display() const
{
	size_t _size = keys.size();
	if (_size == 0) {
		std::cout << "Nothing in map" << std::endl;
		return;
	}
	for (int i = 0; i < _size; i++)
		std::cout << "[" << i << "] => key: " << keys.at(i) << ", value: " << values.at(i) << std::endl;
}

template<typename K, typename V>
inline int Map<K, V>::IndexOf(const K& _key) const
{
	bool found = false;
	size_t _size = keys.size();
	int _index = -1;
	for (int i = 0; i < _size && !found; i++)
	{
		found = keys.at(i) == _key;
		if (found) _index = i;
	}
	return _index;
}

template<typename K, typename V>
inline bool Map<K, V>::IsEmpty() const
{
	return keys.size() > 0;
}

template<typename K, typename V>
inline bool Map<K, V>::Contains(const K& _key) const
{
	bool found = false;
	size_t _size = keys.size();
	for (int i = 0; i < _size && !found; i++)
		found = keys.at(i) == _key;
	return found;
}

template<typename K, typename V>
inline V& Map<K, V>::At(int _index)
{
	_index -= 1;
	if (_index < 0 || _index > keys.size()) throw std::exception("Out of range");
	return values.at(_index);
}

template<typename K, typename V>
inline V& Map<K, V>::operator[](int _index)
{
	_index -= 1;
	if (_index < 0 || _index > keys.size()) throw std::exception("Out of range");
	return values.at(_index);
}

#pragma endregion methods