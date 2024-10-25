import cv2 as cv
import numpy as np

# Carregar o modelo YuNet
model = 'face_detection_yunet_2023mar.onnx'
input_size = (320, 320)  # Tamanho de entrada do modelo

# Criar o detector de faces usando o modelo YuNet
face_detector = cv.FaceDetectorYN.create(
    model, "", input_size, score_threshold=0.9, nms_threshold=0.3,
    top_k=5000, backend_id=cv.dnn.DNN_BACKEND_OPENCV, target_id=cv.dnn.DNN_TARGET_CPU
)

# Definir o endereço da ESP32-CAM
ip = 'http://192.168.0.191'
stream_url = f"{ip}:81/stream"
cap = cv.VideoCapture(stream_url)

if not cap.isOpened():
    print("Não foi possível conectar ao stream da ESP32-CAM")
    exit()

# Configurar o tamanho do frame da captura de vídeo
ret, frame = cap.read()
if not ret:
    print("Falha na captura de vídeo")
    exit()

frame_height, frame_width = frame.shape[:2]
face_detector.setInputSize((frame_width, frame_height))

while True:
    ret, frame = cap.read()
    if not ret:
        print("Falha na captura de vídeo")
        break

    # Converter o frame para o espaço de cores adequado (se necessário)
    # frame = cv.cvtColor(frame, cv.COLOR_BGR2RGB)

    # Executar a detecção de faces
    faces = face_detector.detect(frame)

    if faces[1] is not None:
        for face in faces[1]:
            # Extrair as coordenadas da caixa delimitadora
            x, y, w, h = face[:4].astype(int)

            # Desenhar a caixa delimitadora ao redor do rosto
            cv.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)

            # Desenhar os pontos dos olhos, nariz e boca
            landmarks = face[4:14].reshape((5, 2)).astype(int)
            for (lx, ly) in landmarks:
                cv.circle(frame, (lx, ly), 2, (0, 0, 255), -1)

    # Exibir o vídeo com as detecções
    cv.imshow('Deteccaoo Facial com YuNet', frame)

    # Sair do loop ao pressionar a tecla 'q'
    if cv.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv.destroyAllWindows()
