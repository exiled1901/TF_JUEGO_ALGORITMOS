#include "DRUGS.h"

using namespace System;
using namespace System::Windows::Forms;

void main() {
    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();
    Project4::DRUGS^ myForm = gcnew Project4::DRUGS;
    myForm->WindowState = FormWindowState::Maximized;

    Application::Run(myForm);
}
