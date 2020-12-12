#include <glad/glad.h>
#include <iostream>
//inlcude GLFW yang terakhir ya
#include <GLFW/glfw3.h>


int main(void)
{
    // Deklarasi window
    GLFWwindow* window;

    /* inisialisasi library sekaligus di cek apakah library.nya bekerja/tidak */
    if (!glfwInit())
        return -1;

    /* Kita ingin menggunakan OpenGL versi 3.3 */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Buat mode window dengan kontek dari OPENGL */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    /* Sekedar mengecek apakah fungsi glfwCreateWindow bekerja, jika tidak sesi glfw di matikan */
    if (!window)
    {
        /* hentikan dan bersihkan GLFW */
        glfwTerminate();
        return -1;
    }

    /* Tetapkan konteks window saat ini dengan glfwMakeContextCurrent */
    glfwMakeContextCurrent(window);

    /* Cek Glad terpasang atau belum */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        fprintf(stderr, "Failed to initialize GLAD");
        return -1;
    }

    /* Buat perulangan yang akan berhenti sampai user mengeluarkan window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render window atau set area windows dengan masking yang memberbolehkan penulisan warna
        sekaligus untuk membersihkan warna yang didefinisikan oleh glClearColor()*/
        glClear(GL_COLOR_BUFFER_BIT);

        /* Tukar color buffer depan dan belakang */
        glfwSwapBuffers(window);

        /* ambil dan proses setiap event yang terjadi */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}