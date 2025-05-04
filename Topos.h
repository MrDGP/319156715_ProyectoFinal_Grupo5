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

void topos(glm::mat4 model, GLuint uniformModel, std::vector<Model*> objetosTopos);
void renderStand6(glm::mat4 model, GLuint uniformModel, Model& stand, Model& cuadro, glm::vec3 posicion);
void renderMaquina(glm::mat4 model, GLuint uniformModel, Model& mesa, Model& tubo, Model& planta, glm::vec3 posicion);
void renderMaquina2(glm::mat4 model, GLuint uniformModel, Model& mesa, Model& tubo, Model& planta, glm::vec3 posicion);
void renderMaquina3(glm::mat4 model, GLuint uniformModel, Model& mesa, Model& tubo, Model& planta, glm::vec3 posicion);
void activarTopos();
void actualizarTopos(float deltaTime);