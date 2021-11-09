#include "probability.h"
#include <iostream>

probability::probability()
{
	this->likelihood = 0; // initial value
}

probability operator & (probability event_a, probability event_b)
{
	probability event_c;
	event_c.likelihood = event_a.likelihood * event_b.likelihood;
	return event_c;
}

probability operator | (probability event_a, probability event_b)
{
	probability event_c;
	event_c.likelihood = event_a.likelihood + event_b.likelihood - event_a.likelihood * event_b.likelihood;
	return event_c;
}

probability operator ^ (probability event_a, probability event_b)
{
	probability event_c;
	event_c.likelihood = event_a.likelihood + event_b.likelihood - 2 * event_a.likelihood * event_b.likelihood;
	return event_c;
}

probability operator - (probability event_a, probability event_b)
{
	probability event_c;
	event_c.likelihood = event_a.likelihood - (event_a.likelihood * event_b.likelihood);
	return event_c;
}

probability probability::operator ~ ()
{
	probability event_c;
	event_c.likelihood = 1 - this->likelihood;
	return event_c;
}

void probability::like_setter(double likelihood)
{
	if (likelihood < 0 | likelihood > 1)
	{
		std::cout << "the likelihood should be between 0 and 1";
	}
	else
	{
		this->likelihood = likelihood;
	}

}

double probability::like_getter()
{
	return likelihood;
}