from flask import Flask, render_template, request, render_template_string
from random import choice

app = Flask(__name__)


quotes = [
    "The perfect blossom is a rare thing. You could spend your life looking for one, and it would not be a wasted life.",
    "Perfect... They are all... perfect... ",
    "I have introduced myself. You have introduced yourself. This is a very good conversation.",
    "The Emperor could not hear my words. His army will come. For nine hundred years, my ancestors have protected our people. Now... I have failed them.",
    "When I took this, you were my enemy.",
    "You believe a man can change his destiny?",
    "In spring the snows will melt and the passes will open. Until that time, you are here.",
    "If The Emperor wishes my death, he has but to ask."
]

prefixes = ["Nobu", "Hiro", "Taka", "Kazu", "Ichi", "Gen", "Yasu"]
suffixes = ["naga", "gozen", "mura", "yoshi", "maru", "taro", "hime"]


quote_template = """
<!DOCTYPE html>
<html>
<head>
    <title>The Last Samurai</title>
    <link rel="stylesheet" href="/static/style.css">
</head>
<body>
    <h1>{name} once said:</h1>
    <p>{quote}</p>
    <div id="image-container">
        <img src="static/samurai.png" id="samurai-image" alt="Samurai Image">
    </div>
    <script src="/static/script.js"></script>
</body>
</html>
"""


@app.route('/', methods=('GET', 'POST'))
def index():
    if request.method == 'GET':
        return render_template('index.html')
    elif request.method == 'POST':
        if 'name' not in request.form:
            return render_template('index.html')
        prefix = choice(prefixes)
        suffx = choice(suffixes)
        name = request.form['name']
        name = prefix+name.lower()+suffx
        quote = choice(quotes)
        return render_template_string(quote_template.format(name=name, quote=quote))

if __name__ == '__main__':
    app.run(host='0.0.0.0', debug=False)