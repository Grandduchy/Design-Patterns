#ifndef SUBJECT_HPP
#define SUBJECT_HPP
#include <map>
#include <functional>
#include <algorithm>
#include <vector>

// This subject class works on functions
// Works by taking an event (as an integer) and the event will be tied to the function(observer)
// In using classes instead of functions, instead of a template of the observerfunction,
// use a base class with one function (e.g. update())

template<typename FSignature> // the function signature of the type it will hold
class Subject {
public:
    template<typename ObserverFunc>
    void registerObserver(const int eventNum, ObserverFunc&& observer);
    template<typename ObserverFunc>
    void removeObserver(ObserverFunc&& observer);

    void notify(const int eventNum) const;
private:
        std::map<int, std::vector<std::function<FSignature>>> observers; // Keeps track of each observer on each specific event/integer
};



template<typename FSignature>
template<typename ObserverFunc>
void Subject<FSignature>::registerObserver(const int eventNum, ObserverFunc&& observer) {
    observers[eventNum].push_back(std::forward<ObserverFunc>(observer)); // add the observer to the map
}

template<typename FSignature>
template<typename ObserverFunc>
void Subject<FSignature>::removeObserver(ObserverFunc&& observer) {
	// remove ALL ties to any events from the observer
    for (auto begin = observers.begin(); begin != observers.end(); begin++) {
        auto findIter = std::find(begin->second.begin(), begin->second.end(), std::forward<ObserverFunc>(observer));
        if (findIter != begin->second.end())
            begin->second.erase(findIter);
    }
}

template<typename FSignature>
void Subject<FSignature>::notify(const int eventNum) const {
	// Call each function in the event.
    auto iter = observers.find(eventNum);
    if (iter != observers.end()) {
        for (auto func : iter->second)
            func();
    }
}


#endif // SUBJECT_HPP
