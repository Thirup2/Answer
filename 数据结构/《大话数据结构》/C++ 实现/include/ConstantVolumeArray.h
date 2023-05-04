#ifndef CONSTANTVOLUMEARRAY_H_
#define CONSTANTVOLUMEARRAY_H_

// -----------------------包含头文件-------------------------- //

// -----------------------类定义-------------------------- //
template<typename Type>
class ConstantVolumeArray
{
public:
    using value_type = Type;
    using reference = Type &;
    using const_reference = const Type &;
    using pointer = Type *;
    using const_pointer = const Type *;
    using size_type = unsigned int;
private:
    pointer head;
    size_type size;
public:

};

#endif