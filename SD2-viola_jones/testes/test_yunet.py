import cv2 as cv
import numpy as np

# Carregar o modelo YuNet
model = 'face_detection_yunet_2023mar.onnx'
input_size = (640, 640)
face_detector = cv.FaceDetectorYN.create(
    model, "", input_size, score_threshold=0.8, nms_threshold=0.3,
    top_k=5000, backend_id=cv.dnn.DNN_BACKEND_OPENCV, target_id=cv.dnn.DNN_TARGET_CPU
)



# Captura de vídeo da webcam
cap = cv.VideoCapture(0)

while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        print("Falha na captura de vídeo")
        break

    # Pré-processamento (opcional)
    # frame = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
    # frame = cv.equalizeHist(frame)
    # frame = cv.cvtColor(frame, cv.COLOR_GRAY2BGR)

    # Redimensionar o frame para o tamanho de entrada
    resized_frame = cv.resize(frame, input_size)

    
    faces = face_detector.detect(resized_frame)

    if faces[1] is not None:
        for face in faces[1]:
            # Escalar as coordenadas de volta para o tamanho original
            face = face.astype(int)
            x, y, w, h = face[:4]
            x = int(x * frame.shape[1] / input_size[0])
            y = int(y * frame.shape[0] / input_size[1])
            w = int(w * frame.shape[1] / input_size[0])
            h = int(h * frame.shape[0] / input_size[1])

            # Desenhar a caixa delimitadora ao redor do rosto
            cv.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)

            # Desenhar os pontos dos olhos, nariz e boca
            landmarks = face[4:14].reshape((5, 2))
            for (lx, ly) in landmarks:
                lx = int(lx * frame.shape[1] / input_size[0])
                ly = int(ly * frame.shape[0] / input_size[1])
                cv.circle(frame, (lx, ly), 2, (0, 0, 255), -1)

           

    # Exibir o vídeo com as detecções
    cv.imshow('Detecção Facial com YuNet', frame)

    if cv.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv.destroyAllWindows()
