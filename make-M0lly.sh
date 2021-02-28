#!/bin/bash

# Copy keymap from Internal HDD drive "D" to Custom M0lly directory.
cp /mnt/d/Internal\ Documents/Personal\ Files/Mechanical\ Keyboards/M0lly/QMK\ Configuration/Custom/keymap.c ./keyboards/tkc/m0lly/keymaps/custom/keymap.c

# Copy config from Internal HDD drive "D" to Custom M65a directory.
# cp /mnt/d/Internal\ Documents/Personal\ Files/Mechanical\ Keyboards/M0lly/QMK\ Configuration/Custom/config.h ./keyboards/tkc/m0lly/keymaps/custom/config.h

# Copy rules from Internal HDD drive "D" to Custom M65a directory. Need sudo because of .mk file type.
# cp /mnt/d/Internal\ Documents/Personal\ Files/Mechanical\ Keyboards/M0lly/QMK\ Configuration/Custom/rules.mk ./keyboards/tkc/m0lly/keymaps/custom/rules.mk

echo "Files copied from Windows based hard drives. Running QMK compile..."

# Run make function to create firmware hex file.
make tkc/m0lly:custom

# Copy hex firmware file to Windows Desktop.
cp ./tkc_m0lly_custom.hex /mnt/c/Users/Stephen/Desktop/M0lly_custom.hex

echo "Copying firmware file to Windows desktop..."
