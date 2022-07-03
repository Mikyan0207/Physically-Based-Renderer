#include "OpenGL/VertexBuffer.hpp"

namespace GL
{
	VertexBuffer::VertexBuffer(const u32& size, const GLenum& drawMode)
	{
		Initialize(size, nullptr, drawMode);
	}

	VertexBuffer::VertexBuffer(const u32& size, const f32* vertices, const GLenum& drawMode)
	{
		Initialize(size, vertices, drawMode);
	}

	VertexBuffer::~VertexBuffer()
	{
		Delete();
	}

	void
	VertexBuffer::Initialize(const u32& size, const void* vertices, const GLenum& drawMode)
	{
		glGenBuffers(1, &Id);
		Bind();
		glBufferData(GL_ARRAY_BUFFER, size, vertices, drawMode);
	}

	void
	VertexBuffer::Delete()
	{
		if (Id != 0)
		{
			glDeleteBuffers(1, &Id);
		}
	}

	void
	VertexBuffer::Bind() const
	{
		glBindBuffer(GL_VERTEX_ARRAY, Id);
	}

	void
	VertexBuffer::Unbind() const
	{
		glBindBuffer(GL_VERTEX_ARRAY, 0);
	}

} // namespace GL
