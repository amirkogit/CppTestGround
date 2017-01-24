template<class T>
class X
{

};


template<class T> void f(T);
template<class T> void f(int, T, double);

template<class T>
class X<T*>
{

};

template<>
class X<int>
{

};

int main__()
{
    return 0;
}