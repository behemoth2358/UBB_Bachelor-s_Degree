using ToyLanguage.Models.States;

namespace ToyLanguage.Repository
{
    public interface IRepository
    {
        ProgramState getProgram();
        void logProgramState(ProgramState program);
    }
}