from flask import Flask, request, render_template_string
import subprocess

app = Flask(__name__)

HTML = '''
<!DOCTYPE html>
<html>
<head><title>Integrated Dining System</title></head>
<body>
<h2>Integrated Dining System</h2>
<form method="post">
    Enter command: <input type="text" name="command">
    <input type="submit" value="Run">
</form>
<pre>{{ output }}</pre>
</body>
</html>
'''

@app.route('/', methods=['GET', 'POST'])
def index():
    output = ''
    if request.method == 'POST':
        cmd = request.form['command']
        # Run your C++ program
        try:
            # Compile the C++ program
            subprocess.run(['g++', 'main.cpp', '-o', 'main'], check=True)
            # Execute the program and pass user input
            result = subprocess.run(['./main'], input=cmd.encode(), capture_output=True)
            output = result.stdout.decode()
        except Exception as e:
            output = str(e)
    return render_template_string(HTML, output=output)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=3000)
