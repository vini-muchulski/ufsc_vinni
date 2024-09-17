import dlib
import cv2
import numpy as np

# Carregar o detector de rostos pré-treinado
detector = dlib.get_frontal_face_detector()

# Carregar o preditor de pontos faciais (download em: http://dlib.net/files/shape_predictor_68_face_landmarks.dat.bz2)
predictor = dlib.shape_predictor('shape_predictor_68_face_landmarks.dat')

# Carregar o modelo de reconhecimento facial (download em: http://dlib.net/files/dlib_face_recognition_resnet_model_v1.dat.bz2)
face_rec_model = dlib.face_recognition_model_v1('dlib_face_recognition_resnet_model_v1.dat')

# Carregar a imagem
img = cv2.imread('imagem.jpg')
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# Detectar rostos na imagem
faces = detector(gray)

for face in faces:
    # Obter os pontos faciais
    shape = predictor(gray, face)
    
    # Calcular o embedding do rosto
    face_descriptor = face_rec_model.compute_face_descriptor(img, shape)
    face_vector = np.array(face_descriptor)
    
    # Aqui você pode comparar face_vector com embeddings conhecidos para reconhecimento

    # Desenhar um retângulo ao redor do rosto
    x, y, w, h = face.left(), face.top(), face.width(), face.height()
    cv2.rectangle(img, (x, y), (x + w, y + h), (0, 255, 0), 2)

# Exibir a imagem com os rostos detectados
cv2.imshow('Rostos Detectados', img)
cv2.waitKey(0)
cv2.destroyAllWindows()
