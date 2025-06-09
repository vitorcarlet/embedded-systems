import requests
import serial
import time

# Configurações
CIDADE = "Videira"
SERIAL_PORT = "/dev/ttyACM0"  # ajuste conforme seu caso
BAUD_RATE = 115200
INTERVALO_SEGUNDOS = 300  # intervalo entre requisições (5 minutos)

def get_weather_wttr(cidade="Videira"):
    try:
        r = requests.get(f"https://wttr.in/{cidade}?format=j1", timeout=10)
        r.raise_for_status()
        data = r.json()

        temp = data["current_condition"][0]["temp_C"]
        hum  = data["current_condition"][0]["humidity"]
        chuva = data["weather"][0]["hourly"][0]["chanceofrain"]

        print(f"[OK] T={temp}°C, H={hum}%, R={chuva}%")
        return temp, hum, chuva
    except Exception as e:
        print("[ERRO] Falha ao obter dados do wttr.in:", e)
        return None, None, None

def main():
    try:
        ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=2)
        time.sleep(2)  # Aguarda Arduino resetar
        print("[INFO] Conectado à porta serial.")
    except Exception as e:
        print("[ERRO] Falha ao abrir porta serial:", e)
        return

    while True:
        temp, hum, chuva = get_weather_wttr(CIDADE)
        if temp is not None:
            # Formato: T=23.4;H=60;R=12\n
            linha = f"T={float(temp):.1f};H={hum};R={chuva}\n"
            print("[ENVIO]", linha.strip())
            try:
                ser.write(linha.encode())
            except Exception as e:
                print("[ERRO] Falha ao enviar para serial:", e)

        time.sleep(INTERVALO_SEGUNDOS)

if __name__ == "__main__":
    main()
