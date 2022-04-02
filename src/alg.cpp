// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int prior(char sym) {
    if (sym == '*' || sym == '/') {
        return 2;
    } else if (sym == '+' || sym == '-') {
        return 1;
    } else {
        return 0;
    }
}

std::string infx2pstfx(std::string inf) {
    std::string result = "";
    TStack<char, 100> st;
    for (int i=0; i<inf.length(); i++) {
        char c = inf[i];
        if (c>='0' && c<='9') {
            result += c;
            result += ' ';
        } else if (c=='(') {
            st.push(c);
        } else if (c==')') {
            while (st.top() != '(') {
                result += st.pop();
                result += ' ';
            }
            st.pop();
        } else {
            while (!st.isEmpty() && prior(c) <= prior(st.top())) {
                result += st.pop();
                result += ' ';
            }
            st.push(c);
        }
    }
    while (!st.isEmpty()) {
        result += st.pop();
        result += ' ';
    }
    return result;
}

int charConv(char c) {
    switch (c) {
        case '1': return 1; break;
        case '2': return 2; break;
        case '3': return 3; break;
        case '4': return 4; break;
        case '5': return 5; break;
        case '6': return 6; break;
        case '7': return 7; break;
        case '8': return 8; break;
        case '9': return 9; break;
        default: return 0; break;
    }
}

int eval(std::string post) {
    std::string post1 = post;
    int count = 0;
    for (int i = 0; i < post.length(); i++) {
        if (post[i] == ' ') {
            continue;
        } else {
            post1[count] = post[i];
            count++;
        }
    }
    TStack<char, 100> st;
    for (int i = 0; i < post1.length(); i++) {
        char c = post1[i];
        if (c==' ') {
            break;
        } else if (c >= '0' && c <= '9') {
            st.push(charConv(c));
        } else {
            int num1 = st.pop();
            int num2 = st.pop();
            if (c == '+') {
                st.push(num2 + num1);
            } else if (c == '-') {
                st.push(num2 - num1);
            } else if (c == '/') {
                st.push(num2 / num1);
            } else if (c == '*') {
                st.push(num2 * num1);
            }
        }
    }
    return st.top();
}
