#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H
#include <stdexcept>

class my_exception : public std::runtime_error
{
public:
	using this_type = my_exception;        // 给自己起个别名
	using super_type = std::runtime_error;  // 给父类也起个别名
public:
	my_exception(const char* msg) :            // 构造函数
		super_type(msg)                      // 别名也可以用于构造
	{}

	my_exception() = default;                // 默认构造函数
	~my_exception() = default;                // 默认析构函数
private:
	int code = 0;                            // 其他的内部私有数据
};
#endif 