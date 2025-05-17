#include <iostream>
#include <vector>
#include <string>
#include <stdexcept> 

template <typename T>
class Queue {
private:
    std::vector<T> data;

public:
    void push(const T& item) {
        data.push_back(item);
    }

    void pop() {
        if (data.empty()) {
            throw std::out_of_range("Невозможно извлечь из пустой очереди!");
        }
        data.erase(data.begin());
    }

    T front() const {
        if (data.empty()) {
            throw std::out_of_range("Очередь пуста.");
        }
        return data.front();
    }

    bool empty() const {
        return data.empty();
    }

    void display() const {
        std::cout << "Очередь содержит: ";
        for (const auto& item : data) {
            std::cout << item << " ";
        }
        std::cout << "\n";
    }
};
int main() {
    Queue<int> intQueue;

    try {
        intQueue.pop();
    } catch (const std::out_of_range& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }

    intQueue.push(50);
    intQueue.push(100);
    intQueue.display();

    try {
        intQueue.pop();
        intQueue.pop();
        intQueue.pop();
    } catch (const std::out_of_range& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }

    return 0;
}
