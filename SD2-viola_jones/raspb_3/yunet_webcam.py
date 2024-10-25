import cv2 as cv
import numpy as np
import math

# Carregar o modelo YuNet
model = 'face_detection_yunet_2023mar.onnx'
input_size = (640, 640)
face_detector = cv.FaceDetectorYN.create(
    model, "", input_size, score_threshold=0.8, nms_threshold=0.3,
    top_k=5000, backend_id=cv.dnn.DNN_BACKEND_OPENCV, target_id=cv.dnn.DNN_TARGET_CPU
)

def calculate_face_angle(left_eye, right_eye):
    dx = right_eye[0] - left_eye[0]
    dy = right_eye[1] - left_eye[1]
    angle = math.atan2(dy, dx) * 180 / math.pi
    return angle

def get_face_orientation(angle):
    if abs(angle) < 10:
        return "Frente"
    elif angle < -10:
        return "Virando para a esquerda"
    else:
        return "Virando para a direita"

# Captura de vídeo da webcam
cap = cv.VideoCapture(0)

while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        print("Falha na captura de vídeo")
        break

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

            # Calcular o ângulo da face
            left_eye = landmarks[0]
            right_eye = landmarks[1]
            angle = calculate_face_angle(left_eye, right_eye)
            orientation = get_face_orientation(angle)

            # Exibir o ângulo e a orientação na imagem
            #cv.putText(frame, f"Angulo: {angle:.2f}", (x, y - 30), cv.FONT_HERSHEY_SIMPLEX, 0.7, (255, 0, 0), 2)
            cv.putText(frame, f"Orientacao: {orientation}", (x, y - 60), cv.FONT_HERSHEY_SIMPLEX, 0.7, (255, 0, 0), 2)

  
    cv.imshow('Deteccao Facial com YuNet', frame)

    if cv.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv.destroyAllWindows()