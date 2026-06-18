#include "MovingActor.h"

AMovingActor::AMovingActor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	StaticMeshComp->SetupAttachment(SceneRoot);
 
	PrimaryActorTick.bCanEverTick = true;

	MoveSpeed = FVector(200.0f, 0.0f, 0.0f);
	MaxRange = 500.0f;

	DistanceMoved = 0.0f;
}


void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
	
	//SetActorLocation(FVector(300.0f, 0.0f, 0.0f));
	//SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
	//SetActorScale3D(FVector(2.0f));

	StartLocation = GetActorLocation();
}


void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 현재위치를 가져와서 MoveSpeed 계산해서 더해줌
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation += (MoveSpeed * DeltaTime);
	SetActorLocation(CurrentLocation);

	// 시작위치로부터 현재 위치까지 거리 계산
	DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);

	if (DistanceMoved >= MaxRange)
	{
		// FVector 모든 축 부호를 반대로 변환
		MoveSpeed = MoveSpeed * -1.0f;

		/* [재미나이가 알려줌] 
		프레임 오차 보정:
		   Tick의 실행 타이밍 때문에 MaxRange를 아주 미세하게(예: 0.1cm) 초과할 수 있습니다.
		   방향 전환 시 시작 위치(StartLocation)를 현재 위치 쪽으로 살짝 당겨주어
		   왕복 위치가 매번 조금씩 밀리는 현상을 방지합니다.
		*/
		FVector MoveDirection = MoveSpeed.GetSafeNormal();
		StartLocation = StartLocation + (MoveDirection * -MaxRange);
	}
}

