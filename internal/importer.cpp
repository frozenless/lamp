#include "importer.hpp"
#include "assets.hpp"

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

#include <glad/glad.h>

namespace lamp
{
	meshPtr import_mesh(const std::string_view& path, u32 flag)
	{
		Assimp::Importer importer;

		const aiScene* ai_scene = importer.ReadFile(path.data(), aiProcess_Triangulate | flag);
		const aiMesh*  ai_mesh  = ai_scene->mMeshes[0];

		std::vector<f32> vertices;
		std::vector<u32> indices;

		std::vector<gl::Attribute> attributes;
		attributes.push_back({ 0, 3, 0 });

		if (ai_mesh->HasNormals()) {
			attributes.push_back({1, 3, 3 * sizeof(f32)});
		}

		for (u32 i = 0; i < ai_mesh->mNumVertices; i++)
		{
			const aiVector3D& position = ai_mesh->mVertices[i];

			vertices.emplace_back(position.x);
			vertices.emplace_back(position.y);
			vertices.emplace_back(position.z);

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
			const auto face = ai_mesh->mFaces[i];

			for (u32 j = 0; j < face.mNumIndices; j++)
			{
				indices.emplace_back(face.mIndices[j]);
			}
		}

		return create_mesh(vertices, indices, attributes, GL_TRIANGLES, GL_STATIC_DRAW);
	}
}
