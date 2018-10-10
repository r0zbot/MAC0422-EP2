#!/bin/sh

if make world; then
	cd /boot/image
	lastFile=`ls -t | head -1`
	mv $lastFile 3.1.2a
	reboot
else
	echo Deu ruim