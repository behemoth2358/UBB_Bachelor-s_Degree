﻿using System.Collections.Generic;
using ToyLanguage.Models.States;
using ToyLanguage.Repository;

namespace ToyLanguage.Controller
{
    public class ToyLanguageController
    {
        private IRepository _repository;

        public ToyLanguageController(IRepository repository)
        {
            _repository = repository;
        }

        private void ExecuteOneInstruction(ProgramState program)
        {
            var statement = program.ExecutionStack.Pop();
            
            statement.Execute(program);
        }

        public void ExecuteProgram()
        {
            var program = _repository.getProgram();
            
            _repository.logProgramState(program);
            
            while (program.ExecutionStack.Count != 0)
            {
                
                ExecuteOneInstruction(program);
                _repository.logProgramState(program);
            }
        }
    }
}