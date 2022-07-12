//Copyright(c) 2015 Michael Allar
#include "LabelButtonWidget.h"
#include "UMGExPlugin.h"

ULabelButtonWidget* ULabelButtonWidget::CreateLabelButtonWidget(APlayerController* PlayerController, TSubclassOf<ULabelButtonWidget> ButtonClass, const FLabelButtonInfo& WidgetInfo)
{
	ULabelButtonWidget* NewLabelButtonWidget = CreateWidget<ULabelButtonWidget>(PlayerController, ButtonClass);
	NewLabelButtonWidget->Label = WidgetInfo.Label;
	NewLabelButtonWidget->Tag = WidgetInfo.Tag;
	NewLabelButtonWidget->Caption = WidgetInfo.Caption;
	NewLabelButtonWidget->CaptionTag = WidgetInfo.CaptionTag;
	return NewLabelButtonWidget;
}

