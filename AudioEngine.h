#ifndef AUDIO_ENGINE_H
#define AUDIO_ENGINE_H
#include <irrKlang.h>

using namespace irrklang;

#pragma comment(lib, "irrKlang.lib")

class AudioEngine
{
public:
	int ID;
	ISoundEngine* engine;
	AudioEngine(int ID){
		this->ID = ID;
		engine = createIrrKlangDevice();
	};
	void pauseAll(){
		engine->setAllSoundsPaused(true);
	}
	void resumeAll(){
		engine->setAllSoundsPaused(false);
	}
	void stopAll(){
		engine->stopAllSounds();
	//	engine->drop();
	}
	void setVolume(float size){
	
		engine->setSoundVolume(size);
	
	}
};













#endif