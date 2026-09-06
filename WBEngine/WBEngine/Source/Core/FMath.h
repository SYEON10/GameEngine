#pragma once

#include <Core/CoreTypes.h>

struct FVector2D {
	FLOAT x;
	FLOAT y;

	bool operator==(const FVector2D&) const = default;
};

struct FVector {
	FLOAT x;
	FLOAT y;
	FLOAT z;
};

struct FMatrix {
	FLOAT x;
	FLOAT y;
	FLOAT z;
	FLOAT a;
};