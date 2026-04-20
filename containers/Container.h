/*
1. Написать Container<T>
   └── поля, конструкторы, деструктор
   └── push, pop, find, resize
   └── operator[], операторы присваивания

2. Написать Set<T> : public Container<T>
   └── push с проверкой уникальности + сортировка
   └── pop с проверкой существования
   └── is_element, q_find (бинарный поиск)
   └── +=, -=, *=, +, -, *, ==
   └── friend operator

3. Специализировать методы для char*
   └── сравнение через strcmp
   └── копирование строк через strcpy/new
*/

template <typename T>
class Container{
protected:
    T* pdata;
    int size;
    int max_size;
public:
    virtual void push(T element);
    void pop(int index);
    int find(T element);
    void resize(int new_size);

    T& operator[](int index){return pdata[index];}
    Container& operator=(const Container& other);//присваивание (глубокое копирование)
    Container& operator=(Container&& other);//перемещающее присваивание (move)

    Container(int input_max_size);
    Container();
    Container(const Container&);
    Container(Container&&);
    virtual ~Container();  
};

template<typename T>
Container<T>::Container(){
    this->max_size=8;
    this->size=0;
    this->pdata=new T[max_size];
}

template<typename T>
Container<T>::Container(int input_max_size){
    this->max_size=input_max_size;
    this->size=0;
    this->pdata=new T[max_size];
}

template<typename T>
Container<T>::Container(const Container& other){
    this->max_size = other.max_size;
    this->size = other.size;
    this->pdata = other.pdata;
}

template<typename T>
Container<T>::Container(Container&& other){
    if (this!=other){
        delete pdata;

        pdata = other.pdata;
        size=other.size;
        max_size=other.max_size;

        other.pdata = nullptr;
        other.size = 0;
        other.max_size = 0;
    }
    return *this;
}

template<typename T>
Container<T>::~Container(){
    delete[] pdata;
    pdata = nullptr;
}

template<typename T>
Container<T>& Container<T>::operator=(const Container& other){
    if (this!=other){
        delete[] pdata;
        max_size = other.max_size;
        size = other.size;
        pdata = new T[max_size];
        for(int i{0};i<size;i++){
            pdata[i]=other.pdata[i];
        }
    }
    return *this;
}

template<typename T>
Container<T>& Container<T>::operator=(Container&& other){
    if(this!=&other){
        delete[] pdata;

        pdata = other.pdata;
        size=other.size;
        max_size=other.max_size;

        other.pdata = nullptr;
        other.max_size = 0;
        other.size = 0;

    }
    return *this;
}

template<typename T>
void Container<T>::push(T element){
    
}