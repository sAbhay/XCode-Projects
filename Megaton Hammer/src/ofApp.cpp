#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofBackground(255, 0);

    ofDisableArbTex(); // we need GL_TEXTURE_2D for our models coords.

    bAnimate = false;
    bAnimateMouse = false;
    animationPosition = 0;
    
    model.loadModel("/Users/abhaysinghal/Downloads/Megaton Hammer.stl", false);
    model.setPosition(ofGetWidth() * 0.5, (float)ofGetHeight() * 0.75 , 0);
    model.setLoopStateForAllAnimations(OF_LOOP_NORMAL);
    model.playAllAnimations();
    if(!bAnimate) {
        model.setPausedForAllAnimations(true);
    }
    
    robot = Robot();
    
//    light.setSpecularColor(ofColor(255));
//    light.setDiffuseColor(ofColor(255));
}

//--------------------------------------------------------------
void ofApp::update(){
    model.update();
    
    if(bAnimateMouse) {
        model.setPositionForAllAnimations(animationPosition);
    }

    mesh = model.getCurrentAnimatedMesh(0);
    robot.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255);

    robot.beginCamera();
    
    ofFill();
    ofSetColor(50);
    ofDrawBox(0, 0, 0, 100000, 2, 100000);
    
    ofNoFill();
    ofSetColor(255);
    
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    ofEnableDepthTest();
#ifndef TARGET_PROGRAMMABLE_GL
    glShadeModel(GL_SMOOTH); //some model / light stuff
#endif
    light.enable();
    ofEnableSeparateSpecularLight();

    robot.display();
#ifndef TARGET_PROGRAMMABLE_GL
//    glEnable(GL_NORMALIZE);
#endif
//    ofPushMatrix();
//    ofTranslate(model.getPosition().x-300, model.getPosition().y, 0);
//    ofRotate(90, 1, 0, 0);
//    ofRotate(-mouseX, 0, 0, 1);
//    ofTranslate(-model.getPosition().x, -model.getPosition().y, 0);
//
//    ofxAssimpMeshHelper & meshHelper = model.getMeshHelper(0);
//
//    ofMultMatrix(model.getModelMatrix());
//    ofMultMatrix(meshHelper.matrix);
//
//    ofMaterial & material = meshHelper.material;
//    if(meshHelper.hasTexture()){
//        meshHelper.getTextureRef().bind();
//    }
//    material.begin();
//    mesh.drawWireframe();
//    material.end();
//    if(meshHelper.hasTexture()){
//        meshHelper.getTextureRef().unbind();
//    }
//    ofPopMatrix();
    
    ofDisableDepthTest();
    light.disable();
    ofDisableLighting();
    ofDisableSeparateSpecularLight();
    
//    ofFill();
//    ofSetColor(255,0,0);
//    ofDrawBox(1);
    
    robot.endCamera();
    
    ofSetColor(255, 255, 255 );
    ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate(), 2), 10, 15);
    ofDrawBitmapString("keys 1-5 load models, spacebar to trigger animation", 10, 30);
    ofDrawBitmapString("drag to control animation with mouseY", 10, 45);
    ofDrawBitmapString("num animations for this model: " + ofToString(model.getAnimationCount()), 10, 60);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    ofPoint modelPosition(ofGetWidth() * 0.5, (float)ofGetHeight() * 0.75);
    switch (key) {
        case '1':
            model.loadModel("astroBoy_walk.dae");
            model.setPosition(modelPosition.x, modelPosition.y, modelPosition.z);
            ofEnableSeparateSpecularLight();
            break;
        case '2':
            model.loadModel("TurbochiFromXSI.dae");
            model.setPosition(modelPosition.x, modelPosition.y, modelPosition.z);
            model.setRotation(0, -180, 1, 0, 0);
            ofEnableSeparateSpecularLight();
            break;
        case '3':
            model.loadModel("dwarf.x");
            model.setPosition(modelPosition.x, modelPosition.y, modelPosition.z);
            ofDisableSeparateSpecularLight();
            break;
        case '4':
            model.loadModel("monster-animated-character-X.X");
            model.setPosition(modelPosition.x, modelPosition.y, modelPosition.z);
            model.setRotation(0, -90, 0, 0, 1);
            ofDisableSeparateSpecularLight();
            break;
        case '5':
            model.loadModel("squirrel/NewSquirrel.3ds");
            model.setPosition(modelPosition.x, modelPosition.y, modelPosition.z);
            ofDisableSeparateSpecularLight();
            break;
        case ' ':
            bAnimate = !bAnimate;
            break;
        default:
            break;
    }

    mesh = model.getMesh(0);

    model.setLoopStateForAllAnimations(OF_LOOP_NORMAL);
    model.playAllAnimations();
    if(!bAnimate) {
        model.setPausedForAllAnimations(true);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    //
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    // scrub through aninations manually.
    animationPosition = y / (float)ofGetHeight();
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    // pause all animations, so we can scrub through them manually.
    model.setPausedForAllAnimations(true);
    animationPosition = y / (float)ofGetHeight();
    bAnimateMouse = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    // unpause animations when finished scrubbing.
    if(bAnimate) {
        model.setPausedForAllAnimations(false);
    }
    bAnimateMouse = false;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}


