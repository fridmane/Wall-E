# Test for I2C communication from Raspberry Pi to Arduino
#
# Note the 100ms sleep between commands is necessary for not getting the
# Arduino Stuck

import smbus
import time

# for RPI version 1, use "bus = smbus.SMBus(0)"
bus = smbus.SMBus(1)

# This is the address we setup in the Arduino Program
address = 0x04

# Utility function for converting string to bytes
def StringToBytes(val):
        retVal = []
        for c in val:
                retVal.append(ord(c))
        return retVal

# Test valid commands to Arduino
bus.write_i2c_block_data(address, ord('a'), [49, 50,51])
time.sleep(0.1)
bus.write_i2c_block_data(address, ord('m'), [65, 66,67])
time.sleep(0.1)
bus.write_i2c_block_data(address, ord('m'), [70, 71,72])
time.sleep(0.1)

# Test incorrect input
bus.write_i2c_block_data(address, ord('a'), [49, 50,51,52,53,54])
time.sleep(0.1)
bus.write_i2c_block_data(address, ord('m'), [49, 50])
