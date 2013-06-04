#ifndef IX_CELLID_DEFS_H
#define IX_CELLID_DEFS_H

/** \brief A hash of the abstract representation of the API described in this file.
 * Identifiers, declarations and definitions are included in the calculation of the hash,
 * but documentation is not.
 */
#define MAIDL_HASH ((int)0x28c5d5c8)

#ifndef DONT_WANT_IX_CELLID_TYPEDEFS
#endif
/**
* \brief Information about the current cell, including country,
* network and area code and the cell ID.
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MACellInfo {
	/**
	* Mobile Country Code. Identifies the country whose cellular network the phone
	* is connected to.
	*/
	char mcc[4];

	/**
	* Mobile Network Code. Identifies the network operator
	* in the country specified by the MCC.
	*/
	char mnc[8];

	/**
	* Location Area Code. Identifies a geographic area within the cellular network
	* specified by the MCC and MNC.
	*/
	int lac;

	/**
	* Cell ID. Identifies the base station the phone is connected to,
	* within the cellular network specified by the MCC and MNC.
	* \note While a phone may be in range of several base stations at any time,
	* only one of those base stations controls the connection between the phone and
	* the network. That is the base station reported here.
	*/
	int cellId;
} MACellInfo;
#ifdef _MSC_VER
#pragma pack(pop)
#endif
typedef struct MACellInfoNative {
	/**
	* Mobile Country Code. Identifies the country whose cellular network the phone
	* is connected to.
	*/
	char mcc[4];

	/**
	* Mobile Network Code. Identifies the network operator
	* in the country specified by the MCC.
	*/
	char mnc[8];

	/**
	* Location Area Code. Identifies a geographic area within the cellular network
	* specified by the MCC and MNC.
	*/
	int lac;

	/**
	* Cell ID. Identifies the base station the phone is connected to,
	* within the cellular network specified by the MCC and MNC.
	* \note While a phone may be in range of several base stations at any time,
	* only one of those base stations controls the connection between the phone and
	* the network. That is the base station reported here.
	*/
	int cellId;
} MACellInfoNative;

#define maExtensionFunctionInvoke_IX_CELLID_caselist \

#define maExtensionFunctionInvoke_IX_CELLID_syscall_caselist \

#undef ARG_NO_4
#define ARG_NO_4 SYSCALL_THIS->GetValidatedStackValue(0 VSV_ARGPTR_USE)
#undef ARG_NO_5
#define ARG_NO_5 SYSCALL_THIS->GetValidatedStackValue(4 VSV_ARGPTR_USE)
#undef ARG_NO_6
#define ARG_NO_6 SYSCALL_THIS->GetValidatedStackValue(8 VSV_ARGPTR_USE)
#undef ARG_NO_7
#define ARG_NO_7 SYSCALL_THIS->GetValidatedStackValue(12 VSV_ARGPTR_USE)
#undef ARG_NO_8
#define ARG_NO_8 SYSCALL_THIS->GetValidatedStackValue(16 VSV_ARGPTR_USE)
#undef ARG_NO_9
#define ARG_NO_9 SYSCALL_THIS->GetValidatedStackValue(20 VSV_ARGPTR_USE)
#undef ARG_NO_10
#define ARG_NO_10 SYSCALL_THIS->GetValidatedStackValue(24 VSV_ARGPTR_USE)
#define maIOCtl_IX_CELLID_caselist \
maIOCtl_maGetCellInfo_case(maGetCellInfo) \

#define maIOCtl_IX_CELLID_syscall_caselist \
maIOCtl_syscall_case(maGetCellInfo) \

#undef ARG_NO_4
#define ARG_NO_4 SYSCALL_THIS->GetValidatedStackValue(0 VSV_ARGPTR_USE)
#undef ARG_NO_5
#define ARG_NO_5 SYSCALL_THIS->GetValidatedStackValue(4 VSV_ARGPTR_USE)
#undef ARG_NO_6
#define ARG_NO_6 SYSCALL_THIS->GetValidatedStackValue(8 VSV_ARGPTR_USE)
#undef ARG_NO_7
#define ARG_NO_7 SYSCALL_THIS->GetValidatedStackValue(12 VSV_ARGPTR_USE)
#undef ARG_NO_8
#define ARG_NO_8 SYSCALL_THIS->GetValidatedStackValue(16 VSV_ARGPTR_USE)
#undef ARG_NO_9
#define ARG_NO_9 SYSCALL_THIS->GetValidatedStackValue(20 VSV_ARGPTR_USE)
#undef ARG_NO_10
#define ARG_NO_10 SYSCALL_THIS->GetValidatedStackValue(24 VSV_ARGPTR_USE)
#define maIOCtl_maGetCellInfo 67
#define maIOCtl_maGetCellInfo_case(func) \
case 67: \
{ \
MACellInfo* _pInfo = GVMR(a, MACellInfo); \
return func(_pInfo); \
} \


#endif	//IX_CELLID_DEFS_H
