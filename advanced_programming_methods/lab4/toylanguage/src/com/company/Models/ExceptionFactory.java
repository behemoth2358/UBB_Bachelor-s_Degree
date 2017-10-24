package com.company.Models;

import com.company.Models.Exceptions.*;

public class ExceptionFactory {
    public static Exception create(String type, String message) {
        if (type == null) {
            return null;
        }

        if (type.equalsIgnoreCase("expression")) {
            return new ExpressionException(message);
        }

        if (type.equalsIgnoreCase("variable")) {
            return new VariableException(message);
        }

        if (type.equalsIgnoreCase("stack")) {
            return new StackException(message);
        }

        return null;
    }
}
