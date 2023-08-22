import binascii
with open('model.pb', "rb") as f:
    print(binascii.b2a_base64(f.read(), newline=False))
