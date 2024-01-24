#include <iostream>

double function(double x)
{
    return (-4.0 / 5.0) * x * x + 3.0 * x - 2.0;
}

double integrate(double lower_limit, double upper_limit, double step_size)
{
    double result = 0.0;

    for (double x = lower_limit; x < upper_limit; x += step_size)
    {
        result += function(x) * step_size;
    }

    return result;
}

int main()
{
    double lower_limit, upper_limit;
    std::cin >> lower_limit >> upper_limit;

    // Ensure the input constraints are satisfied
    if (lower_limit < 0 || lower_limit > 100 || upper_limit < 0 || upper_limit > 100)
    {
        std::cerr << "Input constraints violated. Please enter valid limits." << std::endl;
        return 1;
    }

    double step_size = 0.001;
    double result = integrate(lower_limit, upper_limit, step_size);

    std::cout << result << std::endl;

    return 0;
}
