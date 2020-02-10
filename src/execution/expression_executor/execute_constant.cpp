#include "duckdb/common/vector_operations/vector_operations.hpp"
#include "duckdb/execution/expression_executor.hpp"
#include "duckdb/planner/expression/bound_constant_expression.hpp"

using namespace duckdb;
using namespace std;

unique_ptr<ExpressionState> ExpressionExecutor::InitializeState(BoundConstantExpression &expr,
                                                                ExpressionExecutorState &root) {
	return nullptr;
}

void ExpressionExecutor::Execute(BoundConstantExpression &expr, ExpressionState *state, Vector &result) {
	result.Reference(expr.value);
	if (chunk) {
		result.SetCount(chunk->size());
		result.SetSelVector(chunk->sel_vector);
	}
}
