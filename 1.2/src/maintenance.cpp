#include "maintenance.hpp"

uint makeModule(cstr filepath, uint moduleType) {
	std::ifstream file;
	std::stringstream bufferedLines;
	std::string line;

	file.open(filepath);
	while (std::getline(file, line))
		bufferedLines << line << '\n';
    
	std::string shaderSource = bufferedLines.str();
	cstr shaderSrc = shaderSource.c_str();
	bufferedLines.str("");
	file.close();

	uint shaderModule = glCreateShader(moduleType);
	glShaderSource(shaderModule, 1, &shaderSrc, NULL);
	glCompileShader(shaderModule);

	int success;
	glGetShaderiv(shaderModule, GL_COMPILE_STATUS, &success);

	if (!success) {
		char errorLog[1024];
		glGetShaderInfoLog(shaderModule, 1024, NULL, errorLog);
		std::cout << "Shader Module compilation error:\n" << errorLog << std::endl;
	}

	return shaderModule;
}

uint makeShader(cstr vertexFilepath, cstr fragmentFilepath) {
	std::vector<uint> modules;

	modules.push_back(makeModule(vertexFilepath, GL_VERTEX_SHADER));
	modules.push_back(makeModule(fragmentFilepath, GL_FRAGMENT_SHADER));

	uint shader = glCreateProgram();

	for (uint shaderModule : modules)
		glAttachShader(shader, shaderModule);
    
	glLinkProgram(shader);

	int success;
	glGetProgramiv(shader, GL_LINK_STATUS, &success);

	if (!success) {
		char errorLog[1024];
		glGetProgramInfoLog(shader, 1024, NULL, errorLog);
		std::cout << "Shader linking error:\n" << errorLog << '\n';
	}

	for (uint shaderModule : modules)
		glDeleteShader(shaderModule);

	return shader;
}

bool init(int width, int height, cstr title, bool windowResizeable, Window &window) {
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

    GLFWwindow *win = glfwCreateWindow(width, height, title, NULL, NULL);

    if (win == NULL) {
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }

	glfwSetWindowAttrib(win, GLFW_RESIZABLE, GL_FALSE);
    glfwMakeContextCurrent(win);
	
    window.glWin = win;

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwGetFramebufferSize(win, &window.width, &window.height);
    glViewport(0, 0, window.width, window.height);

	glEnable(GL_BLEND);
	glBlendEquation(GL_FUNC_ADD);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    return 0;
}

void closeOpenGL(std::vector<uint> shaders, Window &window) {
	for (uint shader : shaders)
    	glDeleteProgram(shader);
    glfwDestroyWindow(window.glWin);
    glfwTerminate();
}
