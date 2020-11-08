async def app(scope, receive, send):
    assert scope['type'] == 'http'
    await send({
        'type': 'http.response.start',
        'status': 200,
        'headers': [
            [b'Content-Type', b'text/plain'],
            [b'Referer', scope['path'].encode()],
        ]
    })
    await send({
        'type': 'http.response.body',
        'body': b'Hello, world!',
    })
