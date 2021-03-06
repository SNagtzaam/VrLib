#pragma once

#include <VrLib/Model.h>
#include <VrLib/gl/Vertex.h>
#include <VrLib/gl/VBO.h>
#include <VrLib/gl/VIO.h>
#include <VrLib/gl/VAO.h>

namespace vrlib
{
	template<class VertexType>
	class LoLModel : public Model
	{
	protected:
		LoLModel(const std::string &fileName, const ModelLoadOptions &options = ModelLoadOptions());
	public:
		virtual std::vector<glm::vec3> getVertices(int amount) const override;
		virtual std::vector<glm::vec3> getTriangles() const override;
		virtual void draw(const std::function<void(const glm::mat4&)> &modelviewMatrixCallback, const std::function<void(const Material&)> &materialCallback) override;
		virtual ModelInstance* getInstance() override;


		std::vector<glm::vec3> vertices;
		std::vector<unsigned short> indices;


		gl::VBO<VertexType> vbo;
		gl::VIO<unsigned short> vio;
		gl::VAO<VertexType>* vao;


		friend class Model;
	};



}