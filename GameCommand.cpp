#include "GameCommand.h"

void DoMoveCommand(Model & model, int student_id, Point2D p1)
{
	// if (model.GetStudentPtr(student_id) != 0)  //????NOT SURE WHAT OTHER CONDITIONS NEED TO BE CHECKED FOR VALIDITY maybe nullptr??
	// {
		model.GetStudentPtr(student_id)->StartMoving(p1);
		cout << "Moving " << (model.GetStudentPtr(student_id))->getName() << " to " << p1 << endl;
	// }
	// else
	// {
	// 	cout << "Error: Please enter a valid command!" << endl;
	// }
}

void DoMoveToDoctorCommand(Model & model, int student_id, int office_id)
{
	// if (model.GetDoctorsOfficePtr(office_id) != 0 && model.GetStudentPtr(student_id) != 0)
	// {
		model.GetStudentPtr(student_id)->StartMovingToDoctor(model.GetDoctorsOfficePtr(office_id));
		cout << "Moving " << (model.GetStudentPtr(student_id))->getName() << " to doctors office " << model.GetDoctorsOfficePtr(office_id)->GetId() << endl;
	// }
	// else 
	// {
	// 	cout << "Error: Please enter a valid command!" << endl;
	// }
}

void DoMoveToClassCommand(Model & model, int student_id, int class_id)
{
	// if (model.GetClassRoomPtr(class_id) != 0 && model.GetStudentPtr(student_id) != 0)
	// {
		model.GetStudentPtr(student_id)->StartMovingToClass(model.GetClassRoomPtr(class_id));
		cout << "Moving " << (model.GetStudentPtr(student_id))->getName() << " to class " << model.GetClassRoomPtr(class_id)->GetId() << endl;
	// }
	// else 
	// {
	// 	cout << "Error: Please enter a valid command!" << endl;
	// }
}

void DoStopCommand(Model & model, int student_id)
{
	// if (model.GetStudentPtr(student_id) != 0)
	// {
		model.GetStudentPtr(student_id)->Stop();
		cout << "Stopping " << model.GetStudentPtr(student_id)->getName() << endl;
	// }
	// else 
	// {
	// 	cout << "Error: Please enter a valid command!" << endl;
	// }
}

void DoLearningCommand(Model & model, int student_id, unsigned int assignments)
{
	// if (model.GetStudentPtr(student_id) != 0)//???NEED TO CHECK IF STUDENT CAN LEARN THE ASSIGNEMNTS
	// {
		model.GetStudentPtr(student_id)->StartLearning(assignments);
		cout << "Teaching " << model.GetStudentPtr(student_id)->getName() << endl;
	// }
	// else 
	// {
	// 	cout << "Error: Please enter a valid command!" << endl;
	// }
}

void DoRecoverInOfficeCommand(Model& model, int student_id, unsigned int vaccine_needs)
{
	// if (model.GetStudentPtr(student_id) != 0)//???NEED TO CHECK IF STUDENT IS IN DOCTORS OFFICE
	// {
		model.GetStudentPtr(student_id)->StartRecoveringAntibodies(vaccine_needs);
		cout << "Recovering " << model.GetStudentPtr(student_id)->getName() << "'s antibodies" << endl;
	// }
	// else 
	// {
	// 	cout << "Error: Please enter a valid command!" << endl;
	// }
}


//need to write view before implementing these
void DoGoCommand(Model& model, View& view)
{
	cout << "Advancing one tick." << endl;
	model.Update();
	model.Display(view);
	model.ShowStatus();
}
void DoRunCommand(Model& model, View& view)
{
	cout << "Advancing to next event." << endl;
	bool advance = true;
	while (advance == true)
	{
		advance = model.Update();
	}
	model.Display(view);
	model.ShowStatus();
}