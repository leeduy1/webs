// Đối tượng `Validator`
function Validator(options) {
    function getParent(element, selector) {
        while (element.parentElement) {
            if (element.parentElement.matches(selector)) {
                return element.parentElement;
            }
            element = element.parentElement
        }
    }

    var selectorRules = {};

    // Hàm thực hiện validate
    function validate(inputElement, rule) {
        var errorElement = getParent(inputElement, options.formGroupSelector).querySelector(options.errorSeclector)
        var errorMessage;

        // Lấy ra các rules của selector
        var rules = selectorRules[rule.selector];

        // Lặp qua từng rule & kiểm tra
        // Nếu có lỗi thì dừng việc kiểm
        for (var i = 0; i < rules.length; ++i) {
            switch (inputElement.type) {
                case 'radio':
                case 'checkbox':
                    errorMessage = rules[i](inputElement.value) // false
                    break;
                default:
                    errorMessage = rules[i](inputElement.value) // false
                    if (errorMessage) break;
            }

        }

        if (errorMessage) {
            errorElement.innerText = errorMessage
            inputElement.parentElement.classList.add('invalid')
        } else {
            errorElement.innerText = ''
            inputElement.parentElement.classList.remove('invalid')
        }

        return !errorMessage; // true
        // return !errorMessage;
    }

    // Lấy element của form cần validate
    var formElement = document.querySelector(options.form);
    if (formElement) {
        // Khi submit form
        formElement.onsubmit = function(e) {
            e.preventDefault();

            var isFormValid = true;

            // Lặp qua từng rules và validate
            options.rules.forEach(function(rule) {
                var inputElement = formElement.querySelector(rule.selector);
                var isValid = validate(inputElement, rule); // true
                if (!isValid) { //false
                    isFormValid = false;
                }
            });


            if (isFormValid) {
                if (typeof options.onsubmit === 'function') {
                    var enabelInputs = formElement.querySelectorAll('[name]:not(disabled)')
                    var formValues = Array.from(enabelInputs).reduce(function(values, input) {
                        values[input.name] = input.value
                        return values;
                    }, {});
                    options.onsubmit(formValues)
                }
                // trường hợp submit với hành vi mặc định
                // else {
                //     formElement.onsubmit()
                // }
            }
        }

    }

    // Lặp qua mỗi rule và xử lý (lắng nghe sự kiện blur, input, ...)
    options.rules.forEach(function(rule) {

        // Lưu lại các rules cho mỗi input
        if (Array.isArray(selectorRules[rule.selector])) {
            selectorRules[rule.selector].push(rule.test);
        } else {
            selectorRules[rule.selector] = [rule.test];
        }

        var inputElements = formElement.querySelectorAll(rule.selector);


        Array.from(inputElements).forEach(function(inputElement) {
            // Xử lý trường hợp blur khỏi input
            inputElement.onblur = function() {
                validate(inputElement, rule);
            }

            // Xử lý mỗi khi người dùng nhập vào input
            inputElement.oninput = function() {
                var errorElement = getParent(inputElement, options.formGroupSelector).querySelector(options.errorSeclector)
                errorElement.innerText = ''
                getParent(inputElement, options.formGroupSelector).classList.remove('invalid')
            }
        });
    });
}





// Định nghĩa rules
// Nguyên tắc của các rules:
// 1. Khi có lỗi => Trả ra message lỗi
// 2. Khi hợp lệ => Không trả ra cái gì cả (undefined)
Validator.isRequired = function(selector, message) {
    return {
        selector: selector,
        test: function(value) {
            return value ? undefined : message || 'Vui lòng nhập trường này'
        }
    };
}

Validator.isEmail = function(selector, message) {
    return {
        selector: selector,
        test: function(value) {
            var regex = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
            return regex.test(value) ? undefined : message || 'Trường này phải là email';
        }
    };
}

Validator.minLength = function(selector, min, message) {
    return {
        selector: selector,
        test: function(value) {
            return value.length >= min ? undefined : message || `Vui lòng nhập tối thiểu ${min} kí tự`;
        }
    };
}

Validator.isConfirmed = function(selector, getConfirmValue, message) {
    return {
        selector: selector,
        test: function(value) {
            return value === getConfirmValue() ? undefined : message || 'Giá trị nhập vào không chính xác';
        }
    }
}