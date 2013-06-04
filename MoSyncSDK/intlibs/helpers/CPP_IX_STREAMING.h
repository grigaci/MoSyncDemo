#ifndef IX_STREAMING_DEFS_H
#define IX_STREAMING_DEFS_H

/** \brief A hash of the abstract representation of the API described in this file.
 * Identifiers, declarations and definitions are included in the calculation of the hash,
 * but documentation is not.
 */
#define MAIDL_HASH ((int)0x28c5d5c8)

#ifndef DONT_WANT_IX_STREAMING_TYPEDEFS
#endif
/**
* Has MAEvent::data point to a MAStreamEventData.
*/
#define EVENT_TYPE_STREAM 15
/// A connection to the streaming server has been established.
#define STREAMEVENT_OPEN_COMPLETE 1

/// After this event, you can retrieve information about the stream.
#define STREAMEVENT_PREPARE_COMPLETE 2

/// The stream reached its end.
#define STREAMEVENT_PLAY_COMPLETE 3

/// Also known as buffering.
#define STREAMEVENT_LOADING_STARTED 4

/// After this event, the stream is actually playing.
#define STREAMEVENT_LOADING_COMPLETE 5

#define STREAMEVENT_UNKNOWN_EVENT 6
/**
* \brief Event data associated with an audio stream.
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MAStreamEventData {
	/// One of the \link #STREAMEVENT_OPEN_COMPLETE STREAMEVENT \endlink constants.
	int event;

	/// The stream associated with the event.
	MAHandle stream;

	/**
	* Positive values denote progress. Negative values denote errors. Zero is not used.
	* \todo Define all possible values. They're currently platform-specific.
	*/
	int result;
} MAStreamEventData;
#ifdef _MSC_VER
#pragma pack(pop)
#endif
typedef struct MAStreamEventDataNative {
	/// One of the \link #STREAMEVENT_OPEN_COMPLETE STREAMEVENT \endlink constants.
	int event;

	/// The stream associated with the event.
	MAHandle stream;

	/**
	* Positive values denote progress. Negative values denote errors. Zero is not used.
	* \todo Define all possible values. They're currently platform-specific.
	*/
	int result;
} MAStreamEventDataNative;

#define maExtensionFunctionInvoke_IX_STREAMING_caselist \

#define maExtensionFunctionInvoke_IX_STREAMING_syscall_caselist \

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
#define maIOCtl_IX_STREAMING_caselist \
maIOCtl_maSoundPlayConn_case(maSoundPlayConn) \
maIOCtl_maStreamVideoStart_case(maStreamVideoStart) \
maIOCtl_maStreamVideoSize_case(maStreamVideoSize) \
maIOCtl_maStreamVideoSetFrame_case(maStreamVideoSetFrame) \
maIOCtl_maStreamLength_case(maStreamLength) \
maIOCtl_maStreamPos_case(maStreamPos) \
maIOCtl_maStreamSetPos_case(maStreamSetPos) \
maIOCtl_maStreamPause_case(maStreamPause) \
maIOCtl_maStreamResume_case(maStreamResume) \
maIOCtl_maStreamClose_case(maStreamClose) \

#define maIOCtl_IX_STREAMING_syscall_caselist \
maIOCtl_syscall_case(maSoundPlayConn) \
maIOCtl_syscall_case(maStreamVideoStart) \
maIOCtl_syscall_case(maStreamVideoSize) \
maIOCtl_syscall_case(maStreamVideoSetFrame) \
maIOCtl_syscall_case(maStreamLength) \
maIOCtl_syscall_case(maStreamPos) \
maIOCtl_syscall_case(maStreamSetPos) \
maIOCtl_syscall_case(maStreamPause) \
maIOCtl_syscall_case(maStreamResume) \
maIOCtl_syscall_case(maStreamClose) \

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
#define maIOCtl_maSoundPlayConn 71
#define maIOCtl_maSoundPlayConn_case(func) \
case 71: \
{ \
MAHandle _conn = (MAHandle)a; \
const char* _mimeType = GVS(b); \
return func(_conn, _mimeType); \
} \

#define maIOCtl_maStreamVideoStart 72
#define maIOCtl_maStreamVideoStart_case(func) \
case 72: \
{ \
const char* _url = GVS(a); \
return func(_url); \
} \

#define maIOCtl_maStreamVideoSize 73
#define maIOCtl_maStreamVideoSize_case(func) \
case 73: \
{ \
MAHandle _stream = (MAHandle)a; \
return func(_stream); \
} \

#define maIOCtl_maStreamVideoSetFrame 74
#define maIOCtl_maStreamVideoSetFrame_case(func) \
case 74: \
{ \
MAHandle _stream = (MAHandle)a; \
const MARect* _rect = GVMR(b, MARect); \
return func(_stream, _rect); \
} \

#define maIOCtl_maStreamLength 75
#define maIOCtl_maStreamLength_case(func) \
case 75: \
{ \
MAHandle _stream = (MAHandle)a; \
return func(_stream); \
} \

#define maIOCtl_maStreamPos 76
#define maIOCtl_maStreamPos_case(func) \
case 76: \
{ \
MAHandle _stream = (MAHandle)a; \
return func(_stream); \
} \

#define maIOCtl_maStreamSetPos 77
#define maIOCtl_maStreamSetPos_case(func) \
case 77: \
{ \
MAHandle _stream = (MAHandle)a; \
int _pos = b; \
return func(_stream, _pos); \
} \

#define maIOCtl_maStreamPause 78
#define maIOCtl_maStreamPause_case(func) \
case 78: \
{ \
MAHandle _stream = (MAHandle)a; \
return func(_stream); \
} \

#define maIOCtl_maStreamResume 79
#define maIOCtl_maStreamResume_case(func) \
case 79: \
{ \
MAHandle _stream = (MAHandle)a; \
return func(_stream); \
} \

#define maIOCtl_maStreamClose 80
#define maIOCtl_maStreamClose_case(func) \
case 80: \
{ \
MAHandle _stream = (MAHandle)a; \
return func(_stream); \
} \


#endif	//IX_STREAMING_DEFS_H
