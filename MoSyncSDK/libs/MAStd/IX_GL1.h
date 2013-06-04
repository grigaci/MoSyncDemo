#ifndef IX_GL1_H
#define IX_GL1_H

#ifdef __cplusplus
extern "C" {
#endif

/** @ingroup OpenGLES */
IOCTLDEF void glAlphaFunc(GLenum func, GLclampf ref) {
	MA_FV _ref;
	_ref.f = ref;
	(void) maIOCtl(322, func, _ref.i, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glClipPlanef(GLenum plane, const GLfloat* equation) {
	(void) maIOCtl(323, plane, (int)equation, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
	MA_FV _red;
	MA_FV _green;
	MA_FV _blue;
	MA_FV _alpha;
	_red.f = red;
	_green.f = green;
	_blue.f = blue;
	_alpha.f = alpha;
	(void) maIOCtl(324, _red.i, _green.i, _blue.i, _alpha.i);
}

/** @ingroup OpenGLES */
IOCTLDEF void glFogf(GLenum pname, GLfloat param) {
	MA_FV _param;
	_param.f = param;
	(void) maIOCtl(325, pname, _param.i, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glFogfv(GLenum pname, const GLfloat* params) {
	(void) maIOCtl(326, pname, (int)params, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glFrustumf(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar) {
	MA_FV _left;
	MA_FV _right;
	MA_FV _bottom;
	MA_FV _top;
	MA_FV _zNear;
	MA_FV _zFar;
	_left.f = left;
	_right.f = right;
	_bottom.f = bottom;
	_top.f = top;
	_zNear.f = zNear;
	_zFar.f = zFar;
	(void) maIOCtl(327, _left.i, _right.i, _bottom.i, _top.i, _zNear.i, _zFar.i);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetClipPlanef(GLenum pname, GLfloat* eqn) {
	(void) maIOCtl(328, pname, (int)eqn, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetLightfv(GLenum light, GLenum pname, GLfloat* params) {
	(void) maIOCtl(329, light, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetMaterialfv(GLenum face, GLenum pname, GLfloat* params) {
	(void) maIOCtl(330, face, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetTexEnvfv(GLenum env, GLenum pname, GLfloat* params) {
	(void) maIOCtl(331, env, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glLightModelf(GLenum pname, GLfloat param) {
	MA_FV _param;
	_param.f = param;
	(void) maIOCtl(332, pname, _param.i, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glLightModelfv(GLenum pname, const GLfloat* params) {
	(void) maIOCtl(333, pname, (int)params, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glLightf(GLenum light, GLenum pname, GLfloat param) {
	MA_FV _param;
	_param.f = param;
	(void) maIOCtl(334, light, pname, _param.i);
}

/** @ingroup OpenGLES */
IOCTLDEF void glLightfv(GLenum light, GLenum pname, const GLfloat* params) {
	(void) maIOCtl(335, light, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glLoadMatrixf(const GLfloat* m) {
	(void) maIOCtl(336, (int)m, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glMaterialf(GLenum face, GLenum pname, GLfloat param) {
	MA_FV _param;
	_param.f = param;
	(void) maIOCtl(337, face, pname, _param.i);
}

/** @ingroup OpenGLES */
IOCTLDEF void glMaterialfv(GLenum face, GLenum pname, const GLfloat* params) {
	(void) maIOCtl(338, face, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glMultMatrixf(const GLfloat* m) {
	(void) maIOCtl(339, (int)m, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
	MA_FV _s;
	MA_FV _t;
	MA_FV _r;
	MA_FV _q;
	_s.f = s;
	_t.f = t;
	_r.f = r;
	_q.f = q;
	(void) maIOCtl(340, target, _s.i, _t.i, _r.i, _q.i);
}

/** @ingroup OpenGLES */
IOCTLDEF void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) {
	MA_FV _nx;
	MA_FV _ny;
	MA_FV _nz;
	_nx.f = nx;
	_ny.f = ny;
	_nz.f = nz;
	(void) maIOCtl(341, _nx.i, _ny.i, _nz.i);
}

/** @ingroup OpenGLES */
IOCTLDEF void glOrthof(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar) {
	MA_FV _left;
	MA_FV _right;
	MA_FV _bottom;
	MA_FV _top;
	MA_FV _zNear;
	MA_FV _zFar;
	_left.f = left;
	_right.f = right;
	_bottom.f = bottom;
	_top.f = top;
	_zNear.f = zNear;
	_zFar.f = zFar;
	(void) maIOCtl(342, _left.i, _right.i, _bottom.i, _top.i, _zNear.i, _zFar.i);
}

/** @ingroup OpenGLES */
IOCTLDEF void glPointParameterf(GLenum pname, GLfloat param) {
	MA_FV _param;
	_param.f = param;
	(void) maIOCtl(343, pname, _param.i, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glPointParameterfv(GLenum pname, const GLfloat* params) {
	(void) maIOCtl(344, pname, (int)params, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glPointSize(GLfloat size) {
	MA_FV _size;
	_size.f = size;
	(void) maIOCtl(345, _size.i, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
	MA_FV _angle;
	MA_FV _x;
	MA_FV _y;
	MA_FV _z;
	_angle.f = angle;
	_x.f = x;
	_y.f = y;
	_z.f = z;
	(void) maIOCtl(346, _angle.i, _x.i, _y.i, _z.i);
}

/** @ingroup OpenGLES */
IOCTLDEF void glScalef(GLfloat x, GLfloat y, GLfloat z) {
	MA_FV _x;
	MA_FV _y;
	MA_FV _z;
	_x.f = x;
	_y.f = y;
	_z.f = z;
	(void) maIOCtl(347, _x.i, _y.i, _z.i);
}

/** @ingroup OpenGLES */
IOCTLDEF void glTexEnvf(GLenum target, GLenum pname, GLfloat param) {
	MA_FV _param;
	_param.f = param;
	(void) maIOCtl(348, target, pname, _param.i);
}

/** @ingroup OpenGLES */
IOCTLDEF void glTexEnvfv(GLenum target, GLenum pname, const GLfloat* params) {
	(void) maIOCtl(349, target, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glTranslatef(GLfloat x, GLfloat y, GLfloat z) {
	MA_FV _x;
	MA_FV _y;
	MA_FV _z;
	_x.f = x;
	_y.f = y;
	_z.f = z;
	(void) maIOCtl(350, _x.i, _y.i, _z.i);
}

/** @ingroup OpenGLES */
IOCTLDEF void glAlphaFuncx(GLenum func, GLclampx ref) {
	(void) maIOCtl(351, func, ref, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glClearColorx(GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha) {
	(void) maIOCtl(352, red, green, blue, alpha);
}

/** @ingroup OpenGLES */
IOCTLDEF void glClearDepthx(GLclampx depth) {
	(void) maIOCtl(353, depth, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glClientActiveTexture(GLenum texture) {
	(void) maIOCtl(354, texture, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glClipPlanex(GLenum plane, const GLfixed* equation) {
	(void) maIOCtl(355, plane, (int)equation, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) {
	(void) maIOCtl(356, red, green, blue, alpha);
}

/** @ingroup OpenGLES */
IOCTLDEF void glColor4x(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
	(void) maIOCtl(357, red, green, blue, alpha);
}

/** @ingroup OpenGLES */
IOCTLDEF void glColorPointer(GLint size, GLenum type, GLsizei stride, const void* pointer) {
	(void) maIOCtl(358, size, type, stride, (int)pointer);
}

/** @ingroup OpenGLES */
IOCTLDEF void glDepthRangex(GLclampx zNear, GLclampx zFar) {
	(void) maIOCtl(359, zNear, zFar, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glDisableClientState(GLenum array) {
	(void) maIOCtl(360, array, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glEnableClientState(GLenum array) {
	(void) maIOCtl(361, array, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glFogx(GLenum pname, GLfixed param) {
	(void) maIOCtl(362, pname, param, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glFogxv(GLenum pname, const GLfixed* params) {
	(void) maIOCtl(363, pname, (int)params, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glFrustumx(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed zNear, GLfixed zFar) {
	(void) maIOCtl(364, left, right, bottom, top, zNear, zFar);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetClipPlanex(GLenum pname, GLfixed* eqn) {
	(void) maIOCtl(365, pname, (int)eqn, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetFixedv(GLenum pname, GLfixed* params) {
	(void) maIOCtl(366, pname, (int)params, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetLightxv(GLenum light, GLenum pname, GLfixed* params) {
	(void) maIOCtl(367, light, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetMaterialxv(GLenum face, GLenum pname, GLfixed* params) {
	(void) maIOCtl(368, face, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetPointerv(GLenum pname, void* params) {
	(void) maIOCtl(369, pname, (int)params, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetTexEnviv(GLenum env, GLenum pname, GLint* params) {
	(void) maIOCtl(370, env, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetTexEnvxv(GLenum env, GLenum pname, GLfixed* params) {
	(void) maIOCtl(371, env, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetTexParameterxv(GLenum target, GLenum pname, GLfixed* params) {
	(void) maIOCtl(372, target, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glLightModelx(GLenum pname, GLfixed param) {
	(void) maIOCtl(373, pname, param, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glLightModelxv(GLenum pname, const GLfixed* params) {
	(void) maIOCtl(374, pname, (int)params, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glLightx(GLenum light, GLenum pname, GLfixed param) {
	(void) maIOCtl(375, light, pname, param);
}

/** @ingroup OpenGLES */
IOCTLDEF void glLightxv(GLenum light, GLenum pname, const GLfixed* params) {
	(void) maIOCtl(376, light, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glLineWidthx(GLfixed width) {
	(void) maIOCtl(377, width, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glLoadIdentity(void) {
	(void) maIOCtl(378, 0, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glLoadMatrixx(const GLfixed* m) {
	(void) maIOCtl(379, (int)m, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glLogicOp(GLenum opcode) {
	(void) maIOCtl(380, opcode, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glMaterialx(GLenum face, GLenum pname, GLfixed param) {
	(void) maIOCtl(381, face, pname, param);
}

/** @ingroup OpenGLES */
IOCTLDEF void glMaterialxv(GLenum face, GLenum pname, const GLfixed* params) {
	(void) maIOCtl(382, face, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glMatrixMode(GLenum mode) {
	(void) maIOCtl(383, mode, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glMultMatrixx(const GLfixed* m) {
	(void) maIOCtl(384, (int)m, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glMultiTexCoord4x(GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q) {
	(void) maIOCtl(385, target, s, t, r, q);
}

/** @ingroup OpenGLES */
IOCTLDEF void glNormal3x(GLfixed nx, GLfixed ny, GLfixed nz) {
	(void) maIOCtl(386, nx, ny, nz);
}

/** @ingroup OpenGLES */
IOCTLDEF void glNormalPointer(GLenum type, GLsizei stride, const void* pointer) {
	(void) maIOCtl(387, type, stride, (int)pointer);
}

/** @ingroup OpenGLES */
IOCTLDEF void glOrthox(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed zNear, GLfixed zFar) {
	(void) maIOCtl(388, left, right, bottom, top, zNear, zFar);
}

/** @ingroup OpenGLES */
IOCTLDEF void glPointParameterx(GLenum pname, GLfixed param) {
	(void) maIOCtl(389, pname, param, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glPointParameterxv(GLenum pname, const GLfixed* params) {
	(void) maIOCtl(390, pname, (int)params, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glPointSizex(GLfixed size) {
	(void) maIOCtl(391, size, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glPolygonOffsetx(GLfixed factor, GLfixed units) {
	(void) maIOCtl(392, factor, units, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glPopMatrix(void) {
	(void) maIOCtl(393, 0, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glPushMatrix(void) {
	(void) maIOCtl(394, 0, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glRotatex(GLfixed angle, GLfixed x, GLfixed y, GLfixed z) {
	(void) maIOCtl(395, angle, x, y, z);
}

/** @ingroup OpenGLES */
IOCTLDEF void glSampleCoveragex(GLclampx value, GLboolean invert) {
	(void) maIOCtl(396, value, invert, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glScalex(GLfixed x, GLfixed y, GLfixed z) {
	(void) maIOCtl(397, x, y, z);
}

/** @ingroup OpenGLES */
IOCTLDEF void glShadeModel(GLenum mode) {
	(void) maIOCtl(398, mode, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const void* pointer) {
	(void) maIOCtl(399, size, type, stride, (int)pointer);
}

/** @ingroup OpenGLES */
IOCTLDEF void glTexEnvi(GLenum target, GLenum pname, GLint param) {
	(void) maIOCtl(400, target, pname, param);
}

/** @ingroup OpenGLES */
IOCTLDEF void glTexEnvx(GLenum target, GLenum pname, GLfixed param) {
	(void) maIOCtl(401, target, pname, param);
}

/** @ingroup OpenGLES */
IOCTLDEF void glTexEnviv(GLenum target, GLenum pname, const GLint* params) {
	(void) maIOCtl(402, target, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glTexEnvxv(GLenum target, GLenum pname, const GLfixed* params) {
	(void) maIOCtl(403, target, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glTexParameterx(GLenum target, GLenum pname, GLfixed param) {
	(void) maIOCtl(404, target, pname, param);
}

/** @ingroup OpenGLES */
IOCTLDEF void glTexParameterxv(GLenum target, GLenum pname, const GLfixed* params) {
	(void) maIOCtl(405, target, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glTranslatex(GLfixed x, GLfixed y, GLfixed z) {
	(void) maIOCtl(406, x, y, z);
}

/** @ingroup OpenGLES */
IOCTLDEF void glVertexPointer(GLint size, GLenum type, GLsizei stride, const void* pointer) {
	(void) maIOCtl(407, size, type, stride, (int)pointer);
}

/** @ingroup OpenGLES */
IOCTLDEF void glPointSizePointerOES(GLenum type, GLsizei stride, const void* pointer) {
	(void) maIOCtl(408, type, stride, (int)pointer);
}

#ifdef __cplusplus
}
#endif

#endif	//IX_GL1_H
