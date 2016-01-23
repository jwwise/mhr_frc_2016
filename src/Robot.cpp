#include "WPILib.h"

class Robot: public IterativeRobot
{
	Talon *lDrive = new Talon(0);
	Talon *rDrive = new Talon(1);
	Talon *arm1 = new Talon(2);
	Talon *arm2 = new Talon (3);
	Solenoid *piston1 = new Solenoid(0);
	Solenoid *piston2 = new Solenoid(1);
	Joystick *driveStick = new Joystick(0);
	Joystick *manipulatorStick = new Joystick(1);


private:
	LiveWindow *lw = LiveWindow::GetInstance();
	SendableChooser *chooser;
	const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";
	std::string autoSelected;
	double leftX = 0;
	double leftY = 0;
	double rightX = 0;
	double rightY = 0;
	double mLeftY = 0;
	double mRightY = 0;
	double leftTrigger = 0;
	double rightTrigger = 0;
	double threshold = 0.1;

	void RobotInit()
	{
		/*chooser = new SendableChooser();
		chooser->AddDefault(autoNameDefault, (void*)&autoNameDefault);
		chooser->AddObject(autoNameCustom, (void*)&autoNameCustom);
		SmartDashboard::PutData("Auto Modes", chooser);*/


	}


	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString line to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional comparisons to the if-else structure below with additional strings.
	 * If using the SendableChooser make sure to add them to the chooser code above as well.
	 */
	void AutonomousInit()
	{
		autoSelected = *((std::string*)chooser->GetSelected());
		//std::string autoSelected = SmartDashboard::GetString("Auto Selector", autoNameDefault);
		std::cout << "Auto selected: " << autoSelected << std::endl;

		if(autoSelected == autoNameCustom){
			//Custom Auto goes here
		} else {
			//Default Auto goes here
		}
	}

	void AutonomousPeriodic()
	{
		if(autoSelected == autoNameCustom){
			//Custom Auto goes here
		} else {
			//Default Auto goes here
		}
	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		leftX = driveStick->GetRawAxis(0);
		if(fabs(leftX) < threshold)
			leftX = 0;
		leftY = driveStick->GetRawAxis(1);
		if(fabs(leftY) < threshold)
			leftY = 0;
		mLeftY = manipulatorStick->GetRawAxis(1);
		if(fabs(mLeftY) < threshold)
			mLeftY = 0;
		rightX = driveStick->GetRawAxis(4);
		if(fabs(rightX) < threshold)
			rightX = 0;
		rightY = driveStick->GetRawAxis(5);
		if(fabs(rightY) < threshold)
			rightY = 0;
		mRightY = manipulatorStick->GetRawAxis(5);
		if(fabs(mRightY) < threshold)
			mRightY = 0;
		leftTrigger = (driveStick->GetRawAxis(2));
		if(fabs(leftTrigger) < (threshold))
			leftTrigger = 0;
		rightTrigger = (driveStick->GetRawAxis(3));
		if(fabs(rightTrigger) < (threshold))
			rightTrigger = 0;

		lDrive->Set(-(leftY - leftX));
		rDrive->Set(leftY + leftX);

		if(driveStick->GetRawButton(3)) {
			piston1->Set(1);
			piston2->Set(1);
		} else if(driveStick->GetRawButton(2)) {
			piston1->Set(0);
			piston2->Set(0);
		}



		if(manipulatorStick->GetRawButton(6)) {
			arm1->Set(mRightY);
		} else if(driveStick->GetRawButton(6)) {
			arm1->Set(rightY);
		} else {
			arm1 = 0;
		}
		if(manipulatorStick->GetRawButton(5)) {
			arm2->Set(mLeftY);
		} else if(driveStick->GetRawButton(5)) {
			arm2->Set(rightY);
		} else {
			arm2 = 0;
		}

	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot)
