#pragma once

#include "Types.hpp"
#include "glad/glad.h"

namespace GL
{
	struct RenderBuffer
	{
		RenderBuffer(const u32& width, const u32& height);
		RenderBuffer(const RenderBuffer&) = default;
		RenderBuffer(RenderBuffer&&) noexcept = default;
		~RenderBuffer();

		void Initialize();
		void Delete();
		void Bind() const;
		void Unbind() const;

		u32 Id;
		u32 Width;
		u32 Height;
	};
}
