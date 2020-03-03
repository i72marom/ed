#include <cassert>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "pattern.hpp"

Pattern::Pattern(const size_t dim, const int class_label)
{
	//DONE
	pattern_.resize(dim);
	class_ = class_label;
}

Pattern::Pattern(const float values[], const size_t dim, const int class_label)
{
	assert(dim>0);
	//DONE
	pattern_.resize(dim);
	class_ = class_label;
	for (int i = 0; i < dim; ++i)
		pattern_[i] = values[i];
}

Pattern::Pattern(const Pattern& other)
{
	//DONE
	pattern_.resize(other.pattern_.size());
	pattern_ = other.pattern_;
	class_ = other.class_;
}

Pattern::~Pattern()
{
	//TODO
	;
}

size_t Pattern::dim() const
{
	//DONE
	return pattern_.size();
}

int Pattern::class_label() const
{
	//DONE
	return class_;
}

float Pattern::operator [](const size_t idx) const
{
	assert((0 <= idx) && (idx < dim()));
	//DONE
	return pattern_[idx];
}

float Pattern::sum() const
{
	//DONE
	float sum;
	for (int i = 0; i < pattern_.size(); ++i)
		sum += pattern_[i];
	return sum;
}

float Pattern::max() const
{
	//DONE
	return pattern_.max();
}

float Pattern::min() const
{
	//DONE
	return pattern_.min();
}

void Pattern::set_class_label(const int new_label)
{
	//DONE
	class_ = new_label;
}

void Pattern::set_dim(size_t new_dim)
{
	//DONE
	pattern_.resize(new_dim);
}

void Pattern::set_value(const size_t i, const float new_v)
{
	assert(0<=i && i<dim());
	//DONE
	pattern_[i] = new_v;
}

void Pattern::set_values(const float values[])
{
	//DONE
	for (int i = 0; i < dim(); ++i)
		pattern_[i] = values[i];
}

Pattern& Pattern::operator += (const Pattern& o)
{
	assert(o.dim()==dim());
	//DONE
	this->pattern_ += o.pattern_;
	return *this;
}

Pattern& Pattern::operator -= (const Pattern& o)
{
	assert(o.dim()==dim());
	//DONE
	this->pattern_ -= o.pattern_;
	return *this;
}

Pattern& Pattern::operator *= (const Pattern& o)
{
	assert(o.dim()==dim());
	//DONE
	this->pattern_ *= o.pattern_;
	return *this;
}

Pattern& Pattern::operator *= (const float c)
{
	//DONE
	this->pattern_ *= c;
	return *this;
}

float
distance(const Pattern& a, const Pattern& b)
{
	//DONE
	float sum = 0.0;
	for (int i = 0; i < a.dim(); ++i) {
		sum += pow((a[i] - b[i]), 2);
	}


	return sqrt(sum);
}


std::ostream& operator << (std::ostream& output, const Pattern& p)
{
	output << p.class_label();
	for (size_t i=0; i<p.dim(); ++i)
		output << ' ' << p[i];
	output << std::endl;
	return output;
}

std::istream& operator >> (std::istream& input, Pattern& p)
	noexcept(false)
{
   std::string line;
   std::getline(input, line);
   if (input && line.size()>0)
   {
	   std::istringstream _input;
	   _input.str(line);
	   int class_label;
	   std::vector<float> values;
	   _input >> class_label;
	   while(_input)
	   {
		  float v;
		  _input >> v;
		  if (_input)
			  values.push_back(v);
	   }
	   if (values.size() != p.dim())
		   throw std::runtime_error("Wrong input format.");
	   else
	   {
		   p.set_class_label(class_label);
		   p.set_values(&values[0]);
	   }
   }
   return input;
}


std::istream&
load_dataset(std::istream& input,
			 std::vector<Pattern>& dts) noexcept(false)
{
	if (input)
	{
		size_t size;
		size_t dim;
		input >> size >> dim;
		if (!input)
			throw (std::runtime_error("Error: wrong input format."));
		input.ignore(); //Skips newline.
		dts.resize(size, Pattern(dim));
		for (size_t i = 0; i<size; ++i)
		{
			input >> dts[i];
			if (!input)
				throw (std::runtime_error("Error: wrong input format."));
		}
	}
	return input;
}
