# Lab10 for CS315

## Some info...

Author: 11711918 吴烨昌

## Tasks

### Task 1-5

<iframe  height="1800" scrolling='no' title='Fancy Animated SVG Menu' src='main.html' frameborder='no' allowtransparency='true' allowfullscreen='true' style='width: 100%;'></iframe>

### Task 6

#### Step 1

Check certifications

``` plaintext
➜  Wycer openssl s_client -connect www.bilibili.com:443 -showcerts
CONNECTED(00000003)
depth=2 OU = GlobalSign Root CA - R3, O = GlobalSign, CN = GlobalSign
verify return:1
depth=1 C = BE, O = GlobalSign nv-sa, CN = GlobalSign RSA OV SSL CA 2018
verify return:1
depth=0 C = CN, ST = \E4\B8\8A\E6\B5\B7, L = \E4\B8\8A\E6\B5\B7, O = \E4\B8\8A\E6\B5\B7\E5\B9\BB\E7\94\B5\E4\BF\A1\E6\81\AF\E7\A7\91\E6\8A\80\E6\9C\89\E9\99\90\E5\85\AC\E5\8F\B8, CN = *.bilibili.com
verify return:1
---
Certificate chain
 0 s:C = CN, ST = \E4\B8\8A\E6\B5\B7, L = \E4\B8\8A\E6\B5\B7, O = \E4\B8\8A\E6\B5\B7\E5\B9\BB\E7\94\B5\E4\BF\A1\E6\81\AF\E7\A7\91\E6\8A\80\E6\9C\89\E9\99\90\E5\85\AC\E5\8F\B8, CN = *.bilibili.com
   i:C = BE, O = GlobalSign nv-sa, CN = GlobalSign RSA OV SSL CA 2018
-----BEGIN CERTIFICATE-----
MIIGYjCCBUqgAwIBAgIMIZdGOFAcnWDaWHopMA0GCSqGSIb3DQEBCwUAMFAxCzAJ
BgNVBAYTAkJFMRkwFwYDVQQKExBHbG9iYWxTaWduIG52LXNhMSYwJAYDVQQDEx1H
bG9iYWxTaWduIFJTQSBPViBTU0wgQ0EgMjAxODAeFw0yMDA4MDcwNzE2MDZaFw0y
MjEwMTkwOTIxMDRaMHcxCzAJBgNVBAYTAkNOMQ8wDQYDVQQIDAbkuIrmtbcxDzAN
BgNVBAcMBuS4iua1tzEtMCsGA1UECgwk5LiK5rW35bm755S15L+h5oGv56eR5oqA
5pyJ6ZmQ5YWs5Y+4MRcwFQYDVQQDDA4qLmJpbGliaWxpLmNvbTCCASIwDQYJKoZI
hvcNAQEBBQADggEPADCCAQoCggEBANrOd6vZ4pklKMFMjhWsIlqKMYAPIDsdqabS
dnEloIsIQTF6f7nTEvTA1tUDv3vnVvLwW8Rpym+q1euGpwYvZyuT0nAzRUD3GEho
1E9lXJF8qmTU4jd7fmaD/rO+aSCbIF3dGgINU+gqkXqExRJmu1FswEBKnbUZOTU6
HYBVf7CFYY6lhyR8Mlk1DSwugG3xpJYdEqrJpoiQFRizxpOOSTZTINcjbFxATiOH
i59rQdJSrBhl2G/ZoEPm6UWigeJ+9YsNkdLAk5uMZRiTwd4f8oIMQ1QX6Xl9PdNr
vyvSAoqTfBOPH09igVhUgU9wg1ewR2IbgQB2PEZt5wcdqjVayPkCAwEAAaOCAxMw
ggMPMA4GA1UdDwEB/wQEAwIFoDCBjgYIKwYBBQUHAQEEgYEwfzBEBggrBgEFBQcw
AoY4aHR0cDovL3NlY3VyZS5nbG9iYWxzaWduLmNvbS9jYWNlcnQvZ3Nyc2FvdnNz
bGNhMjAxOC5jcnQwNwYIKwYBBQUHMAGGK2h0dHA6Ly9vY3NwLmdsb2JhbHNpZ24u
Y29tL2dzcnNhb3Zzc2xjYTIwMTgwVgYDVR0gBE8wTTBBBgkrBgEEAaAyARQwNDAy
BggrBgEFBQcCARYmaHR0cHM6Ly93d3cuZ2xvYmFsc2lnbi5jb20vcmVwb3NpdG9y
eS8wCAYGZ4EMAQICMAkGA1UdEwQCMAAwJwYDVR0RBCAwHoIOKi5iaWxpYmlsaS5j
b22CDGJpbGliaWxpLmNvbTAdBgNVHSUEFjAUBggrBgEFBQcDAQYIKwYBBQUHAwIw
HwYDVR0jBBgwFoAU+O9/8s14Z6jeb48kjYjxhwMCs+swHQYDVR0OBBYEFA3bh7X3
xVcYKx9xVhlkGt7DyRIGMIIBfwYKKwYBBAHWeQIEAgSCAW8EggFrAWkAdgBvU3as
MfAxGdiZAKRRFf93FRwR2QLBACkGjbIImjfZEwAAAXPHxutKAAAEAwBHMEUCIQDk
BVIt2jkljV9j7d2iAZZG/FPF7S89gKORcY2dmLoM8QIgbn94gRxBtL57+CLOtI29
7ntK0Si2VOgevuQ6ApZymmkAdgBGpVXrdfqRIDC1oolp9PN9ESxBdL79SbiFq/L8
cP5tRwAAAXPHxus6AAAEAwBHMEUCIQC6g30Cs55ncRXgaKikP+GKN/VaLGoO+8uJ
l9mfBlI/mQIgHxHuoTEg7vRQcyeSaEDGrKYsWziybzWxy5KD7zAifMMAdwBRo7D1
/QF5nFZtuDd4jwykeswbJ8v3nohCmg3+1IsF5QAAAXPHxusvAAAEAwBIMEYCIQDA
Jndt3eZC88LqlCU8blkkiokB6vUWvb1K4yNsmciDyQIhAMgHRr4jQyTnxuj+IiRm
BPJkC/F+SX6HJlmjtOXqOO6aMA0GCSqGSIb3DQEBCwUAA4IBAQAlfcuhFPYFupXM
eC4nVtqYMOvrlwejUeBZewTs28Oyb+A4OPaMCqonqepoX+36rjOgPxpK2ksJOMDL
1xALUh6EEbYRrl1SmwEPZ5AbIEVRTA3iuLJhf2xPy7uId71DiIhxY9nY7QM3lW1j
++Dk1S69FQg/CX/M8Bn8qx/hTvCnBdV30kt3R83SBDRAAg7FC9keAIkZfxkuPEEW
5msLHcINbAzyOQ5lkfx7dP8X6V/PLB3cG23cz8AIK+JOuwnQ5oUapz8U0zFgqGzP
q8N1d9fhaAMfX9gfMhUOz37DqXoRzV0Fz9Zl4zfp4tfWGpe9Gmsezd/5h0DJ/wE6
s064/1US
-----END CERTIFICATE-----
 1 s:C = BE, O = GlobalSign nv-sa, CN = GlobalSign RSA OV SSL CA 2018
   i:OU = GlobalSign Root CA - R3, O = GlobalSign, CN = GlobalSign
-----BEGIN CERTIFICATE-----
MIIETjCCAzagAwIBAgINAe5fIh38YjvUMzqFVzANBgkqhkiG9w0BAQsFADBMMSAw
HgYDVQQLExdHbG9iYWxTaWduIFJvb3QgQ0EgLSBSMzETMBEGA1UEChMKR2xvYmFs
U2lnbjETMBEGA1UEAxMKR2xvYmFsU2lnbjAeFw0xODExMjEwMDAwMDBaFw0yODEx
MjEwMDAwMDBaMFAxCzAJBgNVBAYTAkJFMRkwFwYDVQQKExBHbG9iYWxTaWduIG52
LXNhMSYwJAYDVQQDEx1HbG9iYWxTaWduIFJTQSBPViBTU0wgQ0EgMjAxODCCASIw
DQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAKdaydUMGCEAI9WXD+uu3Vxoa2uP
UGATeoHLl+6OimGUSyZ59gSnKvuk2la77qCk8HuKf1UfR5NhDW5xUTolJAgvjOH3
idaSz6+zpz8w7bXfIa7+9UQX/dhj2S/TgVprX9NHsKzyqzskeU8fxy7quRU6fBhM
abO1IFkJXinDY+YuRluqlJBJDrnw9UqhCS98NE3QvADFBlV5Bs6i0BDxSEPouVq1
lVW9MdIbPYa+oewNEtssmSStR8JvA+Z6cLVwzM0nLKWMjsIYPJLJLnNvBhBWk0Cq
o8VS++XFBdZpaFwGue5RieGKDkFNm5KQConpFmvv73W+eka440eKHRwup08CAwEA
AaOCASkwggElMA4GA1UdDwEB/wQEAwIBhjASBgNVHRMBAf8ECDAGAQH/AgEAMB0G
A1UdDgQWBBT473/yzXhnqN5vjySNiPGHAwKz6zAfBgNVHSMEGDAWgBSP8Et/qC5F
JK5NUPpjmove4t0bvDA+BggrBgEFBQcBAQQyMDAwLgYIKwYBBQUHMAGGImh0dHA6
Ly9vY3NwMi5nbG9iYWxzaWduLmNvbS9yb290cjMwNgYDVR0fBC8wLTAroCmgJ4Yl
aHR0cDovL2NybC5nbG9iYWxzaWduLmNvbS9yb290LXIzLmNybDBHBgNVHSAEQDA+
MDwGBFUdIAAwNDAyBggrBgEFBQcCARYmaHR0cHM6Ly93d3cuZ2xvYmFsc2lnbi5j
b20vcmVwb3NpdG9yeS8wDQYJKoZIhvcNAQELBQADggEBAJmQyC1fQorUC2bbmANz
EdSIhlIoU4r7rd/9c446ZwTbw1MUcBQJfMPg+NccmBqixD7b6QDjynCy8SIwIVbb
0615XoFYC20UgDX1b10d65pHBf9ZjQCxQNqQmJYaumxtf4z1s4DfjGRzNpZ5eWl0
6r/4ngGPoJVpjemEuunl1Ig423g7mNA2eymw0lIYkN5SQwCuaifIFJ6GlazhgDEw
fpolu4usBCOmmQDo8dIm7A9+O4orkjgTHY+GzYZSR+Y0fFukAj6KYXwidlNalFMz
hriSqHKvoflShx8xpfywgVcvzfTO3PYkz6fiNJBonf6q8amaEsybwMbDqKWwIX7e
SPY=
-----END CERTIFICATE-----
 2 s:OU = GlobalSign Root CA - R3, O = GlobalSign, CN = GlobalSign
   i:C = BE, O = GlobalSign nv-sa, OU = Root CA, CN = GlobalSign Root CA
-----BEGIN CERTIFICATE-----
MIIETjCCAzagAwIBAgINAe5fFp3/lzUrZGXWajANBgkqhkiG9w0BAQsFADBXMQsw
CQYDVQQGEwJCRTEZMBcGA1UEChMQR2xvYmFsU2lnbiBudi1zYTEQMA4GA1UECxMH
Um9vdCBDQTEbMBkGA1UEAxMSR2xvYmFsU2lnbiBSb290IENBMB4XDTE4MDkxOTAw
MDAwMFoXDTI4MDEyODEyMDAwMFowTDEgMB4GA1UECxMXR2xvYmFsU2lnbiBSb290
IENBIC0gUjMxEzARBgNVBAoTCkdsb2JhbFNpZ24xEzARBgNVBAMTCkdsb2JhbFNp
Z24wggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDMJXaQeQZ4Ihb1wIO2
hMoonv0FdhHFrYhy/EYCQ8eyip0EXyTLLkvhYIJG4VKrDIFHcGzdZNHr9SyjD4I9
DCuul9e2FIYQebs7E4B3jAjhSdJqYi8fXvqWaN+JJ5U4nwbXPsnLJlkNc96wyOkm
DoMVxu9bi9IEYMpJpij2aTv2y8gokeWdimFXN6x0FNx04Druci8unPvQu7/1PQDh
BjPogiuuU6Y6FnOM3UEOIDrAtKeh6bJPkC4yYOlXy7kEkmho5TgmYHWyn3f/kRTv
riBJ/K1AFUjRAjFhGV64l++td7dkmnq/X8ET75ti+w1s4FRpFqkD2m7pg5NxdsZp
hYIXAgMBAAGjggEiMIIBHjAOBgNVHQ8BAf8EBAMCAQYwDwYDVR0TAQH/BAUwAwEB
/zAdBgNVHQ4EFgQUj/BLf6guRSSuTVD6Y5qL3uLdG7wwHwYDVR0jBBgwFoAUYHtm
GkUNl8qJUC99BM00qP/8/UswPQYIKwYBBQUHAQEEMTAvMC0GCCsGAQUFBzABhiFo
dHRwOi8vb2NzcC5nbG9iYWxzaWduLmNvbS9yb290cjEwMwYDVR0fBCwwKjAooCag
JIYiaHR0cDovL2NybC5nbG9iYWxzaWduLmNvbS9yb290LmNybDBHBgNVHSAEQDA+
MDwGBFUdIAAwNDAyBggrBgEFBQcCARYmaHR0cHM6Ly93d3cuZ2xvYmFsc2lnbi5j
b20vcmVwb3NpdG9yeS8wDQYJKoZIhvcNAQELBQADggEBACNw6c/ivvVZrpRCb8RD
M6rNPzq5ZBfyYgZLSPFAiAYXof6r0V88xjPy847dHx0+zBpgmYILrMf8fpqHKqV9
D6ZX7qw7aoXW3r1AY/itpsiIsBL89kHfDwmXHjjqU5++BfQ+6tOfUBJ2vgmLwgtI
fR4uUfaNU9OrH0Abio7tfftPeVZwXwzTjhuzp3ANNyuXlava4BJrHEDOxcd+7cJi
WOx37XMiwor1hkOIreoTbv3Y/kIvuX1erRjvlJDKPSerJpSZdcfL03v3ykzTr1Eh
kluEfSufFT90y1HonoMOFm8b50bOI7355KKL0jlrqnkckSziYSQtjipIcJDEHsXo
4HA=
-----END CERTIFICATE-----
---
Server certificate
......
```

Store first and second certificate to `c0.pem` and `c1.pem`

#### Step 2

Find $n$(module) , $e$ (encrypt key) of the **issuer**

``` bash
➜  Wycer openssl x509 -in c1.pem -noout -modulus
Modulus=A75AC9D50C18210023D5970FEBAEDD5C686B6B8F5060137A81CB97EE8E8A61944B2679F604A72AFBA4DA56BBEEA0A4F07B8A7F551F4793610D6E71513A2524082F8CE1F789D692CFAFB3A73F30EDB5DF21AEFEF54417FDD863D92FD3815A6B5FD347B0ACF2AB3B24794F1FC72EEAB9153A7C184C69B3B52059095E29C363E62E465BAA9490490EB9F0F54AA1092F7C344DD0BC00C506557906CEA2D010F14843E8B95AB59555BD31D21B3D86BEA1EC0D12DB2C9924AD47C26F03E67A70B570CCCD272CA58C8EC2183C92C92E736F0610569340AAA3C552FBE5C505D669685C06B9EE5189E18A0E414D9B92900A89E9166BEFEF75BE7A46B8E3478A1D1C2EA74F
```

``` bash
➜  Wycer openssl x509 -in c1.pem -text -noout | grep Exponent
                Exponent: 65537 (0x10001)
```

#### Step 3

extract the signature block of a certificate.

``` bash
➜  Wycer openssl x509 -in c0.pem -text -noout
Certificate:
......
    Signature Algorithm: sha256WithRSAEncryption
         25:7d:cb:a1:14:f6:05:ba:95:cc:78:2e:27:56:da:98:30:eb:
         eb:97:07:a3:51:e0:59:7b:04:ec:db:c3:b2:6f:e0:38:38:f6:
         8c:0a:aa:27:a9:ea:68:5f:ed:fa:ae:33:a0:3f:1a:4a:da:4b:
         09:38:c0:cb:d7:10:0b:52:1e:84:11:b6:11:ae:5d:52:9b:01:
         0f:67:90:1b:20:45:51:4c:0d:e2:b8:b2:61:7f:6c:4f:cb:bb:
         88:77:bd:43:88:88:71:63:d9:d8:ed:03:37:95:6d:63:fb:e0:
         e4:d5:2e:bd:15:08:3f:09:7f:cc:f0:19:fc:ab:1f:e1:4e:f0:
         a7:05:d5:77:d2:4b:77:47:cd:d2:04:34:40:02:0e:c5:0b:d9:
         1e:00:89:19:7f:19:2e:3c:41:16:e6:6b:0b:1d:c2:0d:6c:0c:
         f2:39:0e:65:91:fc:7b:74:ff:17:e9:5f:cf:2c:1d:dc:1b:6d:
         dc:cf:c0:08:2b:e2:4e:bb:09:d0:e6:85:1a:a7:3f:14:d3:31:
         60:a8:6c:cf:ab:c3:75:77:d7:e1:68:03:1f:5f:d8:1f:32:15:
         0e:cf:7e:c3:a9:7a:11:cd:5d:05:cf:d6:65:e3:37:e9:e2:d7:
         d6:1a:97:bd:1a:6b:1e:cd:df:f9:87:40:c9:ff:01:3a:b3:4e:
         b8:ff:55:12
➜  Wycer vim signature
➜  Wycer cat signature | tr -d '[:space:]:' > sign_std
➜  Wycer cat sign_std
257dcba114f605ba95cc782e2756da9830ebeb9707a351e0597b04ecdbc3b26fe03838f68c0aaa27a9ea685fedfaae33a03f1a4ada4b0938c0cbd7100b521e8411b611ae5d529b010f67901b2045514c0de2b8b2617f6c4fcbbb8877bd4388887163d9d8ed0337956d63fbe0e4d52ebd15083f097fccf019fcab1fe14ef0a705d577d24b7747cdd2043440020ec50bd91e0089197f192e3c4116e66b0b1dc20d6c0cf2390e6591fc7b74ff17e95fcf2c1ddc1b6ddccfc0082be24ebb09d0e6851aa73f14d33160a86ccfabc37577d7e168031f5fd81f32150ecf7ec3a97a11cd5d05cfd665e337e9e2d7d61a97bd1a6b1ecddff98740c9ff013ab34eb8ff5512
```

#### Step 4

use ASN.1 structure to extract the bpdy of the certificate.

```
➜  Wycer openssl asn1parse -i -in c0.pem -strparse 4 -out c0_body.bin -noout
➜  Wycer openssl dgst -sha256 c0_body.bin
SHA256(c0_body.bin)= b4a346a7e966ff17ff6d2a1e8673843e9bc424122a26f7600e652ba861c17928
```

#### Step 5

From step 4, we know that the hash of the certificate body is `b4a346a7e966ff17ff6d2a1e8673843e9bc424122a26f7600e652ba861c17928`.

From step 2 & 3, we know that public key and signature, we decrypt the signature with public key. And use `asn1parse` to find out the decrypted hash.

``` python

def QuickPower(a, n, p): # 快速幂算法
    tmp = a
    ret = 1
    while n > 0:
        if n&1:
            ret = (ret * tmp) % p
        tmp = (tmp * tmp) % p
        n>>=1
    return ret
n = 0xA75AC9D50C18210023D5970FEBAEDD5C686B6B8F5060137A81CB97EE8E8A61944B2679F604A72AFBA4DA56BBEEA0A4F07B8A7F551F4793610D6E71513A2524082F8CE1F789D692CFAFB3A73F30EDB5DF21AEFEF54417FDD863D92FD3815A6B5FD347B0ACF2AB3B24794F1FC72EEAB9153A7C184C69B3B52059095E29C363E62E465BAA9490490EB9F0F54AA1092F7C344DD0BC00C506557906CEA2D010F14843E8B95AB59555BD31D21B3D86BEA1EC0D12DB2C9924AD47C26F03E67A70B570CCCD272CA58C8EC2183C92C92E736F0610569340AAA3C552FBE5C505D669685C06B9EE5189E18A0E414D9B92900A89E9166BEFEF75BE7A46B8E3478A1D1C2EA74F
S = 0x257dcba114f605ba95cc782e2756da9830ebeb9707a351e0597b04ecdbc3b26fe03838f68c0aaa27a9ea685fedfaae33a03f1a4ada4b0938c0cbd7100b521e8411b611ae5d529b010f67901b2045514c0de2b8b2617f6c4fcbbb8877bd4388887163d9d8ed0337956d63fbe0e4d52ebd15083f097fccf019fcab1fe14ef0a705d577d24b7747cdd2043440020ec50bd91e0089197f192e3c4116e66b0b1dc20d6c0cf2390e6591fc7b74ff17e95fcf2c1ddc1b6ddccfc0082be24ebb09d0e6851aa73f14d33160a86ccfabc37577d7e168031f5fd81f32150ecf7ec3a97a11cd5d05cfd665e337e9e2d7d61a97bd1a6b1ecddff98740c9ff013ab34eb8ff5512
e = 65537

d = QuickPower(S, e, n)

print(hex(d))
# 0x1ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff003031300d060960864801650304020105000420b4a346a7e966ff17ff6d2a1e8673843e9bc424122a26f7600e652ba861c17928
```

It ends with the same hash of the certificate body. So it's verified.