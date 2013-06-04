#ifndef IX_CALL_DEFS_H
#define IX_CALL_DEFS_H

/** \brief A hash of the abstract representation of the API described in this file.
 * Identifiers, declarations and definitions are included in the calculation of the hash,
 * but documentation is not.
 */
#define MAIDL_HASH ((int)0x28c5d5c8)

#ifndef DONT_WANT_IX_CALL_TYPEDEFS
#endif
/// Has MAEvent::state be one of the \link #CALLSTATE_UNKNOWN CALLSTATE \endlink constants.
#define EVENT_TYPE_CALL 11
#define CALLSTATE_UNKNOWN 0
#define CALLSTATE_IDLE 1
#define CALLSTATE_DIALLING 2
#define CALLSTATE_RINGING 3
#define CALLSTATE_ANSWERING 4
#define CALLSTATE_CONNECTING 5
#define CALLSTATE_CONNECTED 6
#define CALLSTATE_RECONNECTPENDING 7
#define CALLSTATE_DISCONNECTING 8
#define CALLSTATE_HOLD 9
#define CALLSTATE_TRANSFERRING 10
#define CALLSTATE_TRANSFERALERTING 11
#define maExtensionFunctionInvoke_IX_CALL_caselist \

#define maExtensionFunctionInvoke_IX_CALL_syscall_caselist \

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
#define maIOCtl_IX_CALL_caselist \
maIOCtl_maCallDial_case(maCallDial) \
maIOCtl_maCallAnswer_case(maCallAnswer) \
maIOCtl_maCallHangup_case(maCallHangup) \

#define maIOCtl_IX_CALL_syscall_caselist \
maIOCtl_syscall_case(maCallDial) \
maIOCtl_syscall_case(maCallAnswer) \
maIOCtl_syscall_case(maCallHangup) \

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
#define maIOCtl_maCallDial 68
#define maIOCtl_maCallDial_case(func) \
case 68: \
{ \
const char* _phoneNumber = GVS(a); \
return func(_phoneNumber); \
} \

#define maIOCtl_maCallAnswer 69
#define maIOCtl_maCallAnswer_case(func) \
case 69: \
{ \
return func(); \
} \

#define maIOCtl_maCallHangup 70
#define maIOCtl_maCallHangup_case(func) \
case 70: \
{ \
return func(); \
} \


#endif	//IX_CALL_DEFS_H
