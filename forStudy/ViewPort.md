# What is a Viewport?
* 뷰포트(Viewport): 그래픽스 렌더링에서 최종적으로 그림이 그려질 2D 화면상의 직사각형 영역

	- 쉽게 말해, 카메라로 찍은 3D 장면을 윈도우 창의 어느 위치에, 얼만한 크기로 표시할 것인지 정해주는 도화지의 구역

## 코드에서의 뷰포트 역할
```C++
// 1. 콜백 함수 정의
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height); // <--- 뷰포트 설정
}

// 2. 콜백 함수 등록 (main 함수 내부)
glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
```
* x, y: 뷰포트의 시작 위치 (윈도우 창의 왼쪽 아래 모서리 기준)
* width, height: 뷰포트의 가로, 세로 픽셀 크기

## 콜백 함수의 작동 원리
처음 창이 열릴 때, 또는 사용자가 마우스로 창의 모서리를 잡고 크기를 늘리거나 줄일 때마다 운영체제(OS)는 GLFW에게 창 크기가 변했다고 알려줍니다.

이때 등록해둔 framebuffer_size_callback 함수가 자동으로 실행(호출)됩니다.

바뀐 창의 width와 height 값을 받아 glViewport를 다시 호출하여, OpenGL이 그림을 그릴 영역을 새로운 창 크기에 맞게 업데이트합니다.

## glfwSetFramebufferSizeCallback의 함수 포인터 형
```C++
typedef void (* GLFWframebuffersizefun)(GLFWwindow*, int, int);
```
