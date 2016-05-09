#include "WPILib.h"
//#include <iostream>

/*
*What the things do:

lshifter = Left Shifter
william = Right Shifter
lDrive = Left Drive 1 and 2
rDrive = Right Drive 1 and 2
arm1 = arm that delivers the hook
shooter1 = shooter motor 1
shooter2 = shooter motor 2
winch = old shooter lift (may be applicable to second robot)
winch2 = Robot Lifting Winch
flipper = ball piston
pos = shooter up and down pistons
*/

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
	Talon *winch2;
	//CANTalon *flipper;
	//CANTalon *flipper2;
	DoubleSolenoid *lShifter;
	//DoubleSolenoid *rShifter;
	DoubleSolenoid *william;
	DoubleSolenoid *flipper;
	DoubleSolenoid *pos;
	//DoubleSolenoid *flipper2;
	Joystick *driveStick;
	Joystick *manipulatorStick;
	Compressor *steven;
	DigitalInput *switch1;
	DigitalInput *switch2;
	DigitalInput *switch3;
	DigitalInput *switch4;
	DigitalInput *optical;
	AnalogInput *sonic;
	ADXRS450_Gyro *gyro;
	ADXL362 *accel;
	//I2C *arduino;
	/*DigitalOutput *sonicOut;
	PWM *sonicIn;*/
	/*Image *frame;
	Image *frame2;
	IMAQdxSession *session;*/

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
		winch2 = new Talon(0);
		//flipper = new CANTalon(7);
		//flipper2 = new CANTalon(8);
		lShifter = new DoubleSolenoid(0,1);
		william = new DoubleSolenoid(2,3);
		flipper = new DoubleSolenoid(4,5);
		pos = new DoubleSolenoid(6,7);
		//rShifter = new DoubleSolenoid(6,7);
		driveStick = new Joystick(0);
		manipulatorStick = new Joystick(1);
		steven = new Compressor(0);
		switch1 = new DigitalInput(0);
		switch2 = new DigitalInput(1);
		switch3 = new DigitalInput(2);
		switch4 = new DigitalInput(3);
		optical = new DigitalInput(4);
		sonic = new AnalogInput(0);
		gyro = new ADXRS450_Gyro();
		accel = new ADXL362();
		//arduino = new I2C(4);
		//sonicOut = new DigitalOutput(4);
		//sonicIn = new PWM(0);
		//frame = new ImageType(ColorImage);
		//session = new IMAQdxSession;

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
	bool dUp = false;
	bool dRight = false;
	bool dDown = false;
	bool dLeft = false;
	bool dUpR = false;
	bool dUpL = false;
	bool dDownR = false;
	bool dDownL = false;
	bool autoShot = false;
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
	double speed = 0;
	double imageWidth = 0;
	double COGX = 0;
	double COGY = 0;
	double centerPos = 0;
	double turnDistance = 0;
	double shooterPos = 0;
	double shootCount = 0;
	double targetCenter = 150; // change me for the target center *note camera is offset
	double minTargetmargin = 6;
	double maxTargetmargin = -6;
	std::shared_ptr<NetworkTable> roboRealm;
	bool testrun = false;
	//double gearRatio = 18.75;
	//double gearRatio = 15.32;
	/*double distance = 0;
	double pulse = 0;
	const double inches = 0.125;*/

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
		printf("Good Morning! ");
		roboRealm = NetworkTable::GetTable("SmartDashboard");

		/*frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
		imaqColorThreshold(frame2, frame, 0, 0, Range(0), Range(255), Range(0);*/

//		CameraServer::GetInstance()->SetQuality(30);
//		CameraServer::GetInstance()->StartAutomaticCapture("cam1");

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


	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString line to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional comparisons to the if-else structure below with additional strings.
	 * If using the SendableChooser make sure to add them to the chooser code above as well.
	 */

	/*void RobotPeriodic()
	{
		SmartDashboard::PutNumber("DB/Slider 2", accel->GetY());
		SmartDashboard::PutNumber("DB/Slider 3", gyro->GetAngle());
	}*/

	void AutonomousInit()
	{
		if(action == 0) { //Drive
			lShifter->Set(DoubleSolenoid::Value::kForward);
			lDrive1->Set(-.475 / 1.223890339425587);
			rDrive1->Set(.475 / 1.223890339425587);
			lDrive2->Set(-.475 / 1.223890339425587);
			rDrive2->Set(.475 / 1.223890339425587);
			Wait(2);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
		} else if(action != 0 && ((type == 0 && typeMod == 0) || (type == 4 && typeMod == 0))) {
			lShifter->Set(DoubleSolenoid::Value::kReverse); //Low Bar & Portcullis
			flipper->Set(DoubleSolenoid::Value::kForward);
			Wait(2);
			lDrive1->Set(-.475);
			rDrive1->Set(.475);
			lDrive2->Set(-.475);
			rDrive2->Set(.475);
			Wait(4);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
			/*Wait(0.5);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
			shooter1m->Set(0.4);
			shooter2m->Set(-0.4);
			flipper->Set(DoubleSolenoid::Value::kReverse);
			Wait(2);
			william->Set(DoubleSolenoid::Value::kReverse);
			Wait(0.5);
			flipper->Set(DoubleSolenoid::Value::kForward);*/
		} else if(action != 0 && ((type == 1 && typeMod == 0) || (type == 3 && typeMod == 0) || (type == 3 && typeMod == 1))) {
			lShifter->Set(DoubleSolenoid::Value::kReverse); //Long Drive
			lDrive1->Set(-.555);
			rDrive1->Set(.555);
			lDrive2->Set(-.555);
			rDrive2->Set(.555);
			Wait(4);
			if(type == 1 && typeMod == 0) {
				Wait(1);
			}
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
		} else if(action == 1 && (type == 1 && typeMod == 1)) { // Ramparts
			lShifter->Set(DoubleSolenoid::Value::kReverse);
			lDrive1->Set(-1);
			rDrive1->Set(1);
			lDrive2->Set(-1);
			rDrive2->Set(1);
			Wait(0.5);
			lShifter->Set(DoubleSolenoid::Value::kForward);
			Wait(1);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
		} else if(action != 0 && (type == 0 && typeMod == 1)) { // Cheval de Frise
			lShifter->Set(DoubleSolenoid::Value::kReverse);
			lDrive1->Set(-.475 / 1.223890339425587);
			rDrive1->Set(.472 / 1.223890339425587);
			lDrive2->Set(-.475 / 1.223890339425587);
			rDrive2->Set(.472 / 1.223890339425587);
			Wait(1.6);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
			flipper->Set(DoubleSolenoid::Value::kForward);
			Wait(1.5);
			lDrive1->Set(-.475 / 1.223890339425587);
			rDrive1->Set(.475 / 1.223890339425587);
			lDrive2->Set(-.475 / 1.223890339425587);
			rDrive2->Set(.475 / 1.223890339425587);
			Wait(0.5);
			flipper->Set(DoubleSolenoid::Value::kReverse);
			Wait(1.5);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
			Wait(1);
			lDrive1->Set(-.475 / 1.223890339425587);
			rDrive1->Set(.475 / 1.223890339425587);
			lDrive2->Set(-.475 / 1.223890339425587);
			rDrive2->Set(.475 / 1.223890339425587);
			Wait(1.5);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
		} else if(action != 0 && (type == 2 && typeMod == 0)) { //Drawbridge
			lShifter->Set(DoubleSolenoid::Value::kReverse);
			lDrive1->Set(-.475 / 1.223890339425587);
			rDrive1->Set(.475 / 1.223890339425587);
			lDrive2->Set(-.475 / 1.223890339425587);
			rDrive2->Set(.475 / 1.223890339425587);
			arm1->Set(.85);
			Wait(1.25);
			arm1->Set(0);
			Wait(.75);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
			Wait(0.5);
			arm1->Set(-.45);
			Wait(0.1);
			lDrive1->Set(.3 / 1.223890339425587);
			rDrive1->Set(-.3 / 1.223890339425587);
			lDrive2->Set(.3 / 1.223890339425587);
			rDrive2->Set(-.3 / 1.223890339425587);
			Wait(2.0);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
			Wait(.2);
			lDrive1->Set(-.15 / 1.223890339425587);
			rDrive1->Set(.15 / 1.223890339425587);
			lDrive2->Set(-.15 / 1.223890339425587);
			rDrive2->Set(.15 / 1.223890339425587);
			Wait(1.15);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
			Wait(0.85);
			arm1->Set(0);
			flipper->Set(DoubleSolenoid::Value::kForward);
			Wait(1.5);
			lDrive1->Set(.15 / 1.223890339425587);
			rDrive1->Set(-.15 / 1.223890339425587);
			lDrive2->Set(.15 / 1.223890339425587);
			rDrive2->Set(-.15 / 1.223890339425587);
			Wait(2);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
			Wait(0.5);
			lDrive1->Set(-.475 / 1.223890339425587);
			rDrive1->Set(.475 / 1.223890339425587);
			lDrive2->Set(-.475 / 1.223890339425587);
			rDrive2->Set(.475 / 1.223890339425587);
			Wait(1.5);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
			flipper->Set(DoubleSolenoid::Value::kReverse);
		}

		/*if(fieldPos > 3) {
			lDrive1->Set(-0.45);
			rDrive1->Set(-0.45);
			lDrive2->Set(-0.45);
			rDrive2->Set(-0.45);
		} else if(fieldPos < 3)	{
			lDrive1->Set(0.45);
			rDrive1->Set(0.45);
			lDrive2->Set(0.45);
			rDrive2->Set(0.45);
		}*/

		if(action == 2) {
			COGX = roboRealm->GetNumber("COG_X", -1.0);
			COGY = roboRealm->GetNumber("COG_Y", -1.0);
			centerPos = imageWidth / 2 - COGX;
			turnDistance = centerPos / 10;
		}

		//if(action == 2) {
			/*lDrive1->Set(-.475);
			rDrive1->Set(-.475);
			lDrive2->Set(-.475);
			rDrive2->Set(-.475);*/

			//Wait(2);


		//}

		/*autoSelected = *((std::string*)chooser->GetSelected());
		//std::string autoSelected = SmartDashboard::GetString("Auto Selector", autoNameDefault);
		std::cout << "Auto selected: " << autoSelected << std::endl;

		if(autoSelected == autoNameCustom){
			//Custom Auto goes here
		} else {
			//Default Auto goes here
		}*/
	}

	void AutonomousPeriodic()
	{
		SmartDashboard::PutNumber("DB/Slider 3", gyro->GetAngle());

		if(action == 2) {
			turnDistance = (centerPos / 10) - gyro->GetAngle();
			SmartDashboard::PutNumber("DB/Slider 2", shooterPos);

			if(COGX != -1) {
				if(turnDistance > 1.5) {
					lDrive1->Set(-0.45);
					rDrive1->Set(-0.45);
					lDrive2->Set(-0.45);
					rDrive2->Set(-0.45);
				} else if(turnDistance < -1.5) {
					lDrive1->Set(0.45);
					rDrive1->Set(0.45);
					lDrive2->Set(0.45);
					rDrive2->Set(0.45);
				} else {
					COGX = roboRealm->GetNumber("COG_X", -1.0);
					COGY = roboRealm->GetNumber("COG_Y", -1.0);
					centerPos = imageWidth / 2 - COGX;
					turnDistance = (centerPos / 10) - gyro->GetAngle();
				}
			} else {
				printf("Aaaaaaand it's broke. ");
			}

			/*if(shooterPos < 90) {
				winch->Set(-1);
			} else */if(fabs(turnDistance) < 1.5) {
				winch->Set(0);
				shooter1->Set(-0.75);
				shooter2->Set(0.75);
				Wait(0.5);
				william->Set(DoubleSolenoid::Value::kReverse);
			} else {
				winch->Set(-0.05);
			}

			if(switch1->Get() == false) {
				shooterPos = 0;
			} else {
				shooterPos = shooterPos - winch->Get();
			}
			Wait(0.005);

		}

		/*if(action == 0) { //Drive
			lDrive1->Set(-speed);
			rDrive1->Set(speed);
			lDrive2->Set(-speed);
			rDrive2->Set(speed);
		}*/
		/*if(autoSelected == autoNameCustom){
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
		}*/
	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		//CameraServer::GetInstance()->StartAutomaticCapture("cam0");
		steven->SetClosedLoopControl(true); //Caleb: A+
		SmartDashboard::PutNumber("DB/Slider 0", accel->GetX());
		SmartDashboard::PutNumber("DB/Slider 1", accel->GetY());
//		SmartDashboard::PutNumber("DB/Slider 2", accel->GetZ());
		SmartDashboard::PutNumber("DB/Slider 3", gyro->GetAngle());
		//frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);

		//distance = (sonicIn->GetRaw() * inches);
		//sonicOut->Pulse(10);

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
		mRightTrigger = (manipulatorStick->GetRawAxis(3));
		if(fabs(mRightTrigger) < (threshold))
			mRightTrigger = 0;
		mLeftTrigger = (manipulatorStick->GetRawAxis(2));
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

		rDrive1->Set(-(leftY - leftX));
		rDrive2->Set(-(leftY - leftX));
		lDrive1->Set(leftY + leftX);
		lDrive2->Set(leftY + leftX);

		//TODO find a better button
		/*if (driveStick->GetRawButton(7)) {
			AutoHighGoal();
		} else
		*/ if(driveStick->GetRawButton(3)) {
			lShifter->Set(DoubleSolenoid::Value::kReverse);
			driveStick->SetRumble(driveStick->kLeftRumble, 1);
			driveStick->SetRumble(driveStick->kRightRumble, 1);
			Wait(0.01);
			driveStick->SetRumble(driveStick->kLeftRumble, 0);
			driveStick->SetRumble(driveStick->kRightRumble, 0);
			//rShifter->Set(DoubleSolenoid::Value::kForward);
		} else if(driveStick->GetRawButton(2)) {
			lShifter->Set(DoubleSolenoid::Value::kForward);
			driveStick->SetRumble(driveStick->kLeftRumble, 1);
			driveStick->SetRumble(driveStick->kRightRumble, 1);
			Wait(0.01);
			driveStick->SetRumble(driveStick->kLeftRumble, 0);
			driveStick->SetRumble(driveStick->kRightRumble, 0);
			//rShifter->Set(DoubleSolenoid::Value::kReverse);
		}



		// thing that takes the hook to the bar thingy
		if(driveStick->GetRawButton(6)) {
			if(rightY > threshold && switch3->Get()) {
				arm1->Set(rightY / 1.5);
			} else if(rightY < threshold && switch4->Get()) {
				arm1->Set(rightY / 2);
			} else {
				arm1->Set(0);
			}
		} else if(manipulatorStick->GetRawButton(6)) {
			if(mRightY > threshold && switch3->Get()) {
				arm1->Set(mRightY / 1.5);
			} else if(mRightY < threshold && switch4->Get()) {
				arm1->Set(mRightY / 2);
			} else {
				arm1->Set(0);
			}
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

		/*if(manualShoot) {
			if(driveStick->GetRawButton(8)) {
				if(fabs(rightTrigger)> threshold) {
					shooter1->Set(rightTrigger / 2.5);
				} else if(fabs(mRightTrigger) > threshold) {
					shooter1->Set(mRightTrigger / 2.5);
				} else {
					shooter1->Set(0);
				}
			} else {
				if(fabs(rightTrigger)> threshold) {
					shooter1->Set(-rightTrigger / 1.2);
				} else if(fabs(mRightTrigger) > threshold) {
					shooter1->Set(-mRightTrigger / 1.2);
				} else {
					shooter1->Set(0);
				}
			}
			if(driveStick->GetRawButton(7)) {
				if(fabs(leftTrigger)> threshold) {
					shooter2->Set(-leftTrigger / 2.5);
				} else if(fabs(mLeftTrigger) > threshold) {
					shooter2->Set(-mLeftTrigger / 2.5);
				} else {
					shooter2->Set(0);
				}
			} else {
				if(fabs(leftTrigger)> threshold) {
					shooter2->Set(leftTrigger / 1.2);
				} else if(fabs(mLeftTrigger) > threshold) {
					shooter2->Set(mLeftTrigger / 1.2);
				} else {
					shooter2->Set(0);
				}
			}
		} else {*/
		/*if(fabs(rightTrigger)> threshold) {
			shooter1->Set(-rightTrigger / 1.25);
			shooter2->Set(rightTrigger / 1.25);
		} else if(fabs(mRightTrigger) > threshold) {
			shooter1->Set(-mRightTrigger / 1.25);
			shooter2->Set(mRightTrigger / 1.25);
			manipulatorStick->SetRumble(manipulatorStick->kLeftRumble, mRightTrigger);
			manipulatorStick->SetRumble(manipulatorStick->kRightRumble, mRightTrigger);
		} else if(fabs(leftTrigger)> threshold) {
			shooter1->Set(leftTrigger / 2.8);
			shooter2->Set(-leftTrigger / 2.8);
		} else if(fabs(mLeftTrigger) > threshold) {
			shooter1->Set(mLeftTrigger / 2.8);
			shooter2->Set(-mLeftTrigger / 2.8);
			manipulatorStick->SetRumble(manipulatorStick->kLeftRumble, mLeftTrigger);
			manipulatorStick->SetRumble(manipulatorStick->kRightRumble, mLeftTrigger);
		} else {
			shooter1->Set(0);
			shooter2->Set(0);
			manipulatorStick->SetRumble(manipulatorStick->kLeftRumble, 0);
			manipulatorStick->SetRumble(manipulatorStick->kRightRumble, 0);
		}*/
		//}


		if(driveStick->GetRawButton(5)) {
			william->Set(DoubleSolenoid::Value::kReverse);
			driveStick->SetRumble(driveStick->kLeftRumble, 0.5);
			driveStick->SetRumble(driveStick->kRightRumble, 0.5);
		} else if(manipulatorStick->GetRawButton(5)) {
			william->Set(DoubleSolenoid::Value::kReverse);
			driveStick->SetRumble(driveStick->kLeftRumble, 0.5);
			driveStick->SetRumble(driveStick->kRightRumble, 0.5);
		} else {
			william->Set(DoubleSolenoid::Value::kForward);
			driveStick->SetRumble(driveStick->kLeftRumble, 0);
			driveStick->SetRumble(driveStick->kRightRumble, 0);
		}

		/*if(dUp) {
			william->Set(DoubleSolenoid::Value::kReverse);
		} else if(dDown) {
			william->Set(DoubleSolenoid::Value::kForward);
		}*/

		if(dRight) {
			turnDistance = (centerPos / 10) - gyro->GetAngle();
					//SmartDashboard::PutNumber("DB/Slider 2", shooterPos);
					COGX = (SmartDashboard::GetNumber("COG_X", -1.0) + 55);

					if(COGX != -1) {
						if(COGX < 150) {
							lDrive1->Set(0.25);
							rDrive1->Set(0.25);
							lDrive2->Set(0.25);
							rDrive2->Set(0.25);
						} else if(COGX > 210) {
							lDrive1->Set(-0.25);
							rDrive1->Set(-0.25);
							lDrive2->Set(-0.25);
							rDrive2->Set(-0.25);

						} else if(COGX < 170 && COGX > 150) {
							lDrive1->Set(0.15);
							rDrive1->Set(0.15);
							lDrive2->Set(0.15);
							rDrive2->Set(0.15);
						} else if(COGX > 190 && COGX > 210) {
							lDrive1->Set(-0.15);
							rDrive1->Set(-0.15);
							lDrive2->Set(-0.15);
							rDrive2->Set(-0.15);
						} else {
							lDrive1->Set(0);
							rDrive1->Set(0);
							lDrive2->Set(0);
							rDrive2->Set(0);
						}
					}

			if(COGX > 165 && COGX < 195) {
						winch->Set(0);
						shooter1->Set(-0.8);
						shooter2->Set(0.8);
						shootCount = shootCount + 1;
						if(shootCount > 5) {
							lDrive1->Set(0);
							rDrive1->Set(0);
							lDrive2->Set(0);
							rDrive2->Set(0);
							driveStick->SetRumble(driveStick->kLeftRumble, 0.5);
							driveStick->SetRumble(driveStick->kRightRumble, 0.5);
							Wait(0.5);
							william->Set(DoubleSolenoid::Value::kReverse);
						}
					} else {
						winch->Set(0);
					}
			//driveStick->SetRumble(driveStick->kLeftRumble, 0.5);
			//driveStick->SetRumble(driveStick->kRightRumble, 0.5);
			//manualShoot = true;
		} else {
			if(fabs(rightTrigger)> threshold) {
						shooter1->Set(-rightTrigger / 1.25);
						shooter2->Set(rightTrigger / 1.25);
					} else if(fabs(mRightTrigger) > threshold) {
						shooter1->Set(-mRightTrigger / 1.25);
						shooter2->Set(mRightTrigger / 1.25);
						manipulatorStick->SetRumble(manipulatorStick->kLeftRumble, mRightTrigger);
						manipulatorStick->SetRumble(manipulatorStick->kRightRumble, mRightTrigger);
					} else if(fabs(leftTrigger)> threshold) {
						shooter1->Set(leftTrigger / 2.3);
						shooter2->Set(-leftTrigger / 2.3);
					} else if(fabs(mLeftTrigger) > threshold) {
						shooter1->Set(mLeftTrigger / 2.3);
						shooter2->Set(-mLeftTrigger / 2.3);
						manipulatorStick->SetRumble(manipulatorStick->kLeftRumble, mLeftTrigger);
						manipulatorStick->SetRumble(manipulatorStick->kRightRumble, mLeftTrigger);
					} else {
						shooter1->Set(0);
						shooter2->Set(0);
						manipulatorStick->SetRumble(manipulatorStick->kLeftRumble, 0);
						manipulatorStick->SetRumble(manipulatorStick->kRightRumble, 0);
					}
		}

		/*if(driveStick->GetRawButton(8) && switch1->Get()) {
			winch->Set(0.5);
		} else if(driveStick->GetRawButton(7) && switch2->Get()) {
			winch->Set(-0.5);
		} else if(manipulatorStick->GetRawButton(8) && switch1->Get()) {
			winch->Set(0.5);
		} else if(manipulatorStick->GetRawButton(7) && switch2->Get()) {
			winch->Set(-0.5);
		} else */
		if(dUp && switch2->Get()) {
//			winch->Set(0.5);
			pos->Set(DoubleSolenoid::Value::kReverse);
		} else if(dDown && switch1->Get()) {
//			winch->Set(-0.5);
			pos->Set(DoubleSolenoid::Value::kForward);
		} else if((manipulatorStick->GetPOV() == 0) && switch2->Get()) {
			winch->Set(0.5);
		} else if((manipulatorStick->GetPOV() == 180) && switch1->Get()) {
			winch->Set(-0.5);
		} else if(fabs(mLeftY) > threshold) {
			if(mLeftY > threshold && switch1->Get()) {
				winch->Set(mLeftY);
			} else if(mLeftY < threshold && switch2->Get()) {
				winch->Set(mLeftY);
			}
		/*} else if(cruise && switch2->Get()) {
			winch->Set(-0.05);*/
		} else {
			winch->Set(0);
		}

		if(driveStick->GetRawButton(7)){
			winch2->Set(-1);
		} else if(driveStick->GetRawButton(8)){
			winch2->Set(1);
		} else if(manipulatorStick->GetRawButton(7)){
			winch2->Set(-1);
		} else if(manipulatorStick->GetRawButton(8)){
			winch2->Set(1);
		} else {
			winch2->Set(-0.05);
		}

/*		if(switch1->Get() == false) {
			shooterPos = 0;
		} else {
			shooterPos = shooterPos - winch->Get();
		}*/

		/*if(pencoder->Get()) {
			if(dUp) {
				shooterPos = shooterPos + 1;
			} else if(dDown) {
				shooterPos = shooterPos - 1;
			}
		}*/

		if(dLeft && manipulatorStick->GetPOV() == 270) {
			arm1->Set(0.6);
			Wait(1.2);
			arm1->Set(0);
			Wait(1);
		}

		if(sonic->GetVoltage() < 0.12) {
			SmartDashboard::PutString("DB/String 9", "Loaded");
		} else {
			SmartDashboard::PutString("DB/String 9", "Feed me, please!");
		}

		SmartDashboard::PutNumber("DB/Slider 2", shooterPos);

		//SmartDashboard::PutNumber("DB/Slider 1", sonic->GetVoltage());

	Wait(0.005);
	}//:D

	void TestInit()
	{
		testrun = true;
	}


	void TestPeriodic()
	{
		if (!testrun) return;

		AutoHighGoal();
	}


	void AutoHighGoal() {
		COGX = (SmartDashboard::GetNumber("COG_X", -1.0));

		if(COGX != -1) {
			if(COGX < targetCenter - maxTargetmargin) {
				lDrive1->Set(0.25);
				rDrive1->Set(0.25);
				lDrive2->Set(0.25);
				rDrive2->Set(0.25);
			} else if(COGX > targetCenter + maxTargetmargin) {
				lDrive1->Set(-0.25);
				rDrive1->Set(-0.25);
				lDrive2->Set(-0.25);
				rDrive2->Set(-0.25);

			} else if(COGX < targetCenter - minTargetmargin) {
				lDrive1->Set(0.1);
				rDrive1->Set(0.1);
				lDrive2->Set(0.1);
				rDrive2->Set(0.1);
			} else if(COGX > targetCenter + minTargetmargin) {
				lDrive1->Set(-0.1);
				rDrive1->Set(-0.1);
				lDrive2->Set(-0.1);
				rDrive2->Set(-0.1);
			} else {
				lDrive1->Set(0);
				rDrive1->Set(0);
				lDrive2->Set(0);
				rDrive2->Set(0);
			}
		}

		if(COGX > targetCenter - minTargetmargin && COGX < targetCenter + minTargetmargin) {
			//winch->Set(0);
			pos->Set(DoubleSolenoid::Value::kForward);
			shooter1->Set(-0.8);
			shooter2->Set(0.8);
			//shootCount = shootCount + 1;
			//if(shootCount > 5) {
			Wait(0.2);
				lDrive1->Set(0);
				rDrive1->Set(0);
				lDrive2->Set(0);
				rDrive2->Set(0);
				driveStick->SetRumble(driveStick->kLeftRumble, 0.5);
				driveStick->SetRumble(driveStick->kRightRumble, 0.5);
				Wait(1);
				william->Set(DoubleSolenoid::Value::kReverse);
				Wait(0.1);
				william->Set(DoubleSolenoid::Value::kForward);

				pos->Set(DoubleSolenoid::Value::kReverse);
		}
	}

	void DisabledPeriodic()
	{
		buttonVal0 = SmartDashboard::GetBoolean("DB/Button 0", false);
		buttonVal1 = SmartDashboard::GetBoolean("DB/Button 1", false);
		buttonVal2 = SmartDashboard::GetBoolean("DB/Button 2", false);
		buttonVal3 = SmartDashboard::GetBoolean("DB/Button 3", false);
		SmartDashboard::PutString("DB/String 6", "Position: Slider 0");
//		fieldPos = SmartDashboard::GetNumber("DB/Slider 0", 0.0);

		SmartDashboard::PutNumber("DB/Slider 3", gyro->GetAngle());
//		SmartDashboard::PutNumber("DB/Slider 2", accel->GetY());
//		SmartDashboard::PutNumber("DB/Slider 0", accel->GetX());
//		SmartDashboard::PutNumber("DB/Slider 0", optical->Get());
		SmartDashboard::PutNumber("DB/Slider 1", accel->GetY());

		if(optical->Get() == true) {
			SmartDashboard::PutNumber("DB/Slider 0", 5);
		} else {
			SmartDashboard::PutNumber("DB/Slider 0", 0);
		}

		driveStick->SetRumble(driveStick->kLeftRumble, 0);
		driveStick->SetRumble(driveStick->kRightRumble, 0);

		if(sonic->GetVoltage() < 0.13) {
			SmartDashboard::PutString("DB/String 9", "Loaded");
		} else {
			SmartDashboard::PutString("DB/String 9", "Feed me, please!");
		}
		SmartDashboard::PutNumber("DB/Slider 1", sonic->GetVoltage());

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

//		while(IsDisabled())
//		{
//			Wait(0.005);
//		}
	}
};

START_ROBOT_CLASS(Robot)
