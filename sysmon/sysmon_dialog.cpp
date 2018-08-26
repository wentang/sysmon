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
// sysmonDlg.cpp : implementation file
//

#include "stdafx.h"
#include "sysmon.h"
#include "sysmon_dialog.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// about_dialog dialog used for App About

class about_dialog : public CDialogEx
{
public:
  about_dialog();

  // Dialog Data
#ifdef AFX_DESIGN_TIME
  enum { IDD = IDD_ABOUTBOX };
#endif

protected:
  virtual void DoDataExchange(CDataExchange* dx);    // DDX/DDV support

// Implementation
protected:
  DECLARE_MESSAGE_MAP()
};

about_dialog::about_dialog() : CDialogEx(IDD_ABOUTBOX)
{
}

void about_dialog::DoDataExchange(CDataExchange* dx)
{
  CDialogEx::DoDataExchange(dx);
}

BEGIN_MESSAGE_MAP(about_dialog, CDialogEx)
END_MESSAGE_MAP()

// sysmon_dialog dialog

sysmon_dialog::sysmon_dialog(CWnd* parent /*=nullptr*/)
  : CDialogEx(IDD_SYSMON_DIALOG, parent)
{
  icon_ = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void sysmon_dialog::DoDataExchange(CDataExchange* dx)
{
  CDialogEx::DoDataExchange(dx);
}

BEGIN_MESSAGE_MAP(sysmon_dialog, CDialogEx)
  ON_WM_SYSCOMMAND()
  ON_WM_PAINT()
  ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()

// sysmon_dialog message handlers

BOOL sysmon_dialog::OnInitDialog()
{
  CDialogEx::OnInitDialog();

  // Add "About..." menu item to system menu.

  // IDM_ABOUTBOX must be in the system command range.
  ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
  ASSERT(IDM_ABOUTBOX < 0xF000);

  CMenu* sys_menu = GetSystemMenu(FALSE);
  if (sys_menu != nullptr) {
    BOOL name_valid;
    CString about_menu_string;
    name_valid = about_menu_string.LoadString(IDS_ABOUTBOX);
    ASSERT(name_valid);
    if (!about_menu_string.IsEmpty()) {
      sys_menu->AppendMenu(MF_SEPARATOR);
      sys_menu->AppendMenu(MF_STRING, IDM_ABOUTBOX, about_menu_string);
    }
  }

  // Set the icon for this dialog.  The framework does this automatically
  //  when the application's main window is not a dialog
  SetIcon(icon_, TRUE);      // Set big icon
  SetIcon(icon_, FALSE);    // Set small icon

  // TODO: Add extra initialization here

  return TRUE;  // return TRUE  unless you set the focus to a control
}

void sysmon_dialog::OnSysCommand(UINT id, LPARAM lparam)
{
  if ((id & 0xFFF0) == IDM_ABOUTBOX) {
    about_dialog dialog;
    dialog.DoModal();
  } else {
    CDialogEx::OnSysCommand(id, lparam);
  }
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void sysmon_dialog::OnPaint()
{
  if (IsIconic()) {
    CPaintDC dc(this); // device context for painting

    SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

    // Center icon in client rectangle
    int icon_x = GetSystemMetrics(SM_CXICON);
    int icon_y = GetSystemMetrics(SM_CYICON);
    CRect rect;
    GetClientRect(&rect);
    int x = (rect.Width() - icon_x + 1) / 2;
    int y = (rect.Height() - icon_y + 1) / 2;

    // Draw the icon
    dc.DrawIcon(x, y, icon_);
  } else {
    CDialogEx::OnPaint();
  }
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR sysmon_dialog::OnQueryDragIcon()
{
  return static_cast<HCURSOR>(icon_);
}
