bool isNumber(const char *s) {
    enum InputType {
        INVALID,        // 0
        SPACE,          // 1
        SIGN,           // 2
        DIGIT,          // 3
        DOT,            // 4
        EXPONENT        // 5
    };

    const int kNumInputs = 6;
    int transition_table[][kNumInputs] = {
        -1,  0,  3,  1,  2, -1,     //next states for state 0
        -1,  8, -1,  1,  4,  5,      //state 1
        -1, -1, -1,  4, -1, -1,
        -1, -1, -1,  1,  2, -1, 
        -1,  8, -1,  4, -1,  5, 
        -1, -1,  6,  7, -1, -1, 
        -1, -1, -1,  7, -1, -1, 
        -1,  8, -1,  7, -1, -1, 
        -1,  8, -1, -1, -1, -1
    };

    int state = 0;
    for (; *s != '\0'; ++s) {
        InputType input_type = INVALID;
        if (isspace(*s)) {
            input_type = SPACE;
        }
        else if ('-' == *s || '+' == *s) {
            input_type = SIGN;
        }
        else if (isdigit(*s)) {
            input_type = DIGIT;
        }
        else if ('.' == *s) {
            input_type = DOT;
        }
        else if ('e' == *s || 'E' == *s) {
            input_type = EXPONENT;
        }

        state = transition_table[state][input_type];
        if (-1 == state) return false;
    }

    return 1 == state || 4 == state || 7 == state || 8 == state;
    



}
