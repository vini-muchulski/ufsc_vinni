import cv2
import mediapipe as mp

#pip install opencv-python mediapipe

# Inicializar o Mediapipe Face Mesh
mp_face_mesh = mp.solutions.face_mesh
mp_drawing = mp.solutions.drawing_utils
face_mesh = mp_face_mesh.FaceMesh(max_num_faces=2)

# Captura de vídeo da webcam
cap = cv2.VideoCapture(0)

while cap.isOpened():
    success, frame = cap.read()
    if not success:
        print("Falha na captura de vídeo")
        break

    # Converter a imagem de BGR para RGB
    rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

    # Processar a imagem e detectar a malha facial
    results = face_mesh.process(rgb_frame)

    # Se houver rostos detectados
    if results.multi_face_landmarks:
        for face_landmarks in results.multi_face_landmarks:
            # Desenhar a malha facial
            mp_drawing.draw_landmarks(
                frame, face_landmarks, mp_face_mesh.FACEMESH_TESSELATION,
                mp_drawing.DrawingSpec(color=(0, 255, 0), thickness=1, circle_radius=1),
                mp_drawing.DrawingSpec(color=(0, 0, 255), thickness=1)
            )

    # Exibir a imagem com a malha facial desenhada
    cv2.imshow('Face Mesh', frame)

    # Se pressionar 'q', fecha a janela
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Liberar a captura de vídeo e fechar janelas
cap.release()
cv2.destroyAllWindows()
