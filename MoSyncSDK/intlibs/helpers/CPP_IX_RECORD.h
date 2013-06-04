#ifndef IX_RECORD_DEFS_H
#define IX_RECORD_DEFS_H

/** \brief A hash of the abstract representation of the API described in this file.
 * Identifiers, declarations and definitions are included in the calculation of the hash,
 * but documentation is not.
 */
#define MAIDL_HASH ((int)0x28c5d5c8)

#ifndef DONT_WANT_IX_RECORD_TYPEDEFS
#endif
#define maExtensionFunctionInvoke_IX_RECORD_caselist \

#define maExtensionFunctionInvoke_IX_RECORD_syscall_caselist \

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
#define maIOCtl_IX_RECORD_caselist \
maIOCtl_maRecordSetup_case(maRecordSetup) \
maIOCtl_maRecordStart_case(maRecordStart) \
maIOCtl_maRecordPause_case(maRecordPause) \

#define maIOCtl_IX_RECORD_syscall_caselist \
maIOCtl_syscall_case(maRecordSetup) \
maIOCtl_syscall_case(maRecordStart) \
maIOCtl_syscall_case(maRecordPause) \

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
#define maIOCtl_maRecordSetup 64
#define maIOCtl_maRecordSetup_case(func) \
case 64: \
{ \
return func(); \
} \

#define maIOCtl_maRecordStart 65
#define maIOCtl_maRecordStart_case(func) \
case 65: \
{ \
MAHandle _rec = (MAHandle)a; \
return func(_rec); \
} \

#define maIOCtl_maRecordPause 66
#define maIOCtl_maRecordPause_case(func) \
case 66: \
{ \
MAHandle _rec = (MAHandle)a; \
return func(_rec); \
} \


#endif	//IX_RECORD_DEFS_H
