############################################################
#    This file is for creating a running Flask server,
#       used to respond to an API request that starts
#               a minigame on a raspberry PI.
#
#                        Authors:
#                      Lauren Dziak
#                       Brock Fisher
#                       Sam Fales
#
#
############################################################
#imports
from flask import Flask
from gpiozero import LED
import RPi.GPIO as GPIO
from time import sleep

#Globals
app = Flask('server')


#methods

def test_game():
    led = LED(17)

    GPIO.setnode(GPIO.BCM)
    GPIO.setup(7, GPIO.IN)

    pressure = GPIO.input(7)

    while True:
        if (pressure ==0):
            led.off()
        else:
            led.on()
        sleep(0.5)
def final_game():
    led = LED(17)

    GPIO.setnode(GPIO.BCM)
    GPIO.setup(7, GPIO.IN)

    print("Please place finger on sensor and release when the LED lights up!")
    delay = random.randint(0,9)
    led.off()
    test = True
    while test:
        pressure = GPIO.input(7)
        if (pressure == 0):
            sleep(0.5)
            continue
        else:
            print("The reaction test will begin in 3")
            for x in range(2, 0, -1):
                print(x)
                sleep(1)
            print("0")
            sleep(delay)
            start_reaction_time = datetime.time()
            led.on()
            final_reaction_time = datetime.time()
            result = final_reaction_time - start_reaction_time()





if __name__ == '__main__':
  #  test_game()
    final_game()
    exit
