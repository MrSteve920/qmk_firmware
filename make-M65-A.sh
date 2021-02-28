#!/bin/bash

# Copy keymap from Internal HDD drive "D" to Custom M65a directory.
cp /mnt/d/Internal\ Documents/Personal\ Files/Mechanical\ Keyboards/M65-A/QMK\ Configuration/Custom/keymap.c ./keyboards/jc65/v32u4/keymaps/custom/keymap.c

# Copy config from Internal HDD drive "D" to Custom M65a directory.
cp /mnt/d/Internal\ Documents/Personal\ Files/Mechanical\ Keyboards/M65-A/QMK\ Configuration/Custom/config.h ./keyboards/jc65/v32u4/keymaps/custom/config.h

# Copy rules from Internal HDD drive "D" to Custom M65a directory. Need sudo because of .mk file type.
cp /mnt/d/Internal\ Documents/Personal\ Files/Mechanical\ Keyboards/M65-A/QMK\ Configuration/Custom/rules.mk ./keyboards/jc65/v32u4/keymaps/custom/rules.mk

echo "Files copied from Windows based hard drives. Running QMK compile..."

# Run make function to create firmware hex file.
make jc65/v32u4:custom

# Copy hex firmware file to Windows Desktop.
cp ./jc65_v32u4_custom.hex /mnt/c/Users/Stephen/Desktop/M65-A_custom.hex
