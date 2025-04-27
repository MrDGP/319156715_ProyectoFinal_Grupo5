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

void hacha(glm::mat4 model, GLuint uniformModel, std::vector<Model*> objetosHacha);
void renderStand(glm::mat4 model, GLuint uniformModel, Model &stand, Model &hacha, Model &reja, Model &tabla, Model &objetivo, glm::vec3 posicion);
