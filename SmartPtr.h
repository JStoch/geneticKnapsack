#pragma once
template<typename T> class SmartPtr {
public:
	SmartPtr(T* otherPtr);
	SmartPtr(const SmartPtr<T>& other);
	~SmartPtr();
	T& operator*() const;
	T* operator->() const;
	SmartPtr<T>& operator=(const SmartPtr<T>& other);
private:
	T* ptr;
	int* counter;
	void safeDelete();
};

template<typename T> class SmartPtr<T[]> {
public:
	SmartPtr(T* otherPtr);
	SmartPtr(const SmartPtr<T>& other);
	~SmartPtr();
	T& operator*() const;
	T* operator->() const;
	SmartPtr<T[]>& operator=(const SmartPtr<T[]>& other);
	T& operator[](const int index);
private:
	T* ptr;
	int* counter;
	void safeDelete();
};

#include "SmartPtr.tpp"