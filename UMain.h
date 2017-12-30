//---------------------------------------------------------------------------

#ifndef UMainH
#define UMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFMain : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TGroupBox *GroupBox3;
        TEdit *Edit1;
        TLabel *Label1;
        TMemo *Memo1;
        TTimer *Timer1;
        TPaintBox *pb;
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Edit1Change(TObject *Sender);
        void __fastcall pbPaint(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFMain(TComponent* Owner);
  int Status;
  AnsiString oi;
  double XPos;     
};
//---------------------------------------------------------------------------
extern PACKAGE TFMain *FMain;
//---------------------------------------------------------------------------
#endif
