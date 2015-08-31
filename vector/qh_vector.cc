#include "qh_vector.h"


namespace qh {
	template<class T>

	 // set & get
        T& vector::operator[](size_t index)
        {
        	return data_[index];
        }

        // set
        void vector::push_back(const T& element) {
        	if(size_ == capacity_)
                        reserve(2 * capacity_);
                data_[size_+1] = element;
                size_++;
        }
        void pop_back(const T& element) {
                element = data_[size_-1];
                size_ --;
        }
        void resize(size_t size, const T& value) {
                if(size < size_t)
                {
                        T* temp = new T[size];
                        for(int i = 0;i < size; i++) {
                                temp[i] = data_[i];
                        }
                        T* temp1 = temp;
                        temp = data_;
                        data_ = temp1;
                        delete[] temp;
                        size_ = size;
                }else
                {

                        T* temp = new T[size];
                        for(int i = 0;i < size_; i++) {
                                temp[i] = data_[i];
                        }
                        for(int j = size_;j<size;j++) {
                                temp[j] = value;
                        }
                        T* temp1 = temp;
                        temp = data_;
                        data_ = temp1;
                        delete[] temp;
                        size_ = size;
                        capacity_ = size;  
                }

        }
        void reserve(size_t capacity) {
                if (capacity > capacity_)
                {
                        T* temp = new T[capacity];
                        for(int i =0;i < size_; i++) {
                                temp[i] = data_[i];
                        }   
                        capacity_ = capacity;
                        T* temp1 = temp;
                        temp = data_;
                        data_ = temp1;
                        delete[] temp;
                }
        }
        void clear() {
                size_ = 0;
                capacity_ = 0;
        }
        bool empty() {
                return (size_ == 0);
        }
}