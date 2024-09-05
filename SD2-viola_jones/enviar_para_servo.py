import serial
import time

# Configura a comunicação serial (substitua 'COM3' pela porta onde o Arduino está conectado)


def enviar_angulo(angulo):
    ser = serial.Serial('COM3', 9600)
    time.sleep(2)  # Aguarda a conexão estabilizar

    angulo_str = str(angulo) + '\n'
    ser.write(angulo_str.encode())  # Envia o valor do ângulo como string

    time.sleep(2)
    # Lembre-se de fechar a conexão serial ao terminar
    ser.close()

angulo = 135  # Ângulo que você deseja mover o servo
enviar_angulo(angulo)

