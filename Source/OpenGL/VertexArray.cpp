#include "OpenGL/VertexArray.hpp"
#include <algorithm>

namespace GL
{
	VertexArray::VertexArray()
	{
		Initialize();
	}

	VertexArray::~VertexArray()
	{
		Delete();
	}

	void
	VertexArray::Initialize()
	{
		glGenVertexArrays(1, &Id);
		Bind();
	}

	void
	VertexArray::Delete()
	{
		if (Id != 0)
		{
			glDeleteVertexArrays(1, &Id);
		}
	}

	void
	VertexArray::Bind() const
	{
		glBindVertexArray(Id);
	}

	void
	VertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void
	VertexArray::AddBuffer(std::unique_ptr<VertexBuffer>& buffer)
	{
		VertexBuffers.emplace_back(std::move(buffer));
	}

	void
	VertexArray::AddBuffer(std::unique_ptr<IndexBuffer>& buffer)
	{
		IndexBuffers.emplace_back(std::move(buffer));
	}

	void
	VertexArray::RemoveVertexBuffer(const u32& bufferId)
	{
		auto it = std::find_if(VertexBuffers.begin(), VertexBuffers.end(),
				       [&bufferId](const auto& buffer)
				       { return buffer->Id == bufferId; });

		if (it != VertexBuffers.end())
			VertexBuffers.erase(it);
	}

	void
	VertexArray::RemoveIndexBuffer(const u32& bufferId)
	{
		auto it = std::find_if(IndexBuffers.begin(), IndexBuffers.end(),
				       [&bufferId](const auto& buffer)
				       { return buffer->Id == bufferId; });

		if (it != IndexBuffers.end())
			IndexBuffers.erase(it);
	}

	VertexBuffer*
	VertexArray::GetVertexBuffer(const u32& bufferId)
	{
		auto it = std::find_if(VertexBuffers.begin(), VertexBuffers.end(),
				       [&bufferId](const auto& buffer)
				       { return buffer->Id == bufferId; });

		if (it != VertexBuffers.end())
			return (*it).get();

		return nullptr;
	}

	IndexBuffer*
	VertexArray::GetIndexBuffer(const u32& bufferId)
	{
		auto it = std::find_if(IndexBuffers.begin(), IndexBuffers.end(),
				       [&bufferId](const auto& buffer)
				       { return buffer->Id == bufferId; });

		if (it != IndexBuffers.end())
			return (*it).get();

		return nullptr;
	}
}
