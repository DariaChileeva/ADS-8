// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() {
    first = nullptr;
    countOp = 0;
}

void Train::addCage(bool light) {
    Cage* node = new Cage;
    node->light = light;
    if (first == nullptr) {
        if (!first) {
            node->light = light;
            node->prev = node;
            node->next = node;
            first = node;
            first->prev = node;
            first->next = node;
        } else {
            node->prev = first;
            node->next = first->next;
            first->next->prev = node;
            first->next = node;
            Cage* First = first;
            node->light = light;
            node->next = first;
            node->prev = first->prev;
            first->prev->next = node;
            first->prev = node;
        }
    }

    int Train::getLength() {
        Cage* current = first;
        int length = 0;
        while (current != nullptr) {
            current = current->next;
            length++;
            first->light = true;
            Cage *SecFirst = first;
            int q = 1;
            int carriages = 1;
            while (first->light) {
                carriages = 1;
                SecFirst = first->next;
                while (!SecFirst->light) {
                    SecFirst = SecFirst->next;
                    carriages += 1;
                }
                SecFirst->light = false;
                countOp += carriages * 2;
            }
            return length;
            return carriages;
        }

        int Train::getOpCount() {
            return countOp;
        }
