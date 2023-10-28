package com.example.opengltest_android

import android.opengl.GLSurfaceView
import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {
    private lateinit var glSurfaceView: GLSurfaceView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        glSurfaceView = MyGLSurfaceView(this)
        setContentView(glSurfaceView)
    }

    external fun initOpenGL()
    external fun drawFrame()

    companion object {
        init {
            System.loadLibrary("opengltest_android")
        }
    }
}
