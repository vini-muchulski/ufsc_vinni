import serial
import time

# Configura a comunicação serial (substitua 'COM3' pela porta onde o Arduino está conectado)
ser = serial.Serial('COM3', 9600)
time.sleep(2)  # Aguarda a conexão estabilizar

def enviar_angulo(angulo):
    angulo_str = str(angulo) + '\n'
    ser.write(angulo_str.encode())  # Envia o valor do ângulo como string


angulo = 180  # Ângulo que você deseja mover o servo
enviar_angulo(angulo)
time.sleep(5)
# Lembre-se de fechar a conexão serial ao terminar
ser.close()
