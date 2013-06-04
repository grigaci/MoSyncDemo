#ifndef IX_SEGMENTED_DATA_H
#define IX_SEGMENTED_DATA_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* Increases the size of a data object.
* \note There is no way to decrease the size of a data object.
* However, you can still destroy it.
* \returns #RES_OK if succeded and #RES_OUT_OF_MEMORY if failed.
* \see maDestroyObject()
* \see maCreateData()
* \see maGetDataSize()
*/
IOCTLDEF int maAddDataSize(MAHandle data, int size) {
	return (int) maIOCtl(90, data, size, 0);
}

#ifdef __cplusplus
}
#endif

#endif	//IX_SEGMENTED_DATA_H
