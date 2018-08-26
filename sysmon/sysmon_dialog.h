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
// sysmonDlg.h : header file
//

#pragma once

// sysmon_dialog dialog
class sysmon_dialog : public CDialogEx
{
  // Construction
public:
  sysmon_dialog(CWnd* parent = nullptr);  // standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
  enum { IDD = IDD_SYSMON_DIALOG };
#endif

protected:
  virtual void DoDataExchange(CDataExchange* dx);  // DDX/DDV support

// Implementation
protected:
  HICON icon_;

  // Generated message map functions
  virtual BOOL OnInitDialog();
  afx_msg void OnSysCommand(UINT id, LPARAM lparam);
  afx_msg void OnPaint();
  afx_msg HCURSOR OnQueryDragIcon();
  DECLARE_MESSAGE_MAP()
};
