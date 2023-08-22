from iris import Iris

app = Iris()

app.static('.')

app.listen()
