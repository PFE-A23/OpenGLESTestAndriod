package com.example.opengltest_android

import android.content.Context
import android.opengl.GLSurfaceView
import javax.microedition.khronos.egl.EGLConfig
import javax.microedition.khronos.opengles.GL10

class MyGLSurfaceView(context: Context) : GLSurfaceView(context) {
    private val renderer: Renderer

    init {
        setEGLContextClientVersion(2)
        renderer = MyGLRenderer(context as MainActivity)
        setRenderer(renderer)
    }

    private inner class MyGLRenderer(private val activity: MainActivity) : Renderer {
        override fun onSurfaceCreated(unused: GL10, config: EGLConfig) {
            activity.initOpenGL()
        }

        override fun onDrawFrame(unused: GL10) {
            activity.drawFrame()
        }

        override fun onSurfaceChanged(unused: GL10, width: Int, height: Int) {
            android.opengl.GLES20.glViewport(0, 0, width, height)
        }
    }
}
