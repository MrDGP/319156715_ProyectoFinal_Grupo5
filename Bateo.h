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

void bateo(glm::mat4 model, GLuint uniformModel, std::vector<Model*> objetosBateo);

void renderStand2(glm::mat4 model, GLuint uniformModel, Model& stand, glm::vec3 posicion);
void renderBardas(glm::mat4 model, GLuint uniformModel, Model& bardaBateo, glm::vec3 posicion);
void renderObjetivoBateo(glm::mat4 model, GLuint uniformModel, Model& objetivo, glm::vec3 posicion);
void renderCartelBateo(glm::mat4 model, GLuint uniformModel, Model& cartelBateo, glm::vec3 posicion);
void renderBats(glm::mat4 model, GLuint uniformModel, Model& bats, glm::vec3 posicion);