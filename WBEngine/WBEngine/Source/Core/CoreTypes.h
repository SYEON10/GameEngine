#pragma once

template <typename T>
using TArray = std::vector<T>;

template <typename T>
using TQueue = std::queue<T>;

template <typename T>
using TStack = std::stack<T>;

template <typename Key, typename Value>
using TMap = std::unordered_map<Key, Value>;

template <typename T>
using TSet = std::unordered_set<T>;

template <typename T>
using TUniquePtr = std::unique_ptr<T>;

template <typename T>
using TSharedPtr = std::shared_ptr<T>;

template <typename T>
using TWeakPtr = std::weak_ptr<T>;

template <typename T>
using TFunction = std::function<T>;

template <typename T>
using TOptional = std::optional<T>;

template <typename ... Ts>
using TVariant = std::variant<Ts...>;