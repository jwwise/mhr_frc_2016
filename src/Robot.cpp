#include "WPILib.h"
#include <vector>
#include <cmath>
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
	AnalogInput *sonic;

	//Images
	Image *frame;
	Image *binaryFrame;
	IMAQdxSession session;

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
		sonic = new AnalogInput(0);
		/*frame = new Image(0);
		binaryFrame = new Image(1);*/
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
	bool manualShoot = false;
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
	double shooterPos = 0;
	double speed = 0;

	int imaqError;

	//A structure to hold measurements of a particle
		struct ParticleReport {
			double PercentAreaToImageArea;
			double Area;
			double BoundingRectLeft;
			double BoundingRectTop;
			double BoundingRectRight;
			double BoundingRectBottom;
		};

		//Structure to represent the scores for the various tests used for target identification
		struct Scores {
			double Area;
			double Aspect;
		};

		//Constants
		Range RING_HUE_RANGE = {101, 64};	//Default hue range for ring light
		Range RING_SAT_RANGE = {88, 255};	//Default saturation range for ring light
		Range RING_VAL_RANGE = {134, 255};	//Default value range for ring light
		double AREA_MINIMUM = 0.5; //Default Area minimum for particle as a percentage of total image area
		double LONG_RATIO = 2.22; //long side = 26.9 / height = 12.1 = 2.22
		double SHORT_RATIO = 1.4; //short side = 16.9 / height = 12.1 = 1.4
		double SCORE_MIN = 75.0;  //Minimum score to be considered a tote
		double VIEW_ANGLE = 48.5; //View angle fo camera, set to Axis m1011 by default, 64 for m1013, 51.7 for 206, 52 for HD3000 square, 60 for HD3000 640x480
		ParticleFilterCriteria2 criteria[1];
		ParticleFilterOptions2 filterOptions = {0,0,1,1};
		Scores scores;
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
		// create images
		frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
		binaryFrame = imaqCreateImage(IMAQ_IMAGE_U8, 0);

		imaqError = IMAQdxOpenCamera("cam0", IMAQdxCameraControlModeController, &session);
		if(imaqError != IMAQdxErrorSuccess) {
			DriverStation::ReportError("IMAQdxOpenCamera error: " + std::to_string((long)imaqError) + "\n");
		}
		imaqError = IMAQdxConfigureGrab(session);
		if(imaqError != IMAQdxErrorSuccess) {
			DriverStation::ReportError("IMAQdxConfigureGrab error: " + std::to_string((long)imaqError) + "\n");
		}

		/*frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
		imaqColorThreshold(frame2, frame, 0, 0, Range(0), Range(255), Range(0);*/


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
	void AutonomousInit()
	{
		if(action == 0) { //Drive
			lShifter->Set(DoubleSolenoid::Value::kForward);
			speed = .475;
			Wait(2);
			speed = 0;
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
			Wait(1.15);
			arm1->Set(0);
			Wait(.85);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
			Wait(0.5);
			arm1->Set(-.3);
			Wait(0.1);
			lDrive1->Set(.3);
			rDrive1->Set(-.3);
			lDrive2->Set(.3);
			rDrive2->Set(-.3);
			Wait(2.0);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
			Wait(.2);
			lDrive1->Set(-.15);
			rDrive1->Set(.15);
			lDrive2->Set(-.15);
			rDrive2->Set(.15);
			Wait(1.15);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
			Wait(0.85);
			arm1->Set(0);
			flipper->Set(DoubleSolenoid::Value::kForward);
			Wait(1.5);
			lDrive1->Set(.15);
			rDrive1->Set(-.15);
			lDrive2->Set(.15);
			rDrive2->Set(-.15);
			Wait(2);
			lDrive1->Set(0);
			rDrive1->Set(0);
			lDrive2->Set(0);
			rDrive2->Set(0);
			Wait(0.5);
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
		if(action == 0) { //Drive
			lDrive1->Set(-speed);
			rDrive1->Set(speed);
			lDrive2->Set(-speed);
			rDrive2->Set(speed);
		}
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
		steven->SetClosedLoopControl(true); //Caleb: A
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

		if(driveStick->GetRawButton(3)) {
			lShifter->Set(DoubleSolenoid::Value::kForward);
			//rShifter->Set(DoubleSolenoid::Value::kForward);
		} else if(driveStick->GetRawButton(2)) {
			lShifter->Set(DoubleSolenoid::Value::kReverse);
			//rShifter->Set(DoubleSolenoid::Value::kReverse);
		}


		if(driveStick->GetRawButton(6)) {
			if(rightY > threshold && switch3->Get()) {
				arm1->Set(rightY);
			} else if(rightY < threshold && switch4->Get()) {
				arm1->Set(rightY);
			} else {
				arm1->Set(0);
			}
		} else if(manipulatorStick->GetRawButton(6)) {
			if(mRightY > threshold && switch3->Get()) {
				arm1->Set(mRightY);
			} else if(mRightY < threshold && switch4->Get()) {
				arm1->Set(mRightY);
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

		if(manualShoot) {
			if(driveStick->GetRawButton(8)) {
				if(fabs(rightTrigger)> threshold) {
					shooter1->Set(-rightTrigger / 2.5);
				} else if(fabs(mRightTrigger) > threshold) {
					shooter1->Set(-mRightTrigger / 2.5);
				} else {
					shooter1->Set(0);
				}
			} else {
				if(fabs(rightTrigger)> threshold) {
					shooter1->Set(rightTrigger / 1.2);
				} else if(fabs(mRightTrigger) > threshold) {
					shooter1->Set(mRightTrigger / 1.2);
				} else {
					shooter1->Set(0);
				}
			}
			if(driveStick->GetRawButton(7)) {
				if(fabs(leftTrigger)> threshold) {
					shooter2->Set(leftTrigger / 2.5);
				} else if(fabs(mLeftTrigger) > threshold) {
					shooter2->Set(mLeftTrigger / 2.5);
				} else {
					shooter2->Set(0);
				}
			} else {
				if(fabs(leftTrigger)> threshold) {
					shooter2->Set(-leftTrigger / 1.2);
				} else if(fabs(mLeftTrigger) > threshold) {
					shooter2->Set(-mLeftTrigger / 1.2);
				} else {
					shooter2->Set(0);
				}
			}
		} else {
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
		}

		if(switch1->Get() == false) {
			shooterPos = 0;
		} else {
			shooterPos = shooterPos - winch->Get();
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
			manualShoot = true;
		} else if(dLeft || manipulatorStick->GetPOV() == 270) {
			manualShoot = false;
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
			winch->Set(-0.5);
		} else if(dDown && switch1->Get()) {
			winch->Set(0.5);
		} else if((manipulatorStick->GetPOV() == 0) && switch2->Get()) {
			winch->Set(-0.5);
		} else if((manipulatorStick->GetPOV() == 180) && switch1->Get()) {
			winch->Set(0.5);
		} else if(fabs(mLeftY) > threshold) {
			if(mLeftY > threshold && switch3->Get()) {
				winch->Set(-mLeftY);
			} else if(mLeftY < threshold && switch4->Get()) {
				winch->Set(-mLeftY);
			}
		/*} else if(cruise && switch2->Get()) {
			winch->Set(-0.05);*/
		} else {
			winch->Set(0);
		}

		if(sonic->GetVoltage() < 0.1) {
			SmartDashboard::PutString("DB/String 9", "Loaded");
		} else {
			SmartDashboard::PutString("DB/String 9", "Feed me, please!");
		}

		SmartDashboard::PutNumber("DB/Slider 1", sonic->GetVoltage());
		SmartDashboard::PutNumber("DB/Slider 2", shooterPos);
	}//:D

	void TestInit()
	{
		IMAQdxStartAcquisition(session);
		//read file in from disk. For this example to run you need to copy image.jpg from the SampleImages folder to the
							//directory shown below using FTP or SFTP: http://wpilib.screenstepslive.com/s/4485/m/24166/l/282299-roborio-ftp
							//imaqError = imaqReadFile(frame, "//home//lvuser//SampleImages//image.jpg", NULL, NULL);

							//Update threshold values from SmartDashboard. For performance reasons it is recommended to remove this after calibration is finished.
							/*RING_HUE_RANGE.minValue = SmartDashboard::GetNumber("Tote hue min", RING_HUE_RANGE.minValue);
							RING_HUE_RANGE.maxValue = SmartDashboard::GetNumber("Tote hue max", RING_HUE_RANGE.maxValue);
							RING_SAT_RANGE.minValue = SmartDashboard::GetNumber("Tote sat min", RING_SAT_RANGE.minValue);
							RING_SAT_RANGE.maxValue = SmartDashboard::GetNumber("Tote sat max", RING_SAT_RANGE.maxValue);
							RING_VAL_RANGE.minValue = SmartDashboard::GetNumber("Tote val min", RING_VAL_RANGE.minValue);
							RING_VAL_RANGE.maxValue = SmartDashboard::GetNumber("Tote val max", RING_VAL_RANGE.maxValue);*/

							//Threshold the image looking for ring light color
							imaqError = imaqColorThreshold(binaryFrame, frame, 255, IMAQ_HSV, &RING_HUE_RANGE, &RING_SAT_RANGE, &RING_VAL_RANGE);

							//Send particle count to dashboard
							int numParticles = 0;
							imaqError = imaqCountParticles(binaryFrame, 1, &numParticles);
							SmartDashboard::PutNumber("Masked particles", numParticles);

							//Send masked image to dashboard to assist in tweaking mask.
							SendToDashboard(binaryFrame, imaqError);

							//filter out small particles
							float areaMin = SmartDashboard::GetNumber("Area min %", AREA_MINIMUM);
							criteria[0] = {IMAQ_MT_AREA_BY_IMAGE_AREA, areaMin, 100, false, false};
							imaqError = imaqParticleFilter4(binaryFrame, binaryFrame, criteria, 1, &filterOptions, NULL, NULL);

							//Send particle count after filtering to dashboard
							imaqError = imaqCountParticles(binaryFrame, 1, &numParticles);
							SmartDashboard::PutNumber("Filtered particles", numParticles);

							if(numParticles > 0) {
								//Measure particles and sort by particle size
								std::vector<ParticleReport> particles;
								for(int particleIndex = 0; particleIndex < numParticles; particleIndex++)
								{
									ParticleReport par;
									imaqMeasureParticle(binaryFrame, particleIndex, 0, IMAQ_MT_AREA_BY_IMAGE_AREA, &(par.PercentAreaToImageArea));
									imaqMeasureParticle(binaryFrame, particleIndex, 0, IMAQ_MT_AREA, &(par.Area));
									imaqMeasureParticle(binaryFrame, particleIndex, 0, IMAQ_MT_BOUNDING_RECT_TOP, &(par.BoundingRectTop));
									imaqMeasureParticle(binaryFrame, particleIndex, 0, IMAQ_MT_BOUNDING_RECT_LEFT, &(par.BoundingRectLeft));
									imaqMeasureParticle(binaryFrame, particleIndex, 0, IMAQ_MT_BOUNDING_RECT_BOTTOM, &(par.BoundingRectBottom));
									imaqMeasureParticle(binaryFrame, particleIndex, 0, IMAQ_MT_BOUNDING_RECT_RIGHT, &(par.BoundingRectRight));
									particles.push_back(par);
								}
								sort(particles.begin(), particles.end(), CompareParticleSizes);

								//This example only scores the largest particle. Extending to score all particles and choosing the desired one is left as an exercise
								//for the reader. Note that this scores and reports information about a single particle (single L shaped target). To get accurate information
								//about the location of the tote (not just the distance) you will need to correlate two adjacent targets in order to find the true center of the tote.
								scores.Aspect = AspectScore(particles.at(0));
								SmartDashboard::PutNumber("Aspect", scores.Aspect);
								scores.Area = AreaScore(particles.at(0));
								SmartDashboard::PutNumber("Area", scores.Area);
								bool isTarget = scores.Area > SCORE_MIN && scores.Aspect > SCORE_MIN;

								//Send distance and tote status to dashboard. The bounding rect, particularly the horizontal center (left - right) may be useful for rotating/driving towards a tote
								SmartDashboard::PutBoolean("IsTarget", isTarget);
								SmartDashboard::PutNumber("Distance", computeDistance(binaryFrame, particles.at(0)));
							} else {
								SmartDashboard::PutBoolean("IsTarget", false);
							}
	}

	void TestPeriodic()
	{
		lw->Run();

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

		if(sonic->GetVoltage() < 0.1) {
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
	}

	//Send image to dashboard if IMAQ has not thrown an error
		void SendToDashboard(Image *image, int error)
		{
			if(error < ERR_SUCCESS) {
				DriverStation::ReportError("Send To Dashboard error: " + std::to_string((long)imaqError) + "\n");
			} else {
				CameraServer::GetInstance()->SetImage(binaryFrame);
			}
		}

		//Comparator function for sorting particles. Returns true if particle 1 is larger
		static bool CompareParticleSizes(ParticleReport particle1, ParticleReport particle2)
		{
			//we want descending sort order
			return particle1.PercentAreaToImageArea > particle2.PercentAreaToImageArea;
		}

		/**
		 * Converts a ratio with ideal value of 1 to a score. The resulting function is piecewise
		 * linear going from (0,0) to (1,100) to (2,0) and is 0 for all inputs outside the range 0-2
		 */
		double ratioToScore(double ratio)
		{
			return (fmax(0, fmin(100*(1-fabs(1-ratio)), 100)));
		}


		double AreaScore(ParticleReport report)
		{
			double boundingArea = (report.BoundingRectBottom - report.BoundingRectTop) * (report.BoundingRectRight - report.BoundingRectLeft);
			//Tape is 7" edge so 49" bounding rect. With 2" wide tape it covers 24" of the rect.
			return ratioToScore((49/24)*report.Area/boundingArea);
		}

		/**
		 * Method to score if the aspect ratio of the particle appears to match the retro-reflective target. Target is 7"x7" so aspect should be 1
		 */
		double AspectScore(ParticleReport report)
		{
			return ratioToScore(((report.BoundingRectRight-report.BoundingRectLeft)/(report.BoundingRectBottom-report.BoundingRectTop)));
		}


		/**
		 * Computes the estimated distance to a target using the width of the particle in the image. For more information and graphics
		 * showing the math behind this approach see the Vision Processing section of the ScreenStepsLive documentation.
		 *
		 * @param image The image to use for measuring the particle estimated rectangle
		 * @param report The Particle Analysis Report for the particle
		 * @return The estimated distance to the target in feet.
		 */
		double computeDistance (Image *image, ParticleReport report) {
			double normalizedWidth, targetWidth;
			int xRes, yRes;

			imaqGetImageSize(image, &xRes, &yRes);
			normalizedWidth = 2*(report.BoundingRectRight - report.BoundingRectLeft)/xRes;
			SmartDashboard::PutNumber("Width", normalizedWidth);
			targetWidth = 7;

			return  targetWidth/(normalizedWidth*12*tan(VIEW_ANGLE*M_PI/(180*2)));
		}
};

START_ROBOT_CLASS(Robot)

//lol
