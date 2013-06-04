#ifndef IX_WLAN_DEFS_H
#define IX_WLAN_DEFS_H

/** \brief A hash of the abstract representation of the API described in this file.
 * Identifiers, declarations and definitions are included in the calculation of the hash,
 * but documentation is not.
 */
#define MAIDL_HASH ((int)0x28c5d5c8)

#ifndef DONT_WANT_IX_WLAN_TYPEDEFS
#endif
/// Uses MAEvent::state.
#define EVENT_TYPE_WLAN 7
/**@}*/
#define WLAN_ADDR_LEN 6
/**
* \brief A WLAN address.
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MAWlanAddr {
	byte a[WLAN_ADDR_LEN];
} MAWlanAddr;
#ifdef _MSC_VER
#pragma pack(pop)
#endif
typedef struct MAWlanAddrNative {
	byte a[WLAN_ADDR_LEN];
} MAWlanAddrNative;

/**
* \brief A WLAN access point.
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MAWlanAp {
	/// out
	MAWlanAddr address;

	/// in(ptr), out(content)
	MAAddress name;

	/// in
	int nameBufSize;

	/// out. dBm?
	int signalStrength;
} MAWlanAp;
#ifdef _MSC_VER
#pragma pack(pop)
#endif
typedef struct MAWlanApNative {
	/// out
	MAWlanAddr address;

	/// in(ptr), out(content)
	char* name;

	/// in
	int nameBufSize;

	/// out. dBm?
	int signalStrength;
} MAWlanApNative;

#define maExtensionFunctionInvoke_IX_WLAN_caselist \

#define maExtensionFunctionInvoke_IX_WLAN_syscall_caselist \

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
#define maIOCtl_IX_WLAN_caselist \
maIOCtl_maWlanStartDiscovery_case(maWlanStartDiscovery) \
maIOCtl_maWlanGetNewAp_case(maWlanGetNewAp) \

#define maIOCtl_IX_WLAN_syscall_caselist \
maIOCtl_syscall_case(maWlanStartDiscovery) \
maIOCtl_syscall_case(maWlanGetNewAp) \

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
#define maIOCtl_maWlanStartDiscovery 36
#define maIOCtl_maWlanStartDiscovery_case(func) \
case 36: \
{ \
return func(); \
} \

#define maIOCtl_maWlanGetNewAp 37
#define maIOCtl_maWlanGetNewAp_case(func) \
case 37: \
{ \
MAWlanAp* _dst = GVMR(a, MAWlanAp); \
return func(_dst); \
} \


#endif	//IX_WLAN_DEFS_H
