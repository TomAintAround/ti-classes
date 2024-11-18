import turtle
import serial

def moveTurtle(movement: str):
    turtle.forward(10)

    if movement == b'L':
        turtle.left(10)
    elif movement == b'R':
        turtle.right(10)

def main() -> None:
    serialRead: serial = serial.Serial('/dev/ttyUSB0', baudrate=9600, timeout=0.1)
    read: str = serialRead.readline().strip()
    while read != b'X':
        moveTurtle(read)
    
    turtle.exitonclick()

if __name__ == '__main__':
    main()
