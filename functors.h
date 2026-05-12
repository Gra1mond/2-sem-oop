template<typename T>
struct Ascending {
    bool operator()(const T& a, const T& b) const {
        return a < b;
    }
};

template<typename T>
struct Descending {
    bool operator()(const T& a, const T& b) const {
        return b < a;
    }
};