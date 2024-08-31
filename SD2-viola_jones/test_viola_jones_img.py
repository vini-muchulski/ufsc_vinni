import cv2
import numpy as np

#https://www.youtube.com/watch?v=JyJZRZwj1w4
#viola jones
#SD2
# Carregar o classificador de face pré-treinado
# Detectar faces na imagem
# Desenhar retângulos em torno das faces detectadas

face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')


img = cv2.imread('imagem2.jpg')
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)


faces = face_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5, minSize=(30, 30))


for i, (x, y, w, h) in enumerate(faces):
    cv2.rectangle(img, (x, y), (x+w, y+h), (255, 0, 0), 2)
    
    # Calcular o centro de massa
    center_x = x + w // 2
    center_y = y + h // 2
    
    
    print(f"Face {i+1} - Centro de massa: (x={center_x}, y={center_y})")
    
    
    cross_size = min(w, h) // 4
    cv2.line(img, (center_x - cross_size, center_y), (center_x + cross_size, center_y), (0, 255, 0), 2)
    cv2.line(img, (center_x, center_y - cross_size), (center_x, center_y + cross_size), (0, 255, 0), 2)


cv2.imshow('Face Detection', img)
cv2.waitKey(0)
cv2.destroyAllWindows()
