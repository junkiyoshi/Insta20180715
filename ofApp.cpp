#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("Insta");

	ofBackground(39);
	ofSetColor(239);
	ofSetLineWidth(2.5);
	ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	int deg = 0;
	ofBeginShape();
	for (int rect_len = 0; rect_len < ofGetWidth(); rect_len++) {

		ofPoint point = this->make_rect_point(rect_len, deg % 360);
		int noise_value = ofNoise(rect_len * 0.003 + ofGetFrameNum() * 0.003 * -1) * 5;

		point = this->make_rect_point(rect_len + noise_value * 30, deg % 360);
		ofVertex(point);

		deg += 5;
	}
	ofEndShape();
}

//--------------------------------------------------------------
ofPoint ofApp::make_rect_point(float len, int deg, int z) {

	int half_len = len * 0.5;
	int param = (deg + 45) / 90;
	ofPoint point;

	switch (param % 4) {

	case 0:

		return ofPoint(half_len, ofMap((deg + 45) % 90, 0, 89, -half_len, half_len), z);
	case 1:

		return  ofPoint(ofMap((deg + 45) % 90, 0, 89, half_len, -half_len), half_len, z);
	case 2:

		return ofPoint(-half_len, ofMap((deg + 45) % 90, 0, 89, half_len, -half_len), z);
	case 3:

		return ofPoint(ofMap((deg + 45) % 90, 0, 89, -half_len, half_len), -half_len, z);
	default:

		return ofPoint(0, 0, 0);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}