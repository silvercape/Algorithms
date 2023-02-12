//
// Created by 自制力 on 2023/2/12.
//

#include "MinHeap.hpp"

MinHeap::MinHeap() { heap = new int[MAXN]; }

MinHeap::~MinHeap() { delete heap; }

int MinHeap::size() { return tail; }

bool MinHeap::empty() { return tail == 0; }

void MinHeap::push(int x) {
    int index = tail;
    heap[tail++] = x;
    while (index > 0 && heap[(index - 1) >> 1] > heap[index]) {
        heap[(index - 1) >> 1] = heap[(index - 1) >> 1] ^ heap[index];
        heap[index] = heap[(index - 1) >> 1] ^ heap[index];
        heap[(index - 1) >> 1] = heap[(index - 1) >> 1] ^ heap[index];
        index = (index - 1) >> 1;
    }
}

void MinHeap::pop() {
    if (tail == 0)
        return;
    heap[0] = heap[tail - 1];
    tail = tail - 1;

    int index = 0;
    // While have left child
    while (2 * index + 1 < tail) {
        int sonIndex = (index << 1) + 1;
        if (sonIndex + 1 < tail && heap[sonIndex + 1] < heap[sonIndex])
            sonIndex++;
        if (heap[sonIndex] < heap[index]) {
            heap[sonIndex] = heap[sonIndex] ^ heap[index];
            heap[index] = heap[sonIndex] ^ heap[index];
            heap[sonIndex] = heap[sonIndex] ^ heap[index];
        } else {
            break;
        }

    }
}

int MinHeap::top() { return empty() ? -0x7fffffff : heap[0]; }