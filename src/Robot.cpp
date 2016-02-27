#include "WPILib.h"
//#include <iostream>


class Robot: public IterativeRobot
{
	CANTalon *lDrive1;
	CANTalon *lDrive2;
	CANTalon *rDrive1;
	CANTalon *rDrive2;
	CANTalon *arm1;
<<<<<<< HEAD
	CANTalon *arm2;
	//CANTalon *flipper1;
	//CANTalon *flipper2;
	DoubleSolenoid *lShifter;
	DoubleSolenoid *rShifter;
	DoubleSolenoid *flipper1;
	DoubleSolenoid *flipper2;
	Joystick *driveStick;
	Joystick *manipulatorStick;
	Compressor *steven;

//potatoes
=======
	CANTalon *shooter1;
	CANTalon *shooter2;
	CANTalon *winch;
	//CANTalon *flipper;
	//CANTalon *flipper2;
	DoubleSolenoid *lShifter;
	//DoubleSolenoid *rShifter;
	DoubleSolenoid *william;
	DoubleSolenoid *flipper;
	//DoubleSolenoid *flipper2;
	Joystick *driveStick;
	Joystick *manipulatorStick;
	Compressor *steven;
	DigitalInput *switch1;
	DigitalInput *switch2;
	DigitalInput *switch3;
	DigitalInput *switch4;
	AnalogInput *shooterUS;
	/*Image *frame;
	Image *frame2;
	IMAQdxSession *session;*/

//NOPE
>>>>>>> 2d52d3808d0307cee83315490cf8b3854e69b8d6
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
<<<<<<< HEAD
		arm2 = new CANTalon(6);
		//flipper1 = new CANTalon(7);
		//flipper2 = new CANTalon(8);
		lShifter = new DoubleSolenoid(0,1);
		rShifter = new DoubleSolenoid(2,3);
		flipper1 = new DoubleSolenoid(4,5);
		flipper2 = new DoubleSolenoid(6,7);
		driveStick = new Joystick(0);
		manipulatorStick = new Joystick(1);
		steven = new Compressor(0);
=======
		shooter1 = new CANTalon(6);
		shooter2 = new CANTalon(7);
		winch = new CANTalon(8);
		//flipper = new CANTalon(7);
		//flipper2 = new CANTalon(8);
		lShifter = new DoubleSolenoid(0,1);
		william = new DoubleSolenoid(2,3);
		flipper = new DoubleSolenoid(4,5);
		//rShifter = new DoubleSolenoid(6,7);
		driveStick = new Joystick(0);
		manipulatorStick = new Joystick(1);
		steven = new Compressor(0);
		switch1 = new DigitalInput(0);
		switch2 = new DigitalInput(1);
		switch3 = new DigitalInput(2);
		switch4 = new DigitalInput(3);
		shooterUS = new AnalogInput(4);
		//frame = new ImageType(ColorImage);
		//session = new IMAQdxSession;
>>>>>>> 2d52d3808d0307cee83315490cf8b3854e69b8d6

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
<<<<<<< HEAD
	double threshold = 0.09;

	void RobotInit() override
	{
=======
	double mRightTrigger = 0;
	double mLeftTrigger = 0;
	bool dUp = false;
	bool dRight = false;
	bool dDown = false;
	bool dLeft = false;
	bool dUpR = false;
	bool dUpL = false;
	bool dDownR = false;
	bool dDownL = false;
	bool cruise = false;
	bool buttonVal0 = false;
	bool buttonVal1 = false;
	bool buttonVal2 = false;
	bool buttonVal3 = false;
	int dir = 0;
	int action = 1;
	int type = 0;
	int typeMod = 0;
	int mode = 0;
	double fieldPos = 0;
	double threshold = 0.09;

	/*void drive(double speed = 0)
	{
		lDrive1->Set(speed);
		lDrive2->Set(speed);
		rDrive1->Set(-speed);
		lDrive2->Set(-speed);
	}

	void shoot(double speed = 0)
	{
		shooter1->Set(speed);
		shooter2->Set(-speed);
	}*/

	void RobotInit() override
	{
		/*frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
		imaqColorThreshold(frame2, frame, 0, 0, Range(0), Range(255), Range(0);*/


>>>>>>> 2d52d3808d0307cee83315490cf8b3854e69b8d6
		/*chooser = new SendableChooser();
		chooser->AddDefault(autoNameDefault, (void*)&autoNameDefault);
		chooser->AddObject(autoNameCustom, (void*)&autoNameCustom);
		SmartDashboard::PutData("Auto Modes", chooser);*/

		/*std::cout << "Areas: ";
		std::vector<double> arr = table->GetNumberArray("area", llvm::ArrayRef<double>());
		for (unsigned int i = 0; i < arr.size(); i++) {
<<<<<<< HEAD
			std::cout << arr[i]
		}*/
=======
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
		Wait(1)
		*/
>>>>>>> 2d52d3808d0307cee83315490cf8b3854e69b8d6


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
<<<<<<< HEAD
		autoSelected = *((std::string*)chooser->GetSelected());
=======
		if(action == 0) { //Drive
			lShifter->Set(DoubleSolenoid::Value::kForward);
			lDrive1->Set(-.475);
			rDrive1->Set(.475);
			lDrive2->Set(-.475);
			rDrive2->Set(.475);
			Wait(2);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
		} else if(action == 1 && ((type == 0 && typeMod == 0) || (type == 4 && typeMod == 0))) {
			lShifter->Set(DoubleSolenoid::Value::kForward); //Low Bar & Portcullis
			flipper->Set(DoubleSolenoid::Value::kForward);
			lDrive1->Set(-.475);
			rDrive1->Set(.475);
			lDrive2->Set(-.475);
			rDrive2->Set(.475);
			Wait(6);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
		} else if(action == 1 && ((type == 1 && typeMod == 0) || (type == 3 && typeMod == 0) || (type == 1 && typeMod == 1) || (type == 3 && typeMod == 1))) {
			lShifter->Set(DoubleSolenoid::Value::kForward); //Long Drive
			lDrive1->Set(-.555);
			rDrive1->Set(.555);
			lDrive2->Set(-.555);
			rDrive2->Set(.555);
			Wait(5);
			if(type == 1 && typeMod == 0) {
				Wait(1);
			}
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
		} else if(action == 1 && (type == 0 && typeMod == 1)) { // Cheval de Frise
			lShifter->Set(DoubleSolenoid::Value::kForward);
			lDrive1->Set(-.475);
			rDrive1->Set(.475);
			lDrive2->Set(-.475);
			rDrive2->Set(.475);
			Wait(1.6);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
			flipper->Set(DoubleSolenoid::Value::kForward);
			Wait(1.5);
			lDrive1->Set(-.475);
			rDrive1->Set(.475);
			lDrive2->Set(-.475);
			rDrive2->Set(.475);
			Wait(0.5);
			flipper->Set(DoubleSolenoid::Value::kReverse);
			Wait(1.5);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
			Wait(1);
			lDrive1->Set(-.475);
			rDrive1->Set(.475);
			lDrive2->Set(-.475);
			rDrive2->Set(.475);
			Wait(1.5);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
		} else if(action == 1 && (type == 2 && typeMod == 0)) { //Drawbridge
			lShifter->Set(DoubleSolenoid::Value::kForward);
			lDrive1->Set(-.475);
			rDrive1->Set(.475);
			lDrive2->Set(-.475);
			rDrive2->Set(.475);
			arm1->Set(.75);
			Wait(1.25);
			arm1->Set(0);
			Wait(.75);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
			arm1->Set(-.3);
			Wait(0.1);
			lDrive1->Set(.3);
			rDrive1->Set(-.3);
			lDrive2->Set(.3);
			rDrive2->Set(-.3);
			Wait(1.25);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
			Wait(.2);
			lDrive1->Set(-.15);
			rDrive1->Set(.15);
			lDrive2->Set(-.15);
			rDrive2->Set(.15);
			Wait(1);
			arm1->Set(0);
			flipper->Set(DoubleSolenoid::Value::kForward);
			Wait(.5);
			lDrive1->Set(.15);
			rDrive1->Set(-.15);
			lDrive2->Set(.15);
			rDrive2->Set(-.15);
			Wait(.5);
			lDrive1->Set(-.475);
			rDrive1->Set(.475);
			lDrive2->Set(-.475);
			rDrive2->Set(.475);
			Wait(1.5);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
			flipper->Set(DoubleSolenoid::Value::kReverse);
		}


		/*autoSelected = *((std::string*)chooser->GetSelected());
>>>>>>> 2d52d3808d0307cee83315490cf8b3854e69b8d6
		//std::string autoSelected = SmartDashboard::GetString("Auto Selector", autoNameDefault);
		std::cout << "Auto selected: " << autoSelected << std::endl;

		if(autoSelected == autoNameCustom){
			//Custom Auto goes here
		} else {
			//Default Auto goes here
<<<<<<< HEAD
		}
=======
		}*/
>>>>>>> 2d52d3808d0307cee83315490cf8b3854e69b8d6
	}

	void AutonomousPeriodic()
	{
<<<<<<< HEAD
		if(autoSelected == autoNameCustom){
			lDrive1->Set(.475);
			rDrive1->Set(.475);
			lDrive2->Set(.475);
			rDrive2->Set(.475);
=======
		/*if(autoSelected == autoNameCustom){
			lDrive1->Set(.475);
			rDrive1->Set(-.475);
			lDrive2->Set(.475);
			rDrive2->Set(-.475);
>>>>>>> 2d52d3808d0307cee83315490cf8b3854e69b8d6
			Wait(4);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
		} else {
			//Default Auto goes here
<<<<<<< HEAD
		}
=======
		}*/
>>>>>>> 2d52d3808d0307cee83315490cf8b3854e69b8d6
	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		//CameraServer::GetInstance()->StartAutomaticCapture("cam0");
<<<<<<< HEAD
		//steven->SetClosedLoopControl(true);
=======
		//steven->SetClosedLoopControl(true); //Caleb: A
		//frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
>>>>>>> 2d52d3808d0307cee83315490cf8b3854e69b8d6

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
<<<<<<< HEAD
=======
		mRightTrigger = (manipulatorStick->GetRawAxis(3));
		if(fabs(mRightTrigger) < (threshold))
			mRightTrigger = 0;
		mLeftTrigger = (manipulatorStick->GetRawAxis(2));
		if(fabs(mLeftTrigger) < (threshold))
			mLeftTrigger = 0;
>>>>>>> 2d52d3808d0307cee83315490cf8b3854e69b8d6

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

<<<<<<< HEAD
=======
		if(driveStick->GetPOV() == 0) {
			dUp = true;
			dRight = false;
			dDown = false;
			dLeft = false;
			dUpR = false;
			dUpL = false;
			dDownR = false;
			dDownL = false;
		} else if(driveStick->GetPOV() == 90) {
			dUp = false;
			dRight = true;
			dDown = false;
			dLeft = false;
			dUpR = false;
			dUpL = false;
			dDownR = false;
			dDownL = false;
		} else if(driveStick->GetPOV() == 180) {
			dUp = false;
			dRight = false;
			dDown = true;
			dLeft = false;
			dUpR = false;
			dUpL = false;
			dDownR = false;
			dDownL = false;
		} else if(driveStick->GetPOV() == 270) {
			dUp = false;
			dRight = false;
			dDown = false;
			dLeft = true;
			dUpR = false;
			dUpL = false;
			dDownR = false;
			dDownL = false;
		} else if(driveStick->GetPOV() == 45) {
			dUp = false;
			dRight = false;
			dDown = false;
			dLeft = false;
			dUpR = true;
			dUpL = false;
			dDownR = false;
			dDownL = false;
		} else if(driveStick->GetPOV() == 135) {
			dUp = false;
			dRight = false;
			dDown = false;
			dLeft = false;
			dUpR = false;
			dUpL = false;
			dDownR = true;
			dDownL = false;
		} else if(driveStick->GetPOV() == 225) {
			dUp = false;
			dRight = false;
			dDown = false;
			dLeft = false;
			dUpR = false;
			dUpL = false;
			dDownR = false;
			dDownL = true;
		} else if(driveStick->GetPOV() == 315) {
			dUp = false;
			dRight = false;
			dDown = false;
			dLeft = false;
			dUpR = false;
			dUpL = true;
			dDownR = false;
			dDownL = false;
		} else {
			dUp = false;
			dRight = false;
			dDown = false;
			dLeft = false;
			dUpR = false;
			dUpL = false;
			dDownR = false;
			dDownL = false;
		}

>>>>>>> 2d52d3808d0307cee83315490cf8b3854e69b8d6
		rDrive1->Set(-(leftY - leftX));
		rDrive2->Set(-(leftY - leftX));
		lDrive1->Set(leftY + leftX);
		lDrive2->Set(leftY + leftX);

		if(driveStick->GetRawButton(3)) {
			lShifter->Set(DoubleSolenoid::Value::kForward);
<<<<<<< HEAD
			rShifter->Set(DoubleSolenoid::Value::kForward);
		} else if(driveStick->GetRawButton(2)) {
			lShifter->Set(DoubleSolenoid::Value::kReverse);
			rShifter->Set(DoubleSolenoid::Value::kReverse);
		}



		if(manipulatorStick->GetRawButton(6)) {
			arm1->Set(mRightY);
		} else if(driveStick->GetRawButton(6)) {
			arm1->Set(rightY);
		} else {
			arm1->Set(0);
		}
		if(manipulatorStick->GetRawButton(5)) {
=======
			//rShifter->Set(DoubleSolenoid::Value::kForward);
		} else if(driveStick->GetRawButton(2)) {
			lShifter->Set(DoubleSolenoid::Value::kReverse);
			//rShifter->Set(DoubleSolenoid::Value::kReverse);
		}


		if(driveStick->GetRawButton(6)) {
			if(rightY > threshold && !switch3) {
				arm1->Set(rightY);
			} else if(rightY < threshold && !switch4) {
				arm1->Set(rightY);
			} else {
				arm1->Set(0);
			}
		} else if(manipulatorStick->GetRawButton(6)) {
			if(mRightY > threshold && !switch3) {
				arm1->Set(mRightY);
			} else if(mRightY < threshold && !switch4) {
				arm1->Set(mRightY);
			} else {
				arm1->Set(0);
			}
		} else {
			arm1->Set(0);
		}
/*		if(manipulatorStick->GetRawButton(5)) {
>>>>>>> 2d52d3808d0307cee83315490cf8b3854e69b8d6
			arm2->Set(mLeftY);
		} else if(driveStick->GetRawButton(5)) {
			arm2->Set(rightY);
		} else {
			arm2->Set(0);
<<<<<<< HEAD
		}

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
=======
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
>>>>>>> 2d52d3808d0307cee83315490cf8b3854e69b8d6
			flipper2->Set(0);
		}*/

		if(manipulatorStick->GetRawButton(1) || driveStick->GetRawButton(1)) {
<<<<<<< HEAD
			flipper1->Set(DoubleSolenoid::Value::kForward);
			flipper2->Set(DoubleSolenoid::Value::kForward);
		} else if(manipulatorStick->GetRawButton(4) || driveStick->GetRawButton(4)) {
			flipper1->Set(DoubleSolenoid::Value::kReverse);
			flipper2->Set(DoubleSolenoid::Value::kReverse);
		}

=======
			flipper->Set(DoubleSolenoid::Value::kForward);
			//flipper2->Set(DoubleSolenoid::Value::kForward);
		} else if(manipulatorStick->GetRawButton(4) || driveStick->GetRawButton(4)) {
			flipper->Set(DoubleSolenoid::Value::kReverse);
			//flipper2->Set(DoubleSolenoid::Value::kReverse);
		}

		if(fabs(rightTrigger)> threshold) {
			shooter1->Set(rightTrigger / 1.2);
			shooter2->Set(-rightTrigger / 1.2);
		} else if(fabs(mRightTrigger) > threshold) {
			shooter1->Set(mRightTrigger / 1.2);
			shooter2->Set(-mRightTrigger / 1.2);
		} else if(fabs(leftTrigger)> threshold) {
			shooter1->Set(-leftTrigger / 2.5);
			shooter2->Set(leftTrigger / 2.5);
		} else if(fabs(mLeftTrigger) > threshold) {
			shooter1->Set(-mLeftTrigger / 2.5);
			shooter2->Set(mLeftTrigger / 2.5);
		} else {
			shooter1->Set(0);
			shooter2->Set(0);
		}


		if(driveStick->GetRawButton(5)) {
			william->Set(DoubleSolenoid::Value::kReverse);
		} else if(manipulatorStick->GetRawButton(5)) {
			william->Set(DoubleSolenoid::Value::kReverse);
		} else {
			william->Set(DoubleSolenoid::Value::kForward);
		}

		/*if(dUp) {
			william->Set(DoubleSolenoid::Value::kReverse);
		} else if(dDown) {
			william->Set(DoubleSolenoid::Value::kForward);
		}*/

		if(dRight || manipulatorStick->GetPOV() == 90) {
			cruise = true;
		} else if(dLeft || manipulatorStick->GetPOV() == 270) {
			cruise = false;
		}

		if(driveStick->GetRawButton(8) &! switch1) {
			winch->Set(0.2);
		} else if(driveStick->GetRawButton(7) &! switch2) {
			winch->Set(-0.2);
		} else if(manipulatorStick->GetRawButton(8) &! switch1) {
			winch->Set(0.2);
		} else if(manipulatorStick->GetRawButton(7) &! switch2) {
			winch->Set(-0.2);
		} else if(dUp &! switch2) {
			winch->Set(-0.2);
		} else if(dDown &! switch1) {
			winch->Set(0.2);
		} else if((manipulatorStick->GetPOV() == 0) &! switch2) {
			winch->Set(-0.2);
		} else if((manipulatorStick->GetPOV() == 180) &! switch1) {
			winch->Set(0.2);
		} else if(fabs(mLeftY) > threshold) {
			winch->Set(mLeftY / 2);
		} else if(cruise &! switch2) {
			winch->Set(-0.05);
		} else {
			winch->Set(0);
		}

		if(shooterUS->GetValue() < 20) {
			SmartDashboard::PutString("DB/String 9", "Loaded");
		} else {
			SmartDashboard::PutString("DB/String 9", "Feed me, please!");
		}
>>>>>>> 2d52d3808d0307cee83315490cf8b3854e69b8d6
	}//:D

	void TestPeriodic()
	{
		lw->Run();
<<<<<<< HEAD
=======

		buttonVal0 = SmartDashboard::GetBoolean("DB/Button 0", false);
		buttonVal1 = SmartDashboard::GetBoolean("DB/Button 1", false);
		buttonVal2 = SmartDashboard::GetBoolean("DB/Button 2", false);
		buttonVal3 = SmartDashboard::GetBoolean("DB/Button 3", false);

		if(buttonVal0) {
			william->Set(DoubleSolenoid::Value::kReverse);
		} else if(buttonVal1) {
			william->Set(DoubleSolenoid::Value::kForward);
		}

	}

	void DisabledPeriodic()
	{
		buttonVal0 = SmartDashboard::GetBoolean("DB/Button 0", false);
		buttonVal1 = SmartDashboard::GetBoolean("DB/Button 1", false);
		buttonVal2 = SmartDashboard::GetBoolean("DB/Button 2", false);
		buttonVal3 = SmartDashboard::GetBoolean("DB/Button 3", false);
		SmartDashboard::PutString("DB/String 6", "Position: Slider 0");
		fieldPos = SmartDashboard::GetNumber("DB/Slider 0", 0.0);

		if(type == 0) {
			SmartDashboard::PutString("DB/String 0", "0");
		} else if(type > 0) {
			SmartDashboard::PutString("DB/String 0", "1");
		}

		if(SmartDashboard::GetString("DB/String 1", "") == "drive") {
			action = 0;
		} else if(SmartDashboard::GetString("DB/String 1", "") == "breach") {
			action = 1;
		} else if(SmartDashboard::GetString("DB/String 1", "") == "shoot") {
			action = 2;
		} else {
			SmartDashboard::PutString("DB/String 1", "drive");
		}

		if(SmartDashboard::GetString("DB/String 2", "") == "Class A") {
			type = 0;
		} else if(SmartDashboard::GetString("DB/String 2", "") == "Class B") {
			type = 1;
		} else if(SmartDashboard::GetString("DB/String 2", "") == "Class C") {
			type = 2;
		} else if(SmartDashboard::GetString("DB/String 2", "") == "Class D") {
			type = 3;
		} else if(SmartDashboard::GetString("DB/String 2", "") == "Class E") {
			type = 4;
		} else {
			SmartDashboard::PutString("DB/String 2", "Class A");
		}

		if(SmartDashboard::GetString("DB/String 3", "") == "1") {
			typeMod = 0;
		} else if((SmartDashboard::GetString("DB/String 3", "") == "2") && SmartDashboard::GetString("DB/String 2", "") != "Class E") {
			typeMod = 1;
		} else {
			SmartDashboard::PutString("DB/String 3", "1");
		}

		if(buttonVal0) {
			SmartDashboard::PutBoolean("DB/Button 0", false);
			buttonVal0 = false;
			if(action == 0) {
				SmartDashboard::PutString("DB/String 1", "breach");
			} else if(action == 1) {
				SmartDashboard::PutString("DB/String 1", "shoot");
			} else if(action == 2) {
				SmartDashboard::PutString("DB/String 1", "drive");
			}
		}
		if(buttonVal1 == true) {
			SmartDashboard::PutBoolean("DB/Button 1", false);
			buttonVal1 = false;
			if(type == 0) {
				SmartDashboard::PutString("DB/String 2", "Class A");
			} else if(type == 1) {
				SmartDashboard::PutString("DB/String 2", "Class B");
			} else if(type == 2) {
				SmartDashboard::PutString("DB/String 2", "Class C");
			} else if(type == 3) {
				SmartDashboard::PutString("DB/String 2", "Class D");
			} else if(type == 4) {
				SmartDashboard::PutString("DB/String 2", "Class E");
			}
		}
		if(buttonVal2) {
			SmartDashboard::PutBoolean("DB/Button 2", false);
			buttonVal2 = false;
			if(typeMod == 0) {
				SmartDashboard::PutString("DB/String 3", "1");
			} else if(typeMod == 1) {
				SmartDashboard::PutString("DB/String 3", "2");
			}
		}
		if(buttonVal3) {
			SmartDashboard::PutBoolean("DB/Button 3", false);
			buttonVal3 = false;
		}

		if(typeMod == 0) {
			if(SmartDashboard::GetString("DB/String 2", "") == "Class A") {
				SmartDashboard::PutString("DB/String 8", "Portcullis");
			} else if(SmartDashboard::GetString("DB/String 2", "") == "Class B") {
				SmartDashboard::PutString("DB/String 8", "Moat");
			} else if(SmartDashboard::GetString("DB/String 2", "") == "Class C") {
				SmartDashboard::PutString("DB/String 8", "Drawbridge");
			} else if(SmartDashboard::GetString("DB/String 2", "") == "Class D") {
				SmartDashboard::PutString("DB/String 8", "Rock Wall");
			} else if(SmartDashboard::GetString("DB/String 2", "") == "Class E") {
				SmartDashboard::PutString("DB/String 8", "Low Bar");
			}
		} else if(typeMod == 1) {
			if(SmartDashboard::GetString("DB/String 2", "") == "Class A") {
				SmartDashboard::PutString("DB/String 8", "Cheval de Frise");
			} else if(SmartDashboard::GetString("DB/String 2", "") == "Class B") {
				SmartDashboard::PutString("DB/String 8", "Ramparts");
			} else if(SmartDashboard::GetString("DB/String 2", "") == "Class C") {
				SmartDashboard::PutString("DB/String 8", "Sally Port");
			} else if(SmartDashboard::GetString("DB/String 2", "") == "Class D") {
				SmartDashboard::PutString("DB/String 8", "Rough Terrain");
			}
		}

/*		if(dir != 0 && buttonVal3) {
			SmartDashboard::PutBoolean("DB/Button 3", false);
			buttonVal3 = false;
			dir = 0;
		}

		if(dir == 0) {
			SmartDashboard::PutString("DB/String 0", "Root");
			SmartDashboard::PutString("DB/String 1", "Class A");
			SmartDashboard::PutString("DB/String 2", "Class B");
			SmartDashboard::PutString("DB/String 3", "Class C");
			SmartDashboard::PutString("DB/String 4", "More");
			if(buttonVal0) {
				SmartDashboard::PutBoolean("DB/Button 0", false);
				buttonVal0 = false;
				dir = 1;
			} else if(buttonVal1) {
				SmartDashboard::PutBoolean("DB/Button 1", false);
				buttonVal1 = false;
				dir = 2;
			} else if(buttonVal2) {
				SmartDashboard::PutBoolean("DB/Button 2", false);
				buttonVal2 = false;
				dir = 3;
			} else if(buttonVal3) {
				SmartDashboard::PutBoolean("DB/Button 3", false);
				buttonVal3 = false;
				dir = 4;
			}
		} else if(dir == 1) {
			SmartDashboard::PutString("DB/String 0", "Class A:");
			SmartDashboard::PutString("DB/String 1", "Auto 1");
			SmartDashboard::PutString("DB/String 2", "Auto 2");
			SmartDashboard::PutString("DB/String 3", "Auto 3");
			SmartDashboard::PutString("DB/String 4", "Return");
			if(buttonVal0) {
				mode = 1;
			} else if(buttonVal1) {
				mode = 2;
			} else if(buttonVal2) {
				mode = 3;
			}
		} else if(dir == 2) {
			SmartDashboard::PutString("DB/String 0", "Class B:");
			SmartDashboard::PutString("DB/String 1", "Auto 4");
			SmartDashboard::PutString("DB/String 2", "Auto 5");
			SmartDashboard::PutString("DB/String 3", "Auto 6");
			SmartDashboard::PutString("DB/String 4", "Return");
			if(buttonVal0) {
				mode = 4;
			} else if(buttonVal1) {
				mode = 5;
			} else if(buttonVal2) {
				mode = 6;
			}
		} else if(dir == 3) {
			SmartDashboard::PutString("DB/String 0", "Class C:");
			SmartDashboard::PutString("DB/String 1", "Auto 7");
			SmartDashboard::PutString("DB/String 2", "Auto 8");
			SmartDashboard::PutString("DB/String 3", "Auto 9");
			SmartDashboard::PutString("DB/String 4", "Return");
			if(buttonVal0) {
				mode = 7;
			} else if(buttonVal1) {
				mode = 8;
			} else if(buttonVal2) {
				mode = 9;
			}
		} else if(dir == 4) {
			SmartDashboard::PutString("DB/String 0", "More:");
			SmartDashboard::PutString("DB/String 1", "Class D");
			SmartDashboard::PutString("DB/String 2", "Class E");
			SmartDashboard::PutString("DB/String 3", "Misc.");
			SmartDashboard::PutString("DB/String 4", "Return");
			if(buttonVal0) {
				dir = 41;
			} else if(buttonVal1) {
				dir = 42;
			} else if(buttonVal2) {
				dir = 43;
			}
		}*/
>>>>>>> 2d52d3808d0307cee83315490cf8b3854e69b8d6
	}
};

START_ROBOT_CLASS(Robot)
