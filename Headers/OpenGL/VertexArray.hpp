#pragma once

#include "OpenGL/IndexBuffer.hpp"
#include "OpenGL/VertexBuffer.hpp"
#include "glad/glad.h"
#include "Types.hpp"
#include <memory> // std::unique_ptr
#include <vector>

namespace GL
{
	struct VertexArray
	{
		VertexArray();
		VertexArray(const VertexArray&) = default;
		VertexArray(VertexArray&&) noexcept = default;
		~VertexArray();

		void Initialize();
		void Delete();
		void Bind() const;
		void Unbind() const;
		void AddBuffer(std::unique_ptr<VertexBuffer>& buffer);
		void AddBuffer(std::unique_ptr<IndexBuffer>& buffer);
		void RemoveVertexBuffer(const u32& bufferId);
		void RemoveIndexBuffer(const u32& bufferId);

		VertexBuffer* GetVertexBuffer(const u32& bufferId);
		IndexBuffer* GetIndexBuffer(const u32& bufferId);

		u32 Id;
		std::vector<std::unique_ptr<VertexBuffer>> VertexBuffers = {};
		std::vector<std::unique_ptr<IndexBuffer>> IndexBuffers = {};
	};
}
