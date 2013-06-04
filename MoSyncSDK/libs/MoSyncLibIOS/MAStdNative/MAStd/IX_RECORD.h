#ifndef IX_RECORD_H
#define IX_RECORD_H

#ifdef __cplusplus
extern "C" {
#endif

IOCTLDEF int maRecordSetup(void) {
	return (int) maIOCtl(64, 0, 0, 0);
}

IOCTLDEF int maRecordStart(MAHandle rec) {
	return (int) maIOCtl(65, rec, 0, 0);
}

IOCTLDEF int maRecordPause(MAHandle rec) {
	return (int) maIOCtl(66, rec, 0, 0);
}

#ifdef __cplusplus
}
#endif

#endif	//IX_RECORD_H
