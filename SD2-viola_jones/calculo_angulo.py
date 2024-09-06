import cv2
import math
import time


time.sleep(2)
ultimo_angulo = 0
variacao_minima = 10  # Variação mínima em graus

face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

# Inicializa a captura de vídeo (ajuste o IP/URL conforme necessário)
ip = "http://192.168.0.102:8080/video"
WebCamera = cv2.VideoCapture(0)

#REAJUSTE DE RESOLUCAO
WebCamera.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
WebCamera.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)

while True:
    conectado, img = WebCamera.read()

    if not conectado:
        print("Falha ao conectar na câmera.")
        break

    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray, 1.1, 5, minSize=(30, 30))

    for (x, y, w, h) in faces:
        cv2.rectangle(img, (x, y), (x + w, y + h), (255, 0, 0), 2)

        # Calcula o centro da face
        center_x = x + w // 2
        center_y = y + h // 2

        # Calcula o ângulo em relação ao centro da imagem (320x240)
        dx = center_x - 320
        dy = center_y - 240
        angulo_rad = math.atan2(dy, dx)
        angulo_graus = math.degrees(angulo_rad) 
        angulo_graus = abs(angulo_graus) 
        
        
        # Ajusta o ângulo para o intervalo do servo (0-180)
        #angulo_graus = (angulo_graus + 180) / 2
        
        # Envia o ângulo para o servo
        #enviar_angulo(int(angulo_servo)) 


        # Verifica se houve uma mudança significativa no ângulo
        if abs(angulo_graus - ultimo_angulo) >= variacao_minima:
            print(f"Ângulo para o servo: {angulo_graus:.2f} graus")
            #enviar_angulo(int(angulo_graus))  # Descomente para enviar via serial
            ultimo_angulo = angulo_graus
            
             

    cv2.imshow('Face Detection', img)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break


WebCamera.release()
cv2.destroyAllWindows()

