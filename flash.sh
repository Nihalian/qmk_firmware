#!/bin/bash
echo "Flashing..."

cd ~/qmk/qmk_firmware
qmk compile
cp ./annepro2_c18_Nihalian.bin /mnt/e/QMK/AnnePro2-Tools/target/release/
/mnt/e/QMK/AnnePro2-Tools/target/release/annepro2_tools.exe annepro2_c18_Nihalian.bin

