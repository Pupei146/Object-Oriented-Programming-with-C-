class probability
{
public:
	probability();

	friend probability operator & (probability event_a, probability event_b);

	friend probability operator | (probability event_a, probability event_b);

	friend probability operator ^ (probability event_a, probability event_b);

	friend probability operator - (probability event_a, probability event_b);

	probability operator ~ ();

	void like_setter(double likelihood);

	double like_getter();

private:
	double likelihood;

};