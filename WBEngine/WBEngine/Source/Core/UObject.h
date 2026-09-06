#pragma once

#include "UObjectMinimal.h"

#define GENERATE_BODY(ClassName)                  \
public:                                                                    \
    static class UClass* StaticClass()                                          \
    {                                                                      \
        static UClass* StaticUClass_##ClassName =                         \
            new UClass();                                                   \
        return StaticUClass_##ClassName;                                  \
    }                                                                      \
    virtual class UClass* GetClass() const override                             \
    {                                                                      \
        return StaticClass();                                             \
    }

class UClass;

class UObject
{
	friend class FObjectFactory;

public:
	UObject();
	virtual ~UObject() = default;

	virtual UClass* GetClass() const = 0; //GENERATE_BODY로 생성
};

