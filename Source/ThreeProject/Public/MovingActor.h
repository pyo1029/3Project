#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingActor.generated.h"

UCLASS()
class THREEPROJECT_API AMovingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingActor();

protected:
	// 루트 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MovingActor|Components")
	USceneComponent* SceneRoot;

	// 스테틱매쉬 컴포넌트
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingActor|Components")
	UStaticMeshComponent* StaticMeshComp;

	// 시작지점
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MovingActor|Platform")
	FVector StartLocation;

	// 이동속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingActor|Platform")
	FVector MoveSpeed;

	// 왕복범위
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingActor|Platform")
	float MaxRange;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


private:
	// 현재 누적 이동 거리를 기억하기 위한 변수
	float DistanceMoved;
};
