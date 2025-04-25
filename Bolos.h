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

void bolos(glm::mat4 model, GLuint uniformModel, std::vector<Model*> objetosBolos);
void renderStand5(glm::mat4 model, GLuint uniformModel, Model& stand, glm::vec3 posicion);

void renderPines(glm::mat4 model, GLuint uniformModel, Model& pines, glm::vec3 posicion);
void renderBola(glm::mat4 model, GLuint uniformModel, Model& bola, glm::vec3 posicion);
void renderMesa(glm::mat4 model, GLuint uniformModel, Model& mesa, glm::vec3 posicion);
void renderCartelBoliche(glm::mat4 model, GLuint uniformModel, Model& cartel, glm::vec3 posicion);
