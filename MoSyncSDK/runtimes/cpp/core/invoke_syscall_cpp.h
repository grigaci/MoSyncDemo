case 1:
{
	LOGSC("\tmaCheckInterfaceVersion(");
	int hash = _SYSCALL_CONVERT_int(REG(REG_i0));
	int res = CALL_SYSCALL(maCheckInterfaceVersion)(hash);
	_SYSCALL_HANDLERES_int
	return;
}
case 2:
{
	LOGSC("\tmaExit(");
	int result = _SYSCALL_CONVERT_int(REG(REG_i0));
	CALL_SYSCALL(maExit)(result);
	_SYSCALL_HANDLERES_void
	return;
}
case 3:
{
	LOGSC("\tmaPanic(");
	int result = _SYSCALL_CONVERT_int(REG(REG_i0));
	LOGSC(", ");
	char* message = _SYSCALL_CONVERT_MAString(REG(REG_i1));
	CALL_SYSCALL(maPanic)(result, message);
	_SYSCALL_HANDLERES_void
	return;
}
case 4:
{
	LOGSC("\tmemset(");
	void* dst = _SYSCALL_CONVERT_MAAddress(REG(REG_i0));
	LOGSC(", ");
	int val = _SYSCALL_CONVERT_int(REG(REG_i1));
	LOGSC(", ");
	ulong size = _SYSCALL_CONVERT_ulong(REG(REG_i2));
	void* res = CALL_SYSCALL(memset)(dst, val, size);
	_SYSCALL_HANDLERES_MAAddress
	return;
}
case 5:
{
	LOGSC("\tmemcpy(");
	void* dst = _SYSCALL_CONVERT_MAAddress(REG(REG_i0));
	LOGSC(", ");
	void* src = _SYSCALL_CONVERT_MAAddress(REG(REG_i1));
	LOGSC(", ");
	ulong size = _SYSCALL_CONVERT_ulong(REG(REG_i2));
	void* res = CALL_SYSCALL(memcpy)(dst, src, size);
	_SYSCALL_HANDLERES_MAAddress
	return;
}
case 6:
{
	LOGSC("\tstrcmp(");
	char* str1 = _SYSCALL_CONVERT_MAString(REG(REG_i0));
	LOGSC(", ");
	char* str2 = _SYSCALL_CONVERT_MAString(REG(REG_i1));
	int res = CALL_SYSCALL(strcmp)(str1, str2);
	_SYSCALL_HANDLERES_int
	return;
}
case 7:
{
	LOGSC("\tstrcpy(");
	char* dst = _SYSCALL_CONVERT_NCString(REG(REG_i0));
	LOGSC(", ");
	char* src = _SYSCALL_CONVERT_NCString(REG(REG_i1));
	char* res = CALL_SYSCALL(strcpy)(dst, src);
	_SYSCALL_HANDLERES_MAString
	return;
}
case 8:
{
	LOGSC("\t__adddf3(");
	double a = _SYSCALL_CONVERT_double(REG(REG_i0));
	LOGSC(", ");
	double b = _SYSCALL_CONVERT_double(REG(REG_i2));
	double res = CALL_SYSCALL(__adddf3)(a, b);
	_SYSCALL_HANDLERES_double
	return;
}
case 9:
{
	LOGSC("\t__subdf3(");
	double a = _SYSCALL_CONVERT_double(REG(REG_i0));
	LOGSC(", ");
	double b = _SYSCALL_CONVERT_double(REG(REG_i2));
	double res = CALL_SYSCALL(__subdf3)(a, b);
	_SYSCALL_HANDLERES_double
	return;
}
case 10:
{
	LOGSC("\t__muldf3(");
	double a = _SYSCALL_CONVERT_double(REG(REG_i0));
	LOGSC(", ");
	double b = _SYSCALL_CONVERT_double(REG(REG_i2));
	double res = CALL_SYSCALL(__muldf3)(a, b);
	_SYSCALL_HANDLERES_double
	return;
}
case 11:
{
	LOGSC("\t__divdf3(");
	double a = _SYSCALL_CONVERT_double(REG(REG_i0));
	LOGSC(", ");
	double b = _SYSCALL_CONVERT_double(REG(REG_i2));
	double res = CALL_SYSCALL(__divdf3)(a, b);
	_SYSCALL_HANDLERES_double
	return;
}
case 12:
{
	LOGSC("\t__negdf2(");
	double a = _SYSCALL_CONVERT_double(REG(REG_i0));
	double res = CALL_SYSCALL(__negdf2)(a);
	_SYSCALL_HANDLERES_double
	return;
}
case 13:
{
	LOGSC("\t__fixdfsi(");
	double a = _SYSCALL_CONVERT_double(REG(REG_i0));
	int res = CALL_SYSCALL(__fixdfsi)(a);
	_SYSCALL_HANDLERES_int
	return;
}
case 14:
{
	LOGSC("\t__fixunsdfsi(");
	double a = _SYSCALL_CONVERT_double(REG(REG_i0));
	uint res = CALL_SYSCALL(__fixunsdfsi)(a);
	_SYSCALL_HANDLERES_uint
	return;
}
case 15:
{
	LOGSC("\t__floatsidf(");
	int a = _SYSCALL_CONVERT_int(REG(REG_i0));
	double res = CALL_SYSCALL(__floatsidf)(a);
	_SYSCALL_HANDLERES_double
	return;
}
case 16:
{
	LOGSC("\t__extendsfdf2(");
	float a = _SYSCALL_CONVERT_float(REG(REG_i0));
	double res = CALL_SYSCALL(__extendsfdf2)(a);
	_SYSCALL_HANDLERES_double
	return;
}
case 17:
{
	LOGSC("\tdcmp(");
	double a = _SYSCALL_CONVERT_double(REG(REG_i0));
	LOGSC(", ");
	double b = _SYSCALL_CONVERT_double(REG(REG_i2));
	int res = CALL_SYSCALL(dcmp)(a, b);
	_SYSCALL_HANDLERES_int
	return;
}
case 18:
{
	LOGSC("\t__addsf3(");
	float a = _SYSCALL_CONVERT_float(REG(REG_i0));
	LOGSC(", ");
	float b = _SYSCALL_CONVERT_float(REG(REG_i1));
	float res = CALL_SYSCALL(__addsf3)(a, b);
	_SYSCALL_HANDLERES_float
	return;
}
case 19:
{
	LOGSC("\t__subsf3(");
	float a = _SYSCALL_CONVERT_float(REG(REG_i0));
	LOGSC(", ");
	float b = _SYSCALL_CONVERT_float(REG(REG_i1));
	float res = CALL_SYSCALL(__subsf3)(a, b);
	_SYSCALL_HANDLERES_float
	return;
}
case 20:
{
	LOGSC("\t__mulsf3(");
	float a = _SYSCALL_CONVERT_float(REG(REG_i0));
	LOGSC(", ");
	float b = _SYSCALL_CONVERT_float(REG(REG_i1));
	float res = CALL_SYSCALL(__mulsf3)(a, b);
	_SYSCALL_HANDLERES_float
	return;
}
case 21:
{
	LOGSC("\t__divsf3(");
	float a = _SYSCALL_CONVERT_float(REG(REG_i0));
	LOGSC(", ");
	float b = _SYSCALL_CONVERT_float(REG(REG_i1));
	float res = CALL_SYSCALL(__divsf3)(a, b);
	_SYSCALL_HANDLERES_float
	return;
}
case 22:
{
	LOGSC("\t__negsf2(");
	float a = _SYSCALL_CONVERT_float(REG(REG_i0));
	float res = CALL_SYSCALL(__negsf2)(a);
	_SYSCALL_HANDLERES_float
	return;
}
case 23:
{
	LOGSC("\t__fixsfsi(");
	float a = _SYSCALL_CONVERT_float(REG(REG_i0));
	int res = CALL_SYSCALL(__fixsfsi)(a);
	_SYSCALL_HANDLERES_int
	return;
}
case 24:
{
	LOGSC("\t__fixunssfsi(");
	float a = _SYSCALL_CONVERT_float(REG(REG_i0));
	uint res = CALL_SYSCALL(__fixunssfsi)(a);
	_SYSCALL_HANDLERES_uint
	return;
}
case 25:
{
	LOGSC("\t__floatsisf(");
	int a = _SYSCALL_CONVERT_int(REG(REG_i0));
	float res = CALL_SYSCALL(__floatsisf)(a);
	_SYSCALL_HANDLERES_float
	return;
}
case 26:
{
	LOGSC("\t__truncdfsf2(");
	double a = _SYSCALL_CONVERT_double(REG(REG_i0));
	float res = CALL_SYSCALL(__truncdfsf2)(a);
	_SYSCALL_HANDLERES_float
	return;
}
case 27:
{
	LOGSC("\tfcmp(");
	float a = _SYSCALL_CONVERT_float(REG(REG_i0));
	LOGSC(", ");
	float b = _SYSCALL_CONVERT_float(REG(REG_i1));
	int res = CALL_SYSCALL(fcmp)(a, b);
	_SYSCALL_HANDLERES_int
	return;
}
case 28:
{
	LOGSC("\tsin(");
	double x = _SYSCALL_CONVERT_double(REG(REG_i0));
	double res = CALL_SYSCALL(sin)(x);
	_SYSCALL_HANDLERES_double
	return;
}
case 29:
{
	LOGSC("\tcos(");
	double x = _SYSCALL_CONVERT_double(REG(REG_i0));
	double res = CALL_SYSCALL(cos)(x);
	_SYSCALL_HANDLERES_double
	return;
}
case 30:
{
	LOGSC("\ttan(");
	double x = _SYSCALL_CONVERT_double(REG(REG_i0));
	double res = CALL_SYSCALL(tan)(x);
	_SYSCALL_HANDLERES_double
	return;
}
case 31:
{
	LOGSC("\tsqrt(");
	double x = _SYSCALL_CONVERT_double(REG(REG_i0));
	double res = CALL_SYSCALL(sqrt)(x);
	_SYSCALL_HANDLERES_double
	return;
}
case 32:
{
	LOGSC("\tmaSetColor(");
	int rgb = _SYSCALL_CONVERT_int(REG(REG_i0));
	int res = CALL_SYSCALL(maSetColor)(rgb);
	_SYSCALL_HANDLERES_int
	return;
}
case 33:
{
	LOGSC("\tmaSetClipRect(");
	int left = _SYSCALL_CONVERT_int(REG(REG_i0));
	LOGSC(", ");
	int top = _SYSCALL_CONVERT_int(REG(REG_i1));
	LOGSC(", ");
	int width = _SYSCALL_CONVERT_int(REG(REG_i2));
	LOGSC(", ");
	int height = _SYSCALL_CONVERT_int(REG(REG_i3));
	CALL_SYSCALL(maSetClipRect)(left, top, width, height);
	_SYSCALL_HANDLERES_void
	return;
}
case 34:
{
	LOGSC("\tmaGetClipRect(");
	MARect* out = _SYSCALL_CONVERT_MARect(REG(REG_i0));
	CALL_SYSCALL(maGetClipRect)(out);
	_SYSCALL_HANDLERES_void
	return;
}
case 35:
{
	LOGSC("\tmaPlot(");
	int posX = _SYSCALL_CONVERT_int(REG(REG_i0));
	LOGSC(", ");
	int posY = _SYSCALL_CONVERT_int(REG(REG_i1));
	CALL_SYSCALL(maPlot)(posX, posY);
	_SYSCALL_HANDLERES_void
	return;
}
case 36:
{
	LOGSC("\tmaLine(");
	int startX = _SYSCALL_CONVERT_int(REG(REG_i0));
	LOGSC(", ");
	int startY = _SYSCALL_CONVERT_int(REG(REG_i1));
	LOGSC(", ");
	int endX = _SYSCALL_CONVERT_int(REG(REG_i2));
	LOGSC(", ");
	int endY = _SYSCALL_CONVERT_int(REG(REG_i3));
	CALL_SYSCALL(maLine)(startX, startY, endX, endY);
	_SYSCALL_HANDLERES_void
	return;
}
case 37:
{
	LOGSC("\tmaFillRect(");
	int left = _SYSCALL_CONVERT_int(REG(REG_i0));
	LOGSC(", ");
	int top = _SYSCALL_CONVERT_int(REG(REG_i1));
	LOGSC(", ");
	int width = _SYSCALL_CONVERT_int(REG(REG_i2));
	LOGSC(", ");
	int height = _SYSCALL_CONVERT_int(REG(REG_i3));
	CALL_SYSCALL(maFillRect)(left, top, width, height);
	_SYSCALL_HANDLERES_void
	return;
}
case 38:
{
	LOGSC("\tmaFillTriangleStrip(");
	MAPoint2d* points = _SYSCALL_CONVERT_MAPoint2d(REG(REG_i0));
	LOGSC(", ");
	int count = _SYSCALL_CONVERT_int(REG(REG_i1));
	CALL_SYSCALL(maFillTriangleStrip)(points, count);
	_SYSCALL_HANDLERES_void
	return;
}
case 39:
{
	LOGSC("\tmaFillTriangleFan(");
	MAPoint2d* points = _SYSCALL_CONVERT_MAPoint2d(REG(REG_i0));
	LOGSC(", ");
	int count = _SYSCALL_CONVERT_int(REG(REG_i1));
	CALL_SYSCALL(maFillTriangleFan)(points, count);
	_SYSCALL_HANDLERES_void
	return;
}
case 40:
{
	LOGSC("\tmaGetTextSize(");
	char* str = _SYSCALL_CONVERT_MAString(REG(REG_i0));
	MAExtent res = CALL_SYSCALL(maGetTextSize)(str);
	_SYSCALL_HANDLERES_MAExtent
	return;
}
case 41:
{
	LOGSC("\tmaGetTextSizeW(");
	wchar* str = _SYSCALL_CONVERT_MAWString(REG(REG_i0));
	MAExtent res = CALL_SYSCALL(maGetTextSizeW)(str);
	_SYSCALL_HANDLERES_MAExtent
	return;
}
case 42:
{
	LOGSC("\tmaDrawText(");
	int left = _SYSCALL_CONVERT_int(REG(REG_i0));
	LOGSC(", ");
	int top = _SYSCALL_CONVERT_int(REG(REG_i1));
	LOGSC(", ");
	char* str = _SYSCALL_CONVERT_MAString(REG(REG_i2));
	CALL_SYSCALL(maDrawText)(left, top, str);
	_SYSCALL_HANDLERES_void
	return;
}
case 43:
{
	LOGSC("\tmaDrawTextW(");
	int left = _SYSCALL_CONVERT_int(REG(REG_i0));
	LOGSC(", ");
	int top = _SYSCALL_CONVERT_int(REG(REG_i1));
	LOGSC(", ");
	wchar* str = _SYSCALL_CONVERT_MAWString(REG(REG_i2));
	CALL_SYSCALL(maDrawTextW)(left, top, str);
	_SYSCALL_HANDLERES_void
	return;
}
case 44:
{
	LOGSC("\tmaUpdateScreen(");
	CALL_SYSCALL(maUpdateScreen)();
	_SYSCALL_HANDLERES_void
	return;
}
case 45:
{
	LOGSC("\tmaResetBacklight(");
	CALL_SYSCALL(maResetBacklight)();
	_SYSCALL_HANDLERES_void
	return;
}
case 46:
{
	LOGSC("\tmaGetScrSize(");
	MAExtent res = CALL_SYSCALL(maGetScrSize)();
	_SYSCALL_HANDLERES_MAExtent
	return;
}
case 47:
{
	LOGSC("\tmaDrawImage(");
	MAHandle image = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	LOGSC(", ");
	int left = _SYSCALL_CONVERT_int(REG(REG_i1));
	LOGSC(", ");
	int top = _SYSCALL_CONVERT_int(REG(REG_i2));
	CALL_SYSCALL(maDrawImage)(image, left, top);
	_SYSCALL_HANDLERES_void
	return;
}
case 48:
{
	LOGSC("\tmaDrawRGB(");
	MAPoint2d* dstPoint = _SYSCALL_CONVERT_MAPoint2d(REG(REG_i0));
	LOGSC(", ");
	void* src = _SYSCALL_CONVERT_MAAddress(REG(REG_i1));
	LOGSC(", ");
	MARect* srcRect = _SYSCALL_CONVERT_MARect(REG(REG_i2));
	LOGSC(", ");
	int scanlength = _SYSCALL_CONVERT_int(REG(REG_i3));
	CALL_SYSCALL(maDrawRGB)(dstPoint, src, srcRect, scanlength);
	_SYSCALL_HANDLERES_void
	return;
}
case 49:
{
	LOGSC("\tmaDrawImageRegion(");
	MAHandle image = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	LOGSC(", ");
	MARect* srcRect = _SYSCALL_CONVERT_MARect(REG(REG_i1));
	LOGSC(", ");
	MAPoint2d* dstPoint = _SYSCALL_CONVERT_MAPoint2d(REG(REG_i2));
	LOGSC(", ");
	int transformMode = _SYSCALL_CONVERT_int(REG(REG_i3));
	CALL_SYSCALL(maDrawImageRegion)(image, srcRect, dstPoint, transformMode);
	_SYSCALL_HANDLERES_void
	return;
}
case 50:
{
	LOGSC("\tmaGetImageSize(");
	MAHandle image = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	MAExtent res = CALL_SYSCALL(maGetImageSize)(image);
	_SYSCALL_HANDLERES_MAExtent
	return;
}
case 51:
{
	LOGSC("\tmaGetImageData(");
	MAHandle image = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	LOGSC(", ");
	void* dst = _SYSCALL_CONVERT_MAAddress(REG(REG_i1));
	LOGSC(", ");
	MARect* srcRect = _SYSCALL_CONVERT_MARect(REG(REG_i2));
	LOGSC(", ");
	int scanlength = _SYSCALL_CONVERT_int(REG(REG_i3));
	CALL_SYSCALL(maGetImageData)(image, dst, srcRect, scanlength);
	_SYSCALL_HANDLERES_void
	return;
}
case 52:
{
	LOGSC("\tmaSetDrawTarget(");
	MAHandle image = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	MAHandle res = CALL_SYSCALL(maSetDrawTarget)(image);
	_SYSCALL_HANDLERES_MAHandle
	return;
}
case 53:
{
	LOGSC("\tmaFindLabel(");
	char* name = _SYSCALL_CONVERT_MAString(REG(REG_i0));
	int res = CALL_SYSCALL(maFindLabel)(name);
	_SYSCALL_HANDLERES_int
	return;
}
case 54:
{
	LOGSC("\tmaCreateImageFromData(");
	MAHandle placeholder = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	LOGSC(", ");
	MAHandle data = _SYSCALL_CONVERT_MAHandle(REG(REG_i1));
	LOGSC(", ");
	int offset = _SYSCALL_CONVERT_int(REG(REG_i2));
	LOGSC(", ");
	int size = _SYSCALL_CONVERT_int(REG(REG_i3));
	int res = CALL_SYSCALL(maCreateImageFromData)(placeholder, data, offset, size);
	_SYSCALL_HANDLERES_int
	return;
}
case 55:
{
	LOGSC("\tmaCreateImageRaw(");
	MAHandle placeholder = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	LOGSC(", ");
	void* src = _SYSCALL_CONVERT_MAAddress(REG(REG_i1));
	LOGSC(", ");
	MAExtent size = _SYSCALL_CONVERT_MAExtent(REG(REG_i2));
	LOGSC(", ");
	int alpha = _SYSCALL_CONVERT_int(REG(REG_i3));
	int res = CALL_SYSCALL(maCreateImageRaw)(placeholder, src, size, alpha);
	_SYSCALL_HANDLERES_int
	return;
}
case 56:
{
	LOGSC("\tmaCreateDrawableImage(");
	MAHandle placeholder = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	LOGSC(", ");
	int width = _SYSCALL_CONVERT_int(REG(REG_i1));
	LOGSC(", ");
	int height = _SYSCALL_CONVERT_int(REG(REG_i2));
	int res = CALL_SYSCALL(maCreateDrawableImage)(placeholder, width, height);
	_SYSCALL_HANDLERES_int
	return;
}
case 57:
{
	LOGSC("\tmaCreateData(");
	MAHandle placeholder = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	LOGSC(", ");
	int size = _SYSCALL_CONVERT_int(REG(REG_i1));
	int res = CALL_SYSCALL(maCreateData)(placeholder, size);
	_SYSCALL_HANDLERES_int
	return;
}
case 58:
{
	LOGSC("\tmaCreatePlaceholder(");
	MAHandle res = CALL_SYSCALL(maCreatePlaceholder)();
	_SYSCALL_HANDLERES_MAHandle
	return;
}
case 59:
{
	LOGSC("\tmaDestroyPlaceholder(");
	MAHandle handle = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	CALL_SYSCALL(maDestroyPlaceholder)(handle);
	_SYSCALL_HANDLERES_void
	return;
}
case 60:
{
	LOGSC("\tmaDestroyObject(");
	MAHandle handle = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	CALL_SYSCALL(maDestroyObject)(handle);
	_SYSCALL_HANDLERES_void
	return;
}
case 61:
{
	LOGSC("\tmaGetDataSize(");
	MAHandle data = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	int res = CALL_SYSCALL(maGetDataSize)(data);
	_SYSCALL_HANDLERES_int
	return;
}
case 62:
{
	LOGSC("\tmaReadData(");
	MAHandle data = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	LOGSC(", ");
	void* dst = _SYSCALL_CONVERT_MAAddress(REG(REG_i1));
	LOGSC(", ");
	int offset = _SYSCALL_CONVERT_int(REG(REG_i2));
	LOGSC(", ");
	int size = _SYSCALL_CONVERT_int(REG(REG_i3));
	CALL_SYSCALL(maReadData)(data, dst, offset, size);
	_SYSCALL_HANDLERES_void
	return;
}
case 63:
{
	LOGSC("\tmaWriteData(");
	MAHandle data = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	LOGSC(", ");
	void* src = _SYSCALL_CONVERT_MAAddress(REG(REG_i1));
	LOGSC(", ");
	int offset = _SYSCALL_CONVERT_int(REG(REG_i2));
	LOGSC(", ");
	int size = _SYSCALL_CONVERT_int(REG(REG_i3));
	CALL_SYSCALL(maWriteData)(data, src, offset, size);
	_SYSCALL_HANDLERES_void
	return;
}
case 64:
{
	LOGSC("\tmaCopyData(");
	MACopyData* params = _SYSCALL_CONVERT_MACopyData(REG(REG_i0));
	CALL_SYSCALL(maCopyData)(params);
	_SYSCALL_HANDLERES_void
	return;
}
case 65:
{
	LOGSC("\tmaOpenStore(");
	char* name = _SYSCALL_CONVERT_MAString(REG(REG_i0));
	LOGSC(", ");
	int flags = _SYSCALL_CONVERT_int(REG(REG_i1));
	MAHandle res = CALL_SYSCALL(maOpenStore)(name, flags);
	_SYSCALL_HANDLERES_MAHandle
	return;
}
case 66:
{
	LOGSC("\tmaWriteStore(");
	MAHandle store = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	LOGSC(", ");
	MAHandle data = _SYSCALL_CONVERT_MAHandle(REG(REG_i1));
	int res = CALL_SYSCALL(maWriteStore)(store, data);
	_SYSCALL_HANDLERES_int
	return;
}
case 67:
{
	LOGSC("\tmaReadStore(");
	MAHandle store = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	LOGSC(", ");
	MAHandle placeholder = _SYSCALL_CONVERT_MAHandle(REG(REG_i1));
	int res = CALL_SYSCALL(maReadStore)(store, placeholder);
	_SYSCALL_HANDLERES_int
	return;
}
case 68:
{
	LOGSC("\tmaCloseStore(");
	MAHandle store = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	LOGSC(", ");
	int _delete = _SYSCALL_CONVERT_int(REG(REG_i1));
	CALL_SYSCALL(maCloseStore)(store, _delete);
	_SYSCALL_HANDLERES_void
	return;
}
case 69:
{
	LOGSC("\tmaConnect(");
	char* url = _SYSCALL_CONVERT_MAString(REG(REG_i0));
	MAHandle res = CALL_SYSCALL(maConnect)(url);
	_SYSCALL_HANDLERES_MAHandle
	return;
}
case 70:
{
	LOGSC("\tmaConnClose(");
	MAHandle conn = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	CALL_SYSCALL(maConnClose)(conn);
	_SYSCALL_HANDLERES_void
	return;
}
case 71:
{
	LOGSC("\tmaConnRead(");
	MAHandle conn = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	LOGSC(", ");
	void* dst = _SYSCALL_CONVERT_MAAddress(REG(REG_i1));
	LOGSC(", ");
	int size = _SYSCALL_CONVERT_int(REG(REG_i2));
	CALL_SYSCALL(maConnRead)(conn, dst, size);
	_SYSCALL_HANDLERES_void
	return;
}
case 72:
{
	LOGSC("\tmaConnWrite(");
	MAHandle conn = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	LOGSC(", ");
	void* src = _SYSCALL_CONVERT_MAAddress(REG(REG_i1));
	LOGSC(", ");
	int size = _SYSCALL_CONVERT_int(REG(REG_i2));
	CALL_SYSCALL(maConnWrite)(conn, src, size);
	_SYSCALL_HANDLERES_void
	return;
}
case 73:
{
	LOGSC("\tmaConnReadToData(");
	MAHandle conn = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	LOGSC(", ");
	MAHandle data = _SYSCALL_CONVERT_MAHandle(REG(REG_i1));
	LOGSC(", ");
	int offset = _SYSCALL_CONVERT_int(REG(REG_i2));
	LOGSC(", ");
	int size = _SYSCALL_CONVERT_int(REG(REG_i3));
	CALL_SYSCALL(maConnReadToData)(conn, data, offset, size);
	_SYSCALL_HANDLERES_void
	return;
}
case 74:
{
	LOGSC("\tmaConnWriteFromData(");
	MAHandle conn = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	LOGSC(", ");
	MAHandle data = _SYSCALL_CONVERT_MAHandle(REG(REG_i1));
	LOGSC(", ");
	int offset = _SYSCALL_CONVERT_int(REG(REG_i2));
	LOGSC(", ");
	int size = _SYSCALL_CONVERT_int(REG(REG_i3));
	CALL_SYSCALL(maConnWriteFromData)(conn, data, offset, size);
	_SYSCALL_HANDLERES_void
	return;
}
case 75:
{
	LOGSC("\tmaConnReadFrom(");
	MAHandle conn = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	LOGSC(", ");
	void* dst = _SYSCALL_CONVERT_MAAddress(REG(REG_i1));
	LOGSC(", ");
	int size = _SYSCALL_CONVERT_int(REG(REG_i2));
	LOGSC(", ");
	MAConnAddr* src = _SYSCALL_CONVERT_MAConnAddr(REG(REG_i3));
	CALL_SYSCALL(maConnReadFrom)(conn, dst, size, src);
	_SYSCALL_HANDLERES_void
	return;
}
case 76:
{
	LOGSC("\tmaConnWriteTo(");
	MAHandle conn = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	LOGSC(", ");
	void* src = _SYSCALL_CONVERT_MAAddress(REG(REG_i1));
	LOGSC(", ");
	int size = _SYSCALL_CONVERT_int(REG(REG_i2));
	LOGSC(", ");
	MAConnAddr* dst = _SYSCALL_CONVERT_MAConnAddr(REG(REG_i3));
	CALL_SYSCALL(maConnWriteTo)(conn, src, size, dst);
	_SYSCALL_HANDLERES_void
	return;
}
case 77:
{
	LOGSC("\tmaConnGetAddr(");
	MAHandle conn = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	LOGSC(", ");
	MAConnAddr* addr = _SYSCALL_CONVERT_MAConnAddr(REG(REG_i1));
	int res = CALL_SYSCALL(maConnGetAddr)(conn, addr);
	_SYSCALL_HANDLERES_int
	return;
}
case 78:
{
	LOGSC("\tmaHttpCreate(");
	char* url = _SYSCALL_CONVERT_MAString(REG(REG_i0));
	LOGSC(", ");
	int method = _SYSCALL_CONVERT_int(REG(REG_i1));
	MAHandle res = CALL_SYSCALL(maHttpCreate)(url, method);
	_SYSCALL_HANDLERES_MAHandle
	return;
}
case 79:
{
	LOGSC("\tmaHttpSetRequestHeader(");
	MAHandle conn = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	LOGSC(", ");
	char* key = _SYSCALL_CONVERT_MAString(REG(REG_i1));
	LOGSC(", ");
	char* value = _SYSCALL_CONVERT_MAString(REG(REG_i2));
	CALL_SYSCALL(maHttpSetRequestHeader)(conn, key, value);
	_SYSCALL_HANDLERES_void
	return;
}
case 80:
{
	LOGSC("\tmaHttpGetResponseHeader(");
	MAHandle conn = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	LOGSC(", ");
	char* key = _SYSCALL_CONVERT_MAString(REG(REG_i1));
	LOGSC(", ");
	char* buffer = _SYSCALL_CONVERT_MAString(REG(REG_i2));
	LOGSC(", ");
	int bufSize = _SYSCALL_CONVERT_int(REG(REG_i3));
	int res = CALL_SYSCALL(maHttpGetResponseHeader)(conn, key, buffer, bufSize);
	_SYSCALL_HANDLERES_int
	return;
}
case 81:
{
	LOGSC("\tmaHttpFinish(");
	MAHandle conn = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	CALL_SYSCALL(maHttpFinish)(conn);
	_SYSCALL_HANDLERES_void
	return;
}
case 82:
{
	LOGSC("\tmaLoadResources(");
	MAHandle data = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	int res = CALL_SYSCALL(maLoadResources)(data);
	_SYSCALL_HANDLERES_int
	return;
}
case 83:
{
	LOGSC("\tmaLoadResource(");
	MAHandle handle = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	LOGSC(", ");
	MAHandle placeholder = _SYSCALL_CONVERT_MAHandle(REG(REG_i1));
	LOGSC(", ");
	int flag = _SYSCALL_CONVERT_int(REG(REG_i2));
	int res = CALL_SYSCALL(maLoadResource)(handle, placeholder, flag);
	_SYSCALL_HANDLERES_int
	return;
}
case 84:
{
	LOGSC("\tmaCountResources(");
	int res = CALL_SYSCALL(maCountResources)();
	_SYSCALL_HANDLERES_int
	return;
}
case 85:
{
	LOGSC("\tmaLoadProgram(");
	MAHandle data = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	LOGSC(", ");
	int reload = _SYSCALL_CONVERT_int(REG(REG_i1));
	CALL_SYSCALL(maLoadProgram)(data, reload);
	_SYSCALL_HANDLERES_void
	return;
}
case 86:
{
	LOGSC("\tmaGetKeys(");
	int res = CALL_SYSCALL(maGetKeys)();
	_SYSCALL_HANDLERES_int
	return;
}
case 87:
{
	LOGSC("\tmaGetEvent(");
	MAEvent* event = _SYSCALL_CONVERT_MAEvent(REG(REG_i0));
	int res = CALL_SYSCALL(maGetEvent)(event);
	_SYSCALL_HANDLERES_int
	return;
}
case 88:
{
	LOGSC("\tmaWait(");
	int timeout = _SYSCALL_CONVERT_int(REG(REG_i0));
	CALL_SYSCALL(maWait)(timeout);
	_SYSCALL_HANDLERES_void
	return;
}
case 89:
{
	LOGSC("\tmaTime(");
	int res = CALL_SYSCALL(maTime)();
	_SYSCALL_HANDLERES_int
	return;
}
case 90:
{
	LOGSC("\tmaLocalTime(");
	int res = CALL_SYSCALL(maLocalTime)();
	_SYSCALL_HANDLERES_int
	return;
}
case 91:
{
	LOGSC("\tmaGetMilliSecondCount(");
	int res = CALL_SYSCALL(maGetMilliSecondCount)();
	_SYSCALL_HANDLERES_int
	return;
}
case 92:
{
	LOGSC("\tmaFreeObjectMemory(");
	int res = CALL_SYSCALL(maFreeObjectMemory)();
	_SYSCALL_HANDLERES_int
	return;
}
case 93:
{
	LOGSC("\tmaTotalObjectMemory(");
	int res = CALL_SYSCALL(maTotalObjectMemory)();
	_SYSCALL_HANDLERES_int
	return;
}
case 94:
{
	LOGSC("\tmaVibrate(");
	int ms = _SYSCALL_CONVERT_int(REG(REG_i0));
	int res = CALL_SYSCALL(maVibrate)(ms);
	_SYSCALL_HANDLERES_int
	return;
}
case 95:
{
	LOGSC("\tmaSoundPlay(");
	MAHandle sound_res = _SYSCALL_CONVERT_MAHandle(REG(REG_i0));
	LOGSC(", ");
	int offset = _SYSCALL_CONVERT_int(REG(REG_i1));
	LOGSC(", ");
	int size = _SYSCALL_CONVERT_int(REG(REG_i2));
	int res = CALL_SYSCALL(maSoundPlay)(sound_res, offset, size);
	_SYSCALL_HANDLERES_int
	return;
}
case 96:
{
	LOGSC("\tmaSoundStop(");
	CALL_SYSCALL(maSoundStop)();
	_SYSCALL_HANDLERES_void
	return;
}
case 97:
{
	LOGSC("\tmaSoundIsPlaying(");
	int res = CALL_SYSCALL(maSoundIsPlaying)();
	_SYSCALL_HANDLERES_int
	return;
}
case 98:
{
	LOGSC("\tmaSoundGetVolume(");
	int res = CALL_SYSCALL(maSoundGetVolume)();
	_SYSCALL_HANDLERES_int
	return;
}
case 99:
{
	LOGSC("\tmaSoundSetVolume(");
	int vol = _SYSCALL_CONVERT_int(REG(REG_i0));
	CALL_SYSCALL(maSoundSetVolume)(vol);
	_SYSCALL_HANDLERES_void
	return;
}
case 100:
{
	LOGSC("\tmaExtensionFunctionInvoke(");
	int function = _SYSCALL_CONVERT_int(REG(REG_i0));
	LOGSC(", ");
	int a = _SYSCALL_CONVERT_int(REG(REG_i1));
	LOGSC(", ");
	int b = _SYSCALL_CONVERT_int(REG(REG_i2));
	LOGSC(", ");
	int c = _SYSCALL_CONVERT_int(REG(REG_i3));
	longlong res = CALL_SYSCALL(maExtensionFunctionInvoke)(function, a, b, c);
	_SYSCALL_HANDLERES_longlong
	return;
}
case 101:
{
	LOGSC("\tmaIOCtl(");
	int function = _SYSCALL_CONVERT_int(REG(REG_i0));
	LOGSC(", ");
	int a = _SYSCALL_CONVERT_int(REG(REG_i1));
	LOGSC(", ");
	int b = _SYSCALL_CONVERT_int(REG(REG_i2));
	LOGSC(", ");
	int c = _SYSCALL_CONVERT_int(REG(REG_i3));
	longlong res = CALL_SYSCALL(maIOCtl)(function, a, b, c);
	_SYSCALL_HANDLERES_longlong
	return;
}
