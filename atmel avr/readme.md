!! You need to know wich COM port (windows), or tty (linux)
!! your arduino is hooked on

###Using avrdude to transfer code over usb to arduino
avrdude -p m328P -c arduino -b 115200 -P <serial_port>

serial_port
        | windows : COMn
        | linux   : /dev/ttySn
  
