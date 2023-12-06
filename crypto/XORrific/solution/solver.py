enc_flag = bytes.fromhex("33c971581fac407c06a9411304ad065756ea017c17ee025354ee465a38fa465446e1")
flag = bytes.fromhex("5455437b")
key = ""

for i in range(len(flag)):
    key += format(enc_flag[i] ^ flag[i], "02x")

key = bytes.fromhex(key)
flag = ""

for i in range(len(enc_flag)):
    flag += chr(enc_flag[i] ^ key[i % len(key)])
print(flag)
