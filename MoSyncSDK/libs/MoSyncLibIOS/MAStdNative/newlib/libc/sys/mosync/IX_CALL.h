#ifndef IX_CALL_H
#define IX_CALL_H

#ifdef __cplusplus
extern "C" {
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
/**
* Starts dialing a voice call.
* Returns 0 on successful beginning of dial, or \< 0 on error,
* like a call already in progress.
* Causes CALL events.
* \param phoneNumber Max length: 100.
*/
IOCTLDEF int maCallDial(const char* phoneNumber) {
	return (int) maIOCtl(68, (int)phoneNumber, 0, 0);
}

/**
* Starts answering a voice call. The call state must be #CALLSTATE_RINGING.
* Returns 0 on successful initialization of the answering process,
* or \< 0 on error, like if the line is not ringing.
* Causes CALL events.
* \note The line state may change while this function is being called. Therefore,
* it may fail even if you haven't received a new CALL event.
*/
IOCTLDEF int maCallAnswer(void) {
	return (int) maIOCtl(69, 0, 0, 0);
}

/**
* Starts hanging up a voice call, if a call is in progress.
* Returns 0 if no call is in progress, or on successful beginning of hangup.
* Returns \< 0 on error.
* Can cause CALL events.
*/
IOCTLDEF int maCallHangup(void) {
	return (int) maIOCtl(70, 0, 0, 0);
}

#ifdef __cplusplus
}
#endif

#endif	//IX_CALL_H
