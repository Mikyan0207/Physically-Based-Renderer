#include "OpenGL/IndexBuffer.hpp"

namespace GL
{
	IndexBuffer::IndexBuffer(const u32& size, const u32* indices, const GLenum& drawMode)
	{
		Initialize(size, indices, drawMode);
	}

	IndexBuffer::~IndexBuffer()
	{
		Delete();
	}

	void
	IndexBuffer::Initialize(const u32& size, const u32* indices, const GLenum& drawMode)
	{
		glGenBuffers(1, &Id);
		Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, drawMode);
	}

	void
	IndexBuffer::Delete()
	{
		if (Id != 0)
		{
			glDeleteBuffers(1, &Id);
		}
	}

	void
	IndexBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Id);
	}

	void
	IndexBuffer::Unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}
