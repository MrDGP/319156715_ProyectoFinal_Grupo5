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

void tierra(glm::mat4 model, GLuint uniformModel, Texture& tierra, std::vector<Mesh*> meshList);
void renderTierra(glm::mat4 model, GLuint uniformModel, Texture& tierra, Mesh& piso, glm::vec3 posicion, glm::vec3 escala);
