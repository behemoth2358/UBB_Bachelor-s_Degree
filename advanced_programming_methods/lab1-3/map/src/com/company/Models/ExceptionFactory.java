package com.company.Models;

import com.company.Models.Exceptions.RepositoryException;

public class ExceptionFactory {

    public static Exception create(String type, String message) {
        if (type == null) {
            return null;
        }

        if (type.equalsIgnoreCase("repository")) {
            return new RepositoryException(message);
        }

        return null;
    }
}
