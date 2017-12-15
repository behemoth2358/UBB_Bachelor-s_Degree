package com.company.Models.Exceptions;

public class HeapException extends Exception {
    public HeapException(String message) {
        super("Toy language, file exception: " + message);
    }
}
