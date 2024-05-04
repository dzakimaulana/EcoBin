void servoProximity(proximityDecision* data) {
    if (data->infrared) {
        if (!data->capasitive && !data->inductive) {
            servoOrg.write(180);
            delay(5000);
            servoOrg.write(0);
        } else {
            servoNon.write(180);
            delay(5000);
            servoNon.write(0);
        }
    }
    delay(500);
}

// void servoGate() {

// }