#include "OpenGL/RenderBuffer.hpp"

namespace GL
{
	RenderBuffer::RenderBuffer(const u32& width, const u32& height)
	  : Width(width), Height(height)
	{
		Initialize();
	}

	RenderBuffer::~RenderBuffer()
	{
		Delete();
	}

	void
	RenderBuffer::Initialize()
	{
		glGenRenderbuffers(1, &Id);
		Bind();
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT32, Width, Height);
	}

	void
	RenderBuffer::Delete()
	{
		if (Id != 0)
		{
			glDeleteRenderbuffers(1, &Id);
		}
	}

	void
	RenderBuffer::Bind() const
	{
		glBindRenderbuffer(GL_RENDERBUFFER, Id);
	}

	void
	RenderBuffer::Unbind() const
	{
		glBindRenderbuffer(GL_RENDERBUFFER, 0);
	}
}
