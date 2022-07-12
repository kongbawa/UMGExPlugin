//Copyright(c) 2015 Michael Allar
#include "MessageBoxWidget.h"
#include "UMGExPlugin.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

void UMessageBoxWidget::TriggerOnButtonPressed(const FName ButtonTag)
{
	if (!IsDesignTime())
	{
		OnButtonPressed.Broadcast(Tag, ButtonTag);
	}
}

UMessageBoxWidget* UMessageBoxWidget::ShowMessageBoxWidget(APlayerController* PlayerController, TSubclassOf<UMessageBoxWidget> MessageBoxClass, const FMessageBoxInfo& WidgetInfo)
{
	check(PlayerController);

	UMessageBoxWidget* NewMessageBoxWidget = CreateWidget<UMessageBoxWidget>(PlayerController, MessageBoxClass);
	NewMessageBoxWidget->Label = WidgetInfo.Label;
	NewMessageBoxWidget->Tag = WidgetInfo.Tag;
	NewMessageBoxWidget->Caption = WidgetInfo.Caption;
	NewMessageBoxWidget->ConfirmText = WidgetInfo.ConfirmText;
	NewMessageBoxWidget->CancelText = WidgetInfo.CancelText;
	NewMessageBoxWidget->AddToViewport();

	// Set player controller input to only this widget
	FInputModeUIOnly InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputMode.SetWidgetToFocus(NewMessageBoxWidget->TakeWidget());
	PlayerController->SetInputMode(InputMode);

	return NewMessageBoxWidget;
}

void UMessageBoxWidget::CloseBox()
{
	RemoveFromViewport();
}
