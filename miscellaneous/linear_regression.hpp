#ifndef LINEAR_REGRESSION_HPP
#define LINEAR_REGRESSION_HPP

import std;
using namespace std;

class LinearRegression
{
private:
    vector<vector<double>> points;
    double slope;
    double intercept;

public:
    double rmse(const vector<vector<double>> &points)
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

    double mae(const vector<vector<double>> &points)
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

    void gradient(const vector<vector<double>> &points)
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

    void y_intercept(const vector<double> &p, double slope)
    {
        intercept = p[1] - slope * p[0];
    }

    void fit(const vector<vector<double>> &points)
    {
        gradient(points);
        y_intercept({points[0][0], points[0][1]}, slope);
    }

    double predict(const vector<double> &point)
    {
        return slope * point[0] + intercept;
    }
};

#endif // LINEAR_REGRESSION_HPP