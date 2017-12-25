using System.Collections.Generic;
using ToyLanguage.Models.States;

namespace ToyLanguage.Repository
{
    public class Repository : IRepository
    {
        private List<ProgramState> _programs;

        public List<ProgramState> Programs
        {
            get { return _programs; }
            set { _programs = value; }
        }
        
        private readonly string _logFilePath;

        public Repository(string logFilePath, List<ProgramState> programs = null)
        {
            _programs = programs ?? new List<ProgramState>();
            _logFilePath = logFilePath;
        }

        public void LogProgramState(ProgramState program)
        {
            using (System.IO.StreamWriter file = 
                new System.IO.StreamWriter(_logFilePath, true))
            {
                file.WriteLine($"\n{program}");
                file.WriteLine("\n--------------------------------------------------\n");
            }
        }
    }
}