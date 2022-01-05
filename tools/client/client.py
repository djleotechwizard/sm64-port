import requests

try:
    response = requests.get('http://127.0.0.1:8000/testGET')
    print(response.text)

    response = requests.post('http://127.0.0.1:8000/testPOST', "Test post!")
    print(response.text)
except:
    print("Failed")