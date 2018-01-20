package UI.Controllers;

import Interpreter.Controller.Controller;
import UI.Example;
import UI.Interpreter;
import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.ListView;
import javafx.stage.Stage;
import javafx.scene.control.Button;
import java.net.URL;
import java.util.List;
import java.util.ResourceBundle;
import java.util.stream.Collectors;

public class StartUpController implements Initializable {

    public StartUpController() { }

    @FXML
    private ListView<String> programsList;

    @FXML
    private Button exitButton;

    @FXML
    public void exitButton_onAction() {
        Stage stage = (Stage) exitButton.getScene().getWindow();
        stage.close();
    }

    @FXML
    public Button openInterpreterButton;

    @FXML
    private void openInterpreterButton_onAction() {
        if (programsList.getSelectionModel().getSelectedItem() != null) {
            Interpreter interpreter = new Interpreter();
            try {
                interpreter.show(controllers.get(programsList.getSelectionModel().getSelectedIndex()));
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

    }

    private List<Controller> controllers;

    public void setPrograms(List<Example> programs) {

        controllers = programs.stream().map(Example::getController).collect(Collectors.toList());
        programsList.setItems(FXCollections.observableArrayList(
            programs.stream().map(Example::getName).collect(Collectors.toList()))
        );
    }

    @Override
    public void initialize(URL location, ResourceBundle resources) { }
}
