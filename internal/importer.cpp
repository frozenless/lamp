#include "importer.hpp"
#include "assets.hpp"

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

#include <glad/glad.h>

namespace lamp
{
	gl::mesh_ptr import_mesh(const std::string_view& path, const bool drop_normals)
	{
		Assimp::Importer importer;
		u32 flag = aiProcess_Triangulate;

		if (drop_normals) {
			flag |= aiProcess_DropNormals;
		}

		const aiScene* ai_scene = importer.ReadFile(path.data(), flag);
		const aiMesh*  ai_mesh  = ai_scene->mMeshes[0];

		vertices vertices;
		indices indices;

		attributes attributes;

		if (ai_mesh->HasPositions()) {
			attributes.emplace_back(0, 3, 0);
		}

		if (ai_mesh->HasNormals()) {
			attributes.emplace_back(1, 3, 3 * sizeof(f32));
		}

		for (u32 i = 0; i < ai_mesh->mNumVertices; i++)
		{
			if (ai_mesh->HasPositions())
			{
				const aiVector3D &position = ai_mesh->mVertices[i];

				vertices.emplace_back(position.x);
				vertices.emplace_back(position.y);
				vertices.emplace_back(position.z);
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
			const auto face = ai_mesh->mFaces[i];

			for (u32 j = 0; j < face.mNumIndices; j++)
			{
				indices.emplace_back(face.mIndices[j]);
			}
		}

		return create_mesh(vertices, indices, attributes, GL_TRIANGLES, GL_STATIC_DRAW);
	}
}
