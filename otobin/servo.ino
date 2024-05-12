void servoSteering(bool* det, int* lock, int* manual) {
    if ((*det || *manual == 1) && *lock == 0) {
        servo.write(180);
    } else {
        servo.write(0);
    }
    delay(500);
}
