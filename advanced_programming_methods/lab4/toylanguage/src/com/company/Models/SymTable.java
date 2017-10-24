package com.company.Models;

import java.util.HashMap;

public class SymTable<K, V> extends MyDictionary<K, V> {

    public SymTable() {
        this.myDictionary = new HashMap<>();
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder("Symbol table: \n");

        for(K key : this.myDictionary.keySet()) {
            out.append(key + " = " + this.myDictionary.get(key) + "\n");
        }

        if (this.myDictionary.keySet().size() == 0) {
            out.append("dictionary is empty.\n");
        }

        return out.toString();
    }
}