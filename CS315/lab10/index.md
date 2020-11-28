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
➜  Wycer openssl s_client -connect www.example.org:443 -showcerts
CONNECTED(00000003)
depth=2 C = US, O = DigiCert Inc, OU = www.digicert.com, CN = DigiCert Global Root CA
verify return:1
depth=1 C = US, O = DigiCert Inc, CN = DigiCert SHA2 Secure Server CA
verify return:1
depth=0 C = US, ST = California, L = Los Angeles, O = Internet Corporation for Assigned Names and Numbers, OU = Technology, CN = www.example.org
verify return:1
---
Certificate chain
 0 s:C = US, ST = California, L = Los Angeles, O = Internet Corporation for Assigned Names and Numbers, OU = Technology, CN = www.example.org
   i:C = US, O = DigiCert Inc, CN = DigiCert SHA2 Secure Server CA
-----BEGIN CERTIFICATE-----
MIIHQDCCBiigAwIBAgIQD9B43Ujxor1NDyupa2A4/jANBgkqhkiG9w0BAQsFADBN
......
0Gs4+eH6F9h3SojmPTYkT+8KuZ9w84Mn+M8qBXUQoYoKgIjN
-----END CERTIFICATE-----
 1 s:C = US, O = DigiCert Inc, CN = DigiCert SHA2 Secure Server CA
   i:C = US, O = DigiCert Inc, OU = www.digicert.com, CN = DigiCert Global Root CA
-----BEGIN CERTIFICATE-----
MIIElDCCA3ygAwIBAgIQAf2j627KdciIQ4tyS8+8kTANBgkqhkiG9w0BAQsFADBh
......
j6tJLp07kzQoH3jOlOrHvdPJbRzeXDLz
-----END CERTIFICATE-----
 2 s:C = US, O = DigiCert Inc, OU = www.digicert.com, CN = DigiCert Global Root CA
   i:C = US, O = DigiCert Inc, OU = www.digicert.com, CN = DigiCert Global Root CA
-----BEGIN CERTIFICATE-----
MIIDrzCCApegAwIBAgIQCDvgVpBCRrGhdWrJWZHHSjANBgkqhkiG9w0BAQUFADBh
......
CAUw7C29C79Fv1C5qfPrmAESrciIxpg0X40KPMbp1ZWVbd4=
-----END CERTIFICATE-----
---
```

#### Step 2

Check $n$ (module) , $e$ (encrypt key) of the **issuer**

``` bash
➜  Wycer openssl x509 -in c1.pem -text -noout
Certificate:
    Data:
        Version: 3 (0x2)
        Serial Number:
            01:fd:a3:eb:6e:ca:75:c8:88:43:8b:72:4b:cf:bc:91
        Signature Algorithm: sha256WithRSAEncryption
        Issuer: C = US, O = DigiCert Inc, OU = www.digicert.com, CN = DigiCert Global Root CA
        Validity
            Not Before: Mar  8 12:00:00 2013 GMT
            Not After : Mar  8 12:00:00 2023 GMT
        Subject: C = US, O = DigiCert Inc, CN = DigiCert SHA2 Secure Server CA
        Subject Public Key Info:
            Public Key Algorithm: rsaEncryption
                RSA Public-Key: (2048 bit)
                Modulus:
                    00:dc:ae:58:90:4d:c1:c4:30:15:90:35:5b:6e:3c:
                    82:15:f5:2c:5c:bd:e3:db:ff:71:43:fa:64:25:80:
                    d4:ee:18:a2:4d:f0:66:d0:0a:73:6e:11:98:36:17:
                    64:af:37:9d:fd:fa:41:84:af:c7:af:8c:fe:1a:73:
                    4d:cf:33:97:90:a2:96:87:53:83:2b:b9:a6:75:48:
                    2d:1d:56:37:7b:da:31:32:1a:d7:ac:ab:06:f4:aa:
                    5d:4b:b7:47:46:dd:2a:93:c3:90:2e:79:80:80:ef:
                    13:04:6a:14:3b:b5:9b:92:be:c2:07:65:4e:fc:da:
                    fc:ff:7a:ae:dc:5c:7e:55:31:0c:e8:39:07:a4:d7:
                    be:2f:d3:0b:6a:d2:b1:df:5f:fe:57:74:53:3b:35:
                    80:dd:ae:8e:44:98:b3:9f:0e:d3:da:e0:d7:f4:6b:
                    29:ab:44:a7:4b:58:84:6d:92:4b:81:c3:da:73:8b:
                    12:97:48:90:04:45:75:1a:dd:37:31:97:92:e8:cd:
                    54:0d:3b:e4:c1:3f:39:5e:2e:b8:f3:5c:7e:10:8e:
                    86:41:00:8d:45:66:47:b0:a1:65:ce:a0:aa:29:09:
                    4e:f3:97:eb:e8:2e:ab:0f:72:a7:30:0e:fa:c7:f4:
                    fd:14:77:c3:a4:5b:28:57:c2:b3:f9:82:fd:b7:45:
                    58:9b
                Exponent: 65537 (0x10001)
        X509v3 extensions:
            X509v3 Basic Constraints: critical
                CA:TRUE, pathlen:0
            X509v3 Key Usage: critical
                Digital Signature, Certificate Sign, CRL Sign
            Authority Information Access:
                OCSP - URI:http://ocsp.digicert.com

            X509v3 CRL Distribution Points:

                Full Name:
                  URI:http://crl3.digicert.com/DigiCertGlobalRootCA.crl

                Full Name:
                  URI:http://crl4.digicert.com/DigiCertGlobalRootCA.crl

            X509v3 Certificate Policies:
                Policy: X509v3 Any Policy
                  CPS: https://www.digicert.com/CPS

            X509v3 Subject Key Identifier:
                0F:80:61:1C:82:31:61:D5:2F:28:E7:8D:46:38:B4:2C:E1:C6:D9:E2
            X509v3 Authority Key Identifier:
                keyid:03:DE:50:35:56:D1:4C:BB:66:F0:A3:E2:1B:1B:C3:97:B2:3D:D1:55

    Signature Algorithm: sha256WithRSAEncryption
         23:3e:df:4b:d2:31:42:a5:b6:7e:42:5c:1a:44:cc:69:d1:68:
         b4:5d:4b:e0:04:21:6c:4b:e2:6d:cc:b1:e0:97:8f:a6:53:09:
         cd:aa:2a:65:e5:39:4f:1e:83:a5:6e:5c:98:a2:24:26:e6:fb:
         a1:ed:93:c7:2e:02:c6:4d:4a:bf:b0:42:df:78:da:b3:a8:f9:
         6d:ff:21:85:53:36:60:4c:76:ce:ec:38:dc:d6:51:80:f0:c5:
         d6:e5:d4:4d:27:64:ab:9b:c7:3e:71:fb:48:97:b8:33:6d:c9:
         13:07:ee:96:a2:1b:18:15:f6:5c:4c:40:ed:b3:c2:ec:ff:71:
         c1:e3:47:ff:d4:b9:00:b4:37:42:da:20:c9:ea:6e:8a:ee:14:
         06:ae:7d:a2:59:98:88:a8:1b:6f:2d:f4:f2:c9:14:5f:26:cf:
         2c:8d:7e:ed:37:c0:a9:d5:39:b9:82:bf:19:0c:ea:34:af:00:
         21:68:f8:ad:73:e2:c9:32:da:38:25:0b:55:d3:9a:1d:f0:68:
         86:ed:2e:41:34:ef:7c:a5:50:1d:bf:3a:f9:d3:c1:08:0c:e6:
         ed:1e:8a:58:25:e4:b8:77:ad:2d:6e:f5:52:dd:b4:74:8f:ab:
         49:2e:9d:3b:93:34:28:1f:78:ce:94:ea:c7:bd:d3:c9:6d:1c:
         de:5c:32:f3
```

``` bash
 openssl x509 -in c1.pem -noout -pubkey > issuer-pub.pem
```

#### Step 3

extract the signature block of a certificate.

``` bash
➜  Wycer vim sign
➜  Wycer cat sign | tr -d '[:space:]:' > sign_std
➜  Wycer cat sign_std
737085ef4041a76a43d5789c7b5548e6bc6b9986bafb0d038b78fe11f029a00ccd69140bc60478b2cef087d5019dc4597a71fef06e9ec1a0b0912d1fea3d55c533050ccdc13518b06a68664cbf5621da5bd948b98c3521915ddc75d77a462c2227a66fd33a17ebbebd13c5122673c05da335896afb27d4ddaa74742e37e5013ba6d030b083d0a1c4752185b2e5fa670030a2bc53834dbfd6a883bbbcd6ed1cb31ef1580382008e9cef90f21a5fa2a306da5dbe9fda5da6e62fde588018d3f1627ba6a39faea86972638165ae8283a3b5978a9b2051ff1a3f61401e48d06b38f9e1fa17d8774a88e63d36244fef0ab99f70f38327f8cf2a057510a18a0a8088cd#
```

#### Step 4

use ASN.1 structure to extract the bpdy of the certificate.

```
➜  Wycer openssl asn1parse -i -in c0.pem -strparse 4 -out c0_body.bin -noout
➜  Wycer openssl dgst -sha256 c0_body.bin
SHA256(c0_body.bin)= 2c2a46bf245dab54ddb47298621e9629309f0e2c90c4d80d535c7d4e8ab07d29
```

#### Step 5

From step 4, we know that the hash of the certificate body is `2c2a46bf245dab54ddb47298621e9629309f0e2c90c4d80d535c7d4e8ab07d29`.

From step 2 & 3, we know that public key and signature, we decrypt the signature with public key. And use `asn1parse` to find out the decrypted hash.

``` bash
➜  Wycer echo 737085ef4041a76a43d5789c7b5548e6bc6b9986bafb0d038b78fe11f029a00ccd69140bc60478b2cef087d5019dc4597a71fef06e9ec1a0b0912d1fea3d55c533050ccdc13518b06a68664cbf5621da5bd948b98c3521915ddc75d77a462c2227a66fd33a17ebbebd13c5122673c05da335896afb27d4ddaa74742e37e5013ba6d030b083d0a1c4752185b2e5fa670030a2bc53834dbfd6a883bbbcd6ed1cb31ef1580382008e9cef90f21a5fa2a306da5dbe9fda5da6e62fde588018d3f1627ba6a39faea86972638165ae8283a3b5978a9b2051ff1a3f61401e48d06b38f9e1fa17d8774a88e63d36244fef0ab99f70f38327f8cf2a057510a18a0a8088cd  | xxd -r -p > signature.bin
➜  Wycer openssl rsautl -verify -inkey issuer-pub.pem -in signature.bin -pubin > signature-decrypted.bin
➜  Wycer openssl asn1parse -inform DER -in signature-decrypted.bin
    0:d=0  hl=2 l=  49 cons: SEQUENCE
    2:d=1  hl=2 l=  13 cons: SEQUENCE
    4:d=2  hl=2 l=   9 prim: OBJECT            :sha256
   15:d=2  hl=2 l=   0 prim: NULL
   17:d=1  hl=2 l=  32 prim: OCTET STRING      [HEX DUMP]:2C2A46BF245DAB54DDB47298621E9629309F0E2C90C4D80D535C7D4E8AB07D29
```

Noticed that the hex of hash is matched. So the certificate of example.org is valid.

> https://kulkarniamit.github.io/whatwhyhow/howto/verify-ssl-tls-certificate-signature.html

