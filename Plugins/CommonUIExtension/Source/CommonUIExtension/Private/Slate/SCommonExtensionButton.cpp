// Copyright (C) Cindy Chen. All Rights Reserved.

// Self
#include "Slate/SCommonExtensionButton.h"

void SCommonExtensionButton::Construct(const FArguments& InArgs)
{
	SCommonButton::Construct(SCommonButton::FArguments()
		.ButtonStyle(InArgs._ButtonStyle)
		.HAlign(InArgs._HAlign)
		.VAlign(InArgs._VAlign)
		.ClickMethod(InArgs._ClickMethod)
		.TouchMethod(InArgs._TouchMethod)
		.PressMethod(InArgs._PressMethod)
		.IsFocusable(InArgs._IsFocusable)
		.IsButtonEnabled(InArgs._IsButtonEnabled)
		.IsInteractionEnabled(InArgs._IsInteractionEnabled)
		.OnClicked(InArgs._OnClicked)
		.OnDoubleClicked(InArgs._OnDoubleClicked)
		.OnPressed(InArgs._OnPressed)
		.OnReleased(InArgs._OnReleased)
		.OnReceivedFocus(InArgs._OnReceivedFocus)
		.OnLostFocus(InArgs._OnLostFocus)
		.Content()
		[
			InArgs._Content.Widget
		]
	);

	bIsHoverEnabledOnFocus = InArgs._IsHoverEnabledOnFocus;
}

FReply SCommonExtensionButton::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
	// 這裡不阻擋任何按鍵，無論是搖桿、鍵盤點擊都是依靠Focus
	return SButton::OnKeyDown(MyGeometry, InKeyEvent);
}

FReply SCommonExtensionButton::OnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
	// 這裡不阻擋任何按鍵，無論是搖桿、鍵盤點擊都是依靠Focus
	return SButton::OnKeyUp(MyGeometry, InKeyEvent);
}

FReply SCommonExtensionButton::OnFocusReceived(const FGeometry& MyGeometry, const FFocusEvent& InFocusEvent)
{
	if (bIsHoverEnabledOnFocus)
	{
		// 模擬滑鼠進入達成Hover狀態
		OnMouseEnter(MyGeometry, FPointerEvent());
	}

	return SCommonButton::OnFocusReceived(MyGeometry, InFocusEvent);
}

void SCommonExtensionButton::OnFocusLost(const FFocusEvent& InFocusEvent)
{
	if (bIsHoverEnabledOnFocus)
	{
		// 模擬滑鼠離開達成Unhover狀態
		OnMouseLeave(FPointerEvent());
	}

	SCommonButton::OnFocusLost(InFocusEvent);
}
