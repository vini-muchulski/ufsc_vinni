import serial
import time




def enviar_angulo(angulo):
    ser = serial.Serial('COM3', 9600)
    time.sleep(2)  # Aguarda a conexão estabilizar

    angulo_str = str(angulo) + '\n'
    ser.write(angulo_str.encode())  #

    time.sleep(2)
    
    ser.close()

angulo = 120  # Ângulo que você deseja mover o servo
enviar_angulo(angulo)

