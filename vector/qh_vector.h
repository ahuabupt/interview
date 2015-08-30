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

        // set & get
        T& operator[](size_t index);

        // set
        void push_back(const T& element);
        void pop_back(const T& element);
        void resize(size_t size, const T& value = T());
        void reserve(size_t capacity_);
        void clear();
        bool empty();

    private:
        T*      data_;
        size_t  size_;
        size_t capacity_;  // number of elements that can be stored
    };
}

#endif


