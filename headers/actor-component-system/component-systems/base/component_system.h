#pragma once
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

template <typename T> 
class ComponentSystem {
public:
    void add(int id, T data) {
        Component component { id, data };
        auto it = find_it(id);
        components.insert(it, component);
    }
    
    bool remove(int id) {
        auto it = find_it(id);
        if (it == components.end() || it->id != id) {
            return false;
        }
        components.erase(it);
        return true;
    }

    T* get(int id) {
        auto it = find_it(id);
        if (it == components.end() || it->id != id) {
            return nullptr;
        }
        return &it->data;        
    }
protected:
    struct Component {
        int id;
        T data;
    };
    std::vector<Component> components;

private: 
    auto find_it(int id) {
        return std::lower_bound(
            components.begin(), 
            components.end(), 
            id,
            [](const Component &c0, int id) -> bool {
                return c0.id < id;
            }
        );
    }
};

// #pragma once
// #include <unordered_map>
// #include <vector>
// #include <algorithm>

// template <typename T> 
// class EntitySystem {
// private:
//     struct Component {
//         int id;
//         T data;
//     };
// public:
//     void add(int id, T component) {
//         components.push_back(component);
//         id2Index[id] = components.size() - 1;
//         index2Id[components.size() - 1] = id;
//     }
    
//     bool remove(int id) {
//         if (id2Index.count(id) != 1) {
//             return false;
//         }

//         int index = id2Index[id];     
//         std::iter_swap(components.begin() + index, components.end() - 1);        
         
//         int swappedId = index2Id[components.size() - 1];
//         id2Index[swappedId] = index;
//         index2Id[index] = swappedId;

//         id2Index.erase(id);
//         index2Id.erase(components.size() - 1);       
        
//         components.pop_back();
//         return true;
//     }

//     T* get(int id) {
//         if (id2Index.count(id) != 1) {
//             return nullptr;
//         }        
//         int index = id2Index[id];
//         return &components[index];
//     }

// protected:
//     std::vector<T> components;
// private:
//     std::unordered_map<int, int> id2Index;
//     std::unordered_map<int, int> index2Id;    
// };