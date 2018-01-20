package UI.Controllers;

import Interpreter.Controller.Controller;
import Interpreter.Models.Expression;
import Interpreter.Models.IStatement;
import Interpreter.Models.ProgramState.ProgramState;
import javafx.collections.FXCollections;
import javafx.scene.control.*;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.stage.Stage;
import Interpreter.Utils.Pair;

import java.io.BufferedReader;
import java.net.URL;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.ResourceBundle;
import java.util.stream.Collectors;

public class InterpreterController implements Initializable {

    public InterpreterController() {}

    private Integer selectedProgramID;
    private ProgramState selectedProgram;

    @FXML
    public TextField currentSelectedProgram;

    @FXML
    public void setSelectedProgram() {
        if (programs.getSelectionModel().getSelectedItem() != null) {
            selectedProgramID = programs.getSelectionModel().getSelectedItem();
            selectedProgram = controller.getProgramState(selectedProgramID);
            currentSelectedProgram.setText(selectedProgramID.toString());
            loadData();
        }
    }

    private void loadData() {
        programs.getItems().setAll(controller.getPrograms().stream().map(ProgramState::getID).collect(Collectors.toList()));
        if (selectedProgram != null) {
            loadExeStack();
            loadOutput();
            loadSymbolTable();
            loadFileTable();
            loadHeapTable();
        }
    }

    private void loadSymbolTable() {
        HashMap<String, Integer> dataHash = selectedProgram.getSymTable().getMyDictionary();
        symbolTable.setItems(FXCollections.observableArrayList(dataHash.keySet().stream().map(p -> new Pair<String, Integer>(p, dataHash.get(p))).collect(Collectors.toList())));
    }

    private void loadFileTable() {
        HashMap<Integer, Pair<String, BufferedReader>> dataHash = selectedProgram.getFileTable().getMyDictionary();
        fileTable.setItems(FXCollections.observableArrayList(dataHash.keySet().stream().map(p -> new Pair<String, String>(p.toString(), dataHash.get(p).getFirst())).collect(Collectors.toList())));
    }

    private void loadHeapTable() {
        HashMap<Integer, Integer> dataHash = selectedProgram.getHeapTable().getMyDictionary();
        heapTable.setItems(FXCollections.observableArrayList(dataHash.keySet().stream().map(p -> new Pair<Integer, Integer>(p, dataHash.get(p))).collect(Collectors.toList())));
    }

    private void loadExeStack() {
        List<String> exeStackElems = selectedProgram.getExeStack().getData().stream().map(IStatement::toString).collect(Collectors.toList());
        Collections.reverse(exeStackElems);
        executionStack.getItems().setAll(exeStackElems);
    }

    private void loadOutput() {
        output.getItems().setAll(selectedProgram.getOutput().getData().stream().map(Object::toString).collect(Collectors.toList()));
    }

    private Controller controller;

    public void setController(Controller cont) {
        controller = cont;

        selectedProgram = controller.getPrograms().get(0);
        selectedProgramID = selectedProgram.getID();
        currentSelectedProgram.setText(selectedProgramID.toString());

        loadData();
    }

    @FXML
    public Button runButton;

    public void runButton_onAction() {
        try {
            controller.executeAllProgram();
        } catch (Exception e) {
            openMessageBox("Interpreter", "Interpreter info", "The program is over!");
        }
        loadData();
    }

    @FXML
    public Button runOneStepButton;

    @FXML
    public void runOneStepButton_onAction() {
        try {
            controller.executeOneStepProgram();
        } catch (Exception e) {
            openMessageBox("Interpreter", "Interpreter info", "The program is over!");
        }
        loadData();
    }

    private void openMessageBox(String title, String header, String content) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle(title);
        alert.setHeaderText(header);
        alert.setContentText(content);
        alert.showAndWait().ifPresent(rs -> {
            if (rs == ButtonType.OK) {
                System.out.println("Pressed OK.");
            }
        });
    }

    @FXML
    public Button exitButton;

    @FXML
    public void exitButton_onAction() {
        Stage stage = (Stage) exitButton.getScene().getWindow();
        stage.close();
    }

    @FXML
    public ListView<String> output;
    @FXML
    public ListView<Integer> programs;
    @FXML
    public ListView<String> executionStack;

    @FXML
    public TableView<Pair<String, Integer>> symbolTable;

    @FXML
    public TableColumn<Pair<String, Integer>, String> symbolTableNames;
    @FXML
    public TableColumn<Pair<String, Integer>, Integer> symbolTableValues;

    @FXML
    public TableView<Pair<String, String>> fileTable;

    @FXML
    public TableColumn<Pair<String, String>, String> fileTableNames;
    @FXML
    public TableColumn<Pair<String, String>, String> fileTablePaths;

    @FXML
    public TableView<Pair<Integer, Integer>> heapTable;

    @FXML
    public TableColumn<Pair<Integer, Integer>, Integer> heapTableAddresses;
    @FXML
    public TableColumn<Pair<Integer, Integer>, Integer> heapTableValues;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        symbolTableNames.setCellValueFactory(new PropertyValueFactory<>("first"));
        symbolTableValues.setCellValueFactory(new PropertyValueFactory<>("second"));

        fileTableNames.setCellValueFactory(new PropertyValueFactory<>("first"));
        fileTablePaths.setCellValueFactory(new PropertyValueFactory<>("second"));

        heapTableAddresses.setCellValueFactory(new PropertyValueFactory<>("first"));
        heapTableValues.setCellValueFactory(new PropertyValueFactory<>("second"));
    }
}
