#!/usr/bin/python3
"""
Use requests package to make a get request to the github api.
First argument is username, second argument is password.
"""
import sys
import requests
from requests.auth import HTTPBasicAuth

if __name__ == "__main__":
    auth = HTTPBasicAuth(sys.argv[1], sys.argv[2])
    r = requests.get("http://:api.github.com/user", auth=auth)
    print(r.json().get("id"))
    
