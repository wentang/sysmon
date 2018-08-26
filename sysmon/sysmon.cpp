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
// sysmon.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "sysmon.h"
#include "sysmon_dialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// sysmon_app

BEGIN_MESSAGE_MAP(sysmon_app, CWinApp)
  ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

// sysmon_app construction

sysmon_app::sysmon_app()
{
  // TODO: add construction code here,
  // Place all significant initialization in InitInstance
}

// The one and only sysmon_app object

sysmon_app the_app;

// sysmon_app initialization

BOOL sysmon_app::InitInstance()
{
  // InitCommonControlsEx() is required on Windows XP if an application
  // manifest specifies use of ComCtl32.dll version 6 or later to enable
  // visual styles.  Otherwise, any window creation will fail.
  INITCOMMONCONTROLSEX init_ctrls;
  init_ctrls.dwSize = sizeof(init_ctrls);
  // Set this to include all the common control classes you want to use
  // in your application.
  init_ctrls.dwICC = ICC_WIN95_CLASSES;
  InitCommonControlsEx(&init_ctrls);

  CWinApp::InitInstance();

  AfxEnableControlContainer();

  // Create the shell manager, in case the dialog contains
  // any shell tree view or shell list view controls.
  CShellManager *shell_manager = new CShellManager;

  // Activate "Windows Native" visual manager for enabling themes in MFC controls
  CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

  // Standard initialization
  // If you are not using these features and wish to reduce the size
  // of your final executable, you should remove from the following
  // the specific initialization routines you do not need
  // Change the registry key under which our settings are stored
  // TODO: You should modify this string to be something appropriate
  // such as the name of your company or organization
  // SetRegistryKey(_T("Local AppWizard-Generated Applications"));

  sysmon_dialog dlg;
  m_pMainWnd = &dlg;
  INT_PTR response = dlg.DoModal();
  if (response == IDOK) {
    // TODO: Place code here to handle when the dialog is
    //  dismissed with OK
  } else if (response == IDCANCEL) {
    // TODO: Place code here to handle when the dialog is
    //  dismissed with Cancel
  } else if (response == -1) {
    TRACE(traceAppMsg, 0, "Warning: dialog creation failed, so application is terminating unexpectedly.\n");
    TRACE(traceAppMsg, 0, "Warning: if you are using MFC controls on the dialog, you cannot #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
  }

  // Delete the shell manager created above.
  if (shell_manager != nullptr) {
    delete shell_manager;
  }

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
  ControlBarCleanUp();
#endif

  // Since the dialog has been closed, return FALSE so that we exit the
  //  application, rather than start the application's message pump.
  return FALSE;
}
