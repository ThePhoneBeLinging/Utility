//
// Created by eal on 17/02/25.
//

#ifndef OBSERVABLEVALUE_H
#define OBSERVABLEVALUE_H
#include <functional>
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
        return value;
    }

    void setValue(T value)
    {
        this->value = value;
        for (const auto& fun : callbacks_)
        {
            fun(value);
        }
    }

    void subscribe(std::function<void(T)> callback)
    {
        callbacks_.push_back(callback);
    }

    void unsubscribe(std::function<void(T)> callback)
    {
        callbacks_.erase(std::remove(callbacks_.begin(), callbacks_.end(), callback));
    }

private:
    std::vector<std::function<void(T t)>> callbacks_;
    T value;
};



#endif //OBSERVABLEVALUE_H
