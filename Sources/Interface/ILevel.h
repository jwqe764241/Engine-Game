#pragma once

#include <vector>
#include <d3d10_1.h>
#include <Sources/Interface/ICharacter.h>

class ILevel {
public:
	//레벨에 필요한 에셋들 로드
	virtual bool Load()           = 0;
	//할당한 에셋들 해제 및 레벨 정리
	virtual void Unload()         = 0;
	//입력받은 키, 좌표이동 등을 업데이트
	virtual void Update(float dt) = 0;
	//해당 레벨을 출력
	virtual bool Render(ID3D10Device* device, int screenWidth, int screenHeight) = 0;
	
	//레벨 시작 시 
	virtual void onStart() = 0;
	//레벨 종료 시 -> 레벨 변경 등
	virtual void onEnd() = 0;

};