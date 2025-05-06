#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class Queue {
private:
    std::vector<T> items;
    size_t frontIndex = 0;

public:
    void push(const T& item)
    {
        items.push_back(item);
    }

    T pop()
    {
        if (items.empty())
        {
            throw std::runtime_error("Queue is empty! Cannot pop.");
        }
        T removedItem = items[frontIndex];
        frontIndex++;

        if (frontIndex > items.size() / 2)
        {
            items.erase(items.begin(), items.begin() + frontIndex);
            frontIndex = 0;
        }
        return removedItem;
    }

    void display() const {
        std::cout << "Queue contents: ";
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
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    intQueue.push(10);
    intQueue.push(20);
    intQueue.display();

    try {
        intQueue.pop();
        intQueue.pop();
        intQueue.pop();
    } catch (const std::out_of_range& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}