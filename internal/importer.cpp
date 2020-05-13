#include "importer.hpp"

#include "assets.inl"
#include "layout.inl"

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

namespace lamp
{
	mesh_ptr Importer::import(const char* path, const bool drop_normals)
	{
	    assert(path != nullptr);

		Assimp::Importer importer;
		uint32_t flag = aiProcess_Triangulate | aiProcess_JoinIdenticalVertices;

		if (drop_normals) {
			flag |= aiProcess_DropNormals;
		}

		const aiScene* ai_scene = importer.ReadFile(path, flag);
		const aiMesh*  ai_mesh  = ai_scene->mMeshes[0];

		gl::Layout layout;

		if (ai_mesh->HasPositions()) {
			layout.add<float>(3);
		}

		if (ai_mesh->HasTextureCoords(0)) {
			layout.add<float>(2);
		}

		if (ai_mesh->HasNormals()) {
			layout.add<float>(3);
		}

		std::vector<float>    vertices;
		std::vector<uint32_t> indices;
		indices.reserve(ai_mesh->mNumFaces * 3);

		for (uint32_t i = 0; i < ai_mesh->mNumVertices; i++)
		{
			if (ai_mesh->HasPositions())
			{
				const aiVector3D& position = ai_mesh->mVertices[i];

				vertices.emplace_back(position.x);
				vertices.emplace_back(position.y);
				vertices.emplace_back(position.z);
			}

			if (ai_mesh->HasTextureCoords(0))
			{
				const aiVector3D& uv = ai_mesh->mTextureCoords[0][i];

				vertices.emplace_back(uv.x);
				vertices.emplace_back(uv.y);
			}

			if (ai_mesh->HasNormals())
			{
				const aiVector3D& normal = ai_mesh->mNormals[i];

				vertices.emplace_back(normal.x);
				vertices.emplace_back(normal.y);
				vertices.emplace_back(normal.z);
			}
		}

		for (uint32_t i = 0; i < ai_mesh->mNumFaces; i++)
		{
			const auto& face = ai_mesh->mFaces[i];

			for (uint32_t j = 0; j < face.mNumIndices; j++)
			{
				indices.emplace_back(face.mIndices[j]);
			}
		}

		return Assets::create(vertices, indices, layout, GL_TRIANGLES, GL_STATIC_DRAW);
	}
}
