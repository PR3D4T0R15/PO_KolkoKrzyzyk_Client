function validatePass(pass1, pass2) {

    if (pass1 != pass2) {
        return { valid: false, message: "Has³a s¹ róŸne." };
    }

    // Sprawdzenie d³ugoœci hasla
    if (password.length < 8) {
        return { valid: false, message: "Has³o musi mieæ minimum 8 znaków." };
    }

    // Sprawdzenie obecnosci wielkiej litery
    if (!/[A-Z]/.test(password)) {
        return { valid: false, message: "Has³o musi zawieraæ wielk¹ literê." };
    }

    // Sprawdzenie obecnosci cyfry
    if (!/[0-9]/.test(password)) {
        return { valid: false, message: "Has³o musi zawieraæ cyfrê." };
    }

    // Sprawdzenie obecnosci znaku specjalnego
    if (!/[!@#$%^&*(),.?":{}|<>]/.test(password)) {
        return { valid: false, message: "Has³o musi zawieraæ znak specjalny." };
    }

    return { valid: true, message: "Has³o jest poprawne." };
}