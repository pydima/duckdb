//===----------------------------------------------------------------------===//
//
//                         DuckDB
//
// common/operators/numeric_bitwise_operators.hpp
//
// Author: Mark Raasveldt
//
//===----------------------------------------------------------------------===//

#pragma once

namespace operators {

struct BitwiseXOR {
	template <class T> static inline T Operation(T left, T right) {
		return left ^ right;
	}
};

struct BitwiseAND {
	template <class T> static inline T Operation(T left, T right) {
		return left & right;
	}
};

struct BitwiseOR {
	template <class T> static inline T Operation(T left, T right) {
		return left | right;
	}
};

struct BitwiseShiftLeft {
	template <class T> static inline T Operation(T left, T right) {
		return left << right;
	}
};

struct BitwiseShiftRight {
	template <class T> static inline T Operation(T left, T right) {
		return left >> right;
	}
};

struct BitwiseNOT {
	template <class T> static inline T Operation(T input) {
		return ~input;
	}
};

} // namespace operators
