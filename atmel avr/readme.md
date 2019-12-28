__You need to know wich COM port (windows), or tty (linux)__
__your arduino is hooked on__

### Using avrdude to transfer code over usb to arduino
---
<pre>
avrdude -p m328P -c arduino -b 115200 -P *serial_port* -U flash:w:hexfile.hex:i
serial_port
        | windows : COMn
        | linux   : /dev/ttySn
</pre>  
