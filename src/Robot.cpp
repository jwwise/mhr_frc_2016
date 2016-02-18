#include "WPILib.h"
//#include <iostream>


class Robot: public IterativeRobot
{
	CANTalon *lDrive1;
	CANTalon *lDrive2;
	CANTalon *rDrive1;
	CANTalon *rDrive2;
	CANTalon *arm1;
	CANTalon *shooter1;
	CANTalon *shooter2;
	CANTalon *winch;
	//CANTalon *flipper;
	//CANTalon *flipper2;
	DoubleSolenoid *lShifter;
	DoubleSolenoid *rShifter;
	DoubleSolenoid *william;
	DoubleSolenoid *flipper;
	//DoubleSolenoid *flipper2;
	Joystick *driveStick;
	Joystick *manipulatorStick;
	Compressor *steven;

//NOPE
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
		shooter1 = new CANTalon(6);
		shooter2 = new CANTalon(7);
		winch = new CANTalon(8);
		//flipper = new CANTalon(7);
		//flipper2 = new CANTalon(8);
		lShifter = new DoubleSolenoid(0,1);
		rShifter = new DoubleSolenoid(2,3);
		flipper = new DoubleSolenoid(4,5);
		william = new DoubleSolenoid(6,7);
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
	double mLeftTrigger = 0;
	double threshold = 0.09;

	void drive(double speed = 0)
	{
		while(true) {
			lDrive1->Set(speed);
			lDrive2->Set(speed);
			rDrive1->Set(-speed);
			lDrive2->Set(-speed);
		}
	}

	void shoot(double speed = 0)
	{
		while(true) {
			shooter1->Set(speed);
			shooter2->Set(-speed);
		}
	}

	void shift(bool lowGear = true)
	{
		while(true) {
			if(lowGear) {
				lShifter->Set(DoubleSolenoid::Value::kForward);
				rShifter->Set(DoubleSolenoid::Value::kForward);
			} else if(!lowGear) {
				lShifter->Set(DoubleSolenoid::Value::kReverse);
				rShifter->Set(DoubleSolenoid::Value::kReverse);
			}
		}
	}

	void motorSet(double driveSpeed = 0, double shootSpeed = 0, double armSpeed = 0, double winchSpeed = 0)
	{
		while(true) {
			drive(driveSpeed);
			shoot(shootSpeed);
			arm1->Set(armSpeed);
			winch->Set(winchSpeed);
		}
	}

	void RobotInit() override
	{
		while(true) {
		/*chooser = new SendableChooser();
		chooser->AddDefault(autoNameDefault, (void*)&autoNameDefault);
		chooser->AddObject(autoNameCustom, (void*)&autoNameCustom);
		SmartDashboard::PutData("Auto Modes", chooser);*/

		/*std::cout << "Areas: ";
		std::vector<double> arr = table->GetNumberArray("area", llvm::ArrayRef<double>());
		for (unsigned int i = 0; i < arr.size(); i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
		Wait(1)
		*/

		}
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
			drive(.475);
			Wait(4);
			drive(0);
		} else {
			//Default Auto goes here
		}
	}

	void AutonomousPeriodic()
	{
		if(autoSelected == autoNameCustom){
			/*lDrive1->Set(.475);
			rDrive1->Set(-.475);
			lDrive2->Set(.475);
			rDrive2->Set(-.475);
			Wait(4);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);*/

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
		//steven->SetClosedLoopControl(true); //Caleb: A

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
		mLeftTrigger = (driveStick->GetRawAxis(2));
		if(fabs(mLeftTrigger) < (threshold))
			mLeftTrigger = 0;

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

		drive(-(leftY - leftX));
		/*rDrive1->Set(-(leftY - leftX));
		rDrive2->Set(-(leftY - leftX));
		lDrive1->Set(leftY + leftX);
		lDrive2->Set(leftY + leftX);*/

		if(driveStick->GetRawButton(3)) {
			shift(true);
			/*lShifter->Set(DoubleSolenoid::Value::kForward);
			rShifter->Set(DoubleSolenoid::Value::kForward);*/
		} else if(driveStick->GetRawButton(2)) {
			shift(false);
			/*lShifter->Set(DoubleSolenoid::Value::kReverse);
			rShifter->Set(DoubleSolenoid::Value::kReverse);*/
		}



		if(driveStick->GetRawButton(5)) {
			arm1->Set(rightY / 2);
		} else if(manipulatorStick->GetRawButton(5)) {
			arm1->Set(mRightY / 2);
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
			flipper->Set(mRightY);
			flipper2->Set(-mRightY);
			if(fabs(mRightY) < threshold && !driveStick->GetRawButton(6) && !driveStick->GetRawButton(5)) {
				flipper->Set(rightY);
				flipper2->Set(-rightY);
			}
		} else if(!driveStick->GetRawButton(6) && !driveStick->GetRawButton(5)) {
			flipper->Set(rightY);
			flipper2->Set(-rightY);
		} else {
			flipper->Set(0);
			flipper2->Set(0);
		}*/

		if(manipulatorStick->GetRawButton(1) || driveStick->GetRawButton(1)) {
			flipper->Set(DoubleSolenoid::Value::kForward);
			//flipper2->Set(DoubleSolenoid::Value::kForward);
		} else if(manipulatorStick->GetRawButton(4) || driveStick->GetRawButton(4)) {
			flipper->Set(DoubleSolenoid::Value::kReverse);
			//flipper2->Set(DoubleSolenoid::Value::kReverse);
		}

		if(fabs(rightTrigger)> threshold) {
			shoot(rightTrigger);
			/*shooter1->Set(rightTrigger);
			shooter2->Set(-rightTrigger);*/
		} else if(fabs(mRightTrigger) > threshold) {
			shoot(mRightTrigger);
			/*shooter1->Set(mRightTrigger);
			shooter2->Set(-mRightTrigger);*/
		} else if(fabs(leftTrigger)> threshold) {
			shoot(leftTrigger / 8);
			/*shooter1->Set(leftTrigger / 8);
			shooter2->Set(-leftTrigger / 8);*/
		} else if(fabs(mLeftTrigger) > threshold) {
			shoot(mLeftTrigger / 8);
			/*shooter1->Set(mLeftTrigger / 8);
			shooter2->Set(-mLeftTrigger / 8);*/
		} else {
			shoot(0);
			/*shooter1->Set(0);
			shooter2->Set(0);*/
		}

		if(driveStick->GetRawButton(6)) {
			william->Set(DoubleSolenoid::Value::kForward);
		} else if(manipulatorStick->GetRawButton(6)) {
			william->Set(DoubleSolenoid::Value::kForward);
		} else {
			william->Set(DoubleSolenoid::Value::kReverse);
		}

		if(driveStick->GetRawButton(8)) {
			winch->Set(0.2);
		} else if(driveStick->GetRawButton(7)) {
			winch->Set(-0.2);
		} else if(manipulatorStick->GetRawButton(8)) {
			winch->Set(0.2);
		} else if(manipulatorStick->GetRawButton(7)) {
			winch->Set(-0.2);
		} else {
			winch->Set(0);
		}

	}//:D

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot)
