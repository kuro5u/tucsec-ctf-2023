from flask import Flask, render_template, request, Response
from random import choice
import subprocess
import json

app = Flask(__name__)


def check_website_availability(url):
    curl_command = f'curl -s -o /dev/null -w "%{{http_code}}" -L {url}'
    output = subprocess.run(curl_command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

    if output.stdout != '200':
        return f'{url} is DOWN' + output.stderr
    else:
        return f'{url} is UP' + output.stderr


@app.route('/', methods=('GET', 'POST'))
def index():
    if request.method == 'GET':
        return render_template('index.html')
    elif request.method == 'POST':
        return Response(check_website_availability(request.json['url']), status=200)


if __name__ == '__main__':
    app.run(host='0.0.0.0', port=1337, debug=False)
