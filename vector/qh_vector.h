#ifndef QIHOO_VECTOR_H_
#define QIHOO_VECTOR_H_

namespace qh
{
    template<class T>
    class vector {
    public:
        //ctor
        vector()
            : data_(NULL), size_(0), capacity_(0)
        {
        }

        explicit vector( size_t n, const T& value = T())
        {
            data_ = new T[n];
	    size_ = n;
	    capacity_ = n;
            for (size_t i = 0; i < n; i++)
            {
                data_[i] = value;
            }
        }

        vector<T>& operator=(const vector<T>& rhs)
        {
            if(this == &rhs)
                return *this;
            delete[] data_;
            size_ = rhs.size_;
            capacity_ = rhs.capacity_;
            data_ = new T[capacity_];
            for(int i = 0;i < size_; i++) {
                data_[i] = rhs.data_[i];
            }
            return *this;
        }

        //dtor
        ~vector()
        {
            if (data_)
            {
                delete[] data_;
            }
        }

        //get
        size_t size() const
        {
            return size_;
        }
	
	size_t capacity() const
        {
            return capacity_;
        }

        // set & get
        T& operator[](size_t index) 
        {
	    return data_[index];
        }

        // set
        void push_back(const T& element)
        {
	   if(size_ == capacity_)
	   {
		 if(size_ == 0)
			reserve(1);
		 else
		 	reserve(2 * capacity_);
	   }
           data_[size_] = element;
           size_++;
	}
        void pop_back()
	{
            size_ --;
	}
        void resize(size_t size1, const T& value = T())
	{
	    if(size1 < size_)
            {
                        T* temp = new T[size1];
                        for(int i = 0;i < size1; i++) {
                                temp[i] = data_[i];
                        }
                        T* temp1 = temp;
                        temp = data_;
                        data_ = temp1;
                        delete[] temp;
                        size_ = size1;
            }else
            {

                        T* temp = new T[size1];
                        for(size_t i = 0;i < size_; i++) {
                                temp[i] = data_[i];
                        }
                        for(size_t j = size_;j<size1;j++) {
                                temp[j] = value;
                        }
                        T* temp1 = temp;
                        temp = data_;
                        data_ = temp1;
                        delete[] temp;
                        size_ = size1;
                        capacity_ = size1;  
             }
	}
        void reserve(size_t cap)
	{
		 if (cap > capacity_)
                {
                        T* temp = new T[cap];
                        for(int i =0;i < size_; i++) {
                                temp[i] = data_[i];
                        }   
                        capacity_ = cap;
                        T* temp1 = temp;
                        temp = data_;
                        data_ = temp1;
                        delete[] temp;
                }
	}
        void clear()
	{
		size_ = 0;
                capacity_ = 0;
	}
        bool empty()
	{
		return (size_ == 0);
	}

    private:
        T*      data_;
        size_t  size_;
	size_t  capacity_;
    };
}

#endif


