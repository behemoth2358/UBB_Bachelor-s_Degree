package com.company.Controller;

import com.company.Models.ExceptionFactory;
import com.company.Models.IStatement;
import com.company.Models.Utils.MyIStack;
import com.company.Models.ProgramState;
import com.company.Repository.Repository;
import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;

import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;
import java.util.HashMap;

public class Controller {
    private Repository repository;
    private String configFilePath;
    private HashMap<String, Object> config;

    public Controller(Repository repository, String configFilePath) {
        this.repository = repository;
        this.configFilePath = configFilePath;
        loadConfig();
    }

    private void loadConfig() {
        Gson gson = new Gson();

        try (Reader reader = new FileReader(this.configFilePath)) {

            this.config = gson.fromJson(reader, new TypeToken<HashMap<String, Object>>(){}.getType());

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public ProgramState executeOneInstruction(ProgramState program) throws Exception {
        MyIStack<IStatement> stack = program.getExeStack();

        if (stack.isEmpty()) {
            throw ExceptionFactory.create("stack", "stack is empty!");
        }

        IStatement statement = stack.pop();


        return statement.execute(program);
    }

    public void executeOne() {
        ProgramState program = this.repository.getData().get(0);

        try {
            executeOneInstruction(program);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void executeAllProgram() {
        ProgramState program = this.repository.getData().get(0);

        while(!program.getExeStack().isEmpty()) {

            try {
                executeOneInstruction(program);

                if ((boolean)this.config.get("DEBUG")) {
                    this.repository.logProgramState();
                }

            } catch (Exception e) {
                e.printStackTrace();
            }
        }

    }

}
