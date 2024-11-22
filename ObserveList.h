#pragma once

struct Node {
    IObserver* observer;
    Node* next;
    Node(IObserver* obs) : observer(obs), next(nullptr) {}
};
class ObserverList {
private:
    Node* head;

public:
    ObserverList();

    ~ObserverList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(IObserver* obs) {
        Node* newNode = new Node(obs);
        newNode->next = head;
        head = newNode;
    }


    void remove(IObserver* obs) {
        Node* current = head;
        Node* prev = nullptr;

        while (current) {
            if (current->observer == obs) {
                if (prev) {
                    prev->next = current->next;
                }
                else {
                    head = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    void notify(float temperature, float humidity, float pressure) {
        Node* current = head;
        while (current) {
            current->observer->update(temperature, humidity, pressure);
            current = current->next;
        }
    }

};

inline ObserverList::ObserverList():head(nullptr) {}


