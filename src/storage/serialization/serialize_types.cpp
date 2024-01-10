//===----------------------------------------------------------------------===//
// This file is automatically generated by scripts/generate_serialization.py
// Do not edit this file manually, your changes will be overwritten
//===----------------------------------------------------------------------===//

#include "duckdb/common/serializer/serializer.hpp"
#include "duckdb/common/serializer/deserializer.hpp"
#include "duckdb/common/extra_type_info.hpp"

namespace duckdb {

void ExtraTypeInfo::Serialize(Serializer &serializer) const {
	serializer.WriteProperty<ExtraTypeInfoType>(100, "type", type);
	serializer.WritePropertyWithDefault<string>(101, "alias", alias);
}

shared_ptr<ExtraTypeInfo> ExtraTypeInfo::Deserialize(Deserializer &deserializer) {
	auto type = deserializer.ReadProperty<ExtraTypeInfoType>(100, "type");
	auto alias = deserializer.ReadPropertyWithDefault<string>(101, "alias");
	shared_ptr<ExtraTypeInfo> result;
	switch (type) {
	case ExtraTypeInfoType::AGGREGATE_STATE_TYPE_INFO:
		result = AggregateStateTypeInfo::Deserialize(deserializer);
		break;
	case ExtraTypeInfoType::ANY_TYPE_INFO:
		result = AnyTypeInfo::Deserialize(deserializer);
		break;
	case ExtraTypeInfoType::ARRAY_TYPE_INFO:
		result = ArrayTypeInfo::Deserialize(deserializer);
		break;
	case ExtraTypeInfoType::DECIMAL_TYPE_INFO:
		result = DecimalTypeInfo::Deserialize(deserializer);
		break;
	case ExtraTypeInfoType::ENUM_TYPE_INFO:
		result = EnumTypeInfo::Deserialize(deserializer);
		break;
	case ExtraTypeInfoType::GENERIC_TYPE_INFO:
		result = make_shared<ExtraTypeInfo>(type);
		break;
	case ExtraTypeInfoType::INTEGER_LITERAL_TYPE_INFO:
		result = IntegerLiteralTypeInfo::Deserialize(deserializer);
		break;
	case ExtraTypeInfoType::INVALID_TYPE_INFO:
		return nullptr;
	case ExtraTypeInfoType::LIST_TYPE_INFO:
		result = ListTypeInfo::Deserialize(deserializer);
		break;
	case ExtraTypeInfoType::STRING_TYPE_INFO:
		result = StringTypeInfo::Deserialize(deserializer);
		break;
	case ExtraTypeInfoType::STRUCT_TYPE_INFO:
		result = StructTypeInfo::Deserialize(deserializer);
		break;
	case ExtraTypeInfoType::USER_TYPE_INFO:
		result = UserTypeInfo::Deserialize(deserializer);
		break;
	default:
		throw SerializationException("Unsupported type for deserialization of ExtraTypeInfo!");
	}
	result->alias = std::move(alias);
	return result;
}

void AggregateStateTypeInfo::Serialize(Serializer &serializer) const {
	ExtraTypeInfo::Serialize(serializer);
	serializer.WritePropertyWithDefault<string>(200, "function_name", state_type.function_name);
	serializer.WriteProperty<LogicalType>(201, "return_type", state_type.return_type);
	serializer.WritePropertyWithDefault<vector<LogicalType>>(202, "bound_argument_types", state_type.bound_argument_types);
}

shared_ptr<ExtraTypeInfo> AggregateStateTypeInfo::Deserialize(Deserializer &deserializer) {
	auto result = duckdb::shared_ptr<AggregateStateTypeInfo>(new AggregateStateTypeInfo());
	deserializer.ReadPropertyWithDefault<string>(200, "function_name", result->state_type.function_name);
	deserializer.ReadProperty<LogicalType>(201, "return_type", result->state_type.return_type);
	deserializer.ReadPropertyWithDefault<vector<LogicalType>>(202, "bound_argument_types", result->state_type.bound_argument_types);
	return std::move(result);
}

void AnyTypeInfo::Serialize(Serializer &serializer) const {
	ExtraTypeInfo::Serialize(serializer);
	serializer.WriteProperty<LogicalType>(200, "target_type", target_type);
	serializer.WritePropertyWithDefault<idx_t>(201, "cast_score", cast_score);
}

shared_ptr<ExtraTypeInfo> AnyTypeInfo::Deserialize(Deserializer &deserializer) {
	auto result = duckdb::shared_ptr<AnyTypeInfo>(new AnyTypeInfo());
	deserializer.ReadProperty<LogicalType>(200, "target_type", result->target_type);
	deserializer.ReadPropertyWithDefault<idx_t>(201, "cast_score", result->cast_score);
	return std::move(result);
}

void ArrayTypeInfo::Serialize(Serializer &serializer) const {
	ExtraTypeInfo::Serialize(serializer);
	serializer.WriteProperty<LogicalType>(200, "child_type", child_type);
	serializer.WritePropertyWithDefault<uint32_t>(201, "size", size);
}

shared_ptr<ExtraTypeInfo> ArrayTypeInfo::Deserialize(Deserializer &deserializer) {
	auto child_type = deserializer.ReadProperty<LogicalType>(200, "child_type");
	auto size = deserializer.ReadPropertyWithDefault<uint32_t>(201, "size");
	auto result = duckdb::shared_ptr<ArrayTypeInfo>(new ArrayTypeInfo(std::move(child_type), size));
	return std::move(result);
}

void DecimalTypeInfo::Serialize(Serializer &serializer) const {
	ExtraTypeInfo::Serialize(serializer);
	serializer.WritePropertyWithDefault<uint8_t>(200, "width", width);
	serializer.WritePropertyWithDefault<uint8_t>(201, "scale", scale);
}

shared_ptr<ExtraTypeInfo> DecimalTypeInfo::Deserialize(Deserializer &deserializer) {
	auto result = duckdb::shared_ptr<DecimalTypeInfo>(new DecimalTypeInfo());
	deserializer.ReadPropertyWithDefault<uint8_t>(200, "width", result->width);
	deserializer.ReadPropertyWithDefault<uint8_t>(201, "scale", result->scale);
	return std::move(result);
}

void IntegerLiteralTypeInfo::Serialize(Serializer &serializer) const {
	ExtraTypeInfo::Serialize(serializer);
	serializer.WriteProperty<Value>(200, "constant_value", constant_value);
}

shared_ptr<ExtraTypeInfo> IntegerLiteralTypeInfo::Deserialize(Deserializer &deserializer) {
	auto result = duckdb::shared_ptr<IntegerLiteralTypeInfo>(new IntegerLiteralTypeInfo());
	deserializer.ReadProperty<Value>(200, "constant_value", result->constant_value);
	return std::move(result);
}

void ListTypeInfo::Serialize(Serializer &serializer) const {
	ExtraTypeInfo::Serialize(serializer);
	serializer.WriteProperty<LogicalType>(200, "child_type", child_type);
}

shared_ptr<ExtraTypeInfo> ListTypeInfo::Deserialize(Deserializer &deserializer) {
	auto result = duckdb::shared_ptr<ListTypeInfo>(new ListTypeInfo());
	deserializer.ReadProperty<LogicalType>(200, "child_type", result->child_type);
	return std::move(result);
}

void StringTypeInfo::Serialize(Serializer &serializer) const {
	ExtraTypeInfo::Serialize(serializer);
	serializer.WritePropertyWithDefault<string>(200, "collation", collation);
}

shared_ptr<ExtraTypeInfo> StringTypeInfo::Deserialize(Deserializer &deserializer) {
	auto result = duckdb::shared_ptr<StringTypeInfo>(new StringTypeInfo());
	deserializer.ReadPropertyWithDefault<string>(200, "collation", result->collation);
	return std::move(result);
}

void StructTypeInfo::Serialize(Serializer &serializer) const {
	ExtraTypeInfo::Serialize(serializer);
	serializer.WritePropertyWithDefault<child_list_t<LogicalType>>(200, "child_types", child_types);
}

shared_ptr<ExtraTypeInfo> StructTypeInfo::Deserialize(Deserializer &deserializer) {
	auto result = duckdb::shared_ptr<StructTypeInfo>(new StructTypeInfo());
	deserializer.ReadPropertyWithDefault<child_list_t<LogicalType>>(200, "child_types", result->child_types);
	return std::move(result);
}

void UserTypeInfo::Serialize(Serializer &serializer) const {
	ExtraTypeInfo::Serialize(serializer);
	serializer.WritePropertyWithDefault<string>(200, "user_type_name", user_type_name);
	serializer.WritePropertyWithDefault<string>(201, "catalog", catalog, string());
	serializer.WritePropertyWithDefault<string>(202, "schema", schema, string());
}

shared_ptr<ExtraTypeInfo> UserTypeInfo::Deserialize(Deserializer &deserializer) {
	auto result = duckdb::shared_ptr<UserTypeInfo>(new UserTypeInfo());
	deserializer.ReadPropertyWithDefault<string>(200, "user_type_name", result->user_type_name);
	deserializer.ReadPropertyWithDefault<string>(201, "catalog", result->catalog, string());
	deserializer.ReadPropertyWithDefault<string>(202, "schema", result->schema, string());
	return std::move(result);
}

} // namespace duckdb
