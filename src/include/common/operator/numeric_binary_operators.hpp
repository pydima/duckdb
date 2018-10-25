//===----------------------------------------------------------------------===//
//
//                         DuckDB
//
// common/operators/numeric_binary_operators.hpp
//
// Author: Mark Raasveldt
//
//===----------------------------------------------------------------------===//

#pragma once

namespace operators {

struct Add {
	template <class T> static inline T Operation(T left, T right) {
		return left + right;
	}
};

struct Subtract {
	template <class T> static inline T Operation(T left, T right) {
		return left - right;
	}
};

struct Multiply {
	template <class T> static inline T Operation(T left, T right) {
		return left * right;
	}
};

struct Divide {
	template <class T> static inline T Operation(T left, T right) {
		assert(right != 0); // this should be checked before!
		return left / right;
	}
};

struct Modulo {
	template <class T> static inline T Operation(T left, T right) {
		return left % right;
	}
};

} // namespace operators
