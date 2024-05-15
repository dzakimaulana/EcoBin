void servoSteering(bool* det, int* lock_full, int* lock_blynk, int* manual) {
    if ((*det || *manual == 1) && (*lock_full == 0 && *lock_blynk == 0)) {
        servo1.write(0);
        servo2.write(90);
    } else {
        servo1.write(90);
        servo2.write(0);
    }
    delay(200);
}
