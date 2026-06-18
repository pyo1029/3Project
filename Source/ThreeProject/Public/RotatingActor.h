#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingActor.generated.h"

UCLASS()
class THREEPROJECT_API ARotatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ARotatingActor();

protected:
	// 루트 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "RotatingActor|Components")
	USceneComponent* SceneRoot;

	// 스테틱매쉬 컴포넌트
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotatingActor|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotatingActor|Components")
	float RotationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
