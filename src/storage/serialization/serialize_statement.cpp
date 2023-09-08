//===----------------------------------------------------------------------===//
// This file is automatically generated by scripts/generate_serialization.py
// Do not edit this file manually, your changes will be overwritten
//===----------------------------------------------------------------------===//

#include "duckdb/common/serializer/serializer.hpp"
#include "duckdb/common/serializer/deserializer.hpp"
#include "duckdb/parser/statement/select_statement.hpp"

namespace duckdb {

void SelectStatement::FormatSerialize(Serializer &serializer) const {
	serializer.WriteProperty(100, "node", node);
}

unique_ptr<SelectStatement> SelectStatement::FormatDeserialize(Deserializer &deserializer) {
	auto result = duckdb::unique_ptr<SelectStatement>(new SelectStatement());
	deserializer.ReadProperty(100, "node", result->node);
	return result;
}

} // namespace duckdb
