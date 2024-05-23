function validateUsername(username) {
    const regex = /^[A-Za-z0-9]{1,12}$/;

    if (regex.test(username)) {
        return { valid: true, message: "" };
    }
    return { valid: false, message: "Nazwa u¿ytkownika jest niepoprawna." };
}