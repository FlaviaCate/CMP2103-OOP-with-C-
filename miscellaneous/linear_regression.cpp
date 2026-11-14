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
        for (size_t i = 0; i < m-1; ++i)
        {
            double diff = predict(points[i]) - points[i + 1][1];
            sum += pow(diff, 2);
        }
        return sqrt(sum / m);
    }

    double mae(const vector<vector<double>> &points)
    {
        double sum = 0.0;
        int m = points.size(); // Assuming we're comparing all points
        for (size_t i = 0; i < m-1; ++i)
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

int
main()
{
    vector<vector<double>> prices = {
        {0.0000, 1.2500},
        {1.0000, 1.2514},
        {2.0000, 1.2511},
        {3.0000, 1.2529},
        {4.0000, 1.2568},
        {5.0000, 1.2564},
        {6.0000, 1.2559},
        {7.0000, 1.2600},
        {8.0000, 1.2621},
        {9.0000, 1.2610}};

    LinearRegression lr;
    lr.fit(prices);

    // double slope = lr.gradient(prices);
    // double intercept = lr.y_intercept(prices[0], slope);

    // cout << "Slope: " << slope << "\n";
    // cout << "Intercept: " << intercept << "\n";

    vector<double> new_point = {6.0, 13.0};
    double prediction = lr.predict(new_point);
    cout << "Prediction for point (6, 13): " << prediction << "\n";

    double rmse_value = lr.rmse(prices);
    double mae_value = lr.mae(prices);
    cout << "RMSE: " << rmse_value << "\n";
    cout << "MAE: " << mae_value << "\n";

    return 0;
}
