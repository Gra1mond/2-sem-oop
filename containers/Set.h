#include "Container.h"
/*
Элементы уникальны
Элементы отсортированы
*/

template<typename T>
class Set : public Container<T> {
 public:
    Set() : Container<T>() {}
    Set(T element) : Container<T>() {
        this->pdata[0] = element;
        this->size = 1;
    }

    bool is_element(T element) const;
    int q_find(T element) const;
    void q_sort(int, int);
    void sorting();

    void push(T element);
    void pop(T element);

    Set& operator+=(const Set& other);
    Set& operator-=(const Set& other);
    Set& operator*=(const Set& other);

    Set operator+(const Set& other);
    Set operator-(const Set& other);
    Set operator*(const Set& other);
    bool operator==(const Set& other) const;

    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, const Set<U>& s);

    ~Set() override;
};

template<typename T>
void Set<T>::push(T element) {
    if (is_element(element)) {
        return;
    }
    Container<T>::push(element);
    sorting();
}

template<typename T>
bool Set<T>::is_element(T element) const {
    int answer = q_find(element);
    if (answer == -1) {
        return false;
    } else {
        return true;
    }
}

template<typename T>
void Set<T>::pop(T element) {
    int index = q_find(element);
    if (index == -1) {
        return;
    }
    for (int i = index; i < this->size - 1; ++i) {
        this->pdata[i] = this->pdata[i + 1];
    }
    this->size--;
    if (this->size < this->max_size / 4) {
        this->resize(this->max_size / 2);
    }
}

template<typename U>
std::ostream& operator<<(std::ostream& out, const Set<U>& c) {
    for (int i{0}; i < c.size; ++i) {
        out << c.pdata[i] << " ";
    }
    return out;
}

template<typename T>
void Set<T>::q_sort(int left, int right) {
    if (left >= right) {
        return;
    }
    T pivot = this->pdata[(left + right) / 2];

    int i = left, j = right;
    while (i <= j) {
        while (this->pdata[i] < pivot) {
            ++i;
        }
        while (this->pdata[j] > pivot) {
            --j;
        }
        if (i <= j) {
            T tmp = this->pdata[i];
            this->pdata[i] = this->pdata[j];
            this->pdata[j] = tmp;
            ++i;
            --j;
        }
    }
    q_sort(left, j);
    q_sort(i, right);
}

template<typename T>
void Set<T>::sorting() {
    if (this->size > 1) {
        q_sort(0, this->size - 1);
    }
}

template<typename T>
int Set<T>::q_find(T element) const {
    int left = 0;
    int right = this->size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (this->pdata[mid] == element) {
            return mid;
        } else if (this->pdata[mid] < element) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

template<typename T>
Set<T>& Set<T>::operator+=(const Set& other) {
    for (int i = 0; i < other.size; i++)
        push(other.pdata[i]);
    return *this;
}
template<typename T>
Set<T>& Set<T>::operator-=(const Set& other) {
    for (int i = 0; i < other.size; i++) {
        int index = q_find(other.pdata[i]);
        if (index != -1) {
            Container<T>::pop(index);
        }
    }
    return *this;
}

template<typename T>
Set<T>& Set<T>::operator*=(const Set& other) {
    for (int i = this->size - 1; i >= 0; --i) {
        if (!other.is_element(this->pdata[i])) {
            Container<T>::pop(i);
        }
    }
    return *this;
}

template<typename T>
Set<T> Set<T>::operator+(const Set& other) {
    Set result = *this;
    result += other;
    return result;
}

template<typename T>
Set<T> Set<T>::operator-(const Set& other) {
    Set result = *this;
    result -= other;
    return result;
}

template<typename T>
Set<T> Set<T>::operator*(const Set& other) {
    Set result = *this;
    result *= other;
    return result;
}

template<typename T>
bool Set<T>::operator==(const Set& other) const {
    if (this->size != other.size) {
        return false;
    }
    for (int i{0}; i < this->size; ++i) {
        if (this->pdata[i] != other.pdata[i]) {
            return false;
        }
    }
    return true;
}

template<typename T>
Set<T>::~Set() {
}

//---------Специализация-------------

template<>
void Set<char*>::q_sort(int left, int right) {
    if (left >= right) {
        return;
    }
    char* pivot = this->pdata[(left + right) / 2];

    int i = left, j = right;
    while (i <= j) {
        while (strcmp(this->pdata[i], pivot) < 0) {
            ++i;
        }
        while (strcmp(this->pdata[j], pivot) > 0) {
            --j;
        }
        if (i <= j) {
            char* tmp = this->pdata[i];
            this->pdata[i] = this->pdata[j];
            this->pdata[j] = tmp;
            ++i;
            --j;
        }
    }
    q_sort(left, j);
    q_sort(i, right);
}

template<>
int Set<char*>::q_find(char* element) const {
    int left = 0;
    int right = this->size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (strcmp(this->pdata[mid], element) == 0) {
            return mid;
        }

        else if (strcmp(this->pdata[mid], element) < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

template<>
bool Set<char*>::operator==(const Set& other) const {
    if (this->size != other.size) {
        return false;
    }
    for (int i{0}; i < this->size; ++i) {
        if (strcmp(this->pdata[i], other.pdata[i]) != 0) {
            return false;
        }
    }
    return true;
}

