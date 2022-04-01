// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
private:
    int first = -1;
    int last = size;
    int arr[size];
public:
    bool push(int x) {
        if (first >= (last - 1)) {
            return false;
        } else {
            arr[++first] = x;
            return true;
        }
    }
    int pop() {
        if (first < 0) {
            return 0;
        }
        else {
            int x = arr[first--];
            return x;
        }
    }
    int top() {
        return arr[first];
    }
    bool isEmpty() {
        return (first < 0);
    }
    bool isFull() {
        return (first == last - 1);
    }
};
#endif  // INCLUDE_TSTACK_H_
