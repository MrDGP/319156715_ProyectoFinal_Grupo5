#include "Window.h"
#include "CommonValues.h"
Window::Window()
{
	width = 800;
	height = 600;
	for (size_t i = 0; i < 1024; i++)
	{
		keys[i] = 0;
	}
}
Window::Window(GLint windowWidth, GLint windowHeight)
{
	width = windowWidth;
	height = windowHeight;
	muevex = 2.0f;
	camaraActiva = 0;

	for (size_t i = 0; i < 1024; i++)
	{
		keys[i] = 0;
	}
}
int Window::Initialise()
{
	//Inicialización de GLFW
	if (!glfwInit())
	{
		printf("Falló inicializar GLFW");
		glfwTerminate();
		return 1;
	}
	//Asignando variables de GLFW y propiedades de ventana
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//para solo usar el core profile de OpenGL y no tener retrocompatibilidad
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//CREAR VENTANA
	mainWindow = glfwCreateWindow(width, height, "Proyecto final", NULL, NULL);

	if (!mainWindow)
	{
		printf("Fallo en crearse la ventana con GLFW");
		glfwTerminate();
		return 1;
	}
	//Obtener tamaño de Buffer
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	//asignar el contexto
	glfwMakeContextCurrent(mainWindow);

	//MANEJAR TECLADO y MOUSE
	createCallbacks();


	//permitir nuevas extensiones
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("Falló inicialización de GLEW");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	glEnable(GL_DEPTH_TEST); //HABILITAR BUFFER DE PROFUNDIDAD
							 // Asignar valores de la ventana y coordenadas
							 
							 //Asignar Viewport
	glViewport(0, 0, bufferWidth, bufferHeight);
	//Callback para detectar que se está usando la ventana
	glfwSetWindowUserPointer(mainWindow, this);
}

void Window::createCallbacks()
{
	glfwSetKeyCallback(mainWindow, ManejaTeclado);
	glfwSetCursorPosCallback(mainWindow, ManejaMouse);
}
GLfloat Window::getXChange()
{
	GLfloat theChange = xChange;
	xChange = 0.0f;
	return theChange;
}

GLfloat Window::getYChange()
{
	GLfloat theChange = yChange;
	yChange = 0.0f;
	return theChange;
}

void Window::ManejaTeclado(GLFWwindow* window, int key, int code, int action, int mode)
{
	Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
	if (action == GLFW_PRESS) {
		if (key == GLFW_KEY_1) {
			theWindow->camaraActiva = 0; // aérea
		}
		if (key == GLFW_KEY_2) {
			theWindow->camaraActiva = 1; // tercera persona
		}
		if (key == GLFW_KEY_3) {
			theWindow->camaraActiva = 2; // PUESTOS
		}
	}

// ---------------------------------------------
// X - controlar puesto 0
	if (key == GLFW_KEY_X && action == GLFW_PRESS) {
		if (theWindow->getCamaraActiva() == 3) {
			// Si estamos en cámara puestos
			theWindow->puestoActual = 0; // Cambio de puesto
			// Solo permitir controlar la luz del puesto actual
			for (int i = 0; i < MAX_SPOT_LIGHTS; i++) {
				if (i == theWindow->puestoActual) {
					theWindow->lucesSpot[i] = !theWindow->lucesSpot[i]; // Toggle luz de mi puesto
				}
				else {
					theWindow->lucesSpot[i] = false; // Asegurar que las otras estén apagadas
				}
			}
		}
		else {
			// Libre o tercera persona
			theWindow->lucesSpot[0] = !theWindow->lucesSpot[0]; // Toggle libre
		}
	}

	// ---------------------------------------------
	// C - controlar puesto 1
	if (key == GLFW_KEY_C && action == GLFW_PRESS) {
		if (theWindow->getCamaraActiva() == 2) {
			theWindow->puestoActual = 1;
			for (int i = 0; i < MAX_SPOT_LIGHTS; i++) {
				if (i == theWindow->puestoActual) {
					theWindow->lucesSpot[i] = !theWindow->lucesSpot[i];
				}
				else {
					theWindow->lucesSpot[i] = false;
				}
			}
		}
		else {
			theWindow->lucesSpot[1] = !theWindow->lucesSpot[1];
		}
	}

	// ---------------------------------------------
	// V - controlar puesto 2
	if (key == GLFW_KEY_V && action == GLFW_PRESS) {
		if (theWindow->getCamaraActiva() == 2) {
			theWindow->puestoActual = 2;
			for (int i = 0; i < MAX_SPOT_LIGHTS; i++) {
				if (i == theWindow->puestoActual) {
					theWindow->lucesSpot[i] = !theWindow->lucesSpot[i];
				}
				else {
					theWindow->lucesSpot[i] = false;
				}
			}
		}
		else {
			theWindow->lucesSpot[2] = !theWindow->lucesSpot[2];
		}
	}

	// ---------------------------------------------
	// B - controlar puesto 3
	if (key == GLFW_KEY_B && action == GLFW_PRESS) {
		if (theWindow->getCamaraActiva() == 2) {
			theWindow->puestoActual = 3;
			for (int i = 0; i < MAX_SPOT_LIGHTS; i++) {
				if (i == theWindow->puestoActual) {
					theWindow->lucesSpot[i] = !theWindow->lucesSpot[i];
				}
				else {
					theWindow->lucesSpot[i] = false;
				}
			}
		}
		else {
			theWindow->lucesSpot[3] = !theWindow->lucesSpot[3];
		}
	}
	// ---------------------------------------------
	// N - controlar puesto 4
	if (key == GLFW_KEY_N && action == GLFW_PRESS) {
		if (theWindow->getCamaraActiva() == 2) {
			theWindow->puestoActual = 4;
			for (int i = 0; i < MAX_SPOT_LIGHTS; i++) {
				if (i == theWindow->puestoActual) {
					theWindow->lucesSpot[i] = !theWindow->lucesSpot[i];
				}
				else {
					theWindow->lucesSpot[i] = false;
				}
			}
		}
		else {
			theWindow->lucesSpot[4] = !theWindow->lucesSpot[4];
		}
	}
	// ---------------------------------------------
	// M - controlar puesto 5
	if (key == GLFW_KEY_M && action == GLFW_PRESS) {
		if (theWindow->getCamaraActiva() == 2) {
			theWindow->puestoActual = 5;
			for (int i = 0; i < MAX_SPOT_LIGHTS; i++) {
				if (i == theWindow->puestoActual) {
					theWindow->lucesSpot[i] = !theWindow->lucesSpot[i];
				}
				else {
					theWindow->lucesSpot[i] = false;
				}
			}
		}
		else {
			theWindow->lucesSpot[5] = !theWindow->lucesSpot[5];
		}
	}
	//--------------------------------------------------------

	
	if (key == GLFW_KEY_Y)
	{
		theWindow->muevex += 1.0;
	}
	if (key == GLFW_KEY_U)
	{
		theWindow->muevex -= 1.0;
	}

	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
		{
			theWindow->keys[key] = true;
			//printf("se presiono la tecla %d'\n", key);
		}
		else if (action == GLFW_RELEASE)
		{
			theWindow->keys[key] = false;
			//printf("se solto la tecla %d'\n", key);
		}
	}

	

}


void Window::ManejaMouse(GLFWwindow* window, double xPos, double yPos)
{
	Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

	if (theWindow->mouseFirstMoved)
	{
		theWindow->lastX = xPos;
		theWindow->lastY = yPos;
		theWindow->mouseFirstMoved = false;
	}

	theWindow->xChange = xPos - theWindow->lastX;
	theWindow->yChange = theWindow->lastY - yPos;

	theWindow->lastX = xPos;
	theWindow->lastY = yPos;
}


Window::~Window()
{
	glfwDestroyWindow(mainWindow);
	glfwTerminate();

}
