document.getElementById('submit-code').addEventListener('click', function() {
    const code = document.getElementById('code-editor').value;
    
    // Send the code to the backend (C++) for validation
    alert('Code submitted!');  // In the real game, send this to the server
});

document.getElementById('hint-btn').addEventListener('click', function() {
    alert('Hint: Check for missing semicolons!');
});

// Timer functionality (5-minute countdown)
let timeLeft = 300;
const timer = document.getElementById('timer');

const countdown = setInterval(function() {
    const minutes = Math.floor(timeLeft / 60);
    const seconds = timeLeft % 60;
    timer.innerHTML = `Time Left: ${minutes}:${seconds < 10 ? '0' + seconds : seconds}`;
    
    timeLeft--;

    if (timeLeft < 0) {
        clearInterval(countdown);
        alert('Time is up!');
    }
}, 1000);
