#pragma once

#include <cstdint>
#include "Types.hpp"
#include "glad/glad.h"

namespace GL
{
	struct IndexBuffer
	{
		IndexBuffer(const u32& size, const u32* indices, const GLenum& drawMode);
		IndexBuffer(const IndexBuffer&) = default;
		IndexBuffer(IndexBuffer&&) noexcept = default;
		~IndexBuffer();

		void Initialize(const u32& size, const u32* indices, const GLenum& drawMode);
		void Delete();
		void Bind();
		void Unbind();

		u32 Id;
	};
}
