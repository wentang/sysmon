// Copyright (c) 2018 Wentang Zhou. All rights reserved.
//
// This program is free software : you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.If not, see < https://www.gnu.org/licenses/>.
//
// taskbar_dialog.cpp : implementation file
//

#include "stdafx.h"
#include "sysmon.h"
#include "taskbar_dialog.h"
#include "afxdialogex.h"

// taskbar_dialog dialog

IMPLEMENT_DYNAMIC(taskbar_dialog, CDialogEx)

taskbar_dialog::taskbar_dialog(CWnd* parent /*=nullptr*/)
	: CDialogEx(IDD_TASKBAR_DIALOG, parent)
{
}

void taskbar_dialog::DoDataExchange(CDataExchange* dx)
{
	CDialogEx::DoDataExchange(dx);
}

BEGIN_MESSAGE_MAP(taskbar_dialog, CDialogEx)
END_MESSAGE_MAP()

// taskbar_dialog message handlers
