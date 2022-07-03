#pragma once

#include "Types.hpp"
#include "glad/glad.h"

namespace GL
{
	struct FrameBuffer
	{
		FrameBuffer() = default;
		FrameBuffer(const u32& width, const u32& height, const u32& originalWidth,
			    const u32& originalHeight);
		FrameBuffer(const FrameBuffer&) = default;
		FrameBuffer(FrameBuffer&&) noexcept = default;
		~FrameBuffer();

		void Initialize();
		void Delete();
		void Bind() const;
		void Unbind() const;

		u32 Id;
		u32 Width;
		u32 Height;
		u32 OriginalWidth;
		u32 OriginalHeight;
		u32 ColorAttachmentId;
		u32 RenderBufferId;
	};
}
