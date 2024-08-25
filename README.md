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

4. **Tambahkan Board ESP8266 ke Arduino IDE**:
   - Buka `File > Preferences`.
   - Pada kolom "Additional Board Manager URLs", tambahkan URL berikut: `http://arduino.esp8266.com/stable/package_esp8266com_index.json`.
   - Buka `Tools > Board > Board Manager`, cari "esp8266" dan instal paket yang ditemukan.

5. **Hubungkan Perangkat Keras**:
   - **Sensor DHT22**: Hubungkan sensor DHT22 ke ESP8266 (pin D2).
   - **Layar LCD**: Hubungkan layar I2C LCD ke ESP8266.

## Pendaftaran dan Konfigurasi ThingSpeak

1. **Daftar di ThingSpeak**:
   - Buka situs [ThingSpeak](https://thingspeak.com) dan buat akun baru atau masuk jika Anda sudah memiliki akun.

2. **Buat Channel Baru**:
   - Setelah masuk, klik "Channels" di navigasi dan pilih "New Channel".
   - Isi nama channel, deskripsi, dan tambahkan dua field: `Temperature` dan `Humidity`.
   - Simpan perubahan dengan mengklik tombol "Save Channel".

3. **Catat API Key dan Channel ID**:
   - Setelah channel dibuat, catat `Channel ID` dan `Write API Key` dari tab API Keys di halaman channel.

4. **Konfigurasi Proyek**:
   - Buka file `.ino` dan ubah variabel berikut dengan kredensial WiFi Anda dan informasi dari ThingSpeak:
     ```cpp
     const char *ssid = "Your_SSID";        // Nama jaringan WiFi Anda
     const char *pass = "Your_PASSWORD";    // Kata sandi WiFi Anda
     unsigned long myChannelNumber = YOUR_CHANNEL_NUMBER; // Nomor channel ThingSpeak Anda
     const char *myWriteAPIKey = "YOUR_API_KEY"; // Kunci API Write ThingSpeak Anda
     ```

## Unggah Kode

1. **Hubungkan ESP8266 ke Komputer**:
   - Sambungkan mikrokontroler ESP8266 Anda ke komputer menggunakan kabel USB.

2. **Pilih Board dan Port**:
   - Di Arduino IDE, buka `Tools > Board` dan pilih `NodeMCU 1.0 (ESP-12E Module)` atau board ESP8266 yang sesuai.
   - Buka `Tools > Port` dan pilih port yang sesuai dengan ESP8266 Anda.

3. **Unggah Kode**:
   - Klik tombol "Upload" di Arduino IDE untuk mengunggah kode ke ESP8266 Anda.

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
