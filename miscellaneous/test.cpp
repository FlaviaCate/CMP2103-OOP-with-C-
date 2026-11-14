#include "linear_regression.hpp"

import std;
using namespace std;

int main()
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

    vector<double> X;
    vector<double> y;
    for (const auto &point : prices)
    {
        X.push_back(point[0]);
        y.push_back(point[1]);
    }

    LinearRegression lr;
    lr.fit(X, y);

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
