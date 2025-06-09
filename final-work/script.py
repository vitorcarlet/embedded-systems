# weather_bridge.py
import time, json, requests, serial

API_KEY = 'd09f5118028c39aa21ea69a55723c0a1'
LAT, LON = '-26.922', '-49.066'
URL = (
    f"https://api.openweathermap.org/data/2.5/onecall?"
    f"lat={LAT}&lon={LON}&units=metric&exclude=minutely,alerts&appid={API_KEY}"
)

SER_PORT = '/dev/ttyACM1'        # ou '/dev/ttyUSB0' no Linux
BAUD     = 115200
INTERVAL = 300           # segundos entre consultas

def fetch():
    r = requests.get(URL, timeout=10)
    r.raise_for_status()
    j = r.json()
    t   = j["current"]["temp"]
    hum = j["current"]["humidity"]
    pop = int(j["hourly"][0]["pop"] * 100)
    return t, hum, pop

def main():
    ser = serial.Serial(SER_PORT, BAUD, timeout=2)
    time.sleep(2)        # espera o Arduino reiniciar

    while True:
        try:
            t, h, r = fetch()
            line = f"T={t:.1f};H={h};R={r}\n"
            ser.write(line.encode())
            print("Enviado:", line.strip())
        except Exception as e:
            print("Erro:", e)
        time.sleep(INTERVAL)

if __name__ == "__main__":
    main()
