function Validator(options) {


    var selectorRules = {};

    function validate(inputElement, rule) {
        var errorElement = inputElement.closest(options.formGroupSelector).querySelector(options.errorSelector)
        var errorMessage;

        var rules = selectorRules[rule.selector]

        for (var i = 0; i < rules.length; ++i) {
            errorMessage = rules[i](inputElement.value)
            if (errorMessage) break;
        }

        if (errorMessage) {
            errorElement.innerText = errorMessage;
            inputElement.closest(options.formGroupSelector).classList.add('invalid')
        }
        return !errorMessage;
    }
    var formElement = document.querySelector(options.form)
    if (formElement) {
        //khi submit form
        formElement.onsubmit = function(e) {
            e.preventDefault();

            var isFormValid = true;
            options.rules.forEach(function(rule) {
                var inputElement = formElement.querySelector(rule.selector);
                var isValid = validate(inputElement, rule);
                if (!isValid) {
                    isFormValid = false;
                }
            })

            if (isFormValid) {
                if (typeof options.onSubmit === 'function') {
                    var enableInputs = formElement.querySelectorAll('[name]')
                    var formValues = Array.from(enableInputs).reduce(function(values, input) {
                        values[input.name] = input.value
                        return values
                    }, {})
                }
                options.onSubmit(formValues);
            } else {
                formElement.submit();
            }
        }


        options.rules.forEach(function(rule) {
            if (Array.isArray(selectorRules[rule.selector])) {
                selectorRules[rule.selector].push(rule.test)
            } else {
                selectorRules[rule.selector] = [rule.test]
            }
            var inputElements = formElement.querySelectorAll(rule.selector)
            Array.from(inputElements).forEach(function(inputElement) {
                var errorElement = inputElement.closest(options.formGroupSelector).querySelector(options.errorSelector)
                inputElement.onblur = function() {
                    validate(inputElement, rule);
                }
                inputElement.oninput = function() {
                    errorElement.innerText = '';
                    inputElement.closest(options.formGroupSelector).classList.remove('invalid')
                }
            })
        })
    }
}


Validator.isRequired = function(selector, message) {
    return {
        selector: selector,
        test: function(value) {
            return value ? undefined : message
        }
    };
}

Validator.minLength = function(selector, length, message) {
    return {
        selector: selector,
        test: function(value) {
            return value.length >= length ? undefined : message
        }
    }
}

Validator.capitalFirst = function(selector, message) {
    return {
        selector: selector,
        test: function(value) {
            var regexp = /^[A-Z]/;
            return regexp.test(value) ? undefined : message
        }
    }
}

Validator.specialCharacters = function(selector, message) {
    return {
        selector: selector,
        test: function(value) {
            var format = /[`!@#$%^&*()_+\-=\[\]{};':"\\|,.<>\/?~]/;
            return format.test(value) ? undefined : message
        }
    }
}

Validator.number = function(selector, message) {
    return {
        selector: selector,
        test: function(value) {
            return /\d/.test(value) ? undefined : message
        }
    }
}

Validator.alphabeticCharacters = function(selector, message) {
    return {
        selector: selector,
        test: function(value) {
            var format = /[a-z]/;
            return format.test(value) ? undefined : message
        }
    }
}

