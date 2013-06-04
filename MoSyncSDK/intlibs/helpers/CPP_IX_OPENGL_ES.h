#ifndef IX_OPENGL_ES_DEFS_H
#define IX_OPENGL_ES_DEFS_H

/** \brief A hash of the abstract representation of the API described in this file.
 * Identifiers, declarations and definitions are included in the calculation of the hash,
 * but documentation is not.
 */
#define MAIDL_HASH ((int)0x28c5d5c8)

#ifndef DONT_WANT_IX_OPENGL_ES_TYPEDEFS
/** @ingroup OpenGLES */
typedef signed char khronos_int8_t;
/** @ingroup OpenGLES */
typedef unsigned char khronos_uint8_t;
/** @ingroup OpenGLES */
typedef short int khronos_int16_t;
/** @ingroup OpenGLES */
typedef short unsigned int khronos_uint16_t;
/** @ingroup OpenGLES */
typedef long int khronos_intptr_t;
/** @ingroup OpenGLES */
typedef long unsigned int khronos_uintptr_t;
/** @ingroup OpenGLES */
typedef long int khronos_ssize_t;
/** @ingroup OpenGLES */
typedef long unsigned int khronos_usize_t;
/** @ingroup OpenGLES */
typedef int khronos_int32_t;
/** @ingroup OpenGLES */
typedef unsigned int khronos_uint32_t;
/** @ingroup OpenGLES */
typedef long long int khronos_int64_t;
/** @ingroup OpenGLES */
typedef long long unsigned int khronos_uint64_t;
/** @ingroup OpenGLES */
typedef float khronos_float_t;
/** @ingroup OpenGLES */
typedef khronos_uint64_t khronos_utime_nanoseconds_t;
/** @ingroup OpenGLES */
typedef khronos_int64_t khronos_stime_nanoseconds_t;
/** @ingroup OpenGLES */
typedef void GLvoid;
/** @ingroup OpenGLES */
typedef char GLchar;
/** @ingroup OpenGLES */
typedef unsigned int GLenum;
/** @ingroup OpenGLES */
typedef unsigned char GLboolean;
/** @ingroup OpenGLES */
typedef unsigned int GLbitfield;
/** @ingroup OpenGLES */
typedef khronos_int8_t GLbyte;
/** @ingroup OpenGLES */
typedef short int GLshort;
/** @ingroup OpenGLES */
typedef int GLint;
/** @ingroup OpenGLES */
typedef int GLsizei;
/** @ingroup OpenGLES */
typedef khronos_uint8_t GLubyte;
/** @ingroup OpenGLES */
typedef short unsigned int GLushort;
/** @ingroup OpenGLES */
typedef unsigned int GLuint;
/** @ingroup OpenGLES */
typedef khronos_int32_t GLclampx;
/** @ingroup OpenGLES */
typedef khronos_float_t GLfloat;
/** @ingroup OpenGLES */
typedef khronos_float_t GLclampf;
/** @ingroup OpenGLES */
typedef khronos_int32_t GLfixed;
/** @ingroup OpenGLES */
typedef khronos_intptr_t GLintptr;
/** @ingroup OpenGLES */
typedef khronos_ssize_t GLsizeiptr;

#endif
#define maExtensionFunctionInvoke_IX_OPENGL_ES_caselist \

#define maExtensionFunctionInvoke_IX_OPENGL_ES_syscall_caselist \

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
#define maIOCtl_IX_OPENGL_ES_caselist \
maIOCtl_glActiveTexture_case(glActiveTexture) \
maIOCtl_glBindBuffer_case(glBindBuffer) \
maIOCtl_glBindTexture_case(glBindTexture) \
maIOCtl_glBlendFunc_case(glBlendFunc) \
maIOCtl_glBufferData_case(glBufferData) \
maIOCtl_glBufferSubData_case(glBufferSubData) \
maIOCtl_glClear_case(glClear) \
maIOCtl_glClearColor_case(glClearColor) \
maIOCtl_glClearDepthf_case(glClearDepthf) \
maIOCtl_glClearStencil_case(glClearStencil) \
maIOCtl_glColorMask_case(glColorMask) \
maIOCtl_glCompressedTexImage2D_case(glCompressedTexImage2D) \
maIOCtl_glCompressedTexSubImage2D_case(glCompressedTexSubImage2D) \
maIOCtl_glCopyTexImage2D_case(glCopyTexImage2D) \
maIOCtl_glCopyTexSubImage2D_case(glCopyTexSubImage2D) \
maIOCtl_glCullFace_case(glCullFace) \
maIOCtl_glDeleteBuffers_case(glDeleteBuffers) \
maIOCtl_glDeleteTextures_case(glDeleteTextures) \
maIOCtl_glDepthFunc_case(glDepthFunc) \
maIOCtl_glDepthMask_case(glDepthMask) \
maIOCtl_glDepthRangef_case(glDepthRangef) \
maIOCtl_glDisable_case(glDisable) \
maIOCtl_glDrawArrays_case(glDrawArrays) \
maIOCtl_glDrawElements_case(glDrawElements) \
maIOCtl_glEnable_case(glEnable) \
maIOCtl_glFinish_case(glFinish) \
maIOCtl_glFlush_case(glFlush) \
maIOCtl_glFrontFace_case(glFrontFace) \
maIOCtl_glGenBuffers_case(glGenBuffers) \
maIOCtl_glGenTextures_case(glGenTextures) \
maIOCtl_glGetBooleanv_case(glGetBooleanv) \
maIOCtl_glGetBufferParameteriv_case(glGetBufferParameteriv) \
maIOCtl_glGetError_case(glGetError) \
maIOCtl_glGetFloatv_case(glGetFloatv) \
maIOCtl_glGetIntegerv_case(glGetIntegerv) \
maIOCtl_glGetStringHandle_case(glGetStringHandle) \
maIOCtl_glGetTexParameterfv_case(glGetTexParameterfv) \
maIOCtl_glGetTexParameteriv_case(glGetTexParameteriv) \
maIOCtl_glHint_case(glHint) \
maIOCtl_glIsBuffer_case(glIsBuffer) \
maIOCtl_glIsEnabled_case(glIsEnabled) \
maIOCtl_glIsTexture_case(glIsTexture) \
maIOCtl_glLineWidth_case(glLineWidth) \
maIOCtl_glPixelStorei_case(glPixelStorei) \
maIOCtl_glPolygonOffset_case(glPolygonOffset) \
maIOCtl_glReadPixels_case(glReadPixels) \
maIOCtl_glSampleCoverage_case(glSampleCoverage) \
maIOCtl_glScissor_case(glScissor) \
maIOCtl_glStencilFunc_case(glStencilFunc) \
maIOCtl_glStencilMask_case(glStencilMask) \
maIOCtl_glStencilOp_case(glStencilOp) \
maIOCtl_glTexImage2D_case(glTexImage2D) \
maIOCtl_glTexParameterf_case(glTexParameterf) \
maIOCtl_glTexParameterfv_case(glTexParameterfv) \
maIOCtl_glTexParameteri_case(glTexParameteri) \
maIOCtl_glTexParameteriv_case(glTexParameteriv) \
maIOCtl_glTexSubImage2D_case(glTexSubImage2D) \
maIOCtl_glViewport_case(glViewport) \

#define maIOCtl_IX_OPENGL_ES_syscall_caselist \
maIOCtl_syscall_case(glActiveTexture) \
maIOCtl_syscall_case(glBindBuffer) \
maIOCtl_syscall_case(glBindTexture) \
maIOCtl_syscall_case(glBlendFunc) \
maIOCtl_syscall_case(glBufferData) \
maIOCtl_syscall_case(glBufferSubData) \
maIOCtl_syscall_case(glClear) \
maIOCtl_syscall_case(glClearColor) \
maIOCtl_syscall_case(glClearDepthf) \
maIOCtl_syscall_case(glClearStencil) \
maIOCtl_syscall_case(glColorMask) \
maIOCtl_syscall_case(glCompressedTexImage2D) \
maIOCtl_syscall_case(glCompressedTexSubImage2D) \
maIOCtl_syscall_case(glCopyTexImage2D) \
maIOCtl_syscall_case(glCopyTexSubImage2D) \
maIOCtl_syscall_case(glCullFace) \
maIOCtl_syscall_case(glDeleteBuffers) \
maIOCtl_syscall_case(glDeleteTextures) \
maIOCtl_syscall_case(glDepthFunc) \
maIOCtl_syscall_case(glDepthMask) \
maIOCtl_syscall_case(glDepthRangef) \
maIOCtl_syscall_case(glDisable) \
maIOCtl_syscall_case(glDrawArrays) \
maIOCtl_syscall_case(glDrawElements) \
maIOCtl_syscall_case(glEnable) \
maIOCtl_syscall_case(glFinish) \
maIOCtl_syscall_case(glFlush) \
maIOCtl_syscall_case(glFrontFace) \
maIOCtl_syscall_case(glGenBuffers) \
maIOCtl_syscall_case(glGenTextures) \
maIOCtl_syscall_case(glGetBooleanv) \
maIOCtl_syscall_case(glGetBufferParameteriv) \
maIOCtl_syscall_case(glGetError) \
maIOCtl_syscall_case(glGetFloatv) \
maIOCtl_syscall_case(glGetIntegerv) \
maIOCtl_syscall_case(glGetStringHandle) \
maIOCtl_syscall_case(glGetTexParameterfv) \
maIOCtl_syscall_case(glGetTexParameteriv) \
maIOCtl_syscall_case(glHint) \
maIOCtl_syscall_case(glIsBuffer) \
maIOCtl_syscall_case(glIsEnabled) \
maIOCtl_syscall_case(glIsTexture) \
maIOCtl_syscall_case(glLineWidth) \
maIOCtl_syscall_case(glPixelStorei) \
maIOCtl_syscall_case(glPolygonOffset) \
maIOCtl_syscall_case(glReadPixels) \
maIOCtl_syscall_case(glSampleCoverage) \
maIOCtl_syscall_case(glScissor) \
maIOCtl_syscall_case(glStencilFunc) \
maIOCtl_syscall_case(glStencilMask) \
maIOCtl_syscall_case(glStencilOp) \
maIOCtl_syscall_case(glTexImage2D) \
maIOCtl_syscall_case(glTexParameterf) \
maIOCtl_syscall_case(glTexParameterfv) \
maIOCtl_syscall_case(glTexParameteri) \
maIOCtl_syscall_case(glTexParameteriv) \
maIOCtl_syscall_case(glTexSubImage2D) \
maIOCtl_syscall_case(glViewport) \

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
#define maIOCtl_glActiveTexture 180
#define maIOCtl_glActiveTexture_case(func) \
case 180: \
{ \
GLenum _texture = (GLenum)a; \
func(_texture); \
return 0; \
} \

#define maIOCtl_glBindBuffer 181
#define maIOCtl_glBindBuffer_case(func) \
case 181: \
{ \
GLenum _target = (GLenum)a; \
GLuint _buffer = (GLuint)b; \
func(_target, _buffer); \
return 0; \
} \

#define maIOCtl_glBindTexture 182
#define maIOCtl_glBindTexture_case(func) \
case 182: \
{ \
GLenum _target = (GLenum)a; \
GLuint _texture = (GLuint)b; \
func(_target, _texture); \
return 0; \
} \

#define maIOCtl_glBlendFunc 183
#define maIOCtl_glBlendFunc_case(func) \
case 183: \
{ \
GLenum _sfactor = (GLenum)a; \
GLenum _dfactor = (GLenum)b; \
func(_sfactor, _dfactor); \
return 0; \
} \

#define maIOCtl_glBufferData 184
#define maIOCtl_glBufferData_case(func) \
case 184: \
{ \
GLenum _target = (GLenum)a; \
GLsizeiptr _size = (GLsizeiptr)b; \
const void* _data = GVMR(c, MAAddress); \
GLenum _usage = (GLenum)ARG_NO_4; \
func(_target, _size, _data, _usage); \
return 0; \
} \

#define maIOCtl_glBufferSubData 185
#define maIOCtl_glBufferSubData_case(func) \
case 185: \
{ \
GLenum _target = (GLenum)a; \
GLintptr _offset = (GLintptr)b; \
GLsizeiptr _size = (GLsizeiptr)c; \
const void* _data = GVMR(ARG_NO_4, MAAddress); \
func(_target, _offset, _size, _data); \
return 0; \
} \

#define maIOCtl_glClear 186
#define maIOCtl_glClear_case(func) \
case 186: \
{ \
GLbitfield _mask = (GLbitfield)a; \
func(_mask); \
return 0; \
} \

#define maIOCtl_glClearColor 187
#define maIOCtl_glClearColor_case(func) \
case 187: \
{ \
MA_FV _red_dv; \
_red_dv.i = a; \
GLclampf _red = _red_dv.f; \
MA_FV _green_dv; \
_green_dv.i = b; \
GLclampf _green = _green_dv.f; \
MA_FV _blue_dv; \
_blue_dv.i = c; \
GLclampf _blue = _blue_dv.f; \
MA_FV _alpha_dv; \
_alpha_dv.i = ARG_NO_4; \
GLclampf _alpha = _alpha_dv.f; \
func(_red, _green, _blue, _alpha); \
return 0; \
} \

#define maIOCtl_glClearDepthf 188
#define maIOCtl_glClearDepthf_case(func) \
case 188: \
{ \
MA_FV _depth_dv; \
_depth_dv.i = a; \
GLclampf _depth = _depth_dv.f; \
func(_depth); \
return 0; \
} \

#define maIOCtl_glClearStencil 189
#define maIOCtl_glClearStencil_case(func) \
case 189: \
{ \
GLint _s = (GLint)a; \
func(_s); \
return 0; \
} \

#define maIOCtl_glColorMask 190
#define maIOCtl_glColorMask_case(func) \
case 190: \
{ \
GLboolean _red = (GLboolean)a; \
GLboolean _green = (GLboolean)b; \
GLboolean _blue = (GLboolean)c; \
GLboolean _alpha = (GLboolean)ARG_NO_4; \
func(_red, _green, _blue, _alpha); \
return 0; \
} \

#define maIOCtl_glCompressedTexImage2D 191
#define maIOCtl_glCompressedTexImage2D_case(func) \
case 191: \
{ \
GLenum _target = (GLenum)a; \
GLint _level = (GLint)b; \
GLenum _internalformat = (GLenum)c; \
GLsizei _width = (GLsizei)ARG_NO_4; \
GLsizei _height = (GLsizei)ARG_NO_5; \
GLint _border = (GLint)ARG_NO_6; \
GLsizei _imageSize = (GLsizei)ARG_NO_7; \
const void* _data = GVMR(ARG_NO_8, MAAddress); \
func(_target, _level, _internalformat, _width, _height, _border, _imageSize, _data); \
return 0; \
} \

#define maIOCtl_glCompressedTexSubImage2D 192
#define maIOCtl_glCompressedTexSubImage2D_case(func) \
case 192: \
{ \
GLenum _target = (GLenum)a; \
GLint _level = (GLint)b; \
GLint _xoffset = (GLint)c; \
GLint _yoffset = (GLint)ARG_NO_4; \
GLsizei _width = (GLsizei)ARG_NO_5; \
GLsizei _height = (GLsizei)ARG_NO_6; \
GLenum _format = (GLenum)ARG_NO_7; \
GLsizei _imageSize = (GLsizei)ARG_NO_8; \
const void* _data = GVMR(ARG_NO_9, MAAddress); \
func(_target, _level, _xoffset, _yoffset, _width, _height, _format, _imageSize, _data); \
return 0; \
} \

#define maIOCtl_glCopyTexImage2D 193
#define maIOCtl_glCopyTexImage2D_case(func) \
case 193: \
{ \
GLenum _target = (GLenum)a; \
GLint _level = (GLint)b; \
GLenum _internalformat = (GLenum)c; \
GLint _x = (GLint)ARG_NO_4; \
GLint _y = (GLint)ARG_NO_5; \
GLsizei _width = (GLsizei)ARG_NO_6; \
GLsizei _height = (GLsizei)ARG_NO_7; \
GLint _border = (GLint)ARG_NO_8; \
func(_target, _level, _internalformat, _x, _y, _width, _height, _border); \
return 0; \
} \

#define maIOCtl_glCopyTexSubImage2D 194
#define maIOCtl_glCopyTexSubImage2D_case(func) \
case 194: \
{ \
GLenum _target = (GLenum)a; \
GLint _level = (GLint)b; \
GLint _xoffset = (GLint)c; \
GLint _yoffset = (GLint)ARG_NO_4; \
GLint _x = (GLint)ARG_NO_5; \
GLint _y = (GLint)ARG_NO_6; \
GLsizei _width = (GLsizei)ARG_NO_7; \
GLsizei _height = (GLsizei)ARG_NO_8; \
func(_target, _level, _xoffset, _yoffset, _x, _y, _width, _height); \
return 0; \
} \

#define maIOCtl_glCullFace 195
#define maIOCtl_glCullFace_case(func) \
case 195: \
{ \
GLenum _mode = (GLenum)a; \
func(_mode); \
return 0; \
} \

#define maIOCtl_glDeleteBuffers 196
#define maIOCtl_glDeleteBuffers_case(func) \
case 196: \
{ \
GLsizei _n = (GLsizei)a; \
const GLuint* _buffers = GVMR(b, GLuint); \
func(_n, _buffers); \
return 0; \
} \

#define maIOCtl_glDeleteTextures 197
#define maIOCtl_glDeleteTextures_case(func) \
case 197: \
{ \
GLsizei _n = (GLsizei)a; \
const GLuint* _textures = GVMR(b, GLuint); \
func(_n, _textures); \
return 0; \
} \

#define maIOCtl_glDepthFunc 198
#define maIOCtl_glDepthFunc_case(func) \
case 198: \
{ \
GLenum _func = (GLenum)a; \
func(_func); \
return 0; \
} \

#define maIOCtl_glDepthMask 199
#define maIOCtl_glDepthMask_case(func) \
case 199: \
{ \
GLboolean _flag = (GLboolean)a; \
func(_flag); \
return 0; \
} \

#define maIOCtl_glDepthRangef 200
#define maIOCtl_glDepthRangef_case(func) \
case 200: \
{ \
MA_FV _zNear_dv; \
_zNear_dv.i = a; \
GLclampf _zNear = _zNear_dv.f; \
MA_FV _zFar_dv; \
_zFar_dv.i = b; \
GLclampf _zFar = _zFar_dv.f; \
func(_zNear, _zFar); \
return 0; \
} \

#define maIOCtl_glDisable 201
#define maIOCtl_glDisable_case(func) \
case 201: \
{ \
GLenum _cap = (GLenum)a; \
func(_cap); \
return 0; \
} \

#define maIOCtl_glDrawArrays 202
#define maIOCtl_glDrawArrays_case(func) \
case 202: \
{ \
GLenum _mode = (GLenum)a; \
GLint _first = (GLint)b; \
GLsizei _count = (GLsizei)c; \
func(_mode, _first, _count); \
return 0; \
} \

#define maIOCtl_glDrawElements 203
#define maIOCtl_glDrawElements_case(func) \
case 203: \
{ \
GLenum _mode = (GLenum)a; \
GLsizei _count = (GLsizei)b; \
GLenum _type = (GLenum)c; \
const void* _indices = GVMR(ARG_NO_4, MAAddress); \
func(_mode, _count, _type, _indices); \
return 0; \
} \

#define maIOCtl_glEnable 204
#define maIOCtl_glEnable_case(func) \
case 204: \
{ \
GLenum _cap = (GLenum)a; \
func(_cap); \
return 0; \
} \

#define maIOCtl_glFinish 205
#define maIOCtl_glFinish_case(func) \
case 205: \
{ \
func(); \
return 0; \
} \

#define maIOCtl_glFlush 206
#define maIOCtl_glFlush_case(func) \
case 206: \
{ \
func(); \
return 0; \
} \

#define maIOCtl_glFrontFace 207
#define maIOCtl_glFrontFace_case(func) \
case 207: \
{ \
GLenum _mode = (GLenum)a; \
func(_mode); \
return 0; \
} \

#define maIOCtl_glGenBuffers 208
#define maIOCtl_glGenBuffers_case(func) \
case 208: \
{ \
GLsizei _n = (GLsizei)a; \
GLuint* _buffers = GVMR(b, GLuint); \
func(_n, _buffers); \
return 0; \
} \

#define maIOCtl_glGenTextures 209
#define maIOCtl_glGenTextures_case(func) \
case 209: \
{ \
GLsizei _n = (GLsizei)a; \
GLuint* _textures = GVMR(b, GLuint); \
func(_n, _textures); \
return 0; \
} \

#define maIOCtl_glGetBooleanv 210
#define maIOCtl_glGetBooleanv_case(func) \
case 210: \
{ \
GLenum _pname = (GLenum)a; \
GLboolean* _params = GVMR(b, GLboolean); \
func(_pname, _params); \
return 0; \
} \

#define maIOCtl_glGetBufferParameteriv 211
#define maIOCtl_glGetBufferParameteriv_case(func) \
case 211: \
{ \
GLenum _target = (GLenum)a; \
GLenum _pname = (GLenum)b; \
GLint* _params = GVMR(c, GLint); \
func(_target, _pname, _params); \
return 0; \
} \

#define maIOCtl_glGetError 212
#define maIOCtl_glGetError_case(func) \
case 212: \
{ \
return func(); \
} \

#define maIOCtl_glGetFloatv 213
#define maIOCtl_glGetFloatv_case(func) \
case 213: \
{ \
GLenum _pname = (GLenum)a; \
GLfloat* _params = GVMR(b, GLfloat); \
func(_pname, _params); \
return 0; \
} \

#define maIOCtl_glGetIntegerv 214
#define maIOCtl_glGetIntegerv_case(func) \
case 214: \
{ \
GLenum _pname = (GLenum)a; \
GLint* _params = GVMR(b, GLint); \
func(_pname, _params); \
return 0; \
} \

#define maIOCtl_glGetStringHandle 215
#define maIOCtl_glGetStringHandle_case(func) \
case 215: \
{ \
GLenum _name = (GLenum)a; \
return func(_name); \
} \

#define maIOCtl_glGetTexParameterfv 216
#define maIOCtl_glGetTexParameterfv_case(func) \
case 216: \
{ \
GLenum _target = (GLenum)a; \
GLenum _pname = (GLenum)b; \
GLfloat* _params = GVMR(c, GLfloat); \
func(_target, _pname, _params); \
return 0; \
} \

#define maIOCtl_glGetTexParameteriv 217
#define maIOCtl_glGetTexParameteriv_case(func) \
case 217: \
{ \
GLenum _target = (GLenum)a; \
GLenum _pname = (GLenum)b; \
GLint* _params = GVMR(c, GLint); \
func(_target, _pname, _params); \
return 0; \
} \

#define maIOCtl_glHint 218
#define maIOCtl_glHint_case(func) \
case 218: \
{ \
GLenum _target = (GLenum)a; \
GLenum _mode = (GLenum)b; \
func(_target, _mode); \
return 0; \
} \

#define maIOCtl_glIsBuffer 219
#define maIOCtl_glIsBuffer_case(func) \
case 219: \
{ \
GLuint _buffer = (GLuint)a; \
return func(_buffer); \
} \

#define maIOCtl_glIsEnabled 220
#define maIOCtl_glIsEnabled_case(func) \
case 220: \
{ \
GLenum _cap = (GLenum)a; \
return func(_cap); \
} \

#define maIOCtl_glIsTexture 221
#define maIOCtl_glIsTexture_case(func) \
case 221: \
{ \
GLuint _texture = (GLuint)a; \
return func(_texture); \
} \

#define maIOCtl_glLineWidth 222
#define maIOCtl_glLineWidth_case(func) \
case 222: \
{ \
MA_FV _width_dv; \
_width_dv.i = a; \
GLfloat _width = _width_dv.f; \
func(_width); \
return 0; \
} \

#define maIOCtl_glPixelStorei 223
#define maIOCtl_glPixelStorei_case(func) \
case 223: \
{ \
GLenum _pname = (GLenum)a; \
GLint _param = (GLint)b; \
func(_pname, _param); \
return 0; \
} \

#define maIOCtl_glPolygonOffset 224
#define maIOCtl_glPolygonOffset_case(func) \
case 224: \
{ \
MA_FV _factor_dv; \
_factor_dv.i = a; \
GLfloat _factor = _factor_dv.f; \
MA_FV _units_dv; \
_units_dv.i = b; \
GLfloat _units = _units_dv.f; \
func(_factor, _units); \
return 0; \
} \

#define maIOCtl_glReadPixels 225
#define maIOCtl_glReadPixels_case(func) \
case 225: \
{ \
GLint _x = (GLint)a; \
GLint _y = (GLint)b; \
GLsizei _width = (GLsizei)c; \
GLsizei _height = (GLsizei)ARG_NO_4; \
GLenum _format = (GLenum)ARG_NO_5; \
GLenum _type = (GLenum)ARG_NO_6; \
void* _pixels = GVMR(ARG_NO_7, MAAddress); \
func(_x, _y, _width, _height, _format, _type, _pixels); \
return 0; \
} \

#define maIOCtl_glSampleCoverage 226
#define maIOCtl_glSampleCoverage_case(func) \
case 226: \
{ \
MA_FV _value_dv; \
_value_dv.i = a; \
GLclampf _value = _value_dv.f; \
GLboolean _invert = (GLboolean)b; \
func(_value, _invert); \
return 0; \
} \

#define maIOCtl_glScissor 227
#define maIOCtl_glScissor_case(func) \
case 227: \
{ \
GLint _x = (GLint)a; \
GLint _y = (GLint)b; \
GLsizei _width = (GLsizei)c; \
GLsizei _height = (GLsizei)ARG_NO_4; \
func(_x, _y, _width, _height); \
return 0; \
} \

#define maIOCtl_glStencilFunc 228
#define maIOCtl_glStencilFunc_case(func) \
case 228: \
{ \
GLenum _func = (GLenum)a; \
GLint _ref = (GLint)b; \
GLuint _mask = (GLuint)c; \
func(_func, _ref, _mask); \
return 0; \
} \

#define maIOCtl_glStencilMask 229
#define maIOCtl_glStencilMask_case(func) \
case 229: \
{ \
GLuint _mask = (GLuint)a; \
func(_mask); \
return 0; \
} \

#define maIOCtl_glStencilOp 230
#define maIOCtl_glStencilOp_case(func) \
case 230: \
{ \
GLenum _fail = (GLenum)a; \
GLenum _zfail = (GLenum)b; \
GLenum _zpass = (GLenum)c; \
func(_fail, _zfail, _zpass); \
return 0; \
} \

#define maIOCtl_glTexImage2D 231
#define maIOCtl_glTexImage2D_case(func) \
case 231: \
{ \
GLenum _target = (GLenum)a; \
GLint _level = (GLint)b; \
GLint _internalformat = (GLint)c; \
GLsizei _width = (GLsizei)ARG_NO_4; \
GLsizei _height = (GLsizei)ARG_NO_5; \
GLint _border = (GLint)ARG_NO_6; \
GLenum _format = (GLenum)ARG_NO_7; \
GLenum _type = (GLenum)ARG_NO_8; \
const void* _pixels = GVMR(ARG_NO_9, MAAddress); \
func(_target, _level, _internalformat, _width, _height, _border, _format, _type, _pixels); \
return 0; \
} \

#define maIOCtl_glTexParameterf 232
#define maIOCtl_glTexParameterf_case(func) \
case 232: \
{ \
GLenum _target = (GLenum)a; \
GLenum _pname = (GLenum)b; \
MA_FV _param_dv; \
_param_dv.i = c; \
GLfloat _param = _param_dv.f; \
func(_target, _pname, _param); \
return 0; \
} \

#define maIOCtl_glTexParameterfv 233
#define maIOCtl_glTexParameterfv_case(func) \
case 233: \
{ \
GLenum _target = (GLenum)a; \
GLenum _pname = (GLenum)b; \
const GLfloat* _params = GVMR(c, GLfloat); \
func(_target, _pname, _params); \
return 0; \
} \

#define maIOCtl_glTexParameteri 234
#define maIOCtl_glTexParameteri_case(func) \
case 234: \
{ \
GLenum _target = (GLenum)a; \
GLenum _pname = (GLenum)b; \
GLint _param = (GLint)c; \
func(_target, _pname, _param); \
return 0; \
} \

#define maIOCtl_glTexParameteriv 235
#define maIOCtl_glTexParameteriv_case(func) \
case 235: \
{ \
GLenum _target = (GLenum)a; \
GLenum _pname = (GLenum)b; \
const GLint* _params = GVMR(c, GLint); \
func(_target, _pname, _params); \
return 0; \
} \

#define maIOCtl_glTexSubImage2D 236
#define maIOCtl_glTexSubImage2D_case(func) \
case 236: \
{ \
GLenum _target = (GLenum)a; \
GLint _level = (GLint)b; \
GLint _xoffset = (GLint)c; \
GLint _yoffset = (GLint)ARG_NO_4; \
GLsizei _width = (GLsizei)ARG_NO_5; \
GLsizei _height = (GLsizei)ARG_NO_6; \
GLenum _format = (GLenum)ARG_NO_7; \
GLenum _type = (GLenum)ARG_NO_8; \
const void* _pixels = GVMR(ARG_NO_9, MAAddress); \
func(_target, _level, _xoffset, _yoffset, _width, _height, _format, _type, _pixels); \
return 0; \
} \

#define maIOCtl_glViewport 237
#define maIOCtl_glViewport_case(func) \
case 237: \
{ \
GLint _x = (GLint)a; \
GLint _y = (GLint)b; \
GLsizei _width = (GLsizei)c; \
GLsizei _height = (GLsizei)ARG_NO_4; \
func(_x, _y, _width, _height); \
return 0; \
} \


#endif	//IX_OPENGL_ES_DEFS_H
