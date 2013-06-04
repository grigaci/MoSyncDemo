#ifndef IX_GL1_DEFS_H
#define IX_GL1_DEFS_H

/** \brief A hash of the abstract representation of the API described in this file.
 * Identifiers, declarations and definitions are included in the calculation of the hash,
 * but documentation is not.
 */
#define MAIDL_HASH ((int)0x28c5d5c8)

#ifndef DONT_WANT_IX_GL1_TYPEDEFS
#endif
#define maExtensionFunctionInvoke_IX_GL1_caselist \

#define maExtensionFunctionInvoke_IX_GL1_syscall_caselist \

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
#define maIOCtl_IX_GL1_caselist \
maIOCtl_glAlphaFunc_case(glAlphaFunc) \
maIOCtl_glClipPlanef_case(glClipPlanef) \
maIOCtl_glColor4f_case(glColor4f) \
maIOCtl_glFogf_case(glFogf) \
maIOCtl_glFogfv_case(glFogfv) \
maIOCtl_glFrustumf_case(glFrustumf) \
maIOCtl_glGetClipPlanef_case(glGetClipPlanef) \
maIOCtl_glGetLightfv_case(glGetLightfv) \
maIOCtl_glGetMaterialfv_case(glGetMaterialfv) \
maIOCtl_glGetTexEnvfv_case(glGetTexEnvfv) \
maIOCtl_glLightModelf_case(glLightModelf) \
maIOCtl_glLightModelfv_case(glLightModelfv) \
maIOCtl_glLightf_case(glLightf) \
maIOCtl_glLightfv_case(glLightfv) \
maIOCtl_glLoadMatrixf_case(glLoadMatrixf) \
maIOCtl_glMaterialf_case(glMaterialf) \
maIOCtl_glMaterialfv_case(glMaterialfv) \
maIOCtl_glMultMatrixf_case(glMultMatrixf) \
maIOCtl_glMultiTexCoord4f_case(glMultiTexCoord4f) \
maIOCtl_glNormal3f_case(glNormal3f) \
maIOCtl_glOrthof_case(glOrthof) \
maIOCtl_glPointParameterf_case(glPointParameterf) \
maIOCtl_glPointParameterfv_case(glPointParameterfv) \
maIOCtl_glPointSize_case(glPointSize) \
maIOCtl_glRotatef_case(glRotatef) \
maIOCtl_glScalef_case(glScalef) \
maIOCtl_glTexEnvf_case(glTexEnvf) \
maIOCtl_glTexEnvfv_case(glTexEnvfv) \
maIOCtl_glTranslatef_case(glTranslatef) \
maIOCtl_glAlphaFuncx_case(glAlphaFuncx) \
maIOCtl_glClearColorx_case(glClearColorx) \
maIOCtl_glClearDepthx_case(glClearDepthx) \
maIOCtl_glClientActiveTexture_case(glClientActiveTexture) \
maIOCtl_glClipPlanex_case(glClipPlanex) \
maIOCtl_glColor4ub_case(glColor4ub) \
maIOCtl_glColor4x_case(glColor4x) \
maIOCtl_glColorPointer_case(glColorPointer) \
maIOCtl_glDepthRangex_case(glDepthRangex) \
maIOCtl_glDisableClientState_case(glDisableClientState) \
maIOCtl_glEnableClientState_case(glEnableClientState) \
maIOCtl_glFogx_case(glFogx) \
maIOCtl_glFogxv_case(glFogxv) \
maIOCtl_glFrustumx_case(glFrustumx) \
maIOCtl_glGetClipPlanex_case(glGetClipPlanex) \
maIOCtl_glGetFixedv_case(glGetFixedv) \
maIOCtl_glGetLightxv_case(glGetLightxv) \
maIOCtl_glGetMaterialxv_case(glGetMaterialxv) \
maIOCtl_glGetPointerv_case(glGetPointerv) \
maIOCtl_glGetTexEnviv_case(glGetTexEnviv) \
maIOCtl_glGetTexEnvxv_case(glGetTexEnvxv) \
maIOCtl_glGetTexParameterxv_case(glGetTexParameterxv) \
maIOCtl_glLightModelx_case(glLightModelx) \
maIOCtl_glLightModelxv_case(glLightModelxv) \
maIOCtl_glLightx_case(glLightx) \
maIOCtl_glLightxv_case(glLightxv) \
maIOCtl_glLineWidthx_case(glLineWidthx) \
maIOCtl_glLoadIdentity_case(glLoadIdentity) \
maIOCtl_glLoadMatrixx_case(glLoadMatrixx) \
maIOCtl_glLogicOp_case(glLogicOp) \
maIOCtl_glMaterialx_case(glMaterialx) \
maIOCtl_glMaterialxv_case(glMaterialxv) \
maIOCtl_glMatrixMode_case(glMatrixMode) \
maIOCtl_glMultMatrixx_case(glMultMatrixx) \
maIOCtl_glMultiTexCoord4x_case(glMultiTexCoord4x) \
maIOCtl_glNormal3x_case(glNormal3x) \
maIOCtl_glNormalPointer_case(glNormalPointer) \
maIOCtl_glOrthox_case(glOrthox) \
maIOCtl_glPointParameterx_case(glPointParameterx) \
maIOCtl_glPointParameterxv_case(glPointParameterxv) \
maIOCtl_glPointSizex_case(glPointSizex) \
maIOCtl_glPolygonOffsetx_case(glPolygonOffsetx) \
maIOCtl_glPopMatrix_case(glPopMatrix) \
maIOCtl_glPushMatrix_case(glPushMatrix) \
maIOCtl_glRotatex_case(glRotatex) \
maIOCtl_glSampleCoveragex_case(glSampleCoveragex) \
maIOCtl_glScalex_case(glScalex) \
maIOCtl_glShadeModel_case(glShadeModel) \
maIOCtl_glTexCoordPointer_case(glTexCoordPointer) \
maIOCtl_glTexEnvi_case(glTexEnvi) \
maIOCtl_glTexEnvx_case(glTexEnvx) \
maIOCtl_glTexEnviv_case(glTexEnviv) \
maIOCtl_glTexEnvxv_case(glTexEnvxv) \
maIOCtl_glTexParameterx_case(glTexParameterx) \
maIOCtl_glTexParameterxv_case(glTexParameterxv) \
maIOCtl_glTranslatex_case(glTranslatex) \
maIOCtl_glVertexPointer_case(glVertexPointer) \
maIOCtl_glPointSizePointerOES_case(glPointSizePointerOES) \

#define maIOCtl_IX_GL1_syscall_caselist \
maIOCtl_syscall_case(glAlphaFunc) \
maIOCtl_syscall_case(glClipPlanef) \
maIOCtl_syscall_case(glColor4f) \
maIOCtl_syscall_case(glFogf) \
maIOCtl_syscall_case(glFogfv) \
maIOCtl_syscall_case(glFrustumf) \
maIOCtl_syscall_case(glGetClipPlanef) \
maIOCtl_syscall_case(glGetLightfv) \
maIOCtl_syscall_case(glGetMaterialfv) \
maIOCtl_syscall_case(glGetTexEnvfv) \
maIOCtl_syscall_case(glLightModelf) \
maIOCtl_syscall_case(glLightModelfv) \
maIOCtl_syscall_case(glLightf) \
maIOCtl_syscall_case(glLightfv) \
maIOCtl_syscall_case(glLoadMatrixf) \
maIOCtl_syscall_case(glMaterialf) \
maIOCtl_syscall_case(glMaterialfv) \
maIOCtl_syscall_case(glMultMatrixf) \
maIOCtl_syscall_case(glMultiTexCoord4f) \
maIOCtl_syscall_case(glNormal3f) \
maIOCtl_syscall_case(glOrthof) \
maIOCtl_syscall_case(glPointParameterf) \
maIOCtl_syscall_case(glPointParameterfv) \
maIOCtl_syscall_case(glPointSize) \
maIOCtl_syscall_case(glRotatef) \
maIOCtl_syscall_case(glScalef) \
maIOCtl_syscall_case(glTexEnvf) \
maIOCtl_syscall_case(glTexEnvfv) \
maIOCtl_syscall_case(glTranslatef) \
maIOCtl_syscall_case(glAlphaFuncx) \
maIOCtl_syscall_case(glClearColorx) \
maIOCtl_syscall_case(glClearDepthx) \
maIOCtl_syscall_case(glClientActiveTexture) \
maIOCtl_syscall_case(glClipPlanex) \
maIOCtl_syscall_case(glColor4ub) \
maIOCtl_syscall_case(glColor4x) \
maIOCtl_syscall_case(glColorPointer) \
maIOCtl_syscall_case(glDepthRangex) \
maIOCtl_syscall_case(glDisableClientState) \
maIOCtl_syscall_case(glEnableClientState) \
maIOCtl_syscall_case(glFogx) \
maIOCtl_syscall_case(glFogxv) \
maIOCtl_syscall_case(glFrustumx) \
maIOCtl_syscall_case(glGetClipPlanex) \
maIOCtl_syscall_case(glGetFixedv) \
maIOCtl_syscall_case(glGetLightxv) \
maIOCtl_syscall_case(glGetMaterialxv) \
maIOCtl_syscall_case(glGetPointerv) \
maIOCtl_syscall_case(glGetTexEnviv) \
maIOCtl_syscall_case(glGetTexEnvxv) \
maIOCtl_syscall_case(glGetTexParameterxv) \
maIOCtl_syscall_case(glLightModelx) \
maIOCtl_syscall_case(glLightModelxv) \
maIOCtl_syscall_case(glLightx) \
maIOCtl_syscall_case(glLightxv) \
maIOCtl_syscall_case(glLineWidthx) \
maIOCtl_syscall_case(glLoadIdentity) \
maIOCtl_syscall_case(glLoadMatrixx) \
maIOCtl_syscall_case(glLogicOp) \
maIOCtl_syscall_case(glMaterialx) \
maIOCtl_syscall_case(glMaterialxv) \
maIOCtl_syscall_case(glMatrixMode) \
maIOCtl_syscall_case(glMultMatrixx) \
maIOCtl_syscall_case(glMultiTexCoord4x) \
maIOCtl_syscall_case(glNormal3x) \
maIOCtl_syscall_case(glNormalPointer) \
maIOCtl_syscall_case(glOrthox) \
maIOCtl_syscall_case(glPointParameterx) \
maIOCtl_syscall_case(glPointParameterxv) \
maIOCtl_syscall_case(glPointSizex) \
maIOCtl_syscall_case(glPolygonOffsetx) \
maIOCtl_syscall_case(glPopMatrix) \
maIOCtl_syscall_case(glPushMatrix) \
maIOCtl_syscall_case(glRotatex) \
maIOCtl_syscall_case(glSampleCoveragex) \
maIOCtl_syscall_case(glScalex) \
maIOCtl_syscall_case(glShadeModel) \
maIOCtl_syscall_case(glTexCoordPointer) \
maIOCtl_syscall_case(glTexEnvi) \
maIOCtl_syscall_case(glTexEnvx) \
maIOCtl_syscall_case(glTexEnviv) \
maIOCtl_syscall_case(glTexEnvxv) \
maIOCtl_syscall_case(glTexParameterx) \
maIOCtl_syscall_case(glTexParameterxv) \
maIOCtl_syscall_case(glTranslatex) \
maIOCtl_syscall_case(glVertexPointer) \
maIOCtl_syscall_case(glPointSizePointerOES) \

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
#define maIOCtl_glAlphaFunc 322
#define maIOCtl_glAlphaFunc_case(func) \
case 322: \
{ \
GLenum _func = (GLenum)a; \
MA_FV _ref_dv; \
_ref_dv.i = b; \
GLclampf _ref = _ref_dv.f; \
func(_func, _ref); \
return 0; \
} \

#define maIOCtl_glClipPlanef 323
#define maIOCtl_glClipPlanef_case(func) \
case 323: \
{ \
GLenum _plane = (GLenum)a; \
const GLfloat* _equation = GVMR(b, GLfloat); \
func(_plane, _equation); \
return 0; \
} \

#define maIOCtl_glColor4f 324
#define maIOCtl_glColor4f_case(func) \
case 324: \
{ \
MA_FV _red_dv; \
_red_dv.i = a; \
GLfloat _red = _red_dv.f; \
MA_FV _green_dv; \
_green_dv.i = b; \
GLfloat _green = _green_dv.f; \
MA_FV _blue_dv; \
_blue_dv.i = c; \
GLfloat _blue = _blue_dv.f; \
MA_FV _alpha_dv; \
_alpha_dv.i = ARG_NO_4; \
GLfloat _alpha = _alpha_dv.f; \
func(_red, _green, _blue, _alpha); \
return 0; \
} \

#define maIOCtl_glFogf 325
#define maIOCtl_glFogf_case(func) \
case 325: \
{ \
GLenum _pname = (GLenum)a; \
MA_FV _param_dv; \
_param_dv.i = b; \
GLfloat _param = _param_dv.f; \
func(_pname, _param); \
return 0; \
} \

#define maIOCtl_glFogfv 326
#define maIOCtl_glFogfv_case(func) \
case 326: \
{ \
GLenum _pname = (GLenum)a; \
const GLfloat* _params = GVMR(b, GLfloat); \
func(_pname, _params); \
return 0; \
} \

#define maIOCtl_glFrustumf 327
#define maIOCtl_glFrustumf_case(func) \
case 327: \
{ \
MA_FV _left_dv; \
_left_dv.i = a; \
GLfloat _left = _left_dv.f; \
MA_FV _right_dv; \
_right_dv.i = b; \
GLfloat _right = _right_dv.f; \
MA_FV _bottom_dv; \
_bottom_dv.i = c; \
GLfloat _bottom = _bottom_dv.f; \
MA_FV _top_dv; \
_top_dv.i = ARG_NO_4; \
GLfloat _top = _top_dv.f; \
MA_FV _zNear_dv; \
_zNear_dv.i = ARG_NO_5; \
GLfloat _zNear = _zNear_dv.f; \
MA_FV _zFar_dv; \
_zFar_dv.i = ARG_NO_6; \
GLfloat _zFar = _zFar_dv.f; \
func(_left, _right, _bottom, _top, _zNear, _zFar); \
return 0; \
} \

#define maIOCtl_glGetClipPlanef 328
#define maIOCtl_glGetClipPlanef_case(func) \
case 328: \
{ \
GLenum _pname = (GLenum)a; \
GLfloat* _eqn = GVMR(b, GLfloat); \
func(_pname, _eqn); \
return 0; \
} \

#define maIOCtl_glGetLightfv 329
#define maIOCtl_glGetLightfv_case(func) \
case 329: \
{ \
GLenum _light = (GLenum)a; \
GLenum _pname = (GLenum)b; \
GLfloat* _params = GVMR(c, GLfloat); \
func(_light, _pname, _params); \
return 0; \
} \

#define maIOCtl_glGetMaterialfv 330
#define maIOCtl_glGetMaterialfv_case(func) \
case 330: \
{ \
GLenum _face = (GLenum)a; \
GLenum _pname = (GLenum)b; \
GLfloat* _params = GVMR(c, GLfloat); \
func(_face, _pname, _params); \
return 0; \
} \

#define maIOCtl_glGetTexEnvfv 331
#define maIOCtl_glGetTexEnvfv_case(func) \
case 331: \
{ \
GLenum _env = (GLenum)a; \
GLenum _pname = (GLenum)b; \
GLfloat* _params = GVMR(c, GLfloat); \
func(_env, _pname, _params); \
return 0; \
} \

#define maIOCtl_glLightModelf 332
#define maIOCtl_glLightModelf_case(func) \
case 332: \
{ \
GLenum _pname = (GLenum)a; \
MA_FV _param_dv; \
_param_dv.i = b; \
GLfloat _param = _param_dv.f; \
func(_pname, _param); \
return 0; \
} \

#define maIOCtl_glLightModelfv 333
#define maIOCtl_glLightModelfv_case(func) \
case 333: \
{ \
GLenum _pname = (GLenum)a; \
const GLfloat* _params = GVMR(b, GLfloat); \
func(_pname, _params); \
return 0; \
} \

#define maIOCtl_glLightf 334
#define maIOCtl_glLightf_case(func) \
case 334: \
{ \
GLenum _light = (GLenum)a; \
GLenum _pname = (GLenum)b; \
MA_FV _param_dv; \
_param_dv.i = c; \
GLfloat _param = _param_dv.f; \
func(_light, _pname, _param); \
return 0; \
} \

#define maIOCtl_glLightfv 335
#define maIOCtl_glLightfv_case(func) \
case 335: \
{ \
GLenum _light = (GLenum)a; \
GLenum _pname = (GLenum)b; \
const GLfloat* _params = GVMR(c, GLfloat); \
func(_light, _pname, _params); \
return 0; \
} \

#define maIOCtl_glLoadMatrixf 336
#define maIOCtl_glLoadMatrixf_case(func) \
case 336: \
{ \
const GLfloat* _m = GVMR(a, GLfloat); \
func(_m); \
return 0; \
} \

#define maIOCtl_glMaterialf 337
#define maIOCtl_glMaterialf_case(func) \
case 337: \
{ \
GLenum _face = (GLenum)a; \
GLenum _pname = (GLenum)b; \
MA_FV _param_dv; \
_param_dv.i = c; \
GLfloat _param = _param_dv.f; \
func(_face, _pname, _param); \
return 0; \
} \

#define maIOCtl_glMaterialfv 338
#define maIOCtl_glMaterialfv_case(func) \
case 338: \
{ \
GLenum _face = (GLenum)a; \
GLenum _pname = (GLenum)b; \
const GLfloat* _params = GVMR(c, GLfloat); \
func(_face, _pname, _params); \
return 0; \
} \

#define maIOCtl_glMultMatrixf 339
#define maIOCtl_glMultMatrixf_case(func) \
case 339: \
{ \
const GLfloat* _m = GVMR(a, GLfloat); \
func(_m); \
return 0; \
} \

#define maIOCtl_glMultiTexCoord4f 340
#define maIOCtl_glMultiTexCoord4f_case(func) \
case 340: \
{ \
GLenum _target = (GLenum)a; \
MA_FV _s_dv; \
_s_dv.i = b; \
GLfloat _s = _s_dv.f; \
MA_FV _t_dv; \
_t_dv.i = c; \
GLfloat _t = _t_dv.f; \
MA_FV _r_dv; \
_r_dv.i = ARG_NO_4; \
GLfloat _r = _r_dv.f; \
MA_FV _q_dv; \
_q_dv.i = ARG_NO_5; \
GLfloat _q = _q_dv.f; \
func(_target, _s, _t, _r, _q); \
return 0; \
} \

#define maIOCtl_glNormal3f 341
#define maIOCtl_glNormal3f_case(func) \
case 341: \
{ \
MA_FV _nx_dv; \
_nx_dv.i = a; \
GLfloat _nx = _nx_dv.f; \
MA_FV _ny_dv; \
_ny_dv.i = b; \
GLfloat _ny = _ny_dv.f; \
MA_FV _nz_dv; \
_nz_dv.i = c; \
GLfloat _nz = _nz_dv.f; \
func(_nx, _ny, _nz); \
return 0; \
} \

#define maIOCtl_glOrthof 342
#define maIOCtl_glOrthof_case(func) \
case 342: \
{ \
MA_FV _left_dv; \
_left_dv.i = a; \
GLfloat _left = _left_dv.f; \
MA_FV _right_dv; \
_right_dv.i = b; \
GLfloat _right = _right_dv.f; \
MA_FV _bottom_dv; \
_bottom_dv.i = c; \
GLfloat _bottom = _bottom_dv.f; \
MA_FV _top_dv; \
_top_dv.i = ARG_NO_4; \
GLfloat _top = _top_dv.f; \
MA_FV _zNear_dv; \
_zNear_dv.i = ARG_NO_5; \
GLfloat _zNear = _zNear_dv.f; \
MA_FV _zFar_dv; \
_zFar_dv.i = ARG_NO_6; \
GLfloat _zFar = _zFar_dv.f; \
func(_left, _right, _bottom, _top, _zNear, _zFar); \
return 0; \
} \

#define maIOCtl_glPointParameterf 343
#define maIOCtl_glPointParameterf_case(func) \
case 343: \
{ \
GLenum _pname = (GLenum)a; \
MA_FV _param_dv; \
_param_dv.i = b; \
GLfloat _param = _param_dv.f; \
func(_pname, _param); \
return 0; \
} \

#define maIOCtl_glPointParameterfv 344
#define maIOCtl_glPointParameterfv_case(func) \
case 344: \
{ \
GLenum _pname = (GLenum)a; \
const GLfloat* _params = GVMR(b, GLfloat); \
func(_pname, _params); \
return 0; \
} \

#define maIOCtl_glPointSize 345
#define maIOCtl_glPointSize_case(func) \
case 345: \
{ \
MA_FV _size_dv; \
_size_dv.i = a; \
GLfloat _size = _size_dv.f; \
func(_size); \
return 0; \
} \

#define maIOCtl_glRotatef 346
#define maIOCtl_glRotatef_case(func) \
case 346: \
{ \
MA_FV _angle_dv; \
_angle_dv.i = a; \
GLfloat _angle = _angle_dv.f; \
MA_FV _x_dv; \
_x_dv.i = b; \
GLfloat _x = _x_dv.f; \
MA_FV _y_dv; \
_y_dv.i = c; \
GLfloat _y = _y_dv.f; \
MA_FV _z_dv; \
_z_dv.i = ARG_NO_4; \
GLfloat _z = _z_dv.f; \
func(_angle, _x, _y, _z); \
return 0; \
} \

#define maIOCtl_glScalef 347
#define maIOCtl_glScalef_case(func) \
case 347: \
{ \
MA_FV _x_dv; \
_x_dv.i = a; \
GLfloat _x = _x_dv.f; \
MA_FV _y_dv; \
_y_dv.i = b; \
GLfloat _y = _y_dv.f; \
MA_FV _z_dv; \
_z_dv.i = c; \
GLfloat _z = _z_dv.f; \
func(_x, _y, _z); \
return 0; \
} \

#define maIOCtl_glTexEnvf 348
#define maIOCtl_glTexEnvf_case(func) \
case 348: \
{ \
GLenum _target = (GLenum)a; \
GLenum _pname = (GLenum)b; \
MA_FV _param_dv; \
_param_dv.i = c; \
GLfloat _param = _param_dv.f; \
func(_target, _pname, _param); \
return 0; \
} \

#define maIOCtl_glTexEnvfv 349
#define maIOCtl_glTexEnvfv_case(func) \
case 349: \
{ \
GLenum _target = (GLenum)a; \
GLenum _pname = (GLenum)b; \
const GLfloat* _params = GVMR(c, GLfloat); \
func(_target, _pname, _params); \
return 0; \
} \

#define maIOCtl_glTranslatef 350
#define maIOCtl_glTranslatef_case(func) \
case 350: \
{ \
MA_FV _x_dv; \
_x_dv.i = a; \
GLfloat _x = _x_dv.f; \
MA_FV _y_dv; \
_y_dv.i = b; \
GLfloat _y = _y_dv.f; \
MA_FV _z_dv; \
_z_dv.i = c; \
GLfloat _z = _z_dv.f; \
func(_x, _y, _z); \
return 0; \
} \

#define maIOCtl_glAlphaFuncx 351
#define maIOCtl_glAlphaFuncx_case(func) \
case 351: \
{ \
GLenum _func = (GLenum)a; \
GLclampx _ref = (GLclampx)b; \
func(_func, _ref); \
return 0; \
} \

#define maIOCtl_glClearColorx 352
#define maIOCtl_glClearColorx_case(func) \
case 352: \
{ \
GLclampx _red = (GLclampx)a; \
GLclampx _green = (GLclampx)b; \
GLclampx _blue = (GLclampx)c; \
GLclampx _alpha = (GLclampx)ARG_NO_4; \
func(_red, _green, _blue, _alpha); \
return 0; \
} \

#define maIOCtl_glClearDepthx 353
#define maIOCtl_glClearDepthx_case(func) \
case 353: \
{ \
GLclampx _depth = (GLclampx)a; \
func(_depth); \
return 0; \
} \

#define maIOCtl_glClientActiveTexture 354
#define maIOCtl_glClientActiveTexture_case(func) \
case 354: \
{ \
GLenum _texture = (GLenum)a; \
func(_texture); \
return 0; \
} \

#define maIOCtl_glClipPlanex 355
#define maIOCtl_glClipPlanex_case(func) \
case 355: \
{ \
GLenum _plane = (GLenum)a; \
const GLfixed* _equation = GVMR(b, GLfixed); \
func(_plane, _equation); \
return 0; \
} \

#define maIOCtl_glColor4ub 356
#define maIOCtl_glColor4ub_case(func) \
case 356: \
{ \
GLubyte _red = (GLubyte)a; \
GLubyte _green = (GLubyte)b; \
GLubyte _blue = (GLubyte)c; \
GLubyte _alpha = (GLubyte)ARG_NO_4; \
func(_red, _green, _blue, _alpha); \
return 0; \
} \

#define maIOCtl_glColor4x 357
#define maIOCtl_glColor4x_case(func) \
case 357: \
{ \
GLfixed _red = (GLfixed)a; \
GLfixed _green = (GLfixed)b; \
GLfixed _blue = (GLfixed)c; \
GLfixed _alpha = (GLfixed)ARG_NO_4; \
func(_red, _green, _blue, _alpha); \
return 0; \
} \

#define maIOCtl_glColorPointer 358
#define maIOCtl_glColorPointer_case(func) \
case 358: \
{ \
GLint _size = (GLint)a; \
GLenum _type = (GLenum)b; \
GLsizei _stride = (GLsizei)c; \
const void* _pointer = GVMR(ARG_NO_4, MAAddress); \
func(_size, _type, _stride, _pointer); \
return 0; \
} \

#define maIOCtl_glDepthRangex 359
#define maIOCtl_glDepthRangex_case(func) \
case 359: \
{ \
GLclampx _zNear = (GLclampx)a; \
GLclampx _zFar = (GLclampx)b; \
func(_zNear, _zFar); \
return 0; \
} \

#define maIOCtl_glDisableClientState 360
#define maIOCtl_glDisableClientState_case(func) \
case 360: \
{ \
GLenum _array = (GLenum)a; \
func(_array); \
return 0; \
} \

#define maIOCtl_glEnableClientState 361
#define maIOCtl_glEnableClientState_case(func) \
case 361: \
{ \
GLenum _array = (GLenum)a; \
func(_array); \
return 0; \
} \

#define maIOCtl_glFogx 362
#define maIOCtl_glFogx_case(func) \
case 362: \
{ \
GLenum _pname = (GLenum)a; \
GLfixed _param = (GLfixed)b; \
func(_pname, _param); \
return 0; \
} \

#define maIOCtl_glFogxv 363
#define maIOCtl_glFogxv_case(func) \
case 363: \
{ \
GLenum _pname = (GLenum)a; \
const GLfixed* _params = GVMR(b, GLfixed); \
func(_pname, _params); \
return 0; \
} \

#define maIOCtl_glFrustumx 364
#define maIOCtl_glFrustumx_case(func) \
case 364: \
{ \
GLfixed _left = (GLfixed)a; \
GLfixed _right = (GLfixed)b; \
GLfixed _bottom = (GLfixed)c; \
GLfixed _top = (GLfixed)ARG_NO_4; \
GLfixed _zNear = (GLfixed)ARG_NO_5; \
GLfixed _zFar = (GLfixed)ARG_NO_6; \
func(_left, _right, _bottom, _top, _zNear, _zFar); \
return 0; \
} \

#define maIOCtl_glGetClipPlanex 365
#define maIOCtl_glGetClipPlanex_case(func) \
case 365: \
{ \
GLenum _pname = (GLenum)a; \
GLfixed* _eqn = GVMR(b, GLfixed); \
func(_pname, _eqn); \
return 0; \
} \

#define maIOCtl_glGetFixedv 366
#define maIOCtl_glGetFixedv_case(func) \
case 366: \
{ \
GLenum _pname = (GLenum)a; \
GLfixed* _params = GVMR(b, GLfixed); \
func(_pname, _params); \
return 0; \
} \

#define maIOCtl_glGetLightxv 367
#define maIOCtl_glGetLightxv_case(func) \
case 367: \
{ \
GLenum _light = (GLenum)a; \
GLenum _pname = (GLenum)b; \
GLfixed* _params = GVMR(c, GLfixed); \
func(_light, _pname, _params); \
return 0; \
} \

#define maIOCtl_glGetMaterialxv 368
#define maIOCtl_glGetMaterialxv_case(func) \
case 368: \
{ \
GLenum _face = (GLenum)a; \
GLenum _pname = (GLenum)b; \
GLfixed* _params = GVMR(c, GLfixed); \
func(_face, _pname, _params); \
return 0; \
} \

#define maIOCtl_glGetPointerv 369
#define maIOCtl_glGetPointerv_case(func) \
case 369: \
{ \
GLenum _pname = (GLenum)a; \
void* _params = GVMR(b, MAAddress); \
func(_pname, _params); \
return 0; \
} \

#define maIOCtl_glGetTexEnviv 370
#define maIOCtl_glGetTexEnviv_case(func) \
case 370: \
{ \
GLenum _env = (GLenum)a; \
GLenum _pname = (GLenum)b; \
GLint* _params = GVMR(c, GLint); \
func(_env, _pname, _params); \
return 0; \
} \

#define maIOCtl_glGetTexEnvxv 371
#define maIOCtl_glGetTexEnvxv_case(func) \
case 371: \
{ \
GLenum _env = (GLenum)a; \
GLenum _pname = (GLenum)b; \
GLfixed* _params = GVMR(c, GLfixed); \
func(_env, _pname, _params); \
return 0; \
} \

#define maIOCtl_glGetTexParameterxv 372
#define maIOCtl_glGetTexParameterxv_case(func) \
case 372: \
{ \
GLenum _target = (GLenum)a; \
GLenum _pname = (GLenum)b; \
GLfixed* _params = GVMR(c, GLfixed); \
func(_target, _pname, _params); \
return 0; \
} \

#define maIOCtl_glLightModelx 373
#define maIOCtl_glLightModelx_case(func) \
case 373: \
{ \
GLenum _pname = (GLenum)a; \
GLfixed _param = (GLfixed)b; \
func(_pname, _param); \
return 0; \
} \

#define maIOCtl_glLightModelxv 374
#define maIOCtl_glLightModelxv_case(func) \
case 374: \
{ \
GLenum _pname = (GLenum)a; \
const GLfixed* _params = GVMR(b, GLfixed); \
func(_pname, _params); \
return 0; \
} \

#define maIOCtl_glLightx 375
#define maIOCtl_glLightx_case(func) \
case 375: \
{ \
GLenum _light = (GLenum)a; \
GLenum _pname = (GLenum)b; \
GLfixed _param = (GLfixed)c; \
func(_light, _pname, _param); \
return 0; \
} \

#define maIOCtl_glLightxv 376
#define maIOCtl_glLightxv_case(func) \
case 376: \
{ \
GLenum _light = (GLenum)a; \
GLenum _pname = (GLenum)b; \
const GLfixed* _params = GVMR(c, GLfixed); \
func(_light, _pname, _params); \
return 0; \
} \

#define maIOCtl_glLineWidthx 377
#define maIOCtl_glLineWidthx_case(func) \
case 377: \
{ \
GLfixed _width = (GLfixed)a; \
func(_width); \
return 0; \
} \

#define maIOCtl_glLoadIdentity 378
#define maIOCtl_glLoadIdentity_case(func) \
case 378: \
{ \
func(); \
return 0; \
} \

#define maIOCtl_glLoadMatrixx 379
#define maIOCtl_glLoadMatrixx_case(func) \
case 379: \
{ \
const GLfixed* _m = GVMR(a, GLfixed); \
func(_m); \
return 0; \
} \

#define maIOCtl_glLogicOp 380
#define maIOCtl_glLogicOp_case(func) \
case 380: \
{ \
GLenum _opcode = (GLenum)a; \
func(_opcode); \
return 0; \
} \

#define maIOCtl_glMaterialx 381
#define maIOCtl_glMaterialx_case(func) \
case 381: \
{ \
GLenum _face = (GLenum)a; \
GLenum _pname = (GLenum)b; \
GLfixed _param = (GLfixed)c; \
func(_face, _pname, _param); \
return 0; \
} \

#define maIOCtl_glMaterialxv 382
#define maIOCtl_glMaterialxv_case(func) \
case 382: \
{ \
GLenum _face = (GLenum)a; \
GLenum _pname = (GLenum)b; \
const GLfixed* _params = GVMR(c, GLfixed); \
func(_face, _pname, _params); \
return 0; \
} \

#define maIOCtl_glMatrixMode 383
#define maIOCtl_glMatrixMode_case(func) \
case 383: \
{ \
GLenum _mode = (GLenum)a; \
func(_mode); \
return 0; \
} \

#define maIOCtl_glMultMatrixx 384
#define maIOCtl_glMultMatrixx_case(func) \
case 384: \
{ \
const GLfixed* _m = GVMR(a, GLfixed); \
func(_m); \
return 0; \
} \

#define maIOCtl_glMultiTexCoord4x 385
#define maIOCtl_glMultiTexCoord4x_case(func) \
case 385: \
{ \
GLenum _target = (GLenum)a; \
GLfixed _s = (GLfixed)b; \
GLfixed _t = (GLfixed)c; \
GLfixed _r = (GLfixed)ARG_NO_4; \
GLfixed _q = (GLfixed)ARG_NO_5; \
func(_target, _s, _t, _r, _q); \
return 0; \
} \

#define maIOCtl_glNormal3x 386
#define maIOCtl_glNormal3x_case(func) \
case 386: \
{ \
GLfixed _nx = (GLfixed)a; \
GLfixed _ny = (GLfixed)b; \
GLfixed _nz = (GLfixed)c; \
func(_nx, _ny, _nz); \
return 0; \
} \

#define maIOCtl_glNormalPointer 387
#define maIOCtl_glNormalPointer_case(func) \
case 387: \
{ \
GLenum _type = (GLenum)a; \
GLsizei _stride = (GLsizei)b; \
const void* _pointer = GVMR(c, MAAddress); \
func(_type, _stride, _pointer); \
return 0; \
} \

#define maIOCtl_glOrthox 388
#define maIOCtl_glOrthox_case(func) \
case 388: \
{ \
GLfixed _left = (GLfixed)a; \
GLfixed _right = (GLfixed)b; \
GLfixed _bottom = (GLfixed)c; \
GLfixed _top = (GLfixed)ARG_NO_4; \
GLfixed _zNear = (GLfixed)ARG_NO_5; \
GLfixed _zFar = (GLfixed)ARG_NO_6; \
func(_left, _right, _bottom, _top, _zNear, _zFar); \
return 0; \
} \

#define maIOCtl_glPointParameterx 389
#define maIOCtl_glPointParameterx_case(func) \
case 389: \
{ \
GLenum _pname = (GLenum)a; \
GLfixed _param = (GLfixed)b; \
func(_pname, _param); \
return 0; \
} \

#define maIOCtl_glPointParameterxv 390
#define maIOCtl_glPointParameterxv_case(func) \
case 390: \
{ \
GLenum _pname = (GLenum)a; \
const GLfixed* _params = GVMR(b, GLfixed); \
func(_pname, _params); \
return 0; \
} \

#define maIOCtl_glPointSizex 391
#define maIOCtl_glPointSizex_case(func) \
case 391: \
{ \
GLfixed _size = (GLfixed)a; \
func(_size); \
return 0; \
} \

#define maIOCtl_glPolygonOffsetx 392
#define maIOCtl_glPolygonOffsetx_case(func) \
case 392: \
{ \
GLfixed _factor = (GLfixed)a; \
GLfixed _units = (GLfixed)b; \
func(_factor, _units); \
return 0; \
} \

#define maIOCtl_glPopMatrix 393
#define maIOCtl_glPopMatrix_case(func) \
case 393: \
{ \
func(); \
return 0; \
} \

#define maIOCtl_glPushMatrix 394
#define maIOCtl_glPushMatrix_case(func) \
case 394: \
{ \
func(); \
return 0; \
} \

#define maIOCtl_glRotatex 395
#define maIOCtl_glRotatex_case(func) \
case 395: \
{ \
GLfixed _angle = (GLfixed)a; \
GLfixed _x = (GLfixed)b; \
GLfixed _y = (GLfixed)c; \
GLfixed _z = (GLfixed)ARG_NO_4; \
func(_angle, _x, _y, _z); \
return 0; \
} \

#define maIOCtl_glSampleCoveragex 396
#define maIOCtl_glSampleCoveragex_case(func) \
case 396: \
{ \
GLclampx _value = (GLclampx)a; \
GLboolean _invert = (GLboolean)b; \
func(_value, _invert); \
return 0; \
} \

#define maIOCtl_glScalex 397
#define maIOCtl_glScalex_case(func) \
case 397: \
{ \
GLfixed _x = (GLfixed)a; \
GLfixed _y = (GLfixed)b; \
GLfixed _z = (GLfixed)c; \
func(_x, _y, _z); \
return 0; \
} \

#define maIOCtl_glShadeModel 398
#define maIOCtl_glShadeModel_case(func) \
case 398: \
{ \
GLenum _mode = (GLenum)a; \
func(_mode); \
return 0; \
} \

#define maIOCtl_glTexCoordPointer 399
#define maIOCtl_glTexCoordPointer_case(func) \
case 399: \
{ \
GLint _size = (GLint)a; \
GLenum _type = (GLenum)b; \
GLsizei _stride = (GLsizei)c; \
const void* _pointer = GVMR(ARG_NO_4, MAAddress); \
func(_size, _type, _stride, _pointer); \
return 0; \
} \

#define maIOCtl_glTexEnvi 400
#define maIOCtl_glTexEnvi_case(func) \
case 400: \
{ \
GLenum _target = (GLenum)a; \
GLenum _pname = (GLenum)b; \
GLint _param = (GLint)c; \
func(_target, _pname, _param); \
return 0; \
} \

#define maIOCtl_glTexEnvx 401
#define maIOCtl_glTexEnvx_case(func) \
case 401: \
{ \
GLenum _target = (GLenum)a; \
GLenum _pname = (GLenum)b; \
GLfixed _param = (GLfixed)c; \
func(_target, _pname, _param); \
return 0; \
} \

#define maIOCtl_glTexEnviv 402
#define maIOCtl_glTexEnviv_case(func) \
case 402: \
{ \
GLenum _target = (GLenum)a; \
GLenum _pname = (GLenum)b; \
const GLint* _params = GVMR(c, GLint); \
func(_target, _pname, _params); \
return 0; \
} \

#define maIOCtl_glTexEnvxv 403
#define maIOCtl_glTexEnvxv_case(func) \
case 403: \
{ \
GLenum _target = (GLenum)a; \
GLenum _pname = (GLenum)b; \
const GLfixed* _params = GVMR(c, GLfixed); \
func(_target, _pname, _params); \
return 0; \
} \

#define maIOCtl_glTexParameterx 404
#define maIOCtl_glTexParameterx_case(func) \
case 404: \
{ \
GLenum _target = (GLenum)a; \
GLenum _pname = (GLenum)b; \
GLfixed _param = (GLfixed)c; \
func(_target, _pname, _param); \
return 0; \
} \

#define maIOCtl_glTexParameterxv 405
#define maIOCtl_glTexParameterxv_case(func) \
case 405: \
{ \
GLenum _target = (GLenum)a; \
GLenum _pname = (GLenum)b; \
const GLfixed* _params = GVMR(c, GLfixed); \
func(_target, _pname, _params); \
return 0; \
} \

#define maIOCtl_glTranslatex 406
#define maIOCtl_glTranslatex_case(func) \
case 406: \
{ \
GLfixed _x = (GLfixed)a; \
GLfixed _y = (GLfixed)b; \
GLfixed _z = (GLfixed)c; \
func(_x, _y, _z); \
return 0; \
} \

#define maIOCtl_glVertexPointer 407
#define maIOCtl_glVertexPointer_case(func) \
case 407: \
{ \
GLint _size = (GLint)a; \
GLenum _type = (GLenum)b; \
GLsizei _stride = (GLsizei)c; \
const void* _pointer = GVMR(ARG_NO_4, MAAddress); \
func(_size, _type, _stride, _pointer); \
return 0; \
} \

#define maIOCtl_glPointSizePointerOES 408
#define maIOCtl_glPointSizePointerOES_case(func) \
case 408: \
{ \
GLenum _type = (GLenum)a; \
GLsizei _stride = (GLsizei)b; \
const void* _pointer = GVMR(c, MAAddress); \
func(_type, _stride, _pointer); \
return 0; \
} \


#endif	//IX_GL1_DEFS_H
