#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// 창 크기가 변경될 때 뷰포트 크기를 맞추는 콜백 함수: 뷰포트는 별도문서에 설명(ViewPort.md)
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    // GLFW 초기화 및 OpenGL 버전 설정 (3.3 Core Profile)
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // 윈도우 창 생성
    GLFWwindow* window = glfwCreateWindow(800, 600, "Physics Engine Testbed", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);//호출하는 스레드의 컨텍스트를 현재 윈도우의 컨텍스트로 설정
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);//윈도우 크기 변경시 콜백

    // GLAD 로드 (OpenGL 함수 포인터 초기화)
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // 메인 루프(각 단계의 구성 이유 별도문서에 설명, MainLoop.md)
    while (!glfwWindowShouldClose(window)) {
        // 1. 입력 처리 (ESC를 누르면 창 닫기)
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        // 2. 물리 엔진 업데이트 (추후 운동학 로직 추가 예정)

        // 3. 화면 지우기 (배경색 지정 및 버퍼 초기화)
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // 4. 그래픽스 렌더링 (추후 3D 큐브 드로우 로직 추가)

        // 5. 버퍼 스왑 및 이벤트 폴링
        glfwSwapBuffers(window);
        glfwPollEvents();//이벤트 큐에 있는 이벤트 처리
    }

    // 자원 해제 및 종료
    glfwTerminate();
    return 0;
}