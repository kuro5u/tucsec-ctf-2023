const inputDiv = document.getElementById('inputDiv');
const outputDiv = document.getElementById('outputDiv');

let input = '';
cantype = true;

const bootSequence = `
╔══════════════════════════════╗
║========Welcome to the========║
║========Matrix Computer=======║
║============Emulator==========║
╚══════════════════════════════╝
Initializing Matrix Simulation...

Matrix Simulation Initialized.

Establishing Secure Connection...

Connection Established.

Booting up the Matrix Terminal...

Matrix Terminal is Ready.

Please enter a URL to check if it's up:`;

const lines = bootSequence.split('\n');


function typeOutput(inputString, callback) {
    const newLine = document.createElement('p');
    outputDiv.appendChild(newLine);
    newLine.textContent = '';
  
    let index = 0;
  
    function addLetter() {
      if (index < inputString.length) {
        const letter = inputString[index];
        newLine.textContent += letter;
        index++;
        setTimeout(addLetter, 1);
      } else {
        if (callback) {
          callback();
        }
      }
    }
  
    addLetter();
}

function processLinesSequentially(lines, index) {
    if (index < lines.length) {
        typeOutput(lines[index], function () {
            processLinesSequentially(lines, index + 1);
            });
        }
}

processLinesSequentially(lines, 0);



document.addEventListener('keydown', function (event) {
    const key = event.key;
    if (key.length === 1 && cantype == true){
        input += key;
    }
    else if(key === 'Enter' && input !==''){
        cantype = false;
        const newLine = document.createElement('p');
        newLine.textContent = inputDiv.textContent;
        outputDiv.appendChild(newLine);
        typeOutput('Checking ' + input + '. Please wait for the process to finish');
        input = '';
        fetch('/', {
            method: 'POST',
            body: JSON.stringify({ url: newLine.textContent }),
            headers: {
                'Content-Type': 'application/json'
            }
        })
        .then((response) => response.text())
        .then((text) => {
            typeOutput(text);
            cantype = true;
        });
    }
    else if(key === 'Backspace'){
        input = input.slice(0,-1);
    }
        inputDiv.textContent = input;
})