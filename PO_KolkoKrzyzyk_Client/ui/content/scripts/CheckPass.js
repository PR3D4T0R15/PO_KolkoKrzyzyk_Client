function validatePass(pass1, pass2) {

    if (pass1 != pass2) {
        return { valid: false, message: "Has�a s� r�ne." };
    }

    // Sprawdzenie d�ugo�ci hasla
    if (password.length < 8) {
        return { valid: false, message: "Has�o musi mie� minimum 8 znak�w." };
    }

    // Sprawdzenie obecnosci wielkiej litery
    if (!/[A-Z]/.test(password)) {
        return { valid: false, message: "Has�o musi zawiera� wielk� liter�." };
    }

    // Sprawdzenie obecnosci cyfry
    if (!/[0-9]/.test(password)) {
        return { valid: false, message: "Has�o musi zawiera� cyfr�." };
    }

    // Sprawdzenie obecnosci znaku specjalnego
    if (!/[!@#$%^&*(),.?":{}|<>]/.test(password)) {
        return { valid: false, message: "Has�o musi zawiera� znak specjalny." };
    }

    return { valid: true, message: "Has�o jest poprawne." };
}