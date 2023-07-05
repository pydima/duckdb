#include "handle_functions.hpp"
#include "odbc_fetch.hpp"
#include "odbc_utils.hpp"
#include "parameter_descriptor.hpp"

#include <codecvt>

SQLRETURN duckdb::SetDiagnosticRecord(OdbcHandle *handle, SQLRETURN ret, std::string component,
                                      duckdb::DiagRecord diag_record, std::string data_source) {
	handle->odbc_diagnostic->FormatDiagnosticMessage(diag_record, data_source, component);
	handle->odbc_diagnostic->AddDiagRecord(diag_record);
	return ret;
}

SQLRETURN duckdb::ConvertHandle(SQLHANDLE &handle, OdbcHandle *hdl) {
	if (!handle) {
		return SQL_INVALID_HANDLE;
	}

	hdl = static_cast<OdbcHandle *>(handle);
	if (!hdl->odbc_diagnostic) {
		return SQL_ERROR;
	}

	return SQL_SUCCESS;
}

SQLRETURN duckdb::ConvertEnvironment(SQLHANDLE &environment_handle, OdbcHandleEnv *env) {
	if (!environment_handle) {
		return SQL_ERROR;
	}
	env = static_cast<OdbcHandleEnv *>(environment_handle);
	if (env->type != OdbcHandleType::ENV) {
		return SQL_ERROR;
	}
	if (!env->db) {
		return SQL_ERROR;
	}

	return SQL_SUCCESS;
}

SQLRETURN duckdb::ConvertConnection(SQLHANDLE &connection_handle, OdbcHandleDbc *dbc) {
	if (!connection_handle) {
		return SQL_ERROR;
	}
	dbc = static_cast<OdbcHandleDbc *>(connection_handle);
	if (dbc->type != OdbcHandleType::DBC) {
		return SQL_ERROR;
	}
	if (!dbc->conn) {
		return SQL_ERROR;
	}

	// ODBC requires to clean up the diagnostic for every ODBC function call
	dbc->odbc_diagnostic->Clean();

	return SQL_SUCCESS;
}

SQLRETURN duckdb::ConvertHSTMT(SQLHANDLE &statement_handle, OdbcHandleStmt *&hstmt) {
	if (!statement_handle) {
		return SQL_ERROR;
	}
	hstmt = static_cast<OdbcHandleStmt *>(statement_handle);
	if (hstmt->type != OdbcHandleType::STMT) {
		return SQL_ERROR;
	}
	if (!hstmt->dbc || !hstmt->dbc->conn) {
		return SQL_ERROR;
	}

	// ODBC requires to clean up the diagnostic for every ODBC function call
	hstmt->odbc_diagnostic->Clean();

	return SQL_SUCCESS;
}

SQLRETURN duckdb::ConvertHSTMTPrepared(SQLHANDLE &statement_handle, OdbcHandleStmt *&hstmt) {
	if (ConvertHSTMT(statement_handle, hstmt) != SQL_SUCCESS) {
		return SQL_ERROR;
	}
	if (!hstmt->stmt) {
		return SQL_ERROR;
	}
	if (hstmt->stmt->HasError()) {
		return SQL_ERROR;
	}
	return SQL_SUCCESS;
}

SQLRETURN duckdb::ConvertHSTMTResult(SQLHANDLE &statement_handle, OdbcHandleStmt *&hstmt) {
	if (ConvertHSTMT(statement_handle, hstmt) != SQL_SUCCESS) {
		return SQL_ERROR;
	}
	if (!hstmt->res) {
		return SQL_ERROR;
	}
	if (hstmt->res->HasError()) {
		return SQL_ERROR;
	}
	return SQL_SUCCESS;
}
