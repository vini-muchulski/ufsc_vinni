#include <opencv2/opencv.hpp>

int main() {
    cv::Mat image = cv::imread("1.jpg");
    if (image.empty()) {
        std::cout << "Erro ao carregar a imagem!" << std::endl;
        return -1;
    }
    cv::imshow("Imagem", image);
    cv::waitKey(0);
    return 0;
}
