#include <iostream>
#include <vector>

using namespace std;

class LinearRegression {
public:
    // 기울기와 절편을 저장
    double slope = 0.0; // 기울기
    double intercept = 0.0; // 절편

    // 데이터 학습 함수, 선형 회귀 모델을 학습하는 함수
    void fit(const vector<double>& X, const vector<double>& y) { // X와 y는 각각 독립 변수와 종속 변수
        int n = X.size();
        if (n != y.size()) {
            cerr << "the size of x and y are different." << endl;
            return;
        }

        // 평균 계산 이를 통해 기울기와 절편을 계산할 수 있다.
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
        for (int i = 0; i < n; ++i) { // 기울기 공식을 이용
            num += (X[i] - meanX) * (y[i] - meanY); // X와 y의 공분산 부분
            den += (X[i] - meanX) * (X[i] - meanX); // X의 분산 부분
        }
        slope = num / den;

        // 절편 계산 intercept
        intercept = meanY - slope * meanX;
    }

    // 예측 함수
    double predict(double x) { // 주어진 x 값에 대해 예측된 y값을 반환. 
        return slope * x + intercept; // 회귀 직선의 방정식 사용
    }
};

int main()
{
    // X, y는 학습 데이터, 간단한 데이터셋을 사용
    vector<double> X = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // 독립 변수
    vector<double> y = { 2, 4, 5, 4 ,5, 7, 8, 9, 10, 12 }; // 종속 변수

    // 선형 회귀 모델을 생성
    LinearRegression model;

    // fit 함수를 호출해 모델을 학습시키기
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
