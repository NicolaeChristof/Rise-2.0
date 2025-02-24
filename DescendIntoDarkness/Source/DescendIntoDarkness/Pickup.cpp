// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"
#include "DescendIntoDarknessCharacter.h"
#include "Resource.h"
#include "Kismet/GameplayStatics.h"

APickup::APickup()
{
	//defaults
	ItemID = FName("Please enter an ID");
	ItemQuantity = 1;
}

//destroy when picked up
void APickup::WasCollected_Implementation() {

	// Use the base pickup behavior
	Super::WasCollected_Implementation();
	ADescendIntoDarknessCharacter* player = Cast< ADescendIntoDarknessCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	//Add to Inventory
	if (player)
	{
		FResource temp;
		temp.ResourceName = Name;
		temp.ResourceID = ItemID;
		temp.ResourceImage = ItemImage;
		temp.ResourceQuantity = ItemQuantity;
		player->AddToInventory(temp);
		
	}

	// Destroy the battery
	Destroy();
}

void APickup::Show(bool visible)
{
	
}

FString APickup::GetItemName()
{
	return Name;
}
