package com.company.Controller;

import com.company.Models.ExceptionFactory;
import com.company.Models.Expressions.ConstantExpression;
import com.company.Models.IStatement;
import com.company.Models.Statements.CloseFileStatement;
import com.company.Models.Tables.HeapTable;
import com.company.Utils.MyIDictionary;
import com.company.Utils.MyIStack;
import com.company.Models.ProgramState.ProgramState;
import com.company.Repository.Repository;
import com.company.Utils.Pair;

import java.io.BufferedReader;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class Controller {
    private Repository repository;
    private final ExecutorService executor = Executors.newFixedThreadPool(10);

    public Controller(Repository repository) {
        this.repository = repository;
    }

    private HashMap<Integer, Integer> garbageCollector(
            Collection<Integer> symTableValues, HashMap<Integer, Integer> heapTable) {

        HashMap<Integer, Integer> newHeapTable = new HashMap<>();

        for(Integer key: heapTable.keySet()) {
            if (symTableValues.contains(key)) {
                newHeapTable.put(key, heapTable.get(key));
            }
        }

        return newHeapTable;
    }

    public void executeOneStepForAllPrograms(List<ProgramState> programs) throws InterruptedException {
        List<Callable<ProgramState>> callList = programs.stream()
                .map((ProgramState p) -> (Callable<ProgramState>)(p::executeOneInstruction))
                .collect(Collectors.toList());

        List<ProgramState> newProgramStates = this.executor.invokeAll(callList).stream()
                .map(future -> {
                    try {
                        return future.get();
                    } catch (Exception e) {
                        return null;
                    }
                }).filter(Objects::nonNull)
                .collect(Collectors.toList());

        programs.addAll(newProgramStates);

        programs.forEach(p -> {
            try {
                this.repository.logProgramState(p);
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
    }

    public Set<Integer> mergeSymTableValues(List<ProgramState> programs) {
        Set<Integer> result = new HashSet<Integer>();

        programs.stream().forEach(p -> result.addAll(p.getSymTable().getMyDictionary().values()));

        return result;
    }

    public void executeAllProgram() {
        List<ProgramState> programs = this.repository.getData();
        HeapTable heapTable = programs.get(0).getHeapTable();
        MyIDictionary<Integer, Pair<String, BufferedReader>>fileTable = programs.get(0).getFileTable();

        while(!programs.isEmpty()) {
            try {
                executeOneStepForAllPrograms(programs);
                programs = programs.stream().filter(p -> p.isNotCompleted()).collect(Collectors.toList());
                this.repository.setData(programs);

                heapTable.setHashMap(
                        garbageCollector(
                                mergeSymTableValues(programs),
                                heapTable.getHashMap()
                        )
                );

            } catch (Exception e) {
                e.printStackTrace();
            } finally {
                fileTable.getMyDictionary().values().stream().forEach(f -> {
                        try {
                            f.getSecond().close();
                        } catch (Exception e) {
                        }
                });
            }

        }
    }

}
