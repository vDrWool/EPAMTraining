#include "Shapes.h"

namespace EPAM
{
	IShape::~IShape() {}

	Circle& Circle::operator = (const Circle& other) noexcept
	{
		if (*this == other)
			return *this;

		this->m_center = other.m_center;
		this->m_radius = other.m_radius;

		return *this;
	}
	Square& Square::operator = (const Square& other) noexcept
	{
		if (*this == other)
			return *this;

		this->m_leftUp = other.m_leftUp;
		this->m_length = other.m_length;

		return *this;
	}
	Rectangle& Rectangle::operator = (const Rectangle& other) noexcept
	{
		if (*this == other)
			return *this;

		this->m_leftUp    = other.m_leftUp;
		this->m_rightDown = other.m_rightDown;

		return *this;
	}

	bool Circle::operator == (const Circle& other) noexcept
	{ 
		return this->m_center == other.m_center && this->m_radius == other.m_radius; 
	}
	bool Square::operator == (const Square& other) noexcept
	{
		return this->m_leftUp == other.m_leftUp && this->m_length == other.m_length;
	}
	bool Rectangle::operator == (const Rectangle& other) noexcept
	{
		return this->m_leftUp == other.m_leftUp && this->m_rightDown == other.m_rightDown;
	}

	float Circle::perimeter() const
	{
		if (this->m_radius <= 0)
			throw std::exception("Radius equal or less than zero!");

		return static_cast<float>(2 * 3.1415 * this->m_radius);
	}
	float Square::perimeter() const
	{
		if (this->m_length == 0)
			throw std::exception("Length of the square equal zero!");

		return static_cast<float>(4 * this->m_length);
	}
	float Rectangle::perimeter() const
	{
		return static_cast<float>(
			   (std::abs(this->m_leftUp.x - this->m_rightDown.x) * 2) +
			   (std::abs(this->m_leftUp.y - this->m_rightDown.y) * 2)
			);
	}

	float Circle::square() const
	{
		if (this->m_radius <= 0)
			throw std::exception("Radius equal or less than zero!");

		return static_cast<float>(3.1415 * this->m_radius * this->m_radius);
	}
	float Square::square() const
	{
		if (this->m_length == 0)
			throw std::exception("Length of the square equal zero!");

		return static_cast<float>(this->m_length * this->m_length);
	}
	float Rectangle::square() const
	{
		return static_cast<float>(
				std::abs(this->m_leftUp.x - this->m_rightDown.x) *
			    std::abs(this->m_leftUp.y - this->m_rightDown.y)
			);
	}

	// ====================================================================

	/*GLint createShader()
	{
		const char* fragmentSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

		const char* vertexSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

		GLint idF = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(idF, 1, &fragmentSource, nullptr);
		glCompileShader(idF);

		GLint success{};
		char infoLog[512]{};
		glGetShaderiv(idF, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(idF, 512, nullptr, infoLog);
			std::cout << "ERROR::SHADER\n" << infoLog << std::endl;
		}

		GLint idV = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(idV, 1, &vertexSource, nullptr);
		glCompileShader(idV);

		glGetShaderiv(idV, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(idV, 512, nullptr, infoLog);
			std::cout << "ERROR::SHADER\n" << infoLog << std::endl;
		}

		GLint id = glCreateProgram();
		glAttachShader(id, idF);
		glAttachShader(id, idV);
		glLinkProgram(id);

		glGetProgramiv(id, GL_LINK_STATUS, &success);
		if (GLchar infoLog[512]{}; !success)
		{
			glGetProgramInfoLog(id, 512, nullptr, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM\n" << infoLog << std::endl;
		}

		glDeleteShader(idF);
		glDeleteShader(idV);

		return id;
	}

	std::pair<GLint, GLuint> Circle::dataForDraw()
	{
		GLint id = createShader();

		return { 0, 0 };
	}
	std::pair<GLint, GLuint> Square::dataForDraw()
	{
		GLint shaderId = createShader();

		GLfloat VBOsData[] = {
			this->m_leftUp.x + this->m_length, this->m_leftUp.y                 , 0.0f,
			this->m_leftUp.x + this->m_length, this->m_leftUp.y - this->m_length, 0.0f,
			this->m_leftUp.x                 , this->m_leftUp.y - this->m_length, 0.0f,
			this->m_leftUp.x                 , this->m_leftUp.y                 , 0.0f
		};

		GLuint indexes[] = { 
			0, 1, 3,
			1, 2, 3
		};

		GLuint VAO{}, VBO{}, EBO{};
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(VBOsData), VBOsData, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexes), indexes, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		return { shaderId, VAO };
	}
	std::pair<GLint, GLuint> Rectangle::dataForDraw()
	{
		GLint shaderId = createShader();

		GLfloat VBOsData[] = {
			this->m_rightDown.x, this->m_leftUp.y   , 0.0f,
			this->m_rightDown.x, this->m_rightDown.y, 0.0f,
			this->m_leftUp.x   , this->m_rightDown.y, 0.0f,
			this->m_leftUp.x   , this->m_leftUp.y   , 0.0f
		};

		GLuint indexes[] = {
			0, 1, 3,
			1, 2, 3
		};

		GLuint VAO{}, VBO{}, EBO{};
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(VBOsData), VBOsData, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexes), indexes, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		return { shaderId, VAO };
	}*/
}