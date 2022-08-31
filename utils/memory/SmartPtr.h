#ifndef __SmartPtr_H__
#define __SmartPtr_H__

#include <iostream>

// A generic smart pointer class
template <class T>
class SmartPtr
{
    T *m_Ptr; // Actual pointer

public:
    // Constructor
    explicit SmartPtr(T *p = NULL) { m_Ptr = p; }

    // Destructor
    ~SmartPtr() { delete (m_Ptr); }

    // Overloading dereferencing operator
    T &operator*() { return *m_Ptr; }

    // Overloading arrow operator so that
    // members of T can be accessed
    // like a pointer (useful if T represents
    // a class or struct or union type)
    T *operator->() { return m_Ptr; }
};

#endif // __SmartPtr_H__