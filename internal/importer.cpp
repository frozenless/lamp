#include "importer.hpp"

#include "assets.inl"
#include "layout.inl"

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

#include <glad/glad.h>

namespace lamp
{
	gl::mesh_ptr import_mesh(const std::string_view& path, const bool drop_normals)
	{
		Assimp::Importer importer;
		u32 flag = aiProcess_Triangulate | aiProcess_JoinIdenticalVertices;

		if (drop_normals) {
			flag |= aiProcess_DropNormals;
		}

		const aiScene* ai_scene = importer.ReadFile(path.data(), flag);
		const aiMesh*  ai_mesh  = ai_scene->mMeshes[0];

		Layout layout;

		if (ai_mesh->HasPositions()) {
			layout.add<f32>(3, GL_FLOAT);
		}

		if (ai_mesh->HasTextureCoords(0)) {
			layout.add<f32>(2, GL_FLOAT);
		}

		if (ai_mesh->HasNormals()) {
			layout.add<f32>(3, GL_FLOAT);
		}

		std::vector<f32> vertices;
		std::vector<u32> indices;
		indices.reserve(ai_mesh->mNumFaces * 3);

		for (u32 i = 0; i < ai_mesh->mNumVertices; i++)
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

		for (u32 i = 0; i < ai_mesh->mNumFaces; i++)
		{
			const auto& face = ai_mesh->mFaces[i];

			for (u32 j = 0; j < face.mNumIndices; j++)
			{
				indices.emplace_back(face.mIndices[j]);
			}
		}

		return Assets::create_mesh(vertices, indices, layout, GL_TRIANGLES, GL_UNSIGNED_INT, GL_STATIC_DRAW);
	}
}
