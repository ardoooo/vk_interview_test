async def test_counter_get(service_client):
    response = await service_client.get('/counter')
    assert response.status == 200
    assert response.text == '1'

    response = await service_client.get('/counter')
    assert response.status == 200
    assert response.text == '2'

    response = await service_client.get('/counter')
    assert response.status == 200
    assert response.text == '3'
