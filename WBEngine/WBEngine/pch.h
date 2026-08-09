#pragma once

// ===== 1. 표준 라이브러리: 컨테이너 =====
#include <vector>
#include <array>
#include <unordered_map>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <bitset>

// ===== 2. 표준 라이브러리: 유틸 =====
#include <memory>       // unique_ptr, shared_ptr
#include <functional>   // std::function, delegate 용
#include <algorithm>
#include <optional>

// ===== 3. 표준 라이브러리: 수학/IO =====
#include <cmath>
#include <cstdint> 

// ===== 4. 추후 개발 목적으로 현재는 STD 라이브러리 사용하는 케이스 =====

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

template <typename T>
using TVariant = std::variant<T>;
