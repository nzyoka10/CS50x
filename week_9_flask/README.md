# Birthdays Application

## Overview

The Birthdays Application is a simple web-based app for managing and editing birthday entries. It allows users to add, edit, and delete birthday records stored in an SQLite database. The application is built using Flask, a lightweight Python web framework, and uses Bootstrap for styling. It also integrates SweetAlert2 for user notifications.

## Features

- **Add Birthdays**: Users can add new birthday entries including name, month, and day.
- **Edit Birthdays**: Users can update existing birthday records.
- **Delete Birthdays**: Users can delete birthday entries.
- **Notifications**: Success and error messages are displayed using SweetAlert2.
- **Responsive Design**: The app uses Bootstrap for a clean and responsive user interface.

## Installation

1. **Clone the repository**:

    ```bash
    git clone https://github.com/yourusername/birthdays-app.git
    ```

2. **Navigate to the project directory**:

    ```bash
    cd birthdays-app
    ```

3. **Create a virtual environment**:

    ```bash
    python -m venv venv
    ```

4. **Activate the virtual environment**:
    - On Windows:

      ```bash
      venv\Scripts\activate
      ```

    - On macOS/Linux:

      ```bash
      source venv/bin/activate
      ```

5. **Install the required dependencies**:

    ```bash
    pip install -r requirements.txt
    ```

6. **Set up the SQLite database**:
    - Run the Flask application to create the database and initial tables.

7. **Run the application**:

    ```bash
    flask run
    ```

    The application will be available at `http://127.0.0.1:5000`.

## File Structure

- `app.py`: The main Flask application file.
- `birthdays.db`: SQLite database file.
- `templates/`: Directory containing HTML templates.
  - `index.html`: Template for the main page showing all birthdays.
  - `edit.html`: Template for editing a specific birthday entry.
- `static/`: Directory containing static files like CSS.
  - `styles.css`: Custom CSS styles.
- `requirements.txt`: List of Python dependencies.

## Dependencies

- Flask
- CS50 Library
- Bootstrap 5
- SweetAlert2

## Usage

- **Add a Birthday**: Fill out the form on the main page and submit to add a new birthday.
- **Edit a Birthday**: Click the edit button next to a birthday entry to modify its details.
- **Delete a Birthday**: Click the delete button next to a birthday entry to remove it.


