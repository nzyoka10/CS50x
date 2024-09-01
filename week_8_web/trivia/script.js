// Wait for DOM content to load
document.addEventListener('DOMContentLoaded', function () {

    // Add event listeners for correct multiple choice buttons
    const correctAnswers = document.querySelectorAll('.correct');
    correctAnswers.forEach(button => {
        button.addEventListener('click', function () {
            button.style.backgroundColor = 'green'; // Mark button as correct
            button.parentElement.querySelector('.feedback').textContent = 'Correct!'; // Show correct feedback

            // Disable all buttons after an answer is selected
            disableAllButtons();
        });
    });

    // Add event listeners for incorrect multiple choice buttons
    const incorrectAnswers = document.querySelectorAll('.incorrect');
    incorrectAnswers.forEach(button => {
        button.addEventListener('click', function () {
            button.style.backgroundColor = 'red'; // Mark button as incorrect
            button.parentElement.querySelector('.feedback').textContent = 'Incorrect'; // Show incorrect feedback

            // Disable all buttons after an answer is selected
            disableAllButtons();
        });
    });

    // Function to disable all multiple choice buttons
    function disableAllButtons() {
        const allButtons = document.querySelectorAll('.section:nth-of-type(1) button');
        allButtons.forEach(button => button.disabled = true);
    }

    // Check free response submission
    document.querySelector('#check').addEventListener('click', function () {
        const input = document.querySelector('#freeResponse');
        const feedback = input.parentElement.querySelector('.feedback');

        // Check if the user's input matches the correct answer
        if (input.value.trim().toLowerCase() === 'switzerland') {
            input.style.backgroundColor = 'green';
            feedback.textContent = 'Correct!';
        } else {
            input.style.backgroundColor = 'red';
            feedback.textContent = 'Incorrect';
        }
    });

});

// Function to handle multiple choice check
function checkMultiChoice(event) {
    // Get the button that triggered the event
    const button = event.target;

    // Check if the button's text matches the correct answer
    if (button.innerHTML === '1 person per 6 sheep') {
        button.style.backgroundColor = 'green';
        button.parentElement.querySelector('.feedback').textContent = 'Correct Answer!';
    } else {
        button.style.backgroundColor = 'red';
        button.parentElement.querySelector('.feedback').textContent = 'Incorrect Answer.';
    }
    
    // Disable all buttons after an answer is selected
    disableAllButtons();
}

// Function to handle free response check
function checkFreeResponse(event) {
    // Get the button that triggered the event
    const button = event.target;

    // Get the input element corresponding to the button
    const input = button.parentElement.querySelector('input[type="text"]');

    // Check for the correct answer
    if (input.value.trim().toLowerCase() === 'switzerland') {
        input.style.backgroundColor = 'green';
        input.parentElement.querySelector('.feedback').textContent = 'Correct Answer!';
    } else {
        input.style.backgroundColor = 'red';
        input.parentElement.querySelector('.feedback').textContent = 'Incorrect Answer.';
    }
}
