======================================================
Button btn = {pin};

buttonTick(btn);

if (btn.click) {

	btn.click = 0;
}

if (btn.dbl) {

    btn.dbl = 0;
}

if (btn.press) {

    btn.press = 0;
}

if (btn.hold) {

}

if (btn.released) {

	btn.released = 0;
}
======================================================
Encoder enc = {pinRight, pinLeft, {Button(pin)}};

pinMode(enc.pinRight, INPUT_PULLUP);
pinMode(enc.pinLeft, INPUT_PULLUP);
pinMode(enc.button.pin, INPUT_PULLUP);

encoderTick(enc);

if (enc.right) {
	Keyboard.clickMultimediaKey(KEY_VOL_UP);
	enc.right = false;
}

if (enc.left) {
	Keyboard.clickMultimediaKey(KEY_VOL_DOWN);
	enc.left = false;
}

if (enc.button.click) {
	
	enc.button.click = 0;
}

if (enc.button.press) {
	
	enc.button.press = 0;
}

if (enc.button.hold) {
	
}

if (enc.button.released) {
	
	enc.button.released = 0;
}
