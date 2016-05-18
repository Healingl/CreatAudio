#ifndef AUDIO_H
#define AUDIO_H
#include <irrKlang.h>

using namespace irrklang;

#pragma comment(lib, "irrKlang.lib")

class Audio
{
public:
	irrklang::ISound* audioObject;
	ISoundEngine* engine;
	const char* soundPath;
	bool playLooped;
	
	Audio(ISoundEngine* engine, const char* soundPath, bool playLooped){
		this->engine = engine;
		this->soundPath = soundPath;
		this->playLooped = playLooped;
	};
	

	void Play(){
		audioObject = engine->play2D(soundPath, playLooped, false, true);
		audioObject->setVolume(0.8f);
		if (playLooped==false)
		{
			audioObject->drop();
			audioObject = 0;

		}	
	}

	void Pause(){
		audioObject->setIsPaused(true);
	}
	
	void Resume(){
		audioObject->setIsPaused(false);
	}
	
	void Stop(){
		audioObject->stop();
		audioObject->drop(); 
		audioObject = 0;
	}

	void setVolume(float size){
		if (audioObject){
			audioObject->setVolume(size);
		}
		}
};



































#endif