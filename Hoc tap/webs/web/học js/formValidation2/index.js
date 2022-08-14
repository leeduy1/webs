function Validator(formSelector) {
    function getParent(element, selector) {
        while (element.parentElement) {
            if (element.parentElement.matches(selector)) {
                return element.parentElement;
            }
            element = element.parentElement
        }
    }


    var formRules = {};
    var validatorRules = {
        required: function(value) {
            return value ? undefined : 'Vui lòng nhập trường này'
        },
        email: function(value) {
            var regex = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
            return regex.test(value) ? undefined : 'Trường này phải là email';
        },
        min: function(min) {
            return function(value) {
                return value.length >= min ? undefined : `Vui lòng nhập tối thiểu ${min} kí tự`
            }
        }

    }

    var formElement = document.querySelector(formSelector)

    if (formElement) {
        var inputs = formElement.querySelectorAll('[name][rules]') // lay ra input
        for (var input of inputs) { // chay tung input
            var rules = input.getAttribute('rules').split('|') // tach ra tung mang moi input ung vs 1 mang
            for (var rule of rules) { // chay cac phan tu trong mang

                var ruleInfo;
                var isRuleHasValue = rule.includes(':')

                if (rule.includes(':')) {
                    ruleInfo = rule.split(':')
                    rule = ruleInfo[0];
                }

                var ruleFunc = validatorRules[rule];

                if (isRuleHasValue) {
                    ruleFunc = ruleFunc(ruleInfo[1]);
                }

                if (Array.isArray(formRules[input.name])) {
                    formRules[input.name].push(ruleFunc)
                } else {
                    formRules[input.name] = [ruleFunc];
                }

            }

            // Lắng nghe sự kiện để validate(blur, change)
            input.onblur = handleValidate;
            input.oninput = handleClearError;

            function handleValidate(event) {
                var rules = formRules[event.target.name]
                var errorMessage

                for (var rule of rules) {
                    if (rule(event.target.value)) {
                        errorMessage = rule(event.target.value)
                        break;
                    }
                    errorMessage = rule(event.target.value)
                }
                // rules.find(function(rule) {
                //     errorMessage = rule(event.target.value);
                //     return errorMessage
                // })
                if (errorMessage) {
                    var formGroup = getParent(event.target, '.form-group')
                    if (formGroup) {
                        formGroup.classList.add('invalid')
                        var formMessage = formGroup.querySelector('.form-message')
                        if (formMessage) {
                            formMessage.innerText = errorMessage
                        }
                    }
                }
                return !errorMessage
            }

            function handleClearError(event) {
                var formGroup = getParent(event.target, '.form-group')
                if (formGroup.classList.contains('invalid')) {
                    formGroup.classList.remove('invalid')
                    var formMessage = formGroup.querySelector('.form-message')
                    if (formMessage) {
                        formMessage.innerText = ''
                    }
                }

            }


        }
    }

    formElement.onsubmit = function(event) {
        event.preventDefault();
        var inputs = formElement.querySelectorAll('[name][rules]') // lay ra input

        var isValid = true;
        for (var input of inputs) { // chay tung input
            if (!handleValidate({ target: input })) {
                isValid = false;
            }
        }

        // khi ko co loi thi submit form
        if (isValid) {
            formElement.submit()
        }
    }
}