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

void dados(glm::mat4 model, GLuint uniformModel, std::vector<Model> objetosDados, Texture &tierra, std::vector<Mesh*> meshList);
void renderStand3(glm::mat4 model, GLuint uniformModel, Model stand, glm::vec3 posicion, Texture &tierra, std::vector<Mesh*> lista);
//void renderLuminaria1(glm::mat4 model, GLuint uniformModel, Model luminaria1, glm::vec3 posicion);