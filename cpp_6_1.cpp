/*
template
*/

#include <iostream>
#include <string>

// 아래 정의되는 클래스에 대해 템플릿을 정의
// 템플릿 인자는 T
// T는 반드시 어떤 타입의 이름임을 명시함
// 템플릿 문장 아래 오는 것이 class Vector 이므로
// 이 Vector 클래스에 대한 템플릿을 명시하는 것
template <typename T>
class Vector {
    // member variable (멤버 변수)
    T* data;  // 템플릿 인자로 들어오는 타입을 포인터로 사용
    int capacity;
    int length;

    public:
        // class constructor (클래스 생성자)
        // argument 가 있는 생성자를 사용한 초기화
        Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {}  // 이 문법 이름이 뭐임?
        // 왜 이렇게 써야되는거지...

        // member function (멤버 함수)
        // ??
        void push_back(T s) {
            if (capacity <= length)
            {
                T *temp = new T[capacity * 2];
                for (int i = 0; i < length; i++)
                {
                    temp[i] = data[i];
                }
                delete[] data;
                data = temp;
                capacity *= 2;
            }
            data[length] = s;
            length++;
        }

        // operator overloading for []
        // 임의 위치 원소에 접근
        T operator[](int i) { return data[i]; }

        // x 번째 위치한 원소 제거
        void remove(int x) {
            for (int i = x + 1; i < length; i++) {  // x 다음 원소부터 끝까지 앞으로 당김
                data[i - 1] = data[i];
            }
            length--;
        }

        // 현재 벡터 크기 반환
        int size() { return length; }

    // 소멸자
    ~Vector() {
        if (data) {
            delete[] data;
        }
    }
};

int main() {
    // 클래스<타입> 인스턴스
    Vector<int> int_vec;

    std::cout << "str vec" << std::endl;
    int_vec.push_back(3);
    int_vec.push_back(2);

    std::cout << int_vec[0] << std::endl; 
    std::cout << int_vec[1] << std::endl; 

    std::cout << std::endl;

    Vector<std::string> str_vec;
    std::cout << "str vec" << std::endl;
    str_vec.push_back("ABC");
    str_vec.push_back("EFG");

    std::cout << str_vec[0] << std::endl; 
    std::cout << str_vec[1] << std::endl; 

    return 0;
}