#pragma once

#include "Types.hpp"
#include "glad/glad.h"

namespace GL
{
	struct VertexBuffer
	{
		VertexBuffer(const u32& size, const GLenum& drawMode);
		VertexBuffer(const u32& size, const f32* vertices, const GLenum& drawMode);
		VertexBuffer(const VertexBuffer&) = default;
		VertexBuffer(VertexBuffer&&) noexcept = default;
		~VertexBuffer();

		void Initialize(const u32& size, const void* vertices, const GLenum& drawMode);
		void Delete();
		void Bind() const;
		void Unbind() const;

		uint32_t Id;
	};
} // namespace GL
