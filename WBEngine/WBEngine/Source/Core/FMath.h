#pragma once

#include <Core/CoreTypes.h>

struct FVector2 {
	FVector2() = default;
	explicit FVector2(FLOAT x, FLOAT y)
		: x(x), y(y) {
	}

	static const FVector2& GetEmpty() {
		static const FVector2& STATIC_EMPTY_VECTOR = FVector2(0.f, 0.f);
		return STATIC_EMPTY_VECTOR;
	}

	FLOAT x;
	FLOAT y;

	bool operator==(const FVector2&) const = default;
};

struct FVector3 {
	FVector3() = default;
	explicit FVector3(FLOAT x, FLOAT y, FLOAT z)
		: x(x), y(y), z(z) {}

	static const FVector3& GetEmpty() {
		static const FVector3& STATIC_EMPTY_VECTOR = FVector3(0.f, 0.f, 0.f);
		return STATIC_EMPTY_VECTOR;
	}

	FLOAT x;
	FLOAT y;
	FLOAT z;
};

struct FVector4 {
	FVector4() = default;
	explicit FVector4(FLOAT x, FLOAT y, FLOAT z, FLOAT a)
		: x(x), y(y), z(z), a(a) {
	}

	static const FVector4& GetEmpty() {
		static const FVector4& STATIC_EMPTY_VECTOR = FVector4(0.f, 0.f, 0.f, 0.f);
		return STATIC_EMPTY_VECTOR;
	}

	FLOAT x;
	FLOAT y;
	FLOAT z;
	FLOAT a;
};

struct FTransform {
	FVector3 pos;
	FVector4 rot;
	FVector3 scale;
};