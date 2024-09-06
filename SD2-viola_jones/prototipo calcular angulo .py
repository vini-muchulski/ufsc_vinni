import cv2
import math
import threading
import serial
import time

# Constantes
SERIAL_PORT = 'COM3'
BAUD_RATE = 9600
CAMERA_IP = 0 # "http://192.168.0.102:8080/video"
FACE_CASCADE_PATH = cv2.data.haarcascades + 'haarcascade_frontalface_default.xml'
VARIACAO_MINIMA = 10
DELAY_RECALCULO = 2
CAMERA_CENTER_X = 320
CAMERA_CENTER_Y = 240

# Variáveis globais
ultimo_angulo = 0
pode_calcular_angulo = True

def enviar_angulo(angulo):
    with serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1) as ser:
        time.sleep(2)  # Aguarda a conexão estabilizar
        angulo_str = f"{angulo}\n"
        ser.write(angulo_str.encode())
        time.sleep(2)

def sleep_without_blocking(duration):
    time.sleep(duration)

def reset_calculo_flag():
    global pode_calcular_angulo
    time.sleep(DELAY_RECALCULO)
    pode_calcular_angulo = True

def calcular_e_enviar_angulo(x, y, w, h):
    global ultimo_angulo, pode_calcular_angulo
    
    center_x = x + w // 2
    center_y = y + h // 2

    dx = center_x - CAMERA_CENTER_X
    dy = center_y - CAMERA_CENTER_Y
    angulo_rad = math.atan2(dy, dx)
    angulo_graus = abs(math.degrees(angulo_rad))
    
    if abs(angulo_graus - ultimo_angulo) >= VARIACAO_MINIMA:
        print(f"Ângulo para o servo: {angulo_graus:.2f} graus")
        enviar_angulo(int(angulo_graus))
        ultimo_angulo = angulo_graus
        
        pode_calcular_angulo = False
        threading.Thread(target=sleep_without_blocking, args=(DELAY_RECALCULO,)).start()
        threading.Thread(target=reset_calculo_flag).start()

def main():
    face_cascade = cv2.CascadeClassifier(FACE_CASCADE_PATH)
    web_camera = cv2.VideoCapture(CAMERA_IP)

    while True:
        conectado, img = web_camera.read()

        if not conectado:
            print("Falha ao conectar na câmera.")
            break

        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        faces = face_cascade.detectMultiScale(gray, 1.1, 5, minSize=(30, 30))

        if len(faces) > 0:  # Modificado esta linha
            (x, y, w, h) = faces[0]
            cv2.rectangle(img, (x, y), (x + w, y + h), (255, 0, 0), 2)

            if pode_calcular_angulo:
                calcular_e_enviar_angulo(x, y, w, h)

        cv2.imshow('Face Detection', img)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    web_camera.release()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()