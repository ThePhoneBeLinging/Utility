//
// Created by eal on 17/02/25.
//

#ifndef OBSERVABLEVALUE_H
#define OBSERVABLEVALUE_H
#include <functional>
#include <mutex>
#include <vector>


template <typename T>
class ObservableValue
{
public:
    explicit ObservableValue(T value)
    {
        this->value = value;
    }

    T getValue()
    {
        std::lock_guard<std::mutex> lock(mutex_);
        return value;
    }

    void setValue(T value)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        this->value = value;
        for (const auto& fun : callbacks_)
        {
            fun(value);
        }
    }

    void subscribe(std::function<void(T)> callback)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        callbacks_.push_back(callback);
    }

    void unsubscribe(std::function<void(T)> callback)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        callbacks_.erase(std::remove(callbacks_.begin(), callbacks_.end(), callback));
    }

private:
    std::mutex mutex_;
    std::vector<std::function<void(T t)>> callbacks_;
    T value;
};



#endif //OBSERVABLEVALUE_H
