#!/bin/bash

# Copy keymap from Internal HDD drive "D" to Custom Budget96 directory.
cp /mnt/d/Internal\ Documents/Personal\ Files/Mechanical\ Keyboards/Budget96/QMK\ Configuration/Custom/keymap.c ./keyboards/donutcables/budget96/keymaps/custom/keymap.c

# Copy config from Internal HDD drive "D" to Custom Budget96 directory.
# cp /mnt/d/Internal\ Documents/Personal\ Files/Mechanical\ Keyboards/Budget96/QMK\ Configuration/Custom/config.h ./keyboards/donutcables/budget96/keymaps/custom/config.h

# Copy rules from Internal HDD drive "D" to Custom Budget96 directory. Need sudo because of .mk file type.
# cp /mnt/d/Internal\ Documents/Personal\ Files/Mechanical\ Keyboards/Budget96/QMK\ Configuration/Custom/rules.mk ./keyboards/donutcables/budget96/keymaps/custom/rules.mk

echo "Files copied from Windows based hard drives. Running QMK compile..."

# Run make function to create firmware hex file.
make donutcables/budget96:custom

# Copy hex firmware file to Windows Desktop.
cp ./donutcables_budget96_custom.hex /mnt/c/Users/Stephen/Desktop/budget96_custom.hex
