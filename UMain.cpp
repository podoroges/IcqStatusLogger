//---------------------------------------------------------------------------
#include <vcl.h>
#include <inifiles.hpp>
#include <..\ADBCommLib\WInet.h>
#include <..\ADBCommLib\unigraph.h>
#pragma hdrstop

#include "UMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFMain *FMain;
CUniGraph * g = NULL;
//---------------------------------------------------------------------------
__fastcall TFMain::TFMain(TComponent* Owner) : TForm(Owner){
  Status = -1;
  XPos = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFMain::Timer1Timer(TObject *Sender){
  WInet * w = new WInet();
  w->NoAutoRedirect = 1;                   //  132834924
  AnsiString st = w->Get((AnsiString)"http://status.icq.com/online.gif?icq="+Edit1->Text+"&img=5");
  delete w;

  int ns = (st.Pos("online1.gif")>0);
  if((ns!=Status)||(oi!=Edit1->Text)){
    if(ns)
      Memo1->Lines->Add((AnsiString)"["+Now().FormatString("dd-mmm-yy hh:nn:ss")+"] Icq#"+Edit1->Text+" is online!");
    else
      Memo1->Lines->Add((AnsiString)"["+Now().FormatString("dd-mmm-yy hh:nn:ss")+"] Icq#"+Edit1->Text+" is offline...");
  }

  

  if(g){
    XPos = XPos+1.0/3600.0;
    g->Serie[0]->AddPoint(XPos,ns);
    pb->Canvas->Draw(1,1,g->Bitmap);
  }


  if(ns)
    Label1->Caption = (AnsiString)"Last seen online: "+Now().FormatString("dd-mmm-yy hh:nn:ss");
  oi = Edit1->Text;
  Status = ns;
}
//---------------------------------------------------------------------------
void __fastcall TFMain::FormShow(TObject *Sender){
  TIniFile *ini = new TIniFile(ChangeFileExt(Application->ExeName,".ini"));
  Edit1->Text = ini->ReadString("Main","Icq","146956801");
  delete ini;
  g = new CUniGraph(pb->Width,pb->Height);
  g->StickOx = 0;
  g->StickOy = 1;
  //DrawGrid = 1;
  g->DrawArrows = 0;
  g->DrawNumbers = 0;
  //g->AddSerie(1,clBlue);
  g->Serie[0]->AddPoint(0,1);
  g->Serie[0]->AddPoint(0,0);
  Timer1Timer(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TFMain::FormClose(TObject *Sender, TCloseAction &Action){
  TIniFile *ini = new TIniFile(ChangeFileExt(Application->ExeName,".ini"));
  ini->WriteString("Main","Icq",Edit1->Text);
  delete ini;
  delete g;
}
//---------------------------------------------------------------------------
void __fastcall TFMain::Edit1Change(TObject *Sender){
  Label1->Caption = "";
}
//---------------------------------------------------------------------------
void __fastcall TFMain::pbPaint(TObject *Sender){
  if(!g)return;
  pb->Canvas->Draw(1,1,g->Bitmap);
}
//---------------------------------------------------------------------------

