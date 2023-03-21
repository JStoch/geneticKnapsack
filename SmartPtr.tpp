#pragma once

template<typename T>
SmartPtr<T>::SmartPtr(T* otherPtr) {
	ptr = otherPtr;
	counter = new int(1);
}

template<typename T>
SmartPtr<T>::SmartPtr(const SmartPtr<T>& other) {
	ptr = other.ptr;
	counter = other.counter;
	(*counter)++;
}

template<typename T>
SmartPtr<T>::~SmartPtr() {
	safeDelete();
}

template<typename T>
void SmartPtr<T>::safeDelete() {
	(*counter)--;
	if (counter == 0) {
		delete ptr;
		delete counter;
	}
}

template<typename T>
T& SmartPtr<T>::operator*() const {
	return *ptr;
}

template<typename T>
T* SmartPtr<T>::operator->() const {
	return ptr;
}

template<typename T>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<T>& other) {
	if (ptr != other.ptr) {
		safeDelete();
		ptr = other.ptr;
		counter = other.counter;
		(*counter)++;
	}
	return *this;
}

template<typename T>
SmartPtr<T[]>::SmartPtr(T* otherPtr) {
	ptr = otherPtr;
	counter = new int(1);
}

template<typename T>
SmartPtr<T[]>::SmartPtr(const SmartPtr<T>& other) {
	ptr = other.ptr;
	counter = other.counter;
	(*counter)++;
}

template<typename T>
SmartPtr<T[]>::~SmartPtr() {
	safeDelete();
}

template<typename T>
void SmartPtr<T[]>::safeDelete() {
	(*counter)--;
	if (counter == 0) {
		delete[] ptr;
		delete counter;
	}
}

template<typename T>
T& SmartPtr<T[]>::operator*() const {
	return *ptr;
}

template<typename T>
T* SmartPtr<T[]>::operator->() const {
	return ptr;
}

template<typename T>
SmartPtr<T[]>& SmartPtr<T[]>::operator=(const SmartPtr<T[]>& other) {
	if (ptr != other.ptr) {
		safeDelete();
		ptr = other.ptr;
		counter = other.counter;
		(*counter)++;
	}

	return *this;
}

template<typename T>
T& SmartPtr<T[]>::operator[](const int index) {
	return ptr[index];
}