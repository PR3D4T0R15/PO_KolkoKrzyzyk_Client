function validatePass(pass1) {

    // Sprawdzenie długości hasla
    if (pass1.length < 8) {
        return { valid: false, message: "Hasło musi mieć minimum 8 znaków." };
    }

    // Sprawdzenie obecnosci wielkiej litery
    if (!/[A-Z]/.test(pass1)) {
        return { valid: false, message: "Hasło musi zawierać wielką literę." };
    }

    // Sprawdzenie obecnosci cyfry
    if (!/[0-9]/.test(pass1)) {
        return { valid: false, message: "Hasło musi zawierać cyfrę." };
    }

    // Sprawdzenie obecnosci znaku specjalnego
    if (!/[!@#$%^&*(),.?":{}|<>_-]/.test(pass1)) {
        return { valid: false, message: "Hasło musi zawierać znak specjalny." };
    }

    return { valid: true, message: "Hasło jest poprawne." };
}

function checkIfEqual(pass1, pass2) {
    if (pass1 != pass2) {
        return { valid: false, message: "Hasła są róźne." };
    }

    return { valid: true, message: "" };
}