#include <glad/glad.h>
#include <iostream>
//inlcude GLFW yang terakhir ya
#include <GLFW/glfw3.h>

void framebuffer_size_callback(int width, int height);

void framebuffer_size_callback(int width, int height)
{
    glViewport(0,0,width, height);
}

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

    /* Agar ukuran objek dapat mengikuti window*/
    glfwSetFramebufferSizeCallback(window,(GLFWframebuffersizefun) framebuffer_size_callback);

    float vertices[] = {
        0.0f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    // kita butuh deklarasi unsigned int untuk diteruskan pada pemanggilan fungsi kemudian
    GLuint VBO;
    // bangkitkan buffers. kita butuh 1 id buffer.
    glGenBuffers(1, &VBO);
    // Kita pilih VBO buffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // Letakkan data vertices pada buffer. Mirip dengan fungsi memcpy di bahasa C.
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), vertices, GL_STATIC_DRAW); //atau
    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); 

    GLuint VAO;
    // bangkitkan array dari vertek. 
    glGenVertexArrays(1, &VAO);
    // Ikat/Bind VAO. 
    glBindVertexArray(VAO);

    // glVertexAttribPointer.
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (GLfloat)0, (GLvoid*)0);
    // berikan atribut vertek dengan nilai nilai default 0
    glEnableVertexAttribArray(0);

    /* vertex shader */
    const char* vertexShaderSource = "#version 330 core\n"
        "in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";

    /* buat dan compile vertex shader */
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    
    /* fragment shader */
    const char* fragmentShaderSource = "#version 330 core\n"
        "out vec4 fragColor;\n"
        "void main()\n"
        "{\n"
        " fragColor = vec4(1.0, 1.0, 0.0, 1.0);\n"
        "}\0";

    /* buat dan compile fragment shader */
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);


    /* Attach dan link shader, setelah itu delete*/
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);



    /* Buat perulangan yang akan berhenti sampai user mengeluarkan window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render window atau set area windows dengan masking yang memberbolehkan penulisan warna
        sekaligus untuk membersihkan warna yang didefinisikan oleh glClearColor()*/
        /* Beri warna background window merah */
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        /* Gunakan shader program, ikat VAO, gambar segitiga*/
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO); 
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Tukar color buffer depan dan belakang */
        glfwSwapBuffers(window);

        /* ambil dan proses setiap event yang terjadi */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}