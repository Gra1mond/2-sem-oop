#pragma once

template <typename T>
struct ListNode {
    T data;
    ListNode<T>* next;
    ListNode(const T& value) : data(value), next(nullptr) {}
};
