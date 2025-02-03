#include <iostream>
#include <vector>

using namespace std;

class LinearRegression {
public:
    // 기울기와 절편을 저장
    double slope = 0.0; // 기울기
    double intercept = 0.0; // 절편

    // 데이터 학습 함수 (기울기, 절편을 구하는 함수)
    void fit(const vector<double>& X, const vector<double>& y) {
        int n = X.size();
        if (n != y.size()) {
            cerr << "the size of x and y are different." << endl;
            return;
        }

        // 평균 계산
        double meanX = 0.0;
        double meanY = 0.0;
        for (int i = 0; i < n; ++i) {
            meanX += X[i];
            meanY += y[i];
        }
        meanX /= n;
        meanY /= n;

        // 기울기 계산 slope
        double num = 0.0;
        double den = 0.0;
        for (int i = 0; i < n; ++i) {
            num += (X[i] - meanX) * (y[i] - meanY);
            den += (X[i] - meanX) * (X[i] - meanX);
        }
        slope = num / den;

        // 절편 계산 intercept
        intercept = meanY - slope * meanX;
    }

    // 예측 함수
    double predict(double x) {
        return slope * x + intercept;
    }
};

int main()
{
    // 학습 데이터 (x, y)
    vector<double> X = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; //독립 변수
    vector<double> y = { 2, 4, 5, 4 ,5, 7, 8, 9, 10, 12 }; //종속 변수

    // 선형 회귀 모델 생성
    LinearRegression model;

    // 모델 학습
    model.fit(X, y);

    // 학습된 모델 출력
    cout << "Slope: " << model.slope << endl;
    cout << "Intercept: " << model.intercept << endl;

    // 예측할 x 값 입력받기
    double newX;
    cout << "Enter X value to predict: ";
    cin >> newX;

    // 예측 결과 출력
    double prediction = model.predict(newX);
    cout << "When X = " << newX << ", predicted y values: " << prediction << endl;

    return 0;
}