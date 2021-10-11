#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory>

using namespace std;

class Test
{
public:
    Test()
    {
        cout << "Test 생성자" << endl;
    }
    ~Test()
    {
        cout << "Test 소멸자" << endl;
    }
};

class Cat
{
public:
    string name = "없음";

    Cat()
    {
        cout << "Cat 생성자" << endl;
    }

    ~Cat()
    {
        cout << "Cat 소멸자" << endl;
    }

    void Say()
    {
        cout << "내 이름은: " << this->name << endl;
    }

private:
    Test t;
};

void foo(unique_ptr<Cat> c)
{
    c->Say();
}

int main(void)
{
    cout << "전" << endl;
    {
        unique_ptr<Cat> c = make_unique<Cat>();
        foo(move(c));
    }
    cout << "후" << endl;

    return 0;
}