#ifndef LINEAR_REGRESSION_HPP
#define LINEAR_REGRESSION_HPP

import std;
using namespace std;

class LinearRegression
{
private:
    using Matrix = vector<vector<double>>;
    Matrix points;
    double slope;
    double intercept;

public:
    double rmse(const Matrix &points)
    {
        double sum = 0.0;
        int m = points.size();
        for (size_t i = 0; i < m - 1; ++i)
        {
            double diff = predict(points[i]) - points[i][1];
            sum += pow(diff, 2);
        }
        return sqrt(sum / m);
    }

    double mae(const Matrix &points)
    {
        double sum = 0.0;
        int m = points.size(); // Assuming we're comparing all points
        for (size_t i = 0; i < m - 1; ++i)
        {
            double diff = abs(predict(points[i]) - points[i][1]); // absoulte difference between predicted and actual value
            sum += diff;
        }
        return sum / m;
    }

    void gradient(const Matrix &points)
    {
        double sum_x = 0.0;
        double sum_y = 0.0;
        double sum_xy = 0.0;
        double sum_x2 = 0.0;
        int n = points.size();

        for (const auto &p : points)
        {
            sum_x += p[0];
            sum_y += p[1];
            sum_xy += p[0] * p[1];
            sum_x2 += p[0] * p[0];
        }

        // Get slope using the formula for linear regression
        slope = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    }

    void y_intercept(const vector<double> &p)
    {
        intercept = p[1] - slope * p[0];
    }

    void fit(const vector<double> &X, vector<double> &y)
    {
        gradient(vector<vector<double>>{X, y});
        y_intercept({X[0], y[0]});
    }

    double predict(const vector<double> &point)
    {
        return slope * point[0] + intercept;
    }
};

#endif // LINEAR_REGRESSION_HPP