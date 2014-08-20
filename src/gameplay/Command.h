#ifndef COMMAND_H
#define COMMAND_H

namespace TFG{
	class GameActor;

	class Command
	{
		protected:

		public:
			virtual ~Command(){};
			virtual void execute	(TFG::GameActor& actor) = 0;
			virtual void undo		(TFG::GameActor& actor) = 0;
	};	

	class VoidCommand : public Command
	{
		public:
			virtual void execute	(GameActor& actor){ return;}
			virtual void undo		(GameActor& actor){ return;}
	};

	class MoveUpCommand : public Command
	{
		public:
			virtual void execute (GameActor& actor);
			virtual void undo	 (GameActor& actor);
	};

	class MoveDownCommand : public Command
	{
		public:
			virtual void execute (GameActor& actor);
			virtual void undo	 (GameActor& actor);
	};

	class MoveRightCommand : public Command
	{
		public:
			virtual void execute (GameActor& actor);
			virtual void undo	 (GameActor& actor);
	};

	class MoveLeftCommand : public Command
	{
		public:
			virtual void execute (GameActor& actor);
			virtual void undo	 (GameActor& actor);
	};


}
#endif
