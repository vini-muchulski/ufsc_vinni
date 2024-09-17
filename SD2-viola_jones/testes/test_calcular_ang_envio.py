import cv2
import math
import serial
import time

# Constants
SERIAL_PORT = 'COM3'
BAUD_RATE = 9600
CAMERA_IP = 0  # or "http://192.168.0.102:8080/video"
FACE_CASCADE_PATH = cv2.data.haarcascades + 'haarcascade_frontalface_default.xml'
VARIACAO_MINIMA = 10
DELAY_RECALCULO = 2  # Delay in seconds between angle recalculations
CAMERA_CENTER_X = 320
CAMERA_CENTER_Y = 240

# Global variables
ultimo_angulo = 0

def enviar_angulo(angulo, ser):
    angulo_str = f"{angulo}\n"
    ser.write(angulo_str.encode())

def calcular_e_enviar_angulo(x, y, w, h, ser):
    global ultimo_angulo
    center_x = x + w // 2
    center_y = y + h // 2

    dx = center_x - CAMERA_CENTER_X
    dy = center_y - CAMERA_CENTER_Y
    angulo_rad = math.atan2(dy, dx)
    angulo_graus = abs(math.degrees(angulo_rad))

    if abs(angulo_graus - ultimo_angulo) >= VARIACAO_MINIMA:
        print(f"Ângulo para o servo: {angulo_graus:.2f} graus")
        enviar_angulo(int(angulo_graus), ser)
        ultimo_angulo = angulo_graus

def main():
    face_cascade = cv2.CascadeClassifier(FACE_CASCADE_PATH)
    web_camera = cv2.VideoCapture(CAMERA_IP)
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
    time.sleep(2)  # Wait for the serial connection to stabilize

    last_calculation_time = 0

    while True:
        conectado, img = web_camera.read()

        if not conectado:
            print("Falha ao conectar na câmera.")
            break

        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        faces = face_cascade.detectMultiScale(gray, 1.1, 5, minSize=(30, 30))

        if len(faces) > 0:
            (x, y, w, h) = faces[0]
            cv2.rectangle(img, (x, y), (x + w, y + h), (255, 0, 0), 2)

            current_time = time.time()
            if current_time - last_calculation_time >= DELAY_RECALCULO:
                calcular_e_enviar_angulo(x, y, w, h, ser)
                last_calculation_time = current_time

        cv2.imshow('Face Detection', img)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    web_camera.release()
    ser.close()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()
