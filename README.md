# Proyek ESP8266 DHT22 ThingSpeak

Proyek ini menggunakan mikrokontroler ESP8266 untuk membaca data suhu dan kelembapan dari sensor DHT22 dan menampilkannya pada LCD. Data tersebut juga dikirim ke platform ThingSpeak untuk pemantauan jarak jauh.

## Prasyarat

Sebelum Anda dapat menjalankan proyek ini, pastikan Anda memiliki hal-hal berikut:

- **Arduino IDE**: Pastikan Arduino IDE sudah terinstal di komputer Anda.
- **Paket Board ESP8266**: Instal paket board ESP8266 di Arduino IDE.
- **Library Sensor DHT**: Instal library sensor DHT.
- **Library LiquidCrystal I2C**: Instal library LiquidCrystal I2C.
- **Library ThingSpeak**: Instal library ThingSpeak.

## Instalasi

1. **Clone atau Unduh Repository**:
   - Unduh file `.ino` dari repository ini.

2. **Buka Arduino IDE**:
   - Buka file `sketch_oct6a.ino` di Arduino IDE.

3. **Instal Library yang Diperlukan**:
   - Buka menu `Sketch > Include Library > Manage Libraries...` di Arduino IDE.
   - Cari dan instal library berikut:
     - `DHT Sensor Library by Adafruit`
     - `LiquidCrystal I2C`
     - `ThingSpeak`

4. **Hubungkan Perangkat Keras**:
   - **Sensor DHT22**: Hubungkan sensor DHT22 ke ESP8266 (pin D2).
   - **Layar LCD**: Hubungkan layar I2C LCD ke ESP8266.

5. **Konfigurasi WiFi dan ThingSpeak**:
   - Dalam file `.ino`, ubah variabel berikut dengan kredensial Anda:
     ```cpp
     const char *ssid = "Your_SSID";        // Nama jaringan WiFi Anda
     const char *pass = "Your_PASSWORD";    // Kata sandi WiFi Anda
     unsigned long myChannelNumber = YOUR_CHANNEL_NUMBER; // Nomor channel ThingSpeak Anda
     const char *myWriteAPIKey = "YOUR_API_KEY"; // Kunci API Write ThingSpeak Anda
     ```

6. **Unggah Kode**:
   - Hubungkan ESP8266 Anda ke komputer.
   - Pilih board dan port yang benar di Arduino IDE.
   - Klik tombol "Upload" untuk mengunggah kode ke ESP8266 Anda.

## Penggunaan

- Setelah kode diunggah, ESP8266 akan terhubung ke jaringan WiFi Anda.
- Sensor DHT22 akan mulai membaca suhu dan kelembapan.
- Pembacaan akan ditampilkan di LCD.
- Data juga akan dikirim ke platform ThingSpeak untuk pemantauan jarak jauh.

## Pemecahan Masalah

- **Masalah Koneksi**: Pastikan kredensial WiFi sudah benar dan ESP8266 berada dalam jangkauan jaringan WiFi Anda.
- **Pembacaan Tidak Benar**: Periksa kembali kabel sensor DHT22 dan pastikan terhubung ke pin yang benar.

## Lisensi

Proyek ini dilisensikan di bawah Lisensi MIT - lihat file [LICENSE](LICENSE) untuk detail lebih lanjut.
