#include <cmath>
#include <vector>
#include <math.h>

#include <glew.h>
#include <glfw3.h>

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>

#include "Mesh.h"
#include "Texture.h"
#include"Model.h"

void dardos(glm::mat4 model, GLuint uniformModel, std::vector<Model*> objetosDardos);
void renderStand4(glm::mat4 model, GLuint uniformModel, Model& stand, Model& tabla, Model &cuadro1, Model &cuadro2, glm::vec3 posicion);
void renderGlobos(glm::mat4 model, GLuint uniformModel, Model& base, Model& globo, glm::vec3 posicion);
void renderDardos(glm::mat4 model, GLuint uniformModel, Model& dardo, glm::vec3 posicion);
void lanzarDardo();
void actualizarDardos(float deltaTime);