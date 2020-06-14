#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H
#include <stdexcept>

class my_exception : public std::runtime_error
{
public:
	using this_type = my_exception;        // ���Լ��������
	using super_type = std::runtime_error;  // ������Ҳ�������
public:
	my_exception(const char* msg) :            // ���캯��
		super_type(msg)                      // ����Ҳ�������ڹ���
	{}

	my_exception() = default;                // Ĭ�Ϲ��캯��
	~my_exception() = default;                // Ĭ����������
private:
	int code = 0;                            // �������ڲ�˽������
};
#endif 