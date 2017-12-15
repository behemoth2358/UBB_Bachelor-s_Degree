package com.company.Models.Expressions;

import com.company.Models.ExceptionFactory;
import com.company.Models.Expression;
import com.company.Models.ProgramState.ProgramState;

public class BooleanExpression extends Expression {
    private Expression rightSide;
    private String operator;
    private Expression leftSide;

    public BooleanExpression(Expression leftSide, String operator, Expression rightSide) {
        this.leftSide = leftSide;
        this.operator = operator;
        this.rightSide = rightSide;
    }

    @Override
    public int eval(ProgramState state) throws Exception {
        int rightSideValue = rightSide.eval(state);
        int leftSideValue = leftSide.eval(state);

        if (operator.equals("<")) {
            return (leftSideValue < rightSideValue ? 1 : 0);
        }

        if (operator.equals(">")) {
            return (leftSideValue > rightSideValue ? 1 : 0);
        }

        if (operator.equals("<=")) {
            return (leftSideValue <= rightSideValue ? 1 : 0);
        }

        if (operator.equals(">=")) {
            return (leftSideValue >= rightSideValue ? 1 : 0);
        }

        if (operator.equals("==")) {
            return (leftSideValue == rightSideValue ? 1 : 0);
        }

        if (operator.equals("!=")) {
            return (leftSideValue != rightSideValue ? 1 : 0);
        }

        return 0;
    }

    @Override
    public String toString() {
        return this.leftSide.toString() + " " + this.operator + " " + this.rightSide.toString();
    }
}
