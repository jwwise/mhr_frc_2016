#include "WPILib.h"
//#include <iostream>


class Robot: public IterativeRobot
{
	CANTalon *lDrive1;
	CANTalon *lDrive2;
	CANTalon *rDrive1;
	CANTalon *rDrive2;
	CANTalon *arm1;
	CANTalon *shooter;
	//CANTalon *flipper1;
	//CANTalon *flipper2;
	DoubleSolenoid *shifter;
	DoubleSolenoid *william;
	DoubleSolenoid *flipper1;
	DoubleSolenoid *flipper2;
	Joystick *driveStick;
	Joystick *manipulatorStick;
	Compressor *steven;

//potatoes
public:
	//std::shared_ptr<NetworkTable> table;
	Robot() {
		Wait(1);
		chooser = new SendableChooser;
		lDrive1 = new CANTalon(1);
		lDrive2 = new CANTalon(2);
		rDrive1 = new CANTalon(3);
		rDrive2 = new CANTalon(4);
		arm1 = new CANTalon(5);
		shooter = new CANTalon(6);
		//flipper1 = new CANTalon(7);
		//flipper2 = new CANTalon(8);
		shifter = new DoubleSolenoid(0,1);
		william = new DoubleSolenoid(2,3);
		flipper1 = new DoubleSolenoid(4,5);
		flipper2 = new DoubleSolenoid(6,7);
		driveStick = new Joystick(0);
		manipulatorStick = new Joystick(1);
		steven = new Compressor(0);

		//CameraServer::GetInstance()->SetQuality(50);
		//table = NetworkTable::GetTable("GRIP/myContoursReport");
	}


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
	double mRightTrigger = 0;
	double threshold = 0.09;

	void RobotInit() override
	{
		/*chooser = new SendableChooser();
		chooser->AddDefault(autoNameDefault, (void*)&autoNameDefault);
		chooser->AddObject(autoNameCustom, (void*)&autoNameCustom);
		SmartDashboard::PutData("Auto Modes", chooser);*/

		/*std::cout << "Areas: ";
		std::vector<double> arr = table->GetNumberArray("area", llvm::ArrayRef<double>());
		for (unsigned int i = 0; i < arr.size(); i++) {
			std::cout << arr[i]
		}*/


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
			lDrive1->Set(.475);
			rDrive1->Set(-.475);
			lDrive2->Set(.475);
			rDrive2->Set(-.475);
			Wait(4);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
		} else {
			//Default Auto goes here
		}
	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		//CameraServer::GetInstance()->StartAutomaticCapture("cam0");
		//steven->SetClosedLoopControl(true);

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
		mRightTrigger = (driveStick->GetRawAxis(3));
		if(fabs(mRightTrigger) < (threshold))
			mRightTrigger = 0;

		leftX = pow(fabs(leftX), 1.4);
		if(driveStick->GetRawAxis(0) > 0) {
			leftX = -leftX;
		}
		/*if(driveStick->GetRawAxis(1) < 0) {
			leftY = -leftY;
		}*/
		leftY = pow(fabs(leftY), 1.4);
		if(driveStick->GetRawAxis(1) < 0) {
			leftY = -leftY;
		}
		rightX = pow(fabs(rightX), 1.4);
		if(driveStick->GetRawAxis(4) > 0) {
			rightX = -rightX;
		}
		rightY = pow(fabs(rightY), 1.4);
		if(driveStick->GetRawAxis(5) > 0) {
			rightY = -rightY;
		}
		mRightY = pow(fabs(mRightY), 1.4);
		if(manipulatorStick->GetRawAxis(5) > 0) {
			mRightY = -mRightY;
		}
		mLeftY = pow(fabs(mLeftY), 1.4);
		if(manipulatorStick->GetRawAxis(1) > 0) {
			mLeftY = -mLeftY;
		}

		rDrive1->Set(-(leftY - leftX));
		rDrive2->Set(-(leftY - leftX));
		lDrive1->Set(leftY + leftX);
		lDrive2->Set(leftY + leftX);

		if(driveStick->GetRawButton(3)) {
			shifter->Set(DoubleSolenoid::Value::kForward);
			//rShifter->Set(DoubleSolenoid::Value::kForward);
		} else if(driveStick->GetRawButton(2)) {
			shifter->Set(DoubleSolenoid::Value::kReverse);
			//rShifter->Set(DoubleSolenoid::Value::kReverse);
		}



		if(manipulatorStick->GetRawButton(5)) {
			arm1->Set(mRightY);
		} else if(driveStick->GetRawButton(5)) {
			arm1->Set(rightY);
		} else {
			arm1->Set(0);
		}
/*		if(manipulatorStick->GetRawButton(5)) {
			arm2->Set(mLeftY);
		} else if(driveStick->GetRawButton(5)) {
			arm2->Set(rightY);
		} else {
			arm2->Set(0);
		}*/

		/*if(!manipulatorStick->GetRawButton(6) && !manipulatorStick->GetRawButton(5)) {
			flipper1->Set(mRightY);
			flipper2->Set(-mRightY);
			if(fabs(mRightY) < threshold && !driveStick->GetRawButton(6) && !driveStick->GetRawButton(5)) {
				flipper1->Set(rightY);
				flipper2->Set(-rightY);
			}
		} else if(!driveStick->GetRawButton(6) && !driveStick->GetRawButton(5)) {
			flipper1->Set(rightY);
			flipper2->Set(-rightY);
		} else {
			flipper1->Set(0);
			flipper2->Set(0);
		}*/

		if(manipulatorStick->GetRawButton(1) || driveStick->GetRawButton(1)) {
			flipper1->Set(DoubleSolenoid::Value::kForward);
			flipper2->Set(DoubleSolenoid::Value::kForward);
		} else if(manipulatorStick->GetRawButton(4) || driveStick->GetRawButton(4)) {
			flipper1->Set(DoubleSolenoid::Value::kReverse);
			flipper2->Set(DoubleSolenoid::Value::kReverse);
		}

		if(fabs(mRightTrigger) > threshold) {
			shooter->Set(mRightTrigger);
		} else {
			shooter->Set(0);
		}

		if(manipulatorStick->GetRawButton(6)) {
			william->Set(DoubleSolenoid::Value::kForward);
		} else {
			william->Set(DoubleSolenoid::Value::kReverse);
		}

	}//:D

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot)
