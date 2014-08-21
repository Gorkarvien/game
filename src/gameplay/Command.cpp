#include "Command.h"
#include "GameActor.h"

namespace TFG
{
	void MoveUpCommand::execute(GameActor& actor)
	{
		actor.setmoveUp(true);
	}
	void MoveUpCommand::undo(GameActor& actor)
	{
		actor.setmoveUp(false);
	}

	void MoveDownCommand::execute(GameActor& actor)
	{
		actor.setmoveDown(true);
	}
	void MoveDownCommand::undo(GameActor& actor)
	{
		actor.setmoveDown(false);
	}

	void MoveLeftCommand::execute(GameActor& actor)
	{
		actor.setmoveLeft(true);
	}
	void MoveLeftCommand::undo(GameActor& actor)
	{
		actor.setmoveLeft(false);
	}

	void MoveRightCommand::execute(GameActor& actor)
	{
		actor.setmoveRight(true);
	}
	void MoveRightCommand::undo(GameActor& actor)
	{
		actor.setmoveRight(false);
	}


}
