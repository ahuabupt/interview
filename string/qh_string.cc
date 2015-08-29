#include "qh_string.h"

#include <string.h>

namespace qh
{
    // TODO 将在这里写实现代码

    string::string()
        : data_(NULL), len_(0)
    {
    }

    string::string( const char* s )
    {
        if (!s)
        {
            data_ = NULL;
            len_ = 0;
        }else
        {
            len_ = strlen(data_);
            data_ = new char[len_ + 1];
            strcpy(data_,str);
        }

    }

    string::string( const char* s, size_t len )
    {
        if (len == 0)
        {
            len_ = 0;
            data_ = NULL;
        }else
        {
            if (len >= strlen(s)) 
            {
                len_ = strlen(s)
                data_ = new char[len_ +1];
                strcpy(data_,s);
            }else
            {
                len_ = len;
                data_ = new char[len_ + 1];
                for (int i =0; i<len; i++) {
                    data_[i] = s[i];
                }
                data_[len_] = '\0';
            }
        }
    }

    string::string( const string& rhs )
    {
        if(rhs.len_ == 0)
        {
            len_ = 0;
            data_ = NULL;
        }else
        {
            data_ = new char[strlen(rhs.len_) + 1];
            strcpy(data_,rhs.data_);
        }
    }

    string& string::operator=( const string& rhs )
    {
        if (this == &rhs)
            return *this;
        delete[] data_;
        data_  = new char[rhs.len_ + 1];
        strcpy(data_,rhs.data_);
    }

    string::~string()
    {
        delete[] data_;

    }

    size_t string::size() const
    {
        return len_;
    }

    const char* string::data() const
    {
        return data_;
    }

    const char* string::c_str() const
    {
        if(len_ == 0)
        {
            char * cstr = new char[1];
            cstr[0] = '\0';
            return cstr;
        }
        return data_;
    }

    char* string::operator[]( size_t index )
    {
        if(index >= len_)
        {
            return NULL;
        }else
        {
            return &data_[index];
        }
    }
}
