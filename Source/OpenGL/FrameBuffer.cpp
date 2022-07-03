#include "OpenGL/FrameBuffer.hpp"
#include <iostream>

namespace GL
{
	FrameBuffer::FrameBuffer(const u32 &width, const u32 &height, const u32 &originalWidth,
				 const u32 &originalHeight)
	  : Width(width), Height(height), OriginalWidth(originalWidth),
	    OriginalHeight(originalHeight)
	{
		Initialize();
	}

	void
	FrameBuffer::Initialize()
	{
		glGenTextures(1, &ColorAttachmentId);
		glBindTexture(GL_TEXTURE_2D, ColorAttachmentId);

		// Create Texture for color attachment
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, Width, Height, 0, GL_RGB,
			     GL_UNSIGNED_BYTE, 0);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// Create Render Buffer.
		glGenRenderbuffers(1, &RenderBufferId);
		glBindRenderbuffer(GL_RENDERBUFFER, RenderBufferId);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT32, Width, Height);

		// Link everything to framebuffer.
		glGenFramebuffers(1, &Id);
		Bind();

		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D,
				       ColorAttachmentId, 0);
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER,
					  RenderBufferId);

		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		{
			std::cerr << "[Framebuffer] Incomplete framebuffer!" << std::endl;
		}

		glBindTexture(GL_TEXTURE_2D, 0);
		glBindRenderbuffer(GL_RENDERBUFFER, 0);
		Unbind();
	}

	void
	FrameBuffer::Delete()
	{
		glDeleteFramebuffers(1, &Id);
	}

	void
	FrameBuffer::Bind() const
	{
		glBindFramebuffer(GL_FRAMEBUFFER, Id);
		glViewport(0, 0, Width, Height);

		const GLenum buffers[] = { GL_COLOR_ATTACHMENT0 };
		glDrawBuffers(1, buffers);
	}

	void
	FrameBuffer::Unbind() const
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		glViewport(0, 0, OriginalWidth, OriginalHeight);
	}
} // namespace GL
