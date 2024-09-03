#ifndef SCALAR_CLASS_HP
# define SCALAR_CLASS_HP

# include <string>

class Scalar 
{
	public:

		~Scalar();

		static void convert(const std::string& literal);
	
	private:

		Scalar();
		Scalar(const Scalar& other);
		Scalar& operator=(const Scalar& other);
};

#endif