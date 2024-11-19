// are the seats occupied?
#define passenger1_PIN 2
#define passenger2_PIN 3

String getTouchState()
{
    String state = "";

    if (digitalRead(passenger1_PIN) == HIGH)
    {
        state += "passenger1; ";
    }
    else
    {
        state += "seat 1 empty; ";
    }

    if (digitalRead(passenger2_PIN) == HIGH)
    {
        state += "passenger2; ";
    }
    else
    {
        state += "seat 2 empty; ";
    }

    state.trim();
    return state;
}
