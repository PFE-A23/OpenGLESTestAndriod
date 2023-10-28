#include <jni.h>
#include <string>
#include <GLES2/gl2.h>

GLuint vertexShader;
GLuint fragmentShader;
GLuint programObject;

const char *vShaderStr = R"(
    attribute vec4 vPosition;
    void main()
    {
        gl_Position = vPosition;
    }
)";

const char *fShaderStr = R"(
    precision mediump float;
    void main()
    {
        gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);  // Rouge
    }
)";

extern "C" JNIEXPORT void JNICALL
Java_com_example_opengltest_1android_MainActivity_initOpenGL(JNIEnv* env, jobject /* this */) {
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vShaderStr, nullptr);
    glCompileShader(vertexShader);

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fShaderStr, nullptr);
    glCompileShader(fragmentShader);

    programObject = glCreateProgram();
    glAttachShader(programObject, vertexShader);
    glAttachShader(programObject, fragmentShader);
    glLinkProgram(programObject);
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_opengltest_1android_MainActivity_drawFrame(JNIEnv* env, jobject /* this */) {
    GLfloat vVertices[] = { 0.0f, 0.5f, 0.0f,
                            -0.5f, -0.5f, 0.0f,
                            0.5f, -0.5f, 0.0f };

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);  // Fond blanc
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(programObject);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vVertices);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
