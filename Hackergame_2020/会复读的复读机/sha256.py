import hashlib;m = hashlib.sha256();s = 'import hashlib;m = hashlib.sha256();s = %r;m.update((s %% s).encode());print(m.hexdigest(),end="")';m.update((s % s).encode());print(m.hexdigest(),end="")
