#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

int main() {
    // Carregar o modelo de detecção facial
    std::string model = "face_detection_yunet_2023mar.onnx";
    cv::Size input_size(320, 320);
    double score_threshold = 0.9;
    double nms_threshold = 0.3;
    int top_k = 5000;
    int backend_id = cv::dnn::DNN_BACKEND_OPENCV;
    int target_id = cv::dnn::DNN_TARGET_CPU;

    cv::Ptr<cv::FaceDetectorYN> face_detector = cv::FaceDetectorYN::create(
        model, "", input_size, score_threshold, nms_threshold, top_k, backend_id, target_id);

    // Captura de vídeo da webcam
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cout << "Não foi possível conectar à webcam" << std::endl;
        return -1;
    }

    // Obter as dimensões do frame
    cv::Mat frame;
    cap >> frame;
    if (frame.empty()) {
        std::cout << "Falha na captura de vídeo" << std::endl;
        return -1;
    }

    int frame_width = frame.cols;
    int frame_height = frame.rows;
    face_detector->setInputSize(cv::Size(frame_width, frame_height));

    while (true) {
        cap >> frame;
        if (frame.empty()) {
            std::cout << "Falha na captura de vídeo" << std::endl;
            break;
        }

        cv::Mat faces;
        face_detector->detect(frame, faces);

        if (!faces.empty()) {
            for (int i = 0; i < faces.rows; ++i) {
                // Extrair as coordenadas da caixa delimitadora
                float x = faces.at<float>(i, 0);
                float y = faces.at<float>(i, 1);
                float w = faces.at<float>(i, 2);
                float h = faces.at<float>(i, 3);
                cv::Rect face_rect(cv::Point(cvRound(x), cvRound(y)), cv::Size(cvRound(w), cvRound(h)));
                cv::rectangle(frame, face_rect, cv::Scalar(0, 255, 0), 2);

                // Desenhar os pontos de referência (landmarks)
                for (int k = 4; k < 14; k += 2) {
                    float lx = faces.at<float>(i, k);
                    float ly = faces.at<float>(i, k + 1);
                    cv::circle(frame, cv::Point(cvRound(lx), cvRound(ly)), 2, cv::Scalar(0, 0, 255), -1);
                }
            }
        }

        cv::imshow("Detecção Facial com YuNet", frame);

        if (cv::waitKey(1) == 'q') {
            break;
        }
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}
